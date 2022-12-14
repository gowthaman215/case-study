#include "Epms.h"

// this is for file processing

int add_admin()
{
	char admin_id[MAX_ID];
	char admin_pw[MAX_PW];
	char confirm_pw[MAX_PW];
        FILE *fp;
	/*
        
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
	printf("Admin user created\n");*/
	printf("\t\t\t\t\tUnder development\n");
	pause_on_keypress();

}

int view_admin()
{

	FILE *fp;
	char admin_id[MAX_ID];
	char admin_pw[MAX_PW];
	/*

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

	fclose (fp);*/
	printf("\t\t\t\t\tUnder development\n");
	pause_on_keypress();
}

int delete_admin()
{
	char ch;
	int found = 0;
	char admin_id[MAX_ID];
	char line[20];
	char admin_pw[MAX_PW];
	
    /*    FILE *fp, *fpt;
        
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
	
	//write_sequence_file();*/
	printf("\t\t\t\t\tUnder development\n");
	pause_on_keypress();
}

int add_employee()
{
	char ch, c, cr;
	int char_flag = 0;
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

	printf("\t\t\t\t\t[New Record]\n");
	printf("\t\t\t\t\tEmployee ID      : %s\n", ed.emp_id);
	printf("\t\t\t\t\tEmployee Name    : ");
	read_string(ed.emp_name, MAX_NAME,1);
	ed.emp_status = 'U'; //F - Fully Allocated, P - Partly Allocated , U - Unallocated
	do {
		char_flag = 0;
	printf("\t\t\t\t\tGender[M/F]       : ");
	ed.gender = toupper(read_char());
	while((c = getchar()) != '\n' && c != EOF)
	{
		char_flag = 1;
	}
	if ((char_flag != 0) || !(ed.gender == 'M' || ed.gender == 'm' ||  ed.gender == 'F' ||  ed.gender == 'f' ))
	{
		printf("\t\t\t\t\tEnter valid gender\n");
	}
	} while ((char_flag != 0) || !(ed.gender == 'M' || ed.gender == 'm' ||  ed.gender == 'F' ||  ed.gender == 'f' ));
	do {	
		char_flag = 0;
	printf("\t\t\t\t\tBasic Salary     : ");
	scanf("%ld", &ed.basic_salary);
	while((c = getchar()) != '\n' && c != EOF)
	{
		char_flag = 1;
	}
	if (char_flag == 1)
	{
		printf("\t\t\t\t\tEnter valid salary\n");
	}
	} while(char_flag != 0);
	do {
		char_flag = 0;
	printf("\t\t\t\t\tBonus            : ");
	scanf("%ld", &ed.bonus);
	while((c = getchar()) != '\n' && c != EOF)
	{
		char_flag = 1;
	}
	if (char_flag == 1)
	{
		printf("\t\t\t\t\tEnter valid bonus\n");
	}
	} while (char_flag != 0);
	//while((c = getchar()) != '\n' && c != EOF);
        
        do{	
		printf("\t\t\t\t\tPassword         :"); 
		SetStdinEcho(0);
		read_string(ed.emp_password, MAX_PW, 0);
		SetStdinEcho(1);
                printf("\n");
		printf("\t\t\t\t\tConfirm Password : "); 
		SetStdinEcho(0);
		read_string(confirm_pw, MAX_PW,0);
		SetStdinEcho(1);
                printf("\n");

		if(strcmp (ed.emp_password, confirm_pw) != 0)
		{
			printf("\t\t\t\t\tPassword and Confirm Password not matching.. Try Again..\n\n");
		}

	}while (strcmp (ed.emp_password, confirm_pw) != 0);

	encrypt_password(confirm_pw, ed.emp_password);
	
        //Write data into the file
        fwrite (&ed, sizeof(employee_details_t), 1, fp);
	
	printf("\n\n");
	printf("\t\t\t\t\tAdd New? [Y|N] ");
	ch = read_char();
	printf("\n\n");
	while((c = getchar()) != '\n' && c != EOF);
	}while((ch == 'Y') || (ch == 'y'));
	
        printf("\t\t\t\t\tEmployee Record(s) has been added successfully.\n");
	fclose(fp);
	
	write_sequence_file();
	pause_on_keypress();

}

