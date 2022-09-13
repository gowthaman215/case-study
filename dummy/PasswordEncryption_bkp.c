//Simple C program to encrypt and decrypt a string

#include "EmpProjMgmt.h"

int encrypt_password()
{
   int i, x;
   char str[100];

   printf("\nPlease enter a string:\t");
   scanf("%s",str);

   printf("\nPlease choose following options:\n");
   printf("1 = Encrypt the string.\n");
   printf("2 = Decrypt the string.\n");
   scanf("%d", &x);

   //using switch case statements
   switch(x)
   {
   case 1:
      for(i = 0; (i < 100 && str[i] != '\0'); i++)
        str[i] = str[i] + 3; //the key for encryption is 3 that is added to ASCII value

      printf("\nEncrypted string: %s\n", str);
      break;

   case 2:
      for(i = 0; (i < 100 && str[i] != '\0'); i++)
        str[i] = str[i] - 3; //the key for encryption is 3 that is subtracted to ASCII value

      printf("\nDecrypted string: %s\n", str);
      break;

   default:
      printf("\nError\n");
   }
   
}  
// C program to print *
// in place of characters
int read_password()
{
	char password[55];

	printf("password:\n");
	int p=0;
	do{
		password[p]=getc(stdin);
		if(password[p]!='\r'){
			printf("*");
		}
		p++;
	}while(password[p-1]!='\r');
	password[p-1]='\0';
	printf("\nYou have entered %s as password.",password);

   return 0;
}

int read_password1()
{

char password[128], c;
   int index = 0;
  
   printf("Enter Password : ");
   /* 13 is ASCII value of Enter key */
   while((c = getc(stdin)) != 13){
       if(index < 0)
           index = 0;
       /* 8 is ASCII value of BACKSPACE character */
       if(c == 8){
           putc('\b',stdout);
           putc(NULL,stdout);
           putc('\b',stdout);
           index--;
       continue;
       }
       password[index++] = c;
       putc('*',stdout);
   }
   password[index] = '\0';
 
   printf("\nPassword String = %s", password);
  
   return 0;
   }