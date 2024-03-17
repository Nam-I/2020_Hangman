#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "rn.h"

void Print_Bar(char* bar);
void Make_Bar(char* quiz, char* bar);
void Check(char* quiz, char* bar, char ch);
int String_Check(char* quiz, char* word);

int main(void) {

	int R, i, chance = 5, SC = 0, j;
	char quiz[20] = { NULL }, bar[20] = { NULL }, word[20] = { NULL }, ch, A, RG;


	do {

		for (j = 0; j <= 19; j++) {
			quiz[j] = '\0';
			bar[j] = '\0';
		}
		RandomNumber(quiz);

		printf("������ �����մϴ�.\n");
		printf("��ȸ�� �� %d�� �Դϴ�.\n\n", chance);

		printf("----------------\n");
		printf("|              |\n");
		printf("|               \n");
		printf("|                \n");
		printf("|               \n");
		printf("|____________________\n\n\n");

		Make_Bar(quiz, bar);

		Print_Bar(bar);

		while ((SC != 1) && (chance != 0)) {
			printf("���ϴ� ���ĺ� �Է��ϼ��� : ");
			ch = getchar();
			getchar();
			Check(quiz, bar, ch);
			printf("\n\n");
			Print_Bar(bar);
			printf("\n\n�������� �ܾ �ֳ���? (y/n) : ");
			A = getchar();
			getchar();
			printf("\n\n");
			if (A == 'y') {
				printf("������?(**ù ���ڴ� �빮�ڷ� �Է�**) : ");
				gets(word);
				puts(word);
				printf("\n");
				SC = String_Check(quiz, word);
				if (SC == 1) {
					printf("�����Դϴ�!\n\n");
					printf("-----Mission Success-----\n\n\n");
				}
				else {
					--chance;
					if (chance != 0) {
						if (chance == 4) {
							printf("Ʋ�Ƚ��ϴ�. ������ ��� Ǯ�����.\n\n");
							printf("----------------\n");
							printf("|              |\n");
							printf("|              0\n");
							printf("|                \n");
							printf("|               \n");
							printf("|____________________\n\n\n");
							printf("## %d���� ��ȸ�� ���ҽ��ϴ�. ###\n\n\n", chance);
						}
						else if (chance == 3) {
							printf("Ʋ�Ƚ��ϴ�. ������ ��� Ǯ�����.\n\n");
							printf("----------------\n");
							printf("|              |\n");
							printf("|              0\n");
							printf("|              |\n");
							printf("|               \n");
							printf("|____________________\n\n\n");
							printf("### %d���� ��ȸ�� ���ҽ��ϴ�. ###\n\n\n", chance);
						}
						else if (chance == 2) {
							printf("Ʋ�Ƚ��ϴ�. ������ ��� Ǯ�����.\n\n");
							printf("----------------\n");
							printf("|              |\n");
							printf("|              0\n");
							printf("|             >|\n");
							printf("|               \n");
							printf("|____________________\n\n\n");
							printf("### %d���� ��ȸ�� ���ҽ��ϴ�. ###\n\n\n", chance);
						}
						else if (chance == 1) {
							printf("Ʋ�Ƚ��ϴ�. ������ ��� Ǯ�����.\n\n");
							printf("----------------\n");
							printf("|              |\n");
							printf("|              0\n");
							printf("|             >|<\n");
							printf("|               \n");
							printf("|____________________\n\n\n");
							printf("### %d���� ��ȸ�� ���ҽ��ϴ�. ###\n\n\n", chance);
						}

					}
					else {
						printf("### ��ȸ�� ��� �����߽��ϴ�! ###\n\n");
						printf("----------------\n");
						printf("|              |\n");
						printf("|              0\n");
						printf("|             >|<\n");
						printf("|              H\n");
						printf("|____________________\n\n\n");
						printf("-----GAME OVER-----\n\n\n");

						printf(" ������ =>> ");

						for (i = 0; quiz[i] != '\0'; i++) {
							printf("%c", quiz[i]);
						}

						printf("\n\n\n");
					}
				}
			}
			else {
				--chance;
				if (chance != 0) {
					if (chance == 4) {
						printf("������ ��� Ǯ�����.\n\n");
						printf("----------------\n");
						printf("|              |\n");
						printf("|              0\n");
						printf("|                \n");
						printf("|               \n");
						printf("|____________________\n\n\n");
						printf("### %d���� ��ȸ�� ���ҽ��ϴ�. ###\n\n\n", chance);
					}
					else if (chance == 3) {
						printf("������ ��� Ǯ�����.\n\n");
						printf("----------------\n");
						printf("|              |\n");
						printf("|              0\n");
						printf("|              |\n");
						printf("|               \n");
						printf("|____________________\n\n\n");
						printf("### %d���� ��ȸ�� ���ҽ��ϴ�. ###\n\n\n", chance);
					}
					else if (chance == 2) {
						printf("������ ��� Ǯ�����.\n\n");
						printf("----------------\n");
						printf("|              |\n");
						printf("|              0\n");
						printf("|             >|\n");
						printf("|               \n");
						printf("|____________________\n\n\n");
						printf("### %d���� ��ȸ�� ���ҽ��ϴ�. ###\n\n\n", chance);
					}
					else if (chance == 1) {
						printf("������ ��� Ǯ�����.\n\n");
						printf("----------------\n");
						printf("|              |\n");
						printf("|              0\n");
						printf("|             >|<\n");
						printf("|               \n");
						printf("|____________________\n\n\n");
						printf("### %d���� ��ȸ�� ���ҽ��ϴ�. ###\n\n\n", chance);
					}
				}
				else {
					printf("### ��ȸ�� ��� �����߽��ϴ�! ###\n\n");
					printf("----------------\n");
					printf("|              |\n");
					printf("|              0\n");
					printf("|             >|<\n");
					printf("|              H\n");
					printf("|__________________\n\n\n");
					printf("-----GAME OVER-----\n\n\n");

					printf(" ������ =>> ");

					for (i = 0; quiz[i] != '\0'; i++) {
						printf("%c", quiz[i]);
					}

					printf("\n\n\n");
				}
			}
		}

		SC = 0;
		chance = 5;
		printf("�絵�� �Ͻðڽ��ϱ�? (y/n) : ");
		RG = getchar();
		getchar();
		printf("\n\n");

	} while (RG == 'y');

	printf("������ ����˴ϴ�.\n\n");

}

void Make_Bar(char* quiz, char* bar) {

	int i;
	for (i = 0; i < strlen(quiz); i++) {

		if (i == 0) {
			bar[i] = quiz[i];
		}
		else {
			bar[i] = '_';
		}
	}

}

void Print_Bar(char* bar) {

	int i;

	printf(" ->> ");

	for (i = 0; i < strlen(bar); i++)
		printf("%c ", bar[i]);
	printf("\n\n");
}

void Check(char* quiz, char* bar, char ch) {

	int i;

	for (i = 0; i < strlen(quiz); i++) {
		if (quiz[i] == ch) {
			bar[i] = ch;
		}
	}
}

int String_Check(char* quiz, char* word) {



	if (strcmp(quiz, word) == 0) {
		return 1;
	}
	else {
		return 0;
	}
}
