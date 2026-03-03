def fib(n):
    if n <= 1:
        return n
    return fib(n-1) + fib(n-2)

def print_tree(n, indent=""):
    print(f"{indent}fib({n})")
    if n > 1:
        print_tree(n-1, indent + "  ")
        print_tree(n-2, indent + "  ")