#ifndef LIST_H
#define LIST_H

typedef struct student {
    char am[20];
    char name[100];
    int semester;
} student;

typedef struct node {
    student data;
    struct node *prev;
    struct node *next;
} node;

typedef struct list {
    node *head;
    node *tail;
} list;

void initList(list *l);
int insertStudent(list *l, student s);
node* searchByAM(list *l, char *am);
void searchByName(list *l, char *name);
int deleteStudent(list *l, char *am);
void printList(list *l);
void printBySemester(list *l, int semester);
int modifyStudent(list *l, char *am);
void destroyList(list *l);

#endif