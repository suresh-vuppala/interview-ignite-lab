// /pages/LessonPage.tsx
import { useState, useEffect } from 'react';
import { useParams, Link } from 'react-router-dom';
import { Layout } from '@/components/Layout';
import { Button } from '@/components/ui/button';
import { Separator } from '@/components/ui/separator';
import { Badge } from '@/components/ui/badge';
import { Crown, ChevronLeft, ChevronRight, Lock, Code } from 'lucide-react';
import { ScrollToTop } from '@/components/ScrollToTop';
import { CodeBlock } from '@/components/CodeBlock';
import { useAuth } from '@/hooks/useAuth';

// Preload all markdown files (bundled by Vite)
const markdownFiles = import.meta.glob('/src/data/**/*.md', { as: 'raw' });

interface Lesson {
  order: number;
  title: string;
  slug: string;
  isPremium: boolean;
  type?: 'subHeader';
  lessons?: Lesson[];
  sectionSlug?: string;
  mdFile?: string;
  content?: string;
  codeExamples?: {
    title: string;
    languages: [];
  }[];
}

interface Section {
  title: string;
  slug: string;
  lessons: Lesson[];
}

interface Module {
  title: string;
  slug: string;
  sections: Section[];
}

// Dynamically import module JSON
const importModuleJson = async (courseSlug: string, moduleSlug: string) => {
  try {
    const module = await import(`@/data/courses/${courseSlug}/${moduleSlug}/${moduleSlug}.json`);
    return module.default || module;
  } catch (err) {
    console.warn(`Failed to load module ${moduleSlug}`, err);
    return null;
  }
};

// Dynamically import lesson JSON
const importLessonJson = async (courseSlug: string, moduleSlug: string, sectionSlug: string, lessonSlug: string) => {
  try {
    const lesson = await import(`@/data/courses/${courseSlug}/${moduleSlug}/${sectionSlug}/${lessonSlug}/${lessonSlug}.json`);
    return lesson.default || lesson;
  } catch (err) {
    console.warn(`Failed to load lesson ${lessonSlug}`, err);
    return null;
  }
};

// Fetch markdown content (via Vite glob import)
export const fetchMarkdown = async (courseSlug: string, moduleSlug: string, sectionSlug: string, lessonSlug: string, mdFile: string) => {
  const path = `/src/data/courses/${courseSlug}/${moduleSlug}/${sectionSlug}/${lessonSlug}/${mdFile}`;
  const loader = markdownFiles[path];
  if (!loader) return 'Content not available';
  return await loader();
};

