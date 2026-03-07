const markdownFiles = import.meta.glob('/src/data/courses/**/*.md', { as: 'raw' });
const lessonJsonFiles = import.meta.glob('/src/data/courses/**/*.json', { eager: true });

export const fetchMarkdown = async (
  lessonSlug?: string,
  mdFile?: string
) => {
  if (!lessonSlug || !mdFile) return 'Markdown not available';

  const file = Object.keys(markdownFiles).find(key => key.endsWith(`${lessonSlug}/${mdFile}`));

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

  // first attempt: use the glob-generated list (fast, static)
  const file = Object.keys(lessonJsonFiles).find((key) => key.endsWith(`${lessonSlug}/${lessonSlug}.json`));
  if (file) {
    const lesson = (lessonJsonFiles[file] as any).default || lessonJsonFiles[file];
    return lesson;
  }

  // fallback: the file may have been added while the dev server was running
  // (import.meta.glob won't always refresh dynamically-created files).
  // We'll try a direct dynamic import based on the expected folder structure.
  try {
    let dynamicPath = `@/data/courses/${courseSlug}/${moduleSlug}/`;
    if (sectionSlug) dynamicPath += `${sectionSlug}/`;
    if (subsectionSlug) dynamicPath += `${subsectionSlug}/`;
    dynamicPath += `${lessonSlug}/${lessonSlug}.json`;

    const lessonModule = await import(/* @vite-ignore */ dynamicPath);
    return lessonModule.default || lessonModule;
  } catch (err) {
    console.warn(`❌ Lesson JSON not found via dynamic import for slug: ${lessonSlug}`, err);
    return null;
  }
};