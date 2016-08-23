#include<cstdio>
#include<iostream>
#include<queue>
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

int is_mirror(struct node *root1 , struct node *root2)
{
    if(!root1 && !root2)
        return 1;
    else if((!root1 && root2) || (root1 && !root2))
        return 0;
    return ((root1->data == root2->data) && is_mirror(root1->left, root2->right) && is_mirror(root1->right, root2->left));
}

int main()
{
    struct node *root1 = NULL, *root2 = NULL;
    for(int i = 0; i < 7; i++)
        insert_node(&root1);
    for(int i = 0; i < 6; i++)
        insert_node(&root2);
    if(is_mirror(root1, root2))
        printf("Trees are mirror image of each other\n");
    else
        printf("Trees are not mirror image of each other\n");
    return 0;
}
