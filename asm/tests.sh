echo "\033[44m\033[1mFILE ERROR (empty, not valid, not file, not .s, dev/null, etc.)\033[0m"
echo "\033[41m\033[1m ---> ./asm\033[0m"
./asm
# sh /Volumes/USB/.files/valgrind/vg-in-place --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm
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
# sh /Volumes/USB/.files/valgrind/vg-in-place --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm /dev/random
echo "\n\033[41m\033[1m ---> ./asm ""\033[0m"
./asm ""
# sh /Volumes/USB/.files/valgrind/vg-in-place --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm ""
echo "\n\033[41m\033[1m ---> ./asm NULL\033[0m"
./asm NULL
# sh /Volumes/USB/.files/valgrind/vg-in-place --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm NULL
echo "\n\033[41m\033[1m ---> ./asm main.c\033[0m"
./asm main.c
# sh /Volumes/USB/.files/valgrind/vg-in-place --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm main.c
echo "\n\033[41m\033[1m ---> ./asm main.c Makefile\033[0m"
./asm main.c Makefile
# sh /Volumes/USB/.files/valgrind/vg-in-place --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm main.c Makefile
echo "\n\033[41m\033[1m ---> ./asm tests/test.s\033[0m"
./asm tests/test.s
# sh /Volumes/USB/.files/valgrind/vg-in-place --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm tests/test.s
echo "\n\033[41m\033[1m ---> ./asm tests/empty.s main.c\033[0m"
./asm tests/empty.s main.c
# sh /Volumes/USB/.files/valgrind/vg-in-place --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm tests/empty.s main.c
echo "\n\033[41m\033[1m ---> ./asm main.c empty.s\033[0m"
./asm main.c tests/empty.s
# sh /Volumes/USB/.files/valgrind/vg-in-place --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm main.c tests/empty.s
echo "\n\033[41m\033[1m ---> ./asm tests/empty.s valid.s\033[0m"
./asm tests/empty.s tests/valid.s
# sh /Volumes/USB/.files/valgrind/vg-in-place --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm tests/empty.s tests/valid.s
echo "\n\033[41m\033[1m ---> ./asm tests/empty.s\033[0m"
./asm tests/empty.s
# sh /Volumes/USB/.files/valgrind/vg-in-place --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm tests/empty.s

echo "\n\033[42m\033[1m ---> ./asm tests/valid.s\033[0m"
./asm tests/valid.s
# sh /Volumes/USB/.files/valgrind/vg-in-place --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm tests/valid.s

# ---------------------------------------------------------------------------- #

# Rajouter plusieurs .name
# name max et sup

echo "\n\n\033[44m\033[1mCHAMPION ERROR (name or comment)\033[0m"
echo "\n\033[41m\033[1m ---> ./asm tests/error_name00.s (no name line)\033[0m"
./asm tests/error_name00.s
# sh /Volumes/USB/.files/valgrind/vg-in-place --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm tests/error_name00.s
echo "\n\033[41m\033[1m ---> ./asm tests/error_name01.s (only .name)\033[0m"
./asm tests/error_name01.s
# sh /Volumes/USB/.files/valgrind/vg-in-place --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm tests/error_name01.s
echo "\n\033[41m\033[1m ---> ./asm tests/error_name02.s (.name \"\")\033[0m"
./asm tests/error_name02.s
# sh /Volumes/USB/.files/valgrind/vg-in-place --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm tests/error_name02.s
echo "\n\033[41m\033[1m ---> ./asm tests/error_name03.s (.name 'name')\033[0m"
./asm tests/error_name03.s
# sh /Volumes/USB/.files/valgrind/vg-in-place --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm tests/error_name03.s
echo "\n\033[41m\033[1m ---> ./asm tests/error_name04.s (.name '')\033[0m"
./asm tests/error_name04.s
# sh /Volumes/USB/.files/valgrind/vg-in-place --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm tests/error_name04.s
echo "\n\033[41m\033[1m ---> ./asm tests/error_name05.s (.name \"name\"\"\")\033[0m"
./asm tests/error_name05.s
# sh /Volumes/USB/.files/valgrind/vg-in-place --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm tests/error_name05.s
echo "\n\033[41m\033[1m ---> ./asm tests/error_name06.s (.name \"name\"\")\033[0m"
./asm tests/error_name06.s
# sh /Volumes/USB/.files/valgrind/vg-in-place --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm tests/error_name06.s
echo "\n\033[41m\033[1m ---> ./asm tests/error_name07.s (.name \"name)\033[0m"
./asm tests/error_name07.s
# sh /Volumes/USB/.files/valgrind/vg-in-place --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm tests/error_name07.s
echo "\n\033[41m\033[1m ---> ./asm tests/error_name08.s (.name name)\033[0m"
./asm tests/error_name08.s
# sh /Volumes/USB/.files/valgrind/vg-in-place --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm tests/error_name08.s
echo "\n\033[41m\033[1m ---> ./asm tests/error_name09.s (.name \"name\" ,)\033[0m"
./asm tests/error_name09.s
# sh /Volumes/USB/.files/valgrind/vg-in-place --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm tests/error_name09.s
echo "\n\033[41m\033[1m ---> ./asm tests/error_name10.s (.name \"name\" 	o)\033[0m"
./asm tests/error_name10.s
# sh /Volumes/USB/.files/valgrind/vg-in-place --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm tests/error_name10.s
echo "\n\033[41m\033[1m ---> ./asm tests/error_name11.s (.name o \"name\")\033[0m"
./asm tests/error_name11.s
# sh /Volumes/USB/.files/valgrind/vg-in-place --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm tests/error_name11.s
echo "\n\033[41m\033[1m ---> ./asm tests/error_name12.s (.name , \"name\")\033[0m"
./asm tests/error_name12.s
# sh /Volumes/USB/.files/valgrind/vg-in-place --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm tests/error_name12.s
echo "\n\033[41m\033[1m ---> ./asm tests/error_name13.s (.name name\")\033[0m"
./asm tests/error_name13.s
# sh /Volumes/USB/.files/valgrind/vg-in-place --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm tests/error_name13.s
echo "\n\033[41m\033[1m ---> ./asm tests/error_name14.s (.name \"\" \"name\")\033[0m"
./asm tests/error_name14.s
# sh /Volumes/USB/.files/valgrind/vg-in-place --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm tests/error_name14.s
echo "\n\033[41m\033[1m ---> ./asm tests/error_name15.s (.name \"\"name\")\033[0m"
./asm tests/error_name15.s
# sh /Volumes/USB/.files/valgrind/vg-in-place --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm tests/error_name15.s

