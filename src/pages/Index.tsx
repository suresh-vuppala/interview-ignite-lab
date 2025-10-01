import { Button } from '@/components/ui/button';
import { Card, CardContent, CardDescription, CardHeader, CardTitle } from '@/components/ui/card';
import { Badge } from '@/components/ui/badge';
import { Layout } from '@/components/Layout';
import { Header } from '@/components/Header';
import { 
  BookOpen, 
  Code, 
  Brain, 
  Users, 
  CheckCircle, 
  Star,
  TrendingUp,
  Clock,
  Target,
  Crown,
  ArrowRight,
  Play
} from 'lucide-react';
import { Link } from 'react-router-dom';
import { useAuth } from '@/hooks/useAuth';

const features = [
  {
    icon: Code,
    title: "Data Structures & Algorithms",
    description: "Master the most important patterns that solve 80% of coding problems",
    lessons: 24,
    color: "text-blue-500"
  },
  {
    icon: Brain,
    title: "System Design",
    description: "Learn to design scalable systems like a senior engineer",
    lessons: 18,
    color: "text-purple-500"
  },
  {
    icon: Users,
    title: "Behavioral Interviews",
    description: "Perfect your soft skills and leadership stories",
    lessons: 12,
    color: "text-green-500"
  },
  {
    icon: Target,
    title: "Mock Interviews",
    description: "Practice with real interview scenarios and get feedback",
    lessons: 15,
    color: "text-orange-500"
  }
];

const stats = [
  { label: "Students", value: "10,000+", icon: Users },
  { label: "Success Rate", value: "89%", icon: TrendingUp },
  { label: "Companies", value: "500+", icon: Star },
  { label: "Hours of Content", value: "50+", icon: Clock },
];

const testimonials = [
  {
    name: "Sarah Chen",
    role: "Software Engineer at Google",
    content: "Interview60 helped me land my dream job at Google. The structured approach and real interview patterns made all the difference.",
    rating: 5
  },
  {
    name: "Michael Rodriguez",
    role: "Senior SDE at Amazon",
    content: "The system design course is incredible. I went from struggling with design questions to confidently architecting complex systems.",
    rating: 5
  },
  {
    name: "Emily Zhang",
    role: "Frontend Engineer at Meta",
    content: "The behavioral interview prep was a game-changer. I finally knew how to tell compelling stories about my experience.",
    rating: 5
  }
];

