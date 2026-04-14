import { useState, useEffect } from 'react';
import { Prism as SyntaxHighlighter } from 'react-syntax-highlighter';
import { oneDark } from 'react-syntax-highlighter/dist/esm/styles/prism';
import { Card, CardContent } from '@/components/ui/card';
import { Button } from '@/components/ui/button';
import { Select, SelectContent, SelectItem, SelectTrigger, SelectValue } from '@/components/ui/select';
import { Copy, Check, Code2 } from 'lucide-react';

// 🔹 Eagerly import all code files as raw strings
const codeFiles: Record<string, string> = import.meta.glob(
  '/src/data/**/*.{cpp,java,py,js,ts}',
  { as: 'raw', eager: true }
);

// 🔹 Helper function to fetch a file's raw content (now synchronous via eager)
async function fetchCodeFile(path: string): Promise<string> {
  if (codeFiles[path]) return codeFiles[path];
  const suffix = path.split('/').slice(-3).join('/');
  for (const key of Object.keys(codeFiles)) {
    if (key.endsWith(suffix)) return codeFiles[key];
  }
  console.warn('Code file not found:', path, 'Total files loaded:', Object.keys(codeFiles).length);
  return '// Code file not found';
}

interface CodeLanguage {
  language: string;
  codeFile?: string; // only file path is given
}

interface CodeBlockProps {
  title: string;
  codes: CodeLanguage[]; // array of { language, codeFile }
  showLanguageSelector?: boolean;
}

const customStyle = {
  ...oneDark,
  'pre[class*="language-"]': {
    ...oneDark['pre[class*="language-"]'],
    background: 'hsl(var(--muted))',
    border: '1px solid hsl(var(--border))',
    borderRadius: '0.5rem',
    margin: 0,
  },
  'code[class*="language-"]': {
    ...oneDark['code[class*="language-"]'],
    background: 'transparent',
    color: 'hsl(var(--foreground))',
  },
  '.token.comment': { color: 'hsl(var(--muted-foreground))', fontStyle: 'italic' },
  '.token.keyword': { color: 'hsl(330 100% 70%)', fontWeight: 'bold', fontSize: '1.05em' },
  '.token.string': { color: 'hsl(120 100% 70%)', fontWeight: '600' },
  '.token.function': { color: 'hsl(200 100% 70%)', fontWeight: 'bold', fontSize: '1.05em' },
  '.token.number': { color: 'hsl(330 100% 80%)', fontWeight: '600' },
  '.token.operator': { color: 'hsl(330 100% 65%)', fontWeight: '600' },
  '.token.punctuation': { color: 'hsl(var(--muted-foreground))' },
  '.token.class-name': { color: 'hsl(330 100% 75%)', fontWeight: 'bold', fontSize: '1.05em' },
  '.token.variable': { color: 'hsl(var(--foreground))', fontWeight: '500' },
};

export function CodeBlock({ title, codes, showLanguageSelector = true }: CodeBlockProps) {
  // default to C++ if available, otherwise first language in list
  const defaultLang = codes?.find((c) => c.language === 'cpp')?.language || codes?.[0]?.language || 'cpp';
  const [selectedLanguage, setSelectedLanguage] = useState(defaultLang);
  const [loadedCodes, setLoadedCodes] = useState<{ [lang: string]: string }>({});
  const [copied, setCopied] = useState(false);

  // 🧠 Load all available code files on mount / when codes list changes
  useEffect(() => {
    const loadAllCodes = async () => {
      const loaded: { [lang: string]: string } = {};
      for (const c of codes) {
        if (!c.codeFile) continue;
        try {
          const normalizedPath = c.codeFile.startsWith('/src')
            ? c.codeFile
            : `/src/data/${c.codeFile}`;
          loaded[c.language] = await fetchCodeFile(normalizedPath);
        } catch (err) {
          console.error(`❌ Failed to load ${c.language}:`, err);
          loaded[c.language] = '// Error loading code';
        }
      }
      setLoadedCodes(loaded);
    };
    loadAllCodes();
    // if codes update, reset selected language to cpp if present
    const newDefault = codes.find((c) => c.language === 'cpp')?.language || codes[0]?.language;
    if (newDefault) setSelectedLanguage(newDefault);
  }, [codes]);

  const currentCode = loadedCodes[selectedLanguage] || '// Loading code...';

  const handleCopy = async () => {
    try {
      await navigator.clipboard.writeText(currentCode);
      setCopied(true);
      setTimeout(() => setCopied(false), 2000);
    } catch (err) {
      console.error('Failed to copy code:', err);
    }
  };

  return (
    <Card className="overflow-hidden border-2 border-primary/20 bg-gradient-to-br from-background to-muted/30 shadow-lg hover-lift code-block-wrapper">
      {/* Header */}
      <div className="glass bg-gradient-to-r from-primary/10 to-primary/5 border-b border-primary/20 px-4 py-3">
        <div className="flex items-center justify-between">
          {/* Title & Language Selector */}
          <div className="flex items-center gap-3">
            <div className="flex items-center gap-2">
              <Code2 className="w-4 h-4 text-primary" />
              <h3 className="font-semibold text-foreground text-sm sm:text-base truncate max-w-[200px] sm:max-w-none">{title}</h3>
            </div>

            {showLanguageSelector && codes.length > 1 && (
              <Select value={selectedLanguage} onValueChange={setSelectedLanguage}>
                <SelectTrigger className="w-32 h-8 bg-background/50 border-primary/30">
                  <SelectValue />
                </SelectTrigger>
                <SelectContent>
                  {codes.map((lang) => (
                    <SelectItem key={lang.language} value={lang.language}>
                      {lang.language.toUpperCase()}
                    </SelectItem>
                  ))}
                </SelectContent>
              </Select>
            )}
          </div>

          {/* Copy Button */}
          <Button
            variant="ghost"
            size="sm"
            onClick={handleCopy}
            className="h-8 px-3 hover:bg-primary/10 text-muted-foreground hover:text-primary"
          >
            {copied ? <Check className="w-4 h-4" /> : <Copy className="w-4 h-4" />}
            <span className="ml-1 text-xs">{copied ? 'Copied!' : 'Copy'}</span>
          </Button>
        </div>
      </div>

      {/* Code Display */}
      <CardContent className="p-0">
        <div className="relative max-h-[600px] overflow-auto custom-scrollbar">
          <SyntaxHighlighter
            language={selectedLanguage}
            style={customStyle}
            customStyle={{
              margin: 0,
              padding: '1rem',
              background: 'hsl(var(--card))',
              fontSize: '0.75rem',
              lineHeight: '1.4',
            }}
            showLineNumbers
            lineNumberStyle={{
              color: 'hsl(var(--muted-foreground))',
              paddingRight: '1rem',
              minWidth: '2.5rem',
              textAlign: 'right',
            }}
          >
            {currentCode}
          </SyntaxHighlighter>
        </div>
      </CardContent>
    </Card>
  );
}
