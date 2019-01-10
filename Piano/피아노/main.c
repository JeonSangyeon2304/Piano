#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#pragma comment(lib, "Kernel32.lib")
#pragma warning(disable: 4996)

struct melody { 
	char name[20]; // Array space to store music name
	char song[2000]; // Array space to store music
	char pwd[4]; // Array space to store passwords
};

int tones[] = { 262, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494, 523, 554, 587, 622, 659, 699, 740 };	// 음계 별 주파수 배열 선언

//Recode fuction
void music(char *);

int main() {
	struct melody a[3] = { { "학교종", "g3g3h3h3g3g3d5g3g3d3d3s6g3g3h3h3g3g3d5g3d3s3d3a6", "1234" }, 0 };	// 구조체 선언. 학교종, 학교종의 계이름 및 박자, 비밀번호를 선언
	
	int sel, num, sing; // 메뉴 선택 변수
	char input[200]; // 음계와 박자를 입력 받을 배열 200개 선언
	char PD[4]; // 비밀번호 4자리 선언
	int i, j, n, m, cnt; // 반복변수

	printf("= 피아노 프로그램 ==\n\n");
	printf("++++한곡당 최대 음수 1000개+++++\n");
	printf("++++음 -> 음길이 순으로 입력++++\n");
	printf("++++Example : 도2레2 ++++\n");
	printf("++++비밀번호 최대 4자리까지 입력++++\n");
	printf("++++2옥타브 파를 입력할 시에는 큰따옴표 입력\n"); // 메뉴얼 출력


	while (1) {
		printf("저장된 곡 목록\n"); // 저장된 곡 목록 출력
		for (j = 0; j < 3; j++) { // 저장된 곡 목록을 3번 출력한다.
			if (a[j].name[0] == 0)  // 조건문. name[]배열에 저장된 것이 없다면
				printf("%d. 없음\n", j + 1); // "없음"을 출력한다.
			else // 그게 아니라면
				printf("%d. %s\n", j + 1, a[j].name); // 저장된 노래 제목을 출력한다
		}
		printf("\n");
		printf("메뉴\n");
		printf("1. 곡 입력\n");
		printf("2. 곡 듣기\n");
		printf("3. 곡 삭제\n");
		printf("x. 종료\n\n");
		printf("메뉴 선택 : ");

		scanf("%d", &sel); // 메뉴 선택 입력
		switch (sel) { // 메뉴 선택 조건문
		case 1: // 1번 선택시;
			system("cls");
			printf("저장된 곡 목록\n"); // 다시 저장된 곡 목록을 출력해준다.
			for (j = 0; j < 3; j++) {
				if (a[j].name[0] == 0)
					printf("%d. 없음\n", j + 1); // 
				else
					printf("%d. %s\n", j + 1, a[j].name);
			}
			printf("==========\n\n");
			printf("저장번지 선택 : "); // 노래를 저장할 곳을 선택한다
			scanf("%d", &num); // 노래를 저장할 번호를 입력 받는다.
			memset(a[num - 1].song, 0, 200); // 입력 받은 번호-1 배열의 음계를 초기화 한다. 
			printf("곡 명 :");
			scanf("%s", a[num - 1].name); // 저장 할 노래 이름을 입력 받는다.
			printf("비밀번호 : ");
			scanf("%s", &a[num - 1].pwd); // 비밀번호를 입력 받는다.
			printf("입력 종료키 : x\n\n");
			printf("입력 :");
			printf("-----------------------------------------------\n");
			printf("  도#  레#    파# 솔# 라#       도# 레#     파#\n");
			printf(" 도  레  미 파   솔 라   시   도  레  미  파 \n");
			printf("-----------------------------------------------\n");

			for (i = 0; i < 200; i++) { // 100개를 입력 받을 수 있으므로, 음계 100개, 박자 100개를 입력 받아야 하므로 200번 반복 하도록 한다.
				input[i] = _getch();
				if (input[i] == 'a')
					printf("a");
				else if (input[i] == 's')
					printf("s");
				else if (input[i] == 'd')
					printf("d");
				else if (input[i] == 'f')
					printf("f");
				else if (input[i] == 'g')
					printf("g");
				else if (input[i] == 'h')
					printf("h");
				else if (input[i] == 'j')
					printf("j");
				else if (input[i] == 'k')
					printf("k");
				else if (input[i] == 'l')
					printf("l");
				else if (input[i] == ';')
					printf(";");
				else if (input[i] == 'w')
					printf("w"); // w 출력한다
				else if (input[i] == 'e')
					printf("e"); // e 출력한다
				else if (input[i] == 't')
					printf("t"); // t 출력한다
				else if (input[i] == 'y')
					printf("y");
				else if (input[i] == 'u')
					printf("u");
				else if (input[i] == 'o')
					printf("o"); // o 출력한다
				else if (input[i] == 'p')
					printf("p"); // p 출력한다
				else if (input[i] == ']')
					printf("]"); // ] 출력한다
				else if (input[i] == '/')
					printf("/"); // ] 출력한다

				// 16분음표를 입력 받기 위한 조건문이다.
				else if (input[i] == '0') {
					printf("0");
					if (input[i - 1] == 'a')
						Beep(tones[0], 125);
					else if (input[i - 1] == 'w')
						Beep(tones[1], 125);
					else if (input[i - 1] == 's')
						Beep(tones[2], 125);
					else if (input[i - 1] == 'e')
						Beep(tones[3], 125);
					else if (input[i - 1] == 'd')
						Beep(tones[4], 125);
					else if (input[i - 1] == 'f')
						Beep(tones[5], 125);
					else if (input[i - 1] == 't')
						Beep(tones[6], 125);
					else if (input[i - 1] == 'g')
						Beep(tones[7], 125);
					else if (input[i - 1] == 'y')
						Beep(tones[8], 125);
					else if (input[i - 1] == 'h')
						Beep(tones[9], 125);
					else if (input[i - 1] == 'u')
						Beep(tones[10], 125);
					else if (input[i - 1] == 'j')
						Beep(tones[11], 125);
					else if (input[i - 1] == 'k')
						Beep(tones[12], 125);
					else if (input[i - 1] == 'o')
						Beep(tones[13], 125);
					else if (input[i - 1] == 'l')
						Beep(tones[14], 125);
					else if (input[i - 1] == 'p')
						Beep(tones[15], 125);
					else if (input[i - 1] == ';')
						Beep(tones[16], 125);
					else if (input[i - 1] == '/')
						Beep(tones[17], 125);
					else if (input[i - 1] == ']')
						Beep(tones[18], 125);
				}

				// 점 8분음표를 나타내기 위한 조건문 
				else if (input[i] == '1') {
					printf("1");
					if (input[i - 1] == 'a')
						Beep(tones[0], 250);
					else if (input[i - 1] == 'w')
						Beep(tones[1], 250);
					else if (input[i - 1] == 's')
						Beep(tones[2], 250);
					else if (input[i - 1] == 'e')
						Beep(tones[3], 250);
					else if (input[i - 1] == 'd')
						Beep(tones[4], 250);
					else if (input[i - 1] == 'f')
						Beep(tones[5], 250);
					else if (input[i - 1] == 't')
						Beep(tones[6], 250);
					else if (input[i - 1] == 'g')
						Beep(tones[7], 250);
					else if (input[i - 1] == 'y')
						Beep(tones[8], 250);
					else if (input[i - 1] == 'h')
						Beep(tones[9], 250);
					else if (input[i - 1] == 'u')
						Beep(tones[10], 250);
					else if (input[i - 1] == 'j')
						Beep(tones[11], 250);
					else if (input[i - 1] == 'k')
						Beep(tones[12], 250);
					else if (input[i - 1] == 'o')
						Beep(tones[13], 250);
					else if (input[i - 1] == 'l')
						Beep(tones[14], 250);
					else if (input[i - 1] == 'p')
						Beep(tones[15], 250);
					else if (input[i - 1] == ';')
						Beep(tones[16], 250);
					else if (input[i - 1] == '/')
						Beep(tones[17], 250);
					else if (input[i - 1] == ']')
						Beep(tones[18], 250);
				}

				// 8분음표를 나타내기 위한 조건문
				else if (input[i] == '2') {
					printf("2");
					if (input[i - 1] == 'a')
						Beep(tones[0], 500);
					else if (input[i - 1] == 'w')
						Beep(tones[1], 500);
					else if (input[i - 1] == 's')
						Beep(tones[2], 500);
					else if (input[i - 1] == 'e')
						Beep(tones[3], 500);
					else if (input[i - 1] == 'd')
						Beep(tones[4], 500);
					else if (input[i - 1] == 'f')
						Beep(tones[5], 500);
					else if (input[i - 1] == 't')
						Beep(tones[6], 500);
					else if (input[i - 1] == 'g')
						Beep(tones[7], 500);
					else if (input[i - 1] == 'y')
						Beep(tones[8], 500);
					else if (input[i - 1] == 'h')
						Beep(tones[9], 500);
					else if (input[i - 1] == 'u')
						Beep(tones[10], 500);
					else if (input[i - 1] == 'j')
						Beep(tones[11], 500);
					else if (input[i - 1] == 'k')
						Beep(tones[12], 500);
					else if (input[i - 1] == 'o')
						Beep(tones[13], 500);
					else if (input[i - 1] == 'l')
						Beep(tones[14], 500);
					else if (input[i - 1] == 'p')
						Beep(tones[15], 500);
					else if (input[i - 1] == ';')
						Beep(tones[16], 500);
					else if (input[i - 1] == '/')
						Beep(tones[17], 500);
					else if (input[i - 1] == ']')
						Beep(tones[18], 500);
				}

				// 4분음표를 나타내기 위한 조건문
				else if (input[i] == '3') {
					printf("3");
					if (input[i - 1] == 'a')
						Beep(tones[0], 1000);
					else if (input[i - 1] == 'w')
						Beep(tones[1], 1000);
					else if (input[i - 1] == 's')
						Beep(tones[2], 1000);
					else if (input[i - 1] == 'e')
						Beep(tones[3], 1000);
					else if (input[i - 1] == 'd')
						Beep(tones[4], 1000);
					else if (input[i - 1] == 'f')
						Beep(tones[5], 1000);
					else if (input[i - 1] == 't')
						Beep(tones[6], 1000);
					else if (input[i - 1] == 'g')
						Beep(tones[7], 1000);
					else if (input[i - 1] == 'y')
						Beep(tones[8], 1000);
					else if (input[i - 1] == 'h')
						Beep(tones[9], 1000);
					else if (input[i - 1] == 'u')
						Beep(tones[10], 1000);
					else if (input[i - 1] == 'j')
						Beep(tones[11], 1000);
					else if (input[i - 1] == 'k')
						Beep(tones[12], 1000);
					else if (input[i - 1] == 'o')
						Beep(tones[13], 1000);
					else if (input[i - 1] == 'l')
						Beep(tones[14], 1000);
					else if (input[i - 1] == 'p')
						Beep(tones[15], 1000);
					else if (input[i - 1] == ';')
						Beep(tones[16], 1000);
					else if (input[i - 1] == '/')
						Beep(tones[17], 1000);
					else if (input[i - 1] == ']')
						Beep(tones[18], 1000);
				}

				// 점 4분음표를 나타내기 위한 조건문
				else if (input[i] == '4') {
					printf("4"); // 4를 입력 받을 때 4가 출력이 된다.
					if (input[i - 1] == 'a')
						Beep(tones[0], 1500);
					else if (input[i - 1] == 'w')
						Beep(tones[1], 1500);
					else if (input[i - 1] == 's')
						Beep(tones[2], 1500);
					else if (input[i - 1] == 'e')
						Beep(tones[3], 1500);
					else if (input[i - 1] == 'd')
						Beep(tones[4], 1500);
					else if (input[i - 1] == 'f')
						Beep(tones[5], 1500);
					else if (input[i - 1] == 't')
						Beep(tones[6], 1500);
					else if (input[i - 1] == 'g')
						Beep(tones[7], 1500);
					else if (input[i - 1] == 'y')
						Beep(tones[8], 1500);
					else if (input[i - 1] == 'h')
						Beep(tones[9], 1500);
					else if (input[i - 1] == 'u')
						Beep(tones[10], 1500);
					else if (input[i - 1] == 'j')
						Beep(tones[11], 1500);
					else if (input[i - 1] == 'k')
						Beep(tones[12], 1500);
					else if (input[i - 1] == 'o')
						Beep(tones[13], 1500);
					else if (input[i - 1] == 'l')
						Beep(tones[14], 1500);
					else if (input[i - 1] == 'p')
						Beep(tones[15], 1500);
					else if (input[i - 1] == ';')
						Beep(tones[16], 1500);
					else if (input[i - 1] == '/')
						Beep(tones[17], 1500);
					else if (input[i - 1] == ']')
						Beep(tones[18], 1500);
				}

				// 2분음표를 나타내기 위한 조건문
				else if (input[i] == '5') {
					printf("5"); // 5를 입력 받으면 5를 출력한다.
					if (input[i - 1] == 'a')
						Beep(tones[0], 2000);
					else if (input[i - 1] == 'w')
						Beep(tones[1], 2000);
					else if (input[i - 1] == 's')
						Beep(tones[2], 2000);
					else if (input[i - 1] == 'e')
						Beep(tones[3], 2000);
					else if (input[i - 1] == 'd')
						Beep(tones[4], 2000);
					else if (input[i - 1] == 'f')
						Beep(tones[5], 2000);
					else if (input[i - 1] == 't')
						Beep(tones[6], 2000);
					else if (input[i - 1] == 'g')
						Beep(tones[7], 2000);
					else if (input[i - 1] == 'y')
						Beep(tones[8], 2000);
					else if (input[i - 1] == 'h')
						Beep(tones[9], 2000);
					else if (input[i - 1] == 'u')
						Beep(tones[10], 2000);
					else if (input[i - 1] == 'j')
						Beep(tones[11], 2000);
					else if (input[i - 1] == 'k')
						Beep(tones[12], 2000);
					else if (input[i - 1] == 'o')
						Beep(tones[13], 2000);
					else if (input[i - 1] == 'l')
						Beep(tones[14], 2000);
					else if (input[i - 1] == 'p')
						Beep(tones[15], 2000);
					else if (input[i - 1] == ';')
						Beep(tones[16], 2000);
					else if (input[i - 1] == '/')
						Beep(tones[17], 2000);
					else if (input[i - 1] == ']')
						Beep(tones[18], 2000);
				}

				// 점2분음표를 나타내기 위한 조건문
				else if (input[i] == '6') {
					printf("6");
					if (input[i - 1] == 'a')
						Beep(tones[0], 3000);
					else if (input[i - 1] == 'w')
						Beep(tones[1], 3000);
					else if (input[i - 1] == 's')
						Beep(tones[2], 3000);
					else if (input[i - 1] == 'e')
						Beep(tones[3], 3000);
					else if (input[i - 1] == 'd')
						Beep(tones[4], 3000);
					else if (input[i - 1] == 'f')
						Beep(tones[5], 3000);
					else if (input[i - 1] == 't')
						Beep(tones[6], 3000);
					else if (input[i - 1] == 'g')
						Beep(tones[7], 3000);
					else if (input[i - 1] == 'y')
						Beep(tones[8], 3000);
					else if (input[i - 1] == 'h')
						Beep(tones[9], 3000);
					else if (input[i - 1] == 'u')
						Beep(tones[10], 3000);
					else if (input[i - 1] == 'j')
						Beep(tones[11], 3000);
					else if (input[i - 1] == 'k')
						Beep(tones[12], 3000);
					else if (input[i - 1] == 'o')
						Beep(tones[13], 3000);
					else if (input[i - 1] == 'l')
						Beep(tones[14], 3000);
					else if (input[i - 1] == 'p')
						Beep(tones[15], 3000);
					else if (input[i - 1] == ';')
						Beep(tones[16], 3000);
					else if (input[i - 1] == '/')
						Beep(tones[17], 3000);
					else if (input[i - 1] == ']')
						Beep(tones[18], 3000);
				}

				// 온옴표를 받기 위한 조건문
				else if (input[i] == '7') {
					printf("7");
					if (input[i - 1] == 'a')
						Beep(tones[0], 4000);
					else if (input[i - 1] == 'w')
						Beep(tones[1], 4000);
					else if (input[i - 1] == 's')
						Beep(tones[2], 4000);
					else if (input[i - 1] == 'e')
						Beep(tones[3], 4000);
					else if (input[i - 1] == 'd')
						Beep(tones[4], 4000);
					else if (input[i - 1] == 'f')
						Beep(tones[5], 4000);
					else if (input[i - 1] == 't')
						Beep(tones[6], 4000);
					else if (input[i - 1] == 'g')
						Beep(tones[7], 4000);
					else if (input[i - 1] == 'y')
						Beep(tones[8], 4000);
					else if (input[i - 1] == 'h')
						Beep(tones[9], 4000);
					else if (input[i - 1] == 'u')
						Beep(tones[10], 4000);
					else if (input[i - 1] == 'j')
						Beep(tones[11], 4000);
					else if (input[i - 1] == 'k')
						Beep(tones[12], 4000);
					else if (input[i - 1] == 'o')
						Beep(tones[13], 4000);
					else if (input[i - 1] == 'l')
						Beep(tones[14], 4000);
					else if (input[i - 1] == 'p')
						Beep(tones[15], 4000);
					else if (input[i - 1] == ';')
						Beep(tones[16], 4000);
					else if (input[i - 1] == '"')
						Beep(tones[17], 4000);
					else if (input[i - 1] == ']')
						Beep(tones[18], 4000);
				}

				// 점온옴표를 나타내기 위한 조건문
				else if (input[i] == '8') {
					printf("8");
					if (input[i - 1] == 'a')
						Beep(tones[0], 6000);
					else if (input[i - 1] == 'w')
						Beep(tones[1], 6000);
					else if (input[i - 1] == 's')
						Beep(tones[2], 6000);
					else if (input[i - 1] == 'e')
						Beep(tones[3], 6000);
					else if (input[i - 1] == 'd')
						Beep(tones[4], 6000);
					else if (input[i - 1] == 'f')
						Beep(tones[5], 6000);
					else if (input[i - 1] == 't')
						Beep(tones[6], 6000);
					else if (input[i - 1] == 'g')
						Beep(tones[7], 6000);
					else if (input[i - 1] == 'y')
						Beep(tones[8], 6000);
					else if (input[i - 1] == 'h')
						Beep(tones[9], 6000);
					else if (input[i - 1] == 'u')
						Beep(tones[10], 6000);
					else if (input[i - 1] == 'j')
						Beep(tones[11], 6000);
					else if (input[i - 1] == 'k')
						Beep(tones[12], 6000);
					else if (input[i - 1] == 'o')
						Beep(tones[13], 6000);
					else if (input[i - 1] == 'l')
						Beep(tones[14], 6000);
					else if (input[i - 1] == 'p')
						Beep(tones[15], 6000);
					else if (input[i - 1] == ';')
						Beep(tones[16], 6000);
					else if (input[i - 1] == '"')
						Beep(tones[17], 6000);
					else if (input[i - 1] == ']')
						Beep(tones[18], 6000);
				}

				// x를 입력 받으면
				else if (input[i] == 'x') {
					printf("x\n"); // x가 출력 되고,
					break; // 반복분을 빠져 나간다.
				}
				a[num - 1].song[i] = input[i]; // 구조체 배열에 입력 된 것들을 저장한다.
			}
			break;

		case 2:
			system("cls");
			printf("저장된 곡 목록\n"); // 저장된 곡 목록을 출력한다.
			for (j = 0; j < 3; j++) {
				if (a[j].name[0] == 0)
					printf("%d. 없음\n", j + 1);
				else
					printf("%d. %s\n", j + 1, a[j].name);
			}
			printf("==========\n\n");
			printf("곡 번호 선택 : ");
			scanf("%d", &sing);
			if (a[sing - 1].name[0] == NULL)
				printf("선택하신곳에 저장된 곡이 없습니다.\n");
			else {
				printf("비밀번호 입력 : ");
				scanf("%s", &PD);
				if (strcmp(a[sing - 1].pwd, PD) == 0) {
					printf("반복 횟수를 입력하세요 : ");
					scanf("%d", &cnt);
					for (i = 0; i < cnt; i++) {
						printf("총%d회 반복중 %d번째\n", cnt, i + 1);
						music(a[sing - 1].song);
						printf("\n");
					}
				}
				else {
					printf("비밀번호 입력 오류\n");
				}
				break;

		case 3:
			system("cls");
			printf("저장된 곡 목록\n");
			for (j = 0; j < 3; j++) {
				if (a[j].name[0] == 0)
					printf("%d. 없음\n", j + 1);
				else
					printf("%d. %s\n", j + 1, a[j].name);
			}
			printf("삭제할 곡을 선택하세요 : ");
			scanf("%d", &m);
			if (a[m - 1].name[0] == NULL) {
				printf("선택하신곳에 저장된 곡이 없습니다.\n");
				break;
			}

			if (a[m - 1].song != 0) {
				for (n = 0; n < 200; n++)
					a[m - 1].song[n] = NULL;
				for (n = 0; n < 20; n++)
					a[m - 1].name[n] = NULL;
				for (n = 0; n < 4; n++)
					a[m - 1].pwd[n] = NULL;
			}

			printf(" 곡이 초기화 되었습니다.\n");
			break;
			}
		}
	}
	return 0;
}

