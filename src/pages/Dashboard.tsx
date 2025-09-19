import { Layout } from '@/components/Layout';
import { Card, CardContent, CardDescription, CardHeader, CardTitle } from '@/components/ui/card';
import { Progress } from '@/components/ui/progress';
import { Badge } from '@/components/ui/badge';
import { Button } from '@/components/ui/button';
import { 
  BookOpen, 
  Clock, 
  Target, 
  TrendingUp, 
  Play, 
  Lock,
  Crown,
  CheckCircle,
  Circle
} from 'lucide-react';
import { Link } from 'react-router-dom';
import { useAuth } from '@/hooks/useAuth';

const recentLessons = [
  {
    title: "Two Pointers Pattern",
    course: "Algorithms",
    progress: 80,
    timeLeft: "5 min",
    url: "/course/algorithms/two-pointers",
    completed: false
  },
  {
    title: "Arrays & Strings",
    course: "Data Structures", 
    progress: 100,
    timeLeft: "Completed",
    url: "/course/data-structures/arrays",
    completed: true
  },
  {
    title: "System Design Fundamentals",
    course: "System Design",
    progress: 45,
    timeLeft: "12 min",
    url: "/course/system-design/fundamentals", 
    completed: false
  }
];

const popularCourses = [
  {
    title: "Data Structures & Algorithms",
    description: "Master the most important DSA patterns for coding interviews",
    lessons: 24,
    duration: "8 hours",
    difficulty: "Intermediate",
    isPremium: false,
    url: "/course/data-structures"
  },
  {
    title: "System Design Fundamentals",
    description: "Learn to design scalable systems like a senior engineer",
    lessons: 18,
    duration: "6 hours", 
    difficulty: "Advanced",
    isPremium: true,
    url: "/course/system-design"
  },
  {
    title: "Behavioral Interview Mastery",
    description: "Perfect your soft skills and leadership stories",
    lessons: 12,
    duration: "4 hours",
    difficulty: "Beginner",
    isPremium: true,
    url: "/course/behavioral"
  }
];

const stats = [
  { label: "Lessons Completed", value: "12", subtext: "out of 50", icon: BookOpen },
  { label: "Hours Studied", value: "8.5", subtext: "this week", icon: Clock },
  { label: "Streak", value: "5", subtext: "days", icon: Target },
  { label: "Progress", value: "24%", subtext: "overall", icon: TrendingUp },
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

        {/* Stats Cards */}
        <div className="grid grid-cols-1 md:grid-cols-2 lg:grid-cols-4 gap-6">
          {stats.map((stat) => (
            <Card key={stat.label}>
              <CardContent className="p-6">
                <div className="flex items-center space-x-2">
                  <stat.icon className="w-4 h-4 text-muted-foreground" />
                  <p className="text-sm text-muted-foreground">{stat.label}</p>
                </div>
                <div className="flex items-baseline space-x-1 mt-2">
                  <p className="text-2xl font-bold">{stat.value}</p>
                  <p className="text-sm text-muted-foreground">{stat.subtext}</p>
                </div>
              </CardContent>
            </Card>
          ))}
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
                    <div className="flex-shrink-0">
                      {lesson.completed ? (
                        <CheckCircle className="w-5 h-5 text-green-500" />
                      ) : (
                        <Circle className="w-5 h-5 text-muted-foreground" />
                      )}
                    </div>
                    <div className="flex-1 min-w-0">
                      <div className="flex items-center justify-between">
                        <div>
                          <p className="font-medium truncate">{lesson.title}</p>
                          <p className="text-sm text-muted-foreground">{lesson.course}</p>
                        </div>
                        <div className="text-right">
                          <p className="text-sm font-medium">{lesson.timeLeft}</p>
                          {!lesson.completed && (
                            <Progress value={lesson.progress} className="w-20 h-1 mt-1" />
                          )}
                        </div>
                      </div>
                    </div>
                    <Button variant="ghost" size="sm" asChild>
                      <Link to={lesson.url}>
                        {lesson.completed ? 'Review' : 'Continue'}
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
                          <span>{course.duration}</span>
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

            {/* Study Plan */}
            <Card>
              <CardHeader>
                <CardTitle>Your Study Plan</CardTitle>
                <CardDescription>
                  Recommended next steps
                </CardDescription>
              </CardHeader>
              <CardContent className="space-y-3">
                <div className="space-y-2">
                  <div className="flex justify-between text-sm">
                    <span>Week 1: Foundations</span>
                    <span className="text-green-500">✓</span>
                  </div>
                  <div className="flex justify-between text-sm">
                    <span>Week 2: Data Structures</span>
                    <span className="bg-primary text-primary-foreground text-xs px-2 py-1 rounded">Current</span>
                  </div>
                  <div className="flex justify-between text-sm text-muted-foreground">
                    <span>Week 3: Algorithms</span>
                    <span>Upcoming</span>
                  </div>
                  <div className="flex justify-between text-sm text-muted-foreground">
                    <span>Week 4: System Design</span>
                    <span>Upcoming</span>
                  </div>
                </div>
                <Button variant="outline" className="w-full" size="sm">
                  View Full Plan
                </Button>
              </CardContent>
            </Card>

            {/* Quick Stats */}
            <Card>
              <CardHeader>
                <CardTitle>This Week</CardTitle>
              </CardHeader>
              <CardContent className="space-y-3">
                <div className="flex justify-between">
                  <span className="text-sm">Study time</span>
                  <span className="text-sm font-medium">8.5h / 10h</span>
                </div>
                <Progress value={85} />
                <div className="flex justify-between">
                  <span className="text-sm">Lessons completed</span>
                  <span className="text-sm font-medium">5 / 7</span>
                </div>
                <Progress value={71} />
              </CardContent>
            </Card>
          </div>
        </div>
      </div>
    </Layout>
  );
}