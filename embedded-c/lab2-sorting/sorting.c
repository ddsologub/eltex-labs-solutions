#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int inp_str(char **string, int maxlen)
{
		char buf[maxlen];
		
		char c = getchar();
		int len = 0;
		while (c != '\n' && c != EOF) {
			buf[len] = c;
			c = getchar();
			len++;
		}
		buf[len] = '\0';

		*string = (char*)malloc(sizeof(char) * len + sizeof('\0'));
		strcpy(*string, buf);

		return len;
}

void out_str(char* string, int length, int number)
{
	printf("%s\n", string);
}

int compare_length(const void *p1, const void *p2)
{
	char **s1 = (char **)p1;
	char **s2 = (char **)p2;

	int len1 = strlen(*s1);
	int len2 = strlen(*s2);

	return (len1 - len2);
}

int compare_lex(const void *p1, const void *p2)
{
	char **s1 = (char **)p1;
	char **s2 = (char **)p2;

	return strcmp(*s1, *s2);
}

// empty string returns one word
// ending spaces mistakenly adding a word to count
int get_word_num(char *s)
{
	int word_num = 1;
	bool is_word = false;

	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] == ' ') {
			if (is_word)
			{
				word_num++;
				is_word = false;
			} else {
				continue;
			}
		} else {
			if (!is_word)
				is_word = true;
		}
	}

	return word_num;
}

int compare_word_num(const void *p1, const void *p2)
{
	char **s1 = (char **)p1;
	char **s2 = (char **)p2;
	
	return (get_word_num(*s1) - get_word_num(*s2));
}

int get_digit_num(char *s)
{
	int count = 0;

	for (int i = 0; s[i] != '\0'; i++) {
		if ('0' <= s[i] && s[i] <= '9')
			count++;
	}

	return count;
}

int compare_digit_num(const void *p1, const void *p2)
{
	char **s1 = (char **)p1;
	char **s2 = (char **)p2;
	
	return (get_digit_num(*s1) - get_digit_num(*s2));	
}

int get_first_word_len(char *s)
{
	int i;
	for (i = 0; s[i] == ' ' && s[i] != '\0'; i++);

	int len = 0;
	while (s[i] != ' ' && s[i] != '\n') {
		i++;
		len++;
	}

	return len;
}

int compare_first_word_len(const void *p1, const void *p2)
{
	char **s1 = (char **)p1;
	char **s2 = (char **)p2;

	return (get_first_word_len(*s1) - get_first_word_len(*s2));
}


int main(void)
{
	int n = 0;
	scanf("%d\n", &n);
	const int MAXSTRLEN = 256;

	char **arr = (char**)malloc(sizeof(char*) * n);

	for (int i = 0; i < n; i++) {
		inp_str(&arr[i], MAXSTRLEN);
	}

	//TODO: Reverse function which inverse results of comparing functions
	qsort(&arr[0], n, sizeof(char*), compare_first_word_len);

	for(int i = 0; i < n; i++) {
		out_str(arr[i], 0, i);
	}

	for(int i = n; i >= 0; i--) {
		free(arr[i]);
	}
	free(arr);

	return 0;
}