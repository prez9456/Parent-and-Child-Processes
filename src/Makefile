FILES = Starter.c Fibb.c Prime.c Total.c
OUT_EXE = Starter
OUT_FIB = Fibb
OUT_PRI = Prime
OUT_TOT = Total
PAK = README.txt Makefile
TAR_NAME = Andy-Donis_Paz-HW2.tar

build:
	gcc -o $(OUT_EXE) Starter.c
	gcc -o $(OUT_FIB) Fibb.c
	gcc -o $(OUT_PRI) Prime.c
	gcc -o $(OUT_TOT) Total.c
package:
	tar cvzf $(TAR_NAME) $(FILES) $(PAK)
clean:
	rm -f $(OUT_EXE) $(OUT_FIB) $(OUT_PRI) $(OUT_TOT)