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

int tones[] = { 262, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494, 523, 554, 587, 622, 659, 699, 740 };	// ���� �� ���ļ� �迭 ����

//Recode fuction
void music(char *);

int main() {
	struct melody a[3] = { { "�б���", "g3g3h3h3g3g3d5g3g3d3d3s6g3g3h3h3g3g3d5g3d3s3d3a6", "1234" }, 0 };	// ����ü ����. �б���, �б����� ���̸� �� ����, ��й�ȣ�� ����
	
	int sel, num, sing; // �޴� ���� ����
	char input[200]; // ����� ���ڸ� �Է� ���� �迭 200�� ����
	char PD[4]; // ��й�ȣ 4�ڸ� ����
	int i, j, n, m, cnt; // �ݺ�����

	printf("= �ǾƳ� ���α׷� ==\n\n");
	printf("++++�Ѱ�� �ִ� ���� 1000��+++++\n");
	printf("++++�� -> ������ ������ �Է�++++\n");
	printf("++++Example : ��2��2 ++++\n");
	printf("++++��й�ȣ �ִ� 4�ڸ����� �Է�++++\n");
	printf("++++2��Ÿ�� �ĸ� �Է��� �ÿ��� ū����ǥ �Է�\n"); // �޴��� ���


	while (1) {
		printf("����� �� ���\n"); // ����� �� ��� ���
		for (j = 0; j < 3; j++) { // ����� �� ����� 3�� ����Ѵ�.
			if (a[j].name[0] == 0)  // ���ǹ�. name[]�迭�� ����� ���� ���ٸ�
				printf("%d. ����\n", j + 1); // "����"�� ����Ѵ�.
			else // �װ� �ƴ϶��
				printf("%d. %s\n", j + 1, a[j].name); // ����� �뷡 ������ ����Ѵ�
		}
		printf("\n");
		printf("�޴�\n");
		printf("1. �� �Է�\n");
		printf("2. �� ���\n");
		printf("3. �� ����\n");
		printf("x. ����\n\n");
		printf("�޴� ���� : ");

		scanf("%d", &sel); // �޴� ���� �Է�
		switch (sel) { // �޴� ���� ���ǹ�
		case 1: // 1�� ���ý�;
			system("cls");
			printf("����� �� ���\n"); // �ٽ� ����� �� ����� ������ش�.
			for (j = 0; j < 3; j++) {
				if (a[j].name[0] == 0)
					printf("%d. ����\n", j + 1); // 
				else
					printf("%d. %s\n", j + 1, a[j].name);
			}
			printf("==========\n\n");
			printf("������� ���� : "); // �뷡�� ������ ���� �����Ѵ�
			scanf("%d", &num); // �뷡�� ������ ��ȣ�� �Է� �޴´�.
			memset(a[num - 1].song, 0, 200); // �Է� ���� ��ȣ-1 �迭�� ���踦 �ʱ�ȭ �Ѵ�. 
			printf("�� �� :");
			scanf("%s", a[num - 1].name); // ���� �� �뷡 �̸��� �Է� �޴´�.
			printf("��й�ȣ : ");
			scanf("%s", &a[num - 1].pwd); // ��й�ȣ�� �Է� �޴´�.
			printf("�Է� ����Ű : x\n\n");
			printf("�Է� :");
			printf("-----------------------------------------------\n");
			printf("  ��#  ��#    ��# ��# ��#       ��# ��#     ��#\n");
			printf(" ��  ��  �� ��   �� ��   ��   ��  ��  ��  �� \n");
			printf("-----------------------------------------------\n");

			for (i = 0; i < 200; i++) { // 100���� �Է� ���� �� �����Ƿ�, ���� 100��, ���� 100���� �Է� �޾ƾ� �ϹǷ� 200�� �ݺ� �ϵ��� �Ѵ�.
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
					printf("w"); // w ����Ѵ�
				else if (input[i] == 'e')
					printf("e"); // e ����Ѵ�
				else if (input[i] == 't')
					printf("t"); // t ����Ѵ�
				else if (input[i] == 'y')
					printf("y");
				else if (input[i] == 'u')
					printf("u");
				else if (input[i] == 'o')
					printf("o"); // o ����Ѵ�
				else if (input[i] == 'p')
					printf("p"); // p ����Ѵ�
				else if (input[i] == ']')
					printf("]"); // ] ����Ѵ�
				else if (input[i] == '/')
					printf("/"); // ] ����Ѵ�

				// 16����ǥ�� �Է� �ޱ� ���� ���ǹ��̴�.
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

				// �� 8����ǥ�� ��Ÿ���� ���� ���ǹ� 
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

				// 8����ǥ�� ��Ÿ���� ���� ���ǹ�
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

				// 4����ǥ�� ��Ÿ���� ���� ���ǹ�
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

				// �� 4����ǥ�� ��Ÿ���� ���� ���ǹ�
				else if (input[i] == '4') {
					printf("4"); // 4�� �Է� ���� �� 4�� ����� �ȴ�.
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

				// 2����ǥ�� ��Ÿ���� ���� ���ǹ�
				else if (input[i] == '5') {
					printf("5"); // 5�� �Է� ������ 5�� ����Ѵ�.
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

				// ��2����ǥ�� ��Ÿ���� ���� ���ǹ�
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

				// �¿�ǥ�� �ޱ� ���� ���ǹ�
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

				// ���¿�ǥ�� ��Ÿ���� ���� ���ǹ�
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

				// x�� �Է� ������
				else if (input[i] == 'x') {
					printf("x\n"); // x�� ��� �ǰ�,
					break; // �ݺ����� ���� ������.
				}
				a[num - 1].song[i] = input[i]; // ����ü �迭�� �Է� �� �͵��� �����Ѵ�.
			}
			break;

		case 2:
			system("cls");
			printf("����� �� ���\n"); // ����� �� ����� ����Ѵ�.
			for (j = 0; j < 3; j++) {
				if (a[j].name[0] == 0)
					printf("%d. ����\n", j + 1);
				else
					printf("%d. %s\n", j + 1, a[j].name);
			}
			printf("==========\n\n");
			printf("�� ��ȣ ���� : ");
			scanf("%d", &sing);
			if (a[sing - 1].name[0] == NULL)
				printf("�����ϽŰ��� ����� ���� �����ϴ�.\n");
			else {
				printf("��й�ȣ �Է� : ");
				scanf("%s", &PD);
				if (strcmp(a[sing - 1].pwd, PD) == 0) {
					printf("�ݺ� Ƚ���� �Է��ϼ��� : ");
					scanf("%d", &cnt);
					for (i = 0; i < cnt; i++) {
						printf("��%dȸ �ݺ��� %d��°\n", cnt, i + 1);
						music(a[sing - 1].song);
						printf("\n");
					}
				}
				else {
					printf("��й�ȣ �Է� ����\n");
				}
				break;

		case 3:
			system("cls");
			printf("����� �� ���\n");
			for (j = 0; j < 3; j++) {
				if (a[j].name[0] == 0)
					printf("%d. ����\n", j + 1);
				else
					printf("%d. %s\n", j + 1, a[j].name);
			}
			printf("������ ���� �����ϼ��� : ");
			scanf("%d", &m);
			if (a[m - 1].name[0] == NULL) {
				printf("�����ϽŰ��� ����� ���� �����ϴ�.\n");
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

			printf(" ���� �ʱ�ȭ �Ǿ����ϴ�.\n");
			break;
			}
		}
	}
	return 0;
}

void music(char *input) {
	int i; // �ݺ� ����
	for (i = 0; i<200; i++) { // 200�� �ݺ��Ѵ�. ���� ������ ���̸�, ��ǥ�� �� Ƚ���� 200�� �̹Ƿ�
		if (input[i] == 'a')
			printf("��");
		else if (input[i] == 's')
			printf("��");
		else if (input[i] == 'd')
			printf("��");
		else if (input[i] == 'f')
			printf("��");
		else if (input[i] == 'g')
			printf("��");
		else if (input[i] == 'h')
			printf("��");
		else if (input[i] == 'j')
			printf("��");
		else if (input[i] == 'k')
			printf("��");
		else if (input[i] == 'l')
			printf("��");
		else if (input[i] == ';')
			printf("��");
		else if (input[i] == '"')
			printf("��");
		else if (input[i] == 'w')
			printf("��#");
		else if (input[i] == 'e')
			printf("��#");
		else if (input[i] == 't')
			printf("��#");
		else if (input[i] == 'y')
			printf("��#");
		else if (input[i] == 'u')
			printf("��#");
		else if (input[i] == 'o')
			printf("��#");
		else if (input[i] == 'p')
			printf("��#");
		else if (input[i] == ']')
			printf("��#");

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