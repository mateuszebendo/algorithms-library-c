#include "algorithms.h"

int binary_search(int target, int array[], int array_size)
{
    int start_index = 0; 
    int end_index = array_size - 1;

    while (start_index <= end_index)
    {
        int middle_index = start_index + (end_index - start_index) / 2;
        int current_value = array[middle_index];
        
        if (current_value == target)
        {
            return middle_index;
        }

        if (current_value < target)
        {
            start_index = middle_index + 1;
        } 
        else 
        {
            end_index = middle_index - 1;
        }
    }

    return -1;
}