void music(char *input) {
	int i; // 반복 변수
	for (i = 0; i<200; i++) { // 200번 반복한다. 저장 가능한 계이름, 음표의 총 횟수가 200번 이므로
		if (input[i] == 'a')
			printf("도");
		else if (input[i] == 's')
			printf("레");
		else if (input[i] == 'd')
			printf("미");
		else if (input[i] == 'f')
			printf("파");
		else if (input[i] == 'g')
			printf("솔");
		else if (input[i] == 'h')
			printf("라");
		else if (input[i] == 'j')
			printf("시");
		else if (input[i] == 'k')
			printf("도");
		else if (input[i] == 'l')
			printf("레");
		else if (input[i] == ';')
			printf("미");
		else if (input[i] == '"')
			printf("파");
		else if (input[i] == 'w')
			printf("도#");
		else if (input[i] == 'e')
			printf("레#");
		else if (input[i] == 't')
			printf("파#");
		else if (input[i] == 'y')
			printf("솔#");
		else if (input[i] == 'u')
			printf("라#");
		else if (input[i] == 'o')
			printf("도#");
		else if (input[i] == 'p')
			printf("레#");
		else if (input[i] == ']')
			printf("파#");

		else if (input[i] == '0') {
			if (input[i - 1] == 'a')
				Beep(tones[0], 125);
			else if (input[i - 1] == 'w')
				Beep(tones[1], 125);
			else if (input[i - 1] == 's')
				Beep(tones[2], 125);
			else if (input[i - 1] == 'e')
				Beep(tones[3], 125);
			else if (input[i - 1] == 'd')
				Beep(tones[4], 125);
			else if (input[i - 1] == 'f')
				Beep(tones[5], 125);
			else if (input[i - 1] == 't')
				Beep(tones[6], 125);
			else if (input[i - 1] == 'g')
				Beep(tones[7], 125);
			else if (input[i - 1] == 'y')
				Beep(tones[8], 125);
			else if (input[i - 1] == 'h')
				Beep(tones[9], 125);
			else if (input[i - 1] == 'u')
				Beep(tones[10], 125);
			else if (input[i - 1] == 'j')
				Beep(tones[11], 125);
			else if (input[i - 1] == 'k')
				Beep(tones[12], 125);
			else if (input[i - 1] == 'o')
				Beep(tones[13], 125);
			else if (input[i - 1] == 'l')
				Beep(tones[14], 125);
			else if (input[i - 1] == 'p')
				Beep(tones[15], 125);
			else if (input[i - 1] == ';')
				Beep(tones[16], 125);
			else if (input[i - 1] == '"')
				Beep(tones[17], 125);
			else if (input[i - 1] == ']')
				Beep(tones[18], 125);
		}

		else if (input[i] == '1') {
			if (input[i - 1] == 'a')
				Beep(tones[0], 250);
			else if (input[i - 1] == 'w')
				Beep(tones[1], 250);
			else if (input[i - 1] == 's')
				Beep(tones[2], 250);
			else if (input[i - 1] == 'e')
				Beep(tones[3], 250);
			else if (input[i - 1] == 'd')
				Beep(tones[4], 250);
			else if (input[i - 1] == 'f')
				Beep(tones[5], 250);
			else if (input[i - 1] == 't')
				Beep(tones[6], 250);
			else if (input[i - 1] == 'g')
				Beep(tones[7], 250);
			else if (input[i - 1] == 'y')
				Beep(tones[8], 250);
			else if (input[i - 1] == 'h')
				Beep(tones[9], 250);
			else if (input[i - 1] == 'u')
				Beep(tones[10], 250);
			else if (input[i - 1] == 'j')
				Beep(tones[11], 250);
			else if (input[i - 1] == 'k')
				Beep(tones[12], 250);
			else if (input[i - 1] == 'o')
				Beep(tones[13], 250);
			else if (input[i - 1] == 'l')
				Beep(tones[14], 250);
			else if (input[i - 1] == 'p')
				Beep(tones[15], 250);
			else if (input[i - 1] == ';')
				Beep(tones[16], 250);
			else if (input[i - 1] == '"')
				Beep(tones[17], 250);
			else if (input[i - 1] == ']')
				Beep(tones[18], 250);
		}

		else if (input[i] == '2') {
			if (input[i - 1] == 'a')
				Beep(tones[0], 500);
			else if (input[i - 1] == 'w')
				Beep(tones[1], 500);
			else if (input[i - 1] == 's')
				Beep(tones[2], 500);
			else if (input[i - 1] == 'e')
				Beep(tones[3], 500);
			else if (input[i - 1] == 'd')
				Beep(tones[4], 500);
			else if (input[i - 1] == 'f')
				Beep(tones[5], 500);
			else if (input[i - 1] == 't')
				Beep(tones[6], 500);
			else if (input[i - 1] == 'g')
				Beep(tones[7], 500);
			else if (input[i - 1] == 'y')
				Beep(tones[8], 500);
			else if (input[i - 1] == 'h')
				Beep(tones[9], 500);
			else if (input[i - 1] == 'u')
				Beep(tones[10], 500);
			else if (input[i - 1] == 'j')
				Beep(tones[11], 500);
			else if (input[i - 1] == 'k')
				Beep(tones[12], 500);
			else if (input[i - 1] == 'o')
				Beep(tones[13], 500);
			else if (input[i - 1] == 'l')
				Beep(tones[14], 500);
			else if (input[i - 1] == 'p')
				Beep(tones[15], 500);
			else if (input[i - 1] == ';')
				Beep(tones[16], 500);
			else if (input[i - 1] == '"')
				Beep(tones[17], 500);
			else if (input[i - 1] == ']')
				Beep(tones[18], 500);
		}

		else if (input[i] == '3') {
			if (input[i - 1] == 'a')
				Beep(tones[0], 1000);
			else if (input[i - 1] == 'w')
				Beep(tones[1], 1000);
			else if (input[i - 1] == 's')
				Beep(tones[2], 1000);
			else if (input[i - 1] == 'e')
				Beep(tones[3], 1000);
			else if (input[i - 1] == 'd')
				Beep(tones[4], 1000);
			else if (input[i - 1] == 'f')
				Beep(tones[5], 1000);
			else if (input[i - 1] == 't')
				Beep(tones[6], 1000);
			else if (input[i - 1] == 'g')
				Beep(tones[7], 1000);
			else if (input[i - 1] == 'y')
				Beep(tones[8], 1000);
			else if (input[i - 1] == 'h')
				Beep(tones[9], 1000);
			else if (input[i - 1] == 'u')
				Beep(tones[10], 1000);
			else if (input[i - 1] == 'j')
				Beep(tones[11], 1000);
			else if (input[i - 1] == 'k')
				Beep(tones[12], 1000);
			else if (input[i - 1] == 'o')
				Beep(tones[13], 1000);
			else if (input[i - 1] == 'l')
				Beep(tones[14], 1000);
			else if (input[i - 1] == 'p')
				Beep(tones[15], 1000);
			else if (input[i - 1] == ';')
				Beep(tones[16], 1000);
			else if (input[i - 1] == '"')
				Beep(tones[17], 1000);
			else if (input[i - 1] == ']')
				Beep(tones[18], 1000);
		}

		else if (input[i] == '4') {
			if (input[i - 1] == 'a')
				Beep(tones[0], 1500);
			else if (input[i - 1] == 'w')
				Beep(tones[1], 1500);
			else if (input[i - 1] == 's')
				Beep(tones[2], 1500);
			else if (input[i - 1] == 'e')
				Beep(tones[3], 1500);
			else if (input[i - 1] == 'd')
				Beep(tones[4], 1500);
			else if (input[i - 1] == 'f')
				Beep(tones[5], 1500);
			else if (input[i - 1] == 't')
				Beep(tones[6], 1500);
			else if (input[i - 1] == 'g')
				Beep(tones[7], 1500);
			else if (input[i - 1] == 'y')
				Beep(tones[8], 1500);
			else if (input[i - 1] == 'h')
				Beep(tones[9], 1500);
			else if (input[i - 1] == 'u')
				Beep(tones[10], 1500);
			else if (input[i - 1] == 'j')
				Beep(tones[11], 1500);
			else if (input[i - 1] == 'k')
				Beep(tones[12], 1500);
			else if (input[i - 1] == 'o')
				Beep(tones[13], 1500);
			else if (input[i - 1] == 'l')
				Beep(tones[14], 1500);
			else if (input[i - 1] == 'p')
				Beep(tones[15], 1500);
			else if (input[i - 1] == ';')
				Beep(tones[16], 1500);
			else if (input[i - 1] == '"')
				Beep(tones[17], 1500);
			else if (input[i - 1] == ']')
				Beep(tones[18], 1500);
		}

		else if (input[i] == '5') {
			if (input[i - 1] == 'a')
				Beep(tones[0], 2000);
			else if (input[i - 1] == 'w')
				Beep(tones[1], 2000);
			else if (input[i - 1] == 's')
				Beep(tones[2], 2000);
			else if (input[i - 1] == 'e')
				Beep(tones[3], 2000);
			else if (input[i - 1] == 'd')
				Beep(tones[4], 2000);
			else if (input[i - 1] == 'f')
				Beep(tones[5], 2000);
			else if (input[i - 1] == 't')
				Beep(tones[6], 2000);
			else if (input[i - 1] == 'g')
				Beep(tones[7], 2000);
			else if (input[i - 1] == 'y')
				Beep(tones[8], 2000);
			else if (input[i - 1] == 'h')
				Beep(tones[9], 2000);
			else if (input[i - 1] == 'u')
				Beep(tones[10], 2000);
			else if (input[i - 1] == 'j')
				Beep(tones[11], 2000);
			else if (input[i - 1] == 'k')
				Beep(tones[12], 2000);
			else if (input[i - 1] == 'o')
				Beep(tones[13], 2000);
			else if (input[i - 1] == 'l')
				Beep(tones[14], 2000);
			else if (input[i - 1] == 'p')
				Beep(tones[15], 2000);
			else if (input[i - 1] == ';')
				Beep(tones[16], 2000);
			else if (input[i - 1] == '"')
				Beep(tones[17], 2000);
			else if (input[i - 1] == ']')
				Beep(tones[18], 2000);
		}

		else if (input[i] == '6') {
		if (input[i - 1] == 'a')
			Beep(tones[0], 3000);
			else if (input[i - 1] == 'w')
				Beep(tones[1], 3000);
			else if (input[i - 1] == 's')
				Beep(tones[2], 3000);
			else if (input[i - 1] == 'e')
				Beep(tones[3], 3000);
			else if (input[i - 1] == 'd')
				Beep(tones[4], 3000);
			else if (input[i - 1] == 'f')
				Beep(tones[5], 3000);
			else if (input[i - 1] == 't')
				Beep(tones[6], 3000);
			else if (input[i - 1] == 'g')
				Beep(tones[7], 3000);
			else if (input[i - 1] == 'y')
				Beep(tones[8], 3000);
			else if (input[i - 1] == 'h')
				Beep(tones[9], 3000);
			else if (input[i - 1] == 'u')
				Beep(tones[10], 3000);
			else if (input[i - 1] == 'j')
				Beep(tones[11], 3000);
			else if (input[i - 1] == 'k')
				Beep(tones[12], 3000);
			else if (input[i - 1] == 'o')
				Beep(tones[13], 3000);
			else if (input[i - 1] == 'l')
				Beep(tones[14], 3000);
			else if (input[i - 1] == 'p')
				Beep(tones[15], 3000);
			else if (input[i - 1] == ';')
				Beep(tones[16], 3000);
			else if (input[i - 1] == '"')
				Beep(tones[17], 3000);
			else if (input[i - 1] == ']')
				Beep(tones[18], 3000);
		}

		else if (input[i] == '7') {
			if (input[i - 1] == 'a')
				Beep(tones[0], 4000);
			else if (input[i - 1] == 'w')
				Beep(tones[1], 4000);
			else if (input[i - 1] == 's')
				Beep(tones[2], 4000);
			else if (input[i - 1] == 'e')
				Beep(tones[3], 4000);
			else if (input[i - 1] == 'd')
				Beep(tones[4], 4000);
			else if (input[i - 1] == 'f')
				Beep(tones[5], 4000);
			else if (input[i - 1] == 't')
				Beep(tones[6], 4000);
			else if (input[i - 1] == 'g')
				Beep(tones[7], 4000);
			else if (input[i - 1] == 'y')
				Beep(tones[8], 4000);
			else if (input[i - 1] == 'h')
				Beep(tones[9], 4000);
			else if (input[i - 1] == 'u')
				Beep(tones[10], 4000);
			else if (input[i - 1] == 'j')
				Beep(tones[11], 4000);
			else if (input[i - 1] == 'k')
				Beep(tones[12], 4000);
			else if (input[i - 1] == 'o')
				Beep(tones[13], 4000);
			else if (input[i - 1] == 'l')
				Beep(tones[14], 4000);
			else if (input[i - 1] == 'p')
				Beep(tones[15], 4000);
			else if (input[i - 1] == ';')
				Beep(tones[16], 4000);
			else if (input[i - 1] == '"')
				Beep(tones[17], 4000);
			else if (input[i - 1] == ']')
				Beep(tones[18], 4000);
		}

		else if (input[i] == '8') {
			if (input[i - 1] == 'a')
				Beep(tones[0], 6000);
			else if (input[i - 1] == 'w')
				Beep(tones[1], 6000);
			else if (input[i - 1] == 's')
				Beep(tones[2], 6000);
			else if (input[i - 1] == 'e')
				Beep(tones[3], 6000);
			else if (input[i - 1] == 'd')
				Beep(tones[4], 6000);
			else if (input[i - 1] == 'f')
				Beep(tones[5], 6000);
			else if (input[i - 1] == 't')
				Beep(tones[6], 6000);
			else if (input[i - 1] == 'g')
				Beep(tones[7], 6000);
			else if (input[i - 1] == 'y')
				Beep(tones[8], 6000);
			else if (input[i - 1] == 'h')
				Beep(tones[9], 6000);
			else if (input[i - 1] == 'u')
				Beep(tones[10], 6000);
			else if (input[i - 1] == 'j')
				Beep(tones[11], 6000);
			else if (input[i - 1] == 'k')
				Beep(tones[12], 6000);
			else if (input[i - 1] == 'o')
				Beep(tones[13], 6000);
			else if (input[i - 1] == 'l')
				Beep(tones[14], 6000);
			else if (input[i - 1] == 'p')
				Beep(tones[15], 6000);
			else if (input[i - 1] == ';')
				Beep(tones[16], 6000);
			else if (input[i - 1] == '"')
				Beep(tones[17], 6000);
			else if (input[i - 1] == ']')
				Beep(tones[18], 6000);
		}
	}
}