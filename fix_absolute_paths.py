import os
import json

lessons_config = [
    ('sorting-algorithms/quick-sort', 'quick-sort', 'QuickSort', 'quick-sort'),
    ('sorting-algorithms/quick-sort/kth-smallest-element', 'kth-smallest-element', 'KthSmallestElement', 'kth-smallest-element'),
    ('sorting-algorithms/quick-sort/kth-largest-element', 'kth-largest-element', 'KthLargestElement', 'kth-largest-element'),
    ('greedy/introduction/greedy-vs-dp', 'greedy-vs-dp', 'GreedyVsDp', 'greedy-vs-dp'),
    ('greedy/interval-based/activity-selection', 'activity-selection', 'ActivitySelection', 'activity-selection'),
    ('greedy/interval-based/non-overlapping-intervals', 'non-overlapping-intervals', 'NonOverlappingIntervals', 'non-overlapping-intervals'),
    ('greedy/interval-based/merge-intervals', 'merge-intervals', 'MergeIntervals', 'merge-intervals'),
    ('greedy/interval-based/meeting-rooms-ii', 'meeting-rooms-ii', 'MeetingRoomsII', 'meeting-rooms-ii'),
    ('greedy/scheduling-allocation/job-sequencing', 'job-sequencing', 'JobSequencing', 'job-sequencing'),
    ('greedy/scheduling-allocation/task-scheduler', 'task-scheduler', 'TaskScheduler', 'task-scheduler'),
    ('greedy/scheduling-allocation/gas-station', 'gas-station', 'GasStation', 'gas-station'),
    ('greedy/others/jump-game', 'jump-game', 'JumpGame', 'jump-game'),
    ('greedy/others/jump-game-ii', 'jump-game-ii', 'JumpGameII', 'jump-game-ii'),
    ('greedy/others/remove-k-digits', 'remove-k-digits', 'RemoveKDigits', 'remove-k-digits'),
    ('miscellaneous/design-problems/design-twitter', 'design-twitter', 'Twitter', 'design-twitter'),
]

base_path = 'src/data/courses/dsa'

for lesson_path, slug, class_name, python_name in lessons_config:
    json_file = os.path.join(base_path, lesson_path, f'{slug}.json')
    
    if os.path.exists(json_file):
        with open(json_file, 'r', encoding='utf-8') as f:
            data = json.load(f)
        
        # Update codeFile paths to full absolute paths from /src
        full_path = f"/src/data/courses/dsa/{lesson_path}"
        
        data['codeExamples'] = [
            {
                "title": "Solution",
                "languages": [
                    {
                        "language": "java",
                        "codeFile": f"{full_path}/code/java/{class_name}.java"
                    },
                    {
                        "language": "cpp",
                        "codeFile": f"{full_path}/code/cpp/{class_name}.cpp"
                    },
                    {
                        "language": "python",
                        "codeFile": f"{full_path}/code/python/{python_name}.py"
                    }
                ]
            }
        ]
        
        with open(json_file, 'w', encoding='utf-8') as f:
            json.dump(data, f, indent=4)
        
        print(f"Updated: {slug}")
    else:
        print(f"NOT FOUND: {json_file}")

print(f"\nTotal updated: {len(lessons_config)} lessons")
