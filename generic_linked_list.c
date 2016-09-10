#include <stdio.h>
#include<stdlib.h>
#include<string.h>

short myDataType=0;

struct node {
    void *data;
    struct node *next;
    int type;
};




struct node* get_new_int_node(int data){
    struct node * temp=(struct node *)malloc(sizeof(struct node));
    int *myInt=(int *)malloc(sizeof(int));
    *myInt=data;
    temp->next=NULL;
    temp->data=myInt;
    temp->type=1;

    return temp;
}

struct node* get_new_double_node(double data){
    struct node * temp=(struct node *)malloc(sizeof(struct node));
    double * temp_double=(double *)malloc(sizeof(double));
    *temp_double=data;
    temp->next=NULL;
    temp->data=temp_double;
    temp->type=2;
    return temp;
}

struct node* get_new_char_node(char data){
    struct node * temp=(struct node *)malloc(sizeof(struct node));
    char * temp_char=(char *)malloc(sizeof(char));
    *temp_char=data;
    temp->next=NULL;
    temp->data=temp_char;
    temp->type=3;
    return temp;
}


void print_list_new(struct node *head){
    struct node *p=head;
    printf("\nList content =>:\n");
    if(p==NULL){
        printf("List is empty\n");
    }
    while(p!=NULL){
        if(p->type==1){
            printf("%d ",*(int *)p->data);
            //printf("%u ",(int *)p->data);
        }else if(p->type == 2){
            printf("%f ",*(double *)p->data);
        }else{
            printf("%c ",*(char *)p->data);
        }
        printf("-> ");
        p=p->next;
    }
    printf("null\n");
}

/*not using this*/
void print_list(struct node *head){
    struct node *p=head;
    printf("\nList content =>:\n");
    if(p==NULL){
        printf("List is empty\n");
    }
    while(p!=NULL){
        if(__builtin_types_compatible_p(typeof(p->data), int)) {
                printf("0000000000000000\n");
            printf("%d ",*(int *)p->data);
        }else if(__builtin_types_compatible_p(typeof(p->data), double)){
            printf("1111111111111111111111\n");
            printf("%f ",*(double *)p->data);
        }else{
            printf("%c ",*(char *)p->data);
        }
        printf("-> ");
        p=p->next;
    }
    printf("null\n");
}


struct node* insert_end(struct node** head,void * data,int type){
    struct node *new_node, *p;
    p=*head;
    int x;
    if(type==1){
        x=*((int *)data);
        new_node=get_new_int_node(x);
        printf("%d value will be inserted in the node\n",*(int *)(new_node->data));
    }else if(type==2){
        double y=*((double *)data);
        new_node=get_new_double_node(y);
        printf("%f value will be inserted in the node\n",*(double *)(new_node->data));
    }else{
        char *z=(char *)data;
        new_node=get_new_char_node(*z);
        printf("%c value will be inserted in the node\n",*(char *)(new_node->data));

    }
    if(*head == NULL){
        *head=new_node;
        return *head;
    }

    while(p->next != NULL){
        p=p->next;
    }
    p->next=new_node;
    return *head;
}


int determine(char *input){
    int i=0;
    int c;
    int dot_present=0;
    while((c=input[i++])!= '\0'){
        if(c=='\n'){
            break;
        }
        if(isdigit(c)){
            myDataType=1;
        }else if(c=='.'){
            myDataType=2;
            dot_present=1;
        }else if(isalpha(c) || c==' '){
            myDataType = 4;
            return myDataType;
        }else{
            myDataType = 4;
            return myDataType;
        }
    }
    if(dot_present){
       myDataType=2;
    }else{
        myDataType=1;
    }
    return myDataType;

}

void main(){
    char input[250];
    int type;
    struct node * head=NULL;
    int choice;
    while(1){
        printf("\n1: insert 2: print list 3:Quit\n");
        printf("Enter choice:\n");
        /**[^\n] says to ignore everything after your integer input that isn't a newline, but don't do anything with the newline (skip it).
        otherwise fgets will not wait*/
        scanf("%d",&choice);
        fflush(stdin);
        switch(choice){

        case 1:
            fgets(input, 250, stdin);
            type=determine(input);
            int int_input;
            double double_input;
            if(type==1){
                int_input=atoi(input);
                insert_end(&head,&int_input,type);
            }else if(type == 2){
                double_input=atof(input);
                insert_end(&head,&double_input,type);
            }else{
                insert_end(&head,input,type);
            }
            break;
        case 2:
            print_list_new(head);
            break;
        case 3:
            exit(0);
        default:
            exit(0);


        }
    }



}
