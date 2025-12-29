#include <stdio.h>
#define MAX 100

void readString(char str[]);
void replaceAll(char str[], char pat[], char rep[]);

int main() {
    char STR[MAX], PAT[MAX], REP[MAX];

    printf("Enter MAIN string: ");
    readString(STR);

    printf("Enter PATTERN: ");
    readString(PAT);

    printf("Enter REPLACE: ");
    readString(REP);

    replaceAll(STR, PAT, REP);
    return 0;
}

void readString(char str[]) {
    int i = 0;
    char ch;
    while((ch = getchar()) != '\n')
        str[i++] = ch;
    str[i] = '\0';
}

void replaceAll(char str[], char pat[], char rep[]) {
    char result[MAX];
    int i = 0, j = 0, found = 0;
    int lenPAT = 0, k;

    // Find pattern length
    while(pat[lenPAT] != '\0') lenPAT++;

    // Search and replace
    while(str[i] != '\0') {
        // Check if pattern matches at position i
        if(str[i] == pat[0] && strncmp(str+i, pat, lenPAT) == 0) {
            // Copy replacement
            k = 0;
            while(rep[k] != '\0') {
                result[j++] = rep[k++];
            }
            i += lenPAT;
            found = 1;
        } else {
            result[j++] = str[i++];
        }
    }
    result[j] = '\0';

    if(!found) {
        printf("PATTERN not found\n");
    } else {
        printf("Result: %s\n", result);
    }
}

