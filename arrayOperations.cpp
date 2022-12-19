//@author: paproka
#include "arrayStack.cpp"
#include "arrayLinkedList.cpp"
#include <cstring>

void clear(){
    for (int i=0; i<3; i++){
        std::cout<<"\n";
    }
}

int main(void){

    //Define variables
    Stack stack = NULL;
    LinkedList list = NULL;
    char toString[40];

    //Get our input, and transform it to string
    std::cout<<"Insert array: ";
    std::cin.getline(toString,40);
    std::string word (toString);

    /*
    ->Create an Stack and insert a String.
        -The string will be reverse, for "FIFO" Stack policy.

    ->Sort stack like original String.

    ->Delete the Stack and clear it.
        -It can be deleted directly (with pops until end, and then free the stack)
    */
    std::cout<<"\nSTACK\n";

    //push array to stack
    std::cout<<"---INSERT---\n";
    stack_Insert(&stack, word);

    //sort stack
    std::cout<<"\n---SORT---\n";
    stack = stack_sort(stack);
    printS(stack); 
    std::cout<<"\n";

    //pop array from stack
    stack_clear(&stack);

    //delete stack
    freeStack(&stack);

    //----------------------------------------------------------------------------------------------------------------------//

    clear();

    //----------------------------------------------------------------------------------------------------------------------//
    
    /*
    ->Creates a LinkedList and insert a String
        -It works like Stack's function

    ->Sort LinkedList like original String

    ->Set Ocurrences of all letters, and delete extra letters
        -It is the hardest step

    -> Deletes entirely LinkedList and frees memory
    */

    std::cout<<"LINKED LIST\n";

    //Insert array into LinkedList
    std::cout<<"--Insert--\n";
    linkedList_Insert(&list,word);
    printL(list);

    //Sorts LinkedList
    std::cout<<"\n--Sort--\n";
    linkedList_sort(&list);
    printL(list);

    //Set ocurrences and delete elements
    std::cout<<"\n--Ocurrences-\n";
    linkedList_setOcurrences(&list);
    printL_Ocurrences(list);

    //Clear list
    clearList(&list);

}
/*Things to know about:
    1. Space is considered a character
    2. With LC function, we can compare letters without worrying about their ("size?") [lowCase or upperCase]
        2.5 If it finds a lowCase first, it will appear when printing. Otherwise, an upperCase will appear instead.
    3. Sorry for using breaks.
*/