1. Setup Environment 
	Online GDB, 
	Visual Studio Code and c++ plugin - SR to install
	
2. 
Goals of the project are:
The employee-project management system has been designed and developed to manage the
process project details{project id, project name, start date, end date, no of resources required, no
of resources allocated, project status} and employee details{emp id, emp name, emp status,
gender, basic salary, bonus, project details}. In the employee object, the number of projects being
allocated are a maximum of three projects with allocation information{project id, allocation start
date, allocation end date, role, percentage allocated).

In order to add / delete the employee, the administrator has a built-in login id and password set.
There may be any number of administrators. Here, in the employee details entry, the employee id
is auto generated. All employee details should be captured. 

The administrator is allowed to add projects.
The project id is auto generated. 

All project details should be captured. 
The end date should be atleast one month after the start date. 
The administrator is allowed to allocate the projects to the resource(employee). 

Once a resource is allocated to a project, update the count. -- need to check

The project status is by default active. It will be set as "closed" manually. 

Resources cannot be allocated to closed projects. An employee can be allocated to a max of 3 projects. The
sum of allocation percentage of all the projects should be 100. As soon as an employee is
allocated to 3 projects or allocation percentage sum is 100, the employee is marked as allocated.
The employee is given a user id and password. The employee can login and see his/her details
including employment and project

project details
{
project id, - The project id is auto generated. 
project name, 
start date, - 
end date, - The end date should be atleast one month after the start date.
no of resources required, 
no of resources allocated, 
project status - default active, it will be set as "closed" manually, Resources cannot be allocated to closed projects
}

employee details
{
emp id, - auto generated
emp name, 
emp status, - Fully allocated , partially allocated, not allocated
gender, 
basic salary, 
bonus, 
project details - define as array, max 3 projects can be allocated for an employee
}

allocation information
{
project id, 
allocation start date, 
allocation end date, 
role, 
percentage allocated - 
}


User
1. Admin (admin/admin)
2. Employee

1. Admin user activities
1.1 Add Employee
1.2 Delete Employee
1.3 Add Project
1.4 Delete Project
1.5 Allocate Project to Employee
1.6 

2. Employee user Activity
1.1 view personal details
1.2 view employment and project details



Areas to focus

Pointer
structure
FILE IO
dynemic memory allocatio - memory leaks


Layout

Consumer -> product -> delivery

consumable product
- raw product
- 


show_login_option()
read_login_details()


EmpProjMgmt.h
EmpProjLogin.c - all log in functionality
EmpProjMgmtApp.c - 
EmpProjFileProcess.c
EmpProjAppLoader.c






