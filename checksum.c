
// Checksum
// James Upchurch

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


unsigned int long bitmask(char *word, int size)
{
	int i = 0;
	unsigned int long mask;
	mask = word[i];
	
	for(size -=8; size != 0; size -= 8)
	{
		mask = (mask << 8) + word[i + 1];
		i++;
	}

	return mask;
}

void checksum(int size, char *input, unsigned int long *check)
{
	unsigned int long word;

	word = bitmask(input, size);

	*check = word + *check;

	*check = *check << (64 - size);
	*check = *check >> (64 - size);

	//printf(" %s %lx %lx\n", input, *check, word);
	printf("%s", input);
}

void readFile(char *filename, int size)
{
	FILE *fp;
	int buffer, i = 0, j = 0, k, characterCnt = 0, wordLen = size / 8 + 1;
	unsigned int long *check = calloc(1, sizeof(unsigned int long));
	char *output = malloc(sizeof(char) * wordLen);

	if (size != 8 && size != 16 && size != 32)
	{
		fprintf(stderr, "Valid checksum sizes are 8, 16, or 32\n");
		return;
	}

	fp = fopen(filename, "r");
	printf("\n");

	if(fp == NULL)
	{
		printf("ERROR: FILE UNABLE TO OPEN\n");
		return;
	}

	while(buffer != EOF)
	{
		if (wordLen - i == 1)
		{
			output[i] = '\0';
			checksum(size, output, check);

			j++;
			i = 0;

			// Print 80 characters per line
			if (j * (wordLen - 1) == 80)
				printf("\n");
		}
		else
		{
			buffer = fgetc(fp);

			//printf("\n buf %c buf ", buffer);

			if (buffer == EOF)
			{
				if (size == 16 || size == 32)
				{
					if (wordLen - i != 1 && wordLen - i != wordLen)
					{
						for (k = 0; wordLen - i != 1 && wordLen - i != wordLen; i++, k++)
							output[i] = 'X';

						output[i] = '\0';

						checksum(size, output, check);

						j++;
						characterCnt += k - 1; 
						i = 0;

						// Print 80 characters per line
						if (j * (wordLen - 1) == 80)
							printf("\n");

					} else
						break;

				} else
					break;
			} else
				output[i] = buffer;
		
			characterCnt++;
			i++;
			//printf("\n out %s out %d\n", output, i);
		}
		
	}

	printf("\n");
	printf("%2d bit checksum is %8lx for all %4d chars\n", size, *check, characterCnt);

	fclose(fp);
}



int main(int argc, char *argv[])
{
	readFile(argv[1], atoi(argv[2]));

	return 0;
}
