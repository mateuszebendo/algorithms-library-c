#include "algorithms.h"

#define ERROR "\033[1;31m"
#define ACERT "\033[1;32m"
#define TITLE "\033[1;34m"
#define RESET "\033[0m"

void test_binary_search()
{
    printf("%s\nBusca Binária\n%s", TITLE, RESET);

    Array array;
    array.size = 5; 
    array.start = 0; 
    array.end = array.size - 1;
    array.elements = malloc(array.size * sizeof(int));
    for (int i = 0; i < array.size; i++) {
        array.elements[i] = i + 1;
    } 

    int target = 7;

    if(binary_search(target, array) != -1)
    {
        printf("%s\tTeste falhou\n%s", ERROR, RESET);
    } else {
        printf("%s\tSucesso\n%s", ACERT, RESET);
    };

    target = 2;

    if(binary_search(target, array) == -1)
    {
        printf("%s\tTeste falhou\n%s", ERROR, RESET);
    } else {
        printf("%s\tSucesso\n%s", ACERT, RESET);
    };

    free(array.elements);

    target = 27; 
    array.size = 40;
    array.end = array.size - 1;
    array.elements = malloc(array.size * sizeof(int));

    for(int i = 0; i < array.size; i++)
    {
        *(array.elements + i) = i + 1;
    };

    if(binary_search(target, array) == -1)
    {
        printf("%s\tTeste falhou\n%s", ERROR, RESET);
    } else {
        printf("%s\tSucesso\n%s", ACERT, RESET);
    };

    free(array.elements);
};

void test_binary_search_smallest_element() 
{
    printf("%s\nBusca Binária em Array Circular por Menor Elemento\n%s", TITLE, RESET);

    Array array;
    array.size = 6;  
    array.start = 0;
    array.elements = malloc(array.size * sizeof(int));

    int initial_values[] = {5, 6, 1, 2, 3, 4};
    for (int i = 0; i < array.size; i++) {
        array.elements[i] = initial_values[i];
    }

    if(binary_search_circular_array_smallest_element(array) != 2)
    {
        printf("%s\tTeste falhou\n%s", ERROR, RESET);
    } else {
        printf("%s\tSucesso\n%s", ACERT, RESET);
    };

    free(array.elements);
}

int main()
{
  test_binary_search();  
  test_binary_search_smallest_element();
};