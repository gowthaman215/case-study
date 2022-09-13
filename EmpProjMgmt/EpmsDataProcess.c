#include "Epms.h"

// this is for file processing

int add_admin()
{
	char admin_id[MAX_ID];
	char admin_pw[MAX_PW];
	char confirm_pw[MAX_PW];
        FILE *fp;
        
	fp = fopen ("./datafile/Admin-Details.DAT", "a");
        if (fp == NULL) {
                printf("\nError opened file\n");
                exit (1);
        }

	printf("[New Record]\n");
	printf("Admin ID         : ");
	read_string(admin_id, MAX_ID,0);
	
	while(1)
	{
		printf("Password         : ");
		SetStdinEcho(0);
		read_string(admin_pw, MAX_PW,0);
		SetStdinEcho(1);
                printf("\n");
		printf("Confirm Password : "); 
		SetStdinEcho(0);
		read_string(confirm_pw, MAX_PW,0);
		SetStdinEcho(1);
                printf("\n");

		if(strcmp(admin_pw,confirm_pw) == 0)
		{

			encrypt_password(confirm_pw,admin_pw);
			fprintf(fp,"%s,%s\n",admin_id,admin_pw);
			fclose(fp);
			break;
		}
		else
		{
			printf("Password and Confirm Password should match .. \n");
		}

	}
        printf("\n\n");
	printf("Admin user created\n");
	pause_on_keypress();

}

int view_admin()
{

	FILE *fp;
	char admin_id[MAX_ID];
	char admin_pw[MAX_PW];

	fp = fopen ("./datafile/Admin-Details.DAT", "r");
	if (fp == NULL) {
		printf("\nError opened file\n");
		exit (1);
	}
        
 	printf ("All Admin Details...\n\n");
 	printf ("Admin ID\n");
	printf ("===============\n");


        fseek(fp, 0, SEEK_SET);
	while (fgets(admin_id,MAX_ID,fp) != NULL) {
		printf("%s\n",admin_id);
		fgets(admin_pw,MAX_PW + 1,fp);
	}	

	fclose (fp);
	pause_on_keypress();
}

int delete_admin()
{
	char ch;
	int found = 0;
	char admin_id[MAX_ID];
	char line[20];
	char admin_pw[MAX_PW];
	
        FILE *fp, *fpt;
        
	fp = fopen ("./datafile/Admin-Details.DAT", "r+");
        if (fp == NULL) {
                printf("\nError opened file\n");
                exit (1);
        }

	fpt = fopen ("./datafile/Admin-Details.TMP", "w");
        if (fp == NULL) {
                printf("\nError opening temp file\n");
                exit (1);
        }

	printf("[Delete Record]\n");
	printf("Admin ID      : "); read_string(admin_id, MAX_ID,0);

	fseek(fp, 0, SEEK_SET);
	while(fscanf(fp, "%s", line) != EOF)
	{
		if(strstr(line,strcat(admin_id,",")) == NULL)
		{
			fprintf(fpt, "%s\n", line);
		}
	}

	
	printf("\n\n");
	printf("Employee Record has been modified successfully.\n");
	
	fclose(fpt);
	fclose(fp);
        
	remove("./datafile/Admin-Details.DAT");
        rename("./datafile/Admin-Details.TMP", "./datafile/Admin-Details.DAT");	
	
	//write_sequence_file();
	pause_on_keypress();

}

int add_employee()
{
	char ch;
	employee_details_t ed;
	char confirm_pw[MAX_PW];
        FILE *fp;
        
	fp = fopen ("./datafile/Employee-Details.DAT", "a");
        if (fp == NULL) {
                printf("\nError opened file\n");
                exit (1);
        }

	do
	{
	generate_emp_id(ed.emp_id);

	printf("[New Record]\n");
	printf("Employee ID      : %s\n", ed.emp_id);
	printf("Employee Name    : "); read_string(ed.emp_name, MAX_NAME,1);
	ed.emp_status = 'U'; //F - Fully Allocated, P - Partly Allocated , U - Unallocated
	printf("Gender           : "); ed.gender = toupper(read_char());
	printf("Basic Salary     : "); scanf("%ld", &ed.basic_salary);
	printf("Bonus            : "); scanf("%ld", &ed.bonus);
        
        do{	
		printf("Password         : "); 
		SetStdinEcho(0);
		read_string(ed.emp_password, MAX_PW,0);
		SetStdinEcho(1);
                printf("\n");
		printf("Confirm Password : "); 
		SetStdinEcho(0);
		read_string(confirm_pw, MAX_PW,0);
		SetStdinEcho(1);
                printf("\n");

		if(strcmp (ed.emp_password, confirm_pw) != 0)
		{
			printf("Password and Confirm Password not matching.. Try Again..\n\n");
		}

	}while (strcmp (ed.emp_password, confirm_pw) != 0);

	encrypt_password(confirm_pw, ed.emp_password);
	
        //Write data into the file
        fwrite (&ed, sizeof(employee_details_t), 1, fp);
	
	printf("\n\n");
	printf("Add New? [Y|N] "); ch = read_char();
	printf("\n\n");
	}while(ch == 'Y');
	
        printf("Employee Record(s) has been added successfully.\n");
	fclose(fp);
	
	write_sequence_file();
	pause_on_keypress();

}

