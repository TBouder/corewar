echo "\033[44m\033[1mFILE ERROR (empty, not valid, not file, not .s, dev/null, etc.)\033[0m"
echo "\033[41m\033[1m ---> ./asm\033[0m"
./asm
# ~/.brew/bin/valgrind --leak-check=full --suppressions=.valgrind.supp --show-leak-kinds=all -q ./asm
echo "\n\033[41m\033[1m ---> ./asm ..\033[0m"
./asm ..
# ~/.brew/bin/valgrind --leak-check=full --suppressions=.valgrind.supp --show-leak-kinds=all -q ./asm ..
echo "\n\033[41m\033[1m ---> ./asm 1\033[0m"
./asm 1
# ~/.brew/bin/valgrind --leak-check=full --suppressions=.valgrind.supp --show-leak-kinds=all -q ./asm 1
echo "\n\033[41m\033[1m ---> ./asm empty\033[0m"
./asm empty
# ~/.brew/bin/valgrind --leak-check=full --suppressions=.valgrind.supp --show-leak-kinds=all -q ./asm empty
echo "\n\033[41m\033[1m ---> ./asm /dev/null\033[0m"
./asm /dev/null
# ~/.brew/bin/valgrind --leak-check=full --suppressions=.valgrind.supp --show-leak-kinds=all -q ./asm /dev/null
echo "\n\033[41m\033[1m ---> ./asm /dev/random\033[0m"
./asm /dev/random
# ~/.brew/bin/valgrind --leak-check=full --suppressions=.valgrind.supp --show-leak-kinds=all -q ./asm /dev/random
echo "\n\033[41m\033[1m ---> ./asm ""\033[0m"
./asm ""
# ~/.brew/bin/valgrind --leak-check=full --suppressions=.valgrind.supp --show-leak-kinds=all -q ./asm ""
echo "\n\033[41m\033[1m ---> ./asm NULL\033[0m"
./asm NULL
# ~/.brew/bin/valgrind --leak-check=full --suppressions=.valgrind.supp --show-leak-kinds=all -q ./asm NULL
echo "\n\033[41m\033[1m ---> ./asm main.c\033[0m"
./asm main.c
# ~/.brew/bin/valgrind --leak-check=full --suppressions=.valgrind.supp --show-leak-kinds=all -q ./asm main.c
echo "\n\033[41m\033[1m ---> ./asm main.c Makefile\033[0m"
0./asm main.c Makefile
# ~/.brew/bin/valgrind --leak-check=full --suppressions=.valgrind.supp --show-leak-kinds=all -q ./asm main.c Makefile
echo "\n\033[41m\033[1m ---> ./asm tests/test.s\033[0m"
./asm tests/test.s
# ~/.brew/bin/valgrind --leak-check=full --suppressions=.valgrind.supp --show-leak-kinds=all -q ./asm tests/test.s
echo "\n\033[41m\033[1m ---> ./asm tests/empty.s main.c\033[0m"
./asm tests/empty.s main.c
# ~/.brew/bin/valgrind --leak-check=full --suppressions=.valgrind.supp --show-leak-kinds=all -q ./asm tests/empty.s main.c
echo "\n\033[41m\033[1m ---> ./asm main.c empty.s\033[0m"
./asm main.c tests/empty.s
# ~/.brew/bin/valgrind --leak-check=full --suppressions=.valgrind.supp --show-leak-kinds=all -q ./asm main.c tests/empty.s
echo "\n\033[41m\033[1m ---> ./asm tests/empty.s valid.s\033[0m"
./asm tests/empty.s tests/valid.s
# ~/.brew/bin/valgrind --leak-check=full --suppressions=.valgrind.supp --show-leak-kinds=all -q ./asm tests/empty.s tests/valid.s
echo "\n\033[41m\033[1m ---> ./asm tests/empty.s\033[0m"
./asm tests/empty.s
# ~/.brew/bin/valgrind --leak-check=full --suppressions=.valgrind.supp --show-leak-kinds=all -q ./asm tests/empty.s

echo "\n\033[42m\033[1m ---> ./asm tests/valid.s\033[0m"
./asm tests/valid.s
# ~/.brew/bin/valgrind --leak-check=full --suppressions=.valgrind.supp --show-leak-kinds=all -q ./asm tests/valid.s

# ---------------------------------------------------------------------------- #

# Rajouter plusieurs .name
# name max et sup

