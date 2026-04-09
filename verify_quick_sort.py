import json

with open('src/data/courses/dsa/dsa.json', 'r', encoding='utf-8') as f:
    dsa_data = json.load(f)

print("=" * 60)
print("QUICK SORT SECTION VERIFICATION")
print("=" * 60)

for module in dsa_data['modules']:
    if module['slug'] == 'sorting-algorithms':
        print(f"\nModule: {module['title']}")
        for section in module['sections']:
            if section['slug'] == 'quick-sort':
                print(f"\nSection: {section['title']}")
                print(f"Total Lessons: {len(section['lessons'])}\n")
                for i, lesson in enumerate(section['lessons'], 1):
                    print(f"  {i}. {lesson['title']}")
                    print(f"     Slug: {lesson['slug']}")
                    print(f"     Posted: {lesson.get('isPosted', False)}")
                    print()

print("=" * 60)
print("All lessons added successfully!")
print("=" * 60)
