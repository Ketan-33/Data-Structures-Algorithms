#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *Next;
};
struct node *Head;

void create()
{
    if (Head == NULL)
    {
        printf("-->Enter Head Element: ");
        Head = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &Head->data);
        Head->Next = NULL;
    }
    else
    {
        printf("***List Exists***\n");
    }
}

// Insert at the head node
void insert_begin(int element)
{
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    t->data = element;
    t->Next = Head;
    Head = t;
    printf("***New Head added***\n");
}

// Append element
void append(int ele)
{
    struct node *temp, *temp1;
    temp1 = Head;

    if (Head == NULL)
    {
        printf("**Calling create function**\n");
        create();
    }
    else
    {
        while (temp1->Next != NULL)
        {
            temp1 = temp1->Next;
        }

        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = ele;
        temp->Next = NULL;
        temp1->Next = temp;
        printf("**Element appended**\n");
    }
}

void insert_between(int element, int position)
{
    // if (position <= 1)
    // {
    //     printf("Invalid position for insertion.\n");
    //     return;
    // }

    struct node *temp, *prev, *newnode;
    int count = 1;
    temp = Head;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = element;

    while (temp != NULL && count != position)
    {
        prev = temp;
        temp = temp->Next;
        count++;
    }
    if(position == 1){
        prev=temp;
        temp=temp->Next;
        prev->Next = newnode;
        newnode->Next = temp;
        printf("**Element Inserted**\n");
    }
    if (count == position)
    {
        prev->Next = newnode;
        newnode->Next = temp;
        printf("**Element Inserted**\n");
    }
    else
    {
        printf("**Invalid position for insertion.**\n");
    }
}

void traverse()
{
    struct node *t;
    t = Head;
    if(Head==NULL){
        printf("**List empty**\n");
    }
    while (t != NULL)
    {
        printf("%d -> ", t->data);
        t = t->Next;
    }
    printf("NULL\n");
}

int delete_head(){
    struct node *temp;
    int data;
    temp = Head;
    Head = Head->Next;
    data=temp->data;
    free(temp);
    printf("**Head Deleted**\n");
    return data;
}

int delete_end(){
    struct node *temp,*prev;
    int data;
    temp = Head;
    while (temp->Next!= NULL)
    {
        prev=temp;
        temp = temp->Next;
    }
    prev->Next = NULL;
    data=temp->data;
    free(temp);
    printf("**Last Element deleted %d**\n",data);
    return data;
}

int delete_between(int position)
{
    int data;
    if (Head == NULL)
    {
        printf("**List is empty**\n");
        return -1;
    }

    if (position == 1)
    {
        struct node *temp = Head;
       
        Head = Head->Next;
        data=temp->data;
        free(temp);
        printf("**Element deleted**\n");
        return data;
    }

    struct node *temp = Head, *prev = NULL;
    int count = 1;
    while (temp != NULL && count < position)
    {
        prev = temp;
        temp = temp->Next;
        count++;
    }

    if (temp == NULL)
    {
        printf("**Invalid position**\n");
    }
    else
    {
        prev->Next = temp->Next;
        data=temp->data;
        free(temp);
        printf("**Element deleted**\n");
        return data;
    }
}

void search(int element)
{
    struct node *t;
    t = Head;
    int count = 0;
    while (t != NULL)
    {
        count++;
        if(t->data==element){
            printf("-->Element found at node %d\n",count);
            return;
        }
        t = t->Next;
    }
    printf("**No element found**\n");
    
}
int main()
{
    int element, choice, position;
    create();
    while (choice != 9)
    {
        printf("1. Append\n");
        printf("2. Insert begin\n");
        printf("3. Insert between\n");
        printf("4. Traverse\n");
        printf("5. Delete Head\n");
        printf("6. Delete end\n");
        printf("7. Delete between\n");
        printf("8. Search\n");
        printf("9. To terminate\n");
        printf("-->Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("-->Enter element to append: ");
            scanf("%d", &element);
            append(element);
            break;
        case 2:
            printf("-->Enter New Head: ");
            scanf("%d", &element);
            insert_begin(element);
            break;
        case 3:
            printf("-->Enter element to insert: ");
            scanf("%d", &element);
            printf("-->Enter position: ");
            scanf("%d", &position);
            insert_between(element, position);
            break;
        case 4:
            printf(" ** Your Linked List **\n");
            traverse();
            break;
        case 5:
            delete_head();
            break;
        case 6:
            delete_end();
            break;
        case 7:
            printf("-->Enter position:");
            scanf("%d", &position);
            delete_between(position);
            break;
        case 8:
            printf("-->Enter element to find:");
            scanf("%d", &element);
            search(element);
            break;    
        case 9:
            printf("** Terminating program **.\n");
            break;
        default:
            printf("** Invalid choice **\n");
            break;
        }
    }
}
