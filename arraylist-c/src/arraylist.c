#include "arraylist.h"
#include <stdlib.h>
#include <string.h>

#define AL_INITIAL_CAP 8

static bool al_grow(ArrayList *al, size_t min_capacity) {
    if (al->capacity >= min_capacity) return true;
    size_t new_cap = al->capacity ? al->capacity : AL_INITIAL_CAP;
    while (new_cap < min_capacity) new_cap *= 2;

    void *new_data = realloc(al->data, new_cap * al->elem_size);
    if (!new_data) return false;

    al->data = new_data;
    al->capacity = new_cap;
    return true;
}

ArrayList *al_create(size_t elem_size) {
    if (!elem_size) return NULL;
    ArrayList *al = (ArrayList*)calloc(1, sizeof(ArrayList));
    if (!al) return NULL;
    al->elem_size = elem_size;
    al->capacity  = 0;
    al->size      = 0;
    al->data      = NULL;
    return al;
}

void al_destroy(ArrayList *al) {
    if (!al) return;
    free(al->data);
    free(al);
}

bool al_reserve(ArrayList *al, size_t new_capacity) {
    if (!al) return false;
    return al_grow(al, new_capacity);
}

size_t al_size(const ArrayList *al) {
    return al ? al->size : 0;
}

bool al_add(ArrayList *al, const void *item) {
    if (!al || !item) return false;
    if (!al_grow(al, al->size + 1)) return false;
    void *dst = (char*)al->data + al->size * al->elem_size;
    memcpy(dst, item, al->elem_size);
    al->size += 1;
    return true;
}

bool al_insert(ArrayList *al, size_t index, const void *item) {
    if (!al || !item) return false;
    if (index > al->size) return false; 

    void *base = al->data;
    void *pos  = (char*)base + index * al->elem_size;
  
    memmove((char*)pos + al->elem_size, pos, (al->size - index) * al->elem_size);
    memcpy(pos, item, al->elem_size);
    al->size += 1;
    return true;
}

bool al_remove(ArrayList *al, size_t index) {
    if (!al || index >= al->size) return false;
    void *base = al->data;
    void *pos  = (char*)base + index * al->elem_size;
   
    memmove(pos, (char*)pos + al->elem_size, (al->size - index - 1) * al->elem_size);
    al->size -= 1;
    return true;
}

bool al_set(ArrayList *al, size_t index, const void *item) {
    if (!al || !item || index >= al->size) return false;
    void *dst = (char*)al->data + index * al->elem_size;
    memcpy(dst, item, al->elem_size);
    return true;
}

bool al_get(const ArrayList *al, size_t index, void *out) {
    if (!al || !out || index >= al->size) return false;
    const void *src = (const char*)al->data + index * al->elem_size;
    memcpy(out, src, al->elem_size);
    return true;
}

void al_clear(ArrayList *al) {
    if (!al) return;
    al->size = 0;
}
