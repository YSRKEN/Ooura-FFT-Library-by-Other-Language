#include <cmath>

class fft4g{
	// �����o�ϐ�
	int *ip;	//�r�b�g���]�Ɏg�p�����Ɨ̈�
	double *w;	//cos��sin�̃e�[�u��(ip[0] == 0���Ə����������)
	int n;		//�z��̗v�f��(2N)
	// �����o�֐�
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
	fft4g(const int);	//�R���X�g���N�^
	~fft4g();			//�f�X�g���N�^
	void cdft(int isgn, double *a);	//���f���U�t�[���G�ϊ�
	void rdft(int isgn, double *a);	//�������U�t�[���G�ϊ�
	void ddct(int isgn, double *a);	//���U�R�T�C���ϊ�
	void ddst(int isgn, double *a);	//���U�T�C���ϊ�
	void dfct(double *a, double *t);	//���Ώ̃t�[���G�ϊ���p�����R�T�C���ϊ�
	void dfst(double *a, double *t);	//����Ώ̃t�[���G�ϊ���p�����T�C���ϊ�
};
