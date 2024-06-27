// 헤더에서 만든 변수 extern 같은걸로 빼보세요 여긴 선언만 두고
//?
#pragma once
#ifndef VARS_H
#define VARS_H

#define da 1

#define _CRT_SECURE_NO_WARNINGS

//made in china

#include<stdio.h>//include "stdio.h"
#include<stdlib.h>
#include<conio.h>//include "conio.h"
#include<stdlib.h>//include "stdlib.h"
#include<math.h>//include "math.h"
#include<string.h>//include "string.h"
#include<windows.h>//include "windows.h"
#include<process.h>
#include<io.h>

typedef enum tokens {
	AND,//0x00
	ORB,//0x01
	NOT,//0x02
	XOR,//0x03
	OUP,//0x04
	INP,//0x05
	MOV,//0x06
	CEL,//0x07
	HEX,//0x08
	STC,//0x09
	HLT,//0x0A
	NUL
}TOK_EN;

//COORD

#define clss system("cls")
#define colors(backer, downer) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (backer * 16) + downer)
#define darkmodes system("0f")
#define whitemodes system("f0")
#define token(kokk) printf("%02x", kokk)
#define typers 0x18//1319
#define curposgens(x, y) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {(short)x, (short)y})
#define ands(hexbinn) (hexbinn == 0) ? 0 : ((hexbinn == 1) ? 0 : ((hexbinn == 2) ? 0 : 1)))
#define ors(hexbinn) (hexbinn == 0) ? 0 : ((hexbinn == 1) ? 1 : ((hexbinn == 2) ? 1 : 1)))

typedef struct system//?
{
	struct Memory
	{
		struct Rem {
			int var[100];
			int count[100];
			char bin[100];
		} rem;

		struct Remdriveremembersystem {
			FILE* systempackagerfile;
		} remdriveremembersystem;
	} memory;

	struct Filer {
		int filetype;
		FILE* iwanteatstake;
		int iflevel;
		int ifcapture;
		struct Informationkeeps {
			char himsi[100][100];
			int ihmsi[100];
			char winusrname[100];
			char usrpwdinfdos[100];
		} informationkeeps;
	} file;
	struct directories {
		char directorynowcharacter[/*100 */MAX_PATH];
		char structdirectory_character[100][MAX_PATH];
		int cight;
	}directory;
	struct io {
		int commandnumber[4];
		char commandcharacter[100];
	}io;
} system_1; // 헤더에 구조체를 선언해놨죠

//sscanf();
//"ui 0 0 0 0 0 0"

//extern v

int noter(int caine);

int directorycatlimx(char* i1, char ii[100][100]);

int redirectorycatlimx(char ii[100][MAX_PATH], char i1[MAX_PATH]);

int scaning();

int logoff();

int programlog(char* enostram, char* inputstring);

int startword();

int command_cd();

unsigned _stdcall toroop(void* arg);

int shell();

int root(int i1, int i2, int i3, int i4, char i5[100]);
//?
void Polzit();

typedef enum divliv {
	yos,
	n
}Divliv_t;

Divliv_t directoryscan(char a[100]);

int orer(char jljljl[256]);

#endif