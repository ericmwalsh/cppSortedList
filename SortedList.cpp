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

//O(1)
SortedArrayList::SortedArrayList(){
    buf = new string[capacity];
}
//O(1)
SortedArrayList::SortedArrayList(int cap){
    buf = new string[cap];
    capacity = cap;
}
//O(1)
SortedArrayList::~SortedArrayList(){
    delete buf;
}
//O(N) (with crunchUp included, still an O(N))
void SortedArrayList::insert(string word){
    if(!isFull()){
        int count =0;
        while(buf[count]!= "" && word>buf[count]) count++;
        if(count == size) buf[size++] = word;
        else crunchUp(count, word);
    }
}
//Helper method for insert - O(N)
void SortedArrayList::crunchUp(int inp, string word){
    for(int i = size; i>inp; --i) buf[i]=buf[i-1];
    buf[inp]=word;
    size++;
}
//O(N)
bool SortedArrayList::find(string word){
    if(isEmpty()) return false;
    else{
        for(int i=0; i<size; i++) if(buf[i]==word) return true;
        return false;
    }
}
//O(N) (with crunchDown included, still an O(N))
void SortedArrayList::remove(string word){
    if(!isEmpty())
        for(int i=0; i<size; i++)
            if(buf[i]==word){
                crunchDown(i);
                break;
            }
}
//Helper method for remove - O(N)
void SortedArrayList::crunchDown(int inp){
    for(int i=inp; i<size-1; i++) buf[i]=buf[i+1];
    --size;
}
//O(N)
void SortedArrayList::print(){
    for(int i=0; i<size; i++) cout << buf[i] << endl;
}
//O(1)
bool SortedArrayList::isEmpty(){
    return size==0;
}
//O(1)
bool SortedArrayList::isFull(){
    return size==capacity;
}

//SortedLinkedList Class


//O(1)
SortedLinkedList::SortedLinkedList(){
    head = NULL;
}
//O(1)
SortedLinkedList::SortedLinkedList(ListNode * inp){
    head = inp;
}
//O(1)
bool SortedLinkedList::isEmpty(){
    return head==NULL;
}
//O(1)
bool SortedLinkedList::isFull(){
    return false;
}
//O(N)- actual insertion is O(1) but searching causes it to be O(N)
void SortedLinkedList::insert(string word){
    ListNode * i = head;
    if(isEmpty()) head = new ListNode(word);
    else{
        while(i->next && word>i->info) i=i->next;
        if(word<i->info){
            i->next = new ListNode(i->info, i->next);
            i->info = word;
        }
        else i->next = new ListNode(word);
    }
}
//O(N)
bool SortedLinkedList::find(string word){
    if(!isEmpty()){
        for(ListNode * i = head; i; i=i->next) if(i->info==word) return true;
        return false;
    }
}
//O(N) - actual removal is O(1) but searching causes it to be O(N)
void SortedLinkedList::remove(string word){
    if(!isEmpty()){
        for(ListNode * i = head, *j = head; i; i=i->next){
            //cout << i->info << " HAHA" << endl;
            if(i->info==word){
                if(i->next==NULL){
                    if(i==head) head = NULL;

                    else j->next=NULL;
                }
                else{
                    i->info= i->next->info;
                    i->next= i->next->next;
                    break;
                }
            }
            if(i->next!=NULL && i->next->next!=NULL) j=j->next;
        }
    }
}
//O(N)
void SortedLinkedList::print(){
    for(ListNode * i = head; i; i=i->next) cout << i->info << endl;
}
//O(1)
SortedLinkedList::~SortedLinkedList(){
    delete head;
}
/**
int main(){
    return 0;
}
**/