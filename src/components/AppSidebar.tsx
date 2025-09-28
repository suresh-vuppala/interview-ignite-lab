import React, { useState } from "react";
import { NavLink, useLocation } from "react-router-dom";
import { 
  BookOpen, 
  Home, 
  Settings, 
  Lock, 
  Crown,
  ChevronRight,
  Code,
  Database,
  Brain,
  Users,
  Search,
  GitBranch,
  Building,
  MessageSquare
} from "lucide-react";
import {
  Sidebar,
  SidebarContent,
  SidebarGroup,
  SidebarGroupContent,
  SidebarGroupLabel,
  SidebarMenu,
  SidebarMenuButton,
  SidebarMenuItem,
  SidebarTrigger,
  useSidebar,
  SidebarMenuSub,
  SidebarMenuSubItem,
  SidebarMenuSubButton,
} from "@/components/ui/sidebar";
import { Collapsible, CollapsibleContent, CollapsibleTrigger } from "@/components/ui/collapsible";
import { Badge } from "@/components/ui/badge";
import { Input } from "@/components/ui/input";
import { useAuth } from "@/hooks/useAuth";

// Define courses with proper structure
const courses = [
  {
    id: "dsa",
    title: "DSA (Data Structures & Algorithms)",
    icon: Database,
    modules: [
      {
        title: "Arrays & Strings",
        url: "/course/dsa/arrays",
        lessons: [
          { title: "Introduction to Arrays", url: "/course/dsa/arrays/intro", isPremium: false },
          { title: "Two Pointers Technique", url: "/course/dsa/arrays/two-pointers", isPremium: false },
          { title: "Sliding Window", url: "/course/dsa/arrays/sliding-window", isPremium: true },
          { title: "Prefix Sum", url: "/course/dsa/arrays/prefix-sum", isPremium: true },
        ]
      },
      {
        title: "Linked Lists",
        url: "/course/dsa/linked-lists",
        lessons: [
          { title: "Basics", url: "/course/dsa/linked-lists/basics", isPremium: false },
          { title: "Fast & Slow Pointers", url: "/course/dsa/linked-lists/fast-slow", isPremium: true },
          { title: "Reversal", url: "/course/dsa/linked-lists/reversal", isPremium: true },
        ]
      },
      {
        title: "Trees & Graphs",
        url: "/course/dsa/trees",
        lessons: [
          { title: "Tree Fundamentals", url: "/course/dsa/trees/fundamentals", isPremium: false },
          { title: "DFS & BFS", url: "/course/dsa/trees/dfs-bfs", isPremium: true },
          { title: "Binary Search Trees", url: "/course/dsa/trees/bst", isPremium: true },
        ]
      }
    ]
  },
  {
    id: "system-design-hld",
    title: "System Design (HLD) Fundamentals",
    icon: Brain,
    modules: [
      {
        title: "Scalability Basics",
        url: "/course/system-design-hld/scalability",
        lessons: [
          { title: "Load Balancing", url: "/course/system-design-hld/scalability/load-balancing", isPremium: false },
          { title: "Horizontal vs Vertical Scaling", url: "/course/system-design-hld/scalability/scaling", isPremium: true },
          { title: "Auto Scaling", url: "/course/system-design-hld/scalability/auto-scaling", isPremium: true },
        ]
      },
      {
        title: "Databases",
        url: "/course/system-design-hld/databases",
        lessons: [
          { title: "SQL vs NoSQL", url: "/course/system-design-hld/databases/sql-nosql", isPremium: false },
          { title: "Sharding", url: "/course/system-design-hld/databases/sharding", isPremium: true },
          { title: "Replication", url: "/course/system-design-hld/databases/replication", isPremium: true },
        ]
      },
      {
        title: "Caching",
        url: "/course/system-design-hld/caching",
        lessons: [
          { title: "Cache Patterns", url: "/course/system-design-hld/caching/patterns", isPremium: false },
          { title: "CDN", url: "/course/system-design-hld/caching/cdn", isPremium: true },
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
        url: "/course/lld/design-patterns",
        lessons: [
          { title: "Singleton Pattern", url: "/course/lld/design-patterns/singleton", isPremium: false },
          { title: "Factory Pattern", url: "/course/lld/design-patterns/factory", isPremium: true },
          { title: "Observer Pattern", url: "/course/lld/design-patterns/observer", isPremium: true },
        ]
      },
      {
        title: "Object-Oriented Design",
        url: "/course/lld/oop",
        lessons: [
          { title: "SOLID Principles", url: "/course/lld/oop/solid", isPremium: false },
          { title: "Inheritance vs Composition", url: "/course/lld/oop/inheritance", isPremium: true },
        ]
      },
      {
        title: "System Design Examples",
        url: "/course/lld/examples",
        lessons: [
          { title: "Parking Lot System", url: "/course/lld/examples/parking-lot", isPremium: true },
          { title: "Elevator System", url: "/course/lld/examples/elevator", isPremium: true },
        ]
      }
    ]
  },
  {
    id: "behavioral",
    title: "Behavioral",
    icon: MessageSquare,
    modules: [
      {
        title: "Interview Techniques",
        url: "/course/behavioral/techniques",
        lessons: [
          { title: "STAR Method", url: "/course/behavioral/techniques/star-method", isPremium: false },
          { title: "Storytelling", url: "/course/behavioral/techniques/storytelling", isPremium: true },
        ]
      },
      {
        title: "Common Questions",
        url: "/course/behavioral/questions",
        lessons: [
          { title: "Leadership Examples", url: "/course/behavioral/questions/leadership", isPremium: false },
          { title: "Conflict Resolution", url: "/course/behavioral/questions/conflict", isPremium: true },
          { title: "Failure Stories", url: "/course/behavioral/questions/failure", isPremium: true },
        ]
      },
      {
        title: "Company Culture",
        url: "/course/behavioral/culture",
        lessons: [
          { title: "Culture Fit", url: "/course/behavioral/culture/fit", isPremium: true },
          { title: "Values Alignment", url: "/course/behavioral/culture/values", isPremium: true },
        ]
      }
    ]
  }
];

const mainItems = [
  { title: "Dashboard", url: "/dashboard", icon: Home },
  { title: "Settings", url: "/settings", icon: Settings },
];

export function AppSidebar() {
  const { state } = useSidebar();
  const location = useLocation();
  const { user } = useAuth();
  const currentPath = location.pathname;
  const [searchQuery, setSearchQuery] = useState("");
  
  // Extract current course from URL path
  const pathSegments = currentPath.split('/');
  const currentCourseSlug = pathSegments[2]; // /course/:courseSlug/...
  const currentCourse = courses.find(course => course.id === currentCourseSlug);
  
  const [openGroups, setOpenGroups] = useState<Record<string, boolean>>({
    "dsa": true,
    "system-design-hld": false,
    "lld": false,
    "behavioral": false,
  });
  
  const [openModules, setOpenModules] = useState<Record<string, boolean>>({});

  const isActive = (path: string) => currentPath === path;
  const isLessonActive = (lessonUrl: string) => currentPath === lessonUrl;
  const isModuleActive = (module: any) => 
    module.lessons?.some((lesson: any) => isLessonActive(lesson.url));
  const isCourseActive = (course: any) => 
    course.modules?.some((module: any) => isModuleActive(module));

  const getNavClass = (active: boolean) =>
    active ? "bg-sidebar-accent text-sidebar-accent-foreground font-medium" : "hover:bg-sidebar-accent/50";

  const toggleGroup = (groupKey: string) => {
    setOpenGroups(prev => {
      const newState = { ...prev };
      // Close all other groups when opening a new one (accordion behavior)
      Object.keys(newState).forEach(key => {
        newState[key] = false;
      });
      // Toggle the selected group
      newState[groupKey] = !prev[groupKey];
      return newState;
    });
    
    // Also close all modules when switching groups
    setOpenModules({});
  };

  const toggleModule = (moduleKey: string, courseId: string) => {
    setOpenModules(prev => {
      const newState = { ...prev };
      // Close all modules in the same course (accordion behavior within course)
      Object.keys(newState).forEach(key => {
        if (key.startsWith(courseId + '-')) {
          newState[key] = false;
        }
      });
      // Toggle the selected module
      newState[moduleKey] = !prev[moduleKey];
      return newState;
    });
  };
  
  // Filter courses and lessons based on search query
  const filteredCourses = courses.map(course => ({
    ...course,
    modules: course.modules.map(module => ({
      ...module,
      lessons: module.lessons.filter(lesson =>
        lesson.title.toLowerCase().includes(searchQuery.toLowerCase()) ||
        module.title.toLowerCase().includes(searchQuery.toLowerCase()) ||
        course.title.toLowerCase().includes(searchQuery.toLowerCase())
      )
    })).filter(module => module.lessons.length > 0)
  })).filter(course => course.modules.length > 0);

  const hasAccess = (isPremium: boolean) => {
    // For demo purposes, show premium content as locked for non-authenticated users
    return !isPremium || user !== null;
  };

  return (
    <Sidebar className={`${state === "collapsed" ? "w-14" : "w-80"} transition-all duration-300`}>
      <SidebarContent>
        {/* Logo/Brand */}
        <div className="p-4 border-b border-sidebar-border">
          <div className="flex items-center gap-2">
            <div className="w-8 h-8 bg-gradient-to-br from-primary to-blue-600 rounded-lg flex items-center justify-center">
              <BookOpen className="w-4 h-4 text-white" />
            </div>
            {state === "expanded" && (
              <div>
                <h1 className="font-bold text-lg text-sidebar-foreground">Interview60</h1>
                <p className="text-xs text-sidebar-foreground/70">Ace your interviews</p>
              </div>
            )}
          </div>
        </div>

        {/* Search Box */}
        {state === "expanded" && (
          <div className="p-4 border-b border-sidebar-border">
            <div className="relative">
              <Search className="absolute left-3 top-1/2 transform -translate-y-1/2 w-4 h-4 text-muted-foreground" />
              <Input
                placeholder="Search courses..."
                value={searchQuery}
                onChange={(e) => setSearchQuery(e.target.value)}
                className="pl-9 h-9"
              />
            </div>
          </div>
        )}

        {/* Main Navigation */}
        <SidebarGroup>
          <SidebarGroupLabel>Navigation</SidebarGroupLabel>
          <SidebarGroupContent>
            <SidebarMenu>
              {mainItems.map((item) => (
                <SidebarMenuItem key={item.title}>
                  <SidebarMenuButton asChild>
                    <NavLink to={item.url} className={getNavClass(isActive(item.url))}>
                      <item.icon className="w-4 h-4" />
                      {state === "expanded" && <span>{item.title}</span>}
                    </NavLink>
                  </SidebarMenuButton>
                </SidebarMenuItem>
              ))}
            </SidebarMenu>
          </SidebarGroupContent>
        </SidebarGroup>

        {/* Course Content */}
        {currentCourse && (
          <SidebarGroup>
            <SidebarGroupLabel>
              <div className="flex items-center gap-2">
                <currentCourse.icon className="w-4 h-4" />
                {state === "expanded" && <span>{currentCourse.title}</span>}
              </div>
            </SidebarGroupLabel>
            <SidebarGroupContent>
              <SidebarMenu>
                {currentCourse.modules.map((module) => {
                  const moduleKey = `${currentCourse.id}-${module.title.toLowerCase().replace(/\s+/g, '-')}`;
                  const isModuleOpen = openModules[moduleKey];
                  const moduleActive = isModuleActive(module);

                  return (
                    <Collapsible key={module.title} open={isModuleOpen} onOpenChange={() => toggleModule(moduleKey, currentCourse.id)}>
                      <SidebarMenuItem>
                        <CollapsibleTrigger asChild>
                          <SidebarMenuButton className={`${getNavClass(moduleActive)} font-medium`}>
                            <span className="flex-1 text-left">{module.title}</span>
                            <ChevronRight className={`w-3 h-3 transition-transform ${isModuleOpen ? 'rotate-90' : ''}`} />
                          </SidebarMenuButton>
                        </CollapsibleTrigger>
                        {state === "expanded" && (
                          <CollapsibleContent>
                            <SidebarMenuSub>
                              <div className="ml-4 space-y-1">
                                {module.lessons
                                  .filter(lesson =>
                                    lesson.title.toLowerCase().includes(searchQuery.toLowerCase()) ||
                                    module.title.toLowerCase().includes(searchQuery.toLowerCase()) ||
                                    currentCourse.title.toLowerCase().includes(searchQuery.toLowerCase())
                                  )
                                  .map((lesson) => (
                                    <SidebarMenuSubItem key={lesson.title}>
                                      <SidebarMenuSubButton asChild>
                                        <NavLink 
                                          to={lesson.url} 
                                          className={`${getNavClass(isLessonActive(lesson.url))} flex items-center gap-2 text-sm py-1`}
                                        >
                                          <span className="flex-1">{lesson.title}</span>
                                          {lesson.isPremium && !hasAccess(lesson.isPremium) && (
                                            <Lock className="w-3 h-3 text-yellow-500" />
                                          )}
                                          {lesson.isPremium && (
                                            <Badge variant="secondary" className="text-xs px-1 py-0">
                                              <Crown className="w-2 h-2 mr-1" />
                                              PRO
                                            </Badge>
                                          )}
                                        </NavLink>
                                      </SidebarMenuSubButton>
                                    </SidebarMenuSubItem>
                                  ))}
                              </div>
                            </SidebarMenuSub>
                          </CollapsibleContent>
                        )}
                      </SidebarMenuItem>
                    </Collapsible>
                  );
                })}
              </SidebarMenu>
            </SidebarGroupContent>
          </SidebarGroup>
        )}
      </SidebarContent>
    </Sidebar>
  );
}