int modify_employee()
{

	char ch, c, cr;
	int char_flag = 0;
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


	printf("\t\t\t\t\t[Modify Record]\n");
	printf("\t\t\t\t\tEmployee ID      : "); read_string(ted.emp_id, MAX_ID,0);

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

		printf("\t\t\t\t\tEmployee Name    : "); read_string(ted.emp_name, MAX_NAME,1);
		do {
			char_flag = 0;
			printf("\t\t\t\t\tStatus[F/P/U]      : "); ted.emp_status = read_char();
			while((c = getchar()) != '\n' && c != EOF)
			{
				char_flag = 1;
			}
			if ((char_flag != 0) || !(ted.emp_status == 'F' || ted.emp_status == 'f' ||  ted.emp_status == 'P' || ted.emp_status == 'p'  || ted.emp_status == 'U' ||  ted.emp_status == 'u' ))
			{
				printf("\t\t\t\t\tEnter valid employee status\n");
			}
		} while ((char_flag != 0) || !(ted.emp_status == 'F' || ted.emp_status == 'f' ||  ted.emp_status == 'P' ||  ted.emp_status == 'p'  || ted.emp_status == 'U' ||  ted.emp_status == 'u' ));
		do {
			char_flag = 0;
			printf("\t\t\t\t\tGender[M/F]       : ");
			ted.gender = toupper(read_char());
			while((c = getchar()) != '\n' && c != EOF)
			{
				char_flag = 1;
			}
			if ((char_flag != 0) || !(ted.gender == 'M' || ted.gender == 'm' || ted.gender == 'F' ||  ted.gender == 'f' ))
			{
				printf("\t\t\t\t\tEnter valid gender\n");
			}
	} while ((char_flag != 0) || !(ted.gender == 'M' || ted.gender == 'm' ||  ted.gender == 'F' ||  ted.gender == 'f' ));
	do {	
		char_flag = 0;
	printf("\t\t\t\t\tBasic Salary     : ");
	scanf("%ld", &ted.basic_salary);
	while((c = getchar()) != '\n' && c != EOF)
	{
		char_flag = 1;
	}
	if (char_flag == 1)
	{
		printf("\t\t\t\t\tEnter valid salary\n");
	}
	} while(char_flag != 0);
	do {
		char_flag = 0;
	printf("\t\t\t\t\tBonus            : ");
	scanf("%ld", &ted.bonus);
	while((c = getchar()) != '\n' && c != EOF)
	{
		char_flag = 1;
	}
	if (char_flag == 1)
	{
		printf("\t\t\t\t\tEnter valid bonus\n");
	}
	} while (char_flag != 0);

		fseek(fp, -1 * sizeof(employee_details_t), SEEK_CUR);

		//Write data into the file
		fwrite (&ted, sizeof(employee_details_t), 1, fp);

		printf("\n\n");

		printf("\t\t\t\t\tEmployee Record has been modified successfully.\n");
	}
	else
	{
		printf("\t\t\t\t\tNo Employee Record Found\n");
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

	printf("\t\t\t\t\t[Delete Record]\n");
	printf("\t\t\t\t\tEmployee ID      : "); read_string(ted.emp_id, MAX_ID,0);

	fseek(fp, 0, SEEK_SET);
	while(fread(&ed, sizeof(employee_details_t), 1, fp))
	{
		if(strcmp(ted.emp_id, ed.emp_id) != 0 )
		{
			fwrite (&ed, sizeof(employee_details_t), 1, fpt);
		} else {
			found = 1;
		}
		
	}

	
	printf("\n\n");
	if (found) {
	printf("\t\t\t\t\tEmployee Record has been deleted successfully.\n");
	} else {
	printf("\t\t\t\t\tEmployee Record not found\n");
	}
	
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
 	printf ("Employee ID    Employee Name                        Status    Gender    Basic Salary            Bonus\n");
	printf ("===========    =================================    ======    ======    =================    ===========\n");


        fseek(fp, 0, SEEK_SET);      	
	while(fread(&ed, sizeof(employee_details_t), 1, fp))
	{	
		printf ("%-11s    %-33s    %-6c    %-6c    %-17ld    %-12ld\n", ed.emp_id, ed.emp_name, ed.emp_status, ed.gender, ed.basic_salary, ed.bonus);
	}

	fclose (fp);
	pause_on_keypress();
}
int isleap(int y) {
	if ((y % 4 == 0) && (y % 100 != 0) && (y % 400 == 0)) {
		return 1;
	} else {
		return 0;
	}
}

