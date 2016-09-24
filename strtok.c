/*
Implement strtok functions of strings.
eg char a[]=”ab,cd,e”
Output should be 3 strings–“ab”, “cd” and “e” if we consider the delimiter as ‘,’

*/

#include<stdio.h>
#include<string.h>

void my_strtok(char *input,char *delim){
    int i=0,k=0;
    char temp[100];
    char *final_str[10];
    memset(temp,'\0',sizeof(temp));
    while(*input!='\0'){
        if(*input == *delim || *input=='\n' || *input=='\0'){
            final_str[i]=temp;
            printf("%s\n",final_str[i]);
            i++;
            memset(temp,'\0',sizeof(temp));
        }else{
            //printf("%c",*input);
            sprintf(temp,"%s%c",temp,*input);
        }
        input++;

    }
    final_str[i]=temp;
    printf("%s",final_str[i]);


    //printf("\n\n%d\n\n",i);
    /*int j=0;
    while(j<=i){
        printf("%s\n",final_str[j]);
        j++;
    }
    */

}

int main(int argc,char *argv[]){
    char input[100];
    char delim[10];
    int done=0;
    printf("Enter the string\n");
    //scanf("%s",&input);
    gets(input);
    while(!done){
            printf("Enter delimiter: ");
            gets(delim);
            if(strlen(delim)!=1){
                printf("length of delimiter must be 1\n");
            }else{
                done=1;
            }
    }
    my_strtok(input,delim);

}
