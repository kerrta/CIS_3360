// Checksum

void readFile(char *filename, char *output);
char *checksum(int size, char *input);

void readFile(char *filename, char *output, int size)
{
	FILE *fp;
	char *buffer;
	int i = 0;

	fp = fopen(filename, "r");

	if(fp == NULL)
		printf("INVALID FILE\n");

	while(fscanf(fp, %c, buffer) != EOF)
	{
		output[i] = buffer[i];
	}

}

char *checksum(int size, char *input)
{

}