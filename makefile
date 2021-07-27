FLAGS = -std=c++11 -O3

FILES =MPSmain.cpp parser.cpp MPS.cpp MPS.h

MPS : $(FILES) 
	g++ $(FLAGS) $(FILES) -lm -o MPS

clean :
	rm MPS