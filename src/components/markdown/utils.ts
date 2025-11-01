// import React from "react";

// // Handles bold **text**, inline code `text`
// export const parseInlineFormatting = (text: string) => {
//   const parts = text.split(/(\*\*[^*]+\*\*|`[^`]+`)/g).filter(Boolean);

//   return parts.map((part, i) => {
//     if (part.startsWith("**") && part.endsWith("**")) {
//       return <strong key={i} className="font-semibold text-foreground">{part.slice(2, -2)}</strong>;
//     }
//     if (part.startsWith("`") && part.endsWith("`")) {
//       return <code key={i} className="font-mono text-[hsl(var(--accent-pink))] bg-primary/10 px-1.5 py-0.5 rounded text-sm">{part.slice(1, -1)}</code>;
//     }
//     return part;
//   });
// };
