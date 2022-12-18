#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// Structure of the employee
struct emp {
    char name[50];
    float salary;
    int phnno;
    int id;
    char emailid[100];
};
struct emp e;
  
long int size = sizeof(e);
  
// In the start coordinates
// will be 0, 0
COORD cord = { 0, 0 };
  
// function to set the
// coordinates
void gotoxy(int x, int y)
{
    cord.X = x;
    cord.Y = y;
    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE),
        cord);
}

FILE *fp, *ft;

// Function to add the records
void addrecord()
{
    system("cls");
    fseek(fp, 0, SEEK_END);
    char another = 'y';
  
    while (another == 'y') {
        printf("\nEnter Name : ");
        scanf("%s", &e.name);
        
        printf("\nEnter EMP-ID : ");
        scanf("%d", &e.id);

        printf("\nEnter Phone number : ");
        scanf("%d", &e.phnno);
        
        printf("\nEnter Email-ID : ");
        scanf("%s", &e.emailid);

        printf("\nEnter Salary : ");
        scanf("%f", &e.salary);
  
        fwrite(&e, size, 1, fp);
  
        printf("\nWant to add another"
               " record (Y/N) : ");
        fflush(stdin);
  
        
        another = getche();
    }
}
  
// Function to display the record
void displayrecord()
{
    
    system("cls");
    char empname[50];
    char another = 'y';
  
    while (another == 'y') {
        printf("\nEnter employee name"
               " to display record : ");
        scanf("%s", empname);
  
        rewind(fp);
  
        // While File is open
        while (fread(&e, size, 1, fp) == 1) {
            // Compare the employee name
            // with ename
            if (strcmp(e.name, empname) == 0) {
                printf("\n========================="
                    "==========================="
                    "=================================");
                printf("\nNAME\t\tEMP-ID\t\tPHONE NUMBER\t\tEMAIL ID\t\tSALARY\n", e.name, e.id, e.phnno, e.emailid, e.salary);
                printf("==========================="
                    "==========================="
                    "==============================\n");
            
                    printf("\n%s\t\t%d\t\t%.d\t\t%s\t\t%f", e.name, e.id, e.phnno, e.emailid, e.salary);
                printf("\n\n");
            }
        }
        printf("\nWant to display another"
               " record (Y/N) :");
        fflush(stdin);
        
        another = getche();
    }
}

// Function to show sum of salary
void sum(){
    system("cls");
    float s=0;
    // sets pointer to start
    // of the file
    rewind(fp);
    printf(e.name, e.id, e.phnno, e.emailid, e.salary);
    while (fread(&e, size, 1, fp) == 1){
        s=s+e.salary;
    }
    printf("%f", s);
    printf("\n\n\n\t");
    system("pause");
}

// Function to display all the records
void displayallrecord()
{
    system("cls");
  
    // sets pointer to start
    // of the file
    rewind(fp);
  
    printf("\n========================="
           "==========================="
           "======");
    printf("\nNAME\t\tEMP-ID\t\tPHONE NUMBER\t\tEMAIL ID\t\tSALARY\n",e.name, e.id, e.phnno, e.emailid, e.salary);
    printf("==========================="
           "==========================="
           "====\n");
  
    while (fread(&e, size, 1, fp) == 1)
        printf("\n%s\t\t%d\t\t%.d\t\t%s\t\t%f",
               e.name, e.id, e.phnno, e.emailid, e.salary);
  
    printf("\n\n\n\t");
    system("pause");
}

// Function to delete the records of individual
void deleterecord()
{
    system("cls");
    char empname[50];
    char another = 'y';
  
    while (another == 'y') {
        printf("\nEnter employee "
               "name to delete : ");
        scanf("%s", empname);
  
        ft = fopen("temp.txt", "wb");
        rewind(fp);
  
        while (fread(&e, size,
                     1, fp)
               == 1) {
            if (strcmp(e.name,
                       empname)
                != 0)
                fwrite(&e, size, 1, ft);
        }
  
        fclose(fp);
        fclose(ft);
        remove("data.txt");
        rename("temp.txt", "data.txt");
        fp = fopen("data.txt", "rb+");
  
        printf("\nWant to delete another"
               " record (Y/N) :");
        fflush(stdin);
        another = getche();
    }
}
  
// Driver code
int main()
{
    int choice;
  
    // opening the file
    fp = fopen("data.txt", "rb+");
  
    // showing error if file is
    // unable to open.
    if (fp == NULL) {
        fp = fopen("data.txt", "wb+");
        if (fp == NULL) {
            printf("\nCannot open file...");
            exit(1);
        }
    }
  
    system("Color 5C");
    printf("\n\n\n\n\t\t\t\t============="
           "============================="
           "===========");
    printf("\n\t\t\t\t~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~");
    printf("\n\t\t\t\t==================="
           "============================="
           "=====");
    printf("\n\t\t\t\t[|:::>:::>:::>::>  "
           "EMPLOYEE RECORD  <::<:::<:::"
           "<:::|]\t");
    printf("\n\t\t\t\t==================="
           "============================="
           "=====");
    printf("\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~");
    printf("\n\t\t\t\t====================="
           "==============================\n");
    printf("\n\n\n\t\t\t\t\t\t\t\t\t\t"
           "Developer : @Kavya_Dangi"
           "\n\n\t\t\t\t");
  
    system("pause");
  
    while (1) {
        // Clearing console and asking the
        // user for input
        system("cls");
        gotoxy(30, 10);
        printf("\n1. ADD RECORD\n");
        gotoxy(30, 12);
        printf("\n2. SUM OF SALARY\n");
        gotoxy(30, 14);
        printf("\n3. DISPLAY THE RECORD OF AN INDIVIDUAL\n");
        gotoxy(30, 16);
        printf("\n4. DISPLAY ALL THE RECORDS\n");
        gotoxy(30, 18);
        printf("\n5. DELETE THE RECORD OF AN INDIVIDUAL\n");
        gotoxy(30, 20);
        printf("\n6. EXIT\n");
        gotoxy(30, 22);
        printf("\nENTER YOUR CHOICE...\n");
        fflush(stdin);
        scanf("%d", &choice);
  
        // Switch Case
        switch (choice) {
        case 1:
  
            // Add the records
            addrecord();
            break;
  
        case 2:
  
            // Delete the sum
            sum();
            break;
  
        case 3:
  
            // Display the record of an individual
            displayrecord();
            break;
  
        case 4:
  
            // Display all the records
            displayallrecord();
            break;
  
        case 5:
  
            // Delete the record of an individual
            deleterecord();
            break;

        case 6:
            fclose(fp);
            exit(0);
            break;
  
        default:
            printf("\nINVALID CHOICE...\n");
        }
    }
  
    return 0;
}