#include <stdio.h>
float square(float);
void main(){
    float num;
    printf("Enter number: ");
    scanf("%f", &num);
    printf("Square is = %f\n", square(num));
}
float square(float num){
    return num*num;
}