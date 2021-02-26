#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* createMatrix(int row, int column);

char *stringToWords(char *str, int dim);

void populate(char *matrix, char *string);

int longestWord(char *str, int dim){
    int i;
    int count = 0;
    int max = 0;

    for(i=0; i<strlen(str); i++){
        if(str[i] == ' '){
            if(count > max)
                max = count;
            count = 0;
            printf("spazio\n");
        }
        else
            count++;
            printf("parola\n");
    }
    return max;
}


int main(){
    int i, words;
    int maxlength = 50; 
    char *str = (char*)malloc(sizeof(char) * maxlength);

    printf("Insert the words to add in the WordSearch\nNo more than 200 chars ;)\n");
    printf("Insert words here:");
    scanf("%s",str);

    if(strlen(str) >= maxlength){
        printf("Hey! I told you no more than %d char >:(\n",maxlength);
        return 1;
    }

    printf("longest:%d\n", longestWord(str,strlen(str)));
    return 0;
}