import { useState } from 'react';
import { SidebarTrigger } from '@/components/ui/sidebar';
import { Button } from '@/components/ui/button';
import { LogOut, Crown, Sun, Moon, BookOpen, Menu, Database, Brain } from 'lucide-react';
import { useAuth } from '@/hooks/useAuth';
import { Avatar, AvatarFallback } from '@/components/ui/avatar';
import {
  DropdownMenu,
  DropdownMenuContent,
  DropdownMenuItem,
  DropdownMenuLabel,
  DropdownMenuSeparator,
  DropdownMenuTrigger,
} from '@/components/ui/dropdown-menu';
import {
  NavigationMenu,
  NavigationMenuContent,
  NavigationMenuItem,
  NavigationMenuList,
  NavigationMenuTrigger,
} from "@/components/ui/navigation-menu";
import { Sheet, SheetContent, SheetTrigger } from "@/components/ui/sheet";
import { Badge } from '@/components/ui/badge';
import { Link } from 'react-router-dom';
import { useTheme } from "next-themes";

const courses = [
  { id: 'dsa', title: 'DSA', description: 'Data Structures & Algorithms', icon: Database },
  { id: 'system-design', title: 'System Design (HLD)', description: 'High Level Design', icon: Brain },
];

export function Header() {
  const { user, signOut } = useAuth();
  const { theme, setTheme } = useTheme();
  const [mobileMenuOpen, setMobileMenuOpen] = useState(false);

  return (
    <>
    {/* Desktop Floating Header */}
    <header className="hidden lg:block fixed top-6 left-1/2 -translate-x-1/2 lg:left-[calc(50%+var(--sidebar-width-desktop)/2)] max-w-4xl w-[calc(100%-2rem)] h-12 border bg-background/95 backdrop-blur supports-[backdrop-filter]:bg-background/60 rounded-full shadow-lg z-50">
      <div className="flex items-center justify-between h-full px-6">
        <div className="flex items-center gap-3 min-w-0 flex-1">
          <Link to="/" className="flex items-center hover:opacity-80 transition-opacity">
            <img
              src="/InterviewSortLogo.png"
              alt="InterviewSort"
              className="h-7 w-auto object-contain max-w-[160px]"
            />
          </Link>
          
          <div className="h-6 w-px bg-border" />
          
          <NavigationMenu>
            <NavigationMenuList>
              <NavigationMenuItem>
                <NavigationMenuTrigger className="text-sm h-9">
                  <BookOpen className="w-4 h-4 mr-2" />
                  Courses
                </NavigationMenuTrigger>
                <NavigationMenuContent>
                  <div className="grid gap-3 p-6 w-[420px]">
                    {courses.map(course => (
                      <Link 
                        key={course.id}
                        to={`/course/${course.id}`}
                        className="group flex items-start gap-4 select-none rounded-lg p-4 leading-none no-underline outline-none transition-all hover:bg-accent hover:shadow-md border border-transparent hover:border-border"
                      >
                        <div className="mt-1 p-2 rounded-lg bg-primary/10 group-hover:bg-primary/20 transition-colors">
                          <course.icon className="w-5 h-5 text-primary" />
                        </div>
                        <div className="flex-1 space-y-1">
                          <div className="text-sm font-semibold leading-none group-hover:text-primary transition-colors">{course.title}</div>
                          <p className="line-clamp-2 text-sm leading-snug text-muted-foreground">{course.description}</p>
                        </div>
                      </Link>
                    ))}
                  </div>
                </NavigationMenuContent>
              </NavigationMenuItem>
            </NavigationMenuList>
          </NavigationMenu>
        </div>
        
        <div className="flex items-center gap-2">
          <Button
            variant="ghost"
            size="icon"
            className="h-9 w-9"
            onClick={() => setTheme(theme === "light" ? "dark" : "light")}
          >
            <Sun className="h-4 w-4 rotate-0 scale-100 transition-all dark:-rotate-90 dark:scale-0" />
            <Moon className="absolute h-4 w-4 rotate-90 scale-0 transition-all dark:rotate-0 dark:scale-100" />
            <span className="sr-only">Toggle theme</span>
          </Button>
          
          {user && (
            <DropdownMenu>
              <DropdownMenuTrigger asChild>
                <Button variant="ghost" className="relative h-9 w-9 rounded-full">
                  <Avatar className="h-8 w-8">
                    <AvatarFallback className="bg-primary text-primary-foreground text-sm">
                      {user.email?.charAt(0).toUpperCase()}
                    </AvatarFallback>
                  </Avatar>
                </Button>
              </DropdownMenuTrigger>
              <DropdownMenuContent className="w-56" align="end">
                <DropdownMenuLabel>
                  <div className="flex flex-col space-y-1">
                    <p className="text-sm font-medium truncate">
                      {user.user_metadata?.full_name || user.email}
                    </p>
                    <p className="text-xs text-muted-foreground truncate">{user.email}</p>
                    <Badge variant="secondary" className="w-fit mt-1">
                      <Crown className="w-3 h-3 mr-1" />
                      Free Plan
                    </Badge>
                  </div>
                </DropdownMenuLabel>
                <DropdownMenuSeparator />
                <DropdownMenuItem asChild>
                  <Link to="/upgrade">
                    <Crown className="mr-2 h-4 w-4" />
                    Upgrade to Pro
                  </Link>
                </DropdownMenuItem>
                <DropdownMenuSeparator />
                <DropdownMenuItem onClick={signOut}>
                  <LogOut className="mr-2 h-4 w-4" />
                  Log out
                </DropdownMenuItem>
              </DropdownMenuContent>
            </DropdownMenu>
          )}
        </div>
      </div>
    </header>

    {/* Mobile Header */}
    <header className="lg:hidden h-14 border-b bg-background/95 backdrop-blur supports-[backdrop-filter]:bg-background/60 sticky top-0 z-50">
      <div className="flex items-center justify-between h-full px-4">
        <div className="flex items-center gap-3">
          <SidebarTrigger className="-ml-1" />
          <Link to="/" className="flex items-center hover:opacity-80 transition-opacity">
            <img
              src="/InterviewSortLogo.png"
              alt="InterviewSort"
              className="h-7 w-auto object-contain max-w-[140px]"
            />
          </Link>
        </div>
        
        <div className="flex items-center gap-2">
          <Button
            variant="ghost"
            size="icon"
            className="h-9 w-9"
            onClick={() => setTheme(theme === "light" ? "dark" : "light")}
          >
            <Sun className="h-4 w-4 rotate-0 scale-100 transition-all dark:-rotate-90 dark:scale-0" />
            <Moon className="absolute h-4 w-4 rotate-90 scale-0 transition-all dark:rotate-0 dark:scale-100" />
            <span className="sr-only">Toggle theme</span>
          </Button>

          <Sheet open={mobileMenuOpen} onOpenChange={setMobileMenuOpen}>
            <SheetTrigger asChild>
              <Button variant="ghost" size="icon" className="h-9 w-9">
                <Menu className="h-5 w-5" />
              </Button>
            </SheetTrigger>
            <SheetContent side="right" className="w-[300px] sm:w-[350px]">
              <nav className="flex flex-col gap-4 mt-6">
                <div className="space-y-1">
                  <h3 className="font-semibold text-xs text-muted-foreground mb-2 px-2">COURSES</h3>
                  {courses.map(course => (
                    <Link 
                      key={course.id}
                      to={`/course/${course.id}`}
                      className="flex flex-col gap-1 px-3 py-2.5 rounded-md hover:bg-accent transition-colors"
                      onClick={() => setMobileMenuOpen(false)}
                    >
                      <div className="font-medium text-sm">{course.title}</div>
                      <div className="text-xs text-muted-foreground">{course.description}</div>
                    </Link>
                  ))}
                </div>

                {user && (
                  <div className="border-t pt-4 space-y-2">
                    <div className="px-3 py-2">
                      <p className="text-sm font-medium truncate">
                        {user.user_metadata?.full_name || user.email}
                      </p>
                      <p className="text-xs text-muted-foreground truncate">{user.email}</p>
                      <Badge variant="secondary" className="w-fit mt-2">
                        <Crown className="w-3 h-3 mr-1" />
                        Free Plan
                      </Badge>
                    </div>
                    <Link 
                      to="/upgrade" 
                      className="flex items-center gap-3 px-3 py-2 rounded-md hover:bg-accent transition-colors"
                      onClick={() => setMobileMenuOpen(false)}
                    >
                      <Crown className="h-4 w-4" />
                      Upgrade to Pro
                    </Link>
                    <button 
                      onClick={() => {
                        signOut();
                        setMobileMenuOpen(false);
                      }}
                      className="flex items-center gap-3 px-3 py-2 rounded-md hover:bg-accent transition-colors w-full text-left"
                    >
                      <LogOut className="h-4 w-4" />
                      Log out
                    </button>
                  </div>
                )}
              </nav>
            </SheetContent>
          </Sheet>
        </div>
      </div>
    </header>
    </>
  );
}
