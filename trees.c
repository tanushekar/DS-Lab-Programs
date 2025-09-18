/*
  Binary Search Tree:
  1.Construction
  2.Traversals (DFS and BFS) 
  3.Searching a node by key and displaying its info along with its parent if exists, otherwise a suitable message 
  4.Counting all nodes 
  5.Finding height 
  6.Finding node with the maximum key value and printing the node details along with the parent 
  7.Searching a node by key and deleting if it exists (node to be deleted may be leaf or non-leaf with one child or two children) 
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node *Node;

Node getnode(int value)
{
    Node newnode= (Node)malloc(sizeof(struct node));
    newnode->data= value;
    newnode->right= newnode->left= NULL;
    return newnode;
}

Node insert(Node root, int value)
{
    if(root==NULL)
    {
        return getnode(value);
    }
    if(value== root->data)
    {
        printf("Node already exists\n");
        return root;
    }
    
    if(value<root->data)
    {
        root->left= insert(root->left, value); 
    }
    else
    {
        root->right= insert(root->right, value);
    }

    return root; 
}

//Traversal (DFS)
void inorder(Node root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void preorder(Node root)
{
    if(root!=NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
        
}
void postorder(Node root)
{
    if(root!=NULL)
    {
       postorder(root->left);
       postorder(root->right);
       printf("%d ", root->data);
    }
}

//Level Order Traversal (BFS)
void levelOrder(Node root)
{
    if(root==NULL)
    {
        return;
    }
    Node queue[100];   
    int front=0;
    int rear=0;

    queue[rear++]=root;
    while(front<rear)
    {
        Node current= queue[front++];
        printf("%d ",current->data); 

        if(current->left!=NULL)
        {
            queue[rear++]= current->left;
        }
        if(current->right!=NULL)
        {
            queue[rear++]=current->right;
        }
    }
}

Node search(Node root, int key)
{
    if(root==NULL || root->data==key)
    {
        return root;
    }
    if(key<root->data)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
}

Node findParent(Node root, int key)
{
    if(root==NULL || root->left!=NULL&&root->left->data==key || root->right!=NULL && root->right->data==key)
    {
        return root;
    }
    if(key<root->data)
    {
        return findParent(root->left, key);
    }
    else
    {
        return findParent(root->right, key);
    }
}

int countNodes(Node root)
{
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        return 1+ countNodes(root->left)+ countNodes(root->right);
    }
}

int height(Node root)
{
    if(root==NULL)
    {
        return -1;
    }
    else
    {
        int leftHeight= height(root->left);
        int rightHeight= height(root->right);
        return (leftHeight>rightHeight ? leftHeight : rightHeight)+1;
    }
}

Node maximum(Node root)
{
    while(root && root->right!= NULL)
    {
        root= root->right;
    }
    return root;
}

Node minimum(Node root)
{
    while(root && root->left!= NULL)
    {
        root= root->left;
    }
    return root;
}

Node delete(Node root, int key)
{
    //to search node with key
    if(root==NULL)
    {
        return root;
    }
    
    if(key < root->data)
    {
        root->left= delete(root->left, key);
    }
    else if(key > root->data)
    {
        root->right= delete(root->right, key);
    }
    else    //root->data==key
    {
        if(root->left==NULL)
        {
            Node temp= root->right;  
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            Node temp= root->left;
            free(root);
            return temp;
        }
        
        /*else if(root->right==NULL&&root->left==NULL)
        return NULL;*/

        Node temp= maximum(root->left);
        root->data= temp->data;
        root->left= delete(root->left, temp->data);
    }
    return root; 
}

void main()
{
    Node root=NULL;

    int choice, X;
    for(;;)
    {
        printf("\n-----MENU-----\n1.Insert\t\t\t2.Preorder\n");
        printf("3.Inorder\t\t\t4.Postorder\n");
        printf("5.Level Order\t\t\t6.Search node\n");
        printf("7.Count nodes\t\t\t8.Height\n");
        printf("9.Maximum\t\t\t10.Delete\n");
        printf("11.Minimum\n12.EXIT\n");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf("Enter key to be inserted: ");
                    scanf("%d", &X);
                    root=insert(root, X);
                    printf("Insertion successful!");
                    break;
                    
            case 2: printf("Preorder Traversal: ");
                    preorder(root);
                    break;
                    
            case 3: printf("Inorder Traversal: ");
                    inorder(root);
                    break;
                    
            case 4: printf("Postorder Traversal: ");
                    postorder(root);
                    break;
                    
            case 5: printf("Level order traversal: ");
                    levelOrder(root);
                    break;
                    
            case 6: printf("Enter key to be searched: ");
                    scanf("%d", &X);
                    Node found= search(root, X);

                    if(found!=NULL)
                    {
                        printf("Node found:%d\n", found->data);

                        Node parent= findParent(root, X);
                        if(parent!=NULL)
                        {
                            printf("Parent: %d\n", parent->data);
                        }
                        else
                        {
                            printf("It is the root node\n");
                        }
                    }
                    else
                    {
                        printf("Key not found..\n");
                    }
                    break;
                    
            case 7: printf("Total number of nodes:%d\n", countNodes(root));
                    break;
                    
            case 8: printf("Height of tree: %d\n", height(root));
                    break;
                    
            case 9: {                                    
                      Node maxnode= maximum(root);
                     if(maxnode!=NULL)
                     {
                        printf("Maximum node: %d\n", maxnode->data);
                        Node parent= findParent(root, maxnode->data);
                        if(parent!=NULL)
                        {
                            printf("Parent:%d\n", parent->data);
                        }
                        else
						{
                            printf("The node is a root\n");
                        }
                     }
                     else
                        printf("Tree is empty\n");
                    }
                    break;
                    
            
            case 10: printf("Enter key to be deleted: ");
                     scanf("%d", &X);
                     Node node= search(root, X);
                     if(node!=NULL)
                     {
                        root= delete(root, node->data);
                        printf("Node is deleted: %d\n", node->data);
                     }
                     if(node==NULL)
                     {
                        printf("Doesn't exist\n");
                     }
                    
                    break;
            
            case 11: {                                    
                       Node minnode= minimum(root);
                       if(minnode!=NULL)
                       {
                          printf("Minimum node: %d\n", minnode->data);
                          Node parent= findParent(root, minnode->data);
                          if(parent!=NULL)
                          {
                            printf("Parent:%d\n", parent->data);
                          }
                          else
						  {
                            printf("The node is a root\n");
                          }
                       }
                     else
                        printf("Tree is empty\n");
                     }
                     break;
                   
            case 12: printf("Exiting\n");
                     exit(0);
                     
            default: printf("Invalid position\n");
        }
    }
}