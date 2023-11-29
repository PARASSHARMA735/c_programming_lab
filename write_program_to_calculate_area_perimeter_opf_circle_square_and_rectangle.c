#include<stdio.h>
void main() {
    //rectangle
    int l,b;
    printf("enter the value of Length of rectangle :\n");
    scanf("%d",&l);
    printf("enter the value of Breadth of rectangle :\n");
    scanf("%d",&b);
    //square
    int side;
    printf("enter the value of side of square :\n ");
    scanf("%d",&side);
    //circle
    float radius;
    printf("enter the value of radius of circle :\n");
    scanf("%f",&radius);
    printf("perimeter of circle :%f/n",2*3.14*radius);
    printf("area of circle :%f\n",radius*radius*3.14);
    printf("perimeter of square :%f\n",4*side);
    printf("area of square :%f\n",side*side);
    printf("perimeter of rectangle :%f\n",2*(l+b));
    printf("area of rectangle :%f\n",l*b);
    
    }

