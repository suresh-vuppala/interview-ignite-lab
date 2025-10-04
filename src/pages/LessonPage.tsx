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

export default function LessonPage() {
  const { courseSlug, categorySlug, lessonSlug } = useParams();
  const { user } = useAuth();
  const [lesson, setLesson] = useState<any>(null);
  const [progress, setProgress] = useState(0);

  useEffect(() => {
    // Simulate loading lesson data
    const lessonKey = categorySlug ? `${courseSlug}-${categorySlug}-${lessonSlug}` : `${courseSlug}-${lessonSlug}`;
    const lessonData = getLessonData(lessonKey);
    setLesson(lessonData);
    
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

  if (lesson.isPremium && !hasAccess(lesson.isPremium)) {
    return (
      <Layout>
        <div className="max-w-4xl mx-auto p-6">
          <Card className="text-center p-8">
            <CardContent className="space-y-4">
              <Lock className="w-16 h-16 text-muted-foreground mx-auto" />
              <h2 className="text-2xl font-bold">Premium Content</h2>
              <p className="text-muted-foreground">
                This lesson is part of our premium content. Upgrade to access advanced topics and exclusive materials.
              </p>
              <Button className="mt-4" asChild>
                <Link to="/upgrade">
                  <Crown className="w-4 h-4 mr-2" />
                  Upgrade to Pro
                </Link>
              </Button>
            </CardContent>
          </Card>
        </div>
      </Layout>
    );
  }

  return (
    <Layout>
      <div className="max-w-7xl mx-auto p-4 sm:p-6">
        <div className="grid grid-cols-1 xl:grid-cols-4 gap-6">
          {/* Main Content */}
          <div className="xl:col-span-3 min-w-0">
            {/* Header */}
            <div className="mb-8">
              <h1 className="text-3xl font-bold mb-3">{lesson.title}</h1>
              
              <div className="flex items-center justify-between flex-wrap gap-3">
                <div className="flex items-center gap-3 text-sm text-muted-foreground">
                  <div className="flex items-center gap-1">
                    <Clock className="w-4 h-4" />
                    {lesson.duration} min
                  </div>
                  {lesson.isPremium && (
                    <Badge variant="secondary" className="gap-1">
                      <Crown className="w-3 h-3" />
                      PRO
                    </Badge>
                  )}
                </div>
                
                <div className="flex items-center gap-2">
                  <Button variant="outline" size="sm">
                    <ChevronLeft className="w-4 h-4 mr-1" />
                    Previous
                  </Button>
                  <Button size="sm">
                    Next
                    <ChevronRight className="w-4 h-4 ml-1" />
                  </Button>
                </div>
              </div>
            </div>

            {/* Content */}
            <div className="prose prose-slate max-w-none dark:prose-invert">
              <div className="space-y-4 leading-relaxed">
                {lesson.content.split('\n').map((line: string, index: number) => {
                  if (line.startsWith('## ')) {
                    return <h2 key={index} className="text-2xl font-bold mt-8 mb-4 text-foreground">{line.slice(3)}</h2>;
                  }
                  if (line.startsWith('### ')) {
                    return <h3 key={index} className="text-xl font-semibold mt-6 mb-3 text-foreground">{line.slice(4)}</h3>;
                  }
                  if (line.startsWith('> ')) {
                    return (
                      <blockquote key={index} className="border-l-4 border-primary pl-4 py-3 bg-primary/5 rounded-r-lg my-3">
                        <p className="text-muted-foreground italic m-0">{line.slice(2)}</p>
                      </blockquote>
                    );
                  }
                  if (line.startsWith('- ')) {
                    return (
                      <li key={index} className="ml-4 mb-1.5 text-foreground">
                        {line.slice(2).split('**').map((part, i) => 
                          i % 2 === 1 ? <strong key={i} className="font-bold text-primary">{part}</strong> : part
                        )}
                      </li>
                    );
                  }
                  if (line.match(/^\d+\. /)) {
                    return (
                      <li key={index} className="ml-4 mb-1.5 text-foreground">
                        {line.replace(/^\d+\. /, '').split('**').map((part, i) => 
                          i % 2 === 1 ? <strong key={i} className="font-bold text-primary">{part}</strong> : part
                        )}
                      </li>
                    );
                  }
                  if (line.trim() && !line.startsWith('#') && !line.startsWith('>') && !line.startsWith('-') && !line.match(/^\d+\./)) {
                    return (
                      <p key={index} className="mb-3 text-foreground">
                        {line.split('**').map((part, i) => 
                          i % 2 === 1 ? <strong key={i} className="font-bold text-primary">{part}</strong> : part
                        )}
                      </p>
                    );
                  }
                  return null;
                })}
              </div>
            </div>

            {/* Code Examples */}
            {lesson.codeExamples && lesson.codeExamples.length > 0 && (
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
              <Button variant="outline">
                <ChevronLeft className="w-4 h-4 mr-2" />
                Previous Lesson
              </Button>
              
              <Button variant="outline">
                Next Lesson
                <ChevronRight className="w-4 h-4 ml-2" />
              </Button>
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