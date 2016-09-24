/*
People are sitting on round table and we have knock out each of one in alternate order eg 1 2 3 4 5 6.
These 6 people are sitting in circular table. If we knock out 2 first. Output should be 2 4 6 3 1 5

*/

#include<stdio.h>
#include<stdlib.h>



void strike_out(int *p,int s,int n){
    int i,removed=0;
    int *cur=p;
    i=s;
    while(removed!=(n)){
        i=i%n;
        //printf("%d in %dth itereation\n",cur[i],i);
        if(cur[i]!= -1){
            printf("Removed %d\n",cur[i]);
            cur[i]=-1;
            removed++;
            int incr_twice=0;
            int j=i+1;
            while(incr_twice!=2 && removed != n){
                if(cur[j%n]!=-1){
                    incr_twice++;
                }
                j++;
            }
            i=j-1;
        }else{
            int j=i;
            while(cur[j]==-1){
                j++;
            }
            i=j;

        }
    }
    printf("\n");

}

void main(int argc,char *argv[]){
    int n,i,s;
    printf("\nNumber of people: ");
    scanf("%d",&n);
    int *p=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        *(p+i)=i+1;
    }
    int loop=1;
    while(loop){
        printf("Start from position: ");
        scanf("%d",&s);
        //array index start from 0
        if(s>n){
            printf("1 <= position <= %d \n",n);
        }else{
            loop=0;
        }

    }
    strike_out(p,s-1,n);


}
