#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int spaceEqX(float finalSpaceX, float initialSpaceX, float initialVelocity, float time) {
    float accelX;
    accelX = ((finalSpaceX * 2) - initialSpaceX - (initialVelocity * time)) / (time * time);
    return accelX;
}

int spaceEqY(float finalSpaceY, float initialSpaceY, float initialVelocity, float time, float accelY) {
    accelY = ((finalSpaceY * 2) - initialSpaceY - (initialVelocity * time)) / (time * time);
    return accelY;
}

int velocityEqX(float finalVelocityX, float initialVelocity, float time, float accelX) {
    finalVelocityX = initialVelocity + (accelX * time);
    return finalVelocityX;
}

int velocityEqY(float finalVelocityY, float initialVelocity, float time, float accelY) {
    finalVelocityY = initialVelocity + (accelY * time);
    return finalVelocityY;
}

double calcDistRoboBola (double xR, double yR, double xB, double yB, double tempo) {
    double dist = sqrt(pow((xB-xR),2) + pow((yB-yR),2));
    return dist;
}

double calcAceleraRobo (double xR, double yR, double xB, double yB, double tempo) {
    double dist = distRoboBola (xR, yR, xB, yB, tempo);
    double aclr = dist*2/pow(tempo,2);
    return aclr;
}

double calcVeloRobo (double xR, double yR, double xB, double yB, double tempo) {
    double aclr = calcAceleraRobo (xR, yR, xB, yB, tempo);
    double velocidade = aclr*tempo;
    return velocidade;
}
