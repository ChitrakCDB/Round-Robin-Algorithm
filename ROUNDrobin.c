#include<stdio.h>
struct Node{
  struct Node *next;
  int aT;
  int pT;
  int prog;
};

 struct Node *first=NULL,*head=NULL,*temp=NULL,*front=NULL,*rear=NULL,*qhead=NULL,*temp2=NULL;
void Arrivaltime();
void Processtime();
void displayProgram();
void displayArrival();
void Roro();
int qT=3,tT=0,T=0;
int main(){
int n;
printf("enter number of programs:");
scanf("%d",&n);
Arrivaltime(n);
Roro();
return 0;
}
void Arrivaltime(n){
   int i =0;
    while(i<n){
temp=(struct Node *)malloc(sizeof(struct Node)*1);
head=(struct Node *)malloc(sizeof(struct Node)*1);
      printf("\nEnter Program number :");
        scanf("%d",&temp->prog);

           printf("\nEnter Arrival time :");
        scanf("%d",&temp->aT);

           printf("\nEnter Process time :");
        scanf("%d",&temp->pT);


        temp->next=NULL;
        if(first==NULL){
            first=temp;
        }
        else{
            head=first;
             while(head->next!=NULL){
                head=head->next;
            }
                head->next=temp; }
                i++;

}
head=first;
tT=first->aT;
while(head->next!=NULL){
    if(tT>head->aT){
        tT=head->aT;
    }
    head=head->next;
}
head=first;
while(head!=NULL){
    tT=tT+head->pT;
    head=head->next;
}
printf("TotalTime:%d",tT);
displayArrival();

}
void displayArrival(){
 head=first;
  if(head==NULL){
                printf("THE STACK IS EMPTY");
            }
            else{   printf("\n\tRound Robin Inputs:");
                             printf("\n\tID || aT || pT ");
                             while(head!=NULL){

                    printf("\n\t%d  || %d  || %d",head->prog,head->aT,head->pT);
                head=head->next;
            }
            }
            }
void Roro(){

int i,flag=0;
while(front==NULL){
    head=first;
    while(head!=NULL){
        if(head->aT==T){
            temp=(struct Node*)malloc(sizeof(struct Node)*1);
            temp->prog=head->prog;
            temp->aT=head->aT;
            temp->pT=head->pT;
            temp->next=NULL;
            if(front==NULL){
                front=temp;
                rear=front;
                printf("\nQueue Value is :%d",front->prog);
            }
            else{
                qhead=front;
                while(qhead->next!=NULL){
                    qhead=qhead->next;
                }
                qhead->next=temp;
                rear=qhead->next;
                printf("\nQueue value is:%d",qhead->next->prog);
            }
        }
        head=head->next;
    }
    T++;
}
T--;
while(T!=tT){
      temp=(struct Node*)malloc(sizeof(struct Node)*1);
          temp->prog=front->prog;
            temp->aT=front->aT;
            temp->pT=front->pT;
            temp->next=NULL;
            front=front->next;
            for(i=0;i<qT;i++){
                T++;
                head=first;
                while(head!=NULL)
                {
                    if(head->aT==T){
                        temp2=(struct Node*)malloc(sizeof(struct Node)*1);
                         temp2->prog=head->prog;
                         temp2->aT=head->aT;
                          temp2->pT=head->pT;
                            temp2->next=NULL;
                            if(front==NULL){
                                front=temp2;
                                rear=front;
                                printf("\nQueue value is:%d",front->prog);
                            }
                            else{
                                rear->next=temp2;
                                rear=rear->next;
                                printf("\nQueue value is:%d",rear->prog);
                            }
                    }
                    head=head->next;
                }
                temp->pT--;
                if(temp->pT==0){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                      rear->next=temp;
                                rear=rear->next;
                                printf("\nQueue value is:%d",rear->prog);
            }
            else{
                flag=0;
            }
}
}
