#include "Epms.h"

// this is for file processing

int add_employee()
{
	employee_details_t ed;
	char confirm_pw[MAX_PW];

	generate_emp_id(ed.emp_id);

	printf("[New Record]\n");
	printf("Employee ID      : %s\n", ed.emp_id);

	printf("Employee Name    : "); read_string(ed.emp_name, MAX_NAME);
	printf("Password         : "); read_string(ed.emp_password, MAX_PW);
	printf("Confirm Password : "); read_string(confirm_pw, MAX_PW);
	printf("Status           : "); ed.emp_status = read_char();
	printf("Gender           : "); ed.gender = read_char();
	printf("Basic Salary     : "); scanf("%ld", &ed.basic_salary);
	printf("Bonus            : "); scanf("%ld", &ed.bonus);
        
	printf("\n\n");

	printf("Employee Name    : [%s]\n", ed.emp_name);
	printf("Password         : [%s]\n", ed.emp_password);
	printf("Confirm Password : [%s]\n", confirm_pw);
	printf("Status           : %c\n", ed.emp_status);
	printf("Gender           : %c\n", ed.gender);
	printf("Basic Salary     : %ld\n", ed.basic_salary);
	printf("Bonus            : %ld\n", ed.bonus);
	
	pause_on_keypress();

}

int add_project()
{

}

int delete_employee()
{
}

int delete_project()
{
}

int allocate_project()
{
}

int logout_admin_user()
{
}

int view_all_employees()
{
}

int view_all_projects()
{
}

int generate_emp_id(char* empid) //e1111111
{
	strcpy(empid,"e5585437");

}


int generate_proj_id(char* empid) //p1111111
{

}

int view_personal_detailsi()
{
}

int view_projects_details()
{
}

int logout_emp_user()
{
}

