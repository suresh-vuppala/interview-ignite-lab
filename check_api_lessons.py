import os
import json

def check_and_update_lessons():
    base_path = "src/data/courses/system-design/api-layer"
    updated_count = 0
    total_count = 0
    
    # Walk through all directories
    for root, dirs, files in os.walk(base_path):
        for file in files:
            if file.endswith('.json') and not file == 'api-layer.json':
                json_path = os.path.join(root, file)
                total_count += 1
                
                try:
                    # Read JSON file
                    with open(json_path, 'r', encoding='utf-8') as f:
                        data = json.load(f)
                    
                    # Check if not posted
                    if not data.get('isPosted', False):
                        print(f"Updating: {json_path}")
                        data['isPosted'] = True
                        
                        # Write back to file
                        with open(json_path, 'w', encoding='utf-8') as f:
                            json.dump(data, f, indent=2)
                        
                        updated_count += 1
                    else:
                        print(f"Already posted: {os.path.basename(os.path.dirname(json_path))}")
                        
                except Exception as e:
                    print(f"Error processing {json_path}: {e}")
    
    print(f"\nSummary:")
    print(f"Total lessons checked: {total_count}")
    print(f"Lessons updated to posted: {updated_count}")
    print(f"Already posted: {total_count - updated_count}")

if __name__ == "__main__":
    check_and_update_lessons()