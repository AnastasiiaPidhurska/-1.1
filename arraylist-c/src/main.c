#include "arraylist.h"
#include <stdio.h>
#include <string.h>

typedef struct {
    int    id;
    char   name[32];
} Item;

static void test_ints() {
    printf("== Test: Ints ==\n");
    ArrayList *al = al_create(sizeof(int));

    for (int i = 1; i <= 5; ++i) al_add(al, &i); 
    int x = 99;
    al_insert(al, 2, &x);                        
    int y = -7;
    al_set(al, 0, &y);                          
    al_remove(al, al_size(al) - 1);             

    for (size_t i = 0; i < al_size(al); ++i) {
        int v; al_get(al, i, &v);
        printf("al[%zu] = %d\n", i, v);
    }

    al_destroy(al);
}

static void test_structs() {
    printf("\n== Test: Structs ==\n");
    ArrayList *al = al_create(sizeof(Item));

    Item a = {1, "Alice"};
    Item b = {2, "Bob"};
    Item c = {3, "Carol"};
    al_add(al, &a);
    al_add(al, &b);
    al_add(al, &c);

    Item d = {4, "Dave"};
    al_insert(al, 1, &d); 

 
    Item b2 = {22, "Bob+"};
    al_set(al, 2, &b2);


    for (size_t i = 0; i < al_size(al); ++i) {
        Item it;
        al_get(al, i, &it);
        printf("al[%zu] = {id=%d, name=%s}\n", i, it.id, it.name);
    }


    al_remove(al, 0); 

    printf("After remove(0), size=%zu\n", al_size(al));

    al_destroy(al);
}

int main(void) {
    test_ints();
    test_structs();
    return 0;
}
