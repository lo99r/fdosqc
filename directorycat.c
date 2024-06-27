#include"qcvars.h"
extern char packtextlist[100][100];
extern system_1 leftandright; // 이게 된다는거죠
//어떻게 고친건가요?
extern int pop; // 이런 식으로 파일 하나에 선언해두고
extern char version[100];

int noter(int caine) {
	if (caine == 1) {
		return 0;
	}
	else {
		return 1;
	}
}

int directorycatlimx(char* i1, char ii[100][100]) {
	leftandright.file.informationkeeps.ihmsi[11] = 0;
	int i = 0;
	int j = 0;
	int k = 0;
	while (1) {
		//returner = i1[k] && i < 100 && j < 100;
		//not
		//int nwenot = not;
		if (noter(i1[k] && i < 100 && j < 100)) {//\/
			ii[j + 1][0] = '\a';
			break;
		}
		if (i1[k] == '\\') {
			j += 1;
			i = 0;
			k++;
			continue;
		}
		ii[j][i] = i1[k];
		i++;
		k++;
	}
	leftandright.file.informationkeeps.ihmsi[11] = 1;
	return 0;
}

int redirectorycatlimx(char ii[100][MAX_PATH], char i1[MAX_PATH]) {
	leftandright.file.informationkeeps.ihmsi[11] = 0;
	memset(i1, 0, MAX_PATH);
	int i = 0;
	int j = 0;
	int k = 0;
	while (1) {
		if (strcmp(ii[j], "\a") == 0/*ii[j + 1][0] == '\a' /* || ii[j + 1][i] == '\a'*/) {//멈춘 지정석
			printf("breaked becouse is ii[%d] == \\a\nverse: %s\n", j, ii[j]);
			break;
		}
		if (ii[j][i] == '\0') {
			//strcat(i1, "\\");
			i1[k] = '\\';
			j += 1;
			i = 0;
			k++;
			if (ii[j][i] == '\a' /*strcmp(ii[j], "\a") || ii[j + 1][i] == '\a'*/) {
				printf("breaked becouse is ii[%d][%d] == \\a\nverse: %c\n", j, i, ii[j][i]);
				break;
			}
			printf("loading(%d): %c\n", k, i1[k]);
			continue;
			//break;
		}
		//strcat(i1, ii[j][i]);
		i1[k] = ii[j][i];
		//i1[k + 1] = '\0';
		i++;
		k++;
	}
	/*int k = 0;
	while (ii[i][j] && k < 100) {
		if(ii[i][j])
	}*/
	leftandright.file.informationkeeps.ihmsi[11] = 1;
	return 0;
}