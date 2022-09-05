
/******************************************************************************
  Employee Project Management
 *******************************************************************************/
#include "Epms.h"
#include <unistd.h>

char choice;
char logon_user[10+1];
char logon_password[10+1];
int return_code;

int show_app_title()
{
	printf("\t\t\t\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
	printf("\t\t\t\t\t|E M P L O Y E E   P R O J E C T   M A N A G M E N T|\n");
	printf("\t\t\t\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
	printf("\n\n");
}

int proc_login()
{


	show_app_title();
	printf("\t\t\t\t\tLogin Application\n\n");
	printf("\t\t\t\t\t1. Admin\n");
	printf("\t\t\t\t\t2. Employee\n");
	printf("\t\t\t\t\t3. Exit\n");

	printf("\t\t\t\t\tYour choice ");
	scanf("%c",&choice);
	fflush(stdin);

	printf("\n\n");

	if(choice == '1')
	{        

		printf("\t\t\t\t\tAdmin Name : "); 
		scanf("%s",logon_user);
		fflush(stdin);
		printf("\t\t\t\t\tAdmin Password  : "); 
		scanf("%s",logon_password);
		fflush(stdin);
	        //validate_user(char* logon_user, char* logon_password, ADMIN);	
		proc_admin_login();
	}
	else if (choice == '2')
	{
		printf("\t\t\t\t\tEmployee Name : "); 
		scanf("%s",logon_user);
		fflush(stdin);
		printf("\t\t\t\t\tEmployee Password  : ");
		scanf("%s",logon_password);
		fflush(stdin);
	        //validate_user(char* logon_user, char* logon_password, EMPLOYEE);	
		proc_emp_login();
	}
	else if(choice == '3')
	{
		return 3;	
	}
	else
	{ 
		printf("\t\t\t\t\tInvalid Choice\n\n");

	}

        choice = ' ';

}

int proc_admin_login()
{
	
	do
	{      
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
		
	        getchar();
		scanf("%c",&choice);
		fflush(stdin);

		printf("\n\nchoice is %c", choice);

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
				break;
			default:
				printf("\t\t\t\t\tInvalid choice. please try again\n");
		}

		printf("\n\n");

	}while(choice != '8');
}

int proc_emp_login()
{
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
	       
	        getchar();	
		scanf("%c",&choice);
		fflush(stdin);

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
	        system("clear");	
		return_code = proc_login();

		if(return_code == 3)
		{
			printf("\t\t\t\t\tUser has Exited Application\n\n");
			break;
		}	
	}
	
	printf("\t\t\t\t\tExiting application\n\n");
	return 0;
}
