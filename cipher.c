#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char alphabet[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int chartoi(char c);
char tabularecta(int row, int col);

int main(int argc, char** argv){
	if(argc < 3){
		printf("Usage: cipher [message] [keyword]\nKeyword must be all caps.\n");
		exit(EXIT_FAILURE);
	}

	int msg_len = strlen(argv[1]);
	int key_len = strlen(argv[2]);

	char* msg_str = argv[1];
	char cipher[msg_len];

	for(int i = 0; i < msg_len; i++){
		if(msg_str[i] < 65 || msg_str[i] > 90){
			if(msg_str[i] >= 97 && msg_str[i] <= 122){
				msg_str[i] -= 32;
			}else{
				cipher[i] = msg_str[i];
				continue;
			}
		}

		char key_char = argv[2][i % key_len];
		int row = chartoi(key_char);
		int col = chartoi(msg_str[i]);
		cipher[i] = tabularecta(row, col);
	}
	cipher[msg_len] = '\0';

	printf("Message : %s\n", msg_str);
	printf("Cipher  : %s\n", cipher);
}

int chartoi(char c){
	if(c < 65 || c > 90){
		printf("chartoi: character '%c' is out of bounds.\n", c);
		exit(EXIT_FAILURE);
	}

	return (int) (c - 65);
}

char tabularecta(int row, int col){
	if(row < 0 || col < 0 || row > 25 || col > 25){
		printf("tabularacta: (%d, %d) is out of bounds.\n", col, row);
		exit(EXIT_FAILURE);
	}

	return alphabet[(row + col) % 26];
}
