
/******************************************************************************
  Employee Project Management
 *******************************************************************************/
#include "Epms.h"
#include <unistd.h>

char logon_user[MAX_ID];
char logon_password[MAX_PW];
int return_code;


int show_app_title()
{
	printf("\t\t\t\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
	printf("\t\t\t\t\t|E M P L O Y E E   P R O J E C T   M A N A G M E N T|\n");
	printf("\t\t\t\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
	printf("\n\n");
}

int read_user_credential()
{

	printf("\t\t\t\t\tUser ID : "); 
	scanf("%s",logon_user);
	printf("\t\t\t\t\tPassword: "); 
	SetStdinEcho(0);
	scanf("%s", logon_password);
	SetStdinEcho(1);
}

int proc_login()
{
        char choice;
	system("clear");
	show_app_title();
	printf("\t\t\t\t\tLogin Application\n\n");
	printf("\t\t\t\t\t1. Admin\n");
	printf("\t\t\t\t\t2. Employee\n");
	printf("\t\t\t\t\t3. Exit\n");

	printf("\t\t\t\t\tYour choice ");
	//scanf("%c%*c",&choice);
	choice = read_char();

	printf("\n\n");

	if(choice == '1')
	{        
                read_user_credential();
		return_code = validate_user(logon_user, logon_password, ADMIN);
		if(return_code != 0)
		{ 
			printf("\n\n");
			printf("\t\t\t\t\tInvalid credential");
			pause_on_keypress();
			return INVALID_CREDENTIAL;
		}
	        	
		proc_admin_login();
	}
	else if (choice == '2')
	{
	     
                read_user_credential();
		return_code = validate_user(logon_user, logon_password, EMPLOYEE);
		if(return_code != 0)
		{ 
			printf("\n\n");
			printf("\t\t\t\t\tInvalid credential");
			pause_on_keypress();
			return INVALID_CREDENTIAL;
		}

		proc_emp_login();
	}
	else if(choice == '3')
	{
		return USER_EXIT;	
	}
	else
	{
		printf("\t\t\t\t\tInvalid Choice\n\n");
		pause_on_keypress();

	}


}

int validate_user(char* logon_user, char* logon_password, usertype_t user_type)
{
	if(user_type == ADMIN)
	{
		if (strcmp(logon_user,ADMIN_ID) == 0 && strcmp(logon_password,ADMIN_PW) == 0)
			return SUCCESS;
		else
			return INVALID_CREDENTIAL; 

	}
	else
	{

	}
}

int proc_admin_login()
{
	
        while(1)	
	{      
		char choice;
		system("clear");
		show_app_title();
		printf("\t\t\t\t\tLogon user [%s] \t\t\t User Type [ADMIN] \t\t\t Environment [DEVELOPMENT]\n",logon_user);
		printf("\n\n");
		printf("\t\t\t\t\tOptions\n\n");
		printf("\t\t\t\t\t1. Add Employee\n");
		printf("\t\t\t\t\t2. Delete Employee\n");
		printf("\t\t\t\t\t3. View Employee Details\n");
		printf("\t\t\t\t\t4. Add Project\n");
		printf("\t\t\t\t\t5. Delete Project\n");
		printf("\t\t\t\t\t6. View Project Details\n");
		printf("\t\t\t\t\t7. Allocate Project\n");
		printf("\t\t\t\t\t8. logout\n");

		printf("\t\t\t\t\tYour choice ");
		//scanf("%*c%c%*c",&choice);
		choice = read_char();

		printf("\n\n");
		
		switch(choice)
		{
			case '1':
				add_employee();
				break;
			case '2':
				delete_employee();
				break;
			case '3':
				view_all_employees();
				break;
			case '4':
				add_project();
				break;
			case '5':
				delete_project();
				break;
			case '6':
				view_all_projects();
				break;
			case '7':
				allocate_project();
				break;
			case '8':
			        logout_admin_user();	
				return USER_LOGOUT;
			default:
				printf("\t\t\t\t\tInvalid choice. please try again\n");
				pause_on_keypress();
		}

	}
}

int proc_emp_login()
{
	char choice;

	do
	{      
		system("clear");
		show_app_title();
		printf("\t\t\t\t\tLogon user [%s] \t\t\t User Type [EMPLOYEE] \t\t\t Environment [DEVELOPMENT]\n",logon_user);
		printf("\n\n");
		printf("\t\t\t\t\tOptions\n\n");
		printf("\t\t\t\t\t1. View Personal Details\n");
		printf("\t\t\t\t\t2. View Employment/Project Details\n");
		printf("\t\t\t\t\t3. logout\n");

		printf("\t\t\t\t\tYour choice ");
	       
		//scanf("%c",&choice);
		choice = read_char();

		printf("\n\nchoice is %c", choice);

		switch(choice)
		{
			case '1':
				view_personal_details;
				break;
			case '2':
				view_projects_details();
				break;
			case '3':
			        logout_emp_user();	
				break;
			default:
				printf("\t\t\t\t\tInvalid choice. please try again\n");
		}

		printf("\n\n");

	}while(choice != '3');

}


int main()
{
	while(1)
	{      
		return_code = proc_login();

		if(return_code == USER_EXIT)
		{
			printf("\t\t\t\t\tUser has Exited Application\n\n");
			break;
		}	
	}
	
	printf("\t\t\t\t\tExiting application\n\n");
	return 0;
}
