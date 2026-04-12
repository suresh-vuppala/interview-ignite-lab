// vite.config.ts
import { defineConfig } from "file:///home/claude/interview-ignite-lab/interview-ignite-lab/node_modules/vite/dist/node/index.js";
import react from "file:///home/claude/interview-ignite-lab/interview-ignite-lab/node_modules/@vitejs/plugin-react-swc/index.js";
import path from "path";
import { componentTagger } from "file:///home/claude/interview-ignite-lab/interview-ignite-lab/node_modules/lovable-tagger/dist/index.js";
var __vite_injected_original_dirname = "/home/claude/interview-ignite-lab/interview-ignite-lab";
var vite_config_default = defineConfig(({ mode }) => ({
  server: {
    host: "::",
    port: 8080,
    // ✅ Enables proper history fallback for React Router (fixes refresh)
    fs: {
      strict: false
    }
  },
  plugins: [
    react(),
    mode === "development" && componentTagger(),
    // ✅ Handles SPA routing fallback for both dev & preview
    {
      name: "spa-fallback",
      configureServer(server) {
        server.middlewares.use((req, res, next) => {
          if (req.url && !req.url.includes(".") && // skip static assets
          !req.url.startsWith("/@")) {
            req.url = "/";
          }
          next();
        });
      }
    }
  ].filter(Boolean),
  resolve: {
    alias: {
      "@": path.resolve(__vite_injected_original_dirname, "./src")
    }
  }
}));
export {
  vite_config_default as default
};
//# sourceMappingURL=data:application/json;base64,ewogICJ2ZXJzaW9uIjogMywKICAic291cmNlcyI6IFsidml0ZS5jb25maWcudHMiXSwKICAic291cmNlc0NvbnRlbnQiOiBbImNvbnN0IF9fdml0ZV9pbmplY3RlZF9vcmlnaW5hbF9kaXJuYW1lID0gXCIvaG9tZS9jbGF1ZGUvaW50ZXJ2aWV3LWlnbml0ZS1sYWIvaW50ZXJ2aWV3LWlnbml0ZS1sYWJcIjtjb25zdCBfX3ZpdGVfaW5qZWN0ZWRfb3JpZ2luYWxfZmlsZW5hbWUgPSBcIi9ob21lL2NsYXVkZS9pbnRlcnZpZXctaWduaXRlLWxhYi9pbnRlcnZpZXctaWduaXRlLWxhYi92aXRlLmNvbmZpZy50c1wiO2NvbnN0IF9fdml0ZV9pbmplY3RlZF9vcmlnaW5hbF9pbXBvcnRfbWV0YV91cmwgPSBcImZpbGU6Ly8vaG9tZS9jbGF1ZGUvaW50ZXJ2aWV3LWlnbml0ZS1sYWIvaW50ZXJ2aWV3LWlnbml0ZS1sYWIvdml0ZS5jb25maWcudHNcIjtpbXBvcnQgeyBkZWZpbmVDb25maWcgfSBmcm9tIFwidml0ZVwiO1xuaW1wb3J0IHJlYWN0IGZyb20gXCJAdml0ZWpzL3BsdWdpbi1yZWFjdC1zd2NcIjtcbmltcG9ydCBwYXRoIGZyb20gXCJwYXRoXCI7XG5pbXBvcnQgeyBjb21wb25lbnRUYWdnZXIgfSBmcm9tIFwibG92YWJsZS10YWdnZXJcIjtcblxuLy8gaHR0cHM6Ly92aXRlanMuZGV2L2NvbmZpZy9cbmV4cG9ydCBkZWZhdWx0IGRlZmluZUNvbmZpZygoeyBtb2RlIH0pID0+ICh7XG4gIHNlcnZlcjoge1xuICAgIGhvc3Q6IFwiOjpcIixcbiAgICBwb3J0OiA4MDgwLFxuICAgIC8vIFx1MjcwNSBFbmFibGVzIHByb3BlciBoaXN0b3J5IGZhbGxiYWNrIGZvciBSZWFjdCBSb3V0ZXIgKGZpeGVzIHJlZnJlc2gpXG4gICAgZnM6IHtcbiAgICAgIHN0cmljdDogZmFsc2UsXG4gICAgfSxcbiAgfSxcbiAgcGx1Z2luczogW1xuICAgIHJlYWN0KCksXG4gICAgbW9kZSA9PT0gXCJkZXZlbG9wbWVudFwiICYmIGNvbXBvbmVudFRhZ2dlcigpLFxuICAgIC8vIFx1MjcwNSBIYW5kbGVzIFNQQSByb3V0aW5nIGZhbGxiYWNrIGZvciBib3RoIGRldiAmIHByZXZpZXdcbiAgICB7XG4gICAgICBuYW1lOiBcInNwYS1mYWxsYmFja1wiLFxuICAgICAgY29uZmlndXJlU2VydmVyKHNlcnZlcjogeyBtaWRkbGV3YXJlczogeyB1c2U6IChhcmcwOiAocmVxOiBhbnksIHJlczogYW55LCBuZXh0OiBhbnkpID0+IHZvaWQpID0+IHZvaWQ7IH07IH0pIHtcbiAgICAgICAgc2VydmVyLm1pZGRsZXdhcmVzLnVzZSgocmVxLCByZXMsIG5leHQpID0+IHtcbiAgICAgICAgICBpZiAoXG4gICAgICAgICAgICByZXEudXJsICYmXG4gICAgICAgICAgICAhcmVxLnVybC5pbmNsdWRlcyhcIi5cIikgJiYgLy8gc2tpcCBzdGF0aWMgYXNzZXRzXG4gICAgICAgICAgICAhcmVxLnVybC5zdGFydHNXaXRoKFwiL0BcIilcbiAgICAgICAgICApIHtcbiAgICAgICAgICAgIHJlcS51cmwgPSBcIi9cIjtcbiAgICAgICAgICB9XG4gICAgICAgICAgbmV4dCgpO1xuICAgICAgICB9KTtcbiAgICAgIH0sXG4gICAgfSxcbiAgXS5maWx0ZXIoQm9vbGVhbiksXG4gIHJlc29sdmU6IHtcbiAgICBhbGlhczoge1xuICAgICAgXCJAXCI6IHBhdGgucmVzb2x2ZShfX2Rpcm5hbWUsIFwiLi9zcmNcIiksXG4gICAgfSxcbiAgfSxcbn0pKTtcbiJdLAogICJtYXBwaW5ncyI6ICI7QUFBb1YsU0FBUyxvQkFBb0I7QUFDalgsT0FBTyxXQUFXO0FBQ2xCLE9BQU8sVUFBVTtBQUNqQixTQUFTLHVCQUF1QjtBQUhoQyxJQUFNLG1DQUFtQztBQU16QyxJQUFPLHNCQUFRLGFBQWEsQ0FBQyxFQUFFLEtBQUssT0FBTztBQUFBLEVBQ3pDLFFBQVE7QUFBQSxJQUNOLE1BQU07QUFBQSxJQUNOLE1BQU07QUFBQTtBQUFBLElBRU4sSUFBSTtBQUFBLE1BQ0YsUUFBUTtBQUFBLElBQ1Y7QUFBQSxFQUNGO0FBQUEsRUFDQSxTQUFTO0FBQUEsSUFDUCxNQUFNO0FBQUEsSUFDTixTQUFTLGlCQUFpQixnQkFBZ0I7QUFBQTtBQUFBLElBRTFDO0FBQUEsTUFDRSxNQUFNO0FBQUEsTUFDTixnQkFBZ0IsUUFBNkY7QUFDM0csZUFBTyxZQUFZLElBQUksQ0FBQyxLQUFLLEtBQUssU0FBUztBQUN6QyxjQUNFLElBQUksT0FDSixDQUFDLElBQUksSUFBSSxTQUFTLEdBQUc7QUFBQSxVQUNyQixDQUFDLElBQUksSUFBSSxXQUFXLElBQUksR0FDeEI7QUFDQSxnQkFBSSxNQUFNO0FBQUEsVUFDWjtBQUNBLGVBQUs7QUFBQSxRQUNQLENBQUM7QUFBQSxNQUNIO0FBQUEsSUFDRjtBQUFBLEVBQ0YsRUFBRSxPQUFPLE9BQU87QUFBQSxFQUNoQixTQUFTO0FBQUEsSUFDUCxPQUFPO0FBQUEsTUFDTCxLQUFLLEtBQUssUUFBUSxrQ0FBVyxPQUFPO0FBQUEsSUFDdEM7QUFBQSxFQUNGO0FBQ0YsRUFBRTsiLAogICJuYW1lcyI6IFtdCn0K
