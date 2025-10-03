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
import { Code, BookOpen, Lock, Database, Brain, GitBranch, MessageSquare } from 'lucide-react';
import { Collapsible, CollapsibleContent, CollapsibleTrigger } from '@/components/ui/collapsible';
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

  return (
    <Sidebar className="w-64 border-r">
      <SidebarContent>
        {course && (
          <SidebarGroup>
            <SidebarGroupLabel className="text-base font-bold px-4 py-3 bg-muted/50 border-b">
              {course.title}
            </SidebarGroupLabel>
            <SidebarGroupContent>
              <SidebarMenu className="space-y-0">
                {course.modules.map((module, moduleIndex) => (
                  <Collapsible
                    key={moduleIndex}
                    defaultOpen={module.lessons.some(lesson => 
                      location.pathname.includes(`/${module.slug}/${lesson.slug}`)
                    )}
                  >
                    {/* Module Header - Dark Grey Background */}
                    <SidebarMenuItem>
                      <CollapsibleTrigger asChild>
                        <SidebarMenuButton className={cn(
                          "w-full justify-start py-3 px-4 bg-muted/30 hover:bg-muted/50",
                          "border-b border-border/50",
                          "data-[state=open]:bg-muted/50"
                        )}>
                          <div className="flex items-center gap-2 w-full">
                            <Code className="h-4 w-4 flex-shrink-0" />
                            <span className="font-semibold text-sm leading-tight">{module.title}</span>
                          </div>
                        </SidebarMenuButton>
                      </CollapsibleTrigger>
                      <CollapsibleContent>
                        {/* Lessons - Light Grey Background */}
                        <div className="bg-background border-b border-border/50">
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
                                    "w-full py-2.5 px-4 hover:bg-muted/30",
                                    isActive && "bg-primary/10 border-l-4 border-primary font-medium",
                                    !isActive && "border-l-4 border-transparent",
                                    isLocked && 'opacity-60'
                                  )}
                                >
                                  <Link to={lessonPath}>
                                    <div className="flex items-center gap-2 w-full">
                                      <BookOpen className="h-4 w-4 flex-shrink-0" />
                                      <span className="text-sm leading-tight flex-1 overflow-hidden text-ellipsis">{lesson.title}</span>
                                      {isLocked && <Lock className="h-3.5 w-3.5 flex-shrink-0 text-muted-foreground" />}
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