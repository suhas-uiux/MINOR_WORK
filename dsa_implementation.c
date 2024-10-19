#include <stdio.h>
#include <stdlib.h>

#define N 5
int a[N];
int top = -1;
int front = -1;
int rear = -1;

//--------------------stack------------------------------------

void stack_in()
{
    int x;
    if (top == N - 1)
    {
        printf("\nStack overflow\n");
    }
    else
    {
        printf("\nEnter the value to be pushed: ");
        scanf("%d", &x);
        top++;
        a[top] = x;
        printf("Pushed: %d\n", x);
    }
}

void stack_out()
{
    if (top == -1)
    {
        printf("\nUnderflow: stack is empty\n");
    }
    else
    {
        int item = a[top];
        top--;
        printf("Popped: %d\n", item);
    }
}

void display_stack()
{
    if (top == -1)
    {
        printf("\nStack is empty\n");
    }
    else
    {
        printf("\nStack elements:\n");
        for (int i = top; i >= 0; i--)
        {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
}

//---------------------------queue----------------------------

void queue_insert()
{
    int x;
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
        printf("\nEnter the value to insert: ");
        scanf("%d", &x);
        a[rear] = x;
    }
    else if (((rear + 1) % N) == front)
    {
        printf("\nQueue full\n");
    }
    else
    {
        rear = (rear + 1) % N;
        printf("\nEnter the value to insert: ");
        scanf("%d", &x);
        a[rear] = x;
    }
}

void queue_delete()
{
    if (front == -1 && rear == -1)
    {
        printf("\nQueue empty\n");
    }
    else
    {
        printf("\nDeleted element: %d\n", a[front]);
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % N;
        }
    }
}

void display_queue()
{
    if (front == -1 && rear == -1)
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        printf("\nQueue elements:\n");
        int i = front;
        while (i != rear)
        {
            printf("%d ", a[i]);
            i = (i + 1) % N;
        }
        printf("%d\n", a[rear]);
    }
}

//---------------------------singly linked list----------------------------

