testmake: SortedList.cpp fileListFunctions.cpp testSortedList.cpp
	g++ SortedList.cpp fileListFunctions.cpp testSortedList.cpp -o testmake -I.