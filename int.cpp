#include<stdio.h>
#include<conio.h>
int main()
{
    float celcius;
    float F;
    printf("Enter temperature in celcius:");
    scanf("%f",&celcius);
    F=(9/5)*celcius+32;
    printf("Temperature in Fahrenheit: %f",F);

}