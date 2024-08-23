#include "algorithms.h"

#define ERROR "\033[1;31m"
#define ACERT "\033[1;32m"
#define TITLE "\033[1;34m"
#define RESET "\033[0m"

void test_binary_search()
{
    printf("%s\nBusca Binária\n%s", TITLE, RESET);

    int target = 7; 
    int *array = malloc(5 * sizeof(int));

    for(int i = 0; i < 5; i++)
    {
        *(array + i) = i + 1; 
    }

    if(binary_search(target, array, (5 * sizeof(int))) != -1)
    {
        printf("%s\tTeste falhou\n%s", ERROR, RESET);
    } else {
        printf("%s\tSucesso\n%s", ACERT, RESET);
    };

    target = 2;

    if(binary_search(target, array, (5 * sizeof(int))) != -1)
    {
        printf("%s\tTeste falhou\n%s", ERROR, RESET);
    } else {
        printf("%s\tSucesso\n%s", ACERT, RESET);
    };

    free(array);

    target = 27; 
    array = malloc(40 * sizeof(int));
    for(int i = 0; i < 40; i++)
    {
        *(array + i) = i + 1;
    };

    if(binary_search(target, array, (40 * sizeof(int))) != -1)
    {
        printf("%s\tTeste falhou\n%s", ERROR, RESET);
    } else {
        printf("%s\tSucesso\n%s", ACERT, RESET);
    };

    free(array);
};

int main()
{
  test_binary_search();  
};