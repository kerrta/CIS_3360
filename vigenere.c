#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 512

void readInput(char *filename, char *output)
{
	int i;
	int buffer;
	FILE *fp;

	fp = fopen(filename, "r");

	if (fp == NULL)
	{
		printf("FILE COULD NOT OPEN \n");
		return;
	}

	for(i = 0; i < MAX_LENGTH; i++)
	{
		buffer = fgetc(fp);

		if (buffer == EOF)
		{
			output[i] = '\0';
			break;
		}

		if(isalpha(buffer))
		{
			buffer = tolower(buffer);
			output[i] = buffer;
		}
		else
			i--;
	}

	output[i] = '\0';

	fclose(fp);
}

void vigenere(char *plain, char *cipher, char *key)
{
	int i, len = strlen(plain), keylen = strlen(key);
	char buffer;

	for (i = 0; i < len; i++)
	{
		buffer = ((plain[i] + key[i % keylen]) - (2 * 'a')) % 26;
		cipher[i] = buffer + 'a';
	}
}

void pad(char *plaintext, char *key)
{
	int keylen = strlen(key), plainlen = strlen(plaintext), temp, i;

	temp = plainlen % keylen;
	temp = keylen - temp;

	if (temp != 0)
		for (i = 0; i < temp && i + plainlen < 512; i++)
			plaintext[i + plainlen] = 'x';
}

void printResults(char *plaintext, char *key, char *cipher)
{
	int i, plainLen = strlen(plaintext), keyLen = strlen(key), cipherLen = strlen(cipher);

	printf("\n\nVigenere Key:\n\n");

	for (i = 0; i < keyLen; i++)
	{
		if (i % 80 == 0 && i != 0)
		{
			printf("\n");
			printf("%c", key[i]);
		}
		else
			printf("%c", key[i]);
	}

	printf("\n\n\nPlaintext:\n\n");

	for (i = 0; i < plainLen; i++)
	{
		if (i % 80 == 0 && i != 0)
		{
			printf("\n");
			printf("%c", plaintext[i]);
		}
		else
			printf("%c", plaintext[i]);
	}

	printf("\n\n\nCiphertext:\n\n");

	for (i = 0; i < cipherLen; i++)
	{
		if (i % 80 == 0 && i != 0)
		{
			printf("\n");
			printf("%c", cipher[i]);
		}
		else
			printf("%c", cipher[i]);
	}

	printf("\n");	
}


int main(int argc, char *argv[])
{
	char *keyarray = malloc(sizeof(char) * (MAX_LENGTH + 1));
	char *plain = malloc(sizeof(char) * (MAX_LENGTH + 1));
	char *cipher = malloc(sizeof(char) * (MAX_LENGTH + 1));

	readInput(argv[1], keyarray);
	readInput(argv[2], plain);

	pad(plain, keyarray);

	vigenere(plain, cipher, keyarray);

	printResults(plain, keyarray, cipher);

	return 0;
}


