// Custom Hide/Show Feature for Markdown
// Processes [[start_hide]] and [[end_hide]] syntax

export function processHideShowSyntax(markdownContent) {
  // Replace [[start_hide]] and [[end_hide]] with HTML details/summary structure
  const processedContent = markdownContent.replace(
    /\[\[start_hide\]\]([\s\S]*?)\[\[end_hide\]\]/g,
    (match, content) => {
      return `<details class="hide-show-section">
<summary class="hide-show-toggle">
  <span class="toggle-icon">▶</span>
  <strong>Click to see solution</strong>
</summary>
<div class="hide-show-content">
${content.trim()}
</div>
</details>`;
    }
  );
  
  return processedContent;
}

// CSS styles for the hide/show feature
export const hideShowStyles = `
.hide-show-section {
  margin: 16px 0;
  border: 1px solid #e1e5e9;
  border-radius: 8px;
  overflow: hidden;
}

.hide-show-toggle {
  display: flex;
  align-items: center;
  padding: 12px 16px;
  background: linear-gradient(135deg, #f8f9fa 0%, #e9ecef 100%);
  cursor: pointer;
  user-select: none;
  border: none;
  font-size: 14px;
  font-weight: 600;
  color: #495057;
  transition: all 0.2s ease;
}

.hide-show-toggle:hover {
  background: linear-gradient(135deg, #e9ecef 0%, #dee2e6 100%);
  color: #212529;
}

.toggle-icon {
  margin-right: 8px;
  font-size: 12px;
  transition: transform 0.2s ease;
  color: #6c757d;
}

.hide-show-section[open] .toggle-icon {
  transform: rotate(90deg);
}

.hide-show-content {
  padding: 16px;
  background: #ffffff;
  border-top: 1px solid #e1e5e9;
}

.hide-show-content pre {
  margin: 0;
  background: #f8f9fa;
  border: 1px solid #e9ecef;
  border-radius: 4px;
  padding: 12px;
  overflow-x: auto;
}

.hide-show-content code {
  background: #f8f9fa;
  padding: 2px 4px;
  border-radius: 3px;
  font-size: 0.9em;
}
`;

// Initialize the feature when DOM is loaded
export function initHideShowFeature() {
  // Add styles to document
  const styleSheet = document.createElement('style');
  styleSheet.textContent = hideShowStyles;
  document.head.appendChild(styleSheet);
  
  // Process all markdown content on the page
  const markdownElements = document.querySelectorAll('.markdown-content, .lesson-content, [data-markdown]');
  
  markdownElements.forEach(element => {
    if (element.innerHTML.includes('[[start_hide]]')) {
      element.innerHTML = processHideShowSyntax(element.innerHTML);
    }
  });
}

// Auto-initialize when script loads
if (typeof document !== 'undefined') {
  if (document.readyState === 'loading') {
    document.addEventListener('DOMContentLoaded', initHideShowFeature);
  } else {
    initHideShowFeature();
  }
}