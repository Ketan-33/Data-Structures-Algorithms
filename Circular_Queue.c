#include<stdio.h>
#include<malloc.h>
const int max=10;
int size=0;
int flag=0;
struct Queue{
    int *Que;
    int Rear;
    int Front;
};

void create(struct Queue *Q){
    Q->Rear=-1;
    Q->Front=-1;
    printf("***Queue Created***\n");
}

int isEmpty(struct Queue *Q){
    if(Q->Rear==Q->Front==-1){
        return 1;
    }
    else
        return 0;
}

//adding element to rear
void Enqueue(struct Queue *Q,int element){
    if(Q->Front==Q->Rear==-1){
        Q->Front=Q->Rear=0;
    }

    else if((Q->Rear+1)%max == Q->Front){
        printf("***Queue Full***\n");
        flag=1;
    }
    else{
        Q->Rear=(Q->Rear+1)%max;
    }
    Q->Que[Q->Rear] = element;
    size++;
}

//removing element 

int Dequeue(struct Queue *Q){
    if(Q->Front==-1 && Q->Rear==-1){
        printf("***Queue Empty***\n");
    }
    else if(Q->Front == Q->Rear){
        Q->Rear=Q->Front=-1;
    }
    else{
        int element=Q->Que[Q->Front+1];
        Q->Front=(Q->Front+1)%max;
        size--;
        return element;

    }
}
// retrun the front element
int Front(struct Queue *Q){
        return Q->Que[Q->Front+1 ];
}

int size_Que(){                     
    printf("-->Size = %d",size);
}
int main(){
    struct Queue Q;
    int choice,data;
    create(&Q);
    do
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Front\n");
        printf("4. Get Size of Queue\n");
        printf("5. Quit\n");
        printf("-->Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if(flag!=1){
            printf("-->Enter data to enqueue: ");
            scanf("%d", &data);
            Enqueue(&Q, data);
            }
            else{
                printf("****Enqueue cannot pe performed****");
            }
            break;
        case 2:
            if (isEmpty(&Q)==0)
            {
                printf("-->Dequeued element: %d\n", Dequeue(&Q));
            }
            else
            {
                printf("***Queue is empty. Cannot dequeue.***\n");
            }
            break;
        case 3:
            if (isEmpty(&Q)==0)
            {
                printf("-->Front element: %d\n", Front(&Q));
            }
            else
            {
                printf("***Queue is empty. No front element.***\n");
            }
            break;
        case 4:
            size_Que();
            break;
        case 5:
            printf("***Exiting program***.\n");
            break;
        default:
            printf("***Invalid choice.***\n");
            break;
        }
    } while (choice != 6);
}
