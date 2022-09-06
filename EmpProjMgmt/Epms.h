//EmpProjMgmt.h


#ifndef _EMPPROJMGMT_H
#define _EMPPROJMGMT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MAX_PROJECT 3
#define MAX_NAME 50
#define MAX_ID 10
#define MAX_PW 20

#define ADMIN_ID "admin"
#define ADMIN_PW "admin"

#define SUCCESS 0
#define USER_EXIT 1000
#define USER_LOGOUT 1001
#define INVALID_CREDENTIAL 1002


//enum boolean {true=1, false=0};
typedef enum usertype 
{
	ADMIN=1, 
	EMPLOYEE=2
}usertype_t;

//structures

typedef struct date
{
	unsigned int day;
	unsigned int month;
	unsigned int year;

}date_t;


typedef struct project_details
{
	unsigned int project_id;  //The project id is auto generated. 
	char project_name[MAX_NAME]; 
	date_t start_date; 
	date_t end_date; //The end date should be atleast one month after the start date.
	unsigned int no_res_required; 
	unsigned int no_res_alloted; 
	char project_status; //default active, it will be set as "closed" manually, Resources cannot be allocated to closed projects

}project_details_t;

typedef struct employee_details
{
	unsigned char emp_id[MAX_ID]; //auto generated
	char emp_name[MAX_NAME]; 
	char emp_password[MAX_PW]; 
	char emp_status; //Fully allocated , partially allocated, not allocated
	char gender; 
	unsigned long int basic_salary; 
	unsigned long int bonus;
	project_details_t projects_assigned[MAX_PROJECT];  //define as array, max 3 projects can be allocated for an employee

}employee_details_t;

typedef struct allocation_info
{
	unsigned char project_id[MAX_ID]; 
	date_t allocation_start_date; 
	date_t allocation_end_date; 
	char role[MAX_NAME]; 
	unsigned int percent_allocated;
 
}allocation_info_t;

//int login();
int read_password();
void SetStdinEcho(int enable);
int encrypt_password(char *pwstr, char *encryptedpwstr);
int decrypt_password(char *encryptedpwstr, char *pwstr);
int proc_emp_login();
int proc_admin_login();
int show_app_title();
int validate_user(char* logon_user, char* logon_password, usertype_t user);	
int read_user_credential();


int add_employee();
int add_project();
int delete_employee();
int delete_project();
int allocate_project();
int logout_admin_user();
int view_all_employees();
int view_all_projects();
int generate_emp_id(char* empid); //e1111111
int generate_proj_id(char* empid); //p1111111
int view_personal_details();
int view_projects_details();
int logout_emp_user();	
char pause_on_keypress();
char read_char();
int read_string(char* str, int length);
char *ltrim(char *s);
char *rtrim(char *s);
char *trim(char *s);

#endif //_EMPPROJMGMT_H


