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
        lessons: [
          { title: "Introduction to Arrays", slug: "intro", isPremium: false },
          { title: "Two Pointers Technique", slug: "two-pointers", isPremium: false },
          { title: "Sliding Window", slug: "sliding-window", isPremium: true },
          { title: "Prefix Sum", slug: "prefix-sum", isPremium: true },
        ]
      },
      {
        title: "Linked Lists",
        slug: "linked-lists",
        lessons: [
          { title: "Basics", slug: "basics", isPremium: false },
          { title: "Fast & Slow Pointers", slug: "fast-slow", isPremium: true },
          { title: "Reversal", slug: "reversal", isPremium: true },
        ]
      },
      {
        title: "Trees & Graphs",
        slug: "trees",
        lessons: [
          { title: "Tree Fundamentals", slug: "fundamentals", isPremium: false },
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
        lessons: [
          { title: "Load Balancing", slug: "load-balancing", isPremium: false },
          { title: "Horizontal vs Vertical Scaling", slug: "scaling", isPremium: true },
          { title: "Auto Scaling", slug: "auto-scaling", isPremium: true },
        ]
      },
      {
        title: "Databases",
        slug: "databases",
        lessons: [
          { title: "SQL vs NoSQL", slug: "sql-nosql", isPremium: false },
          { title: "Sharding", slug: "sharding", isPremium: true },
          { title: "Replication", slug: "replication", isPremium: true },
        ]
      },
      {
        title: "Caching",
        slug: "caching",
        lessons: [
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
        lessons: [
          { title: "Singleton Pattern", slug: "singleton", isPremium: false },
          { title: "Factory Pattern", slug: "factory", isPremium: true },
          { title: "Observer Pattern", slug: "observer", isPremium: true },
        ]
      },
      {
        title: "Object-Oriented Design",
        slug: "oop",
        lessons: [
          { title: "SOLID Principles", slug: "solid", isPremium: false },
          { title: "Inheritance vs Composition", slug: "inheritance", isPremium: true },
        ]
      },
      {
        title: "System Design Examples",
        slug: "examples",
        lessons: [
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
        lessons: [
          { title: "STAR Method", slug: "star-method", isPremium: false },
          { title: "Storytelling", slug: "storytelling", isPremium: true },
        ]
      },
      {
        title: "Common Questions",
        slug: "questions",
        lessons: [
          { title: "Leadership Examples", slug: "leadership", isPremium: false },
          { title: "Conflict Resolution", slug: "conflict", isPremium: true },
          { title: "Failure Stories", slug: "failure", isPremium: true },
        ]
      },
      {
        title: "Company Culture",
        slug: "culture",
        lessons: [
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
    location.pathname.includes(`/${module.slug}/`)
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
                           module.lessons.some(lesson => 
                             lesson.title.toLowerCase().includes(searchQuery.toLowerCase())
                           );
                  })
                  .map((module, moduleIndex) => {
                    const isOpen = openModuleIndex === moduleIndex;
                    const hasActiveLesson = module.lessons.some(lesson => 
                      location.pathname.includes(`/${module.slug}/${lesson.slug}`)
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
                              {module.lessons
                                .filter(lesson => {
                                  if (!searchQuery) return true;
                                  return lesson.title.toLowerCase().includes(searchQuery.toLowerCase());
                                })
                                .map((lesson, lessonIndex) => {
                                  const lessonPath = `/course/${courseId}/${module.slug}/${lesson.slug}`;
                                  const isActive = location.pathname === lessonPath;
                                  const isLocked = lesson.isPremium;

                                  return (
                                    <SidebarMenuItem key={lessonIndex}>
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
                                            <span className="text-sm flex-1 truncate">{lesson.title}</span>
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