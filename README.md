*This project has been created as part of the 42 curriculum by elsalama.*

# ft_printf

## Description

**ft_printf** is a custom C implementation of the standard C library `printf()` function, compiled into a static library named `libftprintf.a`. The goal of this project is to understand and apply **variadic functions** in C (`<stdarg.h>`), format string parsing, low-level output with `write()`, and clean, modular, Norm-compliant C architecture.

Unlike the standard libc `printf()`, this implementation does not perform output buffering. It parses the format string sequentially, writes formatted output directly to standard output (`fd = 1`), and returns the total number of characters printed—or `-1` if an error occurs (such as a `NULL` format string, a trailing `%`, or a failed `write()` / `malloc()` call).

### Supported Conversions

| Specifier | Description | Handler Function |
| :--- | :--- | :--- |
| `%c` | Prints a single character | `ft_putchar()` |
| `%s` | Prints a null-terminated string (prints `(null)` if `NULL`) | `ft_putstr()` |
| `%p` | Prints a `void *` pointer address in lowercase hexadecimal prefixed with `0x` (prints `(nil)` if `NULL`) | `ft_void()` |
| `%d` | Prints a signed decimal (base 10) integer | `ft_putnbr()` |
| `%i` | Prints a signed base 10 integer | `ft_putnbr()` |
| `%u` | Prints an unsigned decimal (base 10) integer | `ft_uputnbr()` |
| `%x` | Prints an unsigned integer in lowercase hexadecimal (base 16) | `ft_hex()` |
| `%X` | Prints an unsigned integer in uppercase hexadecimal (base 16) | `ft_hexupper()` |
| `%%` | Prints a literal percent sign (`%`) | `ft_putchar()` |

---

## Instructions

### Project Structure

```text
ft_printf/
├── Makefile
├── README.md
├── ft_printf.h
├── ft_printf.c
└── src/
    ├── ft_putchar.c
    ├── ft_putstr.c
    ├── ft_putnbr.c
    ├── ft_uputnbr.c
    ├── ft_hex.c
    ├── ft_hexupper.c
    └── ft_void.c
```

### Compilation

Compile the static library `libftprintf.a` at the root of the repository using `make`:

```bash
make
```

The `Makefile` compiles all source files with `cc -Wall -Wextra -Werror` and archives the resulting object files using `ar rcs`.

### Available Makefile Rules

- `make` / `make all` — Compiles the source files and builds `libftprintf.a`.
- `make clean` — Removes all compiled object files (`.o`).
- `make fclean` — Removes object files and `libftprintf.a`.
- `make re` — Performs a full clean rebuild (`fclean` followed by `all`).

### Usage & Linking

1. Include the header in your C file:

```c
#include "ft_printf.h"

int main(void)
{
    int count;
    int value = 42;

    count = ft_printf("Char: %c | Str: %s | Int: %d | Hex: %x | Ptr: %p | 100%%\n",
                      'A', "Hello 42", value, 255, (void *)&value);
    ft_printf("Printed %d characters.\n", count);
    return (0);
}
```

2. Compile and link your program against `libftprintf.a`:

```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o test_printf
./test_printf
```

---

## Algorithm and Data Structure

### Data Structures

1. **Variadic Argument List (`va_list *`)**:
   - The core data structure is the standard C `va_list`, initialized in `ft_printf()` via `va_start()` and always cleaned up via `va_end()`.
   - Rather than passing `va_list` by value to helper functions, a pointer (`va_list *list`) is passed to `ft_parse()` and `ft_format()`. This guarantees consistent cursor advancement across different CPU architectures and ABIs (such as `x86_64` and `arm64`), where `va_list` may be implemented as either an array or a pointer.
   - Separating `ft_parse()` from `ft_printf()` ensures `va_end()` is always executed before returning, even on early `-1` error paths.

2. **Direct Unbuffered Streaming (No Output Buffer Struct)**:
   - Because buffer management is explicitly excluded by the subject, no custom ring buffer or formatting struct is needed. Output is written directly to file descriptor `1`, keeping memory usage minimal and making write-error detection immediate.

3. **Right-to-Left Temporary Buffer for Hexadecimal Conversion (`ft_hex.c`, `ft_hexupper.c`)**:
   - For base-16 conversions, `ft_hexoa()` dynamically allocates an exact-sized `char *` string (`calc_size(n) + 1` bytes, or `2` bytes via `zero_handler()` when `n == 0`) and maps remainders using a static base lookup string (`"0123456789abcdef"` or `"0123456789ABCDEF"`).
   - Because modulo (`n % 16`) extracts digits from least significant to most significant, writing into an exact-sized array from back to front avoids reversing the string or relying on recursion for hexadecimal output. The buffer is printed via `ft_putstr()` and immediately freed before returning, preventing memory leaks even if `write()` fails.

