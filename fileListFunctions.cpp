//
//  fileListFunctions.cpp
//
//
//  Created by Eric Walsh on 1/30/14.
//
//

//#include "SortedList.cpp"
#include "PCTimer.h"

void insertAllWords(char * fileName, SortedArrayList * inp){
    PCTimer t;
    t.start();
    std::ifstream infile(fileName);
    for( std::string line; getline( infile, line ); ){
        //this line converts all words into lowercase for easier conversion using the '>' symbol
        std::transform(line.begin(), line.end(), line.begin(), ::tolower);
        inp->insert(line);
    }
    infile.close();
    t.stop();
    cout << "SortedArrayList: Time to insertAllWords from " << fileName << ": " << t.elapsedTime() << " secs" << endl;
}
bool findAllWords(char * fileName, SortedArrayList * inp){
    PCTimer t;
    t.start();
    std::ifstream infile(fileName);
    for( std::string line; getline( infile, line ); ){
        //this line converts all words into lowercase for easier conversion using the '>' symbol
        std::transform(line.begin(), line.end(), line.begin(), ::tolower);
        if(!inp->find(line)) return false;
    }
    infile.close();
    t.stop();
    cout << "SortedArrayList: Time to findAllWords from " << fileName << ": " << t.elapsedTime() << " secs" << endl;
    return true;
}
void removeAllWords(char * fileName, SortedArrayList * inp){
    PCTimer t;
    t.start();
    std::ifstream infile(fileName);
    for( std::string line; getline( infile, line ); ){
        //this line converts all words into lowercase for easier conversion using the '>' symbol
        std::transform(line.begin(), line.end(), line.begin(), ::tolower);
        inp->remove(line);
    }
    infile.close();
    t.stop();
    cout << "SortedArrayList: Time to removeAllWords from " << fileName << ": " << t.elapsedTime() << " secs" << endl;
}
void insertAllWords(char * fileName, SortedLinkedList * inp){
    PCTimer t;
    t.start();
    std::ifstream infile(fileName);
    for( std::string line; getline( infile, line ); ){
        //this line converts all words into lowercase for easier conversion using the '>' symbol
        std::transform(line.begin(), line.end(), line.begin(), ::tolower);
        inp->insert(line);
    }
    infile.close();
    t.stop();
    cout << "SortedLinkedList: Time to insertAllWords from " << fileName << ": " << t.elapsedTime() << " secs" << endl;
}
bool findAllWords(char * fileName, SortedLinkedList * inp){
    PCTimer t;
    t.start();
    std::ifstream infile(fileName);
    for( std::string line; getline( infile, line ); ){
        //this line converts all words into lowercase for easier conversion using the '>' symbol
        std::transform(line.begin(), line.end(), line.begin(), ::tolower);
        if(!inp->find(line)) return false;
    }
    infile.close();
    t.stop();
    cout << "SortedLinkedList: Time to findAllWords from " << fileName << ": " << t.elapsedTime() << " secs" << endl;
    return true;
}
void removeAllWords(char * fileName, SortedLinkedList * inp){
    PCTimer t;
    t.start();
    std::ifstream infile(fileName);
    for( std::string line; getline( infile, line ); ){
        //this line converts all words into lowercase for easier conversion using the '>' symbol
        std::transform(line.begin(), line.end(), line.begin(), ::tolower);
        inp->remove(line);
    }
    infile.close();
    t.stop();
    cout << "SortedLinkedList: Time to removeAllWords from " << fileName << ": " << t.elapsedTime() << " secs" << endl;
}
