
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

	printf("\t\t\t\t\tEnter Login Details...\n\n"); 
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

	printf("\t\t\t\t\tYour choice? ");
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
			printf("\t\t\t\t\tInvalid credential\n\n");
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
			printf("\t\t\t\t\tInvalid credential\n\n");
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

        return SUCCESS;
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
	
	char choice[2+1];
        while(1)	
	{     
	        memset(choice,'\0',sizeof(choice));	
		system("clear");
		show_app_title();
		printf("\tLogon user [%s] \t\t\t\t User Type [ADMIN] \t\t\t\t Environment [DEVELOPMENT]\n",logon_user);
		printf("\n\n");
		printf("\t\t\t\t\tOptions\n\n");
		printf("\t\t\t\t\t1. Add New Admin\n");
		printf("\t\t\t\t\t2. Delete Admin\n");
		printf("\t\t\t\t\t3. Add New Employee\n");
		printf("\t\t\t\t\t4. Modify Employee Details\n");
		printf("\t\t\t\t\t5. Delete Employee\n");
		printf("\t\t\t\t\t6. View Employee Details\n");
		printf("\t\t\t\t\t7. Add New Project\n");
		printf("\t\t\t\t\t8. Modify Project Details\n");
		printf("\t\t\t\t\t9. Delete Project\n");
		printf("\t\t\t\t\t10. View Project Details\n");
		printf("\t\t\t\t\t11. Allocate Employee to Project\n");
		printf("\t\t\t\t\t12. Deallocate Employee from Project\n"); 
		printf("\t\t\t\t\t13. Change Password\n");
		printf("\t\t\t\t\t14. Logout\n");
		
		printf("\t\t\t\t\tYour choice? ");
		read_string(choice,2);

		printf("\n\n");

		if(strcmp(choice, "1") == 0)
		{
			//1. Add New Admin
			add_admin();
		}
		else if (strcmp(choice, "2") == 0)
		{
			//2. Delete Admin
			delete_admin();
		}
		else if (strcmp(choice, "3") == 0)
		{
			//3. Add New Employee
			add_employee();


		}
		else if (strcmp(choice, "4") == 0)
		{
			//4. Modify Employee Details
			modify_employee();

		}
		else if (strcmp(choice, "5") == 0)
		{
			//5. Delete Employee
			delete_employee();

		}
		else if (strcmp(choice, "6") == 0)
		{
			//6. View Employee Details
			view_all_employees();

		}
		else if (strcmp(choice, "7") == 0)
		{
			//7. Add New Project
			add_project();

		}
		else if (strcmp(choice, "8") == 0)
		{
			//8. Modify Project Details
			modify_project();

		}
		else if (strcmp(choice, "9") == 0)
		{
			//9. Delete Project
			delete_project();

		}
		else if (strcmp(choice, "10") == 0)
		{
			//10. View Project Details
			view_all_projects();

		}
		else if (strcmp(choice, "11") == 0)
		{
			//11. Allocate Employee to Project
			allocate_project();

		}
		else if (strcmp(choice, "12") == 0)
		{
			//12. Deallocate Employee from Project
			deallocate_project();

		}
		else if (strcmp(choice, "13") == 0)
		{
			//13. Change Password
			change_password();

		}
		else if (strcmp(choice, "14") == 0)
		{
			//14. Logout
			logout_admin_user();	
			return USER_LOGOUT;

		}
		else
		{
			printf("\t\t\t\t\tInvalid choice. please try again\n");
			pause_on_keypress();

		}
		
		/*
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
		}*/

	}
}

int proc_emp_login()
{
	char choice;

	do
	{      
		system("clear");
		show_app_title();
		printf("\tLogon user [%s] \t\t\t\t User Type [EMPLOYEE] \t\t\t\t Environment [DEVELOPMENT]\n",logon_user);
		printf("\n\n");
		printf("\t\t\t\t\tOptions\n\n");
		printf("\t\t\t\t\t1. View Personal Details\n");
		printf("\t\t\t\t\t2. View Employment/Project Details\n");
		printf("\t\t\t\t\t3. Update Personal Details\n");
		printf("\t\t\t\t\t4. Update Project Details\n");
		printf("\t\t\t\t\t5. Change Password\n");
		printf("\t\t\t\t\t6. Logout\n");

		printf("\t\t\t\t\tYour choice? ");
	       
		//scanf("%c",&choice);
		choice = read_char();

		printf("\n\nchoice is %c", choice);

		switch(choice)
		{
			case '1': 
				
				//1. View Personal Details
				view_personal_details;
				break;

			case '2': 
				
				//2. View Employment/Project Details
				view_projects_details();
				break;

			case '3':
				//3. Update Personal Details
				update_personal_details;
				break;

			case '4':
				//4. Update Project Details
				update_projects_details();
				break;

			case '5':
				//5. Change Password
			        change_emp_password();	
				break;

			case '6':
				//6. Logout
			        logout_emp_user();	
				break;

			default:
				printf("\t\t\t\t\tInvalid choice. please try again\n");
		}

		printf("\n\n");

	}while(choice != '6');

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
