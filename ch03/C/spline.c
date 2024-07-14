#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 11

double f_sin (const double x) {
  return 2.0*sin(x);
}

double f_pow2 (const double x) {
  return x*x;
}

void MyLUsolve (int n, double A[n][n], const double b[n], double u[n]) {
  double c[n];
  int i, j, k;
  double dtemp;

  /* LU分解 */
  for (k=0; k<n-1; k++) {
    dtemp = 1.0 / A[k][k];
    for (i=k+1; i<n; i++) {
      A[i][k] = A[i][k]*dtemp;
    }
    for (j=k+1; j<n; j++) {
      dtemp = A[j][k];
      for (i=k+1; i<n; i++) {
      A[j][i] = A[j][i] - A[k][i]*dtemp;
      }
    }
  }

  /* 前進代入 */
  for (k=0; k<n; k++) {
    c[k] = b[k];
    for (j=0; j<k; j++) {
      c[k] -= A[k][j]*c[j];
    }
  }

  /* 後退代入 */
  u[n-1] = c[n-1]/A[n-1][n-1];
  for (k=n-2; k>=0; k--) {
    u[k] = c[k];
    for (j=k+1; j<n; j++) {
      u[k] -= A[k][j]*u[j];
    }
    u[k] = u[k] / A[k][k];
  }
}

int main() {
  double A[N-1][N-1], b[N], u[N+1], h_j[N];
  double x_j[N+2], y_j[N+2];
  double x, y, aj, bj, cj, dj;
  int i, j;

  /* サンプルデータ */
  x_j[0]  = 0.0;
  x_j[1]  = 0.375;
  x_j[2]  = 0.75;
  x_j[3]  = 1.125;
  x_j[4]  = 1.5;
  x_j[5]  = 1.875;
  x_j[6]  = 2.25;
  x_j[7]  = 2.625;
  x_j[8]  = 3.0;
  x_j[9]  = 3.375;
  x_j[10] = 3.75;
  x_j[11] = 4.125;
  printf("Starts Calculation\n");
  for (i=0; i<N+1; i++) {
    if (i < 5) {
      y_j[i] = f_pow2(x_j[i]);
    } else {
      y_j[i] = f_sin(x_j[i]);
    }
    printf("%d : (x_j[%d], y_j[%d]) (%e, %e)\n", i, i, i, x_j[i], y_j[i]);
  }
  printf("End Calculation\n");
  for (i=0; i<N+1; i++) {
    u[i] = 0.0;
  }

  /* Aとbの係数を作る */
  for (j=0; j<N; j++) {
    h_j[j] =
      x_j[j+1] - x_j[j];
  }
  for (j=1; j<N; j++) {
    b[j] =
      6.0*((y_j[j+1]-y_j[j])/h_j[j] - (y_j[j]-y_j[j-1])/h_j[j-1]);
  }
  for (i=0; i<N-1; i++) {
    for (j=0; j<N-1; j++) {
      A[i][j] = 0.0;
    }
  }
  for (i=0; i<N-1; i++) {
    A[i][i] = 2.0*(h_j[i]+h_j[i+1]);
  }
  for (i=0; i<N-2; i++) {
    A[i][i+1] = h_j[i+1];
  }
  for (i=1; i<N-1; i++) {
    A[i][i-1] = h_j[i];
  }

  /* 連立一次方程式を解く */
  MyLUsolve(N-1, A, &b[1], u);

  /* 補間の実行 */
  printf("Starts Lagrange interpolation\n");
  j = 0;
  for (i=0; i<100; i++) {
    x = 0.0 + (4.125 / 99.0) * (double)i;
    if (x > x_j[j+1]) j++;
    /* 係数の計算 */
    aj = (u[j+1]-u[j])/ (6*(x_j[j+1]-x_j[j]));
    bj = u[j] / 2.0;
    cj = (y_j[j+1]-y_j[j])/(x_j[j+1]-x_j[j]) - (x_j[j+1]-x_j[j])*(2.0*u[j]+u[j+1])/6.0;
    dj = y_j[j];
    /* 三次元スプラインによる近似 */
    y = aj*(x-x_j[j])*(x-x_j[j])*(x-x_j[j]) + bj*(x-x_j[j])*(x-x_j[j]) + cj*(x-x_j[j]) + dj;
    printf("x,y : %e, %e\n", x, y);
  }
  printf("Ends Lagrange interpolation\n");

  return 0;
}
