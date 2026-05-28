#include<stdio.h>
#define pi 3.14  
int main() {
    float l,w,h1,r1,h2,r2;
    printf("Length, breadth and height of the cuboid Radius and height of cylinder Radius of sphere:\n");
    scanf("%f%f%f",&l,&w,&h1);
    scanf("%f%f",&r1,&h2);
    scanf("%f",&r2);
    printf("Volume of the Cubiod is %.2f\n",l*w*h1);
    printf("Volume of the Cylinder is %.2f\n",pi*r1*r1*h2);
    printf("Volume of the Sphere is %.2f\n",(4*pi*r2*r2*r2)/3);
    return 0;
}