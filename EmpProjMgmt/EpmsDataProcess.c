#include "Epms.h"

// this is for file processing

int add_admin()
{

}

int delete_admin()
{

}

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

int modify_employee()
{

}

int delete_employee()
{
}

int view_all_employees()
{
}

int add_project()
{
        FILE *fp;
        fp = fopen ("project.dat", "a");
        if (fp == NULL) {
                printf("\nError opened file\n");
                exit (1);
        }
        project_details_t pd;
        pd.proj_id = generate_proj_id();
        printf("[New Record]\n");
        printf("Project ID      : %d\n", pd.proj_id);
        printf("Project Name   : "); read_string(pd.project_name, MAX_NAME);
        printf("Enter day:FORMAT: DD  : "); scanf("%u", &pd.start_date.day);
        printf("Enter day:FORMAT: MM  : "); scanf("%u", &pd.start_date.month);
        printf("Enter day:FORMAT: YYYY  : "); scanf("%u", &pd.start_date.year);
        printf("Number of resources required : "); scanf("%u", &pd.no_res_required);
        printf("Number of resources alloted : "); scanf("%u", &pd.no_res_alloted);

        printf("\n\n");
        printf("Project ID      : %d\n", pd.proj_id);
        printf("Project Name    : [%s]\n", pd.project_name);
        printf("DATE         : %u/%u/%u\n", pd.start_date.day, pd.start_date.month, pd.start_date.year);
        printf("Number of resources required  : [%u]\n", pd.no_res_required);
        printf("Number of resources alloted  : [%u]\n", pd.no_res_alloted);

        //Write data into the file
        fwrite (&pd, sizeof(project_details_t), 1, fp);
        if(fp != 0) {
                printf("contents to file written successfully !\n");
        } else {
                printf("error writing file !\n");
        }
        fclose(fp);

        pause_on_keypress();
}

int modify_project()
{

}

int delete_project()
{
}

int view_all_projects()
{
	printf("Development under progress\n");
	FILE *fp1;
	fp1 = fopen ("project.dat", "r");
	if (fp1 == NULL) {
		printf("\nError opened file\n");
		exit (1);
	}
	project_details_t pd1;
	printf ("proj_id|proj_name|start_date|res_reqired|res_allocated|\n");
	
	while(fread(&pd1, sizeof(project_details_t), 1, fp1))
		printf ("%d|%s|%u-%u-%u|%u|%u|\n", pd1.proj_id, pd1.project_name,pd1.start_date.day,pd1.start_date.month,pd1.start_date.year,pd1.no_res_required,pd1.no_res_alloted);
	
	fclose (fp1);
	pause_on_keypress();
}

int allocate_project()
{
}

int deallocate_project()
{

}

int change_password()
{

}

int logout_admin_user()
{
}


int view_personal_details()
{
}

int view_projects_details()
{
}

int update_personal_details()
{

}

int update_projects_details()
{

}

int change_emp_password()
{

}

int logout_emp_user()
{
}

int generate_emp_id(char* empid) //e1111111
{
	strcpy(empid,"e5585437");

}


int generate_proj_id() //p1111111
{
	srand(time(0));
	int id = rand();
	return id;
}


