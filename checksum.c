// Checksum
// James Upchurch

void readFile(char *filename, char *output);
char *checksum(int size, char *input);

void readFile(char *filename, int size)
{
	FILE *fp;
	int buffer, i = 0;
	char *output = malloc(sizeof(char * (size / 4) + 1));

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

		output[i] = buffer;
		i++;
	}


	fclose(fp);
}

char *checksum(int size, char *input)
{

}



int main(int argc, char *argv[])
{
	readFile(argv[1], argv[2]);

	return 0;
}