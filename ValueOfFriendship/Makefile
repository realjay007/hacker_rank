create_case.exe: create_case.c
	gcc create_case.c -o create_case
	create_case > in.txt

sol.exe: sol.cpp
	g++ sol.cpp -o sol -std=c++11

sol: sol.exe create_case.exe
	sol < in.txt > out.txt