#include"qcvars.h"
//#include<io.h>
extern char packtextlist[100][100];
extern system_1 leftandright; // �̰� �ȴٴ°���

extern int pop; // �̷� ������ ���� �ϳ��� �����صΰ�
extern char version[100];

typedef char stringer;

stringer strdir_v[100];

Divliv_t directoryscan(char a[100]) {
	//memset(strdir_v, 100);
	strcpy(strdir_v, leftandright.directory.directorynowcharacter);
	strcat(strdir_v, a);
	strcat(strdir_v, "\\");
	int dirscan = access(strdir_v, 0);
	if (dirscan == 0) {
		return yos;
	}
	else if (dirscan == -1) {
		return n;
	}
	else {
		printf("error: 0x0002");
	}
}