COMPILER = g++
FLAG = -std=c++23
# note i didn't add -c into the FLAG variable because it's not universal

main.out: dones.o todos.o tutils.o main.o
	${COMPILER} ${FLAG} $^ -o $@

dones.o: dones.cpp
	${COMPILER} -c ${FLAG} $^ -o $@

todos.o: todos.cpp
	${COMPILER} -c ${FLAG} $^ -o $@

tutils.o: tutils.cpp
	${COMPILER} -c ${FLAG} $^ -o $@

main.o: main.cpp
	${COMPILER} -c ${FLAG} $^ -o $@