int modify_employee()
{

	char ch;
	int found = 0;
	employee_details_t ed;
	employee_details_t ted;
	char empid[MAX_ID];
	
        FILE *fp;
        
	fp = fopen ("./datafile/Employee-Details.DAT", "r+");
        if (fp == NULL) {
                printf("\nError opened file\n");
                exit (1);
        }


	printf("[Modify Record]\n");
	printf("Employee ID      : "); read_string(ted.emp_id, MAX_ID,0);

	fseek(fp, 0, SEEK_SET);
	while(fread(&ed, sizeof(employee_details_t), 1, fp))
	{
		if(strcmp(ted.emp_id, ed.emp_id) == 0 )
		{
			found = 1;
			break;
		}
		
	}
	
	if(found)
	{

		printf("Employee Name    : "); read_string(ted.emp_name, MAX_NAME,1);
		printf("Status           : "); ted.emp_status = read_char();
		printf("Gender           : "); ted.gender = read_char();
		printf("Basic Salary     : "); scanf("%ld", &ted.basic_salary);
		printf("Bonus            : "); scanf("%ld", &ted.bonus);

		fseek(fp, -1 * sizeof(employee_details_t), SEEK_CUR);

		//Write data into the file
		fwrite (&ted, sizeof(employee_details_t), 1, fp);

		printf("\n\n");

		printf("Employee Record has been modified successfully.\n");
	}
	else
	{
		printf("No Employee Record Found\n");
	}
	
	fclose(fp);
	
	//write_sequence_file();
	pause_on_keypress();
}

int delete_employee()
{

	char ch;
	int found = 0;
	employee_details_t ed;
	employee_details_t ted;
	char empid[MAX_ID];
	
        FILE *fp, *fpt;
        
	fp = fopen ("./datafile/Employee-Details.DAT", "r+");
        if (fp == NULL) {
                printf("\nError opened file\n");
                exit (1);
        }

	fpt = fopen ("./datafile/Employee-Details.TMP", "w");
        if (fp == NULL) {
                printf("\nError opening temp file\n");
                exit (1);
        }

	printf("[Delete Record]\n");
	printf("Employee ID      : "); read_string(ted.emp_id, MAX_ID,0);

	fseek(fp, 0, SEEK_SET);
	while(fread(&ed, sizeof(employee_details_t), 1, fp))
	{
		if(strcmp(ted.emp_id, ed.emp_id) != 0 )
		{
			fwrite (&ed, sizeof(employee_details_t), 1, fpt);
		}
		
	}

	
	printf("\n\n");
	printf("Employee Record has been modified successfully.\n");
	
	fclose(fpt);
	fclose(fp);
        
	remove("./datafile/Employee-Details.DAT");
        rename("./datafile/Employee-Details.TMP", "./datafile/Employee-Details.DAT");	
	
	//write_sequence_file();
	pause_on_keypress();
}

int view_all_employees()
{
	FILE *fp;
	employee_details_t ed;

	fp = fopen ("./datafile/Employee-Details.DAT", "r");
	if (fp == NULL) {
		printf("\nError opened file\n");
		exit (1);
	}
        
 	printf ("All Employee Details...\n\n");
 	printf ("Employee ID    Employee Name                               Status    Gender    Basic Salary                  Bonus\n");
	printf ("===========    ========================================    ======    ======    =========================     =========================\n");


        fseek(fp, 0, SEEK_SET);      	
	while(fread(&ed, sizeof(employee_details_t), 1, fp))
	{	
		printf ("%11s    %-40s    %6c    %6c    %25ld    %25ld\n", ed.emp_id, ed.emp_name, ed.emp_status, ed.gender, ed.basic_salary, ed.bonus);
	}

	fclose (fp);
	pause_on_keypress();
}

