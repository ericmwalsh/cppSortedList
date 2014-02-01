::::::::::::::::::README::::::::::::::::::


Included files:
-SortedList.h
-SortedList.cpp (SOURCE CODE - implementation of ListNode and SortedList classes)
-PCTimer.h
-fileListFunctions.cpp (SOURCE CODE - implementation of insertAllWords/findAllWords/removeAllWords located here)
-testSortedList.cpp (misc test methods and int main() located here)

-makefile
-random.txt
-words.txt


The program inserts words from "random.txt", checks them against all the words in "words.txt", then removes all the words from "random.txt".

In order to compile, unzip and open a terminal in the directory.

Run make then run ./testmake

You should receive results like...



Erics-MacBook-Air-2:HW3 ericwalsh$ ./testmake
Beginning the testing with SortedArrayList...

SortedArrayList: Time to insertAllWords from random.txt: 43.6163 secs
WERE ALL WORDS FOUND?: SortedArrayList: Time to findAllWords from words.txt: 20.9951 secs
1
SortedArrayList: Time to removeAllWords from random.txt: 22.2048 secs


Beginning the testing with SortedLinkedList...

SortedLinkedList: Time to insertAllWords from random.txt: 26.7596 secs
WERE ALL WORDS FOUND?: SortedLinkedList: Time to findAllWords from words.txt: 28.2985 secs
1
SortedLinkedList: Time to removeAllWords from random.txt: 11.8437 secs