import { useState, useEffect } from 'react';
import { useParams, Link } from 'react-router-dom';
import { Layout } from '@/components/Layout';
import { Button } from '@/components/ui/button';
import { Progress } from '@/components/ui/progress';
import { Badge } from '@/components/ui/badge';
import { Separator } from '@/components/ui/separator';
import { 
  ChevronLeft, 
  ChevronRight, 
  Clock, 
  BookOpen, 
  Lock,
  Crown,
  CheckCircle,
  Play,
  Code
} from 'lucide-react';
import { useAuth } from '@/hooks/useAuth';
import { Card, CardContent } from '@/components/ui/card';
import { CodeBlock } from '@/components/CodeBlock';
import { lessonData } from '@/data/lessonData';
import { ScrollToTop } from '@/components/ScrollToTop';
import {
  Breadcrumb,
  BreadcrumbItem,
  BreadcrumbLink,
  BreadcrumbList,
  BreadcrumbPage,
  BreadcrumbSeparator,
} from '@/components/ui/breadcrumb';
import dsaCourseData from '@/data/courses/dsaCourse.json';
import systemDesignCourseData from '@/data/courses/systemDesignCourse.json';
import lldCourseData from '@/data/courses/lldCourse.json';
import behavioralCourseData from '@/data/courses/behavioralCourse.json';

const courseMap: Record<string, any> = {
  'dsa': dsaCourseData,
  'system-design': systemDesignCourseData,
  'lld': lldCourseData,
  'behavioral': behavioralCourseData,
};

