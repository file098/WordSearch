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

int append(tlist *pl, char* elem) 
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
       if(((*str) >= 'a' && (*str) <='z') || ((*str)>='A' && (*str)<='Z')){
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

/* FIXME: */
tlist string2List(char *str)
{
    int i = 0;
    tlist new = (tlist)malloc(sizeof(struct cell));
    while((*str) != '\0'){
        char *buff = (char*)malloc(sizeof(char) * longestWord(str)+1);
        if(((*str) >= 'a' && (*str) <='z') || ((*str)>='A' && (*str)<='Z')){
            buff[i] = *str;
            str++;
            i++;
        }
        else {
            append(&new,buff);
            i = 0;
            str++;
        }
    }
    return new;
}

void printList(tlist l){
    if(l){
        printf("%s\n", l->string);
        printList(l->next);
    }
}

int main()
{
    char *str = (char*)malloc(sizeof(char) * MAXLENGTH);

    printf("Insert the words to add in the WordSearch\nNo more than 200 chars ;)\n");
    printf("Insert words here:");
    scanf("%[^\n]%*c",str);

    if(strlen(str) >= MAXLENGTH){
        printf("Hey! I told you no more than %d char >:(\n",MAXLENGTH);
        return 1;
    }

    printList(string2List(str));

    return 0;
}
