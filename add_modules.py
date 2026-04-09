import json

# Read the dsa.json file
with open('src/data/courses/dsa/dsa.json', 'r', encoding='utf-8') as f:
    dsa_data = json.load(f)

# Find Sorting Algorithms module and add Quick Sort lesson
for module in dsa_data['modules']:
    if module['slug'] == 'sorting':
        for section in module['sections']:
            if section['slug'] == 'merge-sort':
                # Add Quick Sort lesson after Merge Sort section
                quick_sort_section = {
                    "title": "Quick Sort",
                    "lessons": [
                        {
                            "isPosted": True,
                            "title": "Quick Sort",
                            "slug": "quick-sort"
                        }
                    ],
                    "slug": "quick-sort"
                }
                # Insert after merge-sort section
                idx = module['sections'].index(section)
                module['sections'].insert(idx + 1, quick_sort_section)
                break
        break

# Create Greedy Algorithms module
greedy_module = {
    "title": "Greedy Algorithms",
    "sections": [
        {
            "title": "Introduction",
            "lessons": [
                {
                    "isPosted": True,
                    "title": "Greedy Choice Property and When Greedy works vs when DP is required",
                    "slug": "greedy-vs-dp"
                }
            ],
            "slug": "introduction"
        },
        {
            "title": "Interval Based",
            "lessons": [
                {
                    "isPosted": True,
                    "title": "Activity Selection",
                    "slug": "activity-selection"
                },
                {
                    "isPosted": True,
                    "title": "Non-overlapping Intervals",
                    "slug": "non-overlapping-intervals"
                },
                {
                    "isPosted": True,
                    "title": "Merge Intervals",
                    "slug": "merge-intervals"
                },
                {
                    "isPosted": True,
                    "title": "Meeting Rooms II",
                    "slug": "meeting-rooms-ii"
                }
            ],
            "slug": "interval-based"
        },
        {
            "title": "Scheduling / Allocation",
            "lessons": [
                {
                    "isPosted": True,
                    "title": "Job Sequencing with Deadlines",
                    "slug": "job-sequencing"
                },
                {
                    "isPosted": True,
                    "title": "Task Scheduler",
                    "slug": "task-scheduler"
                },
                {
                    "isPosted": True,
                    "title": "Gas Station",
                    "slug": "gas-station"
                }
            ],
            "slug": "scheduling-allocation"
        },
        {
            "title": "Others",
            "lessons": [
                {
                    "isPosted": True,
                    "title": "Jump Game",
                    "slug": "jump-game"
                },
                {
                    "isPosted": True,
                    "title": "Jump Game II",
                    "slug": "jump-game-ii"
                },
                {
                    "isPosted": True,
                    "title": "Remove K Digits",
                    "slug": "remove-k-digits"
                }
            ],
            "slug": "others"
        }
    ],
    "slug": "greedy"
}

# Find Dynamic Programming module index and insert Greedy before it
for i, module in enumerate(dsa_data['modules']):
    if module['slug'] == 'dynamic-programming':
        dsa_data['modules'].insert(i, greedy_module)
        break

# Create Miscellaneous module
misc_module = {
    "title": "Miscellaneous",
    "sections": [
        {
            "title": "Design Problems",
            "lessons": [
                {
                    "isPosted": True,
                    "title": "Design Twitter",
                    "slug": "design-twitter"
                }
            ],
            "slug": "design-problems"
        }
    ],
    "slug": "miscellaneous"
}

# Add Miscellaneous module at the end
dsa_data['modules'].append(misc_module)

# Write back to dsa.json
with open('src/data/courses/dsa/dsa.json', 'w', encoding='utf-8') as f:
    json.dump(dsa_data, f, indent=4, ensure_ascii=False)

print("Successfully added:")
print("  - Quick Sort lesson in Sorting Algorithms")
print("  - Greedy Algorithms module (11 lessons)")
print("  - Miscellaneous module (1 lesson)")
