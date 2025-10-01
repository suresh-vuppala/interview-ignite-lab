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