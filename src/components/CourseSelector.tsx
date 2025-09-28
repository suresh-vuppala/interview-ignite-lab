import React from "react";
import { NavLink, useLocation } from "react-router-dom";
import { ChevronDown } from "lucide-react";
import {
  DropdownMenu,
  DropdownMenuContent,
  DropdownMenuItem,
  DropdownMenuTrigger,
} from "@/components/ui/dropdown-menu";
import { Button } from "@/components/ui/button";
import { 
  Database,
  Brain,
  GitBranch,
  MessageSquare
} from "lucide-react";

const courses = [
  {
    id: "dsa",
    title: "DSA (Data Structures & Algorithms)",
    icon: Database,
    description: "Master algorithms and data structures"
  },
  {
    id: "system-design-hld",
    title: "System Design (HLD)",
    icon: Brain,
    description: "Learn high-level system architecture"
  },
  {
    id: "lld",
    title: "Low Level Design (LLD)",
    icon: GitBranch,
    description: "Object-oriented design patterns"
  },
  {
    id: "behavioral",
    title: "Behavioral",
    icon: MessageSquare,
    description: "Ace behavioral interviews"
  }
];

export function CourseSelector() {
  const location = useLocation();
  const pathSegments = location.pathname.split('/');
  const currentCourseSlug = pathSegments[2];
  const currentCourse = courses.find(course => course.id === currentCourseSlug);

  return (
    <DropdownMenu>
      <DropdownMenuTrigger asChild>
        <Button variant="ghost" className="flex items-center gap-2 h-8 px-2">
          {currentCourse ? (
            <>
              <currentCourse.icon className="w-4 h-4" />
              <span className="hidden sm:inline">{currentCourse.title}</span>
            </>
          ) : (
            <span>Courses</span>
          )}
          <ChevronDown className="w-4 h-4" />
        </Button>
      </DropdownMenuTrigger>
      <DropdownMenuContent align="start" className="w-80">
        {courses.map((course) => (
          <DropdownMenuItem key={course.id} asChild>
            <NavLink 
              to={`/course/${course.id}`}
              className="flex items-start gap-3 p-3 cursor-pointer"
            >
              <course.icon className="w-5 h-5 mt-0.5 text-muted-foreground" />
              <div className="flex-1">
                <div className="font-medium text-sm">{course.title}</div>
                <div className="text-xs text-muted-foreground mt-1">
                  {course.description}
                </div>
              </div>
            </NavLink>
          </DropdownMenuItem>
        ))}
      </DropdownMenuContent>
    </DropdownMenu>
  );
}