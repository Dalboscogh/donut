#ifndef _MATHME_H
#define _MATHME_H

#include<stdio.h>
#include <math.h>

typedef struct vetor{
    double x;
    double y;
    double z;
} vetor;

vetor vetor_create (double a, double b, double c);
vetor soma_vetor (vetor a, vetor b);
vetor subtracao_vetor (vetor a, vetor b);
vetor prod_vetorial (vetor a, vetor b);
double prod_escalar (vetor a, vetor b);
double modulo_vetor (vetor a);
vetor unitario(vetor a);
vetor multi_escalar (vetor a, double escalar);
//vetor change_rot_ref(vetor vet, vetor normal);

typedef struct plane{
    vetor normal;
    vetor origem;
} plane;

typedef struct semiplane{
    vetor normal;
    double height;
    double width;
    vetor origem;
}semiplane;

double raiz(double x);
double arctg(double x);
double mod(double x);
int fatorial(int x);
double potencia(double x, int p);

double dist_ponto_reta (vetor observador, vetor direcao, vetor ponto);

#endif
