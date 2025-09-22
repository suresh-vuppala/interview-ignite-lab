import { useState, useEffect } from 'react';
import { useParams, Link } from 'react-router-dom';
import { Layout } from '@/components/Layout';
import { Button } from '@/components/ui/button';
import { Progress } from '@/components/ui/progress';
import { Badge } from '@/components/ui/badge';
import { Separator } from '@/components/ui/separator';
import { 
  ChevronLeft, 
  ChevronRight, 
  Clock, 
  BookOpen, 
  Lock,
  Crown,
  CheckCircle,
  Play,
  Code
} from 'lucide-react';
import { useAuth } from '@/hooks/useAuth';
import { Card, CardContent } from '@/components/ui/card';
import { CodeBlock } from '@/components/CodeBlock';

// Mock lesson data - in real app this would come from Supabase
const lessonData: Record<string, any> = {
  'getting-started-overview': {
    title: 'Course Overview',
    course: 'Getting Started',
    duration: 15,
    isPremium: false,
    content: `
# Welcome to Interview60!

This comprehensive course will guide you through the most important concepts needed to ace your coding interviews at top tech companies.

## What You'll Learn

- **Fundamental patterns** that solve 80% of coding problems
- **System design principles** for scalable applications  
- **Behavioral interview strategies** to showcase your experience
- **Time management techniques** for interview success

## Course Structure

The course is divided into several key modules:

1. **Foundations** - Core concepts and setup
2. **Data Structures** - Arrays, trees, graphs, and more
3. **Algorithms** - Sorting, searching, and optimization
4. **System Design** - Building scalable systems
5. **Behavioral** - Soft skills and leadership

## Getting Started

Start with the fundamentals and work your way through each module systematically. Each lesson builds upon the previous ones, so it's important to follow the recommended order.

> **💡 Pro Tip:** Practice coding along with the examples. The best way to learn is by doing!

## Prerequisites

- Basic programming knowledge in any language
- Understanding of fundamental CS concepts
- Willingness to practice regularly

Let's begin your journey to interview success!
    `,
    codeExamples: []
  },
  'data-structures-arrays': {
    title: 'Arrays & Strings',
    course: 'Data Structures',
    duration: 25,
    isPremium: false,
    content: `
# Arrays & Strings

Arrays and strings are the most fundamental data structures you'll encounter in coding interviews. Mastering these is essential for success.

## Key Concepts

### Arrays
- **Contiguous memory** allocation
- **O(1) access** by index
- **Dynamic vs static** sizing
- **Common operations** and their complexity

### Strings
- **Immutable** in most languages
- **Character arrays** under the hood
- **Unicode considerations**
- **Common string algorithms**

## Essential Patterns

### 1. Two Pointers
Perfect for problems involving pairs or searching in sorted arrays.

### 2. Sliding Window
Ideal for subarray problems with constraints.

### 3. Prefix Sum
Efficient for range sum queries.

## Practice Problems

1. Two Sum
2. Valid Palindrome
3. Longest Substring Without Repeating Characters
4. Maximum Subarray

## Implementation Tips

- Always check for edge cases (empty arrays, null inputs)
- Consider time and space complexity
- Think about in-place operations when possible
    `,
    codeExamples: [
      {
        title: 'Two Pointers Example',
        language: 'python',
        code: `def two_sum(nums, target):
    """
    Find two numbers that add up to target.
    Time: O(n), Space: O(1) if sorted
    """
    left, right = 0, len(nums) - 1
    
    while left < right:
        current_sum = nums[left] + nums[right]
        
        if current_sum == target:
            return [left, right]
        elif current_sum < target:
            left += 1
        else:
            right -= 1
    
    return []`
      }
    ]
  },
  'algorithms-two-pointers': {
    title: 'Two Pointers Pattern',
    course: 'Algorithms',
    duration: 30,
    isPremium: false,
    content: `
# Two Pointers Pattern

The two pointers technique is one of the most powerful patterns for solving array and string problems efficiently.

## When to Use

- Finding pairs with a specific sum
- Removing duplicates from sorted arrays
- Reversing arrays or strings
- Checking palindromes
- Merging sorted arrays

## Pattern Variations

### 1. Opposite Direction
Pointers start at opposite ends and move toward each other.

### 2. Same Direction
Both pointers start at the beginning, moving at different speeds.

### 3. Sliding Window
A special case where pointers maintain a window of elements.

## Time Complexity
- **Time:** O(n) - single pass through the array
- **Space:** O(1) - only using two pointers

## Common Mistakes
- Not handling edge cases (empty arrays, single elements)
- Off-by-one errors with indices
- Not considering duplicate elements
- Forgetting to update both pointers appropriately
    `,
    codeExamples: [
      {
        title: 'Valid Palindrome',
        language: 'python',
        code: `def is_palindrome(s):
    """
    Check if string is a palindrome (ignoring non-alphanumeric)
    """
    left, right = 0, len(s) - 1
    
    while left < right:
        # Skip non-alphanumeric from left
        while left < right and not s[left].isalnum():
            left += 1
        
        # Skip non-alphanumeric from right  
        while left < right and not s[right].isalnum():
            right -= 1
        
        # Compare characters
        if s[left].lower() != s[right].lower():
            return False
        
        left += 1
        right -= 1
    
    return True`
      },
      {
        title: 'Three Sum',
        language: 'python',
        code: `def three_sum(nums):
    """
    Find all unique triplets that sum to zero
    """
    nums.sort()
    result = []
    
    for i in range(len(nums) - 2):
        # Skip duplicates
        if i > 0 and nums[i] == nums[i-1]:
            continue
        
        left, right = i + 1, len(nums) - 1
        
        while left < right:
            total = nums[i] + nums[left] + nums[right]
            
            if total == 0:
                result.append([nums[i], nums[left], nums[right]])
                
                # Skip duplicates
                while left < right and nums[left] == nums[left+1]:
                    left += 1
                while left < right and nums[right] == nums[right-1]:
                    right -= 1
                
                left += 1
                right -= 1
            elif total < 0:
                left += 1
            else:
                right -= 1
    
    return result`
      }
    ]
  },
  'system-design-fundamentals': {
    title: 'System Design Fundamentals',
    course: 'System Design',
    duration: 45,
    isPremium: false,
    content: `
# System Design Fundamentals

System design interviews test your ability to design large-scale distributed systems. This lesson covers the fundamental concepts you need to know.

## Key Principles

### 1. Scalability
- **Horizontal vs Vertical scaling**
- **Load balancing strategies**
- **Auto-scaling mechanisms**

### 2. Reliability
- **Fault tolerance**
- **Redundancy and replication**
- **Circuit breakers**

### 3. Availability
- **Uptime requirements (99.9% vs 99.99%)**
- **Failover mechanisms**
- **Disaster recovery**

### 4. Consistency
- **ACID properties**
- **CAP theorem**
- **Eventual consistency**

## Common Components

### Load Balancers
Distribute incoming requests across multiple servers.

### Databases
- **SQL vs NoSQL**
- **Sharding strategies**
- **Read replicas**

### Caching
- **In-memory caches (Redis, Memcached)**
- **CDNs for static content**
- **Application-level caching**

### Message Queues
- **Asynchronous processing**
- **Pub/Sub patterns**
- **Message ordering and delivery guarantees**

## Design Process

1. **Clarify requirements** (functional and non-functional)
2. **Estimate scale** (users, data, requests)
3. **High-level design** (major components)
4. **Detailed design** (APIs, schemas, algorithms)
5. **Scale the design** (bottlenecks and solutions)

## Example: Design a URL Shortener

Let's walk through designing a system like bit.ly or tinyurl.
    `,
    codeExamples: [
      {
        title: 'URL Encoding Algorithm',
        language: 'python',
        code: `import hashlib
import base64

def encode_url(long_url, counter):
    """
    Encode a long URL into a short URL
    """
    # Option 1: Use counter-based encoding
    def base62_encode(num):
        alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
        if num == 0:
            return alphabet[0]
        
        result = ""
        while num > 0:
            result = alphabet[num % 62] + result
            num //= 62
        return result
    
    short_code = base62_encode(counter)
    return f"https://short.ly/{short_code}"

# Option 2: Hash-based approach
def hash_encode_url(long_url):
    """
    Use MD5 hash for encoding (with collision handling)
    """
    hash_object = hashlib.md5(long_url.encode())
    hex_dig = hash_object.hexdigest()
    
    # Take first 7 characters for short URL
    short_code = hex_dig[:7]
    return f"https://short.ly/{short_code}"`
      }
    ]
  }
};