int add_project()
{
        FILE *fp;
        char ch;	
        project_details_t pd;
	
	fp = fopen ("./datafile/Project-Details.DAT", "a");
        if (fp == NULL) {
                printf("\nError opened file\n");
                exit (1);
        }

        do
	{
		generate_proj_id(pd.proj_id);
		printf("[New Record]\n");
		//printf("Project ID      : %s\n", g_nxt_projid_seq_str);
		printf("Project ID      : %s\n", pd.proj_id);
		printf("Project Name   : "); read_string(pd.project_name, MAX_NAME,1);
		printf("Enter project start date:\n");
		printf("Enter day:FORMAT: DD  : "); scanf("%u", &pd.start_date.day);
		printf("Enter month:FORMAT: MM  : "); scanf("%u", &pd.start_date.month);
		printf("Enter year:FORMAT: YYYY  : "); scanf("%u", &pd.start_date.year);
		printf("Enter project end date:\n");
		printf("Enter day:FORMAT: DD  : "); scanf("%u", &pd.end_date.day);
		printf("Enter month:FORMAT: MM  : "); scanf("%u", &pd.end_date.month);
		printf("Enter year:FORMAT: YYYY  : "); scanf("%u", &pd.end_date.year);
		printf("Number of resources required : "); scanf("%u", &pd.no_res_required);
		printf("Number of resources alloted : "); scanf("%u", &pd.no_res_alloted);
	
		//Write data into the file
		fwrite (&pd, sizeof(project_details_t), 1, fp);

		printf("\n\n");
		printf("Add New? [Y|N] "); ch = read_char();
		printf("\n\n");

	}while(ch == 'Y');
        
        printf("Project Record(s) has been added successfully.\n");

        fclose(fp);
	write_sequence_file();
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
	FILE *fp1;
	fp1 = fopen ("./datafile/Project-Details.DAT", "r");
	if (fp1 == NULL) {
		printf("\nError opened file\n");
		exit (1);
	}
	project_details_t pd1;
	printf ("proj_id|proj_name|start_date|res_reqired|res_allocated|\n");
	
	while(fread(&pd1, sizeof(project_details_t), 1, fp1))
		printf ("%s|%s|%u-%u-%u|%u-%u-%u|%u|%u|\n", pd1.proj_id, pd1.project_name,pd1.start_date.day,pd1.start_date.month,pd1.start_date.year,pd1.end_date.day, pd1.end_date.month, pd1.end_date.year, pd1.no_res_required,pd1.no_res_alloted);
	
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
	sprintf(empid,"%c%d",'E',g_nxt_empid_seq);
	g_nxt_empid_seq++;
        return 0;

}


int generate_proj_id(char *projid) //p1111111
{
	sprintf(projid,"%c%d",'P',g_nxt_projid_seq);
	g_nxt_projid_seq++;
	return 0;
}

int load_sequence_file()
{

        FILE *fp;
	fp = fopen ("./datafile/Sequence.dat", "r");
	if (fp == NULL) {
		g_nxt_empid_seq=g_nxt_projid_seq=1111111;
        }
	else
	{
		rewind(fp);
		memset(g_nxt_empid_seq_str,'\0',sizeof(g_nxt_empid_seq_str));
		memset(g_nxt_projid_seq_str,'\0',sizeof(g_nxt_projid_seq_str));
		fscanf(fp,"%s %s",g_nxt_empid_seq_str,g_nxt_projid_seq_str);
		g_nxt_empid_seq = atoi(g_nxt_empid_seq_str);
		g_nxt_projid_seq = atoi (g_nxt_projid_seq_str);
		printf("%d , %d", g_nxt_empid_seq, g_nxt_projid_seq);
		fclose(fp);

	}
	return 0;

}

int write_sequence_file()
{

        FILE *fp;
	fp = fopen ("./datafile/Sequence.dat", "w");
	if (fp == NULL) {
                printf("\nError Opening file\n");
                exit (1);
        }
	else
	{
		fprintf(fp,"%d,%d",g_nxt_empid_seq,g_nxt_projid_seq);
		fclose(fp);
	}
	return 0;

}