int countLeapYears(date_t d)
{
	int years = d.year;
	if (d.month <= 2) {
		years--;
	}
	return years / 4
           - years / 100
           + years / 400;
}

int getDifference(date_t dt1, date_t dt2)
{
	const int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	long int n1 = dt1.year * 365 + dt1.day;
	for (int i = 0; i < dt1.month - 1; i++) {
		n1 += monthDays[i];
	}
	n1 += countLeapYears(dt1);
	long int n2 = dt2.year * 365 + dt2.day;
	for (int i = 0; i < dt2.month - 1; i++)
		n2 += monthDays[i];
		n2 += countLeapYears(dt2);
	return (n2 - n1);
}
int datevalid(int d, int m, int y) {
//	printf("Day:%d, Month:%d, Year:%d\n", d, m, y);
   if(y < min_yr || y > max_yr)
      return 0;
   if(m < 1 || m > 12)
      return 0;
   if(d < 1 || d > 31)
      return 0;
      //Now we will check date according to month
   if( m == 2 ) {
      if(isleap(y)) {
         if(d <= 29)
            return 1;
         else
            return 0;
         }
      }
      //April, June, September and November are with 30 days
      if ( m == 4 || m == 6 || m == 9 || m == 11 )
         if(d <= 30)
            return 1;
         else
            return 0;
            return 1;
   }
int add_project()
{
	FILE *fp;
	char ch, c, cr;
	int date_val, dv;
	int diff = 0;
	int char_flag = 0;
	project_details_t pd;
	fp = fopen ("./datafile/Project-Details.DAT", "a");
        if (fp == NULL) {
                printf("\nError opened file\n");
                exit (1);
        }

        do
	{
		generate_proj_id(pd.proj_id);
		printf("\t\t\t\t\t[New Record]\n");
		printf("\t\t\t\t\tProject ID      : %s\n", pd.proj_id);
		printf("\t\t\t\t\tProject Name   : ");
		read_string(pd.project_name, MAX_NAME,1);

		do {
			char_flag = 0;
			printf("\t\t\t\t\tEnter project start date (DD/MM/YYYY format):\n");
			printf("\t\t\t\t\t");
			dv = scanf("%u/%u/%u", &pd.start_date.day, &pd.start_date.month, &pd.start_date.year);
			while((c = getchar()) != '\n' && c != EOF)
			{
				char_flag = 1;
			}

			if (dv == 3) {
				date_val = datevalid(pd.start_date.day, pd.start_date.month, pd.start_date.year);
			} else {
				date_val = 0;
			}

			if ( (!date_val) || (dv != 3) || (char_flag != 0) )
			{
				printf("\t\t\t\t\tStart date is not valid\n");
			}

		} while ((!date_val) || (dv != 3) || (char_flag != 0));

		do {
			char_flag = 0;
			printf("\t\t\t\t\tEnter project end date (DD/MM/YYYY format):\n");
			printf("\t\t\t\t\t");
			dv = scanf("%u/%u/%u", &pd.end_date.day, &pd.end_date.month, &pd.end_date.year);
			while((cr = getchar()) != '\n' && cr != EOF)
			{
				char_flag = 1;

			}
			if (dv == 3) {
				date_val = datevalid(pd.end_date.day, pd.end_date.month, pd.end_date.year);
				diff = getDifference(pd.start_date, pd.end_date);
			} else {
				date_val = 0;
			}

			if ( (!date_val) || (dv != 3) || (char_flag != 0) )
			{
				printf("\t\t\t\t\tEnd date is not valid\n");
			} else if (diff < 30) {
				printf("\t\t\t\t\tEnd date should be after 30 days\n");
			}
		} while ((!date_val) || (dv != 3) || (char_flag != 0) || (diff < 30));
		printf("\t\t\t\t\tNumber of resources required :\n");
		printf("\t\t\t\t\t");
		scanf("%u", &pd.no_res_required);
		do {
			printf("\t\t\t\t\tNumber of resources alloted : \n");
			printf("\t\t\t\t\t");
			scanf("%u", &pd.no_res_alloted);
			if (pd.no_res_alloted > pd.no_res_required)
			{
				printf("\t\t\t\t\tno_res_alloted should be less than or equal to no_res_required\n");
			}
		} while(pd.no_res_alloted > pd.no_res_required);
		
		//Write data into the file
		fwrite (&pd, sizeof(project_details_t), 1, fp);

		printf("\n\n");
		printf("\t\t\t\t\t");
		printf("Add New? [Y|N] \n");
		printf("\t\t\t\t\t");
		ch = read_char();
		printf("\n\n");

	}while((ch == 'Y') || (ch == 'y'));
        
        printf("\t\t\t\t\tProject Record(s) added successfully.\n");

        fclose(fp);
	write_sequence_file();
        pause_on_keypress();
}

