#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int spaceEqX(float finalSpaceX, float initialSpaceX, float initialVelocity, float time)
{
    float accelX;
    accelX = ((finalSpaceX * 2) - initialSpaceX - (initialVelocity * time)) / (time * time);
    return accelX;
}

int spaceEqY(float finalSpaceY, float initialSpaceY, float initialVelocity, float time, float accelY)
{
    accelY = ((finalSpaceY * 2) - initialSpaceY - (initialVelocity * time)) / (time * time);
    return accelY;
}

int velocityEqX(float finalVelocityX, float initialVelocity, float time, float accelX)
{
    finalVelocityX = initialVelocity + (accelX * time);
    return finalVelocityX;
}

int velocityEqY(float finalVelocityY, float initialVelocity, float time, float accelY)
{
    finalVelocityY = initialVelocity + (accelY * time);
    return finalVelocityY;
}

int main()
{

    int i = 0;
    float valuesTime[1001];
    float valuesBallX[1001];
    float valuesBallY[1001];

    for (i = 0; i < 1002; i++) // Initialize and store values for time, ballX, and ballY
    {
        valuesTime[0] = 0;
        valuesTime[i + 1] = valuesTime[i] + 0.020;

        valuesBallX[0] = 1;
        valuesBallX[i + 1] = valuesBallX[i] + 0.010;

        valuesBallY[0] = 0.5;
        valuesBallY[i + 1] = valuesBallY[i] + 0.008;
    }

    float maxVelocityRobot = 2.8;
    float maxAccelRobot = 2;
    float initialSpaceX[1001], initialSpaceY[1001], cos[1001], sin[1001], velocityRobotX[1001], velocityRobotY[1001], velocityRobotT[1001];
    float distance[1001];
    float initialVelocity = 0;
    float accelX[1001], accelY[1001];

    for (i = 0; i < 1002; i++)
    {
        velocityRobotT[i] = 0;
    }

    do
    {
        printf("Informe a posicao inicial do robo em X: ");
        scanf("%f", &initialSpaceX[0]);

        printf("Informe a posicao inicial do robo em Y: ");
        scanf("%f", &initialSpaceY[0]);

        if (initialSpaceX[0] > 2.0 && initialSpaceY[0] > 1.5)
        {
            printf("O robo esta muito longe da bola, tente um valor dentro do raio de 1 metro da bola.\n");
        }

    } while (initialSpaceX[0] > 2.0 && initialSpaceY[0] > 1.5);

    for (int z = 0; z < 1002; z++) // Calculates the velocity of the robot and keeps the values in an array
    {
        velocityRobotT[z] = maxAccelRobot * valuesTime[z];

        if (velocityRobotT[z] >= maxVelocityRobot)
        {
            velocityRobotT[z] = maxVelocityRobot;
        }
    }

    for (i = 0; i < 1002; i++)
    {
        // Calculates the distance between the ball and the robot
        distance[i] = ((valuesBallX[i] - initialSpaceX[i]) * (valuesBallX[i] - initialSpaceX[i])) + ((valuesBallY[i] - initialSpaceY[i]) * (valuesBallY[i] - initialSpaceY[i]));

        cos[i] = (valuesBallX[i] - initialSpaceX[i]) / sqrt(distance[i]); // Calculate the cosine of the angle
        sin[i] = (valuesBallY[i] - initialSpaceY[i]) / sqrt(distance[i]); // Calculate the sine of the angle

        initialSpaceX[i + 1] = initialSpaceX[i] + (cos[i] * 0.04); // Calculates the position of the robot in the next time step for the X axis
        initialSpaceY[i + 1] = initialSpaceY[i] + (sin[i] * 0.05); // Calculates the position of the robot in the next time step for the Y axis

        /*/
        do
        {

            float accelRobotX[1001], accelRobotY[1001];
            accelRobotX[i] = (((initialSpaceX[i] * 2) - initialSpaceX[0] - (initialVelocity * valuesTime[i])) / (valuesTime[i] * valuesTime[i]));
            printf("Aceleracao do robo no eixo X: %.3fm/s^2\n", accelRobotX[i]);

            accelRobotY[i] = (((initialSpaceY[i] * 2) - initialSpaceY[0] - (initialVelocity * valuesTime[i])) / (valuesTime[i] * valuesTime[i]));
            printf("Aceleracao do robo no eixo Y: %.3fm/s^2\n", accelRobotY[i]);

        } while (initialSpaceX[i] < valuesBallX[i] - 0.15 && initialSpaceY[i] > valuesBallX[i] + 0.15 && initialSpaceY[i] < valuesBallY[i] - 0.15 && initialSpaceY[i] > valuesBallY[i] + 0.15);
        /*/

        // Verifies if the distance between the robot and the ball is less than 0.15 which is the radius of interception
        if (initialSpaceX[i] >= valuesBallX[i] - 0.15 && initialSpaceY[i] <= valuesBallX[i] + 0.15 && initialSpaceY[i] >= valuesBallY[i] - 0.15 && initialSpaceY[i] <= valuesBallY[i] + 0.15)
        {
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