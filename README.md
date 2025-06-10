# Pipex

## 📚 Description

**Pipex** is a UNIX-style program that mimics shell piping behavior.  
It takes a file, passes its content through a series of shell commands, and outputs the result to another file.  
This project is part of the 42 school curriculum and helps you deeply understand process handling, piping, and file redirection in UNIX.

---

## 🚀 Mandatory Usage

Your program must behave **exactly like** this shell command:

```bash
< file1 cmd1 | cmd2 > file2
```

### ✅ Program Execution:
```bash
./pipex file1 cmd1 cmd2 file2
```

#### 🔧 Example:
```bash
./pipex infile "ls -l" "wc -l" outfile
# Equivalent to: < infile ls -l | wc -l > outfile
```

---

## 🧠 How It Works

1. Reads from `file1`.
2. Executes `cmd1`, pipes its output to `cmd2`.
3. Writes final output to `file2`.

---

## 🛠️ Installation

### 📦 Requirements
- OS: **Linux** or **macOS**
- Compiler: **GCC** with flags `-Wall -Wextra -Werror`
- Language: **C**
- Libraries: MiniLibX, Libft (your own)
- Tools: **Make**, **bash**

### ⚙️ Build

```bash
make
```

To clean:
```bash
make clean       # removes object files
make fclean      # removes object files + executable
make re          # rebuilds everything
```

---

## 📂 Project Structure

```
.
├── src/
│   ├── pipex.c
│   ├── utils.c
│   └── ...
├── include/
│   └── pipex.h
├── libft/
│   └── ... (copied libft source)
├── Makefile
└── README.md
```

---

## ⚡ Features

- Handles **input/output file redirection**
- Executes shell **commands** with their parameters
- **Pipes output** from one command to the next
- Mimics shell behavior precisely

---

## ✨ Bonus Part (if implemented)

You can run multiple commands in a chain or use **here_doc**:

### ➕ Multiple Commands (Multiple Pipes)

```bash
./pipex infile "cmd1" "cmd2" "cmd3" "cmd4" outfile
# Equivalent to: < infile cmd1 | cmd2 | cmd3 | cmd4 > outfile
```

### ➕ here_doc Support

```bash
./pipex here_doc LIMITER cmd1 cmd2 outfile
# Equivalent to: cmd1 << LIMITER | cmd2 >> outfile
```

---

## 📌 Norm & Constraints

- Written in **C**, 100% **Norm-compliant**
- No **memory leaks**
- Proper error handling (e.g. missing files, invalid commands)
- No crashes (segfaults, bus errors, etc.)
- Efficient and clean resource management (freeing heap memory)

---

## 🧪 Testing

We encourage using test scripts or your own test cases for validation.  
The project should handle invalid arguments, inaccessible files, and wrong commands gracefully.

---

## 📤 Submission

Submit your full project to the Git repository, including:

- All source files (`*.c`, `*.h`)
- `Makefile`
- Libft (if authorized)
- Sample test files or example maps
- Bonus files in `_bonus.c/h` form

---

## 🧠 Author

Project done as part of the [42 School](https://www.42network.org/) curriculum.

---

## 🔐 License

This project is for educational purposes as part of 42 coding school. Do not use in production without permission.




✅ BASIC MULTI-COMMAND PIPELINE TESTS
1. Simple pipeline

< input.txt grep hello | wc -l > output.txt
./pipex_bonus input.txt "grep hello" "wc -l" output.txt


2. Quoted strings

< input.txt grep 'hello world' | awk '{print $1}' > output.txt
./pipex_bonus input.txt "grep 'hello world'" "awk '{print \$1}'" output.txt



✅ ADVANCED COMMAND STRUCTURES
3. Sort and uniq

< input.txt sort | uniq -c | sort -nr > output.txt
./pipex_bonus input.txt "sort" "uniq -c" "sort -nr" output.txt


4. Mixed command options

< input.txt cut -d' ' -f1 | sort | uniq > output.txt
./pipex_bonus input.txt "cut -d' ' -f1" "sort" "uniq" output.txt




✅ HERE_DOC EDGE CASES
5. Basic here_doc

cat <<END | grep foo | wc -l >> output.txt
foo bar
baz foo
not me
END

./pipex_bonus here_doc END "grep foo" "wc -l" output.txt


6. Quoted LIMITER (shell vs. program behavior should match)

cat <<'END' | grep hello | wc >> output.txt
hello world
END

./pipex_bonus here_doc END "grep hello" "wc" output.txt







✅ ERROR HANDLING TESTS
8. Nonexistent command

< input.txt grep hello | nonexistent_cmd | wc -l > output.txt
./pipex_bonus input.txt "grep hello" "nonexistent_cmd" "wc -l" output.txt

Expect: Command not found error.



9. Invalid file

< no_such_file grep hello | wc -l > output.txt
./pipex_bonus no_such_file "grep hello" "wc -l" output.txt

Expect: open infile error.





✅ EDGE-CASE QUOTING BEHAVIOR
10. Quoted quotes

< input.txt awk '{print "\""$1"\""}' | sed 's/"//g' > output.txt
./pipex_bonus input.txt "awk '{print \"\\\"\"\$1\"\\\"\"}'" "sed 's/\"//g'" output.txt

