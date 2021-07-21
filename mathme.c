#include "mathme.h"

//fiz essa aqui pra nada kk
double arctg(double x){
    double arctan=0;
    for (size_t i = 0; i < 5000; i++) {
        arctan += potencia(-1, i)*potencia(x, 2*i+1)/(2*i+1);
    }
    return arctan;
}
double mod(double x){
    if(x >= 0) return x;
    return -x;
}
int fatorial(int x){
    if (x<0) {
        printf("ERRO, fatorial de numero negativo nao esta definido\n");
        return -1;
    }
    if(x==0) return 1;
    return x*fatorial(x-1);
}
double potencia(double x, int p){
    double pot = 1;
    if (p<0) {
        p = -p;
        for (int i = 0; i < p; i++) {
            pot*=x;
        }
        return 1/pot;
    }
    for (int i = 0; i < p; i++) {
        pot*=x;
    }
    return pot;
}

vetor vetor_create (double a, double b, double c){
    vetor retorno;
    retorno.x = a;
    retorno.y = b;
    retorno.z = c;
    return retorno;
}
vetor soma_vetor (vetor a, vetor b){
    vetor new;
    new.x = a.x + b.x;
    new.y = a.y + b.y;
    new.z = a.z + b.z;
    return new;
}
vetor subtracao_vetor (vetor a, vetor b){
    vetor new;
    new.x = a.x - b.x;
    new.y = a.y - b.y;
    new.z = a.z - b.z;
    return new;
}
vetor prod_vetorial (vetor a, vetor b){
    vetor prod;
    prod.x = a.y * b.z - a.z * b.y;
    prod.y = a.z * b.x - a.x * b.z;
    prod.z = a.x * b.y - a.y * b.x;
    return prod;
}
double prod_escalar (vetor a, vetor b){
    return (a.x*b.x+a.y*b.y+a.z*b.z);
}
vetor multi_escalar (vetor a, double escalar){
    vetor aux;
    aux.x = a.x*escalar;
    aux.y = a.y*escalar;
    aux.z = a.z*escalar;
    return aux;
}
double modulo_vetor (vetor a){
    return sqrt(a.x*a.x+a.y*a.y+a.z*a.z);
}
double dist_ponto_reta (vetor observador, vetor direcao, vetor ponto){
    vetor v = subtracao_vetor(ponto, observador);
    return modulo_vetor(prod_vetorial(direcao, v))/modulo_vetor(direcao);
}
vetor unitario(vetor a){
    vetor unitario;
    double modulo = modulo_vetor(a);
    unitario.x = a.x / modulo;
    unitario.y = a.y / modulo;
    unitario.z = a.z / modulo;
    return unitario;
}

// a fazer


/*vetor change_rot_ref(vetor vet, vetor normal){

    //so funciona pra rotacao do plano xz

    //acho que ta bugado, soh com dois vetores nao tem como fazer rotacinar pq nao eh unica, precisa de dois vetores(plano) pra definir bonitinho o role, pq se colocar soh
    // que eh pra ser o eixo z, o eixo x e y tem infinitas possibilidades, mas eu preciso definir um pra colocar
    vetor aux = vetor_create(0, 0, -1);
    double cosalfa = prod_escalar(aux, normal), sinalfa = modulo_vetor(prod_vetorial(aux, normal));
    printf("%lf e %lf\n", cosalfa, sinalfa);
    vetor novo;
    novo.y = vet.y;
    novo.x = vet.x * cosalfa - vet.z * sinalfa;
    novo.z = vet.z * cosalfa + vet.x * sinalfa;
    return novo;
    // se tiver no eixo z vai ter uma componente z*cosalfa em z e uma z*senalfa em xy, ai vai ter mais um angulo pra definir quanto vai colaborar pra eles
}*/
