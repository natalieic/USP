#ifndef STACK_H
    #define STACK_H
    #include "../item/item.h"

    #define MAXSIZE 1000

    typedef struct stack_ stack;

    stack* newstack(void);
    void delstack(**stack s);
    bool stacking(item* item, stack* s);
    item* unstack(stack* s);
    item* stacktop(stack* s);
    bool stackempty(stack* s);
    bool stackfull(stack* s);
    int stacksize(stack* s);
    void stackprint(stack* s);
    bool stackrev(stack* s);
    
#endif