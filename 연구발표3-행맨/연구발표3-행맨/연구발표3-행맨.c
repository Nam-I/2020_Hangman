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

		printf("게임을 시작합니다.\n");
		printf("기회는 총 %d번 입니다.\n\n", chance);

		printf("----------------\n");
		printf("|              |\n");
		printf("|               \n");
		printf("|                \n");
		printf("|               \n");
		printf("|____________________\n\n\n");

		Make_Bar(quiz, bar);

		Print_Bar(bar);

		while ((SC != 1) && (chance != 0)) {
			printf("원하는 알파벳 입력하세요 : ");
			ch = getchar();
			getchar();
			Check(quiz, bar, ch);
			printf("\n\n");
			Print_Bar(bar);
			printf("\n\n떠오르는 단어가 있나요? (y/n) : ");
			A = getchar();
			getchar();
			printf("\n\n");
			if (A == 'y') {
				printf("정답은?(**첫 글자는 대문자로 입력**) : ");
				gets(word);
				puts(word);
				printf("\n");
				SC = String_Check(quiz, word);
				if (SC == 1) {
					printf("정답입니다!\n\n");
					printf("-----Mission Success-----\n\n\n");
				}
				else {
					--chance;
					if (chance != 0) {
						if (chance == 4) {
							printf("틀렸습니다. 문제를 계속 풀어보세요.\n\n");
							printf("----------------\n");
							printf("|              |\n");
							printf("|              0\n");
							printf("|                \n");
							printf("|               \n");
							printf("|____________________\n\n\n");
							printf("## %d번의 기회가 남았습니다. ###\n\n\n", chance);
						}
						else if (chance == 3) {
							printf("틀렸습니다. 문제를 계속 풀어보세요.\n\n");
							printf("----------------\n");
							printf("|              |\n");
							printf("|              0\n");
							printf("|              |\n");
							printf("|               \n");
							printf("|____________________\n\n\n");
							printf("### %d번의 기회가 남았습니다. ###\n\n\n", chance);
						}
						else if (chance == 2) {
							printf("틀렸습니다. 문제를 계속 풀어보세요.\n\n");
							printf("----------------\n");
							printf("|              |\n");
							printf("|              0\n");
							printf("|             >|\n");
							printf("|               \n");
							printf("|____________________\n\n\n");
							printf("### %d번의 기회가 남았습니다. ###\n\n\n", chance);
						}
						else if (chance == 1) {
							printf("틀렸습니다. 문제를 계속 풀어보세요.\n\n");
							printf("----------------\n");
							printf("|              |\n");
							printf("|              0\n");
							printf("|             >|<\n");
							printf("|               \n");
							printf("|____________________\n\n\n");
							printf("### %d번의 기회가 남았습니다. ###\n\n\n", chance);
						}

					}
					else {
						printf("### 기회를 모두 소진했습니다! ###\n\n");
						printf("----------------\n");
						printf("|              |\n");
						printf("|              0\n");
						printf("|             >|<\n");
						printf("|              H\n");
						printf("|____________________\n\n\n");
						printf("-----GAME OVER-----\n\n\n");

						printf(" 정답은 =>> ");

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
						printf("문제를 계속 풀어보세요.\n\n");
						printf("----------------\n");
						printf("|              |\n");
						printf("|              0\n");
						printf("|                \n");
						printf("|               \n");
						printf("|____________________\n\n\n");
						printf("### %d번의 기회가 남았습니다. ###\n\n\n", chance);
					}
					else if (chance == 3) {
						printf("문제를 계속 풀어보세요.\n\n");
						printf("----------------\n");
						printf("|              |\n");
						printf("|              0\n");
						printf("|              |\n");
						printf("|               \n");
						printf("|____________________\n\n\n");
						printf("### %d번의 기회가 남았습니다. ###\n\n\n", chance);
					}
					else if (chance == 2) {
						printf("문제를 계속 풀어보세요.\n\n");
						printf("----------------\n");
						printf("|              |\n");
						printf("|              0\n");
						printf("|             >|\n");
						printf("|               \n");
						printf("|____________________\n\n\n");
						printf("### %d번의 기회가 남았습니다. ###\n\n\n", chance);
					}
					else if (chance == 1) {
						printf("문제를 계속 풀어보세요.\n\n");
						printf("----------------\n");
						printf("|              |\n");
						printf("|              0\n");
						printf("|             >|<\n");
						printf("|               \n");
						printf("|____________________\n\n\n");
						printf("### %d번의 기회가 남았습니다. ###\n\n\n", chance);
					}
				}
				else {
					printf("### 기회를 모두 소진했습니다! ###\n\n");
					printf("----------------\n");
					printf("|              |\n");
					printf("|              0\n");
					printf("|             >|<\n");
					printf("|              H\n");
					printf("|__________________\n\n\n");
					printf("-----GAME OVER-----\n\n\n");

					printf(" 정답은 =>> ");

					for (i = 0; quiz[i] != '\0'; i++) {
						printf("%c", quiz[i]);
					}

					printf("\n\n\n");
				}
			}
		}

		SC = 0;
		chance = 5;
		printf("재도전 하시겠습니까? (y/n) : ");
		RG = getchar();
		getchar();
		printf("\n\n");

	} while (RG == 'y');

	printf("게임이 종료됩니다.\n\n");

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
