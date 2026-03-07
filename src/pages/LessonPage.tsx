// /pages/LessonPage.tsx
import { useState, useEffect } from 'react';
import { useParams, Link } from 'react-router-dom';
import { Layout } from '@/components/layout';
import  CountdownTimer  from '@/components/CountdownTimer';
import { Button } from '@/components/ui/button';
import { Separator } from '@/components/ui/separator';
import { Badge } from '@/components/ui/badge';
import { Crown, ChevronLeft, ChevronRight, Lock, Code } from 'lucide-react';
import { ScrollToTop } from '@/components/ScrollToTop';
import { CodeBlock } from '@/components/CodeBlock';
import { useAuth } from '@/hooks/useAuth';
import ImageCarousel from '@/components/ImageCarousel';
import { lessonData } from '@/data/courses';
import { fetchMarkdown, importLessonJson } from '../utils/markdownFetcher';
import Prism from 'prismjs';
import 'prismjs/themes/prism-tomorrow.css';
import 'prismjs/components/prism-java';
import 'prismjs/components/prism-c';
import 'prismjs/components/prism-cpp';
import 'prismjs/components/prism-python';
import 'prismjs/components/prism-javascript';
import 'prismjs/components/prism-typescript';


// Preload all markdown files (bundled by Vite)
const lessonJsonFiles = import.meta.glob('/src/data/courses/**/*.json', { eager: true });
const markdownFiles = import.meta.glob('/src/data/courses/**/*.md', { as: 'raw' });

