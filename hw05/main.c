#include <stdio.h>
#include <math.h>
#define PI 3.14
int select_shape();
int select_calculater();
int calculate(int (*slc_sp)(), int (*slc_clc)());
int calc_triangle(int result2);
int calc_quadrilateral(int result2);
int calc_circle(int result2);
int calc_pyramid(int result2);
int calc_cylinder(int result2);
int valid_or_not();
enum shapes
{
    Triangle = 1,
    Quadrilateral,
    Circle,
    Pyramid,
    Cylinder
};
enum calculaters
{
    Area = 1,
    Perimeter,
    Volume
};
int main()
{

    calculate(select_shape, select_calculater);
    return 0;
}
int select_shape()
{
    int shape;
    
    do
    {
    printf("Select a shape to calculate:\n");
    printf("----------------------------\n");
    printf("1. Triangle\n");
    printf("2. Quadrilateral\n");
    printf("3. Circle\n");
    printf("4. Pyramid\n");
    printf("5. Cylinder\n");
    printf("0. EXIT\n");
    printf("----------------------------\n");
    printf("Input :");
    	shape=valid_or_not();
    	while(shape==-1)
    	{
    		printf("ERROR! Please enter valid entry\n");
    		shape=valid_or_not();
    	}
    	if(shape != 1 && shape != 2 && shape != 3 && shape != 4 && shape != 5 && shape != 0)
    	{
    		printf("ERROR! Please enter valid entry\n");
    	}
    }
    while(shape != 1 && shape != 2 && shape != 3 && shape != 4 && shape != 5 && shape != 0);
    switch(shape)
    {
    case Triangle: return 1;
    break;
    case Quadrilateral: return 2;
    break;
    case Circle: return 3;
    break;
    case Pyramid: return 4;
    break;
    case Cylinder: return 5;
    break;
    default:return 0;
    break;
    }
}
int select_calculater()
{
    int calc;
    do
    {
    printf("Select calculator\n");
    printf("----------------------------\n");
    printf("1.Area\n");
    printf("2.Perimeter\n");
    printf("3.Volume\n");
    printf("0. EXIT\n");
    printf("----------------------------\n");
    printf("Input :");
    calc=valid_or_not();
    	while(calc==-1)
    	{
    		printf("ERROR! Please enter valid entry\n");
    		calc=valid_or_not();
    	}
    if(calc != 1 && calc != 2 && calc != 3 && calc != 0)
    	{
    		printf("ERROR! Please enter valid entry\n");
    	}
    }
    while(calc != 1 && calc != 2 && calc != 3 && calc != 0);
    switch(calc)
    {
    case Area: return 1;
    break;
    case Perimeter: return 2;
    break;
    case Volume: return 3;
    break;
    default: return 0;
    break;
    }
}
int calculate(int (*slc_sp)(), int (*slc_clc)())
{
    int result1 = slc_sp();
    int result2 = slc_clc();
    switch (result1)
    {
    case 1:
        calc_triangle(result2);
        break;
    case 2:
        calc_quadrilateral(result2);
        break;
    case 3:
        calc_circle(result2);
        break;
        case 4:
        calc_pyramid(result2);
        break;
    case 5:
        calc_cylinder(result2);
        break;
    default :
    	 break;
    }
}

