main : main.o RandomSampling.o Utils.o RandomizedQuickSort.o RandomizedSelect.o Queens.o PollardRho.o
	g++ -o main main.o RandomSampling.o Utils.o RandomizedQuickSort.o RandomizedSelect.o Queens.o PollardRho.o
main.o : main.cpp liushuo.h
	g++ -c main.cpp
RandomSampling.o : RandomSampling.cpp liushuo.h
	g++ -c RandomSampling.cpp
Utils.o : Utils.cpp liushuo.h
	g++ -c Utils.cpp
RandomizedQuickSort.o : RandomizedQuickSort.cpp liushuo.h
	g++ -c RandomizedQuickSort.cpp
RandomizedSelect.o : RandomizedSelect.cpp liushuo.h
	g++ -c RandomizedSelect.cpp
Queens.o : Queens.cpp liushuo.h
	g++ -c Queens.cpp
PollardRho.o : PollardRho.cpp liushuo.h
	g++ -c PollardRho.cpp
