#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
struct week_activity {
    char *day, *activity;
    int d,m,y;
};
typedef struct week_activity WEEK;
WEEK *create(){
    char* days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    WEEK *temp = (WEEK*)malloc(7*sizeof(WEEK));
    int i;
    for(i=0;i<7;i++){
        temp[i].day = days[i];
        temp[i].d = temp[i].m = temp[i].y = 0;
        temp[i].activity = "";
    }
    return temp;
}
void readactivity(WEEK *WA){
    int i, dd, mm, yy;
    char str[50], ch;
    printf("\nEnter the starting date of the week (dd mm yyyy): ");
    scanf("%d %d %d",&dd,&mm,&yy);
    fflush(stdin);
    for(i=0;i<7;i++){
        printf("\nDo you want to create activity for %s (y/n)? ",WA[i].day);
        scanf("%c",&ch);
        WA[i].d = dd + i;
        WA[i].m = mm;
        WA[i].y = yy;
        if(ch == 'y' || ch == 'Y'){
            printf("Enter activity for %s: ",WA[i].day);
            fflush(stdin);
            fgets(str, sizeof(str), stdin);
            str[strcspn(str, "\n")] = 0; // Remove newline character
            WA[i].activity = (char*)malloc((strlen(str)+1)*sizeof(char));
            strcpy(WA[i].activity, str);
        }
    }
}
void display(struct week_activity WA[]){
    int i;
    printf("__________________________________________\n");
    printf("    Day       Date        Activity\n");
    printf("__________________________________________\n");
    for(i=0;i<7;i++){
        printf("%-10s  %02d-%02d-%04d  %-30s\n",WA[i].day,WA[i].d,WA[i].m,WA[i].y,WA[i].activity);
    }
    printf("__________________________________________\n");
}
void main(){
    WEEK *WA;
    WA = create();
    readactivity(WA);
    display(WA);
} 