const Index = () => {
  const { user } = useAuth();

  if (user) {
    return (
      <Layout>
        <div className="container mx-auto px-4 py-12">
          <h1 className="text-4xl font-bold mb-4">Welcome to Interview60</h1>
          <p className="text-muted-foreground">Select a course from the menu to get started.</p>
        </div>
      </Layout>
    );
  }

  return (
    <div className="min-h-screen bg-background">
      <Header />

      {/* Hero Section */}
      <section className="relative py-20 px-4 text-center bg-gradient-to-br from-background via-primary/5 to-background">
        <div className="container mx-auto max-w-4xl">
          <Badge variant="secondary" className="mb-6">
            <Star className="w-3 h-3 mr-1" />
            Trusted by 10,000+ developers
          </Badge>
          
          <h1 className="text-5xl md:text-6xl font-bold mb-6 bg-gradient-to-r from-foreground to-foreground/70 bg-clip-text text-transparent">
            Master Coding Interviews in{' '}
            <span className="bg-gradient-to-r from-primary to-blue-600 bg-clip-text text-transparent">
              60 Days
            </span>
          </h1>
          
          <p className="text-xl text-muted-foreground mb-8 max-w-2xl mx-auto leading-relaxed">
            The most structured way to prepare for coding interviews. Learn key patterns, 
            master system design, and land your dream job at top tech companies.
          </p>
          
          <div className="flex flex-col sm:flex-row gap-4 justify-center items-center">
            <Button size="lg" className="text-lg px-8" asChild>
              <Link to="/auth">
                <Play className="w-5 h-5 mr-2" />
                Start Learning Free
              </Link>
            </Button>
            <Button variant="outline" size="lg" className="text-lg px-8">
              <BookOpen className="w-5 h-5 mr-2" />
              View Curriculum
            </Button>
          </div>
          
          <div className="mt-12 grid grid-cols-2 md:grid-cols-4 gap-8">
            {stats.map((stat) => (
              <div key={stat.label} className="text-center">
                <div className="flex justify-center mb-2">
                  <stat.icon className="w-6 h-6 text-primary" />
                </div>
                <div className="text-2xl font-bold">{stat.value}</div>
                <div className="text-sm text-muted-foreground">{stat.label}</div>
              </div>
            ))}
          </div>
        </div>
      </section>

      {/* Features Section */}
      <section className="py-20 px-4">
        <div className="container mx-auto max-w-6xl">
          <div className="text-center mb-16">
            <h2 className="text-3xl md:text-4xl font-bold mb-4">
              Everything You Need to Succeed
            </h2>
            <p className="text-xl text-muted-foreground max-w-2xl mx-auto">
              Our comprehensive curriculum covers all aspects of technical interviews
            </p>
          </div>
          
          <div className="grid md:grid-cols-2 gap-8">
            {features.map((feature) => (
              <Card key={feature.title} className="p-6 hover:shadow-lg transition-shadow">
                <CardHeader className="pb-4">
                  <div className="flex items-center gap-3 mb-2">
                    <feature.icon className={`w-8 h-8 ${feature.color}`} />
                    <CardTitle className="text-xl">{feature.title}</CardTitle>
                  </div>
                  <CardDescription className="text-base">
                    {feature.description}
                  </CardDescription>
                </CardHeader>
                <CardContent className="pt-0">
                  <div className="flex items-center justify-between">
                    <span className="text-sm text-muted-foreground">
                      {feature.lessons} lessons
                    </span>
                    <Button variant="ghost" size="sm">
                      Learn More
                      <ArrowRight className="w-4 h-4 ml-1" />
                    </Button>
                  </div>
                </CardContent>
              </Card>
            ))}
          </div>
        </div>
      </section>

      {/* Testimonials */}
      <section className="py-20 px-4 bg-muted/30">
        <div className="container mx-auto max-w-6xl">
          <div className="text-center mb-16">
            <h2 className="text-3xl md:text-4xl font-bold mb-4">
              Success Stories
            </h2>
            <p className="text-xl text-muted-foreground">
              Join thousands who've landed their dream jobs
            </p>
          </div>
          
          <div className="grid md:grid-cols-3 gap-8">
            {testimonials.map((testimonial) => (
              <Card key={testimonial.name} className="p-6">
                <CardContent className="space-y-4">
                  <div className="flex gap-1">
                    {[...Array(testimonial.rating)].map((_, i) => (
                      <Star key={i} className="w-4 h-4 fill-yellow-400 text-yellow-400" />
                    ))}
                  </div>
                  <p className="text-muted-foreground italic">
                    "{testimonial.content}"
                  </p>
                  <div>
                    <p className="font-semibold">{testimonial.name}</p>
                    <p className="text-sm text-muted-foreground">{testimonial.role}</p>
                  </div>
                </CardContent>
              </Card>
            ))}
          </div>
        </div>
      </section>

      {/* CTA Section */}
      <section className="py-20 px-4 bg-gradient-to-r from-primary to-blue-600 text-white">
        <div className="container mx-auto max-w-4xl text-center">
          <h2 className="text-3xl md:text-4xl font-bold mb-4">
            Ready to Land Your Dream Job?
          </h2>
          <p className="text-xl opacity-90 mb-8 max-w-2xl mx-auto">
            Join thousands of developers who've successfully prepared for and aced 
            their coding interviews with Interview60.
          </p>
          
          <div className="flex flex-col sm:flex-row gap-4 justify-center">
            <Button size="lg" variant="secondary" className="text-lg px-8" asChild>
              <Link to="/auth">
                <Crown className="w-5 h-5 mr-2" />
                Start Free Trial
              </Link>
            </Button>
            <Button size="lg" variant="outline" className="text-lg px-8 border-white text-white hover:bg-white hover:text-primary">
              <BookOpen className="w-5 h-5 mr-2" />
              View Pricing
            </Button>
          </div>
          
          <div className="mt-8 flex items-center justify-center gap-8 text-sm opacity-80">
            <div className="flex items-center gap-2">
              <CheckCircle className="w-4 h-4" />
              No credit card required
            </div>
            <div className="flex items-center gap-2">
              <CheckCircle className="w-4 h-4" />
              7-day money back guarantee
            </div>
          </div>
        </div>
      </section>

      {/* Footer */}
      <footer className="py-12 px-4 border-t">
        <div className="container mx-auto max-w-6xl">
          <div className="grid md:grid-cols-4 gap-8">
            <div className="space-y-4">
              <div className="flex items-center gap-3">
                <div className="w-8 h-8 bg-gradient-to-br from-primary to-blue-600 rounded-lg flex items-center justify-center">
                  <BookOpen className="w-4 h-4 text-white" />
                </div>
                <span className="font-bold text-xl">Interview60</span>
              </div>
              <p className="text-muted-foreground">
                The most structured way to prepare for coding interviews.
              </p>
            </div>
            
            <div>
              <h3 className="font-semibold mb-4">Courses</h3>
              <ul className="space-y-2 text-muted-foreground">
                <li><Link to="/course/data-structures" className="hover:text-foreground">Data Structures</Link></li>
                <li><Link to="/course/algorithms" className="hover:text-foreground">Algorithms</Link></li>
                <li><Link to="/course/system-design" className="hover:text-foreground">System Design</Link></li>
                <li><Link to="/course/behavioral" className="hover:text-foreground">Behavioral</Link></li>
              </ul>
            </div>
            
            <div>
              <h3 className="font-semibold mb-4">Company</h3>
              <ul className="space-y-2 text-muted-foreground">
                <li><Link to="/about" className="hover:text-foreground">About</Link></li>
                <li><Link to="/blog" className="hover:text-foreground">Blog</Link></li>
                <li><Link to="/careers" className="hover:text-foreground">Careers</Link></li>
                <li><Link to="/contact" className="hover:text-foreground">Contact</Link></li>
              </ul>
            </div>
            
            <div>
              <h3 className="font-semibold mb-4">Support</h3>
              <ul className="space-y-2 text-muted-foreground">
                <li><Link to="/help" className="hover:text-foreground">Help Center</Link></li>
                <li><Link to="/privacy" className="hover:text-foreground">Privacy Policy</Link></li>
                <li><Link to="/terms" className="hover:text-foreground">Terms of Service</Link></li>
              </ul>
            </div>
          </div>
          
          <div className="border-t mt-8 pt-8 text-center text-muted-foreground">
            <p>&copy; 2024 Interview60. All rights reserved.</p>
          </div>
        </div>
      </footer>
    </div>
  );
};

export default Index;
