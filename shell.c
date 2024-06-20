#include"qcvars.h"
extern char packtextlist[100][100];
extern system_1 leftandright; // 이게 된다는거죠

extern int pop; // 이런 식으로 파일 하나에 선언해두고
extern char version[100];

int startword() {
	printf("(c)creams lemoncoream for daramnyang operating shell 2023-2024\n크림즈 레몬코림 fdos %s\n", &version);
	return 0;
}

int command_cd() {
	leftandright.file.informationkeeps.ihmsi[1] = 0;
	MessageBox(NULL, TEXT("현재 디렉토리에서 다른 디렉토리로 이동하시겠습니까?"), TEXT("선택권 없음..."), MB_OK);
	//leftandright.directory.directorynowcharacter[leftandright.directory.cight];
	printf("옮길 디렉토리로 이동\n..는 뒤로갑니다.\n");
	scanf("%s", leftandright.file.informationkeeps.himsi[10]);
	if (strcmp(leftandright.file.informationkeeps.himsi[10], "..") == 0) {
		memset(leftandright.directory.structdirectory_character[leftandright.directory.cight], '\0', MAX_PATH);
		leftandright.directory.cight -= 1;
		int xount = 0;
		memset(leftandright.directory.structdirectory_character[leftandright.directory.cight], '\0', MAX_PATH);
		strcpy(leftandright.directory.structdirectory_character[leftandright.directory.cight], "\a");
	}
	else if (strcmp(leftandright.file.informationkeeps.himsi[10], ".") == 0) {
		int ppp = 0;
	}
	else if (directoryscan(leftandright.file.informationkeeps.himsi[10]) == n) {
		printf("없는 폴더입니다.\nerror: 0x1002");
		return 0;
	}
	else {
		strcpy(leftandright.directory.structdirectory_character[leftandright.directory.cight], leftandright.file.informationkeeps.himsi[10]);
	}
	leftandright.directory.cight++;
	leftandright.file.informationkeeps.ihmsi[1] = 1;
}

unsigned _stdcall toroop(void* arg) {
	while (1) {
		while (leftandright.file.informationkeeps.ihmsi[1]) {
			strcpy(leftandright.directory.structdirectory_character[leftandright.directory.cight], "*");
		}
	}
}

