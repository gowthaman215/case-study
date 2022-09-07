#include <stdio.h>
#include <string.h>

int read_string(char* str, int length);

int read_string(char* str, int length)
{
	fgets(str, length, stdin);
	if(str[0] == '\n')
	{
		//fgets(str, length, stdin);
		scanf("%[^\n]%*c", str);
		//str = trim(str);
	}
	int len = strlen(str);
	if (str[len-1] == '\n')
	{
		str[len-1] = '\0';
	}
	return 0;
}

int main()
{
	char str[50];
	read_string(str, 30);
	printf("string is [%s]", str);
}
