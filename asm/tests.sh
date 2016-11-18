echo "\033[44m\033[1mFILE ERROR (empty, not valid, not file, not .s, dev/null, etc.)\033[0m"
echo "\033[41m\033[1m ---> ./asm\033[0m"
valgrind --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm
echo "\n\033[41m\033[1m ---> ./asm ..\033[0m"
valgrind --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm ..
echo "\n\033[41m\033[1m ---> ./asm 1\033[0m"
valgrind --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm 1
echo "\n\033[41m\033[1m ---> ./asm empty\033[0m"
valgrind --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm empty
echo "\n\033[41m\033[1m ---> ./asm /dev/null\033[0m"
valgrind --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm /dev/null
echo "\n\033[41m\033[1m ---> ./asm /dev/random\033[0m"
valgrind --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm /dev/random
echo "\n\033[41m\033[1m ---> ./asm ""\033[0m"
valgrind --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm ""
echo "\n\033[41m\033[1m ---> ./asm NULL\033[0m"
valgrind --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm NULL
echo "\n\033[41m\033[1m ---> ./asm main.c\033[0m"
valgrind --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm main.c
echo "\n\033[41m\033[1m ---> ./asm main.c Makefile\033[0m"
valgrind --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm main.c Makefile
echo "\n\033[41m\033[1m ---> ./asm tests/test.s\033[0m"
valgrind --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm tests/test.s
echo "\n\033[41m\033[1m ---> ./asm tests/empty.s main.c\033[0m"
valgrind --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm tests/empty.s main.c
echo "\n\033[41m\033[1m ---> ./asm main.c empty.s\033[0m"
valgrind --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm main.c tests/empty.s
echo "\n\033[41m\033[1m ---> ./asm tests/empty.s valid.s\033[0m"
valgrind --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm tests/empty.s tests/valid.s
echo "\n\033[41m\033[1m ---> ./asm tests/empty.s\033[0m"
valgrind --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm tests/empty.s

echo "\n\033[42m\033[1m ---> ./asm tests/valid.s\033[0m"
valgrind --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm tests/valid.s

# ---------------------------------------------------------------------------- #

echo "\n\n\033[44m\033[1mCHAMPION ERROR (name or comment)\033[0m"
echo "\n\033[41m\033[1m ---> ./asm tests/error_name00.s (no name line)\033[0m"
valgrind --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm tests/error_name00.s
echo "\n\033[41m\033[1m ---> ./asm tests/error_name01.s (only .name)\033[0m"
valgrind --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm tests/error_name01.s
echo "\n\033[41m\033[1m ---> ./asm tests/error_name02.s (.name "")\033[0m"
valgrind --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm tests/error_name02.s
echo "\n\033[41m\033[1m ---> ./asm tests/error_name03.s (.name 'name')\033[0m"
valgrind --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm tests/error_name03.s
echo "\n\033[41m\033[1m ---> ./asm tests/error_name04.s (.name '')\033[0m"
valgrind --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm tests/error_name04.s

echo "\n\033[42m\033[1m ---> ./asm tests/valid_strange_name00.s (.name "''")\033[0m"
valgrind --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm tests/valid_strange_name00.s
