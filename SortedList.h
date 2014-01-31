//
//  SortedList.h
//
//
//  Created by Eric Walsh on 1/30/14.
//
//
#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;


#ifndef ____ListNode__
#define ____ListNode__

class ListNode{

public:
    string info;
    ListNode * next;
    ListNode();
    ListNode(string inp);
    ListNode(string inp, ListNode * target);
    ~ListNode();
    bool operator == (const ListNode &s) const;
    void print();
};

#endif // list_node


#ifndef ____SortedArrayList__
#define ____SortedArrayList__

class SortedArrayList{

private:
    string * buf;
    int capacity=45500, size=0;
public:
    SortedArrayList();
    SortedArrayList(int cap);
    ~SortedArrayList();
    void insert(string word);
    bool find(string word);
    void remove(string word);
    void crunchDown(int inp);
    void crunchUp(int inp, string word);
    void print();
    bool isEmpty();
    bool isFull();

};


#endif /* defined(____SortedArrayList__) */


#ifndef ____SortedLinkedList__
#define ____SortedLinkedList__

class SortedLinkedList{

private:
    ListNode * head;
public:
    SortedLinkedList();
    SortedLinkedList(ListNode * inp);
    ~SortedLinkedList();
    void insert(string word);
    bool find(string word);
    void remove(string word);
    void print();
    bool isEmpty();
    bool isFull();

};


#endif /* defined(____SortedLinkedList__) */
