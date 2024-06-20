#include "qcvars.h" // 헤더 내에 구조체를 선언하고 그 헤더를 c 파일에서 include하면 이 파일에서 그 구조체를 쓸수 있습니다


extern char packtextlist[100][100];
extern system_1 leftandright; // 이게 된다는거죠

extern int pop;
extern char version[100]/* = { 0, }*/; // 깜빡했는데 extern 해둔거에는 초기화 값 붙이면 안됩니다

int main(int argc, char* argv[2]) {
	system("color 1f");
	FILE* dotoperating = fopen("version.tmy", "ab+");
	fread(version, sizeof(char), 100, dotoperating);
	char argp[50] = { 0 };

	while (1) {
		if (argc == 1)
		{
			//printf("error: i cant boot fdos, there is no option at here");
			system("title fdos boot mode seleting");
			printf("no argument detected, please enter boot mode\n"); // 일단은 임시로 세팅해두는
			scanf("%s", argp);
		}
		else
		{
			strcpy(argp, argv[1]);
		}

		if ((argc == 1) ? strcmp(argp, "setup") == 0 : strcmp(argv[1], "setup") == 0) {//기본 사용자 설정
			system("title fdos user setting");
			//system("echo 이거 님 디렉토리: %%userprofile%%");
			//system("setx fdosstarter \"%%userprofile%%\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\""); // 잠시 주석처리
			//printf("당신의 윈도우즈 유저네임(폴더명)을 입력하세요.\n");//더 안정적인 컴퓨터 컨트롤을 위해서 윈도우즈 사용자 폴더명을 묻는것
			//char windowsusername[100] = {0};
			//scanf("%s", leftandright.file.informationkeeps.himsi[0]);
			printf("당신이 본 프로그램을 열때 사용할 비밀번호를 입력하세요.\n");
			//char userpasswordinfdos[100] = {0};
			scanf("%s", leftandright.file.informationkeeps.himsi[0]);
			printf("드라이브 이름을 입력하세요");
			scanf("%s", leftandright.file.informationkeeps.himsi[1]);
			leftandright.file.informationkeeps.ihmsi[0] = leftandright.directory.cight;
			leftandright.file.informationkeeps.ihmsi[10] = 1;
			FILE* informationuser = fopen("info.2", "wb+");
			fwrite(leftandright.file.informationkeeps.himsi, sizeof(char), 10000, informationuser);
			fclose(informationuser);
			informationuser = fopen("intfo.2", "wb+");
			fwrite(leftandright.file.informationkeeps.ihmsi, sizeof(int), 100, informationuser);
			fclose(informationuser);
		}
		else if ((argc == 1) ? strcmp(argp, "run") == 0 : strcmp(argv[1], "run") == 0) {
			system("title F-DOS 4.06");
			FILE* informationuser = fopen("info.2", "ab+");
			fread(leftandright.file.informationkeeps.himsi, sizeof(char), 10000, informationuser);
			printf("당신이 설정한 비밀번호를 입력하세요.\n");
			char passwordinput[100] = { 0 };
			scanf("%s", passwordinput);
			if (strcmp(passwordinput, leftandright.file.informationkeeps.himsi[0]) == 0) {
				fclose(informationuser);
				informationuser = fopen("intfo.2", "wb+");
				fread(leftandright.file.informationkeeps.ihmsi, sizeof(int), 100, informationuser);
				fclose(informationuser);
				leftandright.directory.cight += 1;
				strcpy(leftandright.directory.directorynowcharacter, leftandright.file.informationkeeps.himsi[2]);
				strcat(leftandright.directory.directorynowcharacter, ":\\");
				strcpy(leftandright.directory.structdirectory_character[0], leftandright.file.informationkeeps.himsi[2]);
				strcat(leftandright.directory.structdirectory_character[0], ":");
				strcpy(leftandright.directory.structdirectory_character[2], "\a");
				printf("비밀번호가 맞습니다. 이제 쉘을 시작하겠습니다.\n");
				system("echo 넘겨\npause > nul");
				system("cls");
				shell();
			}
		}
		else if ((argc == 1) ? strcmp(argp, "exit") == 0 : strcmp(argv[1], "exit") == 0) {
			logoff();
		}
		else {
			printf("0x0");
		}
	}
}