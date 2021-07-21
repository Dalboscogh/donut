#include <stdio.h>
#include "mathme.h"
#include "donut_p.h"
#include <math.h>
#include <stdlib.h>

int main(){
    double r =7, R=13, tam = 90;
    int lados = 44;
    vetor observador = vetor_create(0,0,0);
    vetor luz = vetor_create(130, 20, 90);

    donut rosquinha;
    rosquinha.normal = vetor_create(0, 0, -1);
    rosquinha.position = vetor_create(0, 0, 120);
    rosquinha.R = 13;
    rosquinha.r = 7;
    rosquinha.arcosR = 360;
    rosquinha.arcosr = 72;
    rosquinha.pontos = geradora_coordenadas(rosquinha);

    semiplane tela;
    tela.height = 1.2*(2*(rosquinha.R+rosquinha.r));
    tela.width = 1.8*(2*(rosquinha.R+rosquinha.r));
    tela.origem = rosquinha.position;
    tela.normal = vetor_create(0,0,-1);

    vetor l = vetor_create(-0.155601, -0.23487, 0.959492), n = vetor_create(0.431711, 0.885139, 0.173648);
    printf("%lf\n", luminosidade(l, n));
    //implementar a mudar o ponto do observador, fora de x=0 e y=0?
    printar_donut(rosquinha, tela, observador, luz);
    system("pause");
    system("cls");
    vetor omega = vetor_create(0, 3.1415926/20, 0); //soh ta funcionando com valor em y e resto 0
    for (size_t i = 0; i < 40; i++) {
        rotacionar_donut(rosquinha, omega, 2400);
        printar_donut(rosquinha ,tela ,observador, luz);
        system("cls");
    }

    sombra(luz, rosquinha.pontos[4], rosquinha);

}
