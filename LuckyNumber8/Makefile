create_case.exe: create_case.c
	gcc create_case.c -o create_case && create_case > in.txt

sol.exe: sol.c
	gcc sol.c -o sol

sol2.exe: sol2.c
	gcc sol2.c -o sol2

sol: sol.exe create_case.exe
	sol < in.txt > out.txt

sol2: sol2.exe create_case.exe
	sol2 < in.txt > out.txt