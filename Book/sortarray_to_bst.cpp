#include<cstdio>
#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};

struct node *arr_to_bst(struct node *root, int arr[], int first, int last)
{
    if(first > last)
        return NULL;
    int mid = first + (last - first) / 2;
    root = new struct node;
    root->data = arr[mid];
    root->left = root->right = NULL;
    root->left = arr_to_bst(root->left, arr, first, mid - 1);
    root->right = arr_to_bst(root->right, arr, mid + 1, last);
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

int main()
{
    int arr[] = {0, 1, 2, 3, 5, 6};
    struct node *root = NULL;
    root = arr_to_bst(root, arr, 0, 5);
    print_inorder(root);
    return 0;
}
