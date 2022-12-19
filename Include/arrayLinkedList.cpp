#include "arrayLinkedList.hpp"
#include <iostream>

    //To Lower Case
    char LC(char x){
        return (char) tolower(x);
    }

    //Basic Operations
    int isEmptyL(LinkedList list){
        return list==NULL;
    }

    void printL(LinkedList list){
        LinkedList pointer;

        pointer = list;
        while(pointer!=NULL)
        {
            std::cout<<pointer->letter;
            pointer = pointer->next;
            if (pointer!=NULL)
                std::cout<<" -> ";
            fflush(stdout);
        }
        std::cout<<"\n";
        fflush(stdout);
    }

    void printL_Ocurrences(LinkedList list){
        LinkedList pointer;

        pointer = list;
        while(pointer!=NULL)
        {
            std::cout<<pointer->letter<<"("<<pointer->ocurrences<<")";
            pointer = pointer->next;
            if (pointer!=NULL)
                std::cout<<" -> ";
            fflush(stdout);
        }
        std::cout<<"\n";
        fflush(stdout);

    }

    int lookForLetters(LinkedList list,char l){
        int ocurrences=0;
        LinkedList pointer = list;
        while (pointer!=NULL){
            if (LC(pointer->letter)==LC(l))
                ocurrences++;
            pointer=pointer->next;
        }
        return ocurrences;
    }

    void addToList(LinkedList *list, char l){ //It will act like an Stack first, after that, we will move through it with deleteFromList and setOcurrences
        LinkedList node = (LinkedList)malloc(sizeof(struct Node));
        node->letter = l;
        node->ocurrences=1;
        node->next = nullptr;

        if (isEmptyL(*list))
            *list=node;
        else
            {
                node->next = *list;
                *list = node;
            }
    }

    void deleteFromList(LinkedList *list, char l){  //Deletes EVERY node that contains the specified letter
        LinkedList prev = NULL; //At start, prev is "before" list
        LinkedList current = *list; //List start

        while (LC((*list)-> letter)==LC(l)){ //If letter is at start
            (*list)=(*list)->next;
            free(current);
            current=*list; //If it is at start, it deletes first and now we need the new first value
            if ((*list==NULL))
                break;
        }

        if ((*list)!=NULL){
            
        LinkedList next = current->next; //Define after because we need new first value
            while (next!=NULL){
                while (LC(current->letter)==LC(l)){ //If letter is at end
                        
                        /*printL(*list);
                        std::cout<<"WHILE CURRENT LETTER: "<<current->letter<<"\n";

                        if (next!=NULL)
                            std::cout<<"NEXT LETTER: "<<next->letter<<"\n";*/

                        if (next==NULL) //Keeping it in safe access
                            break;    

                        prev->next=next;
                        free(current); //Prev to next node, and free current==letter
                        current=NULL;
                        if (LC(next->letter) == LC(l)){ //If there are more
                            current=next;
                            next=next->next;
                        }
                        else
                            break;
                }
                
                if (next!=NULL){    //Move through list
                    prev=current;
                    current=next;
                    next=next->next;
                }
                     
            }

            if (LC(current->letter)==LC(l)){ //If a letter remains at end
                    prev->next=NULL;
                    free(current);
                    current=NULL;
            }
        }
    }


    void clearList(LinkedList *list){ //It will delete all nodes, and then it will free the list
        std::cout<<"\nClearing list...";
        while(!isEmptyL(*list)){
            LinkedList aux = *list;
            *list = aux->next;
            free(aux);
        }
        if (isEmptyL(*list)) //Ensure, don't really needed
            free(*list);
        std::cout<<"\nList removed succesfully!\n";
    } 

    //Custom methods

    void linkedList_Insert(LinkedList *list, std::string word){
        int i=0;
        while (i<word.length()){
            addToList(list,word[i]);
            i++;
        }
    }

    void linkedList_sort(LinkedList *list){
        LinkedList sort = NULL;
        LinkedList aux = *list;
        while(aux!=NULL){
            std::string x;
            linkedList_Insert(&sort,(x=aux->letter));
            aux=aux->next;
        }
        *list = sort;
    }

    void linkedList_setOcurrences(LinkedList *list){
        LinkedList aux = *list;
        while (aux!=NULL){
            char x=aux->letter;
            aux->ocurrences=lookForLetters(aux,x);
            if (aux->ocurrences>1)
                deleteFromList(&aux->next,x);
            aux=aux->next;
        }
    }

    