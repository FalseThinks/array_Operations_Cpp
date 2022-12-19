//@author:paproka
#ifndef __NODE_H_
#define __NODE_H_
typedef struct Node *LinkedList;
typedef struct Node *Stack;
    struct Node{
        char letter;
        int ocurrences;
        LinkedList next;
        Stack nextS;
    };

#endif