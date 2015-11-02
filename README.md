#概要
京都大学助教授の大浦拓哉氏がフリーソフトとして提供する
「汎用 FFT (高速 フーリエ/コサイン/サイン 変換) パッケージ」
(http://www.kurims.kyoto-u.ac.jp/~ooura/fft-j.html)
を他言語に移植したものです。

#説明
データ数N(2の冪乗)の1次元データに対して、離散フーリエ・コサイン・サイン変換を行う。
内部でテーブルを利用するタイプで、インプレース型なので破壊的関数である。

#使用方法
void cdft(const int isgn, double *a);	//複素離散フーリエ変換
void rdft(const int isgn, double *a);	//実数離散フーリエ変換
void ddct(const int isgn, double *a);	//離散コサイン変換
void ddst(const int isgn, double *a);	//離散サイン変換
void dfct(double *a, double *t); //実対称フーリエ変換を用いたコサイン変換
void dfst(double *a, double *t); //実非対称フーリエ変換を用いたサイン変換

#ライセンス
原本のライセンスに倣います。
>Copyright Takuya OOURA, 1996-2001
>このソースコードはフリーソフトです．商用目的を含め，このコードの使用， コピー，修正及び配布は自由に行って結構です．ただし，このコードの修正を 行った場合は，そのことを明記してください．
