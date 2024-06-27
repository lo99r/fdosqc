#include"qcvars.h"
//#include<io.h>
extern char packtextlist[100][100];
extern system_1 leftandright; // 이게 된다는거죠

extern int pop; // 이런 식으로 파일 하나에 선언해두고
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