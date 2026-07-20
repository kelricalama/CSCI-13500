#include "linkedlist.hpp"

int main(){

    LinkedList list;

    list.InsertNode(10);
    list.InsertNode(20);
    list.InsertNodeFront(5);

    list.PrintValues();

}