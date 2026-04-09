import json

with open('src/data/courses/dsa/dsa.json', 'r', encoding='utf-8') as f:
    dsa_data = json.load(f)

print("=== DSA Course Structure ===\n")

for i, module in enumerate(dsa_data['modules'], 1):
    total_lessons = sum(len(section['lessons']) for section in module['sections'])
    print(f"{i}. {module['title']} ({total_lessons} lessons)")
    
    if module['slug'] in ['sorting', 'greedy', 'miscellaneous']:
        for section in module['sections']:
            print(f"   - {section['title']} ({len(section['lessons'])} lessons)")
            for lesson in section['lessons']:
                print(f"     * {lesson['title']}")

print("\n=== Summary ===")
print("Quick Sort: Added to Sorting Algorithms module")
print("Greedy Algorithms: 11 lessons across 4 sections")
print("Miscellaneous: 1 lesson (Design Twitter)")
print("\nTotal modules:", len(dsa_data['modules']))
