import React from "react";
import { Link } from "react-router-dom";
import { Layout } from "@/components/layout";
import { Button } from "@/components/ui/button";
import { Card, CardContent, CardDescription, CardHeader, CardTitle } from "@/components/ui/card";
import { Badge } from "@/components/ui/badge";
import {
  Sheet,
  SheetContent,
  SheetTrigger,
} from "@/components/ui/sheet";
import {
  NavigationMenu,
  NavigationMenuContent,
  NavigationMenuItem,
  NavigationMenuList,
  NavigationMenuTrigger,
} from "@/components/ui/navigation-menu";

import {
  BookOpen,
  Code,
  Brain,
  Users,
  Star,
  TrendingUp,
  Clock,
  ArrowRight,
  Play,
  Menu,
  Database,
} from "lucide-react";

import { useAuth } from "@/hooks/useAuth";

const courses = [
  { id: "dsa", title: "DSA", description: "Data Structures & Algorithms", icon: Database },
  { id: "system-design", title: "System Design (HLD)", description: "High Level Design", icon: Brain },
];

const features = [
  {
    icon: Code,
    title: "Data Structures & Algorithms",
    description: "Master the most important patterns that solve 80% of coding problems",
    lessons: 24,
    color: "text-blue-500",
    link: "/course/dsa",
  },
  {
    icon: Brain,
    title: "System Design",
    description: "Learn to design scalable systems like a senior engineer",
    lessons: 18,
    color: "text-purple-500",
    link: "/course/system-design",
  },
];

const stats = [
  { label: "Students", value: "10,000+", icon: Users },
  { label: "Success Rate", value: "89%", icon: TrendingUp },
  { label: "Companies", value: "500+", icon: Star },
  { label: "Hours of Content", value: "50+", icon: Clock },
];

