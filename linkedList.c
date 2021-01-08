#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *link;
};
struct node* makeNode(){
    struct node *ptr=NULL;
    ptr=(struct node *)malloc(sizeof(struct node));
    printf("%d\n",ptr);
    if(ptr==NULL){
        printf("Memory Problem \n");
        exit(0);
    }
    return ptr;
}
void insertFront(struct node *head,int value){
    if(head==NULL){
        head=makeNode();
        head->data=value;
        head->link=NULL;
        printf("%d",head);
    }
    else{
        struct node *temp=makeNode();
        temp->link=head;
        temp->data=value;
        head=temp;
    }
}
void insertEnd(struct node *head ,int value){
    struct node *ptr=head,*temp;
    if(head==NULL){
        head=makeNode();
        head->data=value;
        head->link=NULL;
    }
    else{
        while(ptr!=NULL)
            ptr=ptr->link;
        temp=makeNode();
        temp->data=value;
        temp->link=NULL;
        ptr->link=temp;
    }
}
void insertMid(struct node *head ,int pos,int value){
    struct node *ptr=head,*temp=head;
    int count=0;
    pos--;
    while(temp!=NULL){
        temp=temp->link;
        count++;
    }
    if(pos<=0||pos>=count-1)
        printf("Wrong input\n");
    else{
        for(int i=1;i<pos;i++)
            ptr=ptr->link;
        temp=makeNode();
        temp->data=value;
        temp->link=ptr->link;
        ptr->link=temp;
    }
}
void deletFront(struct node *head){
    struct node *ptr=head;
    if(head==NULL)
        printf("No elemet here");
    else{
        printf("Remove elemet is %d\n",ptr->data);
        head=head->link;
        free(ptr);
        ptr=NULL;
    }
}
void deleteEnd(struct node *head){
    struct node *ptr;
    if(head==NULL)
        printf("No elemet here");
    else{
        while(ptr->link!=NULL){
            ptr=ptr->link;
        }
        printf("Remove element is %d\n",ptr->link->data);
        free(ptr->link);
        ptr->link=NULL;
    }
}
void deleteMid(struct node *head,int pos){
    struct node *ptr=head;
    pos--;
    int count =0;
    while(ptr!=NULL){
        count++;
        ptr=ptr->link;
    }
    if(pos<=0||pos>=count-1)
        printf("Wrong input \n");
    else{
        for(int i=1;i<pos;i++)
            ptr=ptr->link;
        struct node *temp=ptr->link;
        ptr->link=ptr->link->link;
        printf("Removed element is %d\n",temp->data);
        free(temp);
        temp=NULL;
    }
}
void view (struct node *head){
        struct node* ptr=head;
        printf("\nLINKED LIST\n");
        while(ptr!=NULL){
            printf("\n%d",ptr->data);
            ptr=ptr->link;
        }
        printf("\n");
} 
void main(){
    struct node *head = NULL;
    int dis,inDis,value,pos;
    do{
        printf("\n1-INSERTION\n2-DELETION\n3-VIEW\n4-EXIT \n: ");
        scanf("%d",&dis);
        if(dis==1){
            do{
                printf("\n\t1-INSERTION FORM START\n\t2-INSERTION FORM END\n\t3-INSERTION IN POSITION \n : ");
                scanf("%d",&inDis);
            }while(!(inDis==1||inDis==2||inDis==3));
            printf("\t\tEnter value : ");
            scanf("%d",&value);
            if(inDis==1){
                insertFront(head,value);
                printf("\n%d",head);
            }
            else if(inDis==2)
                insertEnd(head,value);
            else if(inDis==3){
                printf("\t\tRead position (1,2,3....n-1): ");
                scanf("%d",&pos);
                insertMid(head,pos,value);
            }
        }
        else if(dis==2){
            do{
                printf("\n\t1-DELETE FORM START\n\t2-DELETE FORM END\n\t3-DELETE IN POSITION \n : ");
                scanf("%d",&inDis);
            }while(!(inDis==1||inDis==2||inDis==3));
            if(inDis==1)
                deletFront(head);
            else if(inDis==2)
                deleteEnd(head);
            else if(inDis==3){
                printf("\t\tRead position (1,2,3....n-1): ");
                scanf("%d",&pos);
                deleteMid(head,pos);
            }
        }
        else if(dis==3)
            view(head);
    }while(dis!=4);
    free(head);
    head=NULL;
}