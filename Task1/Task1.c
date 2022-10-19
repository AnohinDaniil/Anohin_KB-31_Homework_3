#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

 void Func(int a, int b, int c)
 {
    double x1, x2;
    int D;
    printf("\nКвадратное уравнение: (%d)*x^2 + (%d)*x + (%d) = 0", a, b, c);

    D = pow(b,2)-4*a*c;
    if(D > 0)
    {
      x1 = (double)(-b + sqrt(D))/(2*a);
      x2 = (double)(-b - sqrt(D))/(2*a);
      printf("\nУравнение имеет два корня: x1 = %.3f и x2 = %.3f", x1, x2);
    }
    if(D == 0)
    {
      x1 = -b/(2*a);
      printf("\nУравнение имеет один корень: x1 = %.3f ", x1);
    }
    if(D < 0)
    {
      printf("\nУравнение не имеет корней, так как дискриминант меньше 0: (D = %d) ", D);
    }
    printf("\n\n");
 }

int main(int argc, char **argv) 
{ 
  setlocale(LC_ALL, "Rus");
  int a, b, c;
  a = atoi(argv[1]);
  b = atoi(argv[2]);
  c = atoi(argv[3]);
  Func(a, b, c);
}
