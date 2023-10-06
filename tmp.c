struct vector
{
    int *tableau;
    int taille;
};


//#########################################################
typedef struct vector vector;
void display_vector(vector *t);
vector *creation_vector(int taille);
void initialisation_vector(vector *t);
int lecture_vector(vector *t,int indice);
int ecriture_vector(vector *t,int indice, int valeur);
//#########################################################


int lecture_vector(vector *t,int indice)
{

    if(indice>=t->taille||indice<0) return -1;
    return t->tableau[indice];
    
}

int ecriture_vector(vector *t,int indice, int valeur)
{

    if(indice>=t->taille||indice<0) return 0;
    t->tableau[indice] =valeur;
    return 1;
    
}
vector *creation_vector(int taille)
{
    vector *tmp;
    tmp=(vector*)malloc(sizeof(vector));
    tmp->tableau=(int*)malloc(sizeof(int)*taille);
    tmp->taille = taille;
    return tmp;
}

void affichage_vector(vector *t)
{
    int i;
    for(i=0;i<t->taille-1;i++)
    {
        printf("%d|",lecture_vector(t,i));
    }
    printf("%d",lecture_vector(t,t->taille -1));
}
void initialisation_vector(vector *t)
{
    int i;
    for(i=0;i<t->taille;i++)
    {
        ecriture_vector(t,i,i);
    }
}