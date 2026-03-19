# Hide/Show Feature Implementation Guide

This guide explains how to implement the custom `[[start_hide]]` and `[[end_hide]]` syntax in your markdown files.

## Files Created

1. **`src/utils/hideShowFeature.js`** - Vanilla JavaScript implementation
2. **`src/hooks/useHideShowFeature.js`** - React hook implementation  
3. **`src/components/MarkdownWithHideShow.jsx`** - React component wrapper
4. **`src/styles/hideShow.css`** - CSS styles for the feature

## Integration Options

### Option 1: Vanilla JavaScript (Simple Integration)

```javascript
// Import and initialize
import { initHideShowFeature } from './src/utils/hideShowFeature.js';

// Initialize when DOM is ready
document.addEventListener('DOMContentLoaded', initHideShowFeature);
```

### Option 2: React Hook (React Applications)

```jsx
// In your main App component or layout
import { useHideShowFeature } from './src/hooks/useHideShowFeature';

function App() {
  useHideShowFeature(); // Initialize the feature
  
  return (
    <div className="app">
      {/* Your app content */}
    </div>
  );
}
```

### Option 3: React Component Wrapper

```jsx
// Use the MarkdownWithHideShow component
import { MarkdownWithHideShow } from './src/components/MarkdownWithHideShow';

function LessonPage({ markdownContent }) {
  return (
    <div className="lesson">
      <MarkdownWithHideShow 
        content={markdownContent}
        className="lesson-content"
      />
    </div>
  );
}
```

### Option 4: Higher-Order Component

```jsx
// Wrap your existing markdown component
import { withHideShow } from './src/components/MarkdownWithHideShow';
import ReactMarkdown from 'react-markdown';

const MarkdownWithHideShowFeature = withHideShow(ReactMarkdown);

function LessonPage({ content }) {
  return <MarkdownWithHideShowFeature>{content}</MarkdownWithHideShowFeature>;
}
```

## CSS Integration

Add the CSS file to your project:

```css
/* Import in your main CSS file */
@import './src/styles/hideShow.css';
```

Or include it in your HTML:

```html
<link rel="stylesheet" href="./src/styles/hideShow.css">
```

## Usage in Markdown

```markdown
### Problem 1: Example Problem

**Question**: "Solve this problem"

**Hints**: 
- Think about X
- Consider Y

[[start_hide]]
**Solution**:
```
1. Step 1: Do this
2. Step 2: Do that
3. Result: Answer is 42
```
[[end_hide]]
```

## Features

- ✅ **Click to reveal** - Solutions hidden by default
- ✅ **Smooth animations** - Slide down effect when opening
- ✅ **Responsive design** - Works on mobile and desktop
- ✅ **Dark mode support** - Automatic dark theme detection
- ✅ **Accessibility** - Keyboard navigation and screen reader support
- ✅ **Custom styling** - Easy to customize appearance

## Customization

### Changing the Toggle Text

Modify the replacement text in the processor:

```javascript
// Change "Click to see solution" to your preferred text
<strong>Show Answer</strong>
```

### Custom Styling

Override CSS variables or classes:

```css
.hide-show-toggle {
  background: your-custom-gradient;
  color: your-custom-color;
}
```

### Different Icons

Replace the toggle icon:

```javascript
// Change ▶ to your preferred icon
<span class="toggle-icon">🔍</span>
```

## Browser Support

- ✅ Chrome 60+
- ✅ Firefox 55+  
- ✅ Safari 10.1+
- ✅ Edge 79+

## Performance

- **Lightweight** - ~2KB CSS + ~3KB JS
- **Fast processing** - Regex-based content transformation
- **No dependencies** - Pure JavaScript implementation
- **Lazy loading** - Only processes visible content

## Troubleshooting

### Content Not Processing

1. Ensure the CSS is loaded
2. Check that the JavaScript is initialized
3. Verify the markdown content contains the syntax
4. Check browser console for errors

### Styling Issues

1. Ensure CSS specificity is correct
2. Check for conflicting styles
3. Verify CSS file is properly imported
4. Test in different browsers

### React Integration Issues

1. Ensure hooks are called in function components
2. Check that useEffect dependencies are correct
3. Verify the component is properly wrapped
4. Test with React DevTools