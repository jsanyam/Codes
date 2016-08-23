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

void recur_sibling(struct node *root)
{
    if(!root)
        return;
    if(root->left)
        root->left->sibling = root->right;
    if(root->sibling && root->right)
        root->right->sibling = root->sibling->left;
    recur_sibling(root->left);
    recur_sibling(root->right);
}

void update_siblings(struct node *root)
{
    queue<struct node *>q;
    struct node *current;
    q.push(root);
    q.push(NULL);
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
        current->sibling = q.front();
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
    update_siblings(root);
    printf("%d\n", root->left->sibling->data);
    return 0;
}
