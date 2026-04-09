#!/usr/bin/env python3
import os
import re
from pathlib import Path

def convert_to_cpp(py_content, class_name):
    """Convert Python code to C++"""
    lines = py_content.strip().split('\n')
    cpp_lines = [
        "#include <vector>",
        "#include <unordered_map>",
        "using namespace std;",
        "",
        "class Solution {",
        "public:"
    ]
    
    i = 0
    while i < len(lines):
        line = lines[i]
        stripped = line.strip()
        
        # Skip class definition
        if stripped.startswith('class '):
            i += 1
            continue
        
        # Copy comments
        if '# ===========' in line or '# Time:' in line or '# Space:' in line:
            cpp_lines.append(line.replace('#', '//'))
            i += 1
            continue
        
        # Function definition
        if stripped.startswith('def ') and '(self' in stripped:
            func_match = re.match(r'def (\w+)\(self(?:,\s*(.+?))?\):', stripped)
            if func_match:
                func_name = func_match.group(1)
                params_str = func_match.group(2) or ""
                
                # Parse parameters
                cpp_params = []
                if params_str:
                    for param in params_str.split(','):
                        param = param.strip()
                        if param and '=' not in param:
                            cpp_params.append(f"int {param}")
                
                cpp_lines.append(f"    int {func_name}({', '.join(cpp_params)}) {{")
                
                # Process function body
                i += 1
                while i < len(lines):
                    body_line = lines[i]
                    body_stripped = body_line.strip()
                    
                    # End of function
                    if body_stripped and not body_line.startswith(' ') and not body_line.startswith('\t'):
                        break
                    if body_stripped.startswith('def '):
                        break
                    
                    if not body_stripped or body_stripped.startswith('#'):
                        i += 1
                        continue
                    
                    # Convert Python syntax to C++
                    cpp_line = body_line
                    cpp_line = cpp_line.replace('self.', '')
                    cpp_line = cpp_line.replace('True', 'true').replace('False', 'false')
                    cpp_line = cpp_line.replace('None', 'nullptr')
                    cpp_line = cpp_line.replace(' and ', ' && ').replace(' or ', ' || ')
                    cpp_line = cpp_line.replace(' not ', ' !')
                    cpp_line = cpp_line.replace('elif ', 'else if (').replace('if ', 'if (')
                    cpp_line = cpp_line.replace(' in memo', '.count')
                    
                    # Handle dictionary/map
                    cpp_line = cpp_line.replace('memo = {}', 'unordered_map<int, int> memo;')
                    cpp_line = cpp_line.replace('memo[', 'memo[')
                    
                    # Handle list initialization
                    if 'dp = [0]' in cpp_line:
                        match = re.search(r'dp = \[0\] \* \((.+?)\)', cpp_line)
                        if match:
                            size = match.group(1)
                            indent = len(cpp_line) - len(cpp_line.lstrip())
                            cpp_line = ' ' * indent + f"vector<int> dp({size}, 0);"
                    
                    # Handle tuple assignment
                    if ', ' in cpp_line and '=' in cpp_line and 'dp[' not in cpp_line:
                        parts = cpp_line.split('=')
                        if len(parts) == 2:
                            left = parts[0].strip()
                            right = parts[1].strip()
                            if ',' in left:
                                vars = [v.strip() for v in left.split(',')]
                                vals = [v.strip() for v in right.split(',')]
                                indent = len(cpp_line) - len(cpp_line.lstrip())
                                cpp_line = ''
                                for var, val in zip(vars, vals):
                                    cpp_line += ' ' * indent + f"{var} = {val};\n"
                                cpp_line = cpp_line.rstrip()
                    
                    # Add semicolons
                    if cpp_line.strip() and not cpp_line.strip().endswith(('{', '}', ';', ':')):
                        if 'return' in cpp_line or '=' in cpp_line:
                            cpp_line = cpp_line.rstrip() + ';'
                    
                    # Handle colons
                    if ':' in cpp_line and not '//' in cpp_line:
                        cpp_line = cpp_line.replace(':', ') {')
                    
                    cpp_lines.append(cpp_line)
                    i += 1
                
                cpp_lines.append("    }")
                continue
        
        i += 1
    
    cpp_lines.append("};")
    return '\n'.join(cpp_lines) + '\n'

