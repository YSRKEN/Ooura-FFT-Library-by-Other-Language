#include <cmath>

class fft4g{
	// メンバ変数
	int *ip;	//ビット反転に使用する作業領域
	double *w;	//cosとsinのテーブル(ip[0] == 0だと初期化される)
	int n;		//配列の要素数(2N)
	// メンバ関数
	void makewt(int nw, int *ip, double *w);
	void makect(int nc, int *ip, double *c);
	void bitrv2(int n, int *ip, double *a);
	void bitrv2conj(int n, int *ip, double *a);
	void cftfsub(int n, double *a, double *w);
	void cftbsub(int n, double *a, double *w);
	void cft1st(int n, double *a, double *w);
	void cftmdl(int n, int l, double *a, double *w);
	void rftfsub(int n, double *a, int nc, double *c);
	void rftbsub(int n, double *a, int nc, double *c);
	void dctsub(int n, double *a, int nc, double *c);
	void dstsub(int n, double *a, int nc, double *c);
public:
	fft4g(const int);	//コンストラクタ
	~fft4g();			//デストラクタ
	void cdft(int isgn, double *a);	//複素離散フーリエ変換
	void rdft(int isgn, double *a);	//実数離散フーリエ変換
	void ddct(int isgn, double *a);	//離散コサイン変換
	void ddst(int isgn, double *a);	//離散サイン変換
	void dfct(double *a, double *t);	//実対称フーリエ変換を用いたコサイン変換
	void dfst(double *a, double *t);	//実非対称フーリエ変換を用いたサイン変換
};
