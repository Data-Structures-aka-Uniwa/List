#include <stdio.h>
#include "list.h"

int main()
{
    list l;
    initList(&l);

    int choice;
    student s;
    char am[20];
    char name[100];
    int semester;

    do {
        printf("\n1. Insert\n2. Delete\n3. Search AM\n4. Search Name\n");
        printf("5. Modify\n6. Print All\n7. Print by Semester\n0. Exit\n");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            printf("AM: ");
            scanf("%s", s.am);
            printf("Name: ");
            scanf(" %[^\n]", s.name);
            printf("Semester: ");
            scanf("%d", &s.semester);
            insertStudent(&l, s);
            break;

        case 2:
            printf("AM to delete: ");
            scanf("%s", am);
            if (!deleteStudent(&l, am))
                printf("Student not found.\n");
            break;

        case 3:
            printf("AM: ");
            scanf("%s", am);
            if (searchByAM(&l, am))
                printf("Found!\n");
            else
                printf("Not found.\n");
            break;

        case 4:
            printf("Name: ");
            scanf(" %[^\n]", name);
            searchByName(&l, name);
            break;

        case 5:
            printf("AM to modify: ");
            scanf("%s", am);
            modifyStudent(&l, am);
            break;

        case 6:
            printList(&l);
            break;

        case 7:
            printf("Semester: ");
            scanf("%d", &semester);
            printBySemester(&l, semester);
            break;
        }

    } while (choice != 0);

    destroyList(&l);
    return 0;
}