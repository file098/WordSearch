#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLENGTH 50

typedef struct cell {
    char *string;
    struct cell *next;
} *tlist;

int prepend(tlist *pl, char *elem)
{
    if (*pl == NULL)
        return prepend(pl, elem);
    else{
        tlist pc = *pl;
        while (pc->next != NULL)
            pc = pc->next;
        pc->next = (tlist)malloc(sizeof(struct cell)); 
        if (pc->next != NULL) {
            pc->next->string = elem;
            pc->next->next = NULL;
            return 1;
        }
        else
            return 0;
    }
}

int append(tlist *pl, int elem) 
{ 
    if (*pl == NULL)
        return prepend(pl, elem);
    else
        return append(&((*pl)->next), elem); 
}

int longestWord(char *str)
{
    int count = 0;
    int max = 0;

    while((*str)!='\0'){
       if((*str) >= 'a' && (*str) <='z'|| (*str)>='A'&& (*str)<='Z'){
           count++;
            if(count > max)
                max = count;
        }
        else{
            count=0;
        }
        str++;
    }
    return max;
}

void string2List(char *str)
{
    int i,j;
    char *buff;
    tlist new = (tlist)malloc(sizeof(struct cell));
    while((*str) != '\0'){

    }
}

int main()
{
    int i, words;
    char *str = (char*)malloc(sizeof(char) * MAXLENGTH);

    printf("Insert the words to add in the WordSearch\nNo more than 200 chars ;)\n");
    printf("Insert words here:");
    scanf("%[^\n]%*c",str);

    if(strlen(str) >= MAXLENGTH){
        printf("Hey! I told you no more than %d char >:(\n",MAXLENGTH);
        return 1;
    }

    return 0;
}