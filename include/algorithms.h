#ifndef ALGORITHMS_LIBRARY_H
#define ALGORITHMS_H

typedef struct 
{
    int *elements; 
    int size; 
    int start;
    int end; 
} Array;

int binary_search(int target, Array array);
int binary_search_circular_array_smallest_element(Array array);

#endif //ALGORITHMS_LIBRARY_H
