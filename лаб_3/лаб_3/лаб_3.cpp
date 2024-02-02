#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
int main(void) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Rus");
	char s[100], smbl;
	fgets(s, 100, stdin);
	fflush(stdin);

	int word_cnt = 0, letter_cnt = 0, m_max = 0, m_min = 100, pos_max = 0, pos_min = 0;
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == '.' && word_cnt != 0) {
			printf("\n%d\n", word_cnt+1);
			word_cnt = 0;
			letter_cnt = 0;
			printf("max: %d ", m_max);
			int n = pos_max - m_max + 1;
			for (int j = n; j <= pos_max; j++) {
				smbl = s[n];
				putchar(s[j]);
			}
			printf("\nmin: %d ", m_min);
			for (int j = pos_min - m_min + 1; j <= pos_min; j++) {
				putchar(s[j]);
				if (j == pos_min) { putchar(s[pos_min - m_min + 1]); }
			}
			m_max = 0;
			m_min = 100;
		}

		if (s[i] != ' ' && s[i] != '.' && s[i] != ',') {
			letter_cnt++;
			if (letter_cnt > m_max) {
				m_max = letter_cnt;
				pos_max = i;
			}
			if (letter_cnt < m_min && (s[i + 1] == ' ' || s[i + 1] == '.')) {
				m_min = letter_cnt;
				pos_min = i;
			}
		}
		if (s[i] == ' ' && letter_cnt != 0) {
			word_cnt++;
			letter_cnt = 0;
		}
	}
}