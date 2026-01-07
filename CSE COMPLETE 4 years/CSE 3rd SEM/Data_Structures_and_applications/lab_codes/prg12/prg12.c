#include<stdio.h>
#include<stdlib.h>

struct Emprec
{
    int key;
    char name[20];
    int sal;
};
int hashfunction(int key, int m)
{
    return key%m;
}
void insertRecord(struct Emprec emp[], int memlocs[], int key, int m, int n)
{
    int hashvalue,sal;
    char name[20];
    hashvalue = hashfunction(key, m);
    while (emp[hashvalue].key != -1) {
            hashvalue = (hashvalue + 1) % m;
        }
    printf("\nEnter the name : ");
    scanf("%s", emp[hashvalue].name);
    printf("\nEnter the salary : ");
    scanf("%d", &emp[hashvalue].sal);
    emp[hashvalue].key = key;
    memlocs[hashvalue] = hashvalue + 1;
}
void displayhashtable(struct Emprec emp[], int memlocs[], int m)
{
    int i;
    printf("\nHash Table:\n");
    printf("\nMemory Location\t Key \t Name \t Salary\n");
    for ( i = 0; i < m; i++) {
        printf("%d\t\t%d\t%s\t%d\n", memlocs[i], emp[i].key,emp[i].name, emp[i].sal);
    }
}
int main() {
    struct Emprec emp[50];
    int memlocs[20], i, m, n;
    printf("Enter the number of memory locations: ");
    scanf("%d", &m);
    printf("Enter the number of employee records: ");
    scanf("%d", &n);
    for (i = 0; i < 20; i++) {
        emp[i].key = -1;
        memlocs[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        int key;
        printf("Enter the key for employee record %d: ", i + 1);
        scanf("%d", &key);
        insertRecord(emp, memlocs, key, m, n);
    }
    displayhashtable(emp, memlocs, m);
    return 0;
}
