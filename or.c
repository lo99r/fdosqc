#include"qcvars.h"
#include <stdint.h>

extern char packtextlist[100][100];
extern system_1 leftandright; // 이게 된다는거죠

extern int pop; // 이런 식으로 파일 하나에 선언해두고
extern char version[100];

//010607???

//unsigned _stdCELl
//beginthreadex

/*8typedef enum tokens {
	AND,//0x00 2
	ORB,//0x01 2
	NOT,//0x02 3
	XOR,//0x03 2
	OUP,//0x04 2
	INP,//0x05 1
	MOV,//0x06 2
	CEL,//0x07 1
	HEX,//0x08 2 cpy
	STC,//0x09 2 cat
	HLT//0x0A 00
}TOK_EN; */

FILE* getcharacter;

TOK_EN inputedtoken = NUL;

int8_t bincard[256] = {0,};

int orer(char jljljl[256]) {
	char inputing[256];
	//sscanf_s(jljljl, "%s", inputing, sizeof(inputing));
	strcpy(inputing, jljljl);
	getcharacter = fopen(inputing, "rb");
	if (!getcharacter) {
		MessageBox(NULL, TEXT("error in open file"), TEXT("error!!!"), MB_ICONERROR | MB_OK);
		return 0;
	}
	size_t read_count = fread(&bincard, sizeof(int), 256, getcharacter);
	if (read_count != 256) {
		printf("size of file isn\'t 256");
	}
	int i = 0;
	while (1) {
		if ((TOK_EN)bincard[i] == AND) {
			leftandright.memory.rem.var[bincard[i + 1]] = (bincard[i + 2] == 0) ? 0 : ((bincard[i + 2] == 1) ? 0 : ((bincard[i + 2] == 2) ? 0 : 1));
			i += 3;
		}
		else if ((TOK_EN)bincard[i] == ORB) {
			leftandright.memory.rem.var[bincard[i + 1]] = (bincard[i + 2] == 0) ? 0 : ((bincard[i + 2] == 1) ? 1 : ((bincard[i + 2] == 2) ? 1 : 1));
			i += 3;
		}
		else if ((TOK_EN)bincard[i] == NOT) {
			if (bincard[i + 2] == 0) {
				leftandright.memory.rem.var[bincard[i + 1]] = noter(bincard[i + 3]);
			}
			else {
				leftandright.memory.rem.var[bincard[i + 1]] = noter(leftandright.memory.rem.var[bincard[i + 3]]);
			}
			i += 4;
		}
		else if ((TOK_EN)bincard[i] == XOR) {
			leftandright.memory.rem.var[bincard[i + 1]] = (bincard[i + 2] == 0) ? 0 : ((bincard[i + 2] == 1) ? 1 : ((bincard[i + 2] == 2) ? 1 : 0));
			i += 3;
		}
		else if ((TOK_EN)bincard[i] == OUP) {
			//leftandright.memory.rem.var[bincard[i + 1]] = (bincard[i + 2] == 0) ? 0 : ((bincard[i + 2] == 1) ? 1 : ((bincard[i + 2] == 2) ? 1 : 0));
			if (bincard[i + 1] == 0) {
				printf("%d", leftandright.memory.rem.var[bincard[i + 2]]);
			}
			else {
				if (bincard[i + 2] == 0x1a) {
					printf("\n");
				}
				else {
					printf("%c", leftandright.memory.rem.var[bincard[i + 2]]);
				}
			}
			i += 3;
		}
		else if ((TOK_EN)bincard[i] == INP) {
			scanf("%d", &leftandright.memory.rem.var[bincard[i + 1]]);
			i += 2;
		}
		else if ((TOK_EN)bincard[i] == MOV) {
			leftandright.memory.rem.var[bincard[i + 1]] = leftandright.memory.rem.var[bincard[i + 2]];
			leftandright.memory.rem.var[bincard[i + 2]] = 0;
			i += 3;
		}
		else if ((TOK_EN)bincard[i] == CEL) {
			/*leftandright.memory.rem.var[bincard[i + 1]] = leftandright.memory.rem.var[bincard[i + 2]];
			leftandright.memory.rem.var[bincard[i + 2]] = 0;*/
			i = bincard[i + 1];
			//i += 2;
		}
		else if ((TOK_EN)bincard[i] == HEX) {
			if (bincard[i + 2] == 0) {
				leftandright.memory.rem.var[bincard[i + 1]] = leftandright.memory.rem.var[bincard[i + 3]];
			}
			else {
				leftandright.memory.rem.var[bincard[i + 1]] = bincard[i + 3];
			}
			i += 4;
		}
		else if ((TOK_EN)bincard[i] == STC) {
			if (bincard[i + 2] == 0) {
				leftandright.memory.rem.var[bincard[i + 1]] += leftandright.memory.rem.var[bincard[i + 2]];
			}
			else {
				leftandright.memory.rem.var[bincard[i + 1]] += bincard[i + 3];
			}
			i += 4;
		}
		else if ((TOK_EN)bincard[i] == HLT) {
			//leftandright.memory.rem.var[bincard[i + 1]] += leftandright.memory.rem.var[bincard[i + 2]];
			//i += 1;
			printf("and..?");
			break;
		}
		else {
			printf("or... error in i = %d\n", i);
			MessageBox(NULL, TEXT("or 스크립트에 오류가 발생했습니다."), TEXT("error!!!"), MB_ICONERROR | MB_OK);
			break;
			//i += 1;
		}
	}
	printf("i = %d\n");
	return 0;
}