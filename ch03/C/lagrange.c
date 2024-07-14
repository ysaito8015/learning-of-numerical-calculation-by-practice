#include <stdio.h>
#include <math.h>

#define PI 3.14159265

double l_j (double x, int j, int N, const double *x_j) {
  int i;
  double x_u, x_l;

  x_u = 1.0;
  x_l = 1.0;
  for (i=0; i<N+1; i++) {
    if (j != i) {
      x_u *= x - x_j[i];
      x_l *= x_j[j] - x_j[i];
    }
  }
  return x_u / x_l;
}

int main() {
  double x, y, x_j[6], y_j[6];
  int N, i, j;

  N = 5;
  x_j[0] = PI*(1.0/4.0-1.0/3.0);
  x_j[1] = PI*(1.0/4.0+1.0/7.0);
  x_j[2] = PI*(1.0/2.0-1.0/8.0);
  x_j[3] = PI*(1.0/2.0+1.0/6.0);
  x_j[4] = PI*(4.0/5.0);
  x_j[5] = PI*(5.0/6.0);
  for (i=0; i<N+1; i++) {
    y_j[i] = cos(x_j[i]);
  }

  /* 補間計算 */
  for (i=0; i<100; i++ ){
    x = -0.5 + (PI / 100.00) * (double)i;
    y = 0.0;
    for (j=0; j<N+1; j++) {
      y += y_j[j] * l_j(x, j, N, x_j);
    }
    printf("%e %e\n", x, y);
  }

  return 0;
}

