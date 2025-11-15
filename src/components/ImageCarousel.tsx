'use client';

import { useState, useEffect, useCallback } from 'react';
import { ChevronLeft, ChevronRight, Play, Pause } from 'lucide-react';

interface MetadataItem {
  image?: string;
  title?: string;
  description?: string;
}

interface CarouselItem {
  image: string;
  title?: string;
  description?: string;
}

interface ImageCarouselProps {
  folder: string;               // "/Image/FibonacciSolution"
  jsonData?: MetadataItem[];    // array of metadata with image filenames
}

const ImageCarousel: React.FC<ImageCarouselProps> = ({ folder, jsonData = [] }) => {
  const [currentIndex, setCurrentIndex] = useState(0);
  const [isPlaying, setIsPlaying] = useState(false);
  const [imageData, setImageData] = useState<CarouselItem[]>([]);

  // -----------------------------
  // Build image list from jsonData ONLY
  // -----------------------------
  useEffect(() => {
    const cleanFolder = folder.endsWith('/') ? folder.slice(0, -1) : folder;

    const processed = jsonData
      .filter((m) => m.image)         // ignore entries without images
      .map((meta) => ({
        image: `${cleanFolder}/${meta.image}`,
        title: meta.title,
        description: meta.description
      }));

    setImageData(processed);
    setCurrentIndex(0);
  }, [folder, jsonData]);

  // -----------------------------
  // Navigation handlers
  // -----------------------------
  const nextSlide = useCallback(() => {
    setCurrentIndex((prev) =>
      imageData.length ? (prev + 1) % imageData.length : 0
    );
  }, [imageData.length]);

  const prevSlide = useCallback(() => {
    setCurrentIndex((prev) =>
      imageData.length ? (prev - 1 + imageData.length) % imageData.length : 0
    );
  }, [imageData.length]);

  const goToSlide = (i: number) => setCurrentIndex(i);

  // -----------------------------
  // Auto-play
  // -----------------------------
  useEffect(() => {
    if (!isPlaying || imageData.length <= 1) return;
    const timer = window.setInterval(nextSlide, 2000);
    return () => window.clearInterval(timer);
  }, [isPlaying, imageData.length, nextSlide]);

  // -----------------------------
  // Description parser
  // -----------------------------
  const renderDescription = (description?: string) => {
    if (!description) return null;

    const lines = description.split('\n');

    return lines.map((line, idx) => {
      const trimmed = line.trim();
      if (!trimmed) return <br key={idx} />;

      // Indentation
      const indentMatch = line.match(/^(\s+)/);
      const indentLevel = indentMatch ? Math.floor(indentMatch[1].length / 2) : 0;

      // Bold tags
      const processBold = (text: string) => {
        const parts = text.split(/(<b>.*?<\/b>)/g);
        return parts.map((p, i) => {
          if (p.startsWith('<b>') && p.endsWith('</b>')) {
            return (
              <b key={i} className="font-semibold text-pink-600 dark:text-pink-400">
                {p.slice(3, -4)}
              </b>
            );
          }
          return p;
        });
      };

      return (
        <p
          key={idx}
          className={`text-gray-700 dark:text-gray-300 text-sm ${indentLevel > 0 ? `ml-${indentLevel * 4}` : ''} ${
            idx > 0 ? 'mt-2' : ''
          }`}
        >
          {processBold(trimmed)}
        </p>
      );
    });
  };

  // -----------------------------
  if (imageData.length === 0) return null;

  const current = imageData[currentIndex];
  const hasTitleOrDescription = current.title || current.description;

  return (
    <div className="my-4 rounded-lg border border-pink-300 dark:border-pink-600 shadow-sm overflow-hidden bg-white dark:bg-gray-900">
      {/* IMAGE */}
      <div className="relative aspect-video flex items-center justify-center p-2 bg-gray-50 dark:bg-gray-800">
        <img
          src={current.image}
          alt={current.title ?? `Slide ${currentIndex + 1}`}
          className="max-w-full max-h-full object-contain transition-all duration-500 rounded"
        />

        {imageData.length > 1 && (
          <>
            <button
              onClick={prevSlide}
              className="absolute left-3 top-1/2 -translate-y-1/2 bg-pink-600/90 hover:bg-pink-700 text-white p-2 rounded-full shadow-lg"
            >
              <ChevronLeft className="w-4 h-4" />
            </button>

            <button
              onClick={nextSlide}
              className="absolute right-3 top-1/2 -translate-y-1/2 bg-pink-600/90 hover:bg-pink-700 text-white p-2 rounded-full shadow-lg"
            >
              <ChevronRight className="w-4 h-4" />
            </button>
          </>
        )}
      </div>

      {/* TITLE + DESCRIPTION */}
      {hasTitleOrDescription && (
        <div className="p-3 border-t border-pink-200 dark:border-pink-700">
          {current.title && (
            <h4 className="font-semibold text-base mb-2 text-gray-900 dark:text-gray-100">
              {current.title}
            </h4>
          )}
          {current.description && renderDescription(current.description)}
        </div>
      )}

      {/* CONTROLS */}
      {imageData.length > 1 && (
        <div
          className={`flex items-center justify-center p-2 border-t border-pink-200 dark:border-pink-700 ${
            hasTitleOrDescription ? 'bg-white dark:bg-gray-900' : 'bg-gray-50 dark:bg-gray-800'
          } gap-4`}
        >
          {/* Dot indicators */}
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
              />
            ))}
          </div>

          {/* Play/pause */}
          <button
            onClick={() => setIsPlaying((p) => !p)}
            className="flex items-center gap-1.5 px-3 py-1.5 text-xs border border-pink-300 dark:border-pink-600 rounded-md hover:bg-pink-50 dark:hover:bg-pink-900/30 text-pink-700 dark:text-pink-300"
          >
            {isPlaying ? <Pause className="w-3.5 h-3.5" /> : <Play className="w-3.5 h-3.5" />}
          </button>
        </div>
      )}
    </div>
  );
};

export default ImageCarousel;
