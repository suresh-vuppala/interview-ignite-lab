import os
import json

def check_lesson(base_path, section_path, lesson_slug, lesson_title):
    """Check if lesson files exist and have content"""
    lesson_path = os.path.join(base_path, section_path, lesson_slug)
    
    results = {
        'title': lesson_title,
        'path': lesson_path,
        'md': False,
        'json': False,
        'java': False,
        'cpp': False,
        'python': False,
        'issues': []
    }
    
    # Check markdown
    md_file = os.path.join(lesson_path, f"{lesson_slug}.md")
    if os.path.exists(md_file):
        with open(md_file, 'r', encoding='utf-8') as f:
            content = f.read()
            if len(content) > 50 and '## Code' in content:
                results['md'] = True
            else:
                results['issues'].append('MD file too short or missing ## Code')
    else:
        results['issues'].append('MD file missing')
    
    # Check JSON
    json_file = os.path.join(lesson_path, f"{lesson_slug}.json")
    if os.path.exists(json_file):
        with open(json_file, 'r', encoding='utf-8') as f:
            data = json.load(f)
            if data.get('isPosted') == True:
                results['json'] = True
            else:
                results['issues'].append('JSON missing isPosted: true')
    else:
        results['issues'].append('JSON file missing')
    
    # Check code files
    code_path = os.path.join(lesson_path, 'code')
    
    java_file = os.path.join(code_path, 'java', f"{''.join(word.capitalize() for word in lesson_slug.split('-'))}.java")
    if os.path.exists(java_file):
        with open(java_file, 'r') as f:
            if len(f.read()) > 50:
                results['java'] = True
            else:
                results['issues'].append('Java file too short')
    else:
        results['issues'].append(f'Java file missing: {java_file}')
    
    cpp_file = os.path.join(code_path, 'cpp', f"{''.join(word.capitalize() for word in lesson_slug.split('-'))}.cpp")
    if os.path.exists(cpp_file):
        with open(cpp_file, 'r') as f:
            if len(f.read()) > 50:
                results['cpp'] = True
            else:
                results['issues'].append('C++ file too short')
    else:
        results['issues'].append(f'C++ file missing: {cpp_file}')
    
    python_file = os.path.join(code_path, 'python', f"{lesson_slug}.py")
    if os.path.exists(python_file):
        with open(python_file, 'r') as f:
            if len(f.read()) > 30:
                results['python'] = True
            else:
                results['issues'].append('Python file too short')
    else:
        results['issues'].append(f'Python file missing: {python_file}')
    
    return results

base = 'src/data/courses/dsa'

print("=" * 80)
print("COMPREHENSIVE VERIFICATION - ALL NEW LESSONS")
print("=" * 80)

# Quick Sort lessons
print("\n1. QUICK SORT MODULE")
print("-" * 80)
quick_sort_lessons = [
    ('sorting-algorithms/quick-sort', 'quick-sort', 'Quick Sort'),
    ('sorting-algorithms/quick-sort', 'kth-smallest-element', 'Kth Smallest Element'),
    ('sorting-algorithms/quick-sort', 'kth-largest-element', 'Kth Largest Element')
]

for section, slug, title in quick_sort_lessons:
    result = check_lesson(base, section, slug, title)
    status = "✓" if all([result['md'], result['json'], result['java'], result['cpp'], result['python']]) else "✗"
    print(f"\n{status} {result['title']}")
    print(f"   MD: {'✓' if result['md'] else '✗'}  JSON: {'✓' if result['json'] else '✗'}  "
          f"Java: {'✓' if result['java'] else '✗'}  C++: {'✓' if result['cpp'] else '✗'}  "
          f"Python: {'✓' if result['python'] else '✗'}")
    if result['issues']:
        for issue in result['issues']:
            print(f"   ⚠ {issue}")

# Greedy lessons
print("\n\n2. GREEDY ALGORITHMS MODULE")
print("-" * 80)
greedy_lessons = [
    ('greedy/introduction', 'greedy-vs-dp', 'Greedy vs DP'),
    ('greedy/interval-based', 'activity-selection', 'Activity Selection'),
    ('greedy/interval-based', 'non-overlapping-intervals', 'Non-overlapping Intervals'),
    ('greedy/interval-based', 'merge-intervals', 'Merge Intervals'),
    ('greedy/interval-based', 'meeting-rooms-ii', 'Meeting Rooms II'),
    ('greedy/scheduling-allocation', 'job-sequencing', 'Job Sequencing'),
    ('greedy/scheduling-allocation', 'task-scheduler', 'Task Scheduler'),
    ('greedy/scheduling-allocation', 'gas-station', 'Gas Station'),
    ('greedy/others', 'jump-game', 'Jump Game'),
    ('greedy/others', 'jump-game-ii', 'Jump Game II'),
    ('greedy/others', 'remove-k-digits', 'Remove K Digits')
]

for section, slug, title in greedy_lessons:
    result = check_lesson(base, section, slug, title)
    status = "✓" if all([result['md'], result['json'], result['java'], result['cpp'], result['python']]) else "✗"
    print(f"\n{status} {result['title']}")
    print(f"   MD: {'✓' if result['md'] else '✗'}  JSON: {'✓' if result['json'] else '✗'}  "
          f"Java: {'✓' if result['java'] else '✗'}  C++: {'✓' if result['cpp'] else '✗'}  "
          f"Python: {'✓' if result['python'] else '✗'}")
    if result['issues']:
        for issue in result['issues']:
            print(f"   ⚠ {issue}")

# Miscellaneous lessons
print("\n\n3. MISCELLANEOUS MODULE")
print("-" * 80)
misc_lessons = [
    ('miscellaneous/design-problems', 'design-twitter', 'Design Twitter')
]

for section, slug, title in misc_lessons:
    result = check_lesson(base, section, slug, title)
    status = "✓" if all([result['md'], result['json'], result['java'], result['cpp'], result['python']]) else "✗"
    print(f"\n{status} {result['title']}")
    print(f"   MD: {'✓' if result['md'] else '✗'}  JSON: {'✓' if result['json'] else '✗'}  "
          f"Java: {'✓' if result['java'] else '✗'}  C++: {'✓' if result['cpp'] else '✗'}  "
          f"Python: {'✓' if result['python'] else '✗'}")
    if result['issues']:
        for issue in result['issues']:
            print(f"   ⚠ {issue}")

print("\n" + "=" * 80)
print("VERIFICATION COMPLETE")
print("=" * 80)
