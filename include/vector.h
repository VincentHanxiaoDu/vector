#pragma once
#include <stdlib.h>

/* Definition of constants. */
#define VECTOR_INIT_ALLOCATED_SIZE 4
#define VECTOR_EXPAND_EXPONENTIAL_FACTOR 2

/**
 * @brief  Dynamic vector.
 */
typedef struct vector
{
    size_t size;     // size of vector
    size_t capacity; // capacity of vector
    void **items;    // pointer of the pointer of first element
} vector;

/**
 * @brief  Status codes.
 */
enum status_code
{
    success = 0,
    memory_error = -1,
    index_out_of_range_error = -2
};

/**
 * @brief Initializes `vec`.
 *
 * @param *vec `vector` to be initialized.
 * @retval int Status code defined by `status_code`.
 */
int vector_init(vector *vec);

/**
 * @brief Append `item` to the end of `vec`.
 *
 * @param *vec `vector` to operate on.
 * @param *item `item` to be appended.
 * @retval int Status code defined by `status_code`.
 */
int vector_append(vector *vec, void *item);

/**
 * @brief  Remove an element from `vec` at index `index`.
 * @param  *vec: `vector` to operate on.
 * @param  index: Index of the element to be removed.
 * @retval int Status code defined by `status_code`.
 */
int vector_remove(vector *vec, size_t index);

/**
 * @brief  Pop an element from `vec` at index `index`.
 * @param  *vec: `vector` to operate on.
 * @param  index: Index of the element to be popped.
 * @retval pointer of
 */
void *vector_pop(vector *vec, size_t index);
