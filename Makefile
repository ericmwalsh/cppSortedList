testmake: SortedList.cpp fileListFunctions.cpp testSortedList.cpp
	gcc -o testmake SortedList.cpp fileListFunctions.cpp testSortedList.cpp -I.