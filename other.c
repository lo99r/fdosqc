#include"qcvars.h"
extern char packtextlist[100][100];
extern system_1 leftandright; // 이게 된다는거죠

extern int pop; // 이런 식으로 파일 하나에 선언해두고
extern char version[100];

extern int pop; // 이렇게 다른 파일에서 그 변수에 접근해야 할때 extern을 쓰는겁니다
//그러면 구조체는 아이고 구조체는요?
int scaning() {
	if (leftandright.file.filetype == 0) {
		fscanf(leftandright.file.iwanteatstake, "%d %d %d %s", &leftandright.io.commandnumber[0], &leftandright.io.commandnumber[1], &leftandright.io.commandnumber[2], leftandright.io.commandcharacter);
	}
	else {
		sscanf(leftandright.memory.rem.bin, "%d %d %d %s", &leftandright.io.commandnumber[0], &leftandright.io.commandnumber[1], &leftandright.io.commandnumber[2], leftandright.io.commandcharacter);
	}
	return 0;
}

int logoff() {
	if (leftandright.directory.cight <= -1) {
		printf("error: 0x1003\n");
	}
	//system("start explorer.exe");
	//system("start devenv.exe");
	exit(0);
}

int programlog(char* enostram, char* inputstring) {
	strcat(enostram, ".log");
	FILE* log = fopen(enostram, "a+");
	fprintf(log, "%s", inputstring);
	fclose(log);
	return 0;
}

int root(int i1, int i2, int i3, int i4, char i5[100]) {
	switch (i1) {
	case 0:
		printf("we are print developer command code list\n0 print it list\n 1 print opsion\n2 input at varible\n3 if A and B is equal?\n4 var add\n5 var readd\n6 var delete\n7 shutdown\n8 end code\n program command ver is it 1.0");
		break;
	case 1:
		printf("%s", i5);//4.05.0.03
		break;
	case 2:
		scanf("%d", &leftandright.memory.rem.var[i2]);
		break;
	case 3:
		leftandright.file.iflevel += 1;
		if (leftandright.memory.rem.var[i2] != leftandright.memory.rem.var[i3]) {
			leftandright.file.ifcapture = leftandright.file.iflevel;
			while (1) {
				if (leftandright.io.commandnumber[0] == 8) {
					if (leftandright.io.commandnumber[3] == leftandright.file.iflevel) {
						return 3;
					}
				}
				else {
					scaning();
				}
			}
		}
		break;
	case 4:
		leftandright.memory.rem.var[i2] = i3;
		break;

	case 5:
	case 6:
		printf("error: command4 or command5 is dead command. so you dont this command...");
		break;
	case 7: 
		logoff();
		break;
	case 8:;
		char stringlogs[2][100] = { "ifandlogs", "iglog: peace" };
		programlog(stringlogs[0], stringlogs[1]);
		return 90;
		break;
	default:
		printf("error: 0x1004");
		break;
	}
	return 0;
}