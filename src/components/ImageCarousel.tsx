'use client';

import { useState, useEffect, useCallback } from 'react';
import { ChevronLeft, ChevronRight, Play, Pause } from 'lucide-react';

interface CarouselItem {
  image: string;           // full URL to image (required for rendering)
  title?: string;
  description?: string;
}

interface MetadataItem {
  image?: string;          // optional in JSON metadata
  title?: string;
  description?: string;
}

interface ImageCarouselProps {
  folder: string;               // e.g. "/Image/FibonacciSolution"
  images: string[];             // e.g. ["1.jpg", "2.jpg", "3.jpg"]
  jsonData?: MetadataItem[];    // optional metadata array loaded from JSON
}

const ImageCarousel: React.FC<ImageCarouselProps> = ({ folder, images, jsonData = [] }) => {
  const [currentIndex, setCurrentIndex] = useState(0);
  const [isPlaying, setIsPlaying] = useState(false);
  const [imageData, setImageData] = useState<CarouselItem[]>([]);

  // Map image filenames to full URLs and merge with metadata
  useEffect(() => {
    const cleanFolder = folder.endsWith('/') ? folder.slice(0, -1) : folder;
    const processed: CarouselItem[] = images.map((imgFile, i) => {
      const meta: MetadataItem = jsonData[i] ?? {};
      // Use metadata.image if present (relative filename), otherwise use the images array entry
      const filename = meta.image ?? imgFile;
      return {
        image: `${cleanFolder}/${filename}`,
        title: meta.title,
        description: meta.description,
      };
    });

    setImageData(processed);
    // reset index if out of bounds
    setCurrentIndex((prev) => (processed.length === 0 ? 0 : Math.min(prev, processed.length - 1)));
  }, [folder, images, jsonData]);

  // Handlers
  const nextSlide = useCallback(() => {
    setCurrentIndex((prev) => (imageData.length ? (prev + 1) % imageData.length : 0));
  }, [imageData.length]);

  const prevSlide = useCallback(() => {
    setCurrentIndex((prev) => (imageData.length ? (prev - 1 + imageData.length) % imageData.length : 0));
  }, [imageData.length]);

  const goToSlide = (i: number) => setCurrentIndex(i);

  // Auto-play with increased speed (2000ms instead of 3000ms)
  useEffect(() => {
    if (!isPlaying || imageData.length <= 1) return;
    const timer = window.setInterval(nextSlide, 2000);
    return () => window.clearInterval(timer);
  }, [isPlaying, imageData.length, nextSlide]);

  // Function to render description with proper line breaks, indentation, and bold support
  const renderDescription = (description?: string) => {
    if (!description) return null;
    
    const lines = description.split('\n');
    
    return lines.map((line, lineIndex) => {
      const trimmedLine = line.trim();
      
      // Handle empty lines
      if (!trimmedLine) {
        return <br key={lineIndex} />;
      }
      
      // Handle indentation
      const indentMatch = line.match(/^(\s+)/);
      const indentLevel = indentMatch ? Math.floor(indentMatch[1].length / 2) : 0;
      
      // Process bold tags
      const processBoldTags = (text: string) => {
        const parts = text.split(/(<b>.*?<\/b>)/g);
        return parts.map((part, partIndex) => {
          if (part.startsWith('<b>') && part.endsWith('</b>')) {
            const boldText = part.slice(3, -4);
            return <b key={partIndex} className="font-semibold text-pink-600 dark:text-pink-400">{boldText}</b>;
          }
          return part;
        });
      };

      return (
        <p 
          key={lineIndex} 
          className={`text-gray-700 dark:text-gray-300 text-sm ${indentLevel > 0 ? `ml-${indentLevel * 4}` : ''} ${
            lineIndex > 0 ? 'mt-2' : ''
          }`}
        >
          {processBoldTags(trimmedLine)}
        </p>
      );
    });
  };

  if (imageData.length === 0) return null;

  const current = imageData[currentIndex];
  const hasTitleOrDescription = current.title || current.description;

  return (
    <div className="my-4 rounded-lg border border-pink-300 dark:border-pink-600 shadow-sm overflow-hidden bg-white dark:bg-gray-900">
      {/* Image Display */}
      <div className="relative aspect-video flex items-center justify-center p-2 bg-gray-50 dark:bg-gray-800">
        <img
          src={current.image}
          alt={current.title ?? `Image ${currentIndex + 1}`}
          className="max-w-full max-h-full object-contain transition-all duration-500 rounded"
        />

        {/* Nav */}
        {imageData.length > 1 && (
          <>
            <button
              onClick={prevSlide}
              className="absolute left-3 top-1/2 -translate-y-1/2 bg-pink-600/90 hover:bg-pink-700 text-white p-2 rounded-full transition shadow-lg"
            >
              <ChevronLeft className="w-4 h-4" />
            </button>
            <button
              onClick={nextSlide}
              className="absolute right-3 top-1/2 -translate-y-1/2 bg-pink-600/90 hover:bg-pink-700 text-white p-2 rounded-full transition shadow-lg"
            >
              <ChevronRight className="w-4 h-4" />
            </button>
          </>
        )}
      </div>

      {/* Title & Description - Only show if there's content */}
      {hasTitleOrDescription && (
        <div className="p-3 border-t border-pink-200 dark:border-pink-700 bg-white dark:bg-gray-900">
          {current.title && (
            <h4 className="font-semibold text-base mb-2 text-gray-900 dark:text-gray-100">{current.title}</h4>
          )}
          {current.description && (
            <div className="description-content">
              {renderDescription(current.description)}
            </div>
          )}
        </div>
      )}

      {/* Controls - Show only if multiple images */}
      {imageData.length > 1 && (
        <div className={`flex items-center justify-center p-2 border-t border-pink-200 dark:border-pink-700 ${
          hasTitleOrDescription ? 'bg-white dark:bg-gray-900' : 'bg-gray-50 dark:bg-gray-800'
        } gap-4`}>
          {/* Beautiful dashes for navigation */}
          <div className="flex gap-1.5">
            {imageData.map((_, i) => (
              <button
                key={i}
                onClick={() => goToSlide(i)}
                className={`h-1.5 rounded-full transition-all ${
                  i === currentIndex 
                    ? 'bg-pink-600 dark:bg-pink-500 w-6' 
                    : 'bg-pink-300 dark:bg-pink-700 hover:bg-pink-400 dark:hover:bg-pink-600 w-3'
                }`}
                aria-label={`Go to slide ${i + 1}`}
              />
            ))}
          </div>

          {/* Play/Pause button */}
          <button
            onClick={() => setIsPlaying((p) => !p)}
            className="flex items-center gap-1.5 px-3 py-1.5 text-xs border border-pink-300 dark:border-pink-600 rounded-md hover:bg-pink-50 dark:hover:bg-pink-900/30 transition text-pink-700 dark:text-pink-300"
          >
            {isPlaying ? (
              <>
                <Pause className="w-3.5 h-3.5" />
              </>
            ) : (
              <>
                <Play className="w-3.5 h-3.5" />
              </>
            )}
          </button>
        </div>
      )}
    </div>
  );
};

export default ImageCarousel;