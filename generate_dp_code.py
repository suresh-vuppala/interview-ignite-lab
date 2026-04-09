import os
import re
from pathlib import Path

def python_to_cpp(py_code, class_name):
    """Convert Python DP code to C++"""
    cpp = f"#include <vector>\n#include <unordered_map>\nusing namespace std;\n\nclass Solution {{\npublic:\n"
    
    lines = py_code.split('\n')
    in_function = False
    indent_level = 1
    
    for line in lines:
        if '# ===========' in line:
            cpp += '    ' * indent_level + line.replace('#', '//') + '\n'
        elif '# Time:' in line or '# Space:' in line:
            cpp += '    ' * indent_level + line.replace('#', '//') + '\n'
        elif line.strip().startswith('def ') and '(self' in line:
            # Extract function signature
            match = re.search(r'def (\w+)\(self,?\s*(.*?)\):', line)
            if match:
                func_name = match.group(1)
                params = match.group(2)
                
                # Convert parameters
                cpp_params = []
                if params:
                    for param in params.split(','):
                        param = param.strip()
                        if param:
                            if 'List' in py_code or 'vector' in py_code or '[' in py_code[:200]:
                                cpp_params.append(f"vector<int>& {param}")
                            else:
                                cpp_params.append(f"int {param}")
                
                cpp += f"    int {func_name}({', '.join(cpp_params)}) {{\n"
                in_function = True
                indent_level = 2
        elif in_function:
            stripped = line.strip()
            if not stripped or stripped.startswith('#'):
                continue
            
            # Convert Python to C++
            converted = line.replace('self.', '').replace(' and ', ' && ').replace(' or ', ' || ')
            converted = converted.replace('True', 'true').replace('False', 'false').replace('None', 'nullptr')
            converted = converted.replace('elif', 'else if').replace('def ', 'int ')
            
            if 'return' in converted:
                cpp += '    ' * indent_level + converted + '\n'
                if not converted.strip().endswith(';'):
                    cpp = cpp.rstrip() + ';\n'
            elif ':' in converted and not '//' in converted:
                converted = converted.replace(':', ' {')
                cpp += '    ' * indent_level + converted + '\n'
            elif converted.strip():
                cpp += '    ' * indent_level + converted + '\n'
                if not converted.strip().endswith(('{', '}', ';')):
                    cpp = cpp.rstrip() + ';\n'
    
    cpp += "};\n"
    return cpp

def python_to_java(py_code, class_name):
    """Convert Python DP code to Java"""
    java = "import java.util.HashMap;\nimport java.util.Map;\n\nclass Solution {\n"
    
    lines = py_code.split('\n')
    
    for line in lines:
        if '# ===========' in line:
            java += '    ' + line.replace('#', '//') + '\n'
        elif '# Time:' in line or '# Space:' in line:
            java += '    ' + line.replace('#', '//') + '\n'
        elif line.strip().startswith('def ') and '(self' in line:
            match = re.search(r'def (\w+)\(self,?\s*(.*?)\):', line)
            if match:
                func_name = match.group(1)
                params = match.group(2)
                
                java_params = []
                if params:
                    for param in params.split(','):
                        param = param.strip()
                        if param:
                            java_params.append(f"int {param}")
                
                java += f"    public int {func_name}({', '.join(java_params)}) {{\n"
    
    java += "    }\n}\n"
    return java

def process_directory(base_path):
    """Process all Python files and generate C++/Java"""
    python_files = list(Path(base_path).rglob('code/python/*.py'))
    
    for py_file in python_files:
        # Skip if already processed
        cpp_dir = py_file.parent.parent / 'cpp'
        java_dir = py_file.parent.parent / 'java'
        
        # Get class name
        file_name = py_file.stem
        class_name = ''.join(word.capitalize() for word in file_name.split('_'))
        
        cpp_file = cpp_dir / f"{class_name}.cpp"
        java_file = java_dir / f"{class_name}.java"
        
        # Check if files exist and are not empty
        if cpp_file.exists() and cpp_file.stat().st_size > 100:
            if java_file.exists() and java_file.stat().st_size > 100:
                continue
        
        print(f"Processing: {py_file.relative_to(base_path)}")
        
        with open(py_file, 'r', encoding='utf-8') as f:
            py_code = f.read()
        
        # Generate C++
        if not cpp_file.exists() or cpp_file.stat().st_size < 100:
            cpp_code = python_to_cpp(py_code, class_name)
            cpp_dir.mkdir(parents=True, exist_ok=True)
            with open(cpp_file, 'w', encoding='utf-8') as f:
                f.write(cpp_code)
            print(f"  Created: {cpp_file.name}")
        
        # Generate Java
        if not java_file.exists() or java_file.stat().st_size < 100:
            java_code = python_to_java(py_code, class_name)
            java_dir.mkdir(parents=True, exist_ok=True)
            with open(java_file, 'w', encoding='utf-8') as f:
                f.write(java_code)
            print(f"  Created: {java_file.name}")

if __name__ == "__main__":
    base = r"d:\interview-ignite-lab\src\data\courses\dsa\dynamic-programming"
    process_directory(base)
    print("\nDone!")