### Algorithm & Design Justification

1. **Single-Pass Linear Parser (`ft_parse` & `ft_format`)**:
   - `ft_parse()` iterates through the format string once in $O(n)$ time, where $n$ is the length of the format string.
   - Regular characters are written directly via `ft_putchar()`.
   - When `%` is encountered, the parser checks that `str[i + 1]` is not `'\0'` (returning `-1` on a trailing lone `%`, matching `glibc` behavior) and delegates to `ft_format()`, which dispatches via an `if / else if` chain. Using `else if` guarantees mutual exclusivity so no format specifier can fall through into subsequent checks.
   - Every helper returns the `int` number of bytes written (or `-1` on error). Any `-1` return value short-circuits execution immediately so partial errors never corrupt the total character count.

2. **Recursive Base-10 Conversion (`ft_putnbr` & `ft_uputnbr`)**:
   - Signed and unsigned base-10 integers are printed recursively (`nb / 10` followed by `nb % 10`). Recursion naturally reverses the digit extraction order so digits print from most significant to least significant with zero heap allocation and $O(\log_{10} v)$ time and stack space (at most 10 recursive frames for 32-bit integers).
   - In `ft_putnbr()`, the `int` input is promoted to `long` before checking `nb < 0` and negating it. This prevents signed integer overflow when handling `INT_MIN` (`-2147483648`).

3. **Type Safety & Width Handling (`%x`, `%X`, `%u`, `%p`, `%c`)**:
   - `%c` retrieves arguments as `int` (`va_arg(*list, int)`) to respect C default argument promotions.
   - `%u`, `%x`, and `%X` retrieve arguments as `unsigned int` (`va_arg(*list, unsigned int)`). Even though `ft_hex()` and `ft_hexupper()` accept `unsigned long`, extracting `unsigned int` ensures 32-bit values are zero-extended rather than sign-extended on 64-bit platforms (e.g., `-1` prints `ffffffff` rather than `ffffffffffffffff`).
   - `%p` casts `void *` to `unsigned long` in `ft_void()` and passes the full 64-bit address to `ft_hex()`, after checking for `NULL` (printing `"(nil)"` to match Linux/`glibc`) and outputting the `"0x"` prefix. `calc_size()` uses `unsigned long` so addresses with the high bit set (such as `(void *)-1` or `ULONG_MAX`) are computed accurately.

---

## Resources

### References

- **Linux / POSIX Manual Pages**:
  - `man 3 printf` — Specification of conversion specifiers, return values, and edge-case behaviors.
  - `man 3 stdarg` — Documentation for `va_list`, `va_start`, `va_arg`, `va_copy`, and `va_end`.
  - `man 2 write` — Low-level file descriptor output and error return semantics.
- **C Reference Documentation**:
  - [cppreference — Variadic functions](https://en.cppreference.com/w/c/variadic)
  - [cppreference — `printf` family](https://en.cppreference.com/w/c/io/fprintf)
  - [GNU C Library Manual — Formatted Output](https://www.gnu.org/software/libc/manual/html_node/Formatted-Output.html)
- **42 Documentation**:
  - 42 Norm (v4) coding standard guidelines (`norminette`).

### AI Usage Disclosure

AI (Gemini) was used as a review and learning assistant during the development of this project for the following specific tasks:

- **Code Review & Debugging**: Reviewing user-written implementations in `ft_printf.c`, `ft_printf.h`, and `src/*.c` to identify bugs—including missing `int` return counts in helper functions, `NULL` dereferences in `ft_putstr()` and `ft_printf()`, signedness issues in `calc_size()`, pointer dereferencing vs. address casting in `ft_void()`, `if` fall-through bugs in `ft_printf.c`, and 64-bit sign-extension issues with `va_arg()`.
- **Edge-Case & Norminette Verification**: Highlighting edge cases (`INT_MIN`, `ULONG_MAX`, `NULL` pointers/strings, trailing `%`, `write()`/`malloc()` failure propagation) and catching 42 Norm formatting issues (tab alignment, line counts, and header `# include` indentation).
- **Build Configuration Review**: Checking the `Makefile` for correct `src/` file paths, unused headers in `ft_printf.h`, header dependency tracking, and relinking prevention.
- **Documentation**: Assisting in structuring and drafting this `README.md` to ensure full compliance with the Chapter V requirements.