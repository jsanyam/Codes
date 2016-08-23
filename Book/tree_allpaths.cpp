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

void print_path(int path[], int path_len)
{
    for(int i = 0; i < path_len; i++)
        printf("%d ", path[i]);
    printf("\n");
}


void tree_paths(struct node *root, int path[], int path_len)
{
    if(root)
    {
        path[path_len++] = root->data;
        if(root->left == NULL && root->right == NULL)
            print_path(path, path_len);
        else
        {
            tree_paths(root->left, path, path_len);
            tree_paths(root->right, path, path_len);
        }
    }
}

int main()
{
    struct node *root = NULL;
    for(int i = 0; i < 7; i++)
        insert_node(&root);
    int path[7];
    tree_paths(root, path, 0);
    return 0;
}
