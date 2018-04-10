// Checksum
// James Upchurch

void readFile(char *filename, char *output);
char *checksum(int size, char *input);

void readFile(char *filename, int size)
{
	FILE *fp;
	int buffer, i = 0, wordLen = size / 4 + 1;
	char *output = malloc(sizeof(char * wordLen));
	char *check = calloc(wordLen, char);

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

		if (wordLen - i == 1)
		{
			output[i] = '\0';
			checksum(size, output, check);
			i = 0;
		}
		else
			output[i] = buffer;

		i++;
	}


	fclose(fp);
}

void checksum(int size, char *input, char *check)
{
	
}



int main(int argc, char *argv[])
{
	readFile(argv[1], argv[2]);

	return 0;
}