export default function LessonPage() {
  const { courseSlug, moduleSlug, sectionSlug, lessonSlug } = useParams<{
    courseSlug: string;
    moduleSlug: string;
    sectionSlug?: string;
    lessonSlug: string;
  }>();

  const { user } = useAuth();

  const [lesson, setLesson] = useState<Lesson | null>(null);
  const [markdown, setMarkdown] = useState<string>('');
  const [prevLesson, setPrevLesson] = useState<{ path: string; title: string } | null>(null);
  const [nextLesson, setNextLesson] = useState<{ path: string; title: string } | null>(null);

  useEffect(() => {
    if (!courseSlug || !moduleSlug || !lessonSlug) return;

    (async () => {
      const moduleData: Module | null = await importModuleJson(courseSlug, moduleSlug);
      if (!moduleData) return;

      const flattenLessons = moduleData.sections.flatMap(section =>
        section.lessons.flatMap(lesson =>
          lesson.type === 'subHeader' && lesson.lessons
            ? lesson.lessons.map(l => ({ ...l, sectionSlug: section.slug }))
            : [{ ...lesson, sectionSlug: section.slug }]
        )
      );

      const index = flattenLessons.findIndex(l => l.slug === lessonSlug);
      if (index === -1) return;

      setPrevLesson(
        index > 0
          ? {
              path: `/course/${courseSlug}/${moduleSlug}/${flattenLessons[index - 1].sectionSlug}/${flattenLessons[index - 1].slug}`,
              title: flattenLessons[index - 1].title,
            }
          : null
      );

      setNextLesson(
        index < flattenLessons.length - 1
          ? {
              path: `/course/${courseSlug}/${moduleSlug}/${flattenLessons[index + 1].sectionSlug}/${flattenLessons[index + 1].slug}`,
              title: flattenLessons[index + 1].title,
            }
          : null
      );

      const lessonData = await importLessonJson(courseSlug, moduleSlug, sectionSlug, lessonSlug);
      if (!lessonData) return;
      setLesson(lessonData);

      if (lessonData.mdFile) {
        const md = await fetchMarkdown(courseSlug, moduleSlug, sectionSlug, lessonSlug, lessonData.mdFile);
        setMarkdown(md);
      } else {
        setMarkdown(lessonData.content || '');
      }
    })();
  }, [courseSlug, moduleSlug, sectionSlug, lessonSlug]);

  if (!lesson) {
    return (
      <Layout>
        <div className="flex items-center justify-center h-64">
          <div className="animate-spin h-8 w-8 border-b-2 border-primary rounded-full"></div>
          <p className="mt-2 text-muted-foreground">Loading lesson...</p>
        </div>
      </Layout>
    );
  }

  const hasAccess = !lesson.isPremium || !!user;
  const isLockedContent = lesson.isPremium && !hasAccess;

  // 🔹 Inline Code Example Logic
  let exampleIndex = 0;

  const renderMarkdown = () => {
    const lines = markdown.split('\n');
    const elements: JSX.Element[] = [];

    lines.forEach((line, index) => {
      // Inline code example insertion
      if (line.trim() === '```code```' && lesson.codeExamples && lesson.codeExamples[exampleIndex]) {
        let ex = lesson.codeExamples[exampleIndex++];
        // let actualCode = '';
        // try {
        //   actualCode = require(`@/${ex.code}`);
        // } catch (error) {
        //   console.error('❌ Error loading code file:', ex.code, error);
        //   actualCode = '// Error: Unable to load code file.';
        // }
        elements.push(
          <div key={`code-${index}`} className="my-6">
            <h4 className="text-lg font-semibold mb-2 flex items-center gap-2">
              {/* <Code className="w-4 h-4" /> {ex.title} */}
            </h4>
            <CodeBlock
              codes={ex.languages}
              title={ex.title}
              showLanguageSelector
            />
          </div>
        );
        return;
      }

      // Headings
      if (line.startsWith('## ')) {
        elements.push(<h2 key={index} className="text-2xl font-bold mt-6 mb-3 text-foreground">{line.slice(3)}</h2>);
        return;
      }
      if (line.startsWith('### ')) {
        elements.push(<h3 key={index} className="text-xl font-semibold mt-5 mb-2 text-foreground">{line.slice(4)}</h3>);
        return;
      }

      // Blockquote
      if (line.startsWith('> ')) {
        elements.push(
          <blockquote key={index} className="border-l-4 border-primary pl-4 py-2 bg-primary/5 rounded-r-lg my-3">
            <p className="text-muted-foreground italic m-0 leading-relaxed">{line.slice(2)}</p>
          </blockquote>
        );
        return;
      }

      // Bullet list
      if (line.startsWith('- ')) {
        elements.push(
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
        return;
      }

      // Numbered list
      if (line.match(/^\d+\. /)) {
        elements.push(
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
        return;
      }

      // Image
      if (line.startsWith('![') && line.includes('](')) {
        const altMatch = line.match(/!\[(.*?)\]/);
        const urlMatch = line.match(/\((.*?)\)/);
        if (altMatch && urlMatch) {
          elements.push(
            <img 
              key={index} 
              src={urlMatch[1]} 
              alt={altMatch[1]} 
              className="rounded-lg my-4 max-w-full h-auto"
            />
          );
        }
        return;
      }

      // Paragraph or plain text
      if (line.trim() && !line.startsWith('#') && !line.startsWith('>') && !line.startsWith('-') && !line.match(/^\d+\./) && !line.startsWith('![')) {
        elements.push(
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
    });

    return elements;
  };

  return (
    <Layout>
      <div className="max-w-7xl mx-auto p-4 sm:p-6">
        {/* Header */}
        <div className="mb-6 flex items-center justify-between flex-wrap gap-3">
          <h1 className="text-3xl font-bold">{lesson.title}</h1>
          {lesson.isPremium && (
            <Badge variant="secondary" className="gap-1 flex items-center">
              <Crown className="w-3 h-3" /> PRO
            </Badge>
          )}
        </div>

        {/* Lesson Content */}
        <div className="space-y-4">
          {isLockedContent ? (
            <div className="relative p-8 min-h-[400px] bg-muted/20 rounded-lg">
              <div className="absolute inset-0 bg-gradient-to-b from-transparent via-background/70 to-background flex items-center justify-center">
                <div className="text-center space-y-4">
                  <Lock className="w-16 h-16 mx-auto text-muted-foreground" />
                  <h3 className="text-2xl font-bold">Premium Content</h3>
                  <p className="text-muted-foreground max-w-md mx-auto">
                    Unlock this lesson to access advanced topics and code examples.
                  </p>
                  <Button size="lg" asChild>
                    <Link to="/upgrade">
                      <Crown className="w-5 h-5 mr-2" /> Unlock Premium Content
                    </Link>
                  </Button>
                </div>
              </div>
            </div>
          ) : (
            <div className="space-y-3 leading-relaxed">{renderMarkdown()}</div>
          )}
        </div>

        {/* Navigation */}
        <div className="flex justify-between mt-8 pt-6 border-t">
          {prevLesson ? (
            <Button variant="outline" asChild>
              <Link to={prevLesson.path}>
                <ChevronLeft className="w-4 h-4 mr-2" />
                <span className="truncate max-w-[150px]">{prevLesson.title}</span>
              </Link>
            </Button>
          ) : (
            <Button variant="outline" disabled>
              <ChevronLeft className="w-4 h-4 mr-2" /> Previous
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
              Next <ChevronRight className="w-4 h-4 ml-2" />
            </Button>
          )}
        </div>
      </div>
      <ScrollToTop />
    </Layout>
  );
}