int calc_triangle(int result2)
{
float s,a,b,c;

    float area;
    float perimeter;
    switch (result2)
    {
    case 1:
    	printf("please enter sides of Triangle\n");
    	a=valid_or_not();
    	while(a==-1)
    	{
    		printf("ERROR! Please enter valid entry\n");
    		a=valid_or_not();
    	}
    	b=valid_or_not();
    	while(b==-1)
    	{
    		printf("ERROR! Please enter valid entry\n");
    		b=valid_or_not();
    	}
     	c=valid_or_not();
     	while(c==-1)
    	{
    		printf("ERROR! Please enter valid entry\n");
    		c=valid_or_not();
    	}
    	while(a+b<c)
    	{
    		printf("ERROR! Please enter valid entry\n");
    		c=valid_or_not();
    	}
    	while(a+c<b)
    	{
    		printf("ERROR! Please enter valid entry\n");
    		b=valid_or_not();
    	}
    	while(b+c<a)
    	{
    		printf("ERROR! Please enter valid entry\n");
    		a=valid_or_not();
    	}
    	 s = (a + b + c) / 2;
        area = sqrt(s * (s - a) * (s - b) * (s - c));
        printf("Area of Triangle :%f\n", area);
        break;
    case 2:
    	
        printf("please enter sides of Triangle\n");
    	a=valid_or_not();
    	while(a==-1)
    	{
    		printf("ERROR! Please enter valid entry\n");
    		a=valid_or_not();
    	}
    	b=valid_or_not();
    	while(b==-1)
    	{
    		printf("ERROR! Please enter valid entry\n");
    		b=valid_or_not();
    	}
     	c=valid_or_not();
     	while(c==-1)
    	{
    		printf("ERROR! Please enter valid entry\n");
    		c=valid_or_not();
    	}
    	while(a+b<c)
    	{
    		printf("ERROR! Please enter valid entry\n");
    		c=valid_or_not();
    	}
    	while(a+c<b)
    	{
    		printf("ERROR! Please enter valid entry\n");
    		b=valid_or_not();
    	}
    	while(b+c<a)
    	{
    		printf("ERROR! Please enter valid entry\n");
    		a=valid_or_not();
    	}

        perimeter = a + b + c;
        printf("Perimeter of Triangle :%f\n", perimeter);
        break;
    case 3:
        printf("ERROR ! You can not calculate volume of Triangle\n");
        break;
    default:
    	 break;
    }
}
int calc_quadrilateral(int result2)
{
	float s;
    float a, b, c, d;
    
    float area;
    float perimeter;
    switch (result2)
    {
    case 1:
    printf("please enter sides of Quadrilateral\n");
    	a=valid_or_not();
    	while(a==-1)
    	{
    		printf("ERROR! Please enter valid entry\n");
    		a=valid_or_not();
    	}
    	b=valid_or_not();
    	while(b==-1)
    	{
    		printf("ERROR! Please enter valid entry\n");
    		b=valid_or_not();
    	}
     	c=valid_or_not();
     	while(c==-1)
    	{
    		printf("ERROR! Please enter valid entry\n");
    		c=valid_or_not();
    	}
    	d=valid_or_not();
     	while(d==-1)
    	{
    		printf("ERROR! Please enter valid entry\n");
    		d=valid_or_not();
    	}
    	
    s = (a + b + c + d) / 2;
        area = sqrt(s * (s - a) * (s - b) * (s - c) * (s - d));
        printf("Area of Quadrilateral :%f\n", area);
        break;
    case 2:
    printf("please enter sides of Quadrilateral\n");
    	a=valid_or_not();
    	while(a==-1)
    	{
    		printf("ERROR! Please enter valid entry\n");
    		a=valid_or_not();
    	}
    	b=valid_or_not();
    	while(b==-1)
    	{
    		printf("ERROR! Please enter valid entry\n");
    		b=valid_or_not();
    	}
     	c=valid_or_not();
     	while(c==-1)
    	{
    		printf("ERROR! Please enter valid entry\n");
    		c=valid_or_not();
    	}
    	d=valid_or_not();
     	while(d==-1)
    	{
    		printf("ERROR! Please enter valid entry\n");
    		d=valid_or_not();
    	}
      perimeter = a + b + c + d;
       printf("Perimeter of Quadrilateral :%f\n", perimeter);
        break;
    case 3:
        printf("ERROR ! You can not calculate volume of Quadrilateral\n");
        break;
    default :
    	 break;
    }
}
int calc_circle(int result2)
{
	float r;
    float area,perimeter;
    switch (result2)
    {
    case 1:
     printf("Please enter the radius of the circle\n");

    	r=valid_or_not();
    	while(r==-1)
    	{
    		printf("ERROR! Please enter valid entry\n");
    		r=valid_or_not();
    	}
    	area = PI * r * r;
        printf("Area of Circle :%f\n", area);
        break;
    case 2:
    printf("Please enter the radius of the circle\n\n");
    	r=valid_or_not();
    	while(r==-1)
    	{
    		printf("ERROR! Please enter valid entry\n");
    		r=valid_or_not();
    	}
    	 perimeter = 2 * PI * r;
        printf("Perimeter of circle :%f\n", perimeter);
        break;
    case 3:
        printf("ERROR ! You can not calculate volume of Circle\n");
        break;
    default :
    	 break;
    }
    
}
int calc_pyramid(int result2)
{
     float baseSide, height, slantHeight;
    float bsfca, lsfca, sfca, volume;
    float perimeter;
    switch (result2)
    {
    case 1:
        printf("Please enter the base side and slant height of a Pyramid:\n");
    	baseSide=valid_or_not();
    	while(baseSide==-1)
    	{
    		printf("ERROR! Please enter valid entry\n");
    		baseSide=valid_or_not();
    	}
    	slantHeight=valid_or_not();
    	while(slantHeight==-1)
    	{
    		printf("ERROR! Please enter valid entry\n");
    		slantHeight=valid_or_not();
    	}
    	bsfca = baseSide * baseSide;
        lsfca = 2 * baseSide * slantHeight;
        sfca = bsfca + lsfca;
        printf("Base Surface Area of a PYRAMID :%f\n", bsfca);
        printf("Lateral Surface Area of PYRAMID :%f\n", lsfca);
        printf("Surface Area of PYRAMID :%f\n", sfca);
        break;
    case 2:
        printf("Please enter the base side and slant height of a Pyramid:\n");
    	baseSide=valid_or_not();
    	while(baseSide==-1)
    	{
    		printf("ERROR! Please enter valid entry\n");
    		baseSide=valid_or_not();
    	}
    	 perimeter = baseSide*4;;
        printf("Perimeter of a pyramid :%f\n", perimeter);
        break;
         case 3:
        printf("Please enter the base side and height of a Pyramid:\n");
    	baseSide=valid_or_not();
    	while(baseSide==-1)
    	{
    		printf("ERROR! Please enter valid entry\n");
    		baseSide=valid_or_not();
    	}
    		height=valid_or_not();
    	while(height==-1)
    	{
    		printf("ERROR! Please enter valid entry\n");
    		height=valid_or_not();
    	}
    	 volume = (baseSide * baseSide * height) / 3;
        printf("Volume of a PYRAMID: %f", volume);
        break;
    default:
    	 break;
    }
}
int calc_cylinder(int result2)
{
	float radius, height;
    float bsfca, lsfca, sfca, volume;
    float perimeter;
    printf("Please enter the radius and height of a Cylinder:\n");
    	radius=valid_or_not();
    	while(radius==-1)
    	{
    		printf("ERROR! Please enter valid entry\n");
    		radius=valid_or_not();
    	}
    		height=valid_or_not();
    	while(height==-1)
    	{
    		printf("ERROR! Please enter valid entry\n");
    		height=valid_or_not();
    	}
    	switch (result2)
    {
    case 1:
        bsfca = PI * radius * radius;
        lsfca = 2 * PI * radius * height;
        sfca = bsfca + lsfca;
        printf("Base Surface area of a Cylinder :%f\n",bsfca);
        printf("Lateral Surface area of a Cylinder :%f\n",lsfca);
        printf("Surface Area of a Cylinder :%f\n",sfca);
        break;
    case 2:
        perimeter = 4 * 2 * PI * radius + 2 * height;
        printf("Perimeter of a Cylinder :%f\n", perimeter);
        break;
    case 3:
    bsfca = PI * radius * radius;
        volume = bsfca * height;
        printf("Volume of a Cylinder :%f\n",volume);
        break;
    default:
    	 break;
    }
  
}
int valid_or_not()
{
	char ch;
	int control_check=0;
	int sayac=0;
    while((ch= getchar()) != '\n')
    {
        if(ch >='0' && ch<='9')
        {

            sayac=sayac*10+(ch-48);
        }
        else
        {
            control_check++;
        }

    }
    if(control_check==0)
    {
    	return sayac;
    }
    else
    {
    	return -1;
    }
}

