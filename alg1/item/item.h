#ifndef ITEM_H
    #define ITEM_H
    #include <stdbool.h>
    
    typedef struct item_ ITEM;

    ITEM* item_criar(int id, void* value);
    bool item_apagar(ITEM** item);
    bool item_set_dados(ITEM* item, void* value);
    void* item_get_dados(ITEM* item);
    bool item_set_chave(ITEM* item, int newid);
    int item_get_chave(ITEM* item);

#endif