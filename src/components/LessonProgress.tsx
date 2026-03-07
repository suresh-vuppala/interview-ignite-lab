import { useState, useEffect } from 'react';
import { Button } from '@/components/ui/button';
import { CheckCircle2, Circle } from 'lucide-react';
import { toast } from 'sonner';

interface LessonProgressProps {
  courseSlug: string;
  moduleSlug: string;
  lessonSlug: string;
}

export function LessonProgress({ courseSlug, moduleSlug, lessonSlug }: LessonProgressProps) {
  const [isCompleted, setIsCompleted] = useState(false);
  const storageKey = `lesson-progress-${courseSlug}-${moduleSlug}-${lessonSlug}`;

  useEffect(() => {
    const completed = localStorage.getItem(storageKey) === 'true';
    setIsCompleted(completed);
  }, [storageKey]);

  const toggleComplete = () => {
    const newState = !isCompleted;
    setIsCompleted(newState);
    localStorage.setItem(storageKey, String(newState));
    
    if (newState) {
      toast.success('Lesson marked as complete! 🎉');
    } else {
      toast.info('Lesson marked as incomplete');
    }
  };

  return (
    <Button
      onClick={toggleComplete}
      variant={isCompleted ? 'default' : 'outline'}
      size="lg"
      className="gap-2 hover-lift"
    >
      {isCompleted ? (
        <>
          <CheckCircle2 className="w-5 h-5" />
          Completed
        </>
      ) : (
        <>
          <Circle className="w-5 h-5" />
          Mark as Complete
        </>
      )}
    </Button>
  );
}
