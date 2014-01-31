//
//  testSortedList.cpp
//
//
//  Created by Eric Walsh on 1/30/14.
//
//

//#include "fileListFunctions.cpp"

void testSAL(){
    SortedArrayList * a = new SortedArrayList();
    a->insert("zxc");
    a->insert("cat");
    a->insert("dog");
    a->insert("sup");
    a->insert("mom");
    a->insert("apple");
    a->insert("moma");

    a->print();
    cout << endl << "AFTER REMOVALS:" << endl << endl;
    a->remove("moma");
    a->remove("zxc");
    a->remove("dog");
    a->remove("apple");
    a->remove("sup");
    a->remove("mom");
    a->remove("cat");
    a->remove("hey");
    a->print();
    a->insert("moma");

    cout << endl << "AFTER INSERTS:" << endl << endl;
    a->print();

}
void testSLL(){
    SortedLinkedList * a = new SortedLinkedList();
    a->insert("zxc");
    a->insert("cat");
    a->insert("dog");
    a->insert("sup");
    a->insert("mom");
    a->insert("apple");
    a->insert("moma");
    a->insert("zz");
    a->print();
    cout << endl << endl << "REMOVED AFTER THIS :" << endl << endl;
    a->remove("dog");
    a->remove("apple");
    a->remove("sup");
    a->print();
}
int main(int argc, const char * argv[])
{
    cout << "Beginning the testing with SortedArrayList..." << endl << endl;
    SortedArrayList * a = new SortedArrayList();
    insertAllWords("random.txt", a);
    cout << "WERE ALL WORDS FOUND?: " << findAllWords("words.txt", a) << endl;
    removeAllWords("random.txt", a);

    cout << endl << endl << "Beginning the testing with SortedLinkedList..." << endl << endl;
    SortedLinkedList * b = new SortedLinkedList();
    b->insert("zygote");
    insertAllWords("random.txt", b);
    cout << "WERE ALL WORDS FOUND?: " << findAllWords("words.txt", b) << endl;
    removeAllWords("random.txt", b);


    return 0;
}
