#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{

int value;

struct node* left;
struct node* right;
}node;

node * CreateNode(int value);
void CreateTree0();
void CreateTree1(int value);
void AddNodeNode(node * temp, node * insert);
void AddNodeInt(node * temp, int value);
node * deleteNode(node* root, int key);
bool TraverseFind(node * temp, int value);
void TraversePrint(node * start, int space);
node * findMinimum(node * temp);

node * start;
int option;

int main (){


	while (option != 7){
	int value = 0;
	int query = 0;
	bool found = false;


	printf("MENU\n\n");
	printf("Print Functions:\n");
	printf("0. Create Tree 0\n");
	printf("1. Create Tree 1\n");
	printf("2. Add Node Node\n");
	printf("3. Add Node Int\n");
	printf("4. Delete Node (Int)\n");
	printf("5. Traverse Find (Int)\n");
	printf("6. Traverse Print\n");

	printf("7. Quit\n");

	scanf("%d", &option);

		switch (option){

			case 0:
			CreateTree0();
			break;
			
			case 1:
			printf("Please enter an integer\n");
			scanf("%d",&value);
			CreateTree1(value);
			break;
			
			case 2:
			printf("Please enter an integer\n");
			scanf("%d",&value);
			node * insert = CreateNode(value);
			AddNodeNode(start, insert);
			//free(insert);
			break;

			case 3:
			printf("Please enter an integer\n");
			scanf("%d",&value);
			AddNodeInt(start, value);
			break;

			case 4:
			printf("Please enter the value of the node you want to delete.\n");
			scanf("%d",&value);
			deleteNode(start, value);
			break;

			case 5:
			printf("Please enter the value that you want to find.\n");
			scanf("%d",&query);
			found = TraverseFind(start, query);
			printf("The value is in the tree: %s\n", found ? "true" : "false");
			break;

			case 6:
			printf("Beginning of Tree\n\n");
			TraversePrint(start, 1);
			printf("\nEnd of Tree\n\n");
			break;

			default:
			printf("Function not run\n");
			break;

		}

	}


}

//Create Empty Tree
void CreateTree0(){

	start = NULL;

}

//Create Tree with one node
void CreateTree1(int value){

	start = CreateNode(value);

}


//Create Node
node * CreateNode(int value){

	node * p = (node *)malloc(sizeof(node));
	p->value = value;

	p->left = NULL;
	p->right = NULL;
}

//Add Node Node
void AddNodeNode(node * temp, node * insert){

	if (start == NULL){

		printf("Tree is empty. No nodes added\n");

	}else{

		if (insert->value == temp->value){

			printf("Node with the same value exists. Node not inserted.\n");

		}else if(insert->value < temp->value){

			//left link
			if (temp->left == NULL){
			
				temp->left = insert;

			}else{

				AddNodeNode(temp->left, insert);

			}
			
		}else{

			//right link
			if (temp->right == NULL){
			
				temp->right = insert;

			}else{

				AddNodeNode(temp->right, insert);

			}
		}
	}
		
}

//Add Node Integer
void AddNodeInt(node * temp, int value){

	if (start == NULL){

		CreateTree1(value);
		printf("Tree was previously empty. Tree is now created.\n");

	}else{

		if (value == temp->value){

			printf("Node with the same value exists. Node not inserted.\n");

		}else if(value < temp->value){

			//left link
			if (temp->left == NULL){
			
				node * insert = CreateNode(value);
				temp->left = insert;

			}else{

				AddNodeInt(temp->left, value);

			}
			
		}else{

			//right link
			if (temp->right == NULL){
			
				node * insert = CreateNode(value);
				temp->right = insert;

			}else{

				AddNodeInt(temp->right, value);

			}
		}
	}
		
}

//Delete Node
//Code From https://www.geeksforgeeks.org/binary-search-tree-set-2-delete/
struct node* deleteNode(struct node* root, int key) 
{ 
    // base case 
    if (root == NULL) return root; 
  
    // If the key to be deleted is smaller than the root's key, 
    // then it lies in left subtree 
    if (key < root->value) 
        root->left = deleteNode(root->left, key); 
  
    // If the key to be deleted is greater than the root's key, 
    // then it lies in right subtree 
    else if (key > root->value) 
        root->right = deleteNode(root->right, key); 
  
    // if key is same as root's key, then This is the node 
    // to be deleted 
    else
    { 
        // node with only one child or no child 
        if (root->left == NULL) 
        { 
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        } 
  
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        struct node* temp = findMinimum(root->right); 
  
        // Copy the inorder successor's content to this node 
        root->value = temp->value; 
  
        // Delete the inorder successor 
        root->right = deleteNode(root->right, temp->value); 
    } 
    return root; 
} 

//Traverse Find
bool TraverseFind(node * temp, int value){

	if (start == NULL){

		printf("No tree exists yet or there is no node in tree.\n");
		printf("Please Create a tree with:\n");
		printf("1. Create Tree 1\n");
		printf("On the menu screen\n\n");
		return false;

	}else{

		if (value == temp->value){

			return true;

		}else if(value < temp->value){

			//left link
			if (temp->left == NULL){
			
				return false;

			}else{

				TraverseFind(temp->left, value);

			}
			
		}else{

			//right link
			if (temp->right == NULL){
			
				return false;

			}else{

				TraverseFind(temp->right, value);

			}
		}
	}

}
//Traverse Print
void TraversePrint(node * start, int space){

	if (start == NULL){

		printf("The tree is empty\n");

	}else{

		node * temp = start;

		if (temp->left !=NULL)
		TraversePrint(temp->left, space + 1);
		
		for(int i = 0; i < space; i++){
			printf("\t");
		}

		printf("%d\n",temp->value);

		if (temp->right !=NULL)
		TraversePrint(temp->right, space + 1);

	}
}

//Find MInimum VAlue in subtree
node * findMinimum(node * temp){

	while (temp->left != NULL)
	temp = temp->left;

return temp;


}

