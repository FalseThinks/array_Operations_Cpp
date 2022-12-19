//@author: paproka
#ifndef __arrayStack_hpp_
#define __arrayStack_hpp_

#include <node.h>
#include <iostream>

class arrayStack{
    public:

        //Basic operations
        void push(Stack *list, char l);
        void pop(Stack *list);
        void freeStack(Stack *list);
        int isEmpty(Stack list);
        void printS(Stack stack);

        //Custom methods
        void stack_Insert(Stack *stack, std::string word);
        void stack_clear(Stack *stack);
        Stack stack_sort(Stack *stack);
};

#endif