#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Calcula distancia entre o robo e a bola
double calcDistRoboBola (double xR, double yR, double xB, double yB, double tempo){
    double dist = sqrt(pow((xB-xR),2) + pow((yB-yR),2));
    return dist;
}

// Calcula a aceleração necessária para o robor alcançar a bola
double calcAceleraRobo (double xR, double yR, double xB, double yB, double tempo){
    double dist = distRoboBola (xR, yR, xB, yB, tempo);
    double aclr = dist*2/pow(tempo,2);
    return aclr;
}

// Calcula a maior velocidade necessária para o robo alcançar a bola
double calcVeloRobo (double xR, double yR, double xB, double yB, double tempo){
    double aclr = calcAceleraRobo (xR, yR, xB, yB, tempo);
    double velocidade = aclr*tempo;
    return velocidade;
}

int main(void) {
    
}