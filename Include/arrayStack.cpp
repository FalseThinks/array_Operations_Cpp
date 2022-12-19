//@author: paproka
#include "arrayStack.hpp"
#include <iostream>

    //Basic operations
    int isEmpty(Stack list){
        return list==NULL;
    }

    void push(Stack *list, char l){
        Stack node = (Stack)malloc(sizeof(struct Node)); //Memory allocation for Node
        node->letter = l;
        node->nextS = nullptr;

        if (isEmpty(*list))
            *list=node; //*list, refering to content. Without * is a single pointer to memory
        else{
                node->nextS = *list; //We cannot lose our reference. Otherwise, Stack will be removed
                *list = node; //Node is allocated at first
            }
    }

    void pop(Stack *list){
        if(!isEmpty(*list)){
            Stack node = *list;
            *list=node->nextS; //List moves to next node
            free(node); //Delete node
        }
    }

    void freeStack(Stack *list){ //Destroy list (only if empty)
        if (isEmpty(*list)){
            free(*list);
            std::cout<<"Stack removed succesfully!\n";
        }
        else
            std::cout<<"Stack still has elements!\n";
    }

    void printS(Stack stack){
        Stack pointer;

        pointer = stack;
        while(pointer!=NULL)
        {
            std::cout<<pointer->letter;
            pointer = pointer->nextS;
            fflush(stdout);
        }
        std::cout<<"\n";
        fflush(stdout);
    }


    //Custom methods

    void stack_Insert(Stack *stack, std::string word){      
        int i=0;
        while (i<word.length()){
            push(stack,word[i]);
            i++;
        }

        printS(*stack);
    }

    void stack_clear(Stack *stack){
        while(!isEmpty(*stack)){
            pop(stack);
        }

        std::cout<<"Clearing stack...\n";
    }

    Stack stack_sort(Stack stack){
        Stack sort = NULL;
        Stack aux = stack;
        while (aux !=NULL){
            push(&sort,aux->letter);
            aux=aux->nextS;
        }
        return sort;
    }
