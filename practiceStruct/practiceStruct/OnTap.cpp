#define _CRT_SECURE_NO_WARINGS
#include <stdio.h>
#include <string.h>

int main() {
	char str[] = "day la mot chuoi duoc tach boi dau cach";
	const char delim[] = " ";
	char *token;
	char *tokens[100]; // Gi? s? chu?i kh�ng c� qu� 100 token
	int i = 0;

	// T�ch chu?i ??u ti�n
	token = strtok(str, delim);

	// Ti?p t?c t�ch c�c chu?i ti?p theo
	while (token != NULL) {
		tokens[i] = token; // L?u token v�o m?ng
		i++;
		token = strtok(NULL, delim);
	}

	// Truy xu?t ph?n t? th? i (v� d? ph?n t? th? 3)
	int index = 3; // Ch? s? b?t ??u t? 0, ph?n t? th? 3 l� index 2
	if (index < i) {
		printf("Phan tu thu %d: %s\n", index, tokens[index]);
	}
	else {
		printf("Khong co phan tu thu %d\n", index);
	}

	return 0;
}
