/******************************************************************************
Password Encryption and Decryption Module.

*******************************************************************************/



#ifdef WIN32
#include <windows.h>
#else
#include <termios.h>
#include <unistd.h>
#endif

#include <stdio.h>

void SetStdinEcho(int enable)
{
#ifdef WIN32
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE); 
    DWORD mode;
    GetConsoleMode(hStdin, &mode);

    if( !enable )
        mode &= ~ENABLE_ECHO_INPUT;
    else
        mode |= ENABLE_ECHO_INPUT;

    SetConsoleMode(hStdin, mode );

#else
    struct termios tty;
    tcgetattr(STDIN_FILENO, &tty);
    if( !enable )
        tty.c_lflag &= ~ECHO;
    else
        tty.c_lflag |= ECHO;

    (void) tcsetattr(STDIN_FILENO, TCSANOW, &tty);
#endif
}

int encrypt_password(char *pwstr, char *encryptedpwstr)
{
   int i, x;
   for(i = 0; (i < 100 && pwstr[i] != '\0'); i++)
      encryptedpwstr[i] = pwstr[i] + 3; //the key for encryption is 3 that is added to ASCII value
   encryptedpwstr[i] = '\0';
	  
   return 0;
}  


int decrypt_password(char *encryptedpwstr, char *pwstr)
{
   int i, x;
   for(i = 0; (i < 100 && encryptedpwstr[i] != '\0'); i++)
      pwstr[i] = encryptedpwstr[i] - 3; //the key for encryption is 3 that is subtracted to ASCII value
   pwstr[i] = '\0';
    
   return 0;
}  

int read_password()
{
    
    char password[10+1];
	char encrypted_password[10+1];
	char decrypted_password[10+1];
    printf("Enter Password : ");
    SetStdinEcho(0);
    scanf("%10[A-Za-z0-9 ]s", password);
    SetStdinEcho(1);
    
    printf("\n");
    
    printf("password : %s",password);
	
	encrypt_password(password,encrypted_password);
	printf("\nEncrypted string: %s\n", encrypted_password);
	
	decrypt_password(encrypted_password,decrypted_password);
	printf("\nDecrypted string: %s\n", decrypted_password);
    
    return 0;
}
