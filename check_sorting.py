import json

with open('src/data/courses/dsa/dsa.json', 'r', encoding='utf-8') as f:
    dsa_data = json.load(f)

print("=== Checking Sorting Module ===\n")

for module in dsa_data['modules']:
    if 'sort' in module['slug'].lower():
        print(f"Module: {module['title']} (slug: {module['slug']})")
        for section in module['sections']:
            print(f"  Section: {section['title']} (slug: {section['slug']})")
            for lesson in section['lessons']:
                print(f"    - {lesson['title']}")
        print()