int modify_project()
{
	int found = 0;
	char ch, c, cr;
	int date_val, dv;
	int diff = 0;
	int char_flag = 0;
        project_details_t pd;
        project_details_t ted;


        FILE *fp;

        fp = fopen ("./datafile/Project-Details.DAT", "r+");
        if (fp == NULL) {
                printf("\nError opened file\n");
                exit (1);
        }

        printf("\t\t\t\t\t[Modify Record]\n");
        printf("\t\t\t\t\tProject ID      : "); read_string(ted.proj_id, MAX_ID,0);

        fseek(fp, 0, SEEK_SET);
        while(fread(&pd, sizeof(project_details_t), 1, fp))
        {
                if(strcmp(ted.proj_id, pd.proj_id) == 0 )
                {
                        found = 1;
                        break;
                }

        }

        if(found)
        {

		printf("\t\t\t\t\tProject Name   : "); read_string(ted.project_name, MAX_NAME,1);
		do {
			char_flag = 0;
			printf("\t\t\t\t\tEnter project start date (DD/MM/YYYY format):\n");
			printf("\t\t\t\t\t");
			dv = scanf("%u/%u/%u", &ted.start_date.day, &ted.start_date.month, &ted.start_date.year);
			while((c = getchar()) != '\n' && c != EOF)
			{
				char_flag = 1;
			}

			if (dv == 3) {
				date_val = datevalid(ted.start_date.day, ted.start_date.month, ted.start_date.year);
			} else {
				date_val = 0;
			}

			if ( (!date_val) || (dv != 3) || (char_flag != 0) )
			{
				printf("\t\t\t\t\tStart date is not valid\n");
			}

		} while ((!date_val) || (dv != 3) || (char_flag != 0));
		do {
			char_flag = 0;
			printf("\t\t\t\t\tEnter project end date (DD/MM/YYYY format):\n");
			printf("\t\t\t\t\t");
			dv = scanf("%u/%u/%u", &ted.end_date.day, &ted.end_date.month, &ted.end_date.year);
			while((cr = getchar()) != '\n' && cr != EOF)
			{
				char_flag = 1;

			}
			if (dv == 3) {
				date_val = datevalid(ted.end_date.day, ted.end_date.month, ted.end_date.year);
				diff = getDifference(ted.start_date, ted.end_date);
			} else {
				date_val = 0;
			}

			if ( (!date_val) || (dv != 3) || (char_flag != 0) )
			{
				printf("\t\t\t\t\tEnd date is not valid\n");
			} else if (diff < 30) {
				printf("\t\t\t\t\tEnd date should be after 30 days\n");
			}
		} while ((!date_val) || (dv != 3) || (char_flag != 0) || (diff < 30));
		printf("\t\t\t\t\tNumber of resources required :\n");
		printf("\t\t\t\t\t");
		scanf("%u", &ted.no_res_required);
		do {
			printf("\t\t\t\t\tNumber of resources alloted : \n");
			printf("\t\t\t\t\t");
			scanf("%u", &ted.no_res_alloted);
			if (ted.no_res_alloted > ted.no_res_required)
			{
				printf("\t\t\t\t\tno_res_alloted should be less than or equal to no_res_required\n");
			}
		} while(ted.no_res_alloted > ted.no_res_required);

                fseek(fp, -1 * sizeof(project_details_t), SEEK_CUR);

                //Write data into the file
                fwrite (&ted, sizeof(project_details_t), 1, fp);

                printf("\n\n");

                printf("\t\t\t\t\tProject details updated successfully.\n");
        }
        else
        {
                printf("\t\t\t\t\tNo Project Record Found\n");
        }

        fclose(fp);

        //write_sequence_file();
        pause_on_keypress();
}

