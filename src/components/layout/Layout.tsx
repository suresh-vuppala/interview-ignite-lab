import { ReactNode } from 'react';
import { SidebarProvider } from '@/components/ui/sidebar';
import { AppSidebar } from './AppSidebar';
import { Header } from './Header';

interface LayoutProps {
  children: ReactNode;
}

export function Layout({ children }: LayoutProps) {
  return (
    <SidebarProvider defaultOpen={true}>
      <div className="h-screen flex w-full bg-background overflow-hidden">
        <AppSidebar />
        <div className="flex-1 flex flex-col min-w-0">
          <Header />
<<<<<<< HEAD
          <main className="flex-1 overflow-auto px-8 lg:px-20 pt-4 lg:pt-24">
=======
          <main className="flex-1 overflow-auto">
>>>>>>> parent of 78558da (cc)
            {children}
          </main>
        </div>
      </div>
    </SidebarProvider>
  );
}
