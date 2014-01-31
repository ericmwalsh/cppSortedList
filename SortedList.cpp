//
//  SortedList.cpp
//
//
//  Created by Eric Walsh on 1/30/14.
//
//

#include "SortedList.h"

//ListNode for SortedLinkedList class
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

//SortedArrayList Class
SortedArrayList::SortedArrayList(){
    buf = new string[capacity];
}
SortedArrayList::SortedArrayList(int cap){
    buf = new string[cap];
    capacity = cap;
}
SortedArrayList::~SortedArrayList(){
    delete buf;
}
void SortedArrayList::insert(string word){
    if(!isFull()){
        int count =0;
        while(buf[count]!= "" && word>buf[count]) count++;
        if(count == size) buf[size++] = word;
        else crunchUp(count, word);
    }
}
//Helper method for insert
void SortedArrayList::crunchUp(int inp, string word){
    for(int i = size; i>inp; --i) buf[i]=buf[i-1];
    buf[inp]=word;
    size++;
}
bool SortedArrayList::find(string word){
    if(isEmpty()) return false;
    else{
        for(int i=0; i<size; i++) if(buf[i]==word) return true;
        return false;
    }
}
void SortedArrayList::remove(string word){
    if(!isEmpty())
        for(int i=0; i<size; i++)
            if(buf[i]==word){
                crunchDown(i);
                break;
            }
}
//Helper method for remove
void SortedArrayList::crunchDown(int inp){
    for(int i=inp; i<size-1; i++) buf[i]=buf[i+1];
    --size;
}
void SortedArrayList::print(){
    for(int i=0; i<size; i++) cout << buf[i] << endl;
}
bool SortedArrayList::isEmpty(){
    return size==0;
}
bool SortedArrayList::isFull(){
    return size==capacity;
}
