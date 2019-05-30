#ifndef QUATERNION_KOVALETZ_H_INCLUDED
#define QUATERNION_KOVALETZ_H_INCLUDED

// �� ��������� �������, �� ���������� ������-����� �������� � ���� ����� �����
// �� 䳿 ����������� � ��������� ����� ������ ���������
typedef struct {
    double Coordinates[3];
}vector3D;//3�-������, �������� ���������
vector3D summ(vector3D a, vector3D b);//���� �������
vector3D subtraction  (vector3D a, vector3D b);//������ �������
vector3D Scalar_mult(vector3D a, double b);//�������� ������� �� ������
double Dot_product(vector3D a,vector3D b);//��������� �������
vector3D Cross_product(vector3D a, vector3D b);//��������� �������
double norm (vector3D a);//������
//��������� ���������
typedef struct
{
    double Im[3];
    double Re;
}Quaternion;
// ������� ��������: ����������� �����������, ���������� �� ������ ����������,������ �� �������� ���������� �� ������
Quaternion Conjudation (Quaternion a);//���������
Quaternion Scalar_div(Quaternion a,double b);//������ ���������� �� ������
Quaternion scalar_mult(Quaternion a, double b);//�������� ���������� �� ������
double Norm (Quaternion a);//������
Quaternion  Reciprocal (Quaternion a);//���������
//��������� ��������
Quaternion Sum (Quaternion a, Quaternion b);//����
Quaternion Subtraction (Quaternion a,Quaternion b);//������
Quaternion Multiplication(Quaternion a, Quaternion b);//�������� ���������� �� ���������
Quaternion Division(Quaternion a, Quaternion b);//������ ���������� �� ���������
Quaternion Multiplication_Vector(Quaternion a, vector3D b);//�������� ���������� �� ������
 typedef struct //3�-�����
{
    vector3D Rad_vec;//�����-������ �����, �� �� ������� � ������� ��������� � ����� � �����;
    //���� ���� �������� ���������� �����
}Point3D ;
Point3D spherical(Point3D x);//������� �� ���������� ��������� �� ���������
Point3D cylindrical (Point3D x);//������� �� ���������� ��������� �� �����������
Point3D Spherical(Point3D x);//�� ��������� �� ����������
Point3D Cylindrical(Point3D x);//�� ����������� �� ����������
Point3D mult_scalar(Point3D x, double a);// �������� �� ������
Point3D add (Point3D x, Point3D movement);
//��������� - ��� ��������. �������� ���� ��������� ��, ������, ����� �������� ������� ��
typedef struct
{
    double angle;
    vector3D axis;
}Angle3D;
//��������� ��� - ��� �� ����� ���������, ����, ��������������� �� ��� �� ����� ���������. ³�� ��������� ��������
//�� ������, ���������������� �� ��� ���� �������, � �����, �� ������� � ���� ����� �����. ����� �� ��������� �������
//� ����� ��������� ������ ���������.
//��� �������� ����������� �� ��� �� ������ ���������
Angle3D get_angle(vector3D a, vector3D b);
// ��������� - 3� ������
typedef struct
{   int num_points;
    int num_edges;
    Point3D *points;
    Point3D *edges[2];
} Figure3D;
Figure3D turn3D(Figure3D f, Angle3D a, Point3D p);// ������� ������
Figure3D projection3D(Figure3D f, Point3D p);//�������� ������
//������� �����-������
int inputDec(double *x,int len);
int inputExp(double *x,int len);
void inputBinFile(double *x, int len,FILE *file);
void inputTextFile(double *x, int len,FILE *file);//��� � ���������� �����
int outputDec(double *x,int len);
int outputExp(double *x,int len);
void outputBinFile(double *x, int len, FILE *file);
void outputTextFile(double *x, int len, FILE *file);
// ��� ��������� ������
vector3D input_DecV3D();
vector3D input_ExpV3D();
vector3D inputTextFileV3D(FILE *file);
vector3D inputBinFileV3D(FILE *file);
void output_DecV3D(vector3D x);
void outputBinFileV3D(vector3D x, FILE *file);
//��� ��������� Quaternion
Quaternion input_DecQuater();
Quaternion input_ExpQuater();
Quaternion inputTextFileQuater(FILE *file);
Quaternion inputBinFileQuater(FILE *file);
void output_DecQuater(Quaternion x);
void output_ExpQuater(Quaternion x);
void outputBinFileQuater(Quaternion x, FILE *file);
void outputTextFileQuater(Quaternion x, FILE *file);
//��� ��������� Point3D
Point3D input_DecP3D();
Point3D input_ExpP3D();
Point3D inputTextFileP3D(FILE *file);
Point3D inputBinFileP3D(FILE *file);
void output_DecP3D(Point3D x);
void output_ExpP3D(Point3D x);
void outputBinFileP3D(Point3D x, FILE *file);
void outputTextFileP3D(Point3D x, FILE *file);
// ��� ��������� Angle3D
Angle3D input_DecAngle3D();
Angle3D input_ExpAngle3D();
Angle3D inputTextFileAngle3D(FILE *file);
Angle3D inputBinFileAngle3D(FILE *file);
void output_DecAngle3D(Angle3D x);
void output_ExpAngle3D(Angle3D x);
void outputBinFileAngle3D(Angle3D x, FILE *file);
void outputTextFileAngle3D(Angle3D x, FILE *file);
// ��� ��������� Figure3D
Figure3D input_DecFigure3D();
Figure3D input_ExpFigure3D();
Figure3D inputTextFileFig3D(FILE *file_points, FILE *file_edges);
Figure3D inputBinFileFig3D(FILE *file_points, FILE *file_edges);
void output_DecFig3D(Figure3D x);
void output_ExpFig3D(Figure3D x);
void outputTextFileFig3D(Figure3D x, FILE *file_points, FILE *file_edges);
void outputBinFileFig3D(Figure3D x, FILE *file_points, FILE *file_edges);


#endif // QUATERNION_KOVALETZ_H_INCLUDED
