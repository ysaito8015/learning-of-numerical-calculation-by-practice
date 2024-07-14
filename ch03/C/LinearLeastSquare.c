#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f (const double x) {
  return 3.1 + 4.1*x + 5.9*x*x + 2.6*x*x*x + 5.3*sin(x);
}

double f_0 (const double x) {
  return 1.0;
}

double f_1 (const double x) {
  return x;
}

double f_2 (const double x) {
  return x*x;
}

double f_3 (const double x) {
  return x*x*x;
}

double f_4 (const double x) {
  return sin(x);
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

#define N 50
#define M 5

int main() {
  double A[M][M], va[M], vb[M], x_j[N], y_j[N], x, y, fk, fi, dtemp;
  int i, j, k;

  /* サンプルデータ */
  x = -2.0;
  for (i=0; i<N; i++) {
    x = -2.0 + (4.0 / (double)N) * (double)i;
    x_j[i] = x;
    y_j[i] = f(x) + ((double)(rand()%65535)/65535.0) * f(x) * 0.5;
  }

  /* 係数A, bの設定部分 */
  for (i=0; i<M; i++) {
    for (k=0; k<M; k++) {
      dtemp = 0.0;
      for (j=0; j<N; j++) {
        if (k == 0) fk = f_0(x_j[j]);
        if (k == 1) fk = f_1(x_j[j]);
        if (k == 2) fk = f_2(x_j[j]);
        if (k == 3) fk = f_3(x_j[j]);
        if (k == 4) fk = f_4(x_j[j]);
        if (i == 0) fi = f_0(x_j[j]);
        if (i == 1) fi = f_1(x_j[j]);
        if (i == 2) fi = f_2(x_j[j]);
        if (i == 3) fi = f_3(x_j[j]);
        if (i == 4) fi = f_4(x_j[j]);
        dtemp += fk * fi;
      }
      A[k][i] = dtemp;
	}
  }
  for (k=0; k<M; k++) {
    dtemp = 0.0;
    for (j=0; j<N; j++) {
      if (k == 0) fk = f_0(x_j[j]);
	  if (k == 1) fk = f_1(x_j[j]);
      if (k == 2) fk = f_2(x_j[j]);
	  if (k == 3) fk = f_3(x_j[j]);
      if (k == 4) fk = f_4(x_j[j]);
	  dtemp += fk * y_j[j];
    }
    vb[k] = dtemp;
  }
  for (i=0; i<M; i++) {
    for (j=0; j<M; j++) {
	  printf(" %f", A[i][j]);
	}
	printf("\n");
  }

  /* 連立一次方程式を解く */
  MyLUsolve(M, A, vb, va);

  /* 結果の出力 */
  j = 0;
  for (i=0; i<100; i++) {
    x = -2.0 + (4.0 / 100.0) * (double)i;
    /* x軸の点xにおける近似曲線の計算 */
    y = va[0]*f_0(x) + va[1]*f_1(x) + va[2]*f_2(x) + va[3]*f_3(x) + va[4]*f_4(x);
    printf("%e %e\n",x, y);
  }

  return 0;
}
