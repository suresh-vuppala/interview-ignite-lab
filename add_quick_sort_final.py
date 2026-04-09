import json

with open('src/data/courses/dsa/dsa.json', 'r', encoding='utf-8') as f:
    dsa_data = json.load(f)

# Find Sorting Algorithms module and add Quick Sort
for module in dsa_data['modules']:
    if module['slug'] == 'sorting-algorithms':
        # Add Quick Sort section
        quick_sort_section = {
            "title": "Quick Sort",
            "slug": "quick-sort",
            "lessons": [
                {
                    "isPosted": True,
                    "title": "Quick Sort",
                    "slug": "quick-sort"
                }
            ]
        }
        module['sections'].append(quick_sort_section)
        print(f"Added Quick Sort to {module['title']}")
        break

with open('src/data/courses/dsa/dsa.json', 'w', encoding='utf-8') as f:
    json.dump(dsa_data, f, indent=4, ensure_ascii=False)

print("Quick Sort added successfully!")
