import React from "react";
import { useParams } from "react-router-dom";
import { Layout } from "@/components/Layout";
import { Card, CardContent, CardDescription, CardHeader, CardTitle } from "@/components/ui/card";
import { Badge } from "@/components/ui/badge";
import { Button } from "@/components/ui/button";
import { Clock, Users, Star, Lock, Crown } from "lucide-react";
import { NavLink } from "react-router-dom";
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
    description: "Master algorithms and data structures with hands-on practice and real interview questions.",
    modules: [
      {
        title: "Arrays & Strings",
        url: "/course/dsa/arrays",
        lessons: [
          { title: "Introduction to Arrays", url: "/course/dsa/arrays/intro", isPremium: false, estimatedTime: 30 },
          { title: "Two Pointers Technique", url: "/course/dsa/arrays/two-pointers", isPremium: false, estimatedTime: 45 },
          { title: "Sliding Window", url: "/course/dsa/arrays/sliding-window", isPremium: true, estimatedTime: 60 },
          { title: "Prefix Sum", url: "/course/dsa/arrays/prefix-sum", isPremium: true, estimatedTime: 50 },
        ]
      },
      {
        title: "Linked Lists",
        url: "/course/dsa/linked-lists",
        lessons: [
          { title: "Basics", url: "/course/dsa/linked-lists/basics", isPremium: false, estimatedTime: 40 },
          { title: "Fast & Slow Pointers", url: "/course/dsa/linked-lists/fast-slow", isPremium: true, estimatedTime: 55 },
          { title: "Reversal", url: "/course/dsa/linked-lists/reversal", isPremium: true, estimatedTime: 50 },
        ]
      },
      {
        title: "Trees & Graphs",
        url: "/course/dsa/trees",
        lessons: [
          { title: "Tree Fundamentals", url: "/course/dsa/trees/fundamentals", isPremium: false, estimatedTime: 45 },
          { title: "DFS & BFS", url: "/course/dsa/trees/dfs-bfs", isPremium: true, estimatedTime: 60 },
          { title: "Binary Search Trees", url: "/course/dsa/trees/bst", isPremium: true, estimatedTime: 55 },
        ]
      }
    ]
  },
  {
    id: "system-design-hld",
    title: "System Design (HLD) Fundamentals",
    icon: Brain,
    description: "Learn high-level system architecture and design scalable distributed systems.",
    modules: [
      {
        title: "Scalability Basics",
        url: "/course/system-design-hld/scalability",
        lessons: [
          { title: "Load Balancing", url: "/course/system-design-hld/scalability/load-balancing", isPremium: false, estimatedTime: 40 },
          { title: "Horizontal vs Vertical Scaling", url: "/course/system-design-hld/scalability/scaling", isPremium: true, estimatedTime: 50 },
          { title: "Auto Scaling", url: "/course/system-design-hld/scalability/auto-scaling", isPremium: true, estimatedTime: 45 },
        ]
      },
      {
        title: "Databases",
        url: "/course/system-design-hld/databases",
        lessons: [
          { title: "SQL vs NoSQL", url: "/course/system-design-hld/databases/sql-nosql", isPremium: false, estimatedTime: 35 },
          { title: "Sharding", url: "/course/system-design-hld/databases/sharding", isPremium: true, estimatedTime: 55 },
          { title: "Replication", url: "/course/system-design-hld/databases/replication", isPremium: true, estimatedTime: 50 },
        ]
      },
      {
        title: "Caching",
        url: "/course/system-design-hld/caching",
        lessons: [
          { title: "Cache Patterns", url: "/course/system-design-hld/caching/patterns", isPremium: false, estimatedTime: 40 },
          { title: "CDN", url: "/course/system-design-hld/caching/cdn", isPremium: true, estimatedTime: 45 },
        ]
      }
    ]
  },
  {
    id: "lld",
    title: "LLD (Low Level Design)",
    icon: GitBranch,
    description: "Master object-oriented design patterns and principles for technical interviews.",
    modules: [
      {
        title: "Design Patterns",
        url: "/course/lld/design-patterns",
        lessons: [
          { title: "Singleton Pattern", url: "/course/lld/design-patterns/singleton", isPremium: false, estimatedTime: 35 },
          { title: "Factory Pattern", url: "/course/lld/design-patterns/factory", isPremium: true, estimatedTime: 45 },
          { title: "Observer Pattern", url: "/course/lld/design-patterns/observer", isPremium: true, estimatedTime: 50 },
        ]
      },
      {
        title: "Object-Oriented Design",
        url: "/course/lld/oop",
        lessons: [
          { title: "SOLID Principles", url: "/course/lld/oop/solid", isPremium: false, estimatedTime: 60 },
          { title: "Inheritance vs Composition", url: "/course/lld/oop/inheritance", isPremium: true, estimatedTime: 45 },
        ]
      },
      {
        title: "System Design Examples",
        url: "/course/lld/examples",
        lessons: [
          { title: "Parking Lot System", url: "/course/lld/examples/parking-lot", isPremium: true, estimatedTime: 90 },
          { title: "Elevator System", url: "/course/lld/examples/elevator", isPremium: true, estimatedTime: 85 },
        ]
      }
    ]
  },
  {
    id: "behavioral",
    title: "Behavioral",
    icon: MessageSquare,
    description: "Ace behavioral interviews with proven frameworks and real examples.",
    modules: [
      {
        title: "Interview Techniques",
        url: "/course/behavioral/techniques",
        lessons: [
          { title: "STAR Method", url: "/course/behavioral/techniques/star-method", isPremium: false, estimatedTime: 30 },
          { title: "Storytelling", url: "/course/behavioral/techniques/storytelling", isPremium: true, estimatedTime: 40 },
        ]
      },
      {
        title: "Common Questions",
        url: "/course/behavioral/questions",
        lessons: [
          { title: "Leadership Examples", url: "/course/behavioral/questions/leadership", isPremium: false, estimatedTime: 35 },
          { title: "Conflict Resolution", url: "/course/behavioral/questions/conflict", isPremium: true, estimatedTime: 40 },
          { title: "Failure Stories", url: "/course/behavioral/questions/failure", isPremium: true, estimatedTime: 35 },
        ]
      },
      {
        title: "Company Culture",
        url: "/course/behavioral/culture",
        lessons: [
          { title: "Culture Fit", url: "/course/behavioral/culture/fit", isPremium: true, estimatedTime: 25 },
          { title: "Values Alignment", url: "/course/behavioral/culture/values", isPremium: true, estimatedTime: 30 },
        ]
      }
    ]
  }
];

