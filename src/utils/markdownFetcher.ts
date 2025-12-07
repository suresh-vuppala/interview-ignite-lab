const markdownFiles = import.meta.glob('/src/data/courses/**/*.md', { as: 'raw' });
const lessonJsonFiles = import.meta.glob('/src/data/courses/**/*.json', { eager: true });

export const fetchMarkdown = async (
  lessonSlug?: string,
  mdFile?: string
) => {
  if (!lessonSlug || !mdFile) return 'Markdown not available';

  const file = Object.keys(markdownFiles).find(key => key.endsWith(mdFile));

  if (!file) {
    console.warn(`⚠️ Markdown file not found: ${mdFile}`);
    return 'Content not available';
  }

  return await markdownFiles[file]();
};

const buildLessonPath = (
  courseSlug: string,
  moduleSlug: string,
  sectionSlug?: string,
  subsectionSlug?: string,
  lessonSlug?: string
): string => {
  // 🧩 Build folder hierarchy safely
  const parts = ['src', 'data', 'courses', courseSlug, moduleSlug];

  if (sectionSlug) parts.push(sectionSlug);
  if (subsectionSlug) parts.push(subsectionSlug);

  // 🧠 The lesson folder always matches lessonSlug
  return `/${parts.join('/')}/${lessonSlug}/${lessonSlug}.json`;
};

// ✅ Get JSON lesson dynamically
export const importLessonJson = async (
  courseSlug: string,
  moduleSlug: string,
  sectionSlug?: string,
  subsectionSlug?: string,
  lessonSlug?: string
) => {
  if (!lessonSlug) return null;

  const path = buildLessonPath(courseSlug, moduleSlug, sectionSlug, subsectionSlug, lessonSlug);

  const file = Object.keys(lessonJsonFiles).find((key) => key.endsWith(`${lessonSlug}.json`));
  if (!file) {
    console.warn(`⚠️ Lesson JSON not found: ${lessonSlug}`);
    return null;
  }

  const lesson = (lessonJsonFiles[file] as any).default || lessonJsonFiles[file];
  return lesson;
};