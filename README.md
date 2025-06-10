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

