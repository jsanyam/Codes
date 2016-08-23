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

int sum_exists(struct node *root, int sum, int given_sum)
{
    if(root)
    {
        sum = sum + root->data;
        if(root->left == NULL && root->right == NULL)
        {
            if(sum == given_sum)
                return 1;
        }
        else
        {
            return (sum_exists(root->left, sum , given_sum) || sum_exists(root->right, sum, given_sum));
        }
    }
    return 0;
}

int main()
{
    struct node *root = NULL;
    for(int i = 0; i < 4; i++)
        insert_node(&root);
    if(sum_exists(root, 0, 4))
        printf("Sum Exists\n");
    else
        printf("Sum does not exist");
    return 0;
}
