#�T�v
���s��w�������̑�Y��Ǝ����t���[�\�t�g�Ƃ��Ē񋟂���
�u�ėp FFT (���� �t�[���G/�R�T�C��/�T�C�� �ϊ�) �p�b�P�[�W�v
(http://www.kurims.kyoto-u.ac.jp/~ooura/fft-j.html)
�𑼌���ɈڐA�������̂ł��B

#����
�f�[�^��N(2�̙p��)��1�����f�[�^�ɑ΂��āA���U�t�[���G�E�R�T�C���E�T�C���ϊ����s���B
�����Ńe�[�u���𗘗p����^�C�v�ŁA�C���v���[�X�^�Ȃ̂Ŕj��I�֐��ł���B

#�g�p���@
void cdft(const int isgn, double *a);	//���f���U�t�[���G�ϊ�
void rdft(const int isgn, double *a);	//�������U�t�[���G�ϊ�
void ddct(const int isgn, double *a);	//���U�R�T�C���ϊ�
void ddst(const int isgn, double *a);	//���U�T�C���ϊ�
void dfct(double *a, double *t); //���Ώ̃t�[���G�ϊ���p�����R�T�C���ϊ�
void dfst(double *a, double *t); //����Ώ̃t�[���G�ϊ���p�����T�C���ϊ�

#���C�Z���X
���{�̃��C�Z���X�ɕ킢�܂��B
>Copyright Takuya OOURA, 1996-2001
>���̃\�[�X�R�[�h�̓t���[�\�t�g�ł��D���p�ړI���܂߁C���̃R�[�h�̎g�p�C �R�s�[�C�C���y�єz�z�͎��R�ɍs���Č��\�ł��D�������C���̃R�[�h�̏C���� �s�����ꍇ�́C���̂��Ƃ𖾋L���Ă��������D
