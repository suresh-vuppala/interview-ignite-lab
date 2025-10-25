// /components/AppSidebar.tsx
import { useState, useEffect } from 'react';
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
import {
  Code,
  Lock,
  Database,
  Brain,
  GitBranch,
  MessageSquare,
  ChevronDown,
  Circle,
  CircleDot,
} from 'lucide-react';
import { Collapsible, CollapsibleContent, CollapsibleTrigger } from '@/components/ui/collapsible';
import { Input } from '@/components/ui/input';
import { ScrollArea } from '@/components/ui/scroll-area';
import { cn } from '@/lib/utils';

// Import courses
import dsaCourseData from '@/data/courses/dsaCourse.json';
import systemDesignCourseData from '@/data/courses/systemDesignCourse.json';
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

  const [searchQuery, setSearchQuery] = useState('');
  const [openModuleIndex, setOpenModuleIndex] = useState<number | null>(null);

  // ✅ Helper to check if text matches the search
  const matchesSearch = (text: string) =>
    text?.toLowerCase().includes(searchQuery.toLowerCase());

  // ✅ Auto-open active module
  useEffect(() => {
    if (!course) return;

    const activeModuleIndex =
      course.modules.findIndex((module: any) =>
        module.sections?.some((section: any) =>
          section.lessons.some((lesson: any) => {
            if (lesson.lessons) {
              return lesson.lessons.some((sl) =>
                location.pathname.includes(`/${module.slug}/${section.slug}/${sl.slug}`)
              );
            }
            return location.pathname.includes(`/${module.slug}/${section.slug}/${lesson.slug}`);
          })
        )
      ) ?? null;

    if (activeModuleIndex !== null && openModuleIndex === null) {
      setOpenModuleIndex(activeModuleIndex);
    }
  }, [location.pathname, course]);

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
          <div className="px-3 py-2 text-xs font-bold text-muted-foreground uppercase tracking-wider">
            {section.title}
          </div>
          <div className="border-t border-gray-200 mb-1"></div>

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
              const hasSubLessons = Array.isArray(lesson.sections) && lesson.sections.length > 0;

              // Case 1️⃣: Lesson with sub-lessons
              if (hasSubLessons) {
                return (
                  <div key={lessonIndex} className="mt-2">
                    <div className="px-3 py-1 text-[13px] font-semibold text-muted-foreground/40">
                      {lesson.title}
                    </div>
                    <div className="flex flex-col">
                      {lesson.sections
                        .filter((subLesson: any) => matchesSearch(subLesson.title))
                        .map((subLesson: any, subIdx: number) => {
                          const subLessonPath = `/course/${courseSlug}/${module.slug}/${section.slug}/${lesson.slug}/${subLesson.slug}`;
                          const isActive = location.pathname === subLessonPath;
                          const isLocked = subLesson.isPremium;
                          return (
                            <SidebarMenuItem key={`${lessonIndex}-${subIdx}`}>
                              <SidebarMenuButton
                                asChild
                                isActive={isActive}
                                className={cn(
                                  'w-full py-2 px-3 rounded-md transition-colors',
                                  'hover:bg-accent/50',
                                  isActive && 'bg-primary/10 font-medium text-primary',
                                  !isActive && 'text-muted-foreground hover:text-foreground'
                                )}
                              >
                                <Link to={subLessonPath} className="flex items-center gap-2 w-full">
                                  {isActive ? (
                                    <CircleDot className="h-3.5 w-3.5 text-primary" />
                                  ) : (
                                    <Circle className="h-3.5 w-3.5" />
                                  )}
                                  <span className="text-sm flex-1 min-w-0 truncate" title={subLesson.title}>
                                    {subLesson.title.length > 25
                                      ? `${subLesson.title.slice(0, 25)}...`
                                      : subLesson.title}
                                  </span>
                                  {isLocked && (
                                    <Lock className="h-3 w-3 text-muted-foreground ml-auto" />
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
              return (
                <SidebarMenuItem key={lessonIndex}>
                  <SidebarMenuButton
                    asChild
                    isActive={isActive}
                    className={cn(
                      'w-full py-2 px-3 rounded-md transition-colors',
                      'hover:bg-accent/50',
                      isActive && 'bg-primary/10 font-medium text-primary',
                      !isActive && 'text-muted-foreground hover:text-foreground'
                    )}
                  >
                    <Link to={lessonPath} className="flex items-center gap-2 w-full">
                      {isActive ? (
                        <CircleDot className="h-3.5 w-3.5 text-primary" />
                      ) : (
                        <Circle className="h-3.5 w-3.5" />
                      )}
                      <span className="text-sm flex-1 min-w-0 truncate" title={lesson.title}>
                        {lesson.title.length > 25
                          ? `${lesson.title.slice(0, 25)}...`
                          : lesson.title}
                      </span>
                      {isLocked && (
                        <Lock className="h-3 w-3 text-muted-foreground ml-auto" />
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
    <Sidebar className="border-r w-full sm:w-72 lg:w-80 lg:min-w-[350px]">
      {/* 🔍 Search Bar */}
      <SidebarHeader className="border-b px-4 py-3">
        <Input
          type="search"
          placeholder="Search lessons..."
          className="pl-9 h-9"
          value={searchQuery}
          onChange={(e) => setSearchQuery(e.target.value)}
        />
      </SidebarHeader>

      <ScrollArea className="flex-1">
        <SidebarContent>
          {course && (
            <SidebarGroup>
              <SidebarGroupLabel
                className="text-base font-bold px-4 py-3 sticky top-0 bg-background/95 backdrop-blur z-10 border-b truncate"
                title={course.title}
              >
                {course.title}
              </SidebarGroupLabel>

              <SidebarGroupContent>
                <SidebarMenu className="space-y-1 p-2">
                  {course.modules
                    .filter(
                      (module: any) =>
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
                    .map((module: any, moduleIndex: number) => {
                      const isOpen = openModuleIndex === moduleIndex;
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
                                  'w-full justify-between py-2.5 px-3 rounded-md hover:bg-accent-600 transition-colors',
                                  isOpen && 'bg-accent/50'
                                )}
                              >
                                <div className="flex items-center gap-2 min-w-0 flex-1 overflow-hidden">
                                  <Code className="h-4 w-4 flex-shrink-0 text-primary" />
                                  <span className="text-[16px] font-bold truncate">
                                    {module.title.length > 25
                                      ? `${module.title.slice(0, 25)}...`
                                      : module.title}
                                  </span>
                                </div>
                                <ChevronDown
                                  className={cn(
                                    'h-4 w-4 transition-transform flex-shrink-0 ml-1',
                                    isOpen && 'rotate-180'
                                  )}
                                />
                              </SidebarMenuButton>
                            </CollapsibleTrigger>

                            <CollapsibleContent className="mt-1">
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
