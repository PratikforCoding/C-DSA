#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node node;

node *create_node(int value) {
    node *new = (node *)malloc(sizeof(node));
    new->data = value;
    new->left = NULL;
    new->right = NULL;

    return new;
}

//INORDER TRAVERSAL
void inorder(node *root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    printf("%d  " ,root->data);
    inorder(root->right);

}

//PREORDER TRAVERSAL
void preorder(node *root) {
    if (root == NULL) {
        return;
    }

    printf("%d  " ,root->data);
    preorder(root->left);
    preorder(root->right);

}

//POSTORDER TRAVERSAL
void postorder(node *root) {
    if(root == NULL){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%d  ",root->data);

}

//INSERTION
node *insertion(node *root, int value) {
    if (root == NULL){
        return create_node(value);
    }

    if (value < root->data) {
        root->left = insertion(root->left, value);
    } 
    if (value > root->data) {
        root->right = insertion(root->right,value);
    }   
    return root;
}

//TO FIND THE MINIMUM INORDER SUCCESSION
node *minimum(node *p) {
    node *current = p;

    while(current && current->left != NULL) {
        current = current->left;
    }

    return current;
}

//DELETION 
node *deletion(node *root,int value) {
    if (root == NULL) {
        return root;
    }

    if (value < root->data) {
        root->left = deletion(root->left,value);
    
    } else if (value > root->data) {
        root->right = deletion(root->right,value);

    } else {

        if(root->left == NULL) {
            node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            node *temp = root->left;
            free(root);
            return temp;
        }

        node *temp = minimum(root->right);

        root->data = temp->data;
        root->right = deletion(root->right, temp->data);
    }

    return root;
    
}

int main() {
    node *root = create_node(8);
    root = insertion(root, 3);
    root = insertion(root, 10);
    root = insertion(root, 1);
    root = insertion(root, 6);
    root = insertion(root, 4);
    root = insertion(root, 7);
    root = insertion(root, 14);

    inorder(root);

    root = deletion(root, 6);
    printf("\n");
    inorder(root);
    root = insertion(root, 6);
    printf("\n");
    inorder(root);
    root = deletion(root,3);
    printf("\n");
    inorder(root);
    root = insertion(root, 3);
    printf("\n");
    inorder(root);
    return 0;
}


