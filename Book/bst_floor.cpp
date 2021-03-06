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
    else if(data >= root->data)
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

struct node *floor(struct node *root, int data)
{
    struct node *flr;
    if(root == NULL)
        return NULL;
    else if(root->data == data)
        return root;
    else if(root->data > data)
        flr = floor(root->left, data);
    else
    {
        flr = floor(root->right, data);
        if(!flr)
            flr = root;
    }
    return flr;
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
    struct node *flr = floor(root, 12);
    if(!flr)
        printf("Floor does not exist in the tree");
    else
        printf("Floor of the given node is: %d", flr->data);
    return 0;
}
