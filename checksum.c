
// Checksum
// James Upchurch

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void readFile(char *filename, int size)
{
	FILE *fp;
	int buffer, i = 0, j = 0, characterCnt = 0, wordLen = size / 4 + 1;
	int *check = calloc(1, int);
	char *output = malloc(sizeof(char * wordLen));

	if (size != 8 && size != 16 && size != 32)
	{
		fprintf(stderr, "Valid checksum sizes are 8, 16, or 32\n");
		return;
	}

	fp = fopen(filename, "r");

	if(fp == NULL)
		printf("ERROR: FILE UNABLE TO OPEN\n");

	while(buffer != EOF)
	{
		buffer = fgetc(fp);
		if (buffer == EOF)
		{
			output[i] = 'X';
			output[i++] = '\0';
			break;
		}

		characterCnt++;

		if (wordLen - i == 1)
		{
			output[i] = '\0';
			checksum(size, output, check);

			printf("%s", output);
			j++;
			i = 0;

			if (j * (wordLen - 1) == 80)
				printf("\n");
		}
		else
			output[i] = buffer;

		i++;
	}

	printf("%2d bit checksum is %8lx for all %4d chars\n", size, check, characterCnt);

	fclose(fp);
}

void checksum(int size, char *input, int *check)
{
	int word, tempCheck;

	word = bitmask(input, size);
	tempCheck = bitmask(check, size);

	*check = word + tempCheck;
}

int bitmask(char *word, int size)
{
	int i = 0, mask;
	mask = word[i];
	
	for(size; size != 0; size = size - 8)
	{
		mask = (mask << 8) + word[i + 1];

		i++;
	}

	return mask;
}

int main(int argc, char *argv[])
{
	readFile(argv[1], argv[2]);

	return 0;
}