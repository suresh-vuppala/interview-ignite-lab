// /components/MarkdownRenderer.tsx
import { useState } from "react";
import { CodeBlock } from "@/components/CodeBlock";
import { Separator } from "@/components/ui/separator";

interface MarkdownRendererProps {
  markdown: string;
}

export default function MarkdownRenderer({ markdown }: MarkdownRendererProps) {
  const lines = markdown.split("\n");
  const elements: JSX.Element[] = [];

  let currentCode: string[] = [];
  let codeLang = "";
  let inCodeBlock = false;

  lines.forEach((line, i) => {
    const key = `line-${i}`;

    // ✅ Code block start
    if (line.startsWith("```")) {
      if (inCodeBlock) {
        // Close code block
        elements.push(
          <CodeBlock
            key={key}
            code={currentCode.join("\n")}
            language={codeLang || "text"}
            showLanguageSelector
          />
        );
        currentCode = [];
        inCodeBlock = false;
      } else {
        // Open code block
        inCodeBlock = true;
        codeLang = line.slice(3).trim();
      }
      return;
    }

    if (inCodeBlock) {
      currentCode.push(line);
      return;
    }

    // ✅ Headings
    if (line.startsWith("### ")) {
      elements.push(
        <h3 key={key} className="text-xl font-semibold mt-4">
          {line.slice(4)}
        </h3>
      );
      return;
    }

    if (line.startsWith("## ")) {
      elements.push(
        <h2 key={key} className="text-2xl font-bold mt-6">
          {line.slice(3)}
        </h2>
      );
      return;
    }

    if (line.startsWith("# ")) {
      elements.push(
        <h1 key={key} className="text-3xl font-bold mt-6 border-b pb-2">
          {line.slice(2)}
        </h1>
      );
      return;
    }

    // ✅ Bold or inline code formatting
    let formatted = line
      .replace(/\*\*(.*?)\*\*/g, "<strong>$1</strong>")
      .replace(/`([^`]+)`/g, "<code class='bg-muted rounded px-1'>$1</code>");

    // ✅ Image handling
    const imgMatch = line.match(/!\[(.*?)\]\((.*?)\)/);
    if (imgMatch) {
      const [, alt, src] = imgMatch;
      elements.push(
        <div key={key} className="my-4">
          <img
            src={src}
            alt={alt}
            className="rounded-lg border shadow-sm max-w-full"
          />
          {alt && <p className="text-sm text-muted-foreground mt-1">{alt}</p>}
        </div>
      );
      return;
    }

    // ✅ Blockquote (tips or notes)
    if (line.startsWith(">")) {
      elements.push(
        <blockquote
          key={key}
          className="border-l-4 border-blue-500 pl-4 italic text-muted-foreground bg-blue-50 dark:bg-blue-950 py-2 rounded-r-md"
          dangerouslySetInnerHTML={{ __html: line.slice(1).trim() }}
        />
      );
      return;
    }

    // ✅ Lists
    if (line.startsWith("- ")) {
      const last = elements[elements.length - 1];
      if (last && last.type === "ul") {
        (last.props.children as JSX.Element[]).push(
          <li
            key={key}
            dangerouslySetInnerHTML={{ __html: formatted.slice(2) }}
          />
        );
      } else {
        elements.push(
          <ul key={key} className="list-disc pl-6 space-y-1">
            <li dangerouslySetInnerHTML={{ __html: formatted.slice(2) }} />
          </ul>
        );
      }
      return;
    }

    // ✅ Separator
    if (line.trim() === "---") {
      elements.push(<Separator key={key} />);
      return;
    }

    // ✅ Empty line spacing
    if (line.trim() === "") {
      elements.push(<div key={key} className="h-3" />);
      return;
    }

    // ✅ Normal paragraph
    elements.push(
      <p
        key={key}
        className="leading-relaxed"
        dangerouslySetInnerHTML={{ __html: formatted }}
      />
    );
  });

  return (
    <div className="prose prose-slate dark:prose-invert max-w-none space-y-2">
      {elements}
    </div>
  );
}
