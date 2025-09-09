#ifndef ITEM_H
    #define ITEM_H
    #include <stdbool.h>
    
    typedef struct item_ item;

    item* newitem(void* value, int id);
    void delitem(item** item);
    bool itemsetval(item* item, void* value);
    void* itemgetval(item* item);
    bool itemsetid(item* item, int newid);
    int itemgetid(item* item);

#endif