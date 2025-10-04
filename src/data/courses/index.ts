import { arraysLessons } from './dsa/arrays';

// Centralized lesson data - now properly decoupled
export const lessonData: Record<string, any> = {
  ...arraysLessons,
  // Future course modules will be imported and spread here
};
