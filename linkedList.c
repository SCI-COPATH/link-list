#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *link;
};
struct node* makeNode(){
    struct node *ptr=NULL;
    ptr=(struct node *)malloc(sizeof(struct node));
    if(ptr==NULL)
        printf("Memory Problem \n");
    return ptr;
}
struct node* insertFront(struct node *head,int value){
    if(head==NULL){
        head=makeNode();
        head->data=value;
        head->link=NULL;
    }
    else{
        struct node *temp=makeNode();
        temp->link=head;
        temp->data=value;   
        head=temp;
    }
    return head;
}
struct node* insertEnd(struct node *head ,int value){
    struct node *ptr=head,*temp;
    if(head==NULL){
        head=makeNode();
        head->data=value;
        head->link=NULL;
    }
    else{
        while(ptr->link!=NULL)
            ptr=ptr->link;
        temp=makeNode();
        temp->data=value;
        temp->link=NULL;
        ptr->link=temp;
    }
    return head;
}
struct node* insertMid(struct node *head ,int pos,int value){
    struct node *ptr=head,*temp=head;
    int count=0;
    pos--;
    while(temp!=NULL){
        temp=temp->link;
        count++;
    }
     printf("pos is %d and count %d",pos,count);
    if(pos<=0||pos>count-1)
        printf("Wrong input\n");
    else{
        for(int i=1;i<pos;i++)
            ptr=ptr->link;
        temp=makeNode();
        temp->data=value;
        temp->link=ptr->link;
        ptr->link=temp;
    }
    return head;
}
struct node* deletFront(struct node *head){
    struct node *ptr=head;
    if(head==NULL)
        printf("No elemet here");
    else{
        printf("Remove elemet is %d\n",ptr->data);
        head=head->link;
        free(ptr);
        ptr=NULL;
    }
    return head;
}
struct node* deleteEnd(struct node *head){
    struct node *ptr=head;
    if(head==NULL)
        printf("No elemet here");
    else{
        if(ptr->link==NULL){
            printf("Remove element is %d\n",ptr->data);
            free(ptr);
            ptr=NULL;
            head=NULL;
        }
        else{
            while(ptr->link->link!=NULL)
                ptr=ptr->link;
            printf("Remove element is %d\n",ptr->link->data);
            free(ptr->link);
            ptr->link=NULL;
            ptr=NULL;
        }
    }
    return head;
}
struct node* deleteMid(struct node *head,int pos){
    struct node *ptr=head,*temp=head;
    pos--;
    int count =0;
    while(temp!=NULL){
        count++;
        temp=temp->link;
    }
    if(pos<=0||pos>count-1)
        printf("Wrong input \n");
    else{
        for(int i=1;i<pos;i++)
            ptr=ptr->link;
        temp=ptr->link;
        ptr->link=ptr->link->link;
        printf("Removed element is %d\n",temp->data);
        free(temp);
        temp=NULL;
        ptr=NULL;
    }
    return head;
}
void view (struct node *head){
        struct node* ptr=head;
        if(head==NULL)
            printf("EMPTY LINKEDLIST\n");
        else{
            printf("\nLINKED LIST\n");
            while(ptr!=NULL){
                printf("\n%d",ptr->data);
                ptr=ptr->link;
            }
        }
        printf("\n");
} 
int search(struct node *head,int element){
    struct node *ptr=head;
    int count;
    if(head==NULL){
        printf("Empty linkedlist\n");
        return -1;
    }
    else{
        while(ptr!=NULL){
            count++;
            if(ptr->data==element){
                printf("Elemet is present in %d th position\n",count);
                return count;
            }
            ptr=ptr->link;
        }
    }
    printf("Element is not present\n");
    return -1;
}
void main(){
    struct node *head = NULL;
    int dis,inDis,value,pos;
    do{
        printf("\n1-INSERTION\n2-DELETION\n3-SEARCH\n4-VIEW\n5-EXIT \nENTER : ");
        scanf("%d",&dis);
        if(dis==1){
            do{
                printf("\n\t1-INSERTION FORM START\n\t2-INSERTION FORM END\n\t3-INSERTION IN POSITION \n\tENTER : ");
                scanf("%d",&inDis);
            }while(!(inDis==1||inDis==2||inDis==3));
            printf("\t\tEnter value : ");
            scanf("%d",&value);
            if(inDis==1)
                head=insertFront(head,value);
            else if(inDis==2)
                head=insertEnd(head,value);
            else if(inDis==3){
                printf("\t\tRead position (2,3....n-1): ");
                scanf("%d",&pos);
                head=insertMid(head,pos,value);
            }
        }
        else if(dis==2){
            do{
                printf("\n\t1-DELETE FORM START\n\t2-DELETE FORM END\n\t3-DELETE IN POSITION \n\tENTER  : ");
                scanf("%d",&inDis);
            }while(!(inDis==1||inDis==2||inDis==3));
            if(inDis==1)
                head=deletFront(head);
            else if(inDis==2)
                head=deleteEnd(head);
            else if(inDis==3){
                printf("\t\tRead position (2,3....n-1): ");
                scanf("%d",&pos);
                head=deleteMid(head,pos);
            }
        }
        else if(dis==3){
            printf("\tENTER ELEMENT : ");
            scanf("%d",&value);
            value=search(head,value);
        }
        else if(dis==4)
            view(head);
    }while(dis!=5);  
    free(head);
    head=NULL;
}