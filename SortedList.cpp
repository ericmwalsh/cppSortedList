//
//  SortedList.cpp
//  
//
//  Created by Eric Walsh on 1/30/14.
//
//

#include "SortedList.h"

//ListNode for 
ListNode::ListNode(){
    info = "";
    next = NULL;
}
ListNode::ListNode(string inp){
    info = inp;
    next = NULL;
}
ListNode::ListNode(string inp, ListNode * target){
    info = inp;
    next = target;
}
ListNode::~ListNode(){
    delete next;
}
bool ListNode::operator == (const ListNode &s) const{
    return info==s.info;
}
void ListNode::print(){
    cout << info << " ";
    if(next!=NULL) next->print();
}

SortedList::SortedList(){
}
SortedList::~SortedList(){
}



int defaultValue = 45500;

SortedArrayList::SortedArrayList(){
    buf = new string[defaultValue];
    capacity = defaultValue;
}
SortedArrayList::SortedArrayList(int cap){
    buf = new string[cap];
    capacity = cap;
}
SortedArrayList::~SortedArrayList(){
    
}
/**
void insert(string word);
bool find(string word);
void remove(string word);
bool isEmpty();
bool isFull();
**/