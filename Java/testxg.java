/* testxg.cのJava移植版
 * 使い方：
 * fft4g.javaと一緒にコンパイルして実行。
 * 配列サイズ(複素数のデータ数の倍)を指定すれば各種計算を行い、演算誤差を表示する。
 * 表示後は、なにか文字を入力してエンターすれば終了。
 */

import java.util.Scanner;

public class testxg{
	static int seed;
	public static void main(String args[]){
		// 入力
		System.out.println("data length n=? (must be 2^m)");
		Scanner scan = new Scanner(System.in);
		int n = Integer.parseInt(scan.next());
		// 処理
		fft4g fft = new fft4g(n);
		double[] a = new double[n + 1], t = new double[n / 2 + 1];
		double err;

		/* check of CDFT */
		putdata(0, n - 1, a);
		fft.cdft(1, a);
		fft.cdft(-1, a);
		err = errorcheck(0, n - 1, 2.0 / n, a);
		System.out.println("cdft err= " + err);

		/* check of RDFT */
		putdata(0, n - 1, a);
		fft.rdft(1, a);
		fft.rdft(-1, a);
		err = errorcheck(0, n - 1, 2.0 / n, a);
		System.out.println("rdft err= " + err);

		/* check of DDCT */
		putdata(0, n - 1, a);
		fft.ddct(1, a);
		fft.ddct(-1, a);
		a[0] *= 0.5;
		err = errorcheck(0, n - 1, 2.0 / n, a);
		System.out.println("ddct err= " + err);

		/* check of DDST */
		putdata(0, n - 1, a);
		fft.ddst(1, a);
		fft.ddst(-1, a);
		a[0] *= 0.5;
		err = errorcheck(0, n - 1, 2.0 / n, a);
		System.out.println("ddst err= " + err);

		/* check of DFCT */
		putdata(0, n, a);
		a[0] *= 0.5;
		a[n] *= 0.5;
		fft.dfct(a, t);
		a[0] *= 0.5;
		a[n] *= 0.5;
		fft.dfct(a, t);
		err = errorcheck(0, n, 2.0 / n, a);
		System.out.println("dfct err= " + err);

		/* check of DFST */
		putdata(1, n - 1, a);
		fft.dfst(a, t);
		fft.dfst(a, t);
		err = errorcheck(1, n - 1, 2.0 / n, a);
		System.out.println("dfst err= " + err);
		scan.next();
	}
	private static void putdata(int nini, int nend, double[] a){
		seed = 0;
		for(int j = nini; j <= nend; j++){
			a[j] = rnd();
		}
	}
	private static double errorcheck(int nini, int nend, double scale, double[] a){
		seed = 0;
		double err = 0;
		for(int j = nini; j <= nend; j++) {
			double e = rnd() - a[j] * scale;
			err = Math.max(err, Math.abs(e));
		}
		return err;
	}
	private static double rnd(){
		seed = (seed * 7141 + 54773) % 259200;
		return 1.0 * seed / 259200;
	}
}
