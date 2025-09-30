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
} from '@/components/ui/sidebar';
import { Code, BookOpen, Lock } from 'lucide-react';
import { lessonData } from '@/data/lessonData';
import { Collapsible, CollapsibleContent, CollapsibleTrigger } from '@/components/ui/collapsible';
import { cn } from '@/lib/utils';

export function AppSidebar() {
  const location = useLocation();
  const pathSegments = location.pathname.split('/');
  const courseId = pathSegments[2]; // /course/:courseId/...
  const course = lessonData[courseId as keyof typeof lessonData];

  return (
    <Sidebar className="w-64">
      <SidebarContent>
        {course && (
          <SidebarGroup>
            <SidebarGroupLabel className="text-base font-bold px-4 py-3 border-b">
              {course.title}
            </SidebarGroupLabel>
            <SidebarGroupContent className="pt-2">
              <SidebarMenu className="space-y-0">
                {course.modules.map((module, moduleIndex) => (
                  <Collapsible
                    key={moduleIndex}
                    defaultOpen={module.lessons.some(lesson => 
                      location.pathname.includes(`/${module.slug}/${lesson.slug}`)
                    )}
                  >
                    <SidebarMenuItem className="border-l-2 border-muted">
                      <CollapsibleTrigger asChild>
                        <SidebarMenuButton className={cn(
                          "w-full justify-start py-2.5 hover:bg-accent/50",
                          "data-[state=open]:bg-muted/30"
                        )}>
                          <div className="flex items-center gap-2 w-full">
                            <Code className="h-4 w-4 flex-shrink-0 text-muted-foreground" />
                            <span className="truncate font-medium text-sm">{module.title}</span>
                          </div>
                        </SidebarMenuButton>
                      </CollapsibleTrigger>
                      <CollapsibleContent>
                        <div className="space-y-0 border-l-2 border-muted ml-2">
                          {module.lessons.map((lesson, lessonIndex) => {
                            const lessonPath = `/course/${courseId}/${module.slug}/${lesson.slug}`;
                            const isActive = location.pathname === lessonPath;
                            const isLocked = lesson.isPremium;

                            return (
                              <SidebarMenuItem key={lessonIndex}>
                                <SidebarMenuButton
                                  asChild
                                  isActive={isActive}
                                  className={cn(
                                    "w-full py-2 hover:bg-accent/50",
                                    isActive && "bg-accent border-l-2 border-primary",
                                    isLocked && 'opacity-60'
                                  )}
                                >
                                  <Link to={lessonPath}>
                                    <div className="flex items-center gap-2 w-full pl-2">
                                      <BookOpen className="h-3.5 w-3.5 flex-shrink-0 text-muted-foreground" />
                                      <span className="truncate text-sm flex-1">{lesson.title}</span>
                                      {isLocked && <Lock className="h-3 w-3 flex-shrink-0 text-muted-foreground" />}
                                    </div>
                                  </Link>
                                </SidebarMenuButton>
                              </SidebarMenuItem>
                            );
                          })}
                        </div>
                      </CollapsibleContent>
                    </SidebarMenuItem>
                  </Collapsible>
                ))}
              </SidebarMenu>
            </SidebarGroupContent>
          </SidebarGroup>
        )}
      </SidebarContent>
    </Sidebar>
  );
}