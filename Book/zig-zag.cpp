#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
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

void zig_zag(struct node *root)
{
    stack<struct node *>s1, s2, temp;
    int ltor = 1;
    s1.push(root);
    struct node *current;
    while(!s1.empty() || !s2.empty())
    {
        if(ltor)
        {
            current = s1.top();
            printf("%d ", current->data);
            s1.pop();
            if(current->left)
                s2.push(current->left);
            if(current->right)
                s2.push(current->right);
            if(s1.empty())
                ltor = 1 - ltor;
        }
        else
        {
            current = s2.top();
            printf("%d ", current->data);
            s2.pop();
            if(current->right)
                s1.push(current->right);
            if(current->left)
                s1.push(current->left);
            if(s2.empty())
                ltor = 1 - ltor;
        }
    }
}

int main()
{
    struct node *root = NULL;
    for(int i = 0; i < 7; i++)
        insert_node(&root);
    zig_zag(root);
    return 0;
}
