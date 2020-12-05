typedef struct
{
  double x, y;
}Point;

typedef struct
{
  double mag;
  double deg;
  double dis_center;
  double depth_center;
  Point p;
}Quake;

double measure(Quake *q, double x, double y);
double predict(Quake *q, int a);
double root(double a);
