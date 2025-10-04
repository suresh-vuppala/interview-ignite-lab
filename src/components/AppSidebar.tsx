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

const courses = [
  {
    id: "dsa",
    title: "DSA (Data Structures & Algorithms)",
    icon: Database,
    modules: [
      {
        title: "Arrays & Strings",
        slug: "arrays",
        items: [
          { title: "Introduction", isHeader: true },
          { title: "Introduction to Arrays", slug: "intro", isPremium: false },
          { title: "Two Pointers Technique", slug: "two-pointers", isPremium: false },
          { title: "Additional Problems", isHeader: true },
          { title: "Sliding Window", slug: "sliding-window", isPremium: true },
          { title: "Prefix Sum", slug: "prefix-sum", isPremium: true },
        ]
      },
      {
        title: "Linked Lists",
        slug: "linked-lists",
        items: [
          { title: "Introduction", isHeader: true },
          { title: "Basics", slug: "basics", isPremium: false },
          { title: "Advanced Topics", isHeader: true },
          { title: "Fast & Slow Pointers", slug: "fast-slow", isPremium: true },
          { title: "Reversal", slug: "reversal", isPremium: true },
        ]
      },
      {
        title: "Trees & Graphs",
        slug: "trees",
        items: [
          { title: "Fundamentals", isHeader: true },
          { title: "Tree Fundamentals", slug: "fundamentals", isPremium: false },
          { title: "Advanced", isHeader: true },
          { title: "DFS & BFS", slug: "dfs-bfs", isPremium: true },
          { title: "Binary Search Trees", slug: "bst", isPremium: true },
        ]
      }
    ]
  },
  {
    id: "system-design-hld",
    title: "System Design (HLD)",
    icon: Brain,
    modules: [
      {
        title: "Scalability Basics",
        slug: "scalability",
        items: [
          { title: "Core Concepts", isHeader: true },
          { title: "Load Balancing", slug: "load-balancing", isPremium: false },
          { title: "Horizontal vs Vertical Scaling", slug: "scaling", isPremium: true },
          { title: "Auto Scaling", slug: "auto-scaling", isPremium: true },
        ]
      },
      {
        title: "Databases",
        slug: "databases",
        items: [
          { title: "Basics", isHeader: true },
          { title: "SQL vs NoSQL", slug: "sql-nosql", isPremium: false },
          { title: "Advanced", isHeader: true },
          { title: "Sharding", slug: "sharding", isPremium: true },
          { title: "Replication", slug: "replication", isPremium: true },
        ]
      },
      {
        title: "Caching",
        slug: "caching",
        items: [
          { title: "Cache Patterns", slug: "patterns", isPremium: false },
          { title: "CDN", slug: "cdn", isPremium: true },
        ]
      }
    ]
  },
  {
    id: "lld",
    title: "LLD (Low Level Design)",
    icon: GitBranch,
    modules: [
      {
        title: "Design Patterns",
        slug: "design-patterns",
        items: [
          { title: "Singleton Pattern", slug: "singleton", isPremium: false },
          { title: "Factory Pattern", slug: "factory", isPremium: true },
          { title: "Observer Pattern", slug: "observer", isPremium: true },
        ]
      },
      {
        title: "Object-Oriented Design",
        slug: "oop",
        items: [
          { title: "SOLID Principles", slug: "solid", isPremium: false },
          { title: "Inheritance vs Composition", slug: "inheritance", isPremium: true },
        ]
      },
      {
        title: "System Design Examples",
        slug: "examples",
        items: [
          { title: "Parking Lot System", slug: "parking-lot", isPremium: true },
          { title: "Elevator System", slug: "elevator", isPremium: true },
        ]
      }
    ]
  },
  {
    id: "behavioral",
    title: "Behavioral Interview Prep",
    icon: MessageSquare,
    modules: [
      {
        title: "Interview Techniques",
        slug: "techniques",
        items: [
          { title: "STAR Method", slug: "star-method", isPremium: false },
          { title: "Storytelling", slug: "storytelling", isPremium: true },
        ]
      },
      {
        title: "Common Questions",
        slug: "questions",
        items: [
          { title: "Leadership Examples", slug: "leadership", isPremium: false },
          { title: "Conflict Resolution", slug: "conflict", isPremium: true },
          { title: "Failure Stories", slug: "failure", isPremium: true },
        ]
      },
      {
        title: "Company Culture",
        slug: "culture",
        items: [
          { title: "Culture Fit", slug: "fit", isPremium: true },
          { title: "Values Alignment", slug: "values", isPremium: true },
        ]
      }
    ]
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
                              <div className="flex items-center gap-2 min-w-0">
                                <Code className="h-4 w-4 flex-shrink-0 text-primary" />
                                <span className="text-sm font-medium truncate">{module.title}</span>
                              </div>
                              <ChevronDown className={cn(
                                "h-4 w-4 transition-transform flex-shrink-0",
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
                                        <Link to={lessonPath}>
                                          <div className="flex items-center gap-2 w-full min-w-0">
                                            <BookOpen className="h-3.5 w-3.5 flex-shrink-0" />
                                            <span className="text-sm flex-1 truncate">{item.title}</span>
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