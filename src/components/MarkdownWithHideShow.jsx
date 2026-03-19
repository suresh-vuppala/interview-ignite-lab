import React, { useMemo } from 'react';
import { useHideShowFeature } from '../hooks/useHideShowFeature';

// Markdown processor component that handles [[start_hide]] and [[end_hide]] syntax
export const MarkdownWithHideShow = ({ content, className = '' }) => {
  useHideShowFeature();

  const processedContent = useMemo(() => {
    if (!content) return '';
    
    // Process the custom hide/show syntax
    return content.replace(
      /\[\[start_hide\]\]([\s\S]*?)\[\[end_hide\]\]/g,
      (match, hiddenContent) => {
        const uniqueId = Math.random().toString(36).substr(2, 9);
        return `<details class="hide-show-section" id="hide-${uniqueId}">
<summary class="hide-show-toggle">
  <span class="toggle-icon">▶</span>
  <strong>Click to see solution</strong>
</summary>
<div class="hide-show-content">
${hiddenContent.trim()}
</div>
</details>`;
      }
    );
  }, [content]);

  return (
    <div 
      className={`markdown-content ${className}`}
      dangerouslySetInnerHTML={{ __html: processedContent }}
    />
  );
};

// Higher-order component to wrap existing markdown components
export const withHideShow = (MarkdownComponent) => {
  return (props) => {
    useHideShowFeature();
    return <MarkdownComponent {...props} />;
  };
};

// Utility function to process markdown content
export const processMarkdownContent = (content) => {
  if (!content) return '';
  
  return content.replace(
    /\[\[start_hide\]\]([\s\S]*?)\[\[end_hide\]\]/g,
    (match, hiddenContent) => {
      const uniqueId = Math.random().toString(36).substr(2, 9);
      return `<details class="hide-show-section" id="hide-${uniqueId}">
<summary class="hide-show-toggle">
  <span class="toggle-icon">▶</span>
  <strong>Click to see solution</strong>
</summary>
<div class="hide-show-content">
${hiddenContent.trim()}
</div>
</details>`;
    }
  );
};