const Index = () => {
  const { user } = useAuth();
  const [mobileMenuOpen, setMobileMenuOpen] = React.useState(false);

  if (user) {
    return (
      <Layout>
        <div className="max-w-6xl mx-auto px-6 py-12">
          <h1 className="text-4xl font-bold mb-4">
            Welcome to InterviewSort
          </h1>
          <p className="text-muted-foreground">
            Select a course from the menu to get started.
          </p>
        </div>
      </Layout>
    );
  }

  return (
    <div className="min-h-screen bg-background">

        {/* Desktop Header */}
        <header className="hidden lg:flex fixed top-6 left-1/2 -translate-x-1/2 max-w-5xl w-[calc(100%-2rem)] h-14 border bg-background/95 backdrop-blur rounded-full shadow-lg z-50 items-center justify-between px-6">
          
          <Link to="/" className="flex items-center">
            <img
              src="/InterviewSortLogo.png"
              alt="InterviewSort"
              className="h-7"
            />
          </Link>

          <div className="flex items-center gap-4">

            <NavigationMenu>
              <NavigationMenuList>
                <NavigationMenuItem>
                  <NavigationMenuTrigger className="text-sm h-9">
                    <BookOpen className="w-4 h-4 mr-2" />
                    Courses
                  </NavigationMenuTrigger>

                  <NavigationMenuContent>
                    <div className="grid gap-3 p-6 w-[420px]">
                      {courses.map((course) => (
                        <Link
                          key={course.id}
                          to={`/course/${course.id}`}
                          className="group flex items-start gap-4 select-none rounded-lg p-4 leading-none no-underline outline-none transition-all hover:bg-accent hover:shadow-md border border-transparent hover:border-border"
                        >
                          <div className="mt-1 p-2 rounded-lg bg-primary/10 group-hover:bg-primary/20 transition-colors">
                            <course.icon className="w-5 h-5 text-primary" />
                          </div>
                          <div className="flex-1 space-y-1">
                            <div className="text-sm font-semibold leading-none group-hover:text-primary transition-colors">
                              {course.title}
                            </div>
                            <p className="line-clamp-2 text-sm leading-snug text-muted-foreground">
                              {course.description}
                            </p>
                          </div>
                        </Link>
                      ))}
                    </div>
                  </NavigationMenuContent>

                </NavigationMenuItem>
              </NavigationMenuList>
            </NavigationMenu>

            <Button size="sm" asChild>
              <Link to="/course/dsa/programming-essentials/getting-started/getting-started-with-easy-problems">
                Get Started
              </Link>
            </Button>

          </div>
        </header>

        {/* Mobile Header */}
        <header className="lg:hidden fixed top-0 left-0 right-0 h-16 border-b bg-background z-50 flex items-center justify-between px-4">

          <Link to="/" className="flex items-center">
            <img
              src="/InterviewSortLogo.png"
              alt="InterviewSort"
              className="h-7"
            />
          </Link>

          <Sheet open={mobileMenuOpen} onOpenChange={setMobileMenuOpen}>
            <SheetTrigger asChild>
              <Button variant="ghost" size="icon" aria-label="Menu">
                <Menu className="h-5 w-5" />
              </Button>
            </SheetTrigger>

            <SheetContent side="right" className="w-[300px]">
              <nav className="flex flex-col gap-6 mt-8">

                <div>
                  <h3 className="text-sm font-semibold text-muted-foreground mb-3">
                    COURSES
                  </h3>

                  {courses.map((course) => (
                    <Link
                      key={course.id}
                      to={`/course/${course.id}`}
                      className="block px-3 py-3 rounded-md hover:bg-accent"
                      onClick={() => setMobileMenuOpen(false)}
                    >
                      <div className="font-medium">{course.title}</div>
                      <div className="text-sm text-muted-foreground">
                        {course.description}
                      </div>
                    </Link>
                  ))}

                </div>

                <Button asChild>
                  <Link
                    to="/course/dsa/programming-essentials/getting-started/getting-started-with-easy-problems"
                    onClick={() => setMobileMenuOpen(false)}
                  >
                    Get Started Free
                  </Link>
                </Button>

              </nav>
            </SheetContent>
          </Sheet>

        </header>

        {/* Hero */}
        <section className="pt-28 pb-20 text-center bg-gradient-to-b from-primary/5 to-background">

          <div className="max-w-5xl mx-auto px-6">

            <Badge variant="secondary" className="mb-6">
              <Star className="w-3 h-3 mr-1 fill-yellow-500 text-yellow-500" />
              Trusted by 10,000+ developers
            </Badge>

            <h1 className="text-4xl md:text-6xl font-bold mb-6">
              Master Tech Interviews in{" "}
              <span className="bg-gradient-to-r from-primary to-purple-600 bg-clip-text text-transparent">
                60 Days
              </span>
            </h1>

            <p className="text-lg text-muted-foreground mb-10 max-w-3xl mx-auto">
              The most structured way to prepare for coding interviews.
              Learn key patterns, master system design, and land your dream job.
            </p>

            <div className="flex flex-col sm:flex-row gap-4 justify-center">

              <Button size="lg" className="h-14 px-10" asChild>
                <Link to="/course/dsa/programming-essentials/getting-started/getting-started-with-easy-problems">
                  <Play className="w-5 h-5 mr-2" />
                  Start Learning Free
                </Link>
              </Button>

              <Button size="lg" variant="outline" className="h-14 px-10" asChild>
                <Link to="/course/system-design/system-design-foundations/introduction-to-system-design/what-why-how-when-where-system-design">
                  <Brain className="w-5 h-5 mr-2" />
                  System Design
                </Link>
              </Button>

            </div>

          </div>
        </section>

        {/* Features */}
        <section className="py-20 bg-muted/30">
          <div className="max-w-5xl mx-auto px-6">

            <div className="text-center mb-16">
              <h2 className="text-4xl font-bold mb-4">
                Everything You Need to Succeed
              </h2>

              <p className="text-lg text-muted-foreground max-w-2xl mx-auto">
                Comprehensive curriculum covering all aspects of technical interviews
              </p>
            </div>

            <div className="grid md:grid-cols-2 gap-8">

              {features.map((feature) => (
                <Card key={feature.title} className="p-8 hover:shadow-xl transition">

                  <CardHeader className="pb-6">
                    <div className="flex gap-4">

                      <div className="p-3 rounded-xl bg-muted">
                        <feature.icon className={`w-8 h-8 ${feature.color}`} />
                      </div>

                      <div>
                        <CardTitle className="text-2xl">
                          {feature.title}
                        </CardTitle>

                        <CardDescription>
                          {feature.description}
                        </CardDescription>
                      </div>

                    </div>
                  </CardHeader>

                  <CardContent>
                    <Button variant="ghost" size="sm" asChild>
                      <Link to={feature.link}>
                        Explore Course
                        <ArrowRight className="w-4 h-4 ml-2" />
                      </Link>
                    </Button>
                  </CardContent>

                </Card>
              ))}

            </div>

          </div>
        </section>

        {/* CTA */}
        <section className="py-20 bg-gradient-to-r from-primary via-blue-600 to-purple-600 text-white">

          <div className="max-w-4xl mx-auto text-center px-6">

            <h2 className="text-4xl font-bold mb-6">
              Ready to Land Your Dream Job?
            </h2>

            <p className="text-lg opacity-90 mb-10">
              Join thousands of developers who successfully prepared
              for tech interviews with InterviewSort.
            </p>

            <div className="flex flex-col sm:flex-row gap-4 justify-center">

              <Button size="lg" variant="secondary" className="h-14 px-10" asChild>
                <Link to="/course/dsa/programming-essentials/getting-started/getting-started-with-easy-problems">
                  <Code className="w-5 h-5 mr-2" />
                  Start Coding
                </Link>
              </Button>

              <Button
                size="lg"
                variant="outline"
                className="h-14 px-10 border-white text-white hover:bg-white hover:text-primary"
                asChild
              >
                <Link to="/course/system-design/system-design-foundations/introduction-to-system-design/what-why-how-when-where-system-design">
                  <Brain className="w-5 h-5 mr-2" />
                  System Design
                </Link>
              </Button>

            </div>

          </div>
        </section>

      </div>
  );
};

export default Index;