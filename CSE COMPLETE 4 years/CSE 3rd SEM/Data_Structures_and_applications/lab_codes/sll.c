#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<string.h>


struct Day
{
    char *day_name;
    char *activity;
    int date;
};

void create(struct Day *day)
{
    day->day_name = (char*)malloc(sizeof(char*20));
    day->activity = (char*)malloc(sizeof(char*100));
    printf("\nEnter the Day Name: ");
    scanf("%s",day->day_name);
    printf("\nEnter the Date: ");
    scanf("%d",&day->date);
    printf("\nEnter the Activity: ");
    scanf("%s",day->activity);

}
void read(struct Day *calander)
{
    for(int i=0; i<7; i++){
        printf("Enter the details for Day %d",i+1);
        create(&calander[i]);
    }
}
void display(struct Day *calander)
{
    printf("Day Name\t Date\t Activity\n");
    for(int i=0; i<n; i++){
        printf("%s\t%d\t%s",calander[i].day_name,calander[i].date,calander[i].activity);
    }
}
void freememory(struct Day *calander)
{
    for(int i=0; i<7; i++){
        free(calander[i].day_name);
        free(calander[i].activity);
    }
}
void main()
{
    struct Day *calander = (struct Day*)malloc(sizeof(struct Day)*7);
    if(calander == NULL){
        printf("Memory allocation Failed");
    }
    read(calander);
    display(calander);
    freememory(calander);
    free(calander);
}