echo "\n\033[42m\033[1m ---> ./asm tests/valid_strange_name00.s (.name "''")\033[0m"
./asm tests/valid_strange_name00.s
# sh /Volumes/USB/.files/valgrind/vg-in-place --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm tests/valid_strange_name00.s

# ---------------------------------------------------------------------------- #
# echo "\n\n\033[44m\033[1mTEST HEX VALUE\033[0m"
# echo "\n\033[42m\033[1m ---> ./asm ../champions/42.s\033[0m => \033[45m\033[1m 3dd \033[0m"
# ./asm ../champions/42.s
# echo "\n\033[42m\033[1m ---> ./asm ../champions/Backward.s\033[0m => \033[45m\033[1m 34 \033[0m"
# ./asm ../champions/Backward.s
# echo "\n\033[42m\033[1m ---> ./asm ../champions/Car.s\033[0m => \033[45m\033[1m 119 \033[0m"
# ./asm ../champions/Car.s
# echo "\n\033[42m\033[1m ---> ./asm ../champions/Death.s\033[0m => \033[45m\033[1m a8 \033[0m"
# ./asm ../champions/Death.s
# echo "\n\033[42m\033[1m ---> ./asm ../champions/Gagnant.s\033[0m => \033[45m\033[1m 145 \033[0m"
# ./asm ../champions/Gagnant.s
# echo "\n\033[42m\033[1m ---> ./asm ../champions/Octobre_Rouge_V4.2.s\033[0m => \033[45m\033[1m 261 \033[0m"
# ./asm ../champions/Octobre_Rouge_V4.2.s
# echo "\n\033[42m\033[1m ---> ./asm ../champions/Survivor.s\033[0m => \033[45m\033[1m 27 \033[0m"
# ./asm ../champions/Survivor.s
# echo "\n\033[42m\033[1m ---> ./asm ../champions/Torpille.s\033[0m => \033[45m\033[1m 96 \033[0m"
# ./asm ../champions/Torpille.s
# echo "\n\033[42m\033[1m ---> ./asm ../champions/barriere.s\033[0m => \033[45m\033[1m 3ff \033[0m"
# ./asm ../champions/barriere.s
# echo "\n\033[42m\033[1m ---> ./asm ../champions/ex.s\033[0m => \033[45m\033[1m 17 \033[0m"
# ./asm ../champions/ex.s
# echo "\n\033[42m\033[1m ---> ./asm ../champions/jumper.s\033[0m => \033[45m\033[1m 140 \033[0m"
# ./asm ../champions/jumper.s
# echo "\n\033[42m\033[1m ---> ./asm ../champions/lde.s\033[0m => \033[45m\033[1m 341 \033[0m"
# ./asm ../champions/lde.s
# echo "\n\033[42m\033[1m ---> ./asm ../champions/leeloo.s\033[0m => \033[45m\033[1m 385 \033[0m"
# ./asm ../champions/leeloo.s
# echo "\n\033[42m\033[1m ---> ./asm ../champions/mat.s\033[0m => \033[45m\033[1m 387 \033[0m"
# ./asm ../champions/mat.s
# echo "\n\033[42m\033[1m ---> ./asm ../champions/maxidef.s\033[0m => \033[45m\033[1m 12d \033[0m"
# ./asm ../champions/maxidef.s
# echo "\n\033[42m\033[1m ---> ./asm ../champions/mortel.s\033[0m => \033[45m\033[1m ee \033[0m"
# ./asm ../champions/mortel.s
# echo "\n\033[42m\033[1m ---> ./asm ../champions/new.s\033[0m => \033[45m\033[1m 38c \033[0m"
# ./asm ../champions/new.s
# echo "\n\033[42m\033[1m ---> ./asm ../champions/slider2.s\033[0m => \033[45m\033[1m 240 \033[0m"
# ./asm ../champions/slider2.s
# echo "\n\033[42m\033[1m ---> ./asm ../champions/tdc2.s\033[0m => \033[45m\033[1m c3 \033[0m"
# ./asm ../champions/tdc2.s
# echo "\n\033[42m\033[1m ---> ./asm ../champions/tdc3.s\033[0m => \033[45m\033[1m 74 \033[0m"
# ./asm ../champions/tdc3.s
# echo "\n\033[42m\033[1m ---> ./asm ../champions/tdc4.s\033[0m => \033[45m\033[1m 4c \033[0m"
# ./asm ../champions/tdc4.s
# echo "\n\033[42m\033[1m ---> ./asm ../champions/toto.s\033[0m => \033[45m\033[1m 145 \033[0m"
# ./asm ../champions/toto.s
