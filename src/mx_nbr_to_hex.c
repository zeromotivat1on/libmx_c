#include "../inc/libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
	if (nbr > 4294967295) return 0;
	unsigned long quotient = nbr;
	int remainder, j = 0, size = 0;
	int temp = nbr;
	while (temp != 0) {
		size++;
		temp /= 16;
	}
	char *hexadecimal = mx_strnew(size);
	while (quotient != 0) {
		remainder = quotient % 16;
		if (remainder < 10)
			hexadecimal[j] = 48 + remainder;
		else
			hexadecimal[j] = 87 + remainder;
		j++;
		quotient /= 16;
	}
	j--;
	for (int i = 0; i < j; i++, j--) {
		char tmp = hexadecimal[i];
		hexadecimal[i] = hexadecimal[j];
		hexadecimal[j] = tmp;
	}
	return hexadecimal;
}