def convert_to_java(py_content, class_name):
    """Convert Python code to Java"""
    lines = py_content.strip().split('\n')
    java_lines = [
        "import java.util.HashMap;",
        "import java.util.Map;",
        "",
        "class Solution {"
    ]
    
    i = 0
    while i < len(lines):
        line = lines[i]
        stripped = line.strip()
        
        # Skip class definition
        if stripped.startswith('class '):
            i += 1
            continue
        
        # Copy comments
        if '# ===========' in line or '# Time:' in line or '# Space:' in line:
            java_lines.append(line.replace('#', '//'))
            i += 1
            continue
        
        # Function definition
        if stripped.startswith('def ') and '(self' in stripped:
            func_match = re.match(r'def (\w+)\(self(?:,\s*(.+?))?\):', stripped)
            if func_match:
                func_name = func_match.group(1)
                params_str = func_match.group(2) or ""
                
                # Parse parameters
                java_params = []
                if params_str:
                    for param in params_str.split(','):
                        param = param.strip()
                        if param and '=' not in param:
                            java_params.append(f"int {param}")
                
                java_lines.append(f"    public int {func_name}({', '.join(java_params)}) {{")
                
                # Process function body
                i += 1
                while i < len(lines):
                    body_line = lines[i]
                    body_stripped = body_line.strip()
                    
                    # End of function
                    if body_stripped and not body_line.startswith(' ') and not body_line.startswith('\t'):
                        break
                    if body_stripped.startswith('def '):
                        break
                    
                    if not body_stripped or body_stripped.startswith('#'):
                        i += 1
                        continue
                    
                    # Convert Python syntax to Java
                    java_line = body_line
                    java_line = java_line.replace('self.', '')
                    java_line = java_line.replace('True', 'true').replace('False', 'false')
                    java_line = java_line.replace('None', 'null')
                    java_line = java_line.replace(' and ', ' && ').replace(' or ', ' || ')
                    java_line = java_line.replace(' not ', ' !')
                    java_line = java_line.replace('elif ', 'else if (').replace('if ', 'if (')
                    
                    # Handle dictionary/map
                    java_line = java_line.replace('memo = {}', 'Map<Integer, Integer> memo = new HashMap<>();')
                    java_line = java_line.replace(' in memo', '.containsKey')
                    
                    # Handle list initialization
                    if 'dp = [0]' in java_line:
                        match = re.search(r'dp = \[0\] \* \((.+?)\)', java_line)
                        if match:
                            size = match.group(1)
                            indent = len(java_line) - len(java_line.lstrip())
                            java_line = ' ' * indent + f"int[] dp = new int[{size}];"
                    
                    # Handle tuple assignment
                    if ', ' in java_line and '=' in java_line and 'dp[' not in java_line and '[' not in java_line:
                        parts = java_line.split('=')
                        if len(parts) == 2:
                            left = parts[0].strip()
                            right = parts[1].strip()
                            if ',' in left:
                                vars = [v.strip() for v in left.split(',')]
                                vals = [v.strip() for v in right.split(',')]
                                indent = len(java_line) - len(java_line.lstrip())
                                java_line = ''
                                for var, val in zip(vars, vals):
                                    java_line += ' ' * indent + f"{var} = {val};\n"
                                java_line = java_line.rstrip()
                    
                    # Add semicolons
                    if java_line.strip() and not java_line.strip().endswith(('{', '}', ';', ':')):
                        if 'return' in java_line or '=' in java_line:
                            java_line = java_line.rstrip() + ';'
                    
                    # Handle colons
                    if ':' in java_line and not '//' in java_line:
                        java_line = java_line.replace(':', ') {')
                    
                    java_lines.append(java_line)
                    i += 1
                
                java_lines.append("    }")
                continue
        
        i += 1
    
    java_lines.append("}")
    return '\n'.join(java_lines) + '\n'

def process_all_files():
    """Process all Python DP files"""
    base_path = Path(r"d:\interview-ignite-lab\src\data\courses\dsa\dynamic-programming")
    python_files = list(base_path.rglob('code/python/*.py'))
    
    processed = 0
    skipped = 0
    
    for py_file in python_files:
        # Read Python content
        with open(py_file, 'r', encoding='utf-8') as f:
            py_content = f.read()
        
        # Skip if empty or placeholder
        if len(py_content) < 50 or 'pass' in py_content:
            skipped += 1
            continue
        
        # Get class name
        file_name = py_file.stem
        class_name = ''.join(word.capitalize() for word in file_name.split('_'))
        
        # Paths for C++ and Java
        cpp_dir = py_file.parent.parent / 'cpp'
        java_dir = py_file.parent.parent / 'java'
        cpp_file = cpp_dir / f"{class_name}.cpp"
        java_file = java_dir / f"{class_name}.java"
        
        # Check if already exists and has content
        cpp_exists = cpp_file.exists() and cpp_file.stat().st_size > 200
        java_exists = java_file.exists() and java_file.stat().st_size > 200
        
        if cpp_exists and java_exists:
            skipped += 1
            continue
        
        print(f"Processing: {py_file.name}")
        
        # Generate C++
        if not cpp_exists:
            try:
                cpp_content = convert_to_cpp(py_content, class_name)
                cpp_dir.mkdir(parents=True, exist_ok=True)
                with open(cpp_file, 'w', encoding='utf-8') as f:
                    f.write(cpp_content)
                print(f"  [OK] Created {cpp_file.name}")
            except Exception as e:
                print(f"  [ERROR] Error creating C++: {e}")
        
        # Generate Java
        if not java_exists:
            try:
                java_content = convert_to_java(py_content, class_name)
                java_dir.mkdir(parents=True, exist_ok=True)
                with open(java_file, 'w', encoding='utf-8') as f:
                    f.write(java_content)
                print(f"  [OK] Created {java_file.name}")
            except Exception as e:
                print(f"  [ERROR] Error creating Java: {e}")
        
        processed += 1
    
    print(f"\n[DONE] Processed: {processed} files")
    print(f"[SKIP] Skipped: {skipped} files")

if __name__ == "__main__":
    process_all_files()
