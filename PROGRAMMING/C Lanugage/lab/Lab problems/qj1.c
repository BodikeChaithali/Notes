#include<stdio.h>
int main(){
float a,b,c,d,e,f;
printf("Enter the length of the cuboid\n");
printf("Enter the breadth of the cuboid\n");
printf("Enter the height of the cuboid\n");
scanf("%f%f%f",&a,&b,&c);
printf("Enter the height cylinder\n");
printf("Enter the Radius of cylinder\n");

scanf("%f%f",&d,&e);
printf("Enter the radius of sphere\n");
scanf("%f",&f); 
printf("The volume of the Cuboid is %.2f\n",a*b*c); 
printf("The volume of the cylinder is %.2f\n",3.14*e*e*d); 
printf("The volume of the Sphere is %.2f\n",4/3*(3.14*f*f*f)); 

return 0;
}