echo "\n\n\033[44m\033[1mCHAMPION ERROR (name or comment)\033[0m"
echo "\n\033[41m\033[1m ---> ./asm tests/error_name00.s (no name line)\033[0m"
./asm tests/error_name00.s
# ~/.brew/bin/valgrind --leak-check=full --suppressions=.valgrind.supp --show-leak-kinds=all -q ./asm tests/error_name00.s
echo "\n\033[41m\033[1m ---> ./asm tests/error_name01.s (only .name)\033[0m"
./asm tests/error_name01.s
# ~/.brew/bin/valgrind --leak-check=full --suppressions=.valgrind.supp --show-leak-kinds=all -q ./asm tests/error_name01.s
echo "\n\033[41m\033[1m ---> ./asm tests/error_name02.s (.name \"\")\033[0m"
./asm tests/error_name02.s
# ~/.brew/bin/valgrind --leak-check=full --suppressions=.valgrind.supp --show-leak-kinds=all -q ./asm tests/error_name02.s
echo "\n\033[41m\033[1m ---> ./asm tests/error_name03.s (.name 'name')\033[0m"
./asm tests/error_name03.s
# ~/.brew/bin/valgrind --leak-check=full --suppressions=.valgrind.supp --show-leak-kinds=all -q ./asm tests/error_name03.s
echo "\n\033[41m\033[1m ---> ./asm tests/error_name04.s (.name '')\033[0m"
./asm tests/error_name04.s
# ~/.brew/bin/valgrind --leak-check=full --suppressions=.valgrind.supp --show-leak-kinds=all -q ./asm tests/error_name04.s
echo "\n\033[41m\033[1m ---> ./asm tests/error_name05.s (.name \"name\"\"\")\033[0m"
./asm tests/error_name05.s
# ~/.brew/bin/valgrind --leak-check=full --suppressions=.valgrind.supp --show-leak-kinds=all -q ./asm tests/error_name05.s
echo "\n\033[41m\033[1m ---> ./asm tests/error_name06.s (.name \"name\"\")\033[0m"
./asm tests/error_name06.s
# ~/.brew/bin/valgrind --leak-check=full --suppressions=.valgrind.supp --show-leak-kinds=all -q ./asm tests/error_name06.s
echo "\n\033[41m\033[1m ---> ./asm tests/error_name07.s (.name \"name)\033[0m"
./asm tests/error_name07.s
# ~/.brew/bin/valgrind --leak-check=full --suppressions=.valgrind.supp --show-leak-kinds=all -q ./asm tests/error_name07.s
echo "\n\033[41m\033[1m ---> ./asm tests/error_name08.s (.name name)\033[0m"
./asm tests/error_name08.s
# ~/.brew/bin/valgrind --leak-check=full --suppressions=.valgrind.supp --show-leak-kinds=all -q ./asm tests/error_name08.s
echo "\n\033[41m\033[1m ---> ./asm tests/error_name09.s (.name \"name\" ,)\033[0m"
./asm tests/error_name09.s
# ~/.brew/bin/valgrind --leak-check=full --suppressions=.valgrind.supp --show-leak-kinds=all -q ./asm tests/error_name09.s
echo "\n\033[41m\033[1m ---> ./asm tests/error_name10.s (.name \"name\" 	o)\033[0m"
./asm tests/error_name10.s
# ~/.brew/bin/valgrind --leak-check=full --suppressions=.valgrind.supp --show-leak-kinds=all -q ./asm tests/error_name10.s
echo "\n\033[41m\033[1m ---> ./asm tests/error_name11.s (.name o \"name\")\033[0m"
./asm tests/error_name11.s
# ~/.brew/bin/valgrind --leak-check=full --suppressions=.valgrind.supp --show-leak-kinds=all -q ./asm tests/error_name11.s
echo "\n\033[41m\033[1m ---> ./asm tests/error_name12.s (.name , \"name\")\033[0m"
./asm tests/error_name12.s
# ~/.brew/bin/valgrind --leak-check=full --suppressions=.valgrind.supp --show-leak-kinds=all -q ./asm tests/error_name12.s
echo "\n\033[41m\033[1m ---> ./asm tests/error_name13.s (.name name\")\033[0m"
./asm tests/error_name13.s
# ~/.brew/bin/valgrind --leak-check=full --suppressions=.valgrind.supp --show-leak-kinds=all -q ./asm tests/error_name13.s
echo "\n\033[41m\033[1m ---> ./asm tests/error_name14.s (.name \"\" \"name\")\033[0m"
./asm tests/error_name14.s
# ~/.brew/bin/valgrind --leak-check=full --suppressions=.valgrind.supp --show-leak-kinds=all -q ./asm tests/error_name14.s
echo "\n\033[41m\033[1m ---> ./asm tests/error_name15.s (.name \"\"name\")\033[0m"
./asm tests/error_name15.s
# ~/.brew/bin/valgrind --leak-check=full --suppressions=.valgrind.supp --show-leak-kinds=all -q ./asm tests/error_name15.s

echo "\n\033[42m\033[1m ---> ./asm tests/valid_strange_name00.s (.name "''")\033[0m"
./asm tests/valid_strange_name00.s
# ~/.brew/bin/valgrind --leak-check=full --suppressions=.valgrind.supp --show-leak-kinds=all -q ./asm tests/valid_strange_name00.s
