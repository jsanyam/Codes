#include<cstdio>
#include<iostream>
#include<queue>
#include<climits>
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

int find_heigh(struct node *root)
{
    if(!root)
        return 0;
    int level = 0;
    queue<struct node *> q;
    struct node *temp;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        //cout<<temp->data<<endl;
        if(temp == NULL)
        {
            if(!q.empty())
                q.push(NULL);
            level++;
        }
        else
        {
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
    return level;
}

int main()
{
    struct node *root = NULL;
    for(int i = 0; i < 8; i++)
        insert_node(&root);
    printf("%d\n", find_heigh(root));
    return 0;
}
