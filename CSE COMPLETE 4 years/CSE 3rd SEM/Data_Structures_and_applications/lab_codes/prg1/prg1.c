#include<stdio.h>
#include<stdlib.h>

struct Day
{
    char *dayname;
    int date;
    char *activity;
};
void create(struct Day *day)
{
    day->dayname = (char*)malloc(sizeof(char)*20);
    day->activity = (char*)malloc(sizeof(char)*100);

    printf("\nEnter the Day name: ");
    scanf("%s",day->dayname);

    printf("\nEnter the Date: ");
    scanf("%d",&day->date);

    printf("\nEnter the activity: ");
    scanf("%s",day->activity);
}
void read(struct Day *calander, int size)
{
    int i;
    for(i=0; i<size; i++){
        printf("Enter the details for Day %d:",i+1);
        create(&calander[i]);
    }
}
void display(struct Day *calander, int size)
{
    printf("--Week Activity Details--\n");
    for (int i = 0; i < size; i++) {
        printf("Day %d:\t", i + 1);
        printf("Day Name: %s\t", calander[i].dayname);
        printf("Date: %d\t", calander[i].date);
        printf("Activity: %s\t", calander[i].activity);
        printf("\n");
    }
}
void freememory(struct Day *calander, int size)
{
    for (int i = 0; i < size; i++) {
        free(calander[i].dayname);
        free(calander[i].activity);
    }
}
void main()
{
    int size;
    printf("Enter the size of the week: ");
    scanf("%d",&size);
    struct Day *calander = (struct Day *)malloc(sizeof(struct Day)*size);

    if(calander == NULL){
        printf("\nMemory alloc failed Exiting prg");
        return;
    }
    read(calander,size);
    display(calander,size);
    freememory(calander,size);
    free(calander);
}
