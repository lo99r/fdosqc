#include "qcvars.h" // ��� ���� ����ü�� �����ϰ� �� ����� c ���Ͽ��� include�ϸ� �� ���Ͽ��� �� ����ü�� ���� �ֽ��ϴ�


extern char packtextlist[100][100];
extern system_1 leftandright; // �̰� �ȴٴ°���

extern int pop;
extern char version[100]/* = { 0, }*/; // �����ߴµ� extern �صаſ��� �ʱ�ȭ �� ���̸� �ȵ˴ϴ�

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
			printf("no argument detected, please enter boot mode\n"); // �ϴ��� �ӽ÷� �����صδ�
			scanf("%s", argp);
		}
		else
		{
			strcpy(argp, argv[1]);
		}

		if ((argc == 1) ? strcmp(argp, "setup") == 0 : strcmp(argv[1], "setup") == 0) {//�⺻ ����� ����
			system("title fdos user setting");
			//system("echo �̰� �� ���丮: %%userprofile%%");
			//system("setx fdosstarter \"%%userprofile%%\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\""); // ��� �ּ�ó��
			//printf("����� �������� ��������(������)�� �Է��ϼ���.\n");//�� �������� ��ǻ�� ��Ʈ���� ���ؼ� �������� ����� �������� ���°�
			//char windowsusername[100] = {0};
			//scanf("%s", leftandright.file.informationkeeps.himsi[0]);
			printf("����� �� ���α׷��� ���� ����� ��й�ȣ�� �Է��ϼ���.\n");
			//char userpasswordinfdos[100] = {0};
			scanf("%s", leftandright.file.informationkeeps.himsi[0]);
			printf("����̺� �̸��� �Է��ϼ���");
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
			printf("����� ������ ��й�ȣ�� �Է��ϼ���.\n");
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
				printf("��й�ȣ�� �½��ϴ�. ���� ���� �����ϰڽ��ϴ�.\n");
				system("echo �Ѱ�\npause > nul");
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