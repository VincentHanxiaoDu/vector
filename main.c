#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    vector *vec = malloc(sizeof(vector));
    vector_init(vec);
    for (int i=0; i<6; i++)
    {
        unsigned int s_size;
        if (i == 0)
        {
            s_size = sizeof(char);
        }
        else
        {
            s_size = sizeof(char) * (int)log10(i);
        }

        char* i_str;
        i_str = malloc(s_size);
        sprintf(i_str, "%d", i);
        vector_append(vec, i_str);
    }
    for (int i=0; i<vec->size; i++)
    {
        printf("%s\n", (char*)vec->items[i]);
    }
    // unsigned int i = -1;
    // printf("%u", i);
    vector_remove(vec, 0);
    
    printf("%s\n", "===========");
    for (int i=0; i<vec->size; i++)
    {
        printf("%i_%s_%p\n",i, (char*)vec->items[i], &vec->items[i]);
    }
    printf("%i\n", vector_pop(vec, 6));
    // printf("%s\n", "===========");
    // for (int i=0; i<vec->size; i++)
    // {
    //     printf("%i_%s_%p\n",i, (char*)vec->items[i], &vec->items[i]);
    // }
    // printf("pointer pop:%p\n", vector_pop(vec, 3));

    // printf("%s\n", "===========");
    // for (int i=0; i<vec->capacity; i++)
    // {
    //     printf("%s\n", (char*)vec->items[i]);
    // }
}