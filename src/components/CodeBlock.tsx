import { useState } from 'react';
import { Prism as SyntaxHighlighter } from 'react-syntax-highlighter';
import { oneDark } from 'react-syntax-highlighter/dist/esm/styles/prism';
import { Card, CardContent } from '@/components/ui/card';
import { Button } from '@/components/ui/button';
import { Select, SelectContent, SelectItem, SelectTrigger, SelectValue } from '@/components/ui/select';
import { Copy, Check, Code2 } from 'lucide-react';

interface CodeBlockProps {
  title: string;
  code: string;
  language?: string;
  showLanguageSelector?: boolean;
}

const LANGUAGES = [
  { value: 'python', label: 'Python' },
  { value: 'javascript', label: 'JavaScript' },
  { value: 'java', label: 'Java' },
  { value: 'cpp', label: 'C++' },
  { value: 'typescript', label: 'TypeScript' },
  { value: 'go', label: 'Go' },
  { value: 'rust', label: 'Rust' },
  { value: 'sql', label: 'SQL' },
];

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
  '.token.comment': {
    color: 'hsl(var(--muted-foreground))',
  },
  '.token.keyword': {
    color: 'hsl(330 100% 70%)', // Pink for keywords
  },
  '.token.string': {
    color: 'hsl(120 100% 70%)', // Green for strings
  },
  '.token.function': {
    color: 'hsl(200 100% 70%)', // Blue for functions
  },
  '.token.number': {
    color: 'hsl(330 100% 80%)', // Light pink for numbers
  },
  '.token.operator': {
    color: 'hsl(330 100% 65%)', // Pink for operators
  },
  '.token.punctuation': {
    color: 'hsl(var(--muted-foreground))',
  },
  '.token.class-name': {
    color: 'hsl(330 100% 75%)', // Pink for class names
  },
  '.token.variable': {
    color: 'hsl(var(--foreground))',
  },
};

export function CodeBlock({ title, code, language = 'python', showLanguageSelector = true }: CodeBlockProps) {
  const [selectedLanguage, setSelectedLanguage] = useState(language);
  const [copied, setCopied] = useState(false);

  const handleCopy = async () => {
    try {
      await navigator.clipboard.writeText(code);
      setCopied(true);
      setTimeout(() => setCopied(false), 2000);
    } catch (err) {
      console.error('Failed to copy code:', err);
    }
  };

  return (
    <Card className="overflow-hidden border-2 border-primary/20 bg-gradient-to-br from-background to-muted/30">
      <div className="bg-gradient-to-r from-primary/10 to-primary/5 border-b border-primary/20 px-4 py-3">
        <div className="flex items-center justify-between">
          <div className="flex items-center gap-3">
            <div className="flex items-center gap-2">
              <Code2 className="w-4 h-4 text-primary" />
              <h3 className="font-semibold text-foreground">{title}</h3>
            </div>
            {showLanguageSelector && (
              <Select value={selectedLanguage} onValueChange={setSelectedLanguage}>
                <SelectTrigger className="w-32 h-8 bg-background/50 border-primary/30">
                  <SelectValue />
                </SelectTrigger>
                <SelectContent>
                  {LANGUAGES.map((lang) => (
                    <SelectItem key={lang.value} value={lang.value}>
                      {lang.label}
                    </SelectItem>
                  ))}
                </SelectContent>
              </Select>
            )}
          </div>
          
          <Button
            variant="ghost"
            size="sm"
            onClick={handleCopy}
            className="h-8 px-3 hover:bg-primary/10 text-muted-foreground hover:text-primary"
          >
            {copied ? (
              <Check className="w-4 h-4" />
            ) : (
              <Copy className="w-4 h-4" />
            )}
            <span className="ml-1 text-xs">
              {copied ? 'Copied!' : 'Copy'}
            </span>
          </Button>
        </div>
      </div>
      
      <CardContent className="p-0">
        <div className="relative max-h-[600px] overflow-auto">
          <SyntaxHighlighter
            language={selectedLanguage}
            style={customStyle}
            customStyle={{
              margin: 0,
              padding: '1.5rem',
              background: 'hsl(var(--card))',
              fontSize: '0.875rem',
              lineHeight: '1.5',
            }}
            showLineNumbers
            lineNumberStyle={{
              color: 'hsl(var(--muted-foreground))',
              paddingRight: '1rem',
              minWidth: '2.5rem',
              textAlign: 'right',
            }}
          >
            {code}
          </SyntaxHighlighter>
          
          {/* Pink highlight overlay for important lines */}
          <div className="absolute inset-0 pointer-events-none">
            <div className="h-full w-full bg-gradient-to-r from-primary/5 via-transparent to-primary/5 opacity-30"></div>
          </div>
        </div>
      </CardContent>
    </Card>
  );
}