#include "Epms.h"
#include <ctype.h>

int read_string(char* str, int length)
{
	fgets(str, length, stdin);
	if(str[0] == '\n')
	{
		//fgets(str, length, stdin);
		scanf("%[^\n]%*c", str);
		str = trim(str);
	}
	int len = strlen(str);
	if (str[len-1] == '\n')
	{
		str[len-1] = '\0';
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
	scanf("%c%*c",&ch);
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
