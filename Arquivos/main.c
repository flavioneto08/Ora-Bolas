#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    
    //Common Variables
    int i = 0;
    float time[1001];
    float cos[1001];
    float sin[1001];
    float distance[1001]; //Between robot and the ball 
    float initialVelocity = 0; //Initial velocity will always be 0
    float accelX[1001]; 
    float accelY[1001];
    
    //Ball Variables
    float ballXPosition[1001];
    float ballYPosition[1001];
    
    //Robot Variables
    float robotMaxVelocity = 2.8;
    float maxAccelRobot = 2;
    float initialSpaceX[1001];
    float initialSpaceY[1001];
    float velocityRobotX[1001];
    float velocityRobotY[1001];
    float velocityRobotT[1001];

    for (i = 0; i < 1002; i++) { // Did not find a good way to read the files, so mocked the values inside initial arrays
        time[0] = 0;
        time[i + 1] = time[i] + 0.020;

        ballXPosition[0] = 1;
        ballXPosition[i + 1] = ballXPosition[i] + 0.010;

        ballYPosition[0] = 0.5;
        ballYPosition[i + 1] = ballYPosition[i] + 0.008;
        
        velocityRobotT[i] = 0;
    }

    do { // Asks for user initial position of the robot, while user inserts an invalid value for the position
        printf("Informe a posicao inicial do robo em X: ");
        scanf("%f", &initialSpaceX[0]);

        printf("Informe a posicao inicial do robo em Y: ");
        scanf("%f", &initialSpaceY[0]);

        if (initialSpaceX[0] > 2.0 && initialSpaceY[0] > 1.5) {
            printf("O robo esta muito longe da bola, tente um valor dentro do raio de 1 metro da bola.\n");
        }

    } while (initialSpaceX[0] > 2.0 && initialSpaceY[0] > 1.5);

    // We are doing the next for to check if the velocity of the robot reaches its max, bc in case it overlaps the max it means that the robot will not be possible to steal the ball
    for (int i = 0; i < 1002; i++) { // Calculates the velocity of the robot and keeps the values in an array
        velocityRobotT[i] = maxAccelRobot * valuesTime[i];
        if (velocityRobotT[i] >= robotMaxVelocity) {
            velocityRobotT[i] = robotMaxVelocity;
        }
    } 
    
    for (i = 0; i < 1002; i++) {
        // Calculates the distance between the ball and the robot
        distance[i] = ((valuesBallX[i] - initialSpaceX[i]) * (valuesBallX[i] - initialSpaceX[i])) + ((valuesBallY[i] - initialSpaceY[i]) * (valuesBallY[i] - initialSpaceY[i]));

        cos[i] = (valuesBallX[i] - initialSpaceX[i]) / sqrt(distance[i]); // Calculate the cosine of the angle
        sin[i] = (valuesBallY[i] - initialSpaceY[i]) / sqrt(distance[i]); // Calculate the sine of the angle

        initialSpaceX[i + 1] = initialSpaceX[i] + (cos[i] * 0.04); // Calculates the position of the robot in the next time step for the X axis
        initialSpaceY[i + 1] = initialSpaceY[i] + (sin[i] * 0.05); // Calculates the position of the robot in the next time step for the Y axis

        //  To append acceleration for every second into an array so we can graph latter
        do {
            float accelRobotX[1001], accelRobotY[1001];
            accelRobotX[i] = (((initialSpaceX[i] * 2) - initialSpaceX[0] - (initialVelocity * valuesTime[i])) / (valuesTime[i] * valuesTime[i]));
            accelRobotY[i] = (((initialSpaceY[i] * 2) - initialSpaceY[0] - (initialVelocity * valuesTime[i])) / (valuesTime[i] * valuesTime[i]));
            
        } while (initialSpaceX[i] < valuesBallX[i] - 0.15 && initialSpaceY[i] > valuesBallX[i] + 0.15 && initialSpaceY[i] < valuesBallY[i] - 0.15 && initialSpaceY[i] > valuesBallY[i] + 0.15);
        

        // Verifies if the distance between the robot and the ball is less than 0.15 which is the radius of interception
        if (initialSpaceX[i] >= valuesBallX[i] - 0.15 && initialSpaceY[i] <= valuesBallX[i] + 0.15 && initialSpaceY[i] >= valuesBallY[i] - 0.15 && initialSpaceY[i] <= valuesBallY[i] + 0.15) {
            
            printf("O robo conseguiu alcancar a bola!\n");
            printf("Dados: \n");
            printf("Posicao do robo no eixo X: %.3fm     Posicao do robo no eixo Y: %.3fm     Velocidade do robo: %.1fm/s\n", initialSpaceX[i], initialSpaceY[i], velocityRobotT[i]);
            printf("Posicao da bola no eixo X: %.3fm     Posicao da bola no eixo Y: %.3fm\n", valuesBallX[i], valuesBallY[i]);
            printf("Tempo gasto ate o robo encontrar a bola: %.2fs\n", valuesTime[i]);

            // double acellX = spaceEqX(initialSpaceX[i], initialSpaceX[0], initialVelocity, valuesTime[i]);
            float accelRobotX = (((initialSpaceX[i] * 2) - initialSpaceX[0] - (initialVelocity * valuesTime[i])) / (valuesTime[i] * valuesTime[i]));
            printf("Aceleracao do robo no eixo X: %.3fm/s^2\n", accelRobotX);

            float accelRobotY = (((initialSpaceY[i] * 2) - initialSpaceY[0] - (initialVelocity * valuesTime[i])) / (valuesTime[i] * valuesTime[i]));
            printf("Aceleracao do robo no eixo Y: %.3fm/s^2\n", accelRobotY);

            break;
        }
    }

    system("pause");
}
