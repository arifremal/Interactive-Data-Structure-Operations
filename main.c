#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Linked List Node
struct Node {
    int data;
    struct Node* next;
};

// Stack Node
struct StackNode {
    int data;
    struct StackNode* next;
};

// Queue Node
struct QueueNode {
    int data;
    struct QueueNode* next;
};

// Binary Search Tree Node
struct BSTNode {
    int data;
    struct BSTNode* left;
    struct BSTNode* right;
};

// Function Prototypes
void displayMenu();
void arrayOperations();
void linkedListOperations();
void stackOperations();
void queueOperations();
void binarySearchTreeOperations();

// Array Operations
void insertArray(int arr[], int *size, int position, int value);
void deleteArray(int arr[], int *size, int position);
void searchArray(int arr[], int size, int value);

// Linked List Operations
void insertLinkedList(struct Node** head, int position, int value);
void deleteLinkedList(struct Node** head, int position);
void searchLinkedList(struct Node* head, int value);

// Stack Operations
void push(struct StackNode** top, int value);
void pop(struct StackNode** top);
void searchStack(struct StackNode* top, int value);

// Queue Operations
void enqueue(struct QueueNode** front, struct QueueNode** rear, int value);
void dequeue(struct QueueNode** front, struct QueueNode** rear);
void searchQueue(struct QueueNode* front, int value);

// Binary Search Tree Operations
struct BSTNode* insertBST(struct BSTNode* root, int value);
struct BSTNode* deleteBST(struct BSTNode* root, int value);
void searchBST(struct BSTNode* root, int value);
void inorderBST(struct BSTNode* root);

int main() {
    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: arrayOperations(); break;
            case 2: linkedListOperations(); break;
            case 3: stackOperations(); break;
            case 4: queueOperations(); break;
            case 5: binarySearchTreeOperations(); break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n"); break;
        }
    } while (choice != 0);
    
    return 0;
}

// Menu Display Function
void displayMenu() {
    printf("\nData Structure Operations Menu:\n");
    printf("1. Array\n");
    printf("2. Linked List\n");
    printf("3. Stack\n");
    printf("4. Queue\n");
    printf("5. Binary Search Tree\n");
    printf("0. Exit\n");
}

// Array Operations
void arrayOperations() {
    int arr[MAX_SIZE], size = 0, choice, position, value;
    do {
        printf("\nArray Operations Menu:\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Search Element\n");
        printf("0. Go Back\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter position (0 to %d): ", size);
                scanf("%d", &position);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertArray(arr, &size, position, value);
                break;
            case 2:
                printf("Enter position (0 to %d): ", size - 1);
                scanf("%d", &position);
                deleteArray(arr, &size, position);
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                searchArray(arr, size, value);
                break;
            case 0:
                break;
            default:
                printf("Invalid choice!\n");
        }

        // Display current state of the array
        printf("Array: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

    } while (choice != 0);
}

// Array Functions
void insertArray(int arr[], int *size, int position, int value) {
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = value;
    (*size)++;
}

void deleteArray(int arr[], int *size, int position) {
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

void searchArray(int arr[], int size, int value) {
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            printf("Element %d found at index %d.\n", value, i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Element %d not found in the array.\n", value);
    }
}

// Linked List Operations
void linkedListOperations() {
    struct Node* head = NULL;
    int choice, position, value;
    do {
        printf("\nLinked List Operations Menu:\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Search Element\n");
        printf("0. Go Back\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter position to insert (0 to N): ");
                scanf("%d", &position);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertLinkedList(&head, position, value);
                break;
            case 2:
                printf("Enter position to delete (0 to N-1): ");
                scanf("%d", &position);
                deleteLinkedList(&head, position);
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                searchLinkedList(head, value);
                break;
            case 0:
                break;
            default:
                printf("Invalid choice!\n");
        }

        // Display current state of the linked list
        printf("Linked List: ");
        struct Node* temp = head;
        while(temp) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");

    } while (choice != 0);
}

