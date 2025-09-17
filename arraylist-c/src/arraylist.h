#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <stddef.h>
#include <stdbool.h>

typedef struct {
    void   *data;     
    size_t  size;      
    size_t  capacity;   
    size_t  elem_size;  
} ArrayList;


ArrayList *al_create(size_t elem_size);
void       al_destroy(ArrayList *al);


bool   al_add(ArrayList *al, const void *item);                
bool   al_insert(ArrayList *al, size_t index, const void *item);
size_t al_size(const ArrayList *al);                           
bool   al_remove(ArrayList *al, size_t index);                  
bool   al_set(ArrayList *al, size_t index, const void *item);    
bool   al_get(const ArrayList *al, size_t index, void *out);    


void   al_clear(ArrayList *al);
bool   al_reserve(ArrayList *al, size_t new_capacity);

#endif 
