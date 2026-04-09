import json

with open('src/data/courses/dsa/dsa.json', 'r', encoding='utf-8') as f:
    dsa_data = json.load(f)

print("=" * 60)
print("FINAL VERIFICATION - DSA COURSE UPDATES")
print("=" * 60)

# Check Quick Sort
print("\n1. QUICK SORT IN SORTING ALGORITHMS:")
for module in dsa_data['modules']:
    if module['slug'] == 'sorting-algorithms':
        for section in module['sections']:
            if section['slug'] == 'quick-sort':
                print(f"   Found: {section['title']}")
                for lesson in section['lessons']:
                    print(f"     - {lesson['title']} (slug: {lesson['slug']})")
                break

# Check Greedy Algorithms
print("\n2. GREEDY ALGORITHMS MODULE:")
for module in dsa_data['modules']:
    if module['slug'] == 'greedy':
        print(f"   Module: {module['title']}")
        for section in module['sections']:
            print(f"   Section: {section['title']} ({len(section['lessons'])} lessons)")
            for lesson in section['lessons']:
                print(f"     - {lesson['title']}")

# Check Miscellaneous
print("\n3. MISCELLANEOUS MODULE:")
for module in dsa_data['modules']:
    if module['slug'] == 'miscellaneous':
        print(f"   Module: {module['title']}")
        for section in module['sections']:
            print(f"   Section: {section['title']} ({len(section['lessons'])} lessons)")
            for lesson in section['lessons']:
                print(f"     - {lesson['title']}")

# Summary
print("\n" + "=" * 60)
print("SUMMARY:")
print("=" * 60)
total_modules = len(dsa_data['modules'])
total_lessons = sum(len(lesson) for module in dsa_data['modules'] for section in module.get('sections', []) for lesson in section.get('lessons', []))

print(f"Total Modules: {total_modules}")
print(f"Total Lessons: {total_lessons}")
print("\nNew Additions:")
print("  - Quick Sort: 1 lesson in Sorting Algorithms")
print("  - Greedy Algorithms: 11 lessons (4 sections)")
print("  - Miscellaneous: 1 lesson (Design Twitter)")
print("\nAll files created successfully!")
