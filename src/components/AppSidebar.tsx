// /components/AppSidebar.tsx
import { useState, useEffect, useRef } from 'react';
import { Link, useLocation, useNavigate  } from 'react-router-dom';
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
  useSidebar,
} from '@/components/ui/sidebar';
import {
  FolderOpen,
  Lock,
  Database,
  Brain,
  GitBranch,
  MessageSquare,
  ChevronRight,
  FileText,
} from 'lucide-react';
import { Collapsible, CollapsibleContent, CollapsibleTrigger } from '@/components/ui/collapsible';
import { Input } from '@/components/ui/input';
import { ScrollArea } from '@/components/ui/scroll-area';
import { cn } from '@/lib/utils';

// Import courses
import dsaCourseData from '@/data/courses/dsa/dsa.json';
import systemDesignCourseData from '@/data/courses/system-design/system-design.json';
import lldCourseData from '@/data/courses/lldCourse.json';
import behavioralCourseData from '@/data/courses/behavioralCourse.json';

const courses: any[] = [
  { ...dsaCourseData, icon: Database },
  { ...systemDesignCourseData, icon: Brain },
  { ...lldCourseData, icon: GitBranch },
  { ...behavioralCourseData, icon: MessageSquare },
];

export function AppSidebar() {
  const location = useLocation();
  const pathSegments = location.pathname.split('/');
  const courseSlug = pathSegments[2];
  const course = courses.find((c) => c.id === courseSlug);
  const { setOpenMobile  } = useSidebar(); // ✅ Sidebar context hook

  const [searchQuery, setSearchQuery] = useState('');
  const [openModuleIndex, setOpenModuleIndex] = useState<number | null>(null);
  const [openModuleIndices, setOpenModuleIndices] = useState<number[]>([]);
  const activeItemRef = useRef<HTMLLIElement>(null);

  // ✅ Helper to check if text matches the search
  const matchesSearch = (text: string) =>
    text?.toLowerCase().includes(searchQuery.toLowerCase());

  // Auto-expand modules when searching
  useEffect(() => {
    if (searchQuery && course) {
      // Expand all modules with matching content
      const matchingIndices = course.modules
        .map((module: any, index: number) => {
          const hasMatch = matchesSearch(module.title) ||
            module.sections?.some((section: any) =>
              matchesSearch(section.title) ||
              section.lessons?.some((lesson: any) => {
                if (lesson.lessons) {
                  return matchesSearch(lesson.title) || lesson.lessons.some((sl: any) => matchesSearch(sl.title));
                }
                return matchesSearch(lesson.title);
              })
            );
          return hasMatch ? index : -1;
        })
        .filter((index: number) => index >= 0);
      
      console.log('Matching module indices:', matchingIndices);
      setOpenModuleIndices(matchingIndices);
    } else {
      setOpenModuleIndices([]);
    }
  }, [searchQuery, course]);

const navigate = useNavigate();

useEffect(() => {
  if (!course) return;

  // 🧭 1️⃣ Detect if we’re at course root (e.g. /course/system-design)
  const isCourseRoot = pathSegments.length <= 3;

  // 🧩 2️⃣ Try to find the active module by path
  const activeModuleIndex =
    course.modules.findIndex((module: any) =>
      module.sections?.some((section: any) =>
        section.lessons.some((lesson: any) => {
          if (lesson.lessons) {
            // has sub-lessons
            return lesson.lessons.some((sl: any) =>
              location.pathname.includes(`/${module.slug}/${section.slug}/${lesson.slug}/${sl.slug}`)
            );
          }
          return location.pathname.includes(`/${module.slug}/${section.slug}/${lesson.slug}`);
        })
      )
    ) ?? 0;

  // 🧭 3️⃣ Default to first module if none active
  const openIndex = activeModuleIndex >= 0 ? activeModuleIndex : 0;
  setOpenModuleIndex(openIndex);

  // 🚀 4️⃣ If at course root (like /course/system-design) → redirect to first lesson
  if (isCourseRoot) {
    const firstModule = course.modules?.[0];
    const firstSection = firstModule?.sections?.[0];
    const firstLesson = firstSection?.lessons?.[0];

    if (firstLesson) {
      let firstPath = '';

      if (firstLesson.lessons && firstLesson.lessons.length > 0) {
        // 🧠 subsection lesson
        const subLesson = firstLesson.lessons[0];
        firstPath = `/course/${courseSlug}/${firstModule.slug}/${firstSection.slug}/${firstLesson.slug}/${subLesson.slug}`;
      } else {
        // 🧠 normal lesson
        firstPath = `/course/${courseSlug}/${firstModule.slug}/${firstSection.slug}/${firstLesson.slug}`;
      }

      // ✅ Navigate only if not already there
      if (location.pathname !== firstPath) {
        navigate(firstPath, { replace: true });
      }
    }
  }
}, [location.pathname, course]);

// 🎯 Auto-scroll to active item when it's rendered
useEffect(() => {
  // Wait for the module to fully expand and DOM to render
  // Using animation frame + extra delay to ensure Collapsible animation completes
  const frame = requestAnimationFrame(() => {
    const timer = setTimeout(() => {
      if (activeItemRef.current) {
        console.log('✅ Active item found, scrolling to:', {
          element: activeItemRef.current,
          pathname: location.pathname,
          text: activeItemRef.current.textContent
        });
        
        // Scroll the parent SidebarMenuItem into view
        activeItemRef.current.scrollIntoView({
          behavior: 'smooth',
          block: 'center'
        });
      } else {
        console.warn('⚠️ Active item ref not set. Checking DOM...', {
          pathname: location.pathname,
          openModuleIndex: openModuleIndex
        });
        
        // Retry once more with longer delay
        const retryTimer = setTimeout(() => {
          if (activeItemRef.current) {
            console.log('✅ Active item found on retry');
            activeItemRef.current.scrollIntoView({
              behavior: 'smooth',
              block: 'center'
            });
          } else {
            console.error('❌ Active item still not found after retry');
          }
        }, 400);
        
        return () => clearTimeout(retryTimer);
      }
    }, 300); // Wait for Collapsible animation to complete
    
    return () => clearTimeout(timer);
  });
  
  return () => cancelAnimationFrame(frame);
}, [location.pathname, openModuleIndex]);

  const handleModuleToggle = (index: number) => {
    setOpenModuleIndex(openModuleIndex === index ? null : index);
  };

  // ✅ Renders lessons inside module → section → lesson → sublesson
  const renderLessons = (module: any) => {
    if (!module.sections) return null;

    return module.sections
      .filter(
        (section: any) =>
          matchesSearch(section.title) ||
          section.lessons?.some((lesson: any) => {
            if (lesson.sections) {
              return (
                matchesSearch(lesson.title) ||
                lesson.sections.some((sl: any) => matchesSearch(sl.title))
              );
            }
            return matchesSearch(lesson.title);
          })
      )
      .map((section: any, sectionIndex: number) => (
        <div key={sectionIndex} className="mt-2">
          {/* Section header */}
          <div className="px-2 py-1.5 text-[11px] font-semibold text-foreground/60 uppercase tracking-wider">
            {section.title}
          </div>

          {/* Lessons inside section */}
          {section.lessons
            .filter((lesson: any) => {
              if (lesson.sections) {
                return (
                  matchesSearch(lesson.title) ||
                  lesson.sections.some((sl: any) => matchesSearch(sl.title))
                );
              }
              return matchesSearch(lesson.title);
            })
            .map((lesson: any, lessonIndex: number) => {
              const hasSubLessons = Array.isArray(lesson.lessons) && lesson.lessons.length > 0;

              // Case 1️⃣: Lesson with sub-lessons
              if (hasSubLessons) {
                return (
                  <div key={lessonIndex} className="mt-2">
                    <div className="px-2 py-1 text-[11px] font-semibold text-foreground/50">
                      {lesson.title}
                    </div>
                    <div className="flex flex-col">
                      {lesson.lessons
                        .filter((subLesson: any) => matchesSearch(subLesson.title))
                        .map((subLesson: any, subIdx: number) => {
                          const subLessonPath = `/course/${courseSlug}/${module.slug}/${section.slug}/${lesson.slug}/${subLesson.slug}`;
                          const isActive = location.pathname === subLessonPath;
                          const isLocked = subLesson.isPremium;
                          
                          if (isActive) {
                            console.log('🔍 Found active sub-lesson:', {
                              title: subLesson.title,
                              path: subLessonPath,
                              currentPath: location.pathname
                            });
                          }
                          
                          return (
                            <SidebarMenuItem 
                              key={`${lessonIndex}-${subIdx}`}
                              ref={isActive ? activeItemRef : null}
                            >
                              <SidebarMenuButton
                                asChild
                                isActive={isActive}
                                className={cn(
                                  'w-full py-1.5 px-2 h-auto rounded-md transition-colors',
                                  isActive && 'bg-pink-100/60 dark:bg-pink-900/20 font-medium',
                                  !isActive && 'hover:bg-accent/60 text-foreground/80 hover:text-pink-400 dark:hover:text-pink-300'
                                )}
                              >
                                <Link to={subLessonPath} className="flex items-center gap-2 w-full">
                                  <FileText className={cn(
                                    "h-3.5 w-3.5 flex-shrink-0",
                                    isActive ? "text-pink-600 dark:text-pink-400" : "text-muted-foreground"
                                  )} />
                                  <span className={cn("text-[13px] flex-1 min-w-0 truncate max-w-[250px]", isActive && "text-pink-600 dark:text-pink-400 underline decoration-2 underline-offset-2")} title={subLesson.title}>
                                    {subLesson.title}
                                  </span>
                                  {isLocked && (
                                    <Lock className="h-3 w-3 ml-auto flex-shrink-0 text-yellow-600" />
                                  )}
                                </Link>
                              </SidebarMenuButton>
                            </SidebarMenuItem>
                          );
                        })}
                    </div>
                  </div>
                );
              }

              // Case 2️⃣: Normal clickable lesson
              const lessonPath = `/course/${courseSlug}/${module.slug}/${section.slug}/${lesson.slug}`;
              const isActive = location.pathname === lessonPath;
              const isLocked = lesson.isPremium;
              
              if (isActive) {
                console.log('🔍 Found active normal lesson:', {
                  title: lesson.title,
                  path: lessonPath,
                  currentPath: location.pathname
                });
              }
              
              return (
                <SidebarMenuItem 
                  key={lessonIndex}
                  ref={isActive ? activeItemRef : null}
                >
                  <SidebarMenuButton
                    asChild
                    isActive={isActive}
                    className={cn(
                      'w-full py-1.5 px-2 h-auto rounded-md transition-colors',
                      isActive && 'bg-pink-100/60 dark:bg-pink-900/20 font-medium',
                      !isActive && 'hover:bg-accent/60 text-foreground/80 hover:text-pink-400 dark:hover:text-pink-300'
                    )}
                  >
                    <Link to={lessonPath} 
                      onClick={() => {
                        if (window.innerWidth < 768) setOpenMobile(false);
                      }}
                      className="flex items-center gap-2 w-full">
                      <FileText className={cn(
                        "h-3.5 w-3.5 flex-shrink-0",
                        isActive ? "text-pink-600 dark:text-pink-400" : "text-muted-foreground"
                      )} />
                      <span className={cn("text-[13px] flex-1 min-w-0 truncate max-w-[250px]", isActive && "text-pink-600 dark:text-pink-400")} title={lesson.title}>
                        {lesson.title}
                      </span>
                      {isLocked && (
                        <Lock className="h-3 w-3 ml-auto flex-shrink-0 text-yellow-600" />
                      )}
                    </Link>
                  </SidebarMenuButton>
                </SidebarMenuItem>
              );
            })}
        </div>
      ));
  };

  
  return (
    <Sidebar className="border-r w-full sm:w-96 lg:w-[420px] z-40 text-xs sm:text-sm" collapsible="none">
      {/* 🔍 Search Bar */}
      <SidebarHeader className="border-b px-3 py-2.5">
        <Input
          type="search"
          placeholder="Search..."
          className="h-8 text-sm"
          value={searchQuery}
          onChange={(e) => setSearchQuery(e.target.value)}
        />
      </SidebarHeader>

      <ScrollArea className="flex-1">
        <SidebarContent>
          {course && (
            <SidebarGroup>
              <SidebarGroupLabel
                className="text-base font-bold px-3 py-2 sticky top-0 bg-gradient-to-r from-pink-50 to-transparent dark:from-pink-950/20 dark:to-transparent z-10 border-b text-pink-600 dark:text-pink-400"
                title={course.title}
              >
                {course.title}
              </SidebarGroupLabel>

              <SidebarGroupContent>
                <SidebarMenu className="space-y-1 p-2">
                  {course.modules
                    .map((module: any, originalIndex: number) => ({ module, originalIndex }))
                    .filter(
                      ({ module }: any) =>
                        matchesSearch(module.title) ||
                        module.sections?.some((section: any) =>
                          matchesSearch(section.title) ||
                          section.lessons?.some((lesson: any) => {
                            if (lesson.sections) {
                              return (
                                matchesSearch(lesson.title) ||
                                lesson.sections.some((sl: any) => matchesSearch(sl.title))
                              );
                            }
                            return matchesSearch(lesson.title);
                          })
                        )
                    )
                    .map(({ module, originalIndex }: any) => {
                      const isOpen = searchQuery ? openModuleIndices.includes(originalIndex) : openModuleIndex === originalIndex;
                      return (
                        <Collapsible
                          key={originalIndex}
                          open={isOpen}
                          onOpenChange={() => !searchQuery && handleModuleToggle(originalIndex)}
                        >
                          <SidebarMenuItem>
                            <CollapsibleTrigger asChild>
                              <SidebarMenuButton
                                className={cn(
                                  'w-full justify-between py-2 px-2 rounded-md hover:bg-accent/70 transition-colors group/module',
                                  isOpen && 'bg-accent/70'
                                )}
                              >
                                <div className="flex items-center gap-2 min-w-0 flex-1 max-w-[320px]">
                                  <FolderOpen className="h-4 w-4 flex-shrink-0 text-primary" />
                                  <span className="text-sm font-bold break-words whitespace-normal text-foreground line-clamp-2 group-hover/module:text-pink-500 dark:group-hover/module:text-pink-300 transition-colors">
                                    {module.title}
                                  </span>
                                </div>
                                <ChevronRight
                                  className={cn(
                                    'h-4 w-4 transition-transform flex-shrink-0 text-foreground/60',
                                    isOpen && 'rotate-90'
                                  )}
                                />
                              </SidebarMenuButton>
                            </CollapsibleTrigger>

                            <CollapsibleContent className="mt-1 ml-1">
                              {renderLessons(module)}
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
