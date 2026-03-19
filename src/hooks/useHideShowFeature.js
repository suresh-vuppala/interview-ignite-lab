import { useEffect } from 'react';

// React Hook for Hide/Show Feature
export const useHideShowFeature = () => {
  useEffect(() => {
    // Process [[start_hide]] and [[end_hide]] syntax
    const processHideShowSyntax = (content) => {
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

    // Add CSS styles
    const addStyles = () => {
      const existingStyle = document.getElementById('hide-show-styles');
      if (existingStyle) return;

      const style = document.createElement('style');
      style.id = 'hide-show-styles';
      style.textContent = `
        .hide-show-section {
          margin: 16px 0;
          border: 1px solid #e1e5e9;
          border-radius: 8px;
          overflow: hidden;
          box-shadow: 0 2px 4px rgba(0,0,0,0.1);
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
          width: 100%;
          text-align: left;
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
          animation: slideDown 0.2s ease-out;
        }

        @keyframes slideDown {
          from {
            opacity: 0;
            transform: translateY(-10px);
          }
          to {
            opacity: 1;
            transform: translateY(0);
          }
        }

        .hide-show-content pre {
          margin: 8px 0;
          background: #f8f9fa;
          border: 1px solid #e9ecef;
          border-radius: 4px;
          padding: 12px;
          overflow-x: auto;
          font-family: 'Monaco', 'Menlo', 'Ubuntu Mono', monospace;
          font-size: 13px;
          line-height: 1.4;
        }

        .hide-show-content code {
          background: #f8f9fa;
          padding: 2px 4px;
          border-radius: 3px;
          font-size: 0.9em;
          font-family: 'Monaco', 'Menlo', 'Ubuntu Mono', monospace;
        }

        .hide-show-content strong {
          color: #212529;
          font-weight: 600;
        }
      `;
      document.head.appendChild(style);
    };

    // Process markdown content
    const processMarkdownContent = () => {
      const selectors = [
        '.markdown-content',
        '.lesson-content', 
        '[data-markdown]',
        '.prose',
        'article',
        '.content'
      ];
      
      selectors.forEach(selector => {
        const elements = document.querySelectorAll(selector);
        elements.forEach(element => {
          if (element.innerHTML && element.innerHTML.includes('[[start_hide]]')) {
            element.innerHTML = processHideShowSyntax(element.innerHTML);
          }
        });
      });
    };

    // Initialize
    addStyles();
    processMarkdownContent();

    // Re-process when content changes (for dynamic content)
    const observer = new MutationObserver((mutations) => {
      mutations.forEach((mutation) => {
        if (mutation.type === 'childList') {
          mutation.addedNodes.forEach((node) => {
            if (node.nodeType === Node.ELEMENT_NODE) {
              const element = node;
              if (element.innerHTML && element.innerHTML.includes('[[start_hide]]')) {
                element.innerHTML = processHideShowSyntax(element.innerHTML);
              }
            }
          });
        }
      });
    });

    observer.observe(document.body, {
      childList: true,
      subtree: true
    });

    return () => {
      observer.disconnect();
    };
  }, []);
};

// Component wrapper for easy integration
export const HideShowProvider = ({ children }) => {
  useHideShowFeature();
  return children;
};