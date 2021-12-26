#include "vector.h"
#include <stdlib.h>
#include <string.h>

int vector_init(vector *vec)
{
    vec->size = 0;
    vec->capacity = VECTOR_INIT_ALLOCATED_SIZE;
    vec->items = malloc(sizeof(void *) * vec->capacity);
    if (!vec->items)
        return memory_error;

    return success;
}

/**
 * @brief Exponentially expands the capacity of `vec`.
 *
 * @param vec `vector` to operate on.
 */
void static inline vector_expand_allocated_size(vector *vec)
{
    vec->capacity = vec->capacity * VECTOR_EXPAND_EXPONENTIAL_FACTOR;
}

int vector_append(vector *vec, void *item)
{
    if (vec->size == vec->capacity)
    {
        vector_expand_allocated_size(vec);
        void **new_items = realloc(vec->items, sizeof(void *) * vec->capacity);
        if (!new_items)
            return memory_error;
        vec->items = new_items;
    }
    vec->items[vec->size] = item;
    vec->size++;

    return success;
}

int vector_remove(vector *vec, size_t index)
{
    if (vector_pop(vec, index) == (void*)index_out_of_range_error)
        return index_out_of_range_error;
    return success;
}

void* vector_pop(vector *vec, size_t index)
{
    if ((index < 0) | (index > vec->size - 1))
        return (void*)index_out_of_range_error;

    void** index_ptr = &vec->items[index];
    memcpy(index_ptr, index_ptr + 1, sizeof(void *) * (vec->size - index - 1));
    vec->items[vec->size - 1] = NULL;
    vec->size--;

    return index_ptr;
}