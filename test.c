#include "tools.h"


int main()
{
    int *tab;

    tab = (int*)calloc(10,sizeof(int));
    //display_array_pos(tab, 10);

    printf("coucou\n");
    free(tab);
    return EXIT_SUCCESS;
}