#include "donut_p.h"

/*Buscar pontos que cruzam as retas de visao
    achar os pontos mais proximos aos pontos da reta(distancia ponto reta, achar os 4 mais proximos e seleciona eles)*/

donut_p *geradora_coordenadas(donut donut1){
    donut1.normal;
    donut1.position;
    donut_p *rosquinha= (donut_p *) malloc(donut1.arcosR  * donut1.arcosr * sizeof(donut_p));
    double dif1 = 2*3.1415926/donut1.arcosR, dif2 = 2*3.1415926/donut1.arcosr;
    int count = 0;
    for ( int i = 0; i < donut1.arcosr; i++) {
        for (int j = 0; j < donut1.arcosR; j++) {
            rosquinha[count].position.x =  ((donut1.R + donut1.r*cos(dif2*i))*cos(dif1*j));
            rosquinha[count].position.y =  (donut1.R +donut1.r *cos(dif2*i)) *sin(dif1 * j);
            rosquinha[count].position.z = donut1.r *sin(dif2*i);
            rosquinha[count].position = soma_vetor(rosquinha[count].position, donut1.position);
            rosquinha[count].normal.x=cos(dif2*i)*cos(dif1*j);
            rosquinha[count].normal.y=cos(dif2*i)*sin(dif1*j);
            rosquinha[count].normal.z=sin(dif2*i);
            //printf("ponto - %lf %lf %lf \n", rosquinha[count].position.x, rosquinha[count].position.y, rosquinha[count].position.z);
            count++;
        }
    }
    return rosquinha;
}

donut rotacionar_donut (donut donut1, vetor omega, double tempo){
    double dt = 1;
    for (int i = 0; i < tempo; i+=dt) {
        donut1.normal.z = cos(omega.y*dt);
        donut1.normal.x = sin(omega.y*dt);
        for (int j = 0; j < donut1.arcosr*donut1.arcosR; ++j) {
        }
    }
}

void printar_donut(donut rosquinha, semiplane tela, vetor observador, vetor luz){
    for (int i = 0; i < rosquinha.arcosR *rosquinha.arcosr; ++i) {
        vetor dir = unitario(subtracao_vetor(rosquinha.pontos[i].position, luz));
        //printf("normal : %lf %lf %lf \n", rosquinha.pontos[i].normal.x, rosquinha.pontos[i].normal.y, rosquinha.pontos[i].normal.z);
        //printf("vetor da luz : %lf %lf %lf \n", dir.x, dir.y, dir.z);
        rosquinha.pontos[i].light = luminosidade(rosquinha.pontos[i].normal , dir);
        vetor obs = (subtracao_vetor(rosquinha.pontos[i].position, observador));
        rosquinha.pontos[i].ref = prod_vetorial(obs, rosquinha.pontos[i].normal);
    }


    vetor auxdir, dir;
    for (int i = 1; i <= tela.height; i++) {
        for (int j = 0; j < tela.width; j++) {
            auxdir.x = tela.height/2-i;
            auxdir.y = -tela.width/2+j;
            auxdir.z = tela.origem.z;
            dir = subtracao_vetor(auxdir, observador);
            int index = distancia_donut_dir(rosquinha, observador, dir);
            if (index == -1) char_decider(rosquinha.pontos[0].ref, 0 );
            else char_decider(rosquinha.pontos[index].ref, rosquinha.pontos[index].light);
        }
        printf("\n");
    }
}

void char_decider(vetor ref, double light){
//fazer o light na real definir cor usando conio e ai o ref o caractere?
//

    //printf("%lf \n", light);

    char c;
    /*if (ref.x< -0.33 && ref.y > 0.33 )
        c = "_.";
    else if (ref.x > -0.33 && ref.x < 0.33 && ref.y> 0.33)
        c = "_";
    else if (ref.x > 0.33 && ref.y> 0.33)
        c = "._";
    else if (ref.x< -0.33 && ref.y < 0.33 && ref.y > -0.33 ) c = "%";
    else if (ref.x > -0.33 && ref.x < 0.33 && ref.y < 0.33 && ref.y > -0.33) c = "@";
    else if (ref.x > 0.33 && ref.y < 0.33 && ref.y > -0.33) c = "$";

    else if (ref.x< -0.33 && ref.y < -0.33 ) c = "*-";
    else if (ref.x > -0.33 && ref.x < 0.33 && ref.y < -0.33) c = "-";
    else if (ref.x > 0.33 && ref.y < -0.33) c = "-*";*/
    //maior que 0.5
        //maior que 0.75
    if (light > 0.95) printf("@");
    else if (light > 0.9) printf("$");
    else if (light > 0.8) printf("#");
       //menor que 0.75
    else if (light > 0.7) printf("*");
    else if (light > 0.6) printf("!");
    else if (light > 0.55) printf("=");

    //menor que 0.5
    else if (light > 0.45) printf(";");
    else if (light > 0.40) printf(":");
    else if (light > 0.25) printf("~");
    else if (light > 0.20) printf("-");
    else if (light > 0.15) printf(",");
    else if (light > 0.1) printf(".");
    else printf(" ");

    printf("%c", c);

}

double luminosidade(vetor normal, vetor luz){
    return -prod_escalar(normal, luz);
}

int distancia_donut_dir(donut rosquinha, vetor observador, vetor dir){
    int tam = 30;
    double aux1[30];
    int aux2[30];
    for (int i = 0; i < tam; i++) {
        aux1[i] = 100000000;
        aux2[i] = 0;
    }
    for (int i = 0; i < rosquinha.arcosR*rosquinha.arcosr; i++) {
        double dist = dist_ponto_reta(observador, dir, rosquinha.pontos[i].position);
        if (dist > 3) continue;
        for (int j = 0; j < tam; j++) {
            if(dist < aux1[j]){
                for (int k = tam-1; k > j; k--) {
                    aux1[k] = aux1[k-1];
                    aux2[k] = aux2[k-1];
                }
                aux2[j] = i;
                aux1[j] = dist;
            }
        }
    }

    int mais_prox=0;
    for (int i = 0; i < tam; i++) {
        if (rosquinha.pontos[aux2[i]].position.z > rosquinha.pontos[aux2[mais_prox]].position.z) {
            mais_prox = i;
        }
    }
    return aux2[mais_prox];
}


// a fazer
int distancia_donut_pts(donut rosquinha, vetor ponto1, vetor ponto2){
    /*int tam = 30;
    double aux1[30];
    int aux2[30];
    for (int i = 0; i < tam; i++) {
        aux1[i] = 100000000;
        aux2[i] = 0;
    }
    for (int i = 0; i < rosquinha.arcosR*rosquinha.arcosr; i++) {
        double dist = dist_ponto_reta(ponto1, dir, rosquinha.pontos[i].position);
        if (dist > 3) continue;
        for (int j = 0; j < tam; j++) {
            if(dist < aux1[j]){
                for (int k = tam-1; k > j; k--) {
                    aux1[k] = aux1[k-1];
                    aux2[k] = aux2[k-1];
                }
                aux2[j] = i;
                aux1[j] = dist;
            }
        }
    }

    int mais_prox=0;
    for (int i = 0; i < tam; i++) {
        if (rosquinha.pontos[aux2[i]].position.z > rosquinha.pontos[aux2[mais_prox]].position.z) {
            mais_prox = i;
        }
    }
    return aux2[mais_prox];*/
}

bool sombra (vetor luz, donut_p ponto1, donut donut1) {
    return true;
}
