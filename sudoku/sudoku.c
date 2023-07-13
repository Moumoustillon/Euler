#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int* lire_grille(char* nom_fichier)
{
    int* grid = (int*)malloc(sizeof(int)*81);
    FILE *file = fopen(nom_fichier, "r+");
    if (file == NULL){
        printf("could not open file\n");
        exit(EXIT_FAILURE);
    } 

    char cursor = fgetc(file); 
    int i = 0;
    while (cursor!= EOF)
    {
        if (cur != '\n'){
            grid[i] = cursor - '0'; 
            i++;
        }
        cursor = fgetc(file);
    }
    fclose(file);
    return grid;
}

int ligne(int c)
{
    return c/9;
}

int colonne(int c)
{
    return c%9;
}

int groupe(int c)
{
    int ligne = ligne(c);
    int colonne = colonne(c);

    if (ligne<3)
    {
        if (colonne<3)
            return 1;
        else if (colonne<6)
            return 2;
        else
            return 3;
    }
    if (ligne<6)
    {
        if (colonne<3)
            return 4;
        else if (colonne<6)
            return 5;
        else
            return 6;
    }
    else
    {
        if (colonne<3)
            return 7;
        else if (colonne<6)
            return 8;
        else
            return 9;
    }
}

int verification(int grille[81], int p)
{
    int ligne = ligne(p);
    int colonne = colonne(p);
    int groupe = groupe(p);
    int element = grille[p];

    int l, c, g;
    l = p;
    while(ligne == ligne(l))
    {
        l = l-1;
        if (grille[l] == element) return 0;
    }
    l = p;
    while(ligne == ligne(l))
    {
        l = l+1;
        if (grille[l] == element) return 0;
    }

    c = p;
    while(colonne == colonne(c))
    {
        c = c-9;
        if (grille[c] == element) return 0;
    }
    c = p;
    while(colonne == colonne(c))
    {
        c = c+9;
        if (grille[c] == element) return 0;
    }
    
    g = p;
    
    
}

int main()
{
    clock_t start, end;
    start = clock();

    int *sudoku = lire_grille("grille2.txt");

	

    end = clock();
    double duration = ((double)end - start)/CLOCKS_PER_SEC;
    printf("\nTime taken to execute in seconds : %f\n", duration);
    return EXIT_SUCCESS;
}