export default function LessonPage() {
  const { courseSlug, lessonSlug } = useParams();
  const { user } = useAuth();
  const [lesson, setLesson] = useState<any>(null);
  const [progress, setProgress] = useState(0);

  useEffect(() => {
    // Simulate loading lesson data
    const lessonKey = `${courseSlug}-${lessonSlug}`;
    const lessonData = getLessonData(lessonKey);
    setLesson(lessonData);
    
    // Simulate progress
    const timer = setTimeout(() => setProgress(75), 1000);
    return () => clearTimeout(timer);
  }, [courseSlug, lessonSlug]);

  const getLessonData = (key: string) => {
    return lessonData[key] || {
      title: 'Lesson Not Found',
      course: 'Unknown',
      duration: 0,
      isPremium: false,
      content: 'This lesson is not available.',
      codeExamples: []
    };
  };

  const hasAccess = (isPremium: boolean) => {
    return !isPremium || user !== null;
  };

  if (!lesson) {
    return (
      <Layout>
        <div className="flex items-center justify-center h-64">
          <div className="text-center">
            <div className="animate-spin rounded-full h-8 w-8 border-b-2 border-primary mx-auto"></div>
            <p className="mt-2 text-muted-foreground">Loading lesson...</p>
          </div>
        </div>
      </Layout>
    );
  }

  if (lesson.isPremium && !hasAccess(lesson.isPremium)) {
    return (
      <Layout>
        <div className="max-w-4xl mx-auto p-6">
          <Card className="text-center p-8">
            <CardContent className="space-y-4">
              <Lock className="w-16 h-16 text-muted-foreground mx-auto" />
              <h2 className="text-2xl font-bold">Premium Content</h2>
              <p className="text-muted-foreground">
                This lesson is part of our premium content. Upgrade to access advanced topics and exclusive materials.
              </p>
              <Button className="mt-4" asChild>
                <Link to="/upgrade">
                  <Crown className="w-4 h-4 mr-2" />
                  Upgrade to Pro
                </Link>
              </Button>
            </CardContent>
          </Card>
        </div>
      </Layout>
    );
  }

  return (
    <Layout>
      <div className="max-w-6xl mx-auto">
        <div className="grid lg:grid-cols-4 gap-6">
          {/* Main Content */}
          <div className="lg:col-span-3 p-6">
            {/* Header */}
            <div className="mb-6">
              <div className="flex items-center gap-2 text-sm text-muted-foreground mb-2">
                <Link to="/dashboard" className="hover:text-foreground">Dashboard</Link>
                <ChevronRight className="w-4 h-4" />
                <span>{lesson.course}</span>
                <ChevronRight className="w-4 h-4" />
                <span>{lesson.title}</span>
              </div>
              
              <div className="flex items-center justify-between mb-4">
                <div>
                  <h1 className="text-3xl font-bold mb-2">{lesson.title}</h1>
                  <div className="flex items-center gap-4 text-sm text-muted-foreground">
                    <div className="flex items-center gap-1">
                      <Clock className="w-4 h-4" />
                      {lesson.duration} min
                    </div>
                    <div className="flex items-center gap-1">
                      <BookOpen className="w-4 h-4" />
                      {lesson.course}
                    </div>
                    {lesson.isPremium && (
                      <Badge variant="secondary">
                        <Crown className="w-3 h-3 mr-1" />
                        PRO
                      </Badge>
                    )}
                  </div>
                </div>
                
                <div className="flex items-center gap-2">
                  <Button variant="outline" size="sm">
                    <ChevronLeft className="w-4 h-4 mr-1" />
                    Previous
                  </Button>
                  <Button size="sm">
                    Next
                    <ChevronRight className="w-4 h-4 ml-1" />
                  </Button>
                </div>
              </div>
              
              <div className="space-y-2">
                <div className="flex justify-between text-sm">
                  <span>Progress</span>
                  <span>{progress}%</span>
                </div>
                <Progress value={progress} className="h-2" />
              </div>
            </div>

            {/* Content */}
            <div className="prose prose-slate max-w-none dark:prose-invert">
              <div className="whitespace-pre-wrap leading-relaxed">
                {lesson.content}
              </div>
            </div>

            {/* Code Examples */}
            {lesson.codeExamples && lesson.codeExamples.length > 0 && (
              <div className="mt-8 space-y-6">
                <Separator />
                <h2 className="text-xl font-semibold flex items-center gap-2">
                  <Code className="w-5 h-5" />
                  Code Examples
                </h2>
                
                {lesson.codeExamples.map((example: any, index: number) => (
                  <CodeBlock
                    key={index}
                    title={example.title}
                    code={example.code}
                    language={example.language}
                    showLanguageSelector={true}
                  />
                ))}
              </div>
            )}

            {/* Navigation */}
            <div className="flex justify-between items-center mt-8 pt-6 border-t">
              <Button variant="outline">
                <ChevronLeft className="w-4 h-4 mr-2" />
                Previous Lesson
              </Button>
              
              <Button>
                <CheckCircle className="w-4 h-4 mr-2" />
                Mark Complete
              </Button>
              
              <Button variant="outline">
                Next Lesson
                <ChevronRight className="w-4 h-4 ml-2" />
              </Button>
            </div>
          </div>

          {/* Sidebar */}
          <div className="lg:col-span-1 p-6 space-y-6">
            {/* Course Progress */}
            <Card>
              <CardContent className="p-4">
                <h3 className="font-semibold mb-3">Course Progress</h3>
                <div className="space-y-2">
                  <div className="flex justify-between text-sm">
                    <span>Completed</span>
                    <span>3/8 lessons</span>
                  </div>
                  <Progress value={38} />
                  <p className="text-xs text-muted-foreground">
                    Keep going! You're making great progress.
                  </p>
                </div>
              </CardContent>
            </Card>

            {/* Related Lessons */}
            <Card>
              <CardContent className="p-4">
                <h3 className="font-semibold mb-3">Up Next</h3>
                <div className="space-y-3">
                  <div className="flex items-center gap-3 p-2 rounded hover:bg-accent cursor-pointer">
                    <Play className="w-4 h-4 text-muted-foreground" />
                    <div className="flex-1 min-w-0">
                      <p className="text-sm font-medium truncate">Sliding Window Pattern</p>
                      <p className="text-xs text-muted-foreground">20 min</p>
                    </div>
                  </div>
                  
                  <div className="flex items-center gap-3 p-2 rounded hover:bg-accent cursor-pointer">
                    <Lock className="w-4 h-4 text-yellow-500" />
                    <div className="flex-1 min-w-0">
                      <p className="text-sm font-medium truncate">Dynamic Programming</p>
                      <p className="text-xs text-muted-foreground">35 min • PRO</p>
                    </div>
                  </div>
                  
                  <div className="flex items-center gap-3 p-2 rounded hover:bg-accent cursor-pointer">
                    <Play className="w-4 h-4 text-muted-foreground" />
                    <div className="flex-1 min-w-0">
                      <p className="text-sm font-medium truncate">Binary Search</p>
                      <p className="text-xs text-muted-foreground">25 min</p>
                    </div>
                  </div>
                </div>
              </CardContent>
            </Card>

            {/* Study Tips */}
            <Card>
              <CardContent className="p-4">
                <h3 className="font-semibold mb-3">💡 Study Tips</h3>
                <ul className="text-sm space-y-2 text-muted-foreground">
                  <li>• Practice coding along with examples</li>
                  <li>• Take notes on key patterns</li>
                  <li>• Solve related problems</li>
                  <li>• Review previous lessons</li>
                </ul>
              </CardContent>
            </Card>
          </div>
        </div>
      </div>
    </Layout>
  );
}