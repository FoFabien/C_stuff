#ifndef __SIGNAL__
#define __SIGNAL__

double* chargement(char*);
int ecriture(char*, double*);

double moyenne3(double*, unsigned int);
double* convolution(double*);
double* gaussienne(int);

int traitement(char*);

#endif
