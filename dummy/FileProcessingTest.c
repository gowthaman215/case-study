/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdlib.h>
#include <stdio.h>

struct Person 
{
    char f_name[256];
    char l_name[256];
    int age;
};

int people_count;

int write_datafile()
{
    struct Person* people;
    

    printf("How many people would you like to create: ");
    scanf("%i", &people_count);
    people = (Person*) malloc(sizeof(struct Person) * people_count);  

    int n;
    for (n = 0; n < people_count; n++)
    {
        printf("Person %i's First Name: ", n);
        scanf("%s", people[n].f_name);

        printf("Person %i's Last Name: ", n);
        scanf("%s", people[n].l_name);

        printf("Person %i's Age: ", n);
        scanf("%i", &people[n].age);
    }

    FILE* data;
    if ( (data = fopen("datafile\\data.bin", "wb")) == NULL )
    {
        printf("Error opening file\n");
        return 1;   
    }

    fwrite(people, sizeof(struct Person) * people_count, 1, data);
    fclose(data);

    return 0;
}


int load_datafile()
{
    FILE* data;
    if ((data = fopen("datafile\\data.bin", "rb")) == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    struct Person* people;

    fread(people, sizeof(struct Person) * 1/* Just read one person */, 1, data);
    
    for (int i=0; i<people_count; i++)
    {
        printf("%s\n", people[0].f_name);
        printf("%s\n", people[0].l_name);
        printf("%d\n", people[0].age);
    }
    fclose(data);

    return 0;
}

int main()
{
    write_datafile();
    load_datafile();
    return 0;
}

