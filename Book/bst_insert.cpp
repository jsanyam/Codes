#include<cstdio>
#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};

struct node *insert_node(struct node *root, int data)
{
    if(root == NULL)
    {
        root = new struct node;
        root->data = data;
        root->left = root->right = NULL;
        return root;
    }
    if(data < root->data)
        root->left = insert_node(root->left, data);
    else
        root->right = insert_node(root->right, data);
    return root;
}

void print_inorder(struct node *root)
{
    if(root == NULL)
        return;
    print_inorder(root->left);
    printf("%d ", root->data);
    print_inorder(root->right);
}

struct node *find_max(struct node *root)
{
    if(root->right == NULL)
        return root;
    return find_max(root->right);
}

struct node *find_min(struct node *root)
{
    if(root->left == NULL)
        return root;
    return find_min(root->left);
}

void delete_node(struct node *root)
{
    if(root == NULL)
    if(root->left == NULL && root->right == NULL)
    {
        free(root)
        return NULL;
    }
    if()
}

int main()
{
    struct node *root = NULL;
    int data;
    for(int i = 0; i < 7; i++)
    {
        scanf("%d", &data);
        root = insert_node(root, data);
    }
    print_inorder(root);
    printf("\nMax element is: %d\n", find_max(root)->data);
    printf("Min element is: %d\n", find_min(root)->data);
    return 0;
}
