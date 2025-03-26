import difflib
import subprocess
import tempfile
import os

def generate_assembly(code: str) -> str:
    """Compiles C code to assembly and returns the assembly output."""
    with tempfile.NamedTemporaryFile(suffix=".c", delete=False) as temp_c:
        temp_c.write(code.encode())
        temp_c.flush()
        asm_file = temp_c.name.replace(".c", ".s")
        
        subprocess.run(["gcc", "-S", "-o", asm_file, temp_c.name], check=True)
        
        with open(asm_file, "r") as f:
            assembly_code = f.read()
        
        os.remove(temp_c.name)
        os.remove(asm_file)
        
        return assembly_code

def extract_differences(code_a: str, code_b: str) -> str:
    """Finds the differences between two C codes and their assembly representations."""
    # Identify line differences in C code
    _differ = difflib.unified_diff(code_a.splitlines(), code_b.splitlines(), lineterm="")
    differ = list(_differ)
    # print(str(differ))
    c_diff_before = [line[1:] for line in differ if line.startswith("-") and not line.startswith("--")]
    c_diff_after = [line[1:] for line in differ if line.startswith("+") and not line.startswith("++")]
    #print(c_diff_after)
    
    # Generate assembly for both codes
    asm_a = generate_assembly(code_a)
    asm_b = generate_assembly(code_b)
    
    # Identify line differences in assembly code
    _asm_differ = difflib.unified_diff(asm_a.splitlines(), asm_b.splitlines(), lineterm="")
    asm_differ = list(_asm_differ)
    asm_diff_before = [line[1:] for line in asm_differ if line.startswith("-") and not line.startswith("--")]
    asm_diff_after = [line[1:] for line in asm_differ if line.startswith("+") and not line.startswith("++")]
    
    # Format output as plain text to avoid markdown errors
    output = (
        "### Code Differences (Before Change)\n\n" + "\n".join(c_diff_before) + 
        "\n\n### Corresponding Assembly (Before Change)\n\n" + "\n".join(asm_diff_before) + 
        "\n\n### Code Differences (After Change)\n\n" + "\n".join(c_diff_after) + 
        "\n\n### Corresponding Assembly (After Change)\n\n" + "\n".join(asm_diff_after)
    )
    
    return output

# Example usage
code_ex_0a = """
#include <stdio.h>

int main(){
    int n = 5;
    n = n + 1;
} 
"""

code_ex_0b = """
#include <stdio.h>

int main(){
    int n = 5;
    n = n * 3;
} 
"""


# Example usage
code_ex_1a = """
#include <stdio.h>

int main() {
    int x = 10;
    if (x > 5) {
        printf("Hello\\n");
    }
}
"""

code_ex_1b = """
#include <stdio.h>

int main() {
    int x = 10;
    if ((x * 2 - 5) % 3 == 0) {
        printf("Hello\\n");
    }
}
"""

# Example usage
code_ex_2a = """
#include <stdio.h>

int main() {
    for (int i = 0; i < 10; i++) {
        printf("%d\\n", i);
    }
}
"""

code_ex_2b = """
#include <stdio.h>

int main() {
    int i = 0;
    while (i < 10) {
        printf("%d\\n", i);
        i++;
    }
}
"""

# Example usage
code_ex_3a = """
#include <stdio.h>

int main() {
    int n = 8;
    n = n * 2;
}
"""

code_ex_3b = """
#include <stdio.h>

int main() {
    int n = 8;
    n = n << 1;
}
"""

# Example usage
code_ex_4a = """
#include <stdio.h>

int main() {
    int a = 5;
    int b = 2;
    int c = a / b;
}
"""

code_ex_4b = """
#include <stdio.h>

int main() {
    float a = 5.0;
    float b = 2.0;
    float c = a / b;
}
"""

# Example usage
code_ex_5a = """
#include <stdio.h>

int square(int x) {
    return x * x;
}

int main() {
    int n = square(5);
}
"""

code_ex_5b = """
#include <stdio.h>

int main() {
    int n = 5 * 5;
}
"""


result = extract_differences(code_ex_0a, code_ex_0b)
print("## Ex 1")
print(result)
result = extract_differences(code_ex_1a, code_ex_1b)
print("## Ex 2")
print(result)
result = extract_differences(code_ex_2a, code_ex_2b)
print("## Ex 3")
print(result)
result = extract_differences(code_ex_3a, code_ex_3b)
print("## Ex 4")
print(result)
print("## Ex 5")
result = extract_differences(code_ex_4a, code_ex_4b)
print(result)
