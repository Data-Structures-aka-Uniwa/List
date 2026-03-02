#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

void initList(list *l)
{
    l->head = NULL;
    l->tail = NULL;
}

int insertStudent(list *l, student s)
{
    if (searchByAM(l, s.am)) {
        printf("Duplicate AM not allowed.\n");
        return 0;
    }

    node *newNode = malloc(sizeof(node));
    if (!newNode) {
        printf("Memory allocation error.\n");
        exit(1);
    }

    newNode->data = s;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (l->head == NULL) {
        l->head = l->tail = newNode;
        return 1;
    }

    node *current = l->head;

    while (current && strcmp(current->data.am, s.am) < 0)
        current = current->next;

    if (current == l->head) {
        newNode->next = l->head;
        l->head->prev = newNode;
        l->head = newNode;
    }
    else if (current == NULL) {
        newNode->prev = l->tail;
        l->tail->next = newNode;
        l->tail = newNode;
    }
    else {
        newNode->next = current;
        newNode->prev = current->prev;
        current->prev->next = newNode;
        current->prev = newNode;
    }

    return 1;
}

node* searchByAM(list *l, char *am)
{
    node *current;
    
    current = l->head;

    while (current)
    {
        if (strcmp(current->data.am, am) == 0)
            return current;
        current = current->next;
    }

    return NULL;
}

void searchByName(list *l, char *name)
{
    node *current;
    int found;

    current = l->head;
    found = 0;

    while (current)
    {
        if (strcmp(current->data.name, name) == 0)
        {
            printf("%s | %s | %d\n", 
                current->data.am,
                current->data.name,
                current->data.semester);
            found = 1;
        }
        current = current->next;
    }

    if (!found)
        printf("No student found.\n");
}

int deleteStudent(list *l, char *am)
{
    node *n;

    n = searchByAM(l, am);
    if (!n)
        return 0;
    
    if (n == l->head)
        l->head = n->next;
    
    if (n == l->tail)
        l->tail = n->prev;
    
    if (n->prev)
        n->prev = n->next;
    
    if (n->next)
        n->next = n->prev;
    
    free(n);

    return 1;
}

void printList(list *l)
{
    node *current;

    current = l->head;

    while (current)
    {
        printf("%s | %s | %d\n",
            current->data.am,
            current->data.name,
            current->data.semester);
        current = current->next;
    }
}

void printBySemester(list *l, int semester)
{
    node *current;

    current = l->head;

    while (current)
    {
        if (current->data.semester == semester)
        {
            printf("%s | %s | %d\n",
                current->data.am,
                current->data.name,
                current->data.semester);
        }
        current = current->next;
    }
}

int modifyStudent(list *l, char *am)
{
    node *n = searchByAM(l, am);
    if (!n) {
        printf("Student not found.\n");
        return 0;
    }

    student temp = n->data;

    printf("New AM: ");
    scanf("%s", temp.am);

    printf("New Name: ");
    scanf(" %[^\n]", temp.name);

    printf("New Semester: ");
    scanf("%d", &temp.semester);

    deleteStudent(l, am);
    insertStudent(l, temp);

    return 1;
}

void destroyList(list *l)
{
    node *current, *temp;

    current = l->head;

    while (current)
    {
        temp = current;
        current = current->next;
        free(temp);
    }

    l->head = l->tail = NULL;
}

