#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
	struct node*left;
	struct node*right;
};
typedef struct node BST;
int flag;

struct node*insert(struct node*r, int x)
{
	if (r == NULL)
	{
	    r = (struct node*)malloc(sizeof(struct node));
	    r->info = x;
	    r->left = r->right = NULL;
	    return r;
	}
	else if (x < r->info)
	    r->left = insert(r->left, x);
	else if (x > r->info)
	    r->right = insert(r->right, x);
	return r;
}

void inorder(struct node *t)
{
    if (t->left != NULL)
	inorder(t->left);
    printf("%d -> ", t->info);
    if (t->right != NULL)
	inorder(t->right);
}

void preorder(struct node *t)
{
    printf("%d -> ", t->info);
    if (t->left != NULL)
	preorder(t->left);
    if (t->right != NULL)
	preorder(t->right);
}

void postorder(struct node *t)
{
    if (t->left != NULL)
	postorder(t->left);
    if (t->right != NULL)
	postorder(t->right);
    printf("%d -> ", t->info);
}


int main()
{
    struct node* root = NULL;
    int x, c = 1, z;
    int element;
    char ch;
    printf("\nEnter an element: ");
    scanf("%d", &x);
    root = insert(root, x);
    printf("\nDo you want to enter another element :y or n");
    scanf(" %c",&ch);
    while (ch == 'y')
    {
        printf("\nEnter an element:");
        scanf("%d", &x);
        root = insert(root,x);
        printf("\nPress y or n to insert another element: y or n: ");
        scanf(" %c", &ch);
    }
    while(1)
    {
        printf("\n1 Insert an element ");
        printf("\n2 inorder traversal ");
	printf("\n3 preorder traversal");
	printf("\n4 post order traversal");
	printf("\n5 Exit");
	printf("\nEnter your choice: ");
	scanf("%d", &c);
	switch(c)
	{
	    case 1:
		printf("\nEnter the item:");
		scanf("%d", &z);
		root = insert(root,z);
		break;
	    case 2: inorder(root) ;
		break;
	    case 3 : preorder(root) ;
		break;
	    case 4 : postorder(root) ;
		break;
	    case 5:
		printf("\nExiting...");
		return;
	    default:
                printf("Enter a valid choice: ");
 
        }
    }
    return 0;
}
