import os
import json

def find_missing_content():
    base_path = "src/data/courses/system-design/api-layer"
    missing_content = []
    
    # Walk through all directories
    for root, dirs, files in os.walk(base_path):
        json_files = [f for f in files if f.endswith('.json') and f != 'api-layer.json']
        
        for json_file in json_files:
            lesson_slug = json_file.replace('.json', '')
            md_file = f"{lesson_slug}.md"
            
            # Check if corresponding .md file exists
            if md_file not in files:
                json_path = os.path.join(root, json_file)
                
                # Read JSON to get title
                try:
                    with open(json_path, 'r', encoding='utf-8') as f:
                        data = json.load(f)
                    
                    if data.get('isPosted', False):
                        missing_content.append({
                            'slug': lesson_slug,
                            'title': data.get('title', lesson_slug),
                            'path': root,
                            'json_path': json_path
                        })
                except Exception as e:
                    print(f"Error reading {json_path}: {e}")
    
    return missing_content

if __name__ == "__main__":
    missing = find_missing_content()
    
    print(f"Found {len(missing)} lessons with missing markdown content:")
    for lesson in missing:
        print(f"- {lesson['title']} ({lesson['slug']})")
        print(f"  Path: {lesson['path']}")
    
    if missing:
        print(f"\nThese lessons are marked as posted but have no content files!")
    else:
        print("\nAll posted lessons have content files.")