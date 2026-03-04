import os
import json

def check_lesson(base_path, section_path, lesson_slug, lesson_title):
    lesson_path = os.path.join(base_path, section_path, lesson_slug)
    
    results = {
        'title': lesson_title,
        'md': False,
        'json': False,
        'java': False,
        'cpp': False,
        'python': False
    }
    
    md_file = os.path.join(lesson_path, f"{lesson_slug}.md")
    if os.path.exists(md_file):
        with open(md_file, 'r', encoding='utf-8') as f:
            content = f.read()
            if len(content) > 50 and '## Code' in content:
                results['md'] = True
    
    json_file = os.path.join(lesson_path, f"{lesson_slug}.json")
    if os.path.exists(json_file):
        with open(json_file, 'r', encoding='utf-8') as f:
            data = json.load(f)
            if data.get('isPosted') == True:
                results['json'] = True
    
    code_path = os.path.join(lesson_path, 'code')
    
    java_file = os.path.join(code_path, 'java', f"{''.join(word.capitalize() for word in lesson_slug.split('-'))}.java")
    if os.path.exists(java_file):
        with open(java_file, 'r') as f:
            if len(f.read()) > 50:
                results['java'] = True
    
    cpp_file = os.path.join(code_path, 'cpp', f"{''.join(word.capitalize() for word in lesson_slug.split('-'))}.cpp")
    if os.path.exists(cpp_file):
        with open(cpp_file, 'r') as f:
            if len(f.read()) > 50:
                results['cpp'] = True
    
    python_file = os.path.join(code_path, 'python', f"{lesson_slug}.py")
    if os.path.exists(python_file):
        with open(python_file, 'r') as f:
            if len(f.read()) > 30:
                results['python'] = True
    
    return results

base = 'src/data/courses/dsa'

print("=" * 80)
print("COMPREHENSIVE VERIFICATION - ALL NEW LESSONS")
print("=" * 80)

all_lessons = [
    ('Quick Sort', 'sorting-algorithms/quick-sort', 'quick-sort'),
    ('Kth Smallest', 'sorting-algorithms/quick-sort', 'kth-smallest-element'),
    ('Kth Largest', 'sorting-algorithms/quick-sort', 'kth-largest-element'),
    ('Greedy vs DP', 'greedy/introduction', 'greedy-vs-dp'),
    ('Activity Selection', 'greedy/interval-based', 'activity-selection'),
    ('Non-overlapping Intervals', 'greedy/interval-based', 'non-overlapping-intervals'),
    ('Merge Intervals', 'greedy/interval-based', 'merge-intervals'),
    ('Meeting Rooms II', 'greedy/interval-based', 'meeting-rooms-ii'),
    ('Job Sequencing', 'greedy/scheduling-allocation', 'job-sequencing'),
    ('Task Scheduler', 'greedy/scheduling-allocation', 'task-scheduler'),
    ('Gas Station', 'greedy/scheduling-allocation', 'gas-station'),
    ('Jump Game', 'greedy/others', 'jump-game'),
    ('Jump Game II', 'greedy/others', 'jump-game-ii'),
    ('Remove K Digits', 'greedy/others', 'remove-k-digits'),
    ('Design Twitter', 'miscellaneous/design-problems', 'design-twitter')
]

total = len(all_lessons)
passed = 0

for title, section, slug in all_lessons:
    result = check_lesson(base, section, slug, title)
    all_ok = all([result['md'], result['json'], result['java'], result['cpp'], result['python']])
    
    if all_ok:
        passed += 1
        print(f"\n[OK] {title}")
    else:
        print(f"\n[FAIL] {title}")
        print(f"  MD:{result['md']} JSON:{result['json']} Java:{result['java']} C++:{result['cpp']} Py:{result['python']}")

print("\n" + "=" * 80)
print(f"RESULT: {passed}/{total} lessons verified successfully")
print("=" * 80)
