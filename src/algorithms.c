#include "algorithms.h"

int binary_search(int target, Array array)
{
    int middle_index = array.start + (array.end - array.start) / 2;
    int current_value = *(array.elements + middle_index);

    if(array.start > array.end)
    {
        return -1;
    }

    if (current_value == target)
    {
        return middle_index;
    }

    if (current_value < target)
    {
        array.start = middle_index + 1;
        return binary_search(target, array);
    } 
    else 
    {
        array.end = middle_index - 1;
        return binary_search(target, array);
    }
}

int binary_search_circular_array_smallest_element(Array array)
{
    if (array.size <= 0) {
        return -1;
    }

    int start = array.start;
    int end = array.size - 1;

    if (array.elements[start] < array.elements[end]) {
        return start;
    }

    while (start < end) {
        int middle_index = start + (end - start) / 2;

        if (array.elements[middle_index] > array.elements[end]) {
            start = middle_index + 1;
        } else {
            end = middle_index;
        }
    }

    return start;
}