int delete_project()
{
	char ch;
        int found = 0;
        project_details_t pd;
        project_details_t ted;
        char empid[MAX_ID];

        FILE *fp, *fpt;

        fp = fopen ("./datafile/Project-Details.DAT", "r+");
        if (fp == NULL) {
                printf("\nError opened file\n");
                exit (1);
        }

        fpt = fopen ("./datafile/Project-Details.TMP", "w");
        if (fp == NULL) {
                printf("\nError opening temp file\n");
                exit (1);
        }

        printf("\t\t\t\t\t[Delete Record]\n");
        printf("\t\t\t\t\tProject ID      : "); read_string(ted.proj_id, MAX_ID,0);

        fseek(fp, 0, SEEK_SET);
        while(fread(&pd, sizeof(project_details_t), 1, fp))
        {
                if(strcmp(ted.proj_id, pd.proj_id) != 0 )
                {
                        fwrite (&pd, sizeof(project_details_t), 1, fpt);
                } else {
			found = 1;

		}

        }


        printf("\n\n");
	if (found) {
		printf("\t\t\t\t\tProject deleted successfully.\n");
	} else {
                printf("\t\t\t\t\tNo project record found.\n");
	}

        fclose(fpt);
        fclose(fp);

        remove("./datafile/Project-Details.DAT");
        rename("./datafile/Project-Details.TMP", "./datafile/Project-Details.DAT");

        write_sequence_file();
        pause_on_keypress();
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

 	printf ("All Project Details...\n\n");
 	printf ("Project ID    Project Name                    Start Date    End Date    Resource Req    Resource Alloc\n");
	printf ("===========   ============================    ==========    =========   ============    ===============\n");
	
	while(fread(&pd1, sizeof(project_details_t), 1, fp1))
		printf ("%-11s   %-28s    %-2u-%-2u-%-2u    %-2u-%-2u-%-2u   %-12u    %-15u\n", pd1.proj_id, pd1.project_name,pd1.start_date.day,pd1.start_date.month,pd1.start_date.year,pd1.end_date.day, pd1.end_date.month, pd1.end_date.year, pd1.no_res_required,pd1.no_res_alloted);
	
	fclose (fp1);
	pause_on_keypress();
}

int allocate_project()
{
	printf("\t\t\t\t\tUnder development\n");
	pause_on_keypress();
}

int deallocate_project()
{
	printf("\t\t\t\t\tUnder development\n");
	pause_on_keypress();
}

int change_password()
{
	printf("\t\t\t\t\tUnder development\n");
	pause_on_keypress();

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
		g_nxt_empid_seq = 1111111;
		g_nxt_projid_seq = 1111111;
        } else {
		rewind(fp);
		memset(g_nxt_empid_seq_str,'\0',sizeof(g_nxt_empid_seq_str));
		memset(g_nxt_projid_seq_str,'\0',sizeof(g_nxt_projid_seq_str));
		fscanf(fp,"%s %s", g_nxt_empid_seq_str, g_nxt_projid_seq_str);
		g_nxt_empid_seq = atoi(g_nxt_empid_seq_str);
		g_nxt_projid_seq = atoi(g_nxt_projid_seq_str);
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
		fprintf(fp,"%d %d",g_nxt_empid_seq,g_nxt_projid_seq);
		fclose(fp);
	}
	return 0;

}


