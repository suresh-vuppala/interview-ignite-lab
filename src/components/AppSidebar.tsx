import { useState } from "react";
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
  Users
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
import { useAuth } from "@/hooks/useAuth";

const courseItems = [
  {
    title: "Getting Started",
    url: "/course/getting-started",
    icon: Home,
    category: "foundation",
    lessons: [
      { title: "Overview", url: "/course/getting-started/overview", isPremium: false },
      { title: "Setting Up Environment", url: "/course/getting-started/setup", isPremium: false },
      { title: "Interview Process", url: "/course/getting-started/interview-process", isPremium: true },
    ]
  },
  {
    title: "Data Structures",
    url: "/course/data-structures",
    icon: Database,
    category: "dsa",
    lessons: [
      { title: "Arrays & Strings", url: "/course/data-structures/arrays", isPremium: false },
      { title: "Linked Lists", url: "/course/data-structures/linked-lists", isPremium: false },
      { title: "Trees & Graphs", url: "/course/data-structures/trees", isPremium: true },
      { title: "Hash Tables", url: "/course/data-structures/hash-tables", isPremium: true },
    ]
  },
  {
    title: "Algorithms",
    url: "/course/algorithms",
    icon: Code,
    category: "dsa",
    lessons: [
      { title: "Two Pointers", url: "/course/algorithms/two-pointers", isPremium: false },
      { title: "Sliding Window", url: "/course/algorithms/sliding-window", isPremium: false },
      { title: "Dynamic Programming", url: "/course/algorithms/dp", isPremium: true },
      { title: "Graph Algorithms", url: "/course/algorithms/graph", isPremium: true },
    ]
  },
  {
    title: "System Design",
    url: "/course/system-design",
    icon: Brain,
    category: "system-design",
    lessons: [
      { title: "Fundamentals", url: "/course/system-design/fundamentals", isPremium: false },
      { title: "Scalability", url: "/course/system-design/scalability", isPremium: true },
      { title: "Database Design", url: "/course/system-design/databases", isPremium: true },
      { title: "Microservices", url: "/course/system-design/microservices", isPremium: true },
    ]
  },
  {
    title: "Behavioral",
    url: "/course/behavioral",
    icon: Users,
    category: "behavioral",
    lessons: [
      { title: "STAR Method", url: "/course/behavioral/star-method", isPremium: false },
      { title: "Common Questions", url: "/course/behavioral/common-questions", isPremium: true },
      { title: "Leadership Stories", url: "/course/behavioral/leadership", isPremium: true },
    ]
  },
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
  
  const [openGroups, setOpenGroups] = useState<Record<string, boolean>>({
    "getting-started": true,
    "data-structures": false,
    "algorithms": false,
    "system-design": false,
    "behavioral": false,
  });

  const isActive = (path: string) => currentPath === path;
  const isLessonActive = (lessonUrl: string) => currentPath === lessonUrl;
  const isGroupActive = (item: any) => 
    item.lessons?.some((lesson: any) => isLessonActive(lesson.url)) || isActive(item.url);

  const getNavClass = (active: boolean) =>
    active ? "bg-sidebar-accent text-sidebar-accent-foreground font-medium" : "hover:bg-sidebar-accent/50";

  const toggleGroup = (groupKey: string) => {
    setOpenGroups(prev => ({ ...prev, [groupKey]: !prev[groupKey] }));
  };

  const hasAccess = (isPremium: boolean) => {
    // For demo purposes, show premium content as locked for non-authenticated users
    return !isPremium || user !== null;
  };

  return (
    <Sidebar className={state === "collapsed" ? "w-14" : "w-80"}>
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
        <SidebarGroup>
          <SidebarGroupLabel>Courses</SidebarGroupLabel>
          <SidebarGroupContent>
            <SidebarMenu>
              {courseItems.map((item) => {
                const groupKey = item.url.split('/').pop() || '';
                const isOpen = openGroups[groupKey];
                const groupActive = isGroupActive(item);

                return (
                  <Collapsible key={item.title} open={isOpen} onOpenChange={() => toggleGroup(groupKey)}>
                    <SidebarMenuItem>
                      <CollapsibleTrigger asChild>
                        <SidebarMenuButton className={getNavClass(groupActive)}>
                          <item.icon className="w-4 h-4" />
                          {state === "expanded" && (
                            <>
                              <span className="flex-1 text-left">{item.title}</span>
                              <ChevronRight className={`w-4 h-4 transition-transform ${isOpen ? 'rotate-90' : ''}`} />
                            </>
                          )}
                        </SidebarMenuButton>
                      </CollapsibleTrigger>
                      {state === "expanded" && (
                        <CollapsibleContent>
                          <SidebarMenuSub>
                            {item.lessons.map((lesson) => (
                              <SidebarMenuSubItem key={lesson.title}>
                                <SidebarMenuSubButton asChild>
                                  <NavLink 
                                    to={lesson.url} 
                                    className={`${getNavClass(isLessonActive(lesson.url))} flex items-center gap-2`}
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
      </SidebarContent>
    </Sidebar>
  );
}