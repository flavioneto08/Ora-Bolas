#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    int i = 0;
    float time[1001];
    float ballXPosition[1001];
    float ballYPosition[1001];

    for (i = 0; i < 1002; i++) { // Initialize and store values for time, ballXPosition, and ballYPosition
        time[0] = 0;
        time[i + 1] = time[i] + 0.020;

        ballXPosition[0] = 1;
        ballXPosition[i + 1] = ballXPosition[i] + 0.010;

        ballYPosition[0] = 0.5;
        ballYPosition[i + 1] = ballYPosition[i] + 0.008;
    }

    float maxVelocityRobot = 2.8;
    float maxAccelRobot = 2;
    float initialSpaceX[1001], initialSpaceY[1001], cos[1001], sin[1001], velocityRobotX[1001], velocityRobotY[1001], velocityRobotT[1001];
    float distance[1001];
    float initialVelocity = 0;
    float accelX[1001], accelY[1001];

    for (i = 0; i < 1002; i++) {
        velocityRobotT[i] = 0;
    }

    do {
        printf("Informe a posicao inicial do robo em X: ");
        scanf("%f", &initialSpaceX[0]);

        printf("Informe a posicao inicial do robo em Y: ");
        scanf("%f", &initialSpaceY[0]);

        if (initialSpaceX[0] > 2.0 && initialSpaceY[0] > 1.5) {
            printf("O robo esta muito longe da bola, tente um valor dentro do raio de 1 metro da bola.\n");
        }

    } while (initialSpaceX[0] > 2.0 && initialSpaceY[0] > 1.5);

    for (int z = 0; z < 1002; z++) {// Calculates the velocity of the robot and keeps the values in an array
        
        velocityRobotT[z] = maxAccelRobot * valuesTime[z];
        if (velocityRobotT[z] >= maxVelocityRobot) {
            velocityRobotT[z] = maxVelocityRobot;
        }
    }

    for (i = 0; i < 1002; i++) {
        // Calculates the distance between the ball and the robot
        distance[i] = ((valuesBallX[i] - initialSpaceX[i]) * (valuesBallX[i] - initialSpaceX[i])) + ((valuesBallY[i] - initialSpaceY[i]) * (valuesBallY[i] - initialSpaceY[i]));

        cos[i] = (valuesBallX[i] - initialSpaceX[i]) / sqrt(distance[i]); // Calculate the cosine of the angle
        sin[i] = (valuesBallY[i] - initialSpaceY[i]) / sqrt(distance[i]); // Calculate the sine of the angle

        initialSpaceX[i + 1] = initialSpaceX[i] + (cos[i] * 0.04); // Calculates the position of the robot in the next time step for the X axis
        initialSpaceY[i + 1] = initialSpaceY[i] + (sin[i] * 0.05); // Calculates the position of the robot in the next time step for the Y axis

        /* Calculations for acceleration and velocity
        float velocityRobotX[1001], velocityRobotY[1001];
        velocityRobotX[i] = velocityRobotT[i] * cos[i];
        printf("Velocidade durante a trajetoria no eixo X: %.3f\n", velocityRobotX[i]);
        velocityRobotY[i] = velocityRobotT[i] * sin[i];
        printf("Velocidade durante a trajetoria no eixo Y: %.3f\n", velocityRobotY[i]);

        float accelRobotX[1001], accelRobotY[1001], accelRobotTX[1001], accelRobotTY[1001];
        accelRobotTX[i] = (velocityRobotX[i] + velocityRobotX[i + 1])/(valuesTime[i + 1] - valuesTime[i]);
        accelRobotX[i] = accelRobotTX[i] * cos[i];
        printf("Aceleração durante a trajetoria no eixo X: %.3f\n", accelRobotX[i]);

        accelRobotTY[i] = (velocityRobotY[i] + velocityRobotY[i + 1])/(valuesTime[i + 1] - valuesTime[i]);
        accelRobotY[i] = accelRobotTY[i] * sin[i];
        printf("Aceleração durante a trajetoria no eixo Y: %.3f\n", accelRobotY[i]);
        */
        
        // Verifies if the distance between the robot and the ball is less than 0.15 which is the radius of interception
        if (initialSpaceX[i] >= valuesBallX[i] - 0.15 && initialSpaceY[i] <= valuesBallX[i] + 0.15 && initialSpaceY[i] >= valuesBallY[i] - 0.15 && initialSpaceY[i] <= valuesBallY[i] + 0.15) {
            printf("O robo conseguiu alcancar a bola!\n");
            printf("Dados: \n");
            printf("Posicao do robo no eixo X: %.3fm     Posicao do robo no eixo Y: %.3fm     Velocidade do robo: %.1fm/s\n", initialSpaceX[i], initialSpaceY[i], velocityRobotT[i]);
            printf("Posicao da bola no eixo X: %.3fm     Posicao da bola no eixo Y: %.3fm\n", valuesBallX[i], valuesBallY[i]);
            printf("Tempo gasto ate o robo encontrar a bola: %.2fs\n", valuesTime[i]);

            
        else
        {

            printf("X: %.3f    Y: %.3f     Tempo: %.3f     Velocidade: %.3f\n", initialSpaceX[i], initialSpaceY[i], valuesTime[i], velocityRobotT[i]);
            printf("BolaX: %.3f     BolaY: %.3f\n\n", valuesBallX[i], valuesBallY[i]);
            // printf("Aceleracao do robo no eixo X: %.3fm/s^2\n", accelRobotX[i]);
            // printf("Aceleracao do robo no eixo Y: %.3fm/s^2\n\n", accelRobotY[i]);
        }

            break;
        }
    }

    system("pause");
}
