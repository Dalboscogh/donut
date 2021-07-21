#ifndef _DONUT_H
#define _DONUT_H

#include "mathme.h"
#include <stdbool.h>
#include "mathme.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

typedef struct donut_p{
    vetor position;
    vetor normal;
    vetor ref;
    double light;
} donut_p;


typedef struct donut{
    vetor position;
    vetor normal;
    double R;
    double r;
    int arcosR;
    int arcosr;
    donut_p *pontos;
} donut;


donut_p *geradora_coordenadas(donut donut1);
donut rotacionar_donut (donut donut1, vetor omega, double tempo);
///determinar as retas? 2 angulos, alfa e beta, definem o vetor direção da reta, procuram ponto do donut_p, fazer isso até não achar mais ponto do donut_p, angulo sólido!!
///vai ter algumas várias retas, usa conversão pra elas ficarem no tamanho que quer, aglutina na quantidade de pontos desejada, fica apenas com a reta central
///preciso elaborar um jeito de armazenar as retas, como trabalhar com elas, forma vetorial ou eq geral
///pontos intercepta - mais proximos -> calcular produto escalar da reta com a normal para determinar caracter
///printa - usar uma gradação de alfa e beta para printar direitinho na ordem desejada.
///fazer ela rodar
void printar_donut(donut rosquinha, semiplane tela, vetor observador, vetor luz);
double luminosidade(vetor normal, vetor dir);
int distancia_donut_dir(donut rosquinha, vetor observador, vetor dir);
void char_decider(vetor ref, double light);
int distancia_donut_pts(donut rosquinha, vetor ponto1, vetor ponto2);

bool sombra (vetor luz, donut_p ponto1, donut donut1);
//teste de alteracao no git

#endif
