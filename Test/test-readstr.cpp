#include <stdio.h>
#include <string.h>


int read_string(char* str, int length, int allowspace)
{
	int len;

	while(1)
	{
		memset(str, '\0', length);
		scanf("%[^\n]%*c", str);

		if(str[0] == '\n' || str[0] == '\0')
		{
			scanf("%[^\n]%*c", str);
		}


		len = strlen(str);

		if (len > length)
		{
			printf("Enter value <= %d characters : ", length);
			continue;
		}
		else if(allowspace == 0 && strstr(str," ") != NULL)
		{
			printf("Enter value without space : ");
			continue;
		}
		else
		{
			break;
		}

	}

	return 0;
}

int main()
{
	char str[50];
	char str1[50];

	printf("str : ");
	read_string(str,10,1);
	printf("str1 : ");
	read_string(str1,10,1);
}

