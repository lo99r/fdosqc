#include"qcvars.h"
extern char packtextlist[100][100];
extern system_1 leftandright; // 이게 된다는거죠

extern int pop; // 이런 식으로 파일 하나에 선언해두고
extern char version[100];

void Polzit() {
	switch (pop) {
	case 1:
		printf("hhhhhhh");
		break;
	}
}

TOK_EN testers = AND;
int tokkk() {
	token(testers);
}