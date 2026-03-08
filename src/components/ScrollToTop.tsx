import { useState, useEffect } from 'react';
import { ArrowUp } from 'lucide-react';

export function ScrollToTop() {
  const [isVisible, setIsVisible] = useState(true); // Always visible for testing

  useEffect(() => {
    const toggleVisibility = () => {
      setIsVisible(window.scrollY > 100);
    };

    window.addEventListener('scroll', toggleVisibility);
    toggleVisibility();
    return () => window.removeEventListener('scroll', toggleVisibility);
  }, []);

  const scrollToTop = () => {
    window.scrollTo({ top: 0, behavior: 'smooth' });
  };

  if (!isVisible) return null;

  return (
    <div
      onClick={scrollToTop}
      style={{
        position: 'fixed',
        bottom: '80px',
        right: '16px',
        zIndex: 99999,
        width: '48px',
        height: '48px',
        borderRadius: '50%',
        backgroundColor: '#ff69b4',
        display: 'flex',
        alignItems: 'center',
        justifyContent: 'center',
        cursor: 'pointer',
        boxShadow: '0 4px 12px rgba(0,0,0,0.4)'
      }}
    >
      <ArrowUp style={{ width: '24px', height: '24px', color: 'white' }} />
    </div>
  );
}
