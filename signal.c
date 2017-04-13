#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "signal.h"

double* chargement(char* name)
{
    FILE *fichier = NULL;
    double *data;
    int taille =0, i = 0, tmp = 0;

    fichier = fopen(name, "r");
    if (fichier == NULL)
        return NULL;

    if (fseek(fichier, 44, SEEK_SET) != 0)
    {
        fclose(fichier);
        return NULL;
    }

    while (fgetc(fichier) != EOF)
        taille++;

    if (fseek(fichier, 44, SEEK_SET) != 0)
    {
        fclose(fichier);
        return NULL;
    }

    data = malloc(taille * sizeof(double) + 1);

    do
    {
        tmp = fgetc(fichier);
        data[i] = tmp; // *1.f ?
        i++;
    }
    while (tmp != EOF)

        fclose(fichier);

    return data;
}

int ecriture(char* name, double* data)
{
    FILE *origine = NULL, *copie = NULL;
    int i;

    origine = fopen(name, "r");
    copie = fopen("new.wav", "w+");

    if (origine == NULL || copie == NULL)
        return 0;

    for (i = 44; i > 0; i--) // Recopie d'en-tete
        fputc(fgetc(origine), copie);
    fclose(origine);

    for (i = 0; data[i] != EOF; i++)
        fputc(floor(data[i]), copie);

    fclose(copie);

    return 1;
}

double moyenne3(double* data, unsigned int x)
{
    return 1.f;
}

double* convolution(double*)
{

}

double* gaussienne(int)
{
    return 1.f;
}

int traitement(char*)
{
    return 1;
}
