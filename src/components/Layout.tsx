import React, { ReactNode, useState } from 'react';
import { SidebarProvider, SidebarTrigger } from '@/components/ui/sidebar';
import { AppSidebar } from '@/components/AppSidebar';
import { Button } from '@/components/ui/button';
import { LogOut, Crown, Sun, Moon, BookOpen, Briefcase, HelpCircle, Users, Menu, GraduationCap } from 'lucide-react';
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
  NavigationMenuLink,
  NavigationMenuList,
  NavigationMenuTrigger,
} from "@/components/ui/navigation-menu";
import {
  Sheet,
  SheetContent,
  SheetTrigger,
} from "@/components/ui/sheet";
import { Badge } from '@/components/ui/badge';
import { Link } from 'react-router-dom';
import { useTheme } from "next-themes";

interface LayoutProps {
  children: ReactNode;
}

export function Layout({ children }: LayoutProps) {
  const { user, signOut } = useAuth();
  const { theme, setTheme } = useTheme();
  const [mobileMenuOpen, setMobileMenuOpen] = useState(false);

  return (
    <SidebarProvider>
      <div className="min-h-screen flex w-full">
        <AppSidebar />
        
        <div className="flex-1 flex flex-col min-w-0">
          {/* Header */}
          <header className="h-14 border-b bg-background/95 backdrop-blur supports-[backdrop-filter]:bg-background/60 sticky top-0 z-50">
            <div className="flex items-center justify-between h-full px-4">
              <div className="flex items-center gap-4 min-w-0">
                <SidebarTrigger className="lg:hidden" />
                
                {/* Logo */}
                <Link to="/" className="flex items-center gap-2 font-bold text-lg hover:opacity-80 transition-opacity">
                  <GraduationCap className="h-6 w-6 text-primary" />
                  <span className="hidden sm:inline">Interview60</span>
                </Link>
                
                <div className="h-6 w-px bg-border hidden lg:block" />
                
                {/* Desktop Navigation */}
                <NavigationMenu className="hidden lg:flex">
                  <NavigationMenuList>
                    <NavigationMenuItem>
                      <NavigationMenuTrigger>
                        <BookOpen className="w-4 h-4 mr-2" />
                        Courses
                      </NavigationMenuTrigger>
                      <NavigationMenuContent>
                        <div className="grid gap-3 p-4 md:w-[400px] lg:w-[500px]">
                          <Link className="block select-none space-y-1 rounded-md p-3 leading-none no-underline outline-none transition-colors hover:bg-accent hover:text-accent-foreground focus:bg-accent focus:text-accent-foreground" to="/course/dsa">
                            <div className="text-sm font-medium leading-none">DSA</div>
                            <p className="line-clamp-2 text-sm leading-snug text-muted-foreground">
                              Data Structures & Algorithms
                            </p>
                          </Link>
                          <Link className="block select-none space-y-1 rounded-md p-3 leading-none no-underline outline-none transition-colors hover:bg-accent hover:text-accent-foreground focus:bg-accent focus:text-accent-foreground" to="/course/system-design-hld">
                            <div className="text-sm font-medium leading-none">System Design (HLD)</div>
                            <p className="line-clamp-2 text-sm leading-snug text-muted-foreground">
                              High Level Design
                            </p>
                          </Link>
                          <Link className="block select-none space-y-1 rounded-md p-3 leading-none no-underline outline-none transition-colors hover:bg-accent hover:text-accent-foreground focus:bg-accent focus:text-accent-foreground" to="/course/lld">
                            <div className="text-sm font-medium leading-none">LLD</div>
                            <p className="line-clamp-2 text-sm leading-snug text-muted-foreground">
                              Low Level Design
                            </p>
                          </Link>
                          <Link className="block select-none space-y-1 rounded-md p-3 leading-none no-underline outline-none transition-colors hover:bg-accent hover:text-accent-foreground focus:bg-accent focus:text-accent-foreground" to="/course/behavioral">
                            <div className="text-sm font-medium leading-none">Behavioral</div>
                            <p className="line-clamp-2 text-sm leading-snug text-muted-foreground">
                              Interview Skills
                            </p>
                          </Link>
                        </div>
                      </NavigationMenuContent>
                    </NavigationMenuItem>
                    <NavigationMenuItem>
                      <NavigationMenuLink className="group inline-flex h-9 w-max items-center justify-center rounded-md bg-background px-4 py-2 text-sm font-medium transition-colors hover:bg-accent hover:text-accent-foreground focus:bg-accent focus:text-accent-foreground focus:outline-none disabled:pointer-events-none disabled:opacity-50" href="/interviews">
                        <Briefcase className="w-4 h-4 mr-2" />
                        Interviews
                      </NavigationMenuLink>
                    </NavigationMenuItem>
                    <NavigationMenuItem>
                      <NavigationMenuLink className="group inline-flex h-9 w-max items-center justify-center rounded-md bg-background px-4 py-2 text-sm font-medium transition-colors hover:bg-accent hover:text-accent-foreground focus:bg-accent focus:text-accent-foreground focus:outline-none disabled:pointer-events-none disabled:opacity-50" href="/questions">
                        <HelpCircle className="w-4 h-4 mr-2" />
                        Questions
                      </NavigationMenuLink>
                    </NavigationMenuItem>
                    <NavigationMenuItem>
                      <NavigationMenuLink className="group inline-flex h-9 w-max items-center justify-center rounded-md bg-background px-4 py-2 text-sm font-medium transition-colors hover:bg-accent hover:text-accent-foreground focus:bg-accent focus:text-accent-foreground focus:outline-none disabled:pointer-events-none disabled:opacity-50" href="/social">
                        <Users className="w-4 h-4 mr-2" />
                        Social
                      </NavigationMenuLink>
                    </NavigationMenuItem>
                  </NavigationMenuList>
                </NavigationMenu>
              </div>
              
              <div className="flex items-center gap-2">
                <Button
                  variant="ghost"
                  size="sm"
                  onClick={() => setTheme(theme === "light" ? "dark" : "light")}
                >
                  <Sun className="h-4 w-4 rotate-0 scale-100 transition-all dark:-rotate-90 dark:scale-0" />
                  <Moon className="absolute h-4 w-4 rotate-90 scale-0 transition-all dark:rotate-0 dark:scale-100" />
                  <span className="sr-only">Toggle theme</span>
                </Button>
                
                {user ? (
                  <DropdownMenu>
                    <DropdownMenuTrigger asChild>
                      <Button variant="ghost" className="relative h-8 w-8 rounded-full hidden lg:flex">
                        <Avatar className="h-8 w-8">
                          <AvatarFallback className="bg-primary text-primary-foreground text-sm">
                            {user.email?.charAt(0).toUpperCase()}
                          </AvatarFallback>
                        </Avatar>
                      </Button>
                    </DropdownMenuTrigger>
                    <DropdownMenuContent className="w-56" align="end" forceMount>
                      <DropdownMenuLabel className="font-normal">
                        <div className="flex flex-col space-y-1">
                          <p className="text-sm font-medium leading-none">
                            {user.user_metadata?.full_name || user.email}
                          </p>
                          <p className="text-xs leading-none text-muted-foreground">
                            {user.email}
                          </p>
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
                          <span>Upgrade to Pro</span>
                        </Link>
                      </DropdownMenuItem>
                      <DropdownMenuSeparator />
                      <DropdownMenuItem onClick={signOut}>
                        <LogOut className="mr-2 h-4 w-4" />
                        <span>Log out</span>
                      </DropdownMenuItem>
                    </DropdownMenuContent>
                  </DropdownMenu>
                ) : null}

                {/* Mobile Menu */}
                <Sheet open={mobileMenuOpen} onOpenChange={setMobileMenuOpen}>
                  <SheetTrigger asChild>
                    <Button variant="ghost" size="sm" className="lg:hidden">
                      <Menu className="h-5 w-5" />
                    </Button>
                  </SheetTrigger>
                  <SheetContent side="right" className="w-[300px] sm:w-[400px]">
                    <nav className="flex flex-col gap-4 mt-6">
                      <div className="space-y-1">
                        <h3 className="font-semibold text-sm text-muted-foreground mb-2">Courses</h3>
                        <Link 
                          to="/course/dsa" 
                          className="flex items-center gap-3 px-3 py-2 rounded-md hover:bg-accent transition-colors"
                          onClick={() => setMobileMenuOpen(false)}
                        >
                          <BookOpen className="h-4 w-4" />
                          <div>
                            <div className="font-medium">DSA</div>
                            <div className="text-xs text-muted-foreground">Data Structures & Algorithms</div>
                          </div>
                        </Link>
                        <Link 
                          to="/course/system-design-hld" 
                          className="flex items-center gap-3 px-3 py-2 rounded-md hover:bg-accent transition-colors"
                          onClick={() => setMobileMenuOpen(false)}
                        >
                          <BookOpen className="h-4 w-4" />
                          <div>
                            <div className="font-medium">System Design (HLD)</div>
                            <div className="text-xs text-muted-foreground">High Level Design</div>
                          </div>
                        </Link>
                        <Link 
                          to="/course/lld" 
                          className="flex items-center gap-3 px-3 py-2 rounded-md hover:bg-accent transition-colors"
                          onClick={() => setMobileMenuOpen(false)}
                        >
                          <BookOpen className="h-4 w-4" />
                          <div>
                            <div className="font-medium">LLD</div>
                            <div className="text-xs text-muted-foreground">Low Level Design</div>
                          </div>
                        </Link>
                        <Link 
                          to="/course/behavioral" 
                          className="flex items-center gap-3 px-3 py-2 rounded-md hover:bg-accent transition-colors"
                          onClick={() => setMobileMenuOpen(false)}
                        >
                          <BookOpen className="h-4 w-4" />
                          <div>
                            <div className="font-medium">Behavioral</div>
                            <div className="text-xs text-muted-foreground">Interview Skills</div>
                          </div>
                        </Link>
                      </div>

                      <div className="border-t pt-4 space-y-1">
                        <Link 
                          to="/interviews" 
                          className="flex items-center gap-3 px-3 py-2 rounded-md hover:bg-accent transition-colors"
                          onClick={() => setMobileMenuOpen(false)}
                        >
                          <Briefcase className="h-4 w-4" />
                          <span>Interviews</span>
                        </Link>
                        <Link 
                          to="/questions" 
                          className="flex items-center gap-3 px-3 py-2 rounded-md hover:bg-accent transition-colors"
                          onClick={() => setMobileMenuOpen(false)}
                        >
                          <HelpCircle className="h-4 w-4" />
                          <span>Questions</span>
                        </Link>
                        <Link 
                          to="/social" 
                          className="flex items-center gap-3 px-3 py-2 rounded-md hover:bg-accent transition-colors"
                          onClick={() => setMobileMenuOpen(false)}
                        >
                          <Users className="h-4 w-4" />
                          <span>Social</span>
                        </Link>
                      </div>

                      {user ? (
                        <div className="border-t pt-4 space-y-1">
                          <div className="px-3 py-2">
                            <p className="text-sm font-medium">{user.user_metadata?.full_name || user.email}</p>
                            <p className="text-xs text-muted-foreground">{user.email}</p>
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
                            <span>Upgrade to Pro</span>
                          </Link>
                          <button 
                            onClick={() => {
                              signOut();
                              setMobileMenuOpen(false);
                            }}
                            className="flex items-center gap-3 px-3 py-2 rounded-md hover:bg-accent transition-colors w-full text-left"
                          >
                            <LogOut className="h-4 w-4" />
                            <span>Log out</span>
                          </button>
                        </div>
                      ) : (
                        <div className="border-t pt-4 space-y-2">
                          <Button variant="outline" className="w-full" asChild onClick={() => setMobileMenuOpen(false)}>
                            <Link to="/auth">Sign In</Link>
                          </Button>
                          <Button className="w-full" asChild onClick={() => setMobileMenuOpen(false)}>
                            <Link to="/auth">Get Started</Link>
                          </Button>
                        </div>
                      )}
                    </nav>
                  </SheetContent>
                </Sheet>
              </div>
            </div>
          </header>
          
          {/* Main Content */}
          <main className="flex-1 overflow-auto min-w-0">
            <div className="min-h-full">
              {children}
            </div>
          </main>
        </div>
      </div>
    </SidebarProvider>
  );
}
