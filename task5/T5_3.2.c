#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

void addNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void deleteNode(struct Node** head, int data) {
    if (*head == NULL) {
        printf("Linked list is empty\n");
        return;
    }

    if ((*head)->data == data) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        printf("Node with data %d deleted\n", data);
        return;
    }

    struct Node* prev = *head;
    struct Node* current = (*head)->next;
    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Node with data %d not found\n", data);
        return;
    }

    prev->next = current->next;
    free(current);
    printf("Node with data %d deleted\n", data);
}

// Function to print the linked list
void printList(struct Node* head) {
    if (head == NULL) {
        printf("Linked list is empty\n");
        return;
    }

    printf("Linked list: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    char input;
    int data;

    printf("Enter '+' to add a node, '-' to delete a node, 'p' to print the list, or 'x' to exit:\n");
    while (1) {
        printf("Enter input: ");
        scanf(" %c", &input);

        switch (input) {
            case '+':
                printf("Enter data: ");
                scanf("%d", &data);
                addNode(&head, data);
                break;
            case '-':
                printf("Enter data: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 'p':
                printList(head);
                break;
            case 'x':
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid input. Try again.\n");
        }
    }

    return 0;
}