// Linked List Functions
void insertLinkedList(struct Node** head, int position, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if(position == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    for(int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Position out of range.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteLinkedList(struct Node** head, int position) {
    if(*head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    struct Node* temp = *head;

    if(position == 0) {
        *head = temp->next;
        free(temp);
        return;
    }

    for(int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if(temp == NULL || temp->next == NULL) {
        printf("Position out of range.\n");
        return;
    }

    struct Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

void searchLinkedList(struct Node* head, int value) {
    struct Node* temp = head;
    while(temp != NULL) {
        if(temp->data == value) {
            printf("Element %d found in the linked list.\n", value);
            return;
        }
        temp = temp->next;
    }
    printf("Element %d not found in the linked list.\n", value);
}

// Stack Operations
void stackOperations() {
    struct StackNode* top = NULL;
    int choice, value;
    do {
        printf("\nStack Operations Menu:\n");
        printf("1. Push Element\n");
        printf("2. Pop Element\n");
        printf("3. Search Element\n");
        printf("0. Go Back\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&top, value);
                break;
            case 2:
                pop(&top);
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                searchStack(top, value);
                break;
            case 0:
                break;
            default:
                printf("Invalid choice!\n");
        }

        // Display current state of the stack
        printf("Stack: ");
        struct StackNode* temp = top;
        while(temp) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");

    } while (choice != 0);
}

// Stack Functions
void push(struct StackNode** top, int value) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

void pop(struct StackNode** top) {
    if(*top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    struct StackNode* temp = *top;
    *top = (*top)->next;
    free(temp);
}

void searchStack(struct StackNode* top, int value) {
    struct StackNode* temp = top;
    while(temp != NULL) {
        if(temp->data == value) {
            printf("Element %d found in the stack.\n", value);
            return;
        }
        temp = temp->next;
    }
    printf("Element %d not found in the stack.\n", value);
}

// Queue Operations
void queueOperations() {
    struct QueueNode *front = NULL, *rear = NULL;
    int choice, value;
    do {
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue Element\n");
        printf("2. Dequeue Element\n");
        printf("3. Search Element\n");
        printf("0. Go Back\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&front, &rear, value);
                break;
            case 2:
                dequeue(&front, &rear);
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                searchQueue(front, value);
                break;
            case 0:
                break;
            default:
                printf("Invalid choice!\n");
        }

        // Display current state of the queue
        printf("Queue: ");
        struct QueueNode* temp = front;
        while(temp) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");

    } while (choice != 0);
}

// Queue Functions
void enqueue(struct QueueNode** front, struct QueueNode** rear, int value) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->data = value;
    newNode->next = NULL;

    if(*rear == NULL) {
        *front = *rear = newNode;
        return;
    }

    (*rear)->next = newNode;
    *rear = newNode;
}

void dequeue(struct QueueNode** front, struct QueueNode** rear) {
    if(*front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct QueueNode* temp = *front;
    *front = (*front)->next;

    if(*front == NULL) {
        *rear = NULL;
    }

    free(temp);
}

void searchQueue(struct QueueNode* front, int value) {
    struct QueueNode* temp = front;
    while(temp != NULL) {
        if(temp->data == value) {
            printf("Element %d found in the queue.\n", value);
            return;
        }
        temp = temp->next;
    }
    printf("Element %d not found in the queue.\n", value);
}

// Binary Search Tree Operations
void binarySearchTreeOperations() {
    struct BSTNode* root = NULL;
    int choice, value;
    do {
        printf("\nBinary Search Tree Operations Menu:\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Search Element\n");
        printf("4. Inorder Traversal\n");
        printf("0. Go Back\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insertBST(root, value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteBST(root, value);
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                searchBST(root, value);
                break;
            case 4:
                inorderBST(root);
                break;
            case 0:
                break;
            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 0);
}

// Binary Search Tree Functions
struct BSTNode* insertBST(struct BSTNode* root, int value) {
    if(root == NULL) {
        struct BSTNode* newNode = (struct BSTNode*)malloc(sizeof(struct BSTNode));
        newNode->data = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if(value < root->data) {
        root->left = insertBST(root->left, value);
    } else if(value > root->data) {
        root->right = insertBST(root->right, value);
    }

    return root;
}

struct BSTNode* deleteBST(struct BSTNode* root, int value) {
    if(root == NULL) {
        printf("Element not found in BST.\n");
        return root;
    }

    if(value < root->data) {
        root->left = deleteBST(root->left, value);
    } else if(value > root->data) {
        root->right = deleteBST(root->right, value);
    } else {
        // Node with only one child or no child
        if(root->left == NULL) {
            struct BSTNode* temp = root->right;
            free(root);
            return temp;
        } else if(root->right == NULL) {
            struct BSTNode* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children
        struct BSTNode* temp = root->right;
        while(temp && temp->left != NULL) {
            temp = temp->left;
        }

        root->data = temp->data;
        root->right = deleteBST(root->right, temp->data);
    }

    return root;
}

void searchBST(struct BSTNode* root, int value) {
    if(root == NULL) {
        printf("Element not found in BST.\n");
        return;
    }

    if(value < root->data) {
        searchBST(root->left, value);
    } else if(value > root->data) {
        searchBST(root->right, value);
    } else {
        printf("Element %d found in BST.\n", value);
    }
}

void inorderBST(struct BSTNode* root) {
    if(root == NULL) {
        return;
    }

    inorderBST(root->left);
    printf("%d ", root->data);
    inorderBST(root->right);
}

