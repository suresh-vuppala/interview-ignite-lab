import { Layout } from '@/components/Layout';
import { Card, CardContent, CardDescription, CardHeader, CardTitle } from '@/components/ui/card';

import { Badge } from '@/components/ui/badge';
import { Button } from '@/components/ui/button';
import { 
  Play, 
  Lock,
  Crown,
  CheckCircle
} from 'lucide-react';
import { Link } from 'react-router-dom';
import { useAuth } from '@/hooks/useAuth';

const recentLessons = [
  {
    title: "Two Pointers Pattern",
    course: "Algorithms",
    url: "/course/dsa/arrays/two-pointers"
  },
  {
    title: "Arrays & Strings",
    course: "Data Structures", 
    url: "/course/dsa/arrays/intro"
  },
  {
    title: "System Design Fundamentals",
    course: "System Design",
    url: "/course/system-design-hld/scalability/load-balancing"
  }
];

const popularCourses = [
  {
    title: "Data Structures & Algorithms",
    description: "Master the most important DSA patterns for coding interviews",
    lessons: 24,
    difficulty: "Intermediate",
    isPremium: false,
    url: "/course/dsa"
  },
  {
    title: "System Design (HLD) Fundamentals",
    description: "Learn to design scalable systems like a senior engineer",
    lessons: 18,
    difficulty: "Advanced",
    isPremium: true,
    url: "/course/system-design-hld"
  },
  {
    title: "Low Level Design",
    description: "Master object-oriented design patterns and principles",
    lessons: 12,
    difficulty: "Advanced",
    isPremium: true,
    url: "/course/lld"
  },
  {
    title: "Behavioral Interview Mastery",
    description: "Perfect your soft skills and leadership stories",
    lessons: 12,
    difficulty: "Beginner",
    isPremium: true,
    url: "/course/behavioral"
  }
];


export default function Dashboard() {
  const { user } = useAuth();

  return (
    <Layout>
      <div className="p-6 space-y-8">
        {/* Header */}
        <div className="space-y-2">
          <h1 className="text-3xl font-bold">
            Welcome back, {user?.user_metadata?.full_name || user?.email?.split('@')[0]}!
          </h1>
          <p className="text-muted-foreground">
            Continue your journey to landing your dream tech job
          </p>
        </div>


        <div className="grid lg:grid-cols-3 gap-8">
          {/* Continue Learning */}
          <div className="lg:col-span-2 space-y-6">
            <Card>
              <CardHeader>
                <CardTitle className="flex items-center gap-2">
                  <Play className="w-5 h-5" />
                  Continue Learning
                </CardTitle>
                <CardDescription>
                  Pick up where you left off
                </CardDescription>
              </CardHeader>
              <CardContent className="space-y-4">
                {recentLessons.map((lesson) => (
                  <div key={lesson.title} className="flex items-center space-x-4 p-4 border rounded-lg hover:bg-accent/50 transition-colors">
                    <div className="flex-1 min-w-0">
                      <div className="flex items-center justify-between">
                        <div>
                          <p className="font-medium truncate">{lesson.title}</p>
                          <p className="text-sm text-muted-foreground">{lesson.course}</p>
                        </div>
                      </div>
                    </div>
                    <Button variant="ghost" size="sm" asChild>
                      <Link to={lesson.url}>
                        Start
                      </Link>
                    </Button>
                  </div>
                ))}
              </CardContent>
            </Card>

            {/* Popular Courses */}
            <Card>
              <CardHeader>
                <CardTitle>Popular Courses</CardTitle>
                <CardDescription>
                  Trending courses this week
                </CardDescription>
              </CardHeader>
              <CardContent className="space-y-4">
                {popularCourses.map((course) => (
                  <div key={course.title} className="p-4 border rounded-lg hover:shadow-md transition-shadow">
                    <div className="flex items-start justify-between">
                      <div className="flex-1">
                        <div className="flex items-center gap-2 mb-2">
                          <h3 className="font-semibold">{course.title}</h3>
                          {course.isPremium && (
                            <Badge variant="secondary" className="text-xs">
                              <Crown className="w-3 h-3 mr-1" />
                              PRO
                            </Badge>
                          )}
                        </div>
                        <p className="text-sm text-muted-foreground mb-3">{course.description}</p>
                        <div className="flex items-center gap-4 text-xs text-muted-foreground">
                          <span>{course.lessons} lessons</span>
                          <Badge variant="outline" className="text-xs">
                            {course.difficulty}
                          </Badge>
                        </div>
                      </div>
                      <Button variant="outline" size="sm" asChild>
                        <Link to={course.url}>
                          {course.isPremium && !user ? (
                            <>
                              <Lock className="w-3 h-3 mr-1" />
                              Upgrade
                            </>
                          ) : (
                            'Start Course'
                          )}
                        </Link>
                      </Button>
                    </div>
                  </div>
                ))}
              </CardContent>
            </Card>
          </div>

          {/* Sidebar */}
          <div className="space-y-6">
            {/* Upgrade Card */}
            {!user && (
              <Card className="bg-gradient-to-br from-primary/10 to-blue-500/10 border-primary/20">
                <CardHeader>
                  <CardTitle className="flex items-center gap-2">
                    <Crown className="w-5 h-5 text-primary" />
                    Upgrade to Pro
                  </CardTitle>
                  <CardDescription>
                    Unlock premium content and features
                  </CardDescription>
                </CardHeader>
                <CardContent className="space-y-4">
                  <ul className="space-y-2 text-sm">
                    <li className="flex items-center gap-2">
                      <CheckCircle className="w-4 h-4 text-green-500" />
                      Access all premium courses
                    </li>
                    <li className="flex items-center gap-2">
                      <CheckCircle className="w-4 h-4 text-green-500" />
                      Advanced system design topics
                    </li>
                    <li className="flex items-center gap-2">
                      <CheckCircle className="w-4 h-4 text-green-500" />
                      Mock interview practice
                    </li>
                    <li className="flex items-center gap-2">
                      <CheckCircle className="w-4 h-4 text-green-500" />
                      Priority support
                    </li>
                  </ul>
                  <Button className="w-full" asChild>
                    <Link to="/upgrade">
                      <Crown className="w-4 h-4 mr-2" />
                      Upgrade Now
                    </Link>
                  </Button>
                </CardContent>
              </Card>
            )}

          </div>
        </div>
      </div>
    </Layout>
  );
}