#ifndef __ARRAYLINKEDLIST_H_
#define __ARRAYLINKEDLIST_H_

#include <node.h>
#include <iostream>
class arrayLinkedList{
    public:
        //Basic operations
        void addToList(LinkedList *list, char l);
        void deleteFromList(LinkedList *list, char l);
        void clearList(LinkedList *list);
        int isEmptyL(LinkedList list);
        void printL(LinkedList list);
        void printL_Ocurrences(LinkedList list);

        //Custom methods
        void linkedList_Insert(LinkedList *list, std::string word);
        void linkedList_sort(LinkedList *list);
        void linkedList_setOcurrences(LinkedList *list);

    private:
        int lookForLetters(LinkedList list);
};

#endif