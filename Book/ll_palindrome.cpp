#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

void insert_node(struct node **head, int value, struct node **tail)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    temp->next = NULL;
    if((*head) == NULL)
    {
        (*head) = temp;
        (*tail) = temp;
    }
    else
    {
        (*tail)->next = temp;
        (*tail) = temp;
    }
}

struct node *mid(struct node *head)
{
    int current = 0;
    struct node *fastptr = head, *slowptr = head;
    while(fastptr != NULL && fastptr->next != NULL)
    {
        if(current == 0)
        {
            fastptr = fastptr->next;
            current = 1;
        }
        else
        {
            fastptr = fastptr->next;
            slowptr = slowptr->next;
            current = 0;
        }
    }
    return slowptr;
}

struct node *reverse_list(struct node *current, struct node *prev)
{
    if(current == NULL)
        return prev;
    struct node *temp = current->next;
    current->next = prev;
    return reverse_list(temp, current);
}

bool palindrome(struct node *head)
{
    if(head == NULL)
        return true;
    struct node *middle = mid(head);
    middle->next = reverse_list(middle->next, NULL);
    struct node *left = head, *right = middle->next;
    while(right != NULL)
    {
        if(left->data != right->data)
            return false;
        left = left->next;
        right = right->next;
    }
    return true;
}

int main()
{
    struct node *head = NULL, *tail = NULL;
    int n, a;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>a;
        insert_node(&head, a, &tail);
    }
    cout<<palindrome(head)<<endl;
    /*struct node *temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<endl;
        temp = temp->next;
    }*/
    return 0;
}
