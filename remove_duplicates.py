import json

with open('src/data/courses/dsa/dsa.json', 'r', encoding='utf-8') as f:
    dsa_data = json.load(f)

# Remove duplicates by keeping only first occurrence of each slug
seen_slugs = set()
unique_modules = []

for module in dsa_data['modules']:
    if module['slug'] not in seen_slugs:
        seen_slugs.add(module['slug'])
        unique_modules.append(module)
    else:
        print(f"Removing duplicate: {module['title']}")

dsa_data['modules'] = unique_modules

with open('src/data/courses/dsa/dsa.json', 'w', encoding='utf-8') as f:
    json.dump(dsa_data, f, indent=4, ensure_ascii=False)

print(f"\nTotal modules after cleanup: {len(unique_modules)}")
