//
//  File.c
//
//
//  Created by Eric Walsh on 1/30/14.
//
//

#include "SortedList.cpp"


int main(int argc, const char * argv[])
{
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

    return 0;
}
