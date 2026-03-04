import json

with open('src/data/courses/dsa/dsa.json', 'r', encoding='utf-8') as f:
    dsa_data = json.load(f)

# Find Sorting Algorithms module and add lessons to Quick Sort section
for module in dsa_data['modules']:
    if module['slug'] == 'sorting-algorithms':
        for section in module['sections']:
            if section['slug'] == 'quick-sort':
                section['lessons'].extend([
                    {
                        "isPosted": True,
                        "title": "Kth Smallest Element",
                        "slug": "kth-smallest-element"
                    },
                    {
                        "isPosted": True,
                        "title": "Kth Largest Element",
                        "slug": "kth-largest-element"
                    }
                ])
                print(f"Added 2 lessons to Quick Sort section")
                break
        break

with open('src/data/courses/dsa/dsa.json', 'w', encoding='utf-8') as f:
    json.dump(dsa_data, f, indent=4, ensure_ascii=False)

print("Lessons added to dsa.json successfully!")
