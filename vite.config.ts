import { defineConfig } from "vite";
import react from "@vitejs/plugin-react-swc";
import path from "path";
import { componentTagger } from "lovable-tagger";

// https://vitejs.dev/config/
export default defineConfig(({ mode }) => ({
  server: {
    host: "::",
    port: 8080,
    // ✅ Enables proper history fallback for React Router (fixes refresh)
    fs: {
      strict: false,
    },
  },
  plugins: [
    react(),
    mode === "development" && componentTagger(),
    // ✅ Handles SPA routing fallback for both dev & preview
    {
      name: "spa-fallback",
      configureServer(server: { middlewares: { use: (arg0: (req: any, res: any, next: any) => void) => void; }; }) {
        server.middlewares.use((req, res, next) => {
          if (
            req.url &&
            !req.url.includes(".") && // skip static assets
            !req.url.startsWith("/@")
          ) {
            req.url = "/";
          }
          next();
        });
      },
    },
  ].filter(Boolean),
  resolve: {
    alias: {
      "@": path.resolve(__dirname, "./src"),
    },
  },
}));
