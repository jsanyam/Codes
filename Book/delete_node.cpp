#include<cstdio>
#include<iostream>
#include<queue>
#include<cstdlib>
using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};

void insert_node(struct node **root)
{
    //struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *temp = new struct node;
    scanf("%d", &temp->data);
    temp->left =NULL;
    temp->right = NULL;
    if(!(*root))
    {
        *root = temp;
        return;
    }
    queue<struct node *> q;
    q.push(*root);
    struct node *current;
    while(!q.empty())
    {
        current = q.front();
        q.pop();
        if(current->left)
            q.push(current->left);
        else
        {
            current->left = temp;
            return;
        }
        if(current->right)
            q.push(current->right);
        else
        {
            current->right = temp;
            return;
        }
    }
}

int find_deepest_node(struct node **root)
{
    queue<struct node *>q;
    struct node *temp;
    q.push(*root);
    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    int data = temp->data;
    cout<<data<<endl;
    //temp->data = 1;
    free(temp); //dangling pointers
    temp = NULL;
    return data;
}

int main()
{
    struct node *root = NULL;
    for(int i = 0; i < 7; i++)
        insert_node(&root);
    int data = find_deepest_node(&root);
    printf("%d\n", data);
    //free(temp);
    int data2 = find_deepest_node(&root);
    printf("%d\n", data2);
    return 0;
}
