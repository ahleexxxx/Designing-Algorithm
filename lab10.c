#include "lab10.h"

// suggested implementation
typedef struct Node Node;

struct Node {
	int data;
	Node *left;
	Node *right;
};

struct BST{
	Node *root;
	int size;
} ;



// O(1)
/*The function returns an empty BST pointer on success, or NULL on failure.*/
BST * initBST()
{
    BST* tree=malloc(sizeof(BST));
    if(tree==NULL){
        printf("ERROR: memory allocation error!\n");
        return NULL;
    }

    tree->root=NULL;
    tree->size=0;

    return tree;
}


/*This function is a helper function for insertBST.
This function will take a root pointer and a new node that we want to insert in BST*/
Node* insertBSTHelper(Node* root, Node* newNode){
    if(root==NULL){
        return newNode;
    }

    else if(newNode->data < root->data){
        root->left=insertBSTHelper(root->left, newNode);
    }

    else if(newNode-> data > root->data){
        root->right=insertBSTHelper(root->right, newNode);
    }

    return root;
}

// O(log(n))
/*This function takes a BST pointer, and an integer to insert in BST. 
It will return 0 on success, or 1 if failed.*/
int insertBST(BST *tree, int data)
{
    Node* newNode=malloc(sizeof(Node));
    if(newNode==NULL){
        printf("ERROR: memory allocation error!\n");
        return 1;
    }
    newNode->left=NULL;
    newNode->right=NULL;
    newNode->data=data;

    tree->root=insertBSTHelper(tree->root, newNode);
    tree->size++;
    return 0;
}



// O(log(n))
/*This function takes a BST pointer, and an integer to search for in BST. 
It will return 0 if the integer is NOT found in BST, or 1 if found.*/
int BSTContains(BST *tree, int data)
{
    Node* ptr=tree->root;
    while(ptr != NULL){
        if(data < ptr->data){
            ptr=ptr->left;
        }

        else if(data > ptr->data){
            ptr=ptr->right;
        }

        else{
            return 1;   //success
        }
    }

    return 0;   //failed

}

/*This function is helper function for freeTree.
This function will take the root of the tree and free every node in the tree.*/
void freeTreeHelper(Node* node){
    if(node != NULL){
        freeTreeHelper(node->left);
        freeTreeHelper(node->right);
        free(node);
    }
    return;
}

// O(n)
/*This function will take a BST pointer, and free all memory allocated to the tree.*/
void freeTree(BST *tree)
{
    freeTreeHelper(tree->root);
    free(tree);

}



/*This function is a helper function for printInOrder.
This function will take the root of the tree and use recursion to print in inorder.*/
void printInOrderHelper(Node* root)
{
    if(root !=NULL){
        printInOrderHelper(root->left);
        printf("[%d] ", root->data);
        printInOrderHelper(root->right);
    }
}
    
// O(n)
/*This function will take a BST pointer, print all of the elements of the tree in order*/
void printInOrder(BST *tree)
{   
    printf("\n\n---print Inorder of BST---\n");
    printInOrderHelper(tree->root);
    printf("\n--------------------------\n");
}



// O(log(n))
/*This function will take a BST pointer, return the maximum element in the tree. You may assume the tree will not be empty.*/
int getMax(BST *tree)
{
    Node* ptr=tree->root;
    int data;

    while(ptr-> right !=NULL){
        ptr=ptr->right;
    }
    
    data=ptr->data;
    return data;
}


