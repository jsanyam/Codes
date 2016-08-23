#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;

struct node
{
    int data;
    struct node *left, *right, *sibling;
};

void insert_node(struct node **root)
{
    //struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *temp = new struct node;
    scanf("%d", &temp->data);
    temp->left =NULL;
    temp->right = NULL;
    temp->sibling = NULL;
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

void update_siblings(struct node *root)
{
    cout<<"hey"<<endl;
    queue<struct node *>q;
    struct node *current;
    q.push(root);
    q.push(NULL);
    cout<<"hello";
    while(!q.empty())
    {
        current = q.front();
        q.pop();
        if(current == NULL)
        {
            if(!q.empty())
                q.push(NULL);
            continue;
        }
        //current->sibling = q.front();
        //cout<<current->sibling->data<<endl;
        cout<<current->data;
        if(current->left)
            q.push(current->left);
        if(current->right)
            q.push(current->right);
    }
}

int main()
{
    struct node *root = NULL;
    for(int i = 0; i < 7; i++)
        insert_node(&root);
    cout<<root->data;
    update_siblings(root);
    //printf("%d\n", root->left->sibling->data);
    return 0;
}