struct Node
{
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void singly_insert()
{
    int x;
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    printf("\nEnter the value to insert in Singly Linked List: ");
    scanf("%d", &x);
    new_node->data = x;
    new_node->next = head;
    head = new_node;
    printf("%d inserted in the list\n", x);
}

void singly_delete()
{
    if (head == NULL)
    {
        printf("\nSingly Linked List is empty\n");
    }
    else
    {
        struct Node* temp = head;
        head = head->next;
        printf("Deleted element: %d\n", temp->data);
        free(temp);
    }
}

void display_singly()
{
    struct Node* temp = head;
    if (temp == NULL)
    {
        printf("\nSingly Linked List is empty\n");
    }
    else
    {
        printf("\nSingly Linked List elements:\n");
        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

//---------------------------doubly linked list----------------------------

struct DNode
{
    int data;
    struct DNode* prev;
    struct DNode* next;
};

struct DNode* dhead = NULL;

void doubly_insert()
{
    int x;
    struct DNode* new_node = (struct DNode*)malloc(sizeof(struct DNode));
    printf("\nEnter the value to insert in Doubly Linked List: ");
    scanf("%d", &x);
    new_node->data = x;
    new_node->prev = NULL;
    new_node->next = dhead;
    if (dhead != NULL)
    {
        dhead->prev = new_node;
    }
    dhead = new_node;
    printf("%d inserted in the list\n", x);
}

void doubly_delete()
{
    if (dhead == NULL)
    {
        printf("\nDoubly Linked List is empty\n");
    }
    else
    {
        struct DNode* temp = dhead;
        dhead = dhead->next;
        if (dhead != NULL)
        {
            dhead->prev = NULL;
        }
        printf("Deleted element: %d\n", temp->data);
        free(temp);
    }
}

void display_doubly()
{
    struct DNode* temp = dhead;
    if (temp == NULL)
    {
        printf("\nDoubly Linked List is empty\n");
    }
    else
    {
        printf("\nDoubly Linked List elements:\n");
        while (temp != NULL)
        {
            printf("%d <-> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

//---------------------------binary search tree----------------------------

struct BSTNode
{
    int data;
    struct BSTNode* left;
    struct BSTNode* right;
};

struct BSTNode* bstroot = NULL;

struct BSTNode* bst_insert(struct BSTNode* node, int data)
{
    if (node == NULL)
    {
        struct BSTNode* new_node = (struct BSTNode*)malloc(sizeof(struct BSTNode));
        new_node->data = data;
        new_node->left = new_node->right = NULL;
        return new_node;
    }
    if (data < node->data)
    {
        node->left = bst_insert(node->left, data);
    }
    else
    {
        node->right = bst_insert(node->right, data);
    }
    return node;
}

struct BSTNode* find_min(struct BSTNode* node)
{
    while (node->left != NULL)
        node = node->left;
    return node;
}

struct BSTNode* bst_delete(struct BSTNode* node, int data)
{
    if (node == NULL)
        return node;

    if (data < node->data)
        node->left = bst_delete(node->left, data);
    else if (data > node->data)
        node->right = bst_delete(node->right, data);
    else
    {
        if (node->left == NULL)
        {
            struct BSTNode* temp = node->right;
            free(node);
            return temp;
        }
        else if (node->right == NULL)
        {
            struct BSTNode* temp = node->left;
            free(node);
            return temp;
        }

        struct BSTNode* temp = find_min(node->right);
        node->data = temp->data;
        node->right = bst_delete(node->right, temp->data);
    }
    return node;
}

void inorder_display(struct BSTNode* node)
{
    if (node == NULL)
        return;

    inorder_display(node->left);
    printf("%d ", node->data);
    inorder_display(node->right);
}

//---------------------------main------------------------------------------//

int main()
{
    int w, x, y, z, data;
    do
    {
        printf("\nPress 1 to open: ");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            do
            {
                printf("\nWelcome! Choose your implementation:\n");
                printf("1: Stack\n2: Queue\n3: Singly Linked List\n4: Doubly Linked List\n5: Binary Search Tree\n");
                printf("Enter the implementation you want to perform: ");
                scanf("%d", &y);
                switch (y)
                {
                case 1:
                    do
                    {
                        printf("\nStack implementation\n");
                        printf("1: Stack insert\n2: Stack delete\n3: Display Stack\n");
                        printf("Enter the choice: ");
                        scanf("%d", &z);
                        switch (z)
                        {
                        case 1:
                            stack_in();
                            break;
                        case 2:
                            stack_out();
                            break;
                        case 3:
                            display_stack();
                            break;
                        }
                    } 
                    while (z != 0);
                    break;
                case 2:
                    do
                    {
                        printf("\nQueue implementation\n");
                        printf("1: Queue insert\n2: Queue delete\n3: Display Queue\n");
                        printf("Enter the choice: ");
                        scanf("%d", &w);
                        switch (w)
                        {
                        case 1:
                            queue_insert();
                            break;
                        case 2:
                            queue_delete();
                            break;
                        case 3:
                            display_queue();
                            break;
                        }
                    } 
                    while (w != 0);
                    break;
                case 3:
                    do
                    {
                        printf("\nSingly Linked List implementation\n");
                        printf("1: Singly insert\n2: Singly delete\n3: Display Singly Linked List\n");
                        printf("Enter the choice: ");
                        scanf("%d", &w);
                        switch (w)
                        {
                        case 1:
                            singly_insert();
                            break;
                        case 2:
                            singly_delete();
                            break;
                        case 3:
                            display_singly();
                            break;
                        }
                    } 
                    while (w != 0);
                    break;
                case 4:
                    do
                    {
                        printf("\nDoubly Linked List implementation\n");
                        printf("1: Doubly insert\n2: Doubly delete\n3: Display Doubly Linked List\n");
                        printf("Enter the choice: ");
                        scanf("%d", &w);
                        switch (w)
                        {
                        case 1:
                            doubly_insert();
                            break;
                        case 2:
                            doubly_delete();
                            break;
                        case 3:
                            display_doubly();
                            break;
                        }
                    } 
                    while (w != 0);
                    break;
                case 5:
                    do
                    {
                        printf("\nBinary Search Tree implementation\n");
                        printf("1: Insert in BST\n2: Delete from BST\n3: In-order Display of BST\n");
                        printf("Enter the choice: ");
                        scanf("%d", &w);
                        switch (w)
                        {
                        case 1:
                            printf("\nEnter value to insert in BST: ");
                            scanf("%d", &data);
                            bstroot = bst_insert(bstroot, data);
                            break;
                        case 2:
                            printf("\nEnter value to delete from BST: ");
                            scanf("%d", &data);
                            bstroot = bst_delete(bstroot, data);
                            break;
                        case 3:
                            printf("\nIn-order traversal of BST: ");
                            inorder_display(bstroot);
                            printf("\n");
                            break;
                        }
                    } 
                    while (w != 0);
                    break;
                }
            } 
            while (y != 0);
            break;
        }
    } 
    while (x != 0);

    return 0;
}
