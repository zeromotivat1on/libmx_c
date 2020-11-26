#include "../inc/libmx.h"

char **mx_strsplit(char const *s, char c) {
	int count_words = mx_count_words(s, c);
	char **result = (char**)malloc(8 * count_words);
	int j = 0;
	for (int i = 0; i < count_words; ++i) {
		int word_length = 0;
		int start = 0;
		for (; s[j]; ++j) {
			if (s[j] != c) { 
				word_length += 1;
				if (start == 0) start = j;
			}
			else if (s[j] == c && word_length) break;
		}
		char* new_word = mx_strnew(word_length);
		for (int k = 0, m = start; m < j; ++k, ++m) new_word[k] = s[m];
		result[i] = new_word;
	}
	result[count_words] = NULL;
	return result;
}
