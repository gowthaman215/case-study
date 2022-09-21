#include "Epms.h"
#include <ctype.h>

int read_string(char* str, int length, int allowspace)
{
	int len;
	//printf("XXXXXXXXX:%s:%d:%d\n", str, length, allowspace);

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

char read_char()
{
	char ch;
	ch = getchar();
	if(ch == '\n')
	{
		//ch = getchar();
		scanf("%c%*c",&ch);
	}
	return ch;
}

char pause_on_keypress()
{
	char ch;
	scanf("%c",&ch);
	return ch;
}

char *ltrim(char *s)
{
	    while(isspace(*s)) s++;
	        return s;
}

char *rtrim(char *s)
{
	    char* back = s + strlen(s);
	        while(isspace(*--back));
		    *(back+1) = '\0';
		    return s;
}

char *trim(char *s)
{
	    return rtrim(ltrim(s)); 
}


