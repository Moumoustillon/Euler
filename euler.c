#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include"toolbox.h"

float pouding(float x) 
{
    int n;
    float y = 0.0, s;
    
    for (n = 0; n<=30;n++)
    {
        s = fabs(fmod(power(2,n)*x, 1.0) - 0.5);
        y += s/power(2,n);
    }
    return y;
}

int longueur(int valeur)
{
	int retour = 0;
	if(valeur < 0)
	{
		retour++;
		valeur = -1 * valeur;
	}
	while(valeur !=0)
	{
		retour++;
		valeur = valeur / 10;
	}
	return retour;
}

float monte_carlo (float (*f)(float), float nb_coups, float debut, float fin, float maximum){
    srand(time(NULL)); 
    int nb_succes = 0, x_int, y_int;
    float x, y;
    for (int i = 0; i < nb_coups; i++){
        x_int = rand(); // entier entre 0 et RAND_MAX
        x = fabs(x_int*power_f(10, -1*longueur(x_int)))/0.5;
        y_int = rand();
        y = fabs(y_int*power_f(10, -1*longueur(y_int)));
        if ((f(x)>y)&&((x - 0.25)*(x - 0.25) + (y - 0.5)*(y - 0.5) < 0.0625)) nb_succes ++;
    }
    float prob = nb_succes/nb_coups; 
    float integrale = prob*(fin-debut)*maximum;
    printf("prob :%f\n", prob); 
    printf("fin - debut %f\n", fin-debut);
    printf("integrale %f\n", integrale);
    return integrale*10; 
}

int main()
{
    clock_t start, end;
    start = clock();
    printf("%.8f\n", pouding(0.1358));

    printf("%.8f\n", monte_carlo(pouding, 1000000, 0, 0.5, 0.67));
    //euler226();

    end = clock();
    double duration = ((double)end - start)/CLOCKS_PER_SEC;
    printf("\nTime taken to execute in seconds : %f\n", duration);
    return EXIT_SUCCESS;
}