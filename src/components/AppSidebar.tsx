import { useState } from 'react';
import { Link, useLocation } from 'react-router-dom';
import {
  Sidebar,
  SidebarContent,
  SidebarGroup,
  SidebarGroupContent,
  SidebarGroupLabel,
  SidebarMenu,
  SidebarMenuButton,
  SidebarMenuItem,
  SidebarHeader,
} from '@/components/ui/sidebar';
import { Code, BookOpen, Lock, Database, Brain, GitBranch, MessageSquare, Search, ChevronDown } from 'lucide-react';
import { Collapsible, CollapsibleContent, CollapsibleTrigger } from '@/components/ui/collapsible';
import { Input } from '@/components/ui/input';
import { ScrollArea } from '@/components/ui/scroll-area';
import { cn } from '@/lib/utils';
import dsaCourseData from '@/data/courses/dsaCourse.json';
import systemDesignCourseData from '@/data/courses/systemDesignCourse.json';
import lldCourseData from '@/data/courses/lldCourse.json';
import behavioralCourseData from '@/data/courses/behavioralCourse.json';

const courses: any[] = [
  {
    ...dsaCourseData,
    icon: Database,
  },
  {
    ...systemDesignCourseData,
    icon: Brain,
  },
  {
    ...lldCourseData,
    icon: GitBranch,
  },
  {
    ...behavioralCourseData,
    icon: MessageSquare,
  }
];

export function AppSidebar() {
  const location = useLocation();
  const pathSegments = location.pathname.split('/');
  const courseId = pathSegments[2]; // /course/:courseId/...
  const course = courses.find(c => c.id === courseId);
  const [searchQuery, setSearchQuery] = useState('');
  const [openModuleIndex, setOpenModuleIndex] = useState<number | null>(null);

  // Find which module is active based on current path
  const activeModuleIndex = course?.modules.findIndex(module =>
    module.items.some((item: any) => 
      !item.isHeader && location.pathname.includes(`/${module.slug}/${item.slug}`)
    )
  ) ?? null;

  // Set the active module as open initially
  useState(() => {
    if (activeModuleIndex !== null && openModuleIndex === null) {
      setOpenModuleIndex(activeModuleIndex);
    }
  });

  const handleModuleToggle = (index: number) => {
    setOpenModuleIndex(openModuleIndex === index ? null : index);
  };

  return (
    <Sidebar className="border-r">
      <SidebarHeader className="border-b px-4 py-3">
        <div className="relative">
          <Search className="absolute left-3 top-1/2 transform -translate-y-1/2 h-4 w-4 text-muted-foreground" />
          <Input
            type="search"
            placeholder="Search lessons..."
            className="pl-9 h-9"
            value={searchQuery}
            onChange={(e) => setSearchQuery(e.target.value)}
          />
        </div>
      </SidebarHeader>
      
      <ScrollArea className="flex-1">
        <SidebarContent>
        {course && (
          <SidebarGroup>
            <SidebarGroupLabel className="text-base font-bold px-4 py-3 sticky top-0 bg-background/95 backdrop-blur supports-[backdrop-filter]:bg-background/60 z-10 border-b">
              {course.title}
            </SidebarGroupLabel>
            <SidebarGroupContent>
              <SidebarMenu className="space-y-1 p-2">
                {course.modules
                  .filter(module => {
                    if (!searchQuery) return true;
                    return module.title.toLowerCase().includes(searchQuery.toLowerCase()) ||
                           module.items.some((item: any) => 
                             item.title.toLowerCase().includes(searchQuery.toLowerCase())
                           );
                  })
                  .map((module, moduleIndex) => {
                    const isOpen = openModuleIndex === moduleIndex;
                    const hasActiveLesson = module.items.some((item: any) => 
                      !item.isHeader && location.pathname.includes(`/${module.slug}/${item.slug}`)
                    );

                    return (
                      <Collapsible
                        key={moduleIndex}
                        open={isOpen}
                        onOpenChange={() => handleModuleToggle(moduleIndex)}
                      >
                        <SidebarMenuItem>
                          <CollapsibleTrigger asChild>
                            <SidebarMenuButton 
                              className={cn(
                                "w-full justify-between py-2.5 px-3 rounded-md",
                                "hover:bg-accent/50 transition-colors",
                                isOpen && "bg-accent/50",
                                hasActiveLesson && "font-semibold"
                              )}
                            >
                              <div className="flex items-center gap-2 min-w-0 flex-1 overflow-hidden">
                                <Code className="h-4 w-4 flex-shrink-0 text-primary" />
                                <span className="text-sm font-medium truncate block">{module.title}</span>
                              </div>
                              <ChevronDown className={cn(
                                "h-4 w-4 transition-transform flex-shrink-0 ml-1",
                                isOpen && "transform rotate-180"
                              )} />
                            </SidebarMenuButton>
                          </CollapsibleTrigger>
                          <CollapsibleContent className="mt-1">
                            <div className="space-y-0.5">
                              {module.items
                                .filter(item => {
                                  if (!searchQuery) return true;
                                  return item.title.toLowerCase().includes(searchQuery.toLowerCase());
                                })
                                .map((item, itemIndex) => {
                                  if (item.isHeader) {
                                    return (
                                      <div
                                        key={itemIndex}
                                        className="px-3 py-2 text-xs font-semibold text-muted-foreground uppercase tracking-wider"
                                      >
                                        {item.title}
                                      </div>
                                    );
                                  }

                                  const lessonPath = `/course/${courseId}/${module.slug}/${item.slug}`;
                                  const isActive = location.pathname === lessonPath;
                                  const isLocked = item.isPremium;

                                  return (
                                    <SidebarMenuItem key={itemIndex}>
                                      <SidebarMenuButton
                                        asChild
                                        isActive={isActive}
                                        className={cn(
                                          "w-full py-2 px-3 rounded-md transition-colors",
                                          "hover:bg-accent/50",
                                          isActive && "bg-primary/10 font-medium text-primary",
                                          !isActive && "text-muted-foreground hover:text-foreground"
                                        )}
                                      >
                                        <Link to={lessonPath} className="flex items-center gap-2 w-full min-w-0">
                                          <BookOpen className="h-3.5 w-3.5 flex-shrink-0" />
                                          <span className="text-sm truncate" title={item.title}>{item.title}</span>
                                          {isLocked && <Lock className="h-3 w-3 flex-shrink-0 text-muted-foreground" />}
                                        </Link>
                                      </SidebarMenuButton>
                                    </SidebarMenuItem>
                                  );
                                })}
                            </div>
                          </CollapsibleContent>
                        </SidebarMenuItem>
                      </Collapsible>
                    );
                  })}
              </SidebarMenu>
            </SidebarGroupContent>
          </SidebarGroup>
        )}
      </SidebarContent>
      </ScrollArea>
    </Sidebar>
  );
}