int shell() {
	startword();
	_beginthreadex(NULL, 0, toroop, 0, 0, NULL);
	while (1) {
		//scanf("%d %d %d %s", &leftandright.io.commandnumber[0], &leftandright.io.commandnumber[1], &leftandright.io.commandnumber[2], leftandright.io.commandcharacter);
		char commandinputer[100] = { 0, };
		int Panert = 0;
		scanf("%s", commandinputer); // 뒤에 들어가는거 뭐임/*leftandright.memory.remdriveremembersystem.systempackagerfile*/
		if (strcmp(commandinputer, "ver") == 0) {
			printf("fdos quick and cool 5.0.01\n");
		}
		else if (strcmp(commandinputer, "dir") == 0) {
			redirectorycatlimx(leftandright.directory.structdirectory_character, leftandright.directory.directorynowcharacter);
			printf("error: 0x1001");
			/*//DIR* setis = opendir();
			DIR            *dir_info;
			struct dirent  *dir_entry;

			//mkdir( "test_A"     , 0755);           // 실행 파일이 있는 곳에 생성
			//mkdir( "test_B"     , 0755);           // 실행 파일이 있는 곳에 생성

			dir_info = opendir( ".");              // 현재 디렉토리를 열기
			if ( NULL != dir_info)
			{
				while( dir_entry   = readdir( dir_info)){ // 디렉토리 안에 있는 모든 파일과 디렉토리 출력
					printf( "%s\n", dir_entry->d_name);
				}
				closedir( dir_info);
			}*/

			//코드를 윈도우 기준으로 짜드리도록 하죠
			//주석좀...
			//제가 모르는 거가 많아요

			HANDLE file_search_handle = INVALID_HANDLE_VALUE; // 윈도우의 대부분의 함수들은 HANDLE을 이용해야 사용 가능
			WIN32_FIND_DATAA file_list_data = { 0 }; // 대충 검색한 파일에 대해 찾은 정보가 저장됩니다🤔
			char search_bool = 0;
			char USA_B[MAX_PATH] = { 0, };

			strcpy(USA_B, leftandright.directory.directorynowcharacter);
			strcat(USA_B, "*");
			printf("\n현재 디렉토리: %s\n전툰입력값: %s\n", leftandright.directory.directorynowcharacter, USA_B);

			file_search_handle = FindFirstFileA(USA_B /* leftandright.directory.directorynowcharacter"*"는 파일 이름, 확장자 상관 없이 모든 파일을 검색한다는 뜻*/, /*"m:\\jojo\\*"*/
				&file_list_data /*포인터로 전달해주셔야 합니다*/); // 파일 검색에 사용할 HANDLE을 생성해주는 함수입니다

			if (file_search_handle != INVALID_HANDLE_VALUE) { // HANDLE이 정상적으로 생성되었다면 받아온 값은 INVALID_HANDLE_VALUE가 아닙니다
				search_bool = 1;
				while (search_bool) {
					printf("%s\n", file_list_data.cFileName); // 이건 뭐 알거라 생각하고
					search_bool = FindNextFileA(file_search_handle, &file_list_data); // 생성한 HANDLE을 그대로 이용하여 다음 파일을 검색합니다
					// 더 이상 파일이 남아있지 않을때는 반환값이 0이 되게 됩니다
				}

				FindClose(file_search_handle); // 보통 윈도우에서 HANDLE의 사용이 끝났을때는 CloseHandle을 써야 하지만
				// 파일을 찾을때 사용되는 HANDLE의 경우에는 특수한 녀석이기에 FindClose를 써줘야 합니다
				// -끝-
				//그런데 이 코드가 실행되는 위치를 정해야되잖아요 그래서 endirectorynow함수를 정의 한것이에요...

				// 이 shell 함수에선 endirectorynow를 호출하고 있지 않습니다만?\
                    //제말은 현재 위치를담은 변수

					// 이곳은 윈도우, 리눅스 기준으로 생각하면 낭패입니다
					// 저렇게 다 적어줘야 한다는 것이오

					// 그리고 잠시 endirectorynow로 가보시죠
			}
			else {
				int i = 0;
				while (1) {
					if (strcmp(leftandright.directory.structdirectory_character[i], "\a") == 0) {
						printf("[%d]%%\\a", i);//leftandright.directory.structdirectory_character[i]
					}
					if (i == 100) {
						break;
					}
					printf("[%d]%s\n", i, leftandright.directory.structdirectory_character[i]);
					i++;
				}
				printf("error: 0x0004 0x1000");
			}
		}
		else if (strcmp(commandinputer, "release") == 0) {
			printf("다람냥 운영환경 5.0 quick and cool 릴리즈\n\
\n5.0.01\n\
\n+ 빠르고 시원해짐\n\
\n버그제보: lookout1423@gmail.com\n");
			//system("start msedge.exe lookout1423@gmail.com");
		}
		else if (strcmp(commandinputer, "cd") == 0) {
			command_cd();
		}
		else if (strcmp(commandinputer, "errorcodes") == 0) {
			printf("\
0x0 운영환경 예외\n\
\n\
0x0000 부팅모드 선택 중 예외\n\
0x0001 명령어 선택 중 예외\n\
0x0002 divuse.c에서 0도 -1도 아닌 예외\n\
0x0003 기타 파일 열기에서 0도 -1도 아닌 예외\n\
0x0004 운영환경 잘못 된 값 예외\n\
\n\
0x1 운영환경 기본 프로그램 예외\n\
\n\
0x1000 운영환경 dir 에서 잘못된 디렉토리\n\
0x1001 운영환경 배열 <-> 문자열 변환기에서 중도 오류\n\
0x1002 운영환경 cd 에서 잘못된 디렉토리\n\
0x1003 운영환경 로그오프중 예외\n\
0x1004 운영환경 데브 스크립트중 오류\n\
0x1005 운영환경 바이러스 침투 감지\n\
0x1006 운영환경 내부 붕괴 감지\n\
\n\
현재버전에서 일어날 수 있는 모든 오류 측정완료...\n");
		}
		else if (strcmp(commandinputer, "help")) {
			printf("ver 버전\ndir 폴더\ncd 폴더에 들어가기\nrelease 릴리즈 노트\nerrorcodes 오류 코드들\nㅗ디ㅔ ahffkdy?\\ㅜexit 나가요!");
		}
		else if (strcmp(commandinputer, "exit") == 0) { // 잘못 끄셨는디?
			printf("본 프로그램을 종료합니다.\n");
			break;
		}
		else {
			int major = access(commandinputer, 0);
			if (major == 0) {
				printf("아직 개발중인 기능입니다.");
			}
			else if (major == -1) {
				printf("error: 0x0001\n");
			}
			else {
				printf("error: 0x0003");
			}
		}
	}
	return 0;
}