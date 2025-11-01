import React from "react";
import { Toaster } from "@/components/ui/toaster";
import { Toaster as Sonner } from "@/components/ui/sonner";
import { TooltipProvider } from "@/components/ui/tooltip";
import { QueryClient, QueryClientProvider } from "@tanstack/react-query";
import { BrowserRouter, Routes, Route, useLocation } from "react-router-dom";
import { AuthProvider } from "@/hooks/useAuth";
import { ThemeProvider } from "@/components/ThemeProvider";
import Index from "./pages/Index";
import Auth from "./pages/Auth";
import CourseOverview from "./pages/CourseOverview";
import LessonPage from "./pages/LessonPage";
import NotFound from "./pages/NotFound";

const queryClient = new QueryClient();

// ✅ Wrapper that forces re-render when route changes
const AnimatedRoutes = () => {
  const location = useLocation();

  return (
    <Routes key={location.pathname}> {/* 👈 Forces remount on route change */}
      <Route path="/" element={<Index />} />
      <Route path="/auth" element={<Auth />} />
      <Route path="/course/:courseSlug" element={<CourseOverview />} />
      {/* Route for lessons with section slug */}
      <Route
        path="/course/:courseSlug/:moduleSlug/:sectionSlug/:subsectionSlug/:lessonSlug"
        element={<LessonPage />}
      />
      <Route
        path="/course/:courseSlug/:moduleSlug/:sectionSlug/:lessonSlug"
        element={<LessonPage />}
      />
      {/* Route for lessons without section slug */}
      <Route
        path="/course/:courseSlug/:moduleSlug/:lessonSlug"
        element={<LessonPage />}
      />
      {/* Catch-all */}
      <Route path="*" element={<NotFound />} />
    </Routes>
  );
};

const App = () => (
  <QueryClientProvider client={queryClient}>
    <ThemeProvider
      attribute="class"
      defaultTheme="system"
      enableSystem
      disableTransitionOnChange
    >
      <AuthProvider>
        <TooltipProvider>
          <Toaster />
          <Sonner />
          <BrowserRouter>
            <AnimatedRoutes /> {/* 👈 Use wrapped routes */}
          </BrowserRouter>
        </TooltipProvider>
      </AuthProvider>
    </ThemeProvider>
  </QueryClientProvider>
);

export default App;
