#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//perceptron 1
double x_1[10];
double w_1[10];
double y_1[1];
double dy_1[1];
double delta_1[1];
double de_1[10];
double sigmoid(double x)
{
    return 1.0/(1.0+exp(-x));
}

int main()
{
    int i;
    for(i=0;i<10;i++)
    {
        x_1[i] = (double) 0.01*i;
        w_1[i] = (double) rand()/(double) RAND_MAX;
    }

    //forward
    y_1[0] = 0.0;
    for(i=0;i<10;i++)
    {
        y_1[0] += w_1[i]*x_1[i];
    }
    y_1[0] = sigmoid(y_1[0]);

    dy_1[0] = y_1[0]*(1-y_1[0]);

    printf("%f\n",y_1[0]);

    //backward
    double e[1] = {1.0};
    delta_1[0] = e[0]*dy_1[0];
    for(i=0;i<10;i++)
    {
        de_1[i] = x_1[i]*delta_1[0];
    }

    return 0;
}
