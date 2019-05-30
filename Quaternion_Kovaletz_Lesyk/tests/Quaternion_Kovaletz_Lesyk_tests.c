#include<stdio.h>
#include<math.h>
#include<malloc.h>
#include"../headers/Quaternion_Kovaletz_Lesyk.h"
double pi=3.14159265358979323846;
int main()
{
    printf("1) Separate numbers using gap when you enter them\n 2)Separate groups of numbers(points, vectors, Quaternion, etc) using key Enter \n");
   //Тестуємо методи для структури Vector3D
    vector3D vector1, vector2;
    double n=3;
    vector1.Coordinates[0]=10;
    vector1.Coordinates[1]=20;
    vector1.Coordinates[2]=30;
    vector2.Coordinates[0]=40;
    vector2.Coordinates[1]=50;
    vector2.Coordinates[2]=60;
    printf("Testing methods for Vector3D:\n");

    vector3D vector;
    vector=input_ExpV3D();
    output_ExpV3D(vector);
    vector=input_DecV3D();
    output_DecV3D(vector);
    printf("Sum of 2 vectors. Expected result (50,70,90):\n");
    output_DecV3D(summ(vector1,vector2));
    printf("Substraction of 2 vectors. Expected result (-30,-30,-30):\n");
    output_DecV3D(subtraction(vector1,vector2));
    printf("Cross product of 2 vectors. Expected result (300,-600,300):\n");
    output_DecV3D(Cross_product(vector1,vector2));
    printf("Product of 2 vectors and scalar. Expected result (30,60,90) and (120,150,180):\n");
    output_DecV3D(Scalar_mult(vector1,n));
    output_DecV3D(Scalar_mult(vector2,n));
    printf("Dot product of 2 vectors. Expected result 3200:\n");
    printf("%f",Dot_product(vector1,vector2));
    Point3D point1;
    printf("Testing methods for Point3D:\n");
    point1=input_ExpP3D();
    output_ExpP3D(point1);
    point1=input_DecP3D();
    output_DecP3D(point1);
    Point3D point;
    point.Rad_vec.Coordinates[0]=10;
    point.Rad_vec.Coordinates[1]=20;
    point.Rad_vec.Coordinates[2]=30;
    printf("Shpherical coordinates of the point. Expected result (37.42, 63.43,36.70):\n");
    output_DecP3D(spherical(point));
    printf("Transition back to Decart coordinates. Expected result (10,20,30):\n");
    output_DecP3D(Spherical(spherical(point)));
    printf("Cylindrical coordinates of the point. Expected result (22.36,63.43,30):\n");
    output_DecP3D(cylindrical(point));
    printf("Transition back to Decart coordinates. Expected result (10,20,30):\n");
    output_DecP3D(Cylindrical(cylindrical(point)));
    Point3D move;
    move.Rad_vec.Coordinates[0]=1;
    move.Rad_vec.Coordinates[1]=2;
    move.Rad_vec.Coordinates[2]=3;
    double m=2;
    printf("Moving point.Expected result (11,22,33):");
    output_DecP3D(add(point,move));
    printf("Product of point and scalar. Expected result (20,40,60):");
   // output_DecP3D(mult_scalar(point,m));*/


    Quaternion quaternion1,quaternion2;
    /*quaternion1=input_ExpQuater();
    output_ExpQuater(quaternion);
    quaternion1=input_DecQuater();
    output_DecQuater(quaternion1);*/
    quaternion1.Re=10;
    quaternion1.Im[0]=10;
    quaternion1.Im[1]=20;
    quaternion1.Im[2]=30;
    quaternion2.Re=30;
    quaternion2.Im[0]=30;
    quaternion2.Im[1]=40;
    quaternion2.Im[2]=50;
    printf("sum of the quaternions. Expected result [40,(40,60,80)]:\n");
    output_DecQuater(Sum(quaternion1, quaternion2));
    printf("subtraction of the quaternions. Expected result [-30,(-20,-20,-30)]:\n");
    output_DecQuater(Subtraction(quaternion1, quaternion2));
    printf("Product of the quaternions. Expected result [-2300,(400,1400,1200)]:\n");
    output_DecQuater(Multiplication(quaternion1, quaternion2));
    printf("Division of the quaternions. Expected result [-0.587,(0.134,0.249,0.268)]:\n");
    output_DecQuater(Division(quaternion1, quaternion2));
    //Quaternion q={1,(1,2,3)};*/


    Angle3D angle;
    angle=input_DecAngle3D();
    output_DecAngle3D(angle);
    angle=input_ExpAngle3D();
    output_ExpAngle3D(angle);
vector3D vector3;
vector3.Coordinates[0]=0;
vector3.Coordinates[1]=1;
vector3.Coordinates[2]=0;
vector3D vector4={(0,1,0)};
vector4.Coordinates[0]=0;
vector4.Coordinates[1]=0;
vector4.Coordinates[2]=1;
angle=get_angle(vector3,vector4);
output_DecAngle3D(angle);

Figure3D figure;//розглядаємо пірамідку
Figure3D figure1;
figure1=input_DecFigure3D();
output_DecFig3D(figure1);
figure1=input_ExpFigure3D();
output_ExpFig3D(figure1);
figure.num_points=4;
figure.num_edges=7;
figure.points = calloc(figure.num_points, sizeof(*figure.points));
for (int i=0;i<2;i++)
{
    figure.edges[i]=calloc(figure.num_edges, sizeof(*figure.edges[i]));
}
figure.points[0].Rad_vec.Coordinates[0]=0;
figure.points[0].Rad_vec.Coordinates[1]=0;
figure.points[0].Rad_vec.Coordinates[2]=0;
figure.points[1].Rad_vec.Coordinates[0]=0;
figure.points[1].Rad_vec.Coordinates[1]=3;
figure.points[1].Rad_vec.Coordinates[2]=4;
figure.points[2].Rad_vec.Coordinates[0]=0;
figure.points[2].Rad_vec.Coordinates[1]=5;
figure.points[2].Rad_vec.Coordinates[2]=6;
figure.points[3].Rad_vec.Coordinates[0]=0;
figure.points[3].Rad_vec.Coordinates[1]=0;
figure.points[3].Rad_vec.Coordinates[2]=1;
figure.edges[0][0]=figure.points[0];
figure.edges[1][0]=figure.points[1];
figure.edges[0][1]=figure.points[0];
figure.edges[1][1]=figure.points[2];
figure.edges[0][2]=figure.points[0];
figure.edges[1][2]=figure.points[3];
figure.edges[0][3]=figure.points[2];
figure.edges[1][3]=figure.points[3];
figure.edges[0][4]=figure.points[1];
figure.edges[1][4]=figure.points[3];
figure.edges[0][5]=figure.points[1];
figure.edges[1][5]=figure.points[2];
Point3D point2;
point2=figure.points[0];
output_DecFig3D(figure);
printf("turn3D\n");
output_DecFig3D(turn3D(figure,angle,point2));
printf("We get figure turned as was expected");
printf("prjection3d\n");
point2=figure.points[3];
output_DecFig3D(projection3D(figure,point2));
printf("We get points  (0,0,0),(0,0,0),(0,3,0),(0,5,0),as was expected");    return 0;
return 0;
}
