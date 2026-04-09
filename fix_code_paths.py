import os
import json

lessons_to_fix = [
    ('sorting-algorithms/quick-sort', 'quick-sort'),
    ('sorting-algorithms/quick-sort/kth-smallest-element', 'kth-smallest-element'),
    ('sorting-algorithms/quick-sort/kth-largest-element', 'kth-largest-element'),
    ('greedy/introduction/greedy-vs-dp', 'greedy-vs-dp'),
    ('greedy/interval-based/activity-selection', 'activity-selection'),
    ('greedy/interval-based/non-overlapping-intervals', 'non-overlapping-intervals'),
    ('greedy/interval-based/merge-intervals', 'merge-intervals'),
    ('greedy/interval-based/meeting-rooms-ii', 'meeting-rooms-ii'),
    ('greedy/scheduling-allocation/job-sequencing', 'job-sequencing'),
    ('greedy/scheduling-allocation/task-scheduler', 'task-scheduler'),
    ('greedy/scheduling-allocation/gas-station', 'gas-station'),
    ('greedy/others/jump-game', 'jump-game'),
    ('greedy/others/jump-game-ii', 'jump-game-ii'),
    ('greedy/others/remove-k-digits', 'remove-k-digits'),
    ('miscellaneous/design-problems/design-twitter', 'design-twitter'),
]

base_path = 'src/data/courses/dsa'

for lesson_path, slug in lessons_to_fix:
    json_file = os.path.join(base_path, lesson_path, f'{slug}.json')
    
    if os.path.exists(json_file):
        with open(json_file, 'r', encoding='utf-8') as f:
            data = json.load(f)
        
        # Fix codeFile paths to be relative with ./
        if 'codeExamples' in data:
            for example in data['codeExamples']:
                for lang in example['languages']:
                    if 'codeFile' in lang and not lang['codeFile'].startswith('./'):
                        lang['codeFile'] = './' + lang['codeFile']
        
        with open(json_file, 'w', encoding='utf-8') as f:
            json.dump(data, f, indent=4)
        
        print(f"Fixed: {slug}")
    else:
        print(f"NOT FOUND: {json_file}")

print(f"\nTotal fixed: {len(lessons_to_fix)} lessons")