export default function CourseOverview() {
  const { courseSlug } = useParams();
  const course = courses.find(c => c.id === courseSlug);

  if (!course) {
    return (
      <Layout>
        <div className="flex items-center justify-center min-h-[50vh]">
          <div className="text-center">
            <h1 className="text-2xl font-bold text-muted-foreground">Course Not Found</h1>
            <p className="text-muted-foreground mt-2">The course you're looking for doesn't exist.</p>
          </div>
        </div>
      </Layout>
    );
  }

  const totalLessons = course.modules.reduce((acc, module) => acc + module.lessons.length, 0);
  const freeLessons = course.modules.reduce((acc, module) => 
    acc + module.lessons.filter(lesson => !lesson.isPremium).length, 0
  );
  const totalTime = course.modules.reduce((acc, module) => 
    acc + module.lessons.reduce((lessonAcc, lesson) => lessonAcc + (lesson.estimatedTime || 30), 0), 0
  );

  return (
    <Layout>
      <div className="min-h-screen bg-gradient-to-br from-background to-muted/20">
        <div className="container mx-auto px-4 py-8">
          {/* Course Header */}
          <div className="mb-8">
            <div className="flex items-center gap-4 mb-4">
              <div className="w-16 h-16 bg-gradient-to-br from-primary to-blue-600 rounded-xl flex items-center justify-center">
                <course.icon className="w-8 h-8 text-white" />
              </div>
              <div>
                <h1 className="text-4xl font-bold text-foreground">{course.title}</h1>
                <p className="text-lg text-muted-foreground mt-2">{course.description}</p>
              </div>
            </div>
            
            <div className="flex items-center gap-6 text-sm text-muted-foreground">
              <div className="flex items-center gap-2">
                <Clock className="w-4 h-4" />
                <span>{Math.round(totalTime / 60)}h {totalTime % 60}m</span>
              </div>
              <div className="flex items-center gap-2">
                <Users className="w-4 h-4" />
                <span>{totalLessons} lessons</span>
              </div>
              <div className="flex items-center gap-2">
                <Star className="w-4 h-4" />
                <span>{freeLessons} free lessons</span>
              </div>
            </div>
          </div>

          {/* Course Modules */}
          <div className="grid gap-6">
            <h2 className="text-2xl font-semibold mb-4">Course Content</h2>
            {course.modules.map((module, moduleIndex) => (
              <Card key={module.title} className="overflow-hidden">
                <CardHeader className="pb-4">
                  <CardTitle className="flex items-center justify-between">
                    <span className="flex items-center gap-3">
                      <div className="w-8 h-8 bg-primary/10 rounded-lg flex items-center justify-center text-primary font-semibold text-sm">
                        {moduleIndex + 1}
                      </div>
                      {module.title}
                    </span>
                    <Badge variant="secondary">
                      {module.lessons.length} lessons
                    </Badge>
                  </CardTitle>
                </CardHeader>
                <CardContent>
                  <div className="space-y-3">
                    {module.lessons.map((lesson, lessonIndex) => (
                      <div
                        key={lesson.title}
                        className="flex items-center justify-between p-3 rounded-lg border bg-card/50 hover:bg-card transition-colors"
                      >
                        <div className="flex items-center gap-3">
                          <div className="w-6 h-6 bg-muted rounded-full flex items-center justify-center text-xs font-medium">
                            {lessonIndex + 1}
                          </div>
                          <div>
                            <h4 className="font-medium text-foreground">{lesson.title}</h4>
                            <div className="flex items-center gap-2 text-sm text-muted-foreground">
                              <Clock className="w-3 h-3" />
                              <span>{lesson.estimatedTime || 30}min</span>
                              {lesson.isPremium && (
                                <Badge variant="secondary" className="text-xs px-1.5 py-0.5">
                                  <Crown className="w-2 h-2 mr-1" />
                                  PRO
                                </Badge>
                              )}
                            </div>
                          </div>
                        </div>
                        <div className="flex items-center gap-2">
                          {lesson.isPremium && (
                            <Lock className="w-4 h-4 text-muted-foreground" />
                          )}
                          <Button size="sm" variant="ghost" asChild>
                            <NavLink to={lesson.url}>
                              Start
                            </NavLink>
                          </Button>
                        </div>
                      </div>
                    ))}
                  </div>
                </CardContent>
              </Card>
            ))}
          </div>
        </div>
      </div>
    </Layout>
  );
}