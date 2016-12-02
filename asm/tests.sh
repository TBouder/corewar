rm ../champions/*.cor

./asm ../champions/Backward.s
./asm ../champions/Car.s
./asm ../champions/Death.s
./asm ../champions/Gagnant.s
./asm ../champions/Octobre_Rouge_V4.2.s
./asm ../champions/Survivor.s
# ./asm ../champions/Torpille.s
./asm ../champions/barriere.s
./asm ../champions/ex.s
./asm ../champions/jumper.s
./asm ../champions/lde.s
./asm ../champions/leeloo.s
./asm ../champions/mat.s
./asm ../champions/maxidef.s
./asm ../champions/mortel.s
./asm ../champions/new.s
./asm ../champions/octobre_rouge2.s
./asm ../champions/slider2.s
./asm ../champions/tdc2.s
./asm ../champions/tdc3.s
./asm ../champions/tdc4.s
./asm ../champions/test.s
./asm ../champions/toto.s
./asm ../champions/valid.s

../corewar-exemple/asm ../champions_o/Backward.s
../corewar-exemple/asm ../champions_o/Car.s
../corewar-exemple/asm ../champions_o/Death.s
../corewar-exemple/asm ../champions_o/Gagnant.s
../corewar-exemple/asm ../champions_o/Octobre_Rouge_V4.2.s
../corewar-exemple/asm ../champions_o/Survivor.s
# ../corewar-exemple/asm ../champions_o/Torpille.s
../corewar-exemple/asm ../champions_o/barriere.s
../corewar-exemple/asm ../champions_o/ex.s
../corewar-exemple/asm ../champions_o/jumper.s
../corewar-exemple/asm ../champions_o/lde.s
../corewar-exemple/asm ../champions_o/leeloo.s
../corewar-exemple/asm ../champions_o/mat.s
../corewar-exemple/asm ../champions_o/maxidef.s
../corewar-exemple/asm ../champions_o/mortel.s
../corewar-exemple/asm ../champions_o/new.s
../corewar-exemple/asm ../champions_o/octobre_rouge2.s
../corewar-exemple/asm ../champions_o/slider2.s
../corewar-exemple/asm ../champions_o/tdc2.s
../corewar-exemple/asm ../champions_o/tdc3.s
../corewar-exemple/asm ../champions_o/tdc4.s
../corewar-exemple/asm ../champions_o/test.s
../corewar-exemple/asm ../champions_o/toto.s
# ../corewar-exemple/asm ../champions_o/valid.s

diff ../champions/Backward.cor ../champions_o/Backward.cor
diff ../champions/Car.cor ../champions_o/Car.cor
diff ../champions/Death.cor ../champions_o/Death.cor
diff ../champions/Gagnant.cor ../champions_o/Gagnant.cor
diff ../champions/Octobre_Rouge_V4.2.cor ../champions_o/Octobre_Rouge_V4.2.cor
diff ../champions/Survivor.cor ../champions_o/Survivor.cor
diff ../champions/barriere.cor ../champions_o/barriere.cor
diff ../champions/ex.cor ../champions_o/ex.cor
diff ../champions/jumper.cor ../champions_o/jumper.cor
diff ../champions/lde.cor ../champions_o/lde.cor
diff ../champions/leeloo.cor ../champions_o/leeloo.cor
diff ../champions/mat.cor ../champions_o/mat.cor
diff ../champions/maxidef.cor ../champions_o/maxidef.cor
diff ../champions/mortel.cor ../champions_o/mortel.cor
diff ../champions/new.cor ../champions_o/new.cor
diff ../champions/octobre_rouge2.cor ../champions_o/octobre_rouge2.cor
diff ../champions/slider2.cor ../champions_o/slider2.cor
diff ../champions/tdc2.cor ../champions_o/tdc2.cor
diff ../champions/tdc3.cor ../champions_o/tdc3.cor
diff ../champions/tdc4.cor ../champions_o/tdc4.cor
diff ../champions/test.cor ../champions_o/test.cor
diff ../champions/toto.cor ../champions_o/toto.cor
# diff ../champions/valid.cor ../champions_o/valid.cor

# echo "\n\033[42m\033[1m ---> ./asm tests/valid_strange_name00.s (.name "''")\033[0m"
# # ./asm tests/valid_strange_name00.s
# sh /Volumes/USB/.files/valgrind/vg-in-place --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm tests/valid_strange_name00.s

# # ---------------------------------------------------------------------------- #
# echo "\n\n\033[44m\033[1mTEST HEX VALUE\033[0m"
# echo "\n\033[42m\033[1m ---> ./asm ../champions/42.s\033[0m => \033[45m\033[1m 3dd \033[0m"
# sh /Volumes/USB/.files/valgrind/vg-in-place --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm ../champions/42.s
# echo "\n\033[42m\033[1m ---> ./asm ../champions/Backward.s\033[0m => \033[45m\033[1m 34 \033[0m"
# sh /Volumes/USB/.files/valgrind/vg-in-place --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm ../champions/Backward.s
# echo "\n\033[42m\033[1m ---> ./asm ../champions/Car.s\033[0m => \033[45m\033[1m 119 \033[0m"
# sh /Volumes/USB/.files/valgrind/vg-in-place --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm ../champions/Car.s
# echo "\n\033[42m\033[1m ---> ./asm ../champions/Death.s\033[0m => \033[45m\033[1m a8 \033[0m"
# sh /Volumes/USB/.files/valgrind/vg-in-place --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm ../champions/Death.s
# echo "\n\033[42m\033[1m ---> ./asm ../champions/Gagnant.s\033[0m => \033[45m\033[1m 145 \033[0m"
# sh /Volumes/USB/.files/valgrind/vg-in-place --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm ../champions/Gagnant.s
# echo "\n\033[42m\033[1m ---> ./asm ../champions/Octobre_Rouge_V4.2.s\033[0m => \033[45m\033[1m 261 \033[0m"
# sh /Volumes/USB/.files/valgrind/vg-in-place --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm ../champions/Octobre_Rouge_V4.2.s
# echo "\n\033[42m\033[1m ---> ./asm ../champions/Survivor.s\033[0m => \033[45m\033[1m 27 \033[0m"
# sh /Volumes/USB/.files/valgrind/vg-in-place --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm ../champions/Survivor.s
# echo "\n\033[42m\033[1m ---> ./asm ../champions/Torpille.s\033[0m => \033[45m\033[1m 96 \033[0m"
# sh /Volumes/USB/.files/valgrind/vg-in-place --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm ../champions/Torpille.s
# echo "\n\033[42m\033[1m ---> ./asm ../champions/barriere.s\033[0m => \033[45m\033[1m 3ff \033[0m"
# sh /Volumes/USB/.files/valgrind/vg-in-place --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm ../champions/barriere.s
# echo "\n\033[42m\033[1m ---> ./asm ../champions/ex.s\033[0m => \033[45m\033[1m 17 \033[0m"
# sh /Volumes/USB/.files/valgrind/vg-in-place --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm ../champions/ex.s
# echo "\n\033[42m\033[1m ---> ./asm ../champions/jumper.s\033[0m => \033[45m\033[1m 140 \033[0m"
# sh /Volumes/USB/.files/valgrind/vg-in-place --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm ../champions/jumper.s
# echo "\n\033[42m\033[1m ---> ./asm ../champions/lde.s\033[0m => \033[45m\033[1m 341 \033[0m"
# sh /Volumes/USB/.files/valgrind/vg-in-place --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm ../champions/lde.s
# echo "\n\033[42m\033[1m ---> ./asm ../champions/leeloo.s\033[0m => \033[45m\033[1m 385 \033[0m"
# sh /Volumes/USB/.files/valgrind/vg-in-place --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm ../champions/leeloo.s
# echo "\n\033[42m\033[1m ---> ./asm ../champions/mat.s\033[0m => \033[45m\033[1m 387 \033[0m"
# sh /Volumes/USB/.files/valgrind/vg-in-place --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm ../champions/mat.s
# echo "\n\033[42m\033[1m ---> ./asm ../champions/maxidef.s\033[0m => \033[45m\033[1m 12d \033[0m"
# sh /Volumes/USB/.files/valgrind/vg-in-place --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm ../champions/maxidef.s
# echo "\n\033[42m\033[1m ---> ./asm ../champions/mortel.s\033[0m => \033[45m\033[1m ee \033[0m"
# sh /Volumes/USB/.files/valgrind/vg-in-place --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm ../champions/mortel.s
# echo "\n\033[42m\033[1m ---> ./asm ../champions/new.s\033[0m => \033[45m\033[1m 38c \033[0m"
# sh /Volumes/USB/.files/valgrind/vg-in-place --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm ../champions/new.s
# echo "\n\033[42m\033[1m ---> ./asm ../champions/slider2.s\033[0m => \033[45m\033[1m 240 \033[0m"
# sh /Volumes/USB/.files/valgrind/vg-in-place --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm ../champions/slider2.s
# echo "\n\033[42m\033[1m ---> ./asm ../champions/tdc2.s\033[0m => \033[45m\033[1m c3 \033[0m"
# sh /Volumes/USB/.files/valgrind/vg-in-place --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm ../champions/tdc2.s
# echo "\n\033[42m\033[1m ---> ./asm ../champions/tdc3.s\033[0m => \033[45m\033[1m 74 \033[0m"
# sh /Volumes/USB/.files/valgrind/vg-in-place --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm ../champions/tdc3.s
# echo "\n\033[42m\033[1m ---> ./asm ../champions/tdc4.s\033[0m => \033[45m\033[1m 4c \033[0m"
# sh /Volumes/USB/.files/valgrind/vg-in-place --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm ../champions/tdc4.s
# echo "\n\033[42m\033[1m ---> ./asm ../champions/toto.s\033[0m => \033[45m\033[1m 145 \033[0m"
# sh /Volumes/USB/.files/valgrind/vg-in-place --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --show-leak-kinds=all -q ./asm ../champions/toto.s
