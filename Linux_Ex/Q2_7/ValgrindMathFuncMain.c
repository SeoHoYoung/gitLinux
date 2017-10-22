#include <stdio.h>
#include <stdlib.h>

double Add(double a, double b);
double Subtract(double a, double b);
double Multiply(double a, double b);
double Divide(double a, double b);
void Test();

void main(){
    printf("Add(1.5,2.3) = %.1lf\n", Add(1.5,2.3));
    printf("Subtract(6.3,1.1) = %.1lf\n", Subtract(6.3,1.1));
    printf("Multiply(2.1,3) = %.1lf\n", Multiply(2.1,3));
    printf("Divide(6,2) = %.1lf\n", Divide(6,2));
    Test();
}

void Test(){
    int i;
    int *ptr;

    i = *ptr;
    ptr = malloc(20 * sizeof(int));
    ptr[20] = 0;
    ptr = 0;
}

double Add(double a, double b){
    return a + b;
}
double Subtract(double a, double b){
    return a - b;
}
double Multiply(double a, double b){
    return a * b;
}
double Divide(double a, double b){
    return a / b;
}