interface Lesson {
  order: number;
  title: string;
  slug: string;
  isPremium: boolean;
  isPosted: boolean;
  type?: 'subHeader';
  lessons?: Lesson[];
  sectionSlug?: string;
  mdFile?: string;
  content?: string;
  codeExamples?: {
    title: string;
    languages: [];
  }[];
  imageDetails?:[]
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

// ✅ New version: Load all modules from single course-level JSON (e.g., dsa.json)
const importModuleJson = async (courseSlug: string, moduleSlug: string) => {
  try {
    // Load the full course JSON once (e.g., dsa.json)
    const courseData = await import(`@/data/courses/${courseSlug}/${courseSlug}.json`);
    const course = courseData.default || courseData;

    // Find the requested module by its slug
    const module = course.modules.find((m: any) => m.slug === moduleSlug);

    if (!module) {
      console.warn(`⚠️ Module not found in ${courseSlug}.json: ${moduleSlug}`);
      return null;
    }

    return module;
  } catch (err) {
    console.error(`❌ Failed to load course or module: ${courseSlug}/${moduleSlug}`, err);
    return null;
  }
};

export default function LessonPage() {
  const { courseSlug, moduleSlug, sectionSlug,subsectionSlug, lessonSlug } = useParams<{
    courseSlug: string;
    moduleSlug: string;
    sectionSlug?: string;
    subsectionSlug?: string;
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
    // 🧠 1. Load full course data from single file (e.g., dsa.json)
    const courseData = await import(`@/data/courses/${courseSlug}/${courseSlug}.json`);
    const course = courseData.default || courseData;

    // 🧩 2. Find specific module by slug
    const moduleData = course.modules.find((m: any) => m.slug === moduleSlug);
    if (!moduleData) {
      console.warn(`⚠️ Module not found in ${courseSlug}.json: ${moduleSlug}`);
      return;
    }

    // 🧩 Step 1: Flatten all lessons — including subsection lessons
    const flattenLessons = moduleData.sections.flatMap((section: any) =>
    section.lessons.flatMap((lesson: any) => {
      // Case 1️⃣: Subsection (lesson.type === 'subHeader')
      if (lesson.lessons) {
        return lesson.lessons.map((sub: any) => ({
          ...sub,
          sectionSlug: section.slug,
          subSectionSlug: lesson.slug, // ✅ store subsection slug
        }));
      }

      // Case 2️⃣: Normal lesson under section
      return {
        ...lesson,
        sectionSlug: section.slug,
        subSectionSlug: null,
      };
  })
);

// 🧭 Step 2: Find current lesson index
const index = flattenLessons.findIndex((l: any) => l.slug === lessonSlug);
if (index === -1) return;

// 🧭 Step 3: Build dynamic path helper (handles subsection or not)
const buildLessonUrl = (lesson: any) => {
  if (lesson.subSectionSlug) {
    // 🧠 Subsection lesson path
    return `/course/${courseSlug}/${moduleSlug}/${lesson.sectionSlug}/${lesson.subSectionSlug}/${lesson.slug}`;
  }
  // 🧠 Regular lesson under section
  return `/course/${courseSlug}/${moduleSlug}/${lesson.sectionSlug}/${lesson.slug}`;
};

// ⬅️ Step 4: Set previous lesson
setPrevLesson(
  index > 0
    ? {
        path: buildLessonUrl(flattenLessons[index - 1]),
        title: flattenLessons[index - 1].title,
      }
    : null
);

// ➡️ Step 5: Set next lesson
setNextLesson(
  index < flattenLessons.length - 1
    ? {
        path: buildLessonUrl(flattenLessons[index + 1]),
        title: flattenLessons[index + 1].title,
      }
    : null
);


    // 📘 6. Load lesson JSON
    const lessonData = await importLessonJson(courseSlug, moduleSlug, sectionSlug, subsectionSlug, lessonSlug);
    if (!lessonData) return;
    lessonData.mdFile = lessonSlug+".md";
    setLesson(lessonData);

    // 🪶 7. Load markdown content if available
    if (lessonData.mdFile) {
      const md = await fetchMarkdown(lessonSlug, lessonData.mdFile);
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

const renderInlineFormatting = (text: string, keyPrefix: string = '') => {
  // Regex to detect [link text](url)
  const linkRegex = /\[([^\]]+)\]\(([^)]+)\)/g;

  const segments = [];
  let lastIndex = 0;
  let match;

  // Split text into link + plain segments
  while ((match = linkRegex.exec(text)) !== null) {
    if (match.index > lastIndex) {
      segments.push(text.slice(lastIndex, match.index));
    }
    segments.push({ text: match[1], url: match[2] });
    lastIndex = linkRegex.lastIndex;
  }
  if (lastIndex < text.length) segments.push(text.slice(lastIndex));

  // Render each segment with nested bold/code formatting
  return segments.map((segment, i) => {
    if (typeof segment === 'string') {
      // Preserve whitespace by converting it to non-breaking spaces and regular spaces
      const processTextWithWhitespace = (text: string) => {
        return text.split('').map((char, idx) => {
          if (char === ' ') {
            return <span key={`${keyPrefix}-space-${i}-${idx}`} className="preserve-whitespace"> </span>;
          } else if (char === '\t') {
            return <span key={`${keyPrefix}-tab-${i}-${idx}`} className="preserve-whitespace tab-width">    </span>;
          } else if (char === '\n') {
            return <br key={`${keyPrefix}-br-${i}-${idx}`} />;
          }
          return char;
        });
      };

      // First split by bold markers
      const boldSegments = segment.split('**');
      
      return boldSegments.map((part, j) => {
        const isBold = j % 2 === 1;
        
        // Then split by code markers within each bold segment
        const codeSegments = part.split('`');
        
        const processedSegments = codeSegments.map((code, k) => {
          const isCode = k % 2 === 1;
          
          if (isCode) {
            return (
              <span
                key={`${keyPrefix}-code-${i}-${j}-${k}`}
                className="font-mono text-[hsl(var(--accent-pink))] bg-primary/10 px-1.5 py-0.5 rounded text-sm"
              >
                {processTextWithWhitespace(code)}
              </span>
            );
          } else if (isBold) {
            return (
              <span key={`${keyPrefix}-bold-${i}-${j}-${k}`} className="font-semibold text-foreground">
                {processTextWithWhitespace(code)}
              </span>
            );
          } else {
            return (
              <span key={`${keyPrefix}-text-${i}-${j}-${k}`} className="whitespace-pre-wrap">
                {processTextWithWhitespace(code)}
              </span>
            );
          }
        });

        return processedSegments;
      }).flat();
    }

    // Handle links - preserve whitespace in link text too
    return (
      <a
        key={`${keyPrefix}-link-${i}`}
        href={segment.url}
        target="_blank"
        rel="noopener noreferrer"
        className="text-blue-500 hover:underline whitespace-pre-wrap"
      >
        {segment.text}
      </a>
    );
  }).flat();
};
const renderMarkdown = (markdown : string) => {
 

  const lines = markdown.split('\n');
  const elements: JSX.Element[] = [];
  let isTable = false;
  let tableLines: string[] = [];
  let blockquoteBuffer: string[] = [];
  let codeBlockBuffer: string[] = [];
  let codeBlockLanguage = '';
  let isInCodeBlock = false;

  lines.forEach((line, index) => {
    const trimmedLine = line.trim();

    // --- Inline code example insertion (check BEFORE code block detection) ---
    if (trimmedLine === '```code```' && lesson.codeExamples && lesson.codeExamples[exampleIndex]) {
      let ex = lesson.codeExamples[exampleIndex++];
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

    // --- Detect code block start ---
    if (trimmedLine.startsWith('```') && !isInCodeBlock) {
      isInCodeBlock = true;
      codeBlockLanguage = trimmedLine.slice(3).trim() || 'java';
      codeBlockBuffer = [];
      return;
    }

    // --- Detect code block end ---
    if (trimmedLine === '```' && isInCodeBlock) {
      isInCodeBlock = false;
      const codeContent = codeBlockBuffer.join('\n');
      
      // Highlight code with Prism
      const grammar = Prism.languages[codeBlockLanguage] || Prism.languages.java;
      const highlightedCode = Prism.highlight(codeContent, grammar, codeBlockLanguage);
      
      elements.push(
        <div key={`codeblock-${index}`} className="my-4 rounded-lg overflow-hidden border border-border">
          <pre className="!bg-[#2d2d2d] !m-0 p-4 overflow-x-auto">
            <code 
              className={`language-${codeBlockLanguage}`}
              dangerouslySetInnerHTML={{ __html: highlightedCode }}
            />
          </pre>
        </div>
      );
      codeBlockBuffer = [];
      return;
    }

    // --- Collect code block lines ---
    if (isInCodeBlock) {
      codeBlockBuffer.push(line);
      return;
    }

    // --- Detect start of table ---
    if (trimmedLine.startsWith('|') && trimmedLine.endsWith('|')) {
      isTable = true;
      tableLines.push(trimmedLine);
      return;
    }

    // --- Render table when it ends ---
    if (isTable && (!trimmedLine.startsWith('|') || !trimmedLine.endsWith('|'))) {
      elements.push(renderTable(tableLines, elements.length));
      tableLines = [];
      isTable = false;
    }

    // --- Blockquote handling ---
    if (trimmedLine.startsWith('>')) {
      const content = trimmedLine.slice(2);
      blockquoteBuffer.push(content === '' ? '\u00A0' : content);
      return;
    } else if (blockquoteBuffer.length > 0) {
      elements.push(
        <blockquote
          key={index}
          className="border-l-4 border-primary pl-6 py-3 bg-gradient-to-r from-primary/10 to-transparent rounded-r-xl my-4 shadow-sm"
        >
          {blockquoteBuffer.map((text, i) => (
            <p key={i} className="text-muted-foreground italic m-0 leading-relaxed text-base">
              {renderInlineFormatting(text, `bq-${index}-${i}`)}
            </p>
          ))}
        </blockquote>
      );
      blockquoteBuffer = [];
    }
    if (line.startsWith('---')) { elements.push(<hr key={index} className="my-10 border-t-2 border-gradient-to-r from-transparent via-primary/30 to-transparent" />); return; }
    // --- Headings ---
    if (line.startsWith('# ')) {
      elements.push(
        <h2 key={index} className="text-3xl font-bold mt-6 mb-3 text-foreground">
          {line.slice(2)}
        </h2>
      );
      return;
    }
    if (line.startsWith('## ')) {
      elements.push(
        <h2 key={index} className="text-2xl font-bold mt-8 mb-4 text-foreground flex items-center gap-3">
          <span className="w-1 h-8 bg-gradient-to-b from-primary to-primary/50 rounded-full"></span>
          {line.slice(3)}
        </h2>
      );
      return;
    }
    if (line.startsWith('### ')) {
      elements.push(
        <h3 key={index} className="text-xl font-semibold mt-6 mb-3 text-foreground flex items-center gap-2">
          <span className="w-2 h-2 bg-primary rounded-full"></span>
          {line.slice(4)}
        </h3>
      );
      return;
    }

    // --- Bullet list ---
    if (line.startsWith('- ')) {
      elements.push(
        <li key={index} className="ml-4 mb-2 text-foreground leading-relaxed">
          {renderInlineFormatting(line.slice(2), `li-${index}`)}
        </li>
      );
      return;
    }
    if (line.startsWith('<br>')) {
      elements.push(
       <br></br>
      );
      return;
    }
    // --- Numbered list ---
    if (line.match(/^\d+\. /)) {
      elements.push(
        <p key={index} className="ml-4 mb-2 text-foreground leading-relaxed">
          {renderInlineFormatting(line, `num-${index}`)}
        </p>
      );
      return;
    }

// --- Image Carousel ---
if (
  trimmedLine.startsWith("![") &&
  trimmedLine.includes("](") &&
  trimmedLine.includes("/")
) {
  const altMatch = trimmedLine.match(/!\[(.*?)\]/);
  const urlMatch = trimmedLine.match(/\((.*?)\)/);

  if (!altMatch || !urlMatch) return;

  const folderPath = urlMatch[1]; // ex: "FibonacciSolution"

  // If no extension → treat as folder for carousel
  if (!folderPath.match(/\.(png|jpg|jpeg|gif|webp)$/i)) {
    
    const folderName = folderPath.split("/").pop();
    const jsonUrl = `${folderPath}/${folderName}.json`;


    const jsonData = lesson.imageDetails?.find(detail => detail[folderName])?.[folderName] || [];
    if (jsonData) {
      elements.push(
        <ImageCarousel
          key={`carousel-${index}`}
          folder={folderPath}
          jsonData={jsonData}
        />
      );
    }

    return;
  }

  // --- Regular Image ---
  elements.push(
    <img
      key={index}
      src={urlMatch[1]}
      alt={altMatch[1]}
      className="rounded-lg my-4 max-w-full h-auto"
    />
  );

  return;
}




    // --- Paragraph or plain text ---
    if (
      line.trim() &&
      !line.startsWith('#') &&
      !line.startsWith('>') &&
      !line.startsWith('-') &&
      !line.match(/^\d+\./) &&
      !line.startsWith('![')
    ) {
      elements.push(
        <p key={index} className="mb-3 text-foreground leading-relaxed">
          {renderInlineFormatting(line, `p-${index}`)}
        </p>
      );
    }
  });

  return elements;
};

// --- Updated table rendering ---
const renderTable = (lines: string[], key: number) => {
  if (lines.length < 2) return null;

  const headers = lines[0].split('|').map(h => h.trim()).filter(Boolean);
  const rows = lines.slice(2).map(line =>
    line.split('|').map(cell => cell.trim()).filter(Boolean)
  );

  return (
    <div key={`table-wrapper-${key}`} className="my-6 overflow-x-auto rounded-xl border border-border shadow-md">
      <table className="table-auto w-full">
        <thead>
          <tr className="bg-gradient-to-r from-primary/20 to-primary/10">
            {headers.map((h, idx) => (
              <th key={idx} className="border-b-2 border-primary/30 px-4 py-3 text-left font-semibold text-foreground">
                {renderInlineFormatting(h, `header-${idx}`)}
              </th>
            ))}
          </tr>
        </thead>
        <tbody>
          {rows.map((row, rIdx) => (
            <tr key={rIdx} className="hover:bg-muted/50 transition-colors">
              {row.map((cell, cIdx) => (
                <td key={cIdx} className="border-b border-border px-4 py-3 align-top">
                  {renderInlineFormatting(cell, `cell-${rIdx}-${cIdx}`)}
                </td>
              ))}
            </tr>
          ))}
        </tbody>
      </table>
    </div>
  );
};


return (
  <Layout>
    <div className="max-w-6xl mx-auto p-4 sm:p-6 lg:p-8">
      {/* Header with gradient background */}
      <div className="mb-8 p-6 rounded-2xl bg-gradient-to-r from-primary/10 via-primary/5 to-transparent border border-primary/20 animate-slide-in">
        <div className="flex items-center justify-between flex-wrap gap-4">
          <h1 className="text-4xl font-bold bg-gradient-to-r from-primary to-primary/60 bg-clip-text text-transparent">
            {lesson.title}
          </h1>
          {lesson.isPremium && (
            <Badge variant="secondary" className="gap-2 px-4 py-2 text-sm">
              <Crown className="w-4 h-4" /> PRO
            </Badge>
          )}
        </div>
      </div>
      {/* Lesson Content */}
      <div className="space-y-6 animate-fade-in">
        {/* Case 1: Coming Soon (Not Posted Yet) */}
        {!lesson.isPosted ? (
          <div className="relative p-10 min-h-[400px] bg-gradient-to-b from-pink-50 to-white dark:from-pink-950/40 dark:to-background rounded-lg flex flex-col items-center justify-center text-center border border-pink-200 dark:border-pink-900 shadow-sm">
            <div className="space-y-6 max-w-lg">
              <h3 className="text-3xl font-bold text-foreground">
                Full Course Dropping Soon 🚀
              </h3>
              <p className="text-muted-foreground text-lg">
                We're putting the final touches! The course launches in:
              </p>

              {/* Countdown */}
              <CountdownTimer targetDate="2026-01-01T00:00:00" />

              <p className="text-muted-foreground text-base">
                Get early updates, exclusive access, and free resources — join our waitlist below.
              </p>

              <Button
                size="lg"
                className="mt-3 bg-primary text-white hover:bg-primary/90"
                asChild
              >
                <Link to="/join">Join the Waitlist</Link>
              </Button>
            </div>
          </div>
        ) : lesson.isPremium ? (
          /* Case 2: Premium Content Lock */
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
          /* Case 3: Public Lesson Content */
          <div className="prose prose-lg max-w-none space-y-4 leading-relaxed">
            {renderMarkdown(markdown)}
          </div>
        )}
      </div>

      {/* Navigation */}
      <div className="flex justify-between items-center mt-12 pt-8 border-t border-border/50">
        {prevLesson ? (
          <Button variant="outline" size="lg" className="hover-lift" asChild>
            <Link to={prevLesson.path}>
              <ChevronLeft className="w-5 h-5 mr-2" />
              <div className="flex flex-col items-start">
                <span className="text-xs text-muted-foreground">Previous</span>
                <span className="truncate max-w-[150px] font-medium">{prevLesson.title}</span>
              </div>
            </Link>
          </Button>
        ) : (
          <Button variant="outline" size="lg" disabled>
            <ChevronLeft className="w-5 h-5 mr-2" /> Previous
          </Button>
        )}
        {nextLesson ? (
          <Button variant="outline" size="lg" className="hover-lift" asChild>
            <Link to={nextLesson.path}>
              <div className="flex flex-col items-end">
                <span className="text-xs text-muted-foreground">Next</span>
                <span className="truncate max-w-[150px] font-medium">{nextLesson.title}</span>
              </div>
              <ChevronRight className="w-5 h-5 ml-2" />
            </Link>
          </Button>
        ) : (
          <Button variant="outline" size="lg" disabled>
            Next <ChevronRight className="w-5 h-5 ml-2" />
          </Button>
        )}
      </div>
    </div>
    <ScrollToTop />
  </Layout>
);

}
