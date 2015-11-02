/* testxg.cのC++移植版
 * 使い方：
 * fft4g.cppと一緒にコンパイルして実行。
 * 配列サイズ(複素数のデータ数の倍)を指定すれば各種計算を行い、演算誤差を表示する。
 * 表示後は、なにか文字を入力してエンターすれば終了。
 */

#include "fft4g.hpp"
#include <cstdio>
#include <cmath>
#define MAX(x,y) ((x) > (y) ? (x) : (y))

/* random number generator, 0 <= RND < 1 */
#define RND(p) ((*(p) = (*(p) * 7141 + 54773) % 259200) * (1.0 / 259200.0))

#ifndef NMAX
#define NMAX 8192
#define NMAXSQRT 64
#endif

void putdata(int nini, int nend, double *a);
double errorcheck(int nini, int nend, double scale, double *a);

int main()
{
	int n = 1;
	double err;

	printf("data length n=? (must be 2^m)\n");
	scanf("%d", &n);

	fft4g fft(n);
	double *a = new double[n];
	double *t = new double[n / 2 + 1];

	/* check of CDFT */
	putdata(0, n - 1, a);
	fft.cdft(1, a);
	fft.cdft(-1, a);
	err = errorcheck(0, n - 1, 2.0 / n, a);
	printf("cdft err= %g \n", err);

	/* check of RDFT */
	putdata(0, n - 1, a);
	fft.rdft(1, a);
	fft.rdft(-1, a);
	err = errorcheck(0, n - 1, 2.0 / n, a);
	printf("rdft err= %g \n", err);

	/* check of DDCT */
	putdata(0, n - 1, a);
	fft.ddct(1, a);
	fft.ddct(-1, a);
	a[0] *= 0.5;
	err = errorcheck(0, n - 1, 2.0 / n, a);
	printf("ddct err= %g \n", err);

	/* check of DDST */
	putdata(0, n - 1, a);
	fft.ddst(1, a);
	fft.ddst(-1, a);
	a[0] *= 0.5;
	err = errorcheck(0, n - 1, 2.0 / n, a);
	printf("ddst err= %g \n", err);

	/* check of DFCT */
	putdata(0, n, a);
	a[0] *= 0.5;
	a[n] *= 0.5;
	fft.dfct(a, t);
	a[0] *= 0.5;
	a[n] *= 0.5;
	fft.dfct(a, t);
	err = errorcheck(0, n, 2.0 / n, a);
	printf("dfct err= %g \n", err);

	/* check of DFST */
	putdata(1, n - 1, a);
	fft.dfst(a, t);
	fft.dfst(a, t);
	err = errorcheck(1, n - 1, 2.0 / n, a);
	printf("dfst err= %g \n", err);

	delete[] a;
	delete[] t;
	scanf("%d", &n);
	return 0;
}

void putdata(int nini, int nend, double *a)
{
	int j, seed = 0;

	for (j = nini; j <= nend; j++) {
		a[j] = RND(&seed);
	}
}

double errorcheck(int nini, int nend, double scale, double *a)
{
	int j, seed = 0;
	double err = 0, e;

	for (j = nini; j <= nend; j++) {
		e = RND(&seed) - a[j] * scale;
		err = MAX(err, fabs(e));
	}
	return err;
}
