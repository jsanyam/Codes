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

struct node *ceil(struct node *root, int data)
{
    struct node *cl;
    if(root == NULL)
        return NULL;
    else if(root->data == data)
        return root;
    else if(root->data > data)
    {
        cl = ceil(root->left, data);
        if(!cl)
            cl = root;
    }
    else
        cl = ceil(root->right, data);
    return cl;
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
    struct node *cl = ceil(root, 12);
    if(!cl)
        printf("Ceil does not exist in the tree");
    else
        printf("Ceil of the given node is: %d", cl->data);
    return 0;
}

