#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char alphabet[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

char itochar(int i);
int chartoi(char c);
char tabularecta(int row, int col);

int main(int argc, char** argv){
	if(argc < 3){
		printf("Usage: decipher [cipher] [keyword]\nKeyword must be all caps.");
		exit(EXIT_FAILURE);
	}

	int cip_len = strlen(argv[1]);
	int key_len = strlen(argv[2]);

	char* cipher = argv[1];
	char msg_str[cip_len];

	for(int i = 0; i < cip_len; i++){
		if(cipher[i] < 65 || cipher[i] > 90){
			if(cipher[i] >= 97 && cipher[i] <= 122){
				cipher[i] -= 32;
			}else{
				msg_str[i] = cipher[i];
				continue;
			}
		}

		char key_char = argv[2][i % key_len];
		int row = chartoi(key_char);
		int dec = (chartoi(cipher[i]) - row + 26) % 26;

		msg_str[i] = itochar(dec);
	}
	msg_str[cip_len] = '\0';

	printf("Cipher  : %s\n", cipher);
	printf("Message : %s\n", msg_str);
}

char itochar(int i){
	if(i < 0 || i > 25){
		printf("itochar: int '%i' is out of bounds.\n", i);
		exit(EXIT_FAILURE);
	}

	return (char) (i + 65);
}

int chartoi(char c){
	if(c < 65 || c > 90){
		printf("chartoi: character '%c' is out of bounds.\n", c);
		exit(EXIT_FAILURE);
	}

	return (int) (c - 65);
}
