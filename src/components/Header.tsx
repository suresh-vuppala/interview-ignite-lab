import { useState } from 'react';
import { Link, useLocation, NavLink } from 'react-router-dom';
import { Button } from '@/components/ui/button';
import { Sheet, SheetContent, SheetTrigger } from '@/components/ui/sheet';
import { BookOpen, Briefcase, HelpCircle, Users, Menu, Moon, Sun, Database, Brain, GitBranch, MessageSquare, ChevronDown } from 'lucide-react';
import { useTheme } from 'next-themes';
import { useAuth } from '@/hooks/useAuth';
import { DropdownMenu, DropdownMenuContent, DropdownMenuItem, DropdownMenuTrigger } from '@/components/ui/dropdown-menu';

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

export function Header() {
  const [mobileMenuOpen, setMobileMenuOpen] = useState(false);
  const { theme, setTheme } = useTheme();
  const { user, signOut } = useAuth();
  const location = useLocation();
  const pathSegments = location.pathname.split('/');
  const currentCourseSlug = pathSegments[2];
  const currentCourse = courses.find(course => course.id === currentCourseSlug);

  const menuItems = [
    { label: 'Interviews', href: '/interviews', icon: Briefcase },
    { label: 'Questions', href: '/questions', icon: HelpCircle },
    { label: 'Social', href: '/social', icon: Users },
  ];

  return (
    <header className="sticky top-0 z-50 w-full border-b bg-background/95 backdrop-blur supports-[backdrop-filter]:bg-background/60">
      <div className="container flex h-16 items-center justify-between px-4">
        {/* Logo */}
        <Link to="/" className="flex items-center gap-2 hover:opacity-80 transition-opacity">
          <BookOpen className="h-6 w-6 text-primary" />
          <span className="font-bold text-xl">InterviewEazy</span>
        </Link>

        {/* Desktop Navigation */}
        <nav className="hidden md:flex items-center gap-6">
          <DropdownMenu>
            <DropdownMenuTrigger asChild>
              <Button variant="ghost" className="flex items-center gap-2 h-9 px-3">
                {currentCourse ? (
                  <>
                    <currentCourse.icon className="w-4 h-4" />
                    <span className="hidden lg:inline">{currentCourse.title}</span>
                    <span className="lg:hidden">Courses</span>
                  </>
                ) : (
                  <>
                    <BookOpen className="w-4 h-4" />
                    <span>Courses</span>
                  </>
                )}
                <ChevronDown className="w-4 h-4" />
              </Button>
            </DropdownMenuTrigger>
            <DropdownMenuContent align="start" className="w-80 bg-background border shadow-lg z-50">
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
          
          {menuItems.map((item) => (
            <Link
              key={item.href}
              to={item.href}
              className="flex items-center gap-2 text-sm font-medium text-muted-foreground hover:text-foreground transition-colors"
            >
              <item.icon className="h-4 w-4" />
              {item.label}
            </Link>
          ))}
        </nav>

        {/* Desktop Actions */}
        <div className="hidden md:flex items-center gap-2">
          <Button
            variant="ghost"
            size="icon"
            onClick={() => setTheme(theme === 'light' ? 'dark' : 'light')}
          >
            {theme === 'light' ? (
              <Moon className="h-5 w-5" />
            ) : (
              <Sun className="h-5 w-5" />
            )}
          </Button>
          
          {user ? (
            <Button variant="outline" onClick={signOut}>
              Sign Out
            </Button>
          ) : (
            <>
              <Button variant="ghost" asChild>
                <Link to="/auth">Sign In</Link>
              </Button>
              <Button asChild>
                <Link to="/auth">Get Started</Link>
              </Button>
            </>
          )}
        </div>

        {/* Mobile Menu */}
        <Sheet open={mobileMenuOpen} onOpenChange={setMobileMenuOpen}>
          <SheetTrigger asChild className="md:hidden">
            <Button variant="ghost" size="icon">
              <Menu className="h-6 w-6" />
            </Button>
          </SheetTrigger>
          <SheetContent side="right" className="w-[300px] sm:w-[400px]">
            <nav className="flex flex-col gap-4 mt-8">
              <div className="mb-2">
                <p className="text-xs font-semibold text-muted-foreground mb-2 px-3">COURSES</p>
                {courses.map((course) => (
                  <Link
                    key={course.id}
                    to={`/course/${course.id}`}
                    className="flex items-center gap-3 p-3 rounded-lg hover:bg-accent transition-colors"
                    onClick={() => setMobileMenuOpen(false)}
                  >
                    <course.icon className="h-5 w-5 text-primary" />
                    <div className="flex-1">
                      <div className="font-medium text-sm">{course.title}</div>
                      <div className="text-xs text-muted-foreground">{course.description}</div>
                    </div>
                  </Link>
                ))}
              </div>
              
              <div className="border-t pt-2">
                {menuItems.map((item) => (
                  <Link
                    key={item.href}
                    to={item.href}
                    className="flex items-center gap-3 text-lg font-medium hover:text-primary transition-colors p-3"
                    onClick={() => setMobileMenuOpen(false)}
                  >
                    <item.icon className="h-5 w-5" />
                    {item.label}
                  </Link>
                ))}
              </div>
              
              <div className="border-t pt-4 mt-4 space-y-4">
                <Button
                  variant="outline"
                  className="w-full justify-start gap-2"
                  onClick={() => setTheme(theme === 'light' ? 'dark' : 'light')}
                >
                  {theme === 'light' ? (
                    <>
                      <Moon className="h-5 w-5" />
                      Dark Mode
                    </>
                  ) : (
                    <>
                      <Sun className="h-5 w-5" />
                      Light Mode
                    </>
                  )}
                </Button>
                
                {user ? (
                  <Button 
                    variant="outline" 
                    className="w-full"
                    onClick={() => {
                      signOut();
                      setMobileMenuOpen(false);
                    }}
                  >
                    Sign Out
                  </Button>
                ) : (
                  <>
                    <Button 
                      variant="outline" 
                      className="w-full"
                      asChild
                      onClick={() => setMobileMenuOpen(false)}
                    >
                      <Link to="/auth">Sign In</Link>
                    </Button>
                    <Button 
                      className="w-full"
                      asChild
                      onClick={() => setMobileMenuOpen(false)}
                    >
                      <Link to="/auth">Get Started</Link>
                    </Button>
                  </>
                )}
              </div>
            </nav>
          </SheetContent>
        </Sheet>
      </div>
    </header>
  );
}