export default function LessonPage() {
  const { courseSlug, categorySlug, lessonSlug } = useParams();
  const { user } = useAuth();
  const [lesson, setLesson] = useState<any>(null);
  const [progress, setProgress] = useState(0);
  const [prevLesson, setPrevLesson] = useState<{ path: string; title: string } | null>(null);
  const [nextLesson, setNextLesson] = useState<{ path: string; title: string } | null>(null);

  useEffect(() => {
    // Simulate loading lesson data
    const lessonKey = categorySlug ? `${courseSlug}-${categorySlug}-${lessonSlug}` : `${courseSlug}-${lessonSlug}`;
    const lessonData = getLessonData(lessonKey);
    setLesson(lessonData);
    
    // Calculate prev/next lessons
    if (courseSlug && categorySlug && lessonSlug) {
      const courseData = courseMap[courseSlug];
      if (courseData) {
        const module = courseData.modules.find((m: any) => m.slug === categorySlug);
        if (module) {
          const currentIndex = module.items.findIndex((item: any) => !item.isHeader && item.slug === lessonSlug);
          const lessons = module.items.filter((item: any) => !item.isHeader);
          const currentLessonIndex = lessons.findIndex((item: any) => item.slug === lessonSlug);
          
          if (currentLessonIndex > 0) {
            const prev = lessons[currentLessonIndex - 1];
            setPrevLesson({
              path: `/course/${courseSlug}/${categorySlug}/${prev.slug}`,
              title: prev.title
            });
          } else {
            setPrevLesson(null);
          }
          
          if (currentLessonIndex < lessons.length - 1) {
            const next = lessons[currentLessonIndex + 1];
            setNextLesson({
              path: `/course/${courseSlug}/${categorySlug}/${next.slug}`,
              title: next.title
            });
          } else {
            setNextLesson(null);
          }
        }
      }
    }
    
    // Simulate progress
    const timer = setTimeout(() => setProgress(75), 1000);
    return () => clearTimeout(timer);
  }, [courseSlug, categorySlug, lessonSlug]);

  const getLessonData = (key: string) => {
    return lessonData[key] || {
      title: 'Lesson Not Found',
      course: 'Unknown',
      duration: 0,
      isPremium: false,
      content: 'This lesson is not available.',
      codeExamples: []
    };
  };

  const hasAccess = (isPremium: boolean) => {
    return !isPremium || user !== null;
  };

  if (!lesson) {
    return (
      <Layout>
        <div className="flex items-center justify-center h-64">
          <div className="text-center">
            <div className="animate-spin rounded-full h-8 w-8 border-b-2 border-primary mx-auto"></div>
            <p className="mt-2 text-muted-foreground">Loading lesson...</p>
          </div>
        </div>
      </Layout>
    );
  }

  const isLockedContent = lesson.isPremium && !hasAccess(lesson.isPremium);

  return (
    <Layout>
      <div className="max-w-7xl mx-auto p-4 sm:p-6">
        <div className="grid grid-cols-1 xl:grid-cols-4 gap-6">
          {/* Main Content */}
          <div className="xl:col-span-3 min-w-0">
            {/* Header */}
            <div className="mb-8">
              {/* Breadcrumb Navigation */}
              <Breadcrumb className="mb-4">
                <BreadcrumbList>
                  <BreadcrumbItem>
                    <BreadcrumbLink asChild>
                      <Link to="/">Home</Link>
                    </BreadcrumbLink>
                  </BreadcrumbItem>
                  <BreadcrumbSeparator />
                  {courseSlug && (
                    <>
                      <BreadcrumbItem>
                        <BreadcrumbLink asChild>
                          <Link to={`/course/${courseSlug}`}>
                            {courseMap[courseSlug]?.title || courseSlug}
                          </Link>
                        </BreadcrumbLink>
                      </BreadcrumbItem>
                      <BreadcrumbSeparator />
                    </>
                  )}
                  {categorySlug && courseSlug && (
                    <>
                      <BreadcrumbItem>
                        <BreadcrumbLink asChild>
                          <Link to={`/course/${courseSlug}`}>
                            {courseMap[courseSlug]?.modules.find((m: any) => m.slug === categorySlug)?.title || categorySlug}
                          </Link>
                        </BreadcrumbLink>
                      </BreadcrumbItem>
                      <BreadcrumbSeparator />
                    </>
                  )}
                  <BreadcrumbItem>
                    <BreadcrumbPage>{lesson.title}</BreadcrumbPage>
                  </BreadcrumbItem>
                </BreadcrumbList>
              </Breadcrumb>

              <h1 className="text-3xl font-bold mb-3">{lesson.title}</h1>
              
              <div className="flex items-center justify-between flex-wrap gap-3">
                <div className="flex items-center gap-3 text-sm text-muted-foreground">
                  {lesson.isPremium && (
                    <Badge variant="secondary" className="gap-1">
                      <Crown className="w-3 h-3" />
                      PRO
                    </Badge>
                  )}
                </div>
                
                <div className="flex items-center gap-2">
                  {prevLesson ? (
                    <Button variant="outline" size="sm" asChild>
                      <Link to={prevLesson.path}>
                        <ChevronLeft className="w-4 h-4 mr-1" />
                        Previous
                      </Link>
                    </Button>
                  ) : (
                    <Button variant="outline" size="sm" disabled>
                      <ChevronLeft className="w-4 h-4 mr-1" />
                      Previous
                    </Button>
                  )}
                  {nextLesson ? (
                    <Button size="sm" asChild>
                      <Link to={nextLesson.path}>
                        Next
                        <ChevronRight className="w-4 h-4 ml-1" />
                      </Link>
                    </Button>
                  ) : (
                    <Button size="sm" disabled>
                      Next
                      <ChevronRight className="w-4 h-4 ml-1" />
                    </Button>
                  )}
                </div>
              </div>
            </div>

            {/* Content */}
            <div className="max-w-none relative">
              {isLockedContent ? (
                <div className="relative min-h-[600px] bg-gradient-to-b from-muted/30 via-muted/50 to-muted rounded-lg overflow-hidden">
                  {/* Blurred placeholder content */}
                  <div className="p-8 space-y-6 blur-sm select-none pointer-events-none opacity-60">
                    <div className="h-8 bg-foreground/10 rounded w-3/4"></div>
                    <div className="space-y-3">
                      <div className="h-4 bg-foreground/10 rounded"></div>
                      <div className="h-4 bg-foreground/10 rounded w-5/6"></div>
                      <div className="h-4 bg-foreground/10 rounded w-4/6"></div>
                    </div>
                    <div className="h-8 bg-foreground/10 rounded w-2/3 mt-8"></div>
                    <div className="space-y-3">
                      <div className="h-4 bg-foreground/10 rounded"></div>
                      <div className="h-4 bg-foreground/10 rounded w-5/6"></div>
                      <div className="h-4 bg-foreground/10 rounded w-3/4"></div>
                      <div className="h-4 bg-foreground/10 rounded w-4/6"></div>
                    </div>
                    <div className="h-32 bg-foreground/10 rounded mt-8"></div>
                    <div className="space-y-3">
                      <div className="h-4 bg-foreground/10 rounded"></div>
                      <div className="h-4 bg-foreground/10 rounded w-5/6"></div>
                    </div>
                  </div>
                  
                  {/* Premium overlay */}
                  <div className="absolute inset-0 bg-gradient-to-b from-transparent via-background/60 to-background flex items-center justify-center">
                    <div className="text-center space-y-4 p-8">
                      <Lock className="w-16 h-16 mx-auto text-muted-foreground" />
                      <h3 className="text-2xl font-bold">Premium Content</h3>
                      <p className="text-muted-foreground max-w-md">
                        Unlock this lesson and get access to advanced topics, code examples, and exclusive materials.
                      </p>
                      <Button size="lg" asChild>
                        <Link to="/upgrade">
                          <Crown className="w-5 h-5 mr-2" />
                          Unlock Premium Content
                        </Link>
                      </Button>
                    </div>
                  </div>
                </div>
              ) : (
                <div className="space-y-3 leading-relaxed">
                  {lesson.content.split('\n').map((line: string, index: number) => {
                    if (line.startsWith('## ')) {
                      return <h2 key={index} className="text-2xl font-bold mt-6 mb-3 text-foreground">{line.slice(3)}</h2>;
                    }
                    if (line.startsWith('### ')) {
                      return <h3 key={index} className="text-xl font-semibold mt-5 mb-2 text-foreground">{line.slice(4)}</h3>;
                    }
                    if (line.startsWith('> ')) {
                      return (
                        <blockquote key={index} className="border-l-4 border-primary pl-4 py-2 bg-primary/5 rounded-r-lg my-3">
                          <p className="text-muted-foreground italic m-0 leading-relaxed">{line.slice(2)}</p>
                        </blockquote>
                      );
                    }
                    if (line.startsWith('- ')) {
                      return (
                        <li key={index} className="ml-4 mb-2 text-foreground leading-relaxed">
                          {line.slice(2).split('**').map((part, i) => 
                            i % 2 === 1 ? <strong key={i} className="font-semibold text-foreground">{part}</strong> : part
                          ).map((part, i) => 
                            typeof part === 'string' && part.includes('`') 
                              ? part.split('`').map((code, j) => 
                                  j % 2 === 1 ? <code key={j} className="font-mono text-[hsl(var(--accent-pink))] bg-primary/10 px-1.5 py-0.5 rounded text-sm">{code}</code> : code
                                )
                              : part
                          )}
                        </li>
                      );
                    }
                    if (line.match(/^\d+\. /)) {
                      return (
                        <li key={index} className="ml-4 mb-2 text-foreground leading-relaxed">
                          {line.replace(/^\d+\. /, '').split('**').map((part, i) => 
                            i % 2 === 1 ? <strong key={i} className="font-semibold text-foreground">{part}</strong> : part
                          ).map((part, i) => 
                            typeof part === 'string' && part.includes('`') 
                              ? part.split('`').map((code, j) => 
                                  j % 2 === 1 ? <code key={j} className="font-mono text-[hsl(var(--accent-pink))] bg-primary/10 px-1.5 py-0.5 rounded text-sm">{code}</code> : code
                                )
                              : part
                          )}
                        </li>
                      );
                    }
                    if (line.startsWith('![') && line.includes('](')) {
                      const altMatch = line.match(/!\[(.*?)\]/);
                      const urlMatch = line.match(/\((.*?)\)/);
                      if (altMatch && urlMatch) {
                        return (
                          <img 
                            key={index} 
                            src={urlMatch[1]} 
                            alt={altMatch[1]} 
                            className="rounded-lg my-4 max-w-full h-auto"
                          />
                        );
                      }
                    }
                    if (line.trim() && !line.startsWith('#') && !line.startsWith('>') && !line.startsWith('-') && !line.match(/^\d+\./) && !line.startsWith('![')) {
                      return (
                        <p key={index} className="mb-3 text-foreground leading-relaxed">
                          {line.split('**').map((part, i) => 
                            i % 2 === 1 ? <strong key={i} className="font-semibold text-foreground">{part}</strong> : part
                          ).map((part, i) => 
                            typeof part === 'string' && part.includes('`') 
                              ? part.split('`').map((code, j) => 
                                  j % 2 === 1 ? <code key={j} className="font-mono text-[hsl(var(--accent-pink))] bg-primary/10 px-1.5 py-0.5 rounded text-sm">{code}</code> : code
                                )
                              : part
                          )}
                        </p>
                      );
                    }
                    return null;
                  })}
                </div>
              )}
            </div>

            {/* Code Examples - Only show for unlocked content */}
            {!isLockedContent && lesson.codeExamples && lesson.codeExamples.length > 0 && (
              <div className="mt-8 space-y-6">
                <Separator />
                <h2 className="text-xl font-semibold flex items-center gap-2">
                  <Code className="w-5 h-5" />
                  Code Examples
                </h2>
                
                {lesson.codeExamples.map((example: any, index: number) => (
                  <CodeBlock
                    key={index}
                    title={example.title}
                    code={example.code}
                    language={example.language}
                    showLanguageSelector={true}
                  />
                ))}
              </div>
            )}

            {/* Navigation */}
            <div className="flex justify-between items-center mt-8 pt-6 border-t">
              {prevLesson ? (
                <Button variant="outline" asChild>
                  <Link to={prevLesson.path}>
                    <ChevronLeft className="w-4 h-4 mr-2" />
                    <span className="truncate max-w-[150px]">{prevLesson.title}</span>
                  </Link>
                </Button>
              ) : (
                <Button variant="outline" disabled>
                  <ChevronLeft className="w-4 h-4 mr-2" />
                  Previous Lesson
                </Button>
              )}
              
              {nextLesson ? (
                <Button variant="outline" asChild>
                  <Link to={nextLesson.path}>
                    <span className="truncate max-w-[150px]">{nextLesson.title}</span>
                    <ChevronRight className="w-4 h-4 ml-2" />
                  </Link>
                </Button>
              ) : (
                <Button variant="outline" disabled>
                  Next Lesson
                  <ChevronRight className="w-4 h-4 ml-2" />
                </Button>
              )}
            </div>
          </div>

          {/* Sidebar - Hidden on mobile, shown on larger screens */}
          <div className="xl:col-span-1 hidden xl:block p-6 space-y-6">
            {/* Related Lessons */}
            <Card>
              <CardContent className="p-4">
                <h3 className="font-semibold mb-3">Up Next</h3>
                <div className="space-y-3">
                  <div className="flex items-center gap-3 p-2 rounded hover:bg-accent cursor-pointer">
                    <Play className="w-4 h-4 text-muted-foreground" />
                    <div className="flex-1 min-w-0">
                      <p className="text-sm font-medium truncate">Sliding Window Pattern</p>
                    </div>
                  </div>
                  
                  <div className="flex items-center gap-3 p-2 rounded hover:bg-accent cursor-pointer">
                    <Lock className="w-4 h-4 text-yellow-500" />
                    <div className="flex-1 min-w-0">
                      <p className="text-sm font-medium truncate">Dynamic Programming</p>
                      <Badge variant="secondary" className="text-xs ml-2">PRO</Badge>
                    </div>
                  </div>
                  
                  <div className="flex items-center gap-3 p-2 rounded hover:bg-accent cursor-pointer">
                    <Play className="w-4 h-4 text-muted-foreground" />
                    <div className="flex-1 min-w-0">
                      <p className="text-sm font-medium truncate">Binary Search</p>
                    </div>
                  </div>
                </div>
              </CardContent>
            </Card>

            {/* Study Tips */}
            <Card>
              <CardContent className="p-4">
                <h3 className="font-semibold mb-3">💡 Study Tips</h3>
                <ul className="text-sm space-y-2 text-muted-foreground">
                  <li>• Practice coding along with examples</li>
                  <li>• Take notes on key patterns</li>
                  <li>• Solve related problems</li>
                  <li>• Review previous lessons</li>
                </ul>
              </CardContent>
            </Card>
          </div>
        </div>
      </div>
      <ScrollToTop />
    </Layout>
  );
}