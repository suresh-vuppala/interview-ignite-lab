#!/usr/bin/env python3
"""
Batch script to analyze DP problems and identify which need markdown documentation.
"""
import os
from pathlib import Path
import json

def check_python_file(file_path):
    """Check if Python file has actual implementation (not just placeholder)"""
    try:
        with open(file_path, 'r', encoding='utf-8') as f:
            content = f.read()
        
        # Check if it's a placeholder
        if len(content) < 100 or 'pass' in content or '# DP solution' in content:
            return False, 0
        
        # Count number of solutions (look for SOLUTION markers)
        solution_count = content.count('# ====')
        return True, solution_count
    except:
        return False, 0

def check_markdown_file(md_path):
    """Check if markdown file exists and has comprehensive content"""
    if not md_path.exists():
        return False, "Missing"
    
    try:
        with open(md_path, 'r', encoding='utf-8') as f:
            content = f.read()
        
        # Check if it has comprehensive format (multiple solutions)
        if '## Solution 1:' in content and '## Solution 2:' in content:
            return True, "Complete"
        elif len(content) > 500:
            return True, "Partial"
        else:
            return False, "Stub"
    except:
        return False, "Error"

def analyze_dp_categories():
    """Analyze all DP categories and generate report"""
    base_path = Path('src/data/courses/dsa/dynamic-programming')
    categories = {
        'string-dp': 'String DP',
        'classic-dp': 'Classic DP',
        'lis-sequence': 'LIS & Sequence',
        'state-decision-dp': 'State/Decision DP'
    }
    
    report = {}
    
    for cat_dir, cat_name in categories.items():
        cat_path = base_path / cat_dir
        if not cat_path.exists():
            continue
        
        problems = []
        
        # Find all problem directories
        for problem_dir in sorted(cat_path.iterdir()):
            if not problem_dir.is_dir():
                continue
            
            problem_name = problem_dir.name
            
            # Check Python implementation
            py_files = list((problem_dir / 'code' / 'python').glob('*.py'))
            has_impl = False
            solution_count = 0
            
            for py_file in py_files:
                impl, count = check_python_file(py_file)
                if impl:
                    has_impl = True
                    solution_count = max(solution_count, count)
            
            # Check markdown
            md_file = problem_dir / f"{problem_name}.md"
            has_md, md_status = check_markdown_file(md_file)
            
            # Check C++ and Java
            cpp_files = list((problem_dir / 'code' / 'cpp').glob('*.cpp')) if (problem_dir / 'code' / 'cpp').exists() else []
            java_files = list((problem_dir / 'code' / 'java').glob('*.java')) if (problem_dir / 'code' / 'java').exists() else []
            
            has_cpp = any(f.stat().st_size > 200 for f in cpp_files)
            has_java = any(f.stat().st_size > 200 for f in java_files)
            
            problems.append({
                'name': problem_name,
                'has_python': has_impl,
                'solutions': solution_count,
                'has_cpp': has_cpp,
                'has_java': has_java,
                'markdown': md_status,
                'needs_work': not has_md or not has_impl or not has_cpp or not has_java
            })
        
        report[cat_name] = problems
    
    return report

def print_report(report):
    """Print formatted report"""
    print("\n" + "="*80)
    print("DP PROBLEMS ANALYSIS REPORT")
    print("="*80)
    
    total_problems = 0
    needs_markdown = 0
    needs_code = 0
    complete = 0
    
    for category, problems in report.items():
        print(f"\n### {category} ({len(problems)} problems)")
        print("-" * 80)
        
        for p in problems:
            total_problems += 1
            status_parts = []
            
            if p['has_python']:
                status_parts.append(f"PY({p['solutions']})")
            else:
                status_parts.append("PY(X)")
                needs_code += 1
            
            status_parts.append("C++" if p['has_cpp'] else "C++(X)")
            status_parts.append("Java" if p['has_java'] else "Java(X)")
            status_parts.append(f"MD:{p['markdown']}")
            
            if not p['needs_work']:
                complete += 1
                status = "[OK] COMPLETE"
            else:
                status = "[!] NEEDS WORK"
                if p['markdown'] in ['Missing', 'Stub']:
                    needs_markdown += 1
            
            print(f"  {p['name']:40} | {' | '.join(status_parts):30} | {status}")
    
    print("\n" + "="*80)
    print(f"SUMMARY:")
    print(f"  Total Problems: {total_problems}")
    print(f"  Complete: {complete}")
    print(f"  Need Markdown: {needs_markdown}")
    print(f"  Need Code: {needs_code}")
    print("="*80 + "\n")
    
    # Generate list of problems needing markdown
    print("\nPROBLEMS NEEDING COMPREHENSIVE MARKDOWN:")
    print("-" * 80)
    for category, problems in report.items():
        md_needed = [p for p in problems if p['markdown'] in ['Missing', 'Stub', 'Partial']]
        if md_needed:
            print(f"\n{category}:")
            for p in md_needed:
                print(f"  - {p['name']} (Status: {p['markdown']}, Solutions: {p['solutions']})")

if __name__ == "__main__":
    os.chdir(r"d:\interview-ignite-lab")
    report = analyze_dp_categories()
    print_report(report)
    
    # Save report to JSON
    with open('dp_analysis_report.json', 'w') as f:
        json.dump(report, f, indent=2)
    print("\nDetailed report saved to: dp_analysis_report.json")
