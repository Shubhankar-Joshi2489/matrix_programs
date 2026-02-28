#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// --- INSERTION ---
void insertAtBeginning(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) last = last->next;
    last->next = new_node;
}

void insertAtPosition(struct Node** head_ref, int new_data, int position) {
    if (position == 1) {
        insertAtBeginning(head_ref, new_data);
        return;
    }
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    struct Node* temp = *head_ref;
    for (int i = 1; i < position - 1 && temp != NULL; i++) temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range.\n");
        free(new_node);
    } else {
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

// --- DELETION ---
void deleteFromBeginning(struct Node** head_ref) {
    if (*head_ref == NULL) return;
    struct Node* temp = *head_ref;
    *head_ref = (*head_ref)->next;
    free(temp);
}

void deleteFromEnd(struct Node** head_ref) {
    if (*head_ref == NULL) return;
    if ((*head_ref)->next == NULL) {
        free(*head_ref);
        *head_ref = NULL;
        return;
    }
    struct Node* temp = *head_ref;
    while (temp->next->next != NULL) temp = temp->next;
    free(temp->next);
    temp->next = NULL;
}

void deleteValue(struct Node** head_ref, int key) {
    struct Node *temp = *head_ref, *prev = NULL;
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

// --- SEARCH & PRINT ---
void search(struct Node* head, int key) {
    struct Node* current = head;
    int pos = 1;
    while (current != NULL) {
        if (current->data == key) {
            printf("Value %d found at position %d\n", key, pos);
            return;
        }
        current = current->next;
        pos++;
    }
    printf("Value %d not found.\n", key);
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// --- REVERSE (RECURSIVE) ---
struct Node* reverseRecursive(struct Node* head) {
    if (head == NULL || head->next == NULL) return head;// 
                                                        //100  200 300 400 500
    struct Node* rest = reverseRecursive(head->next);   //[ 1 ,2  ,3  ,4,  5]
                                                        // 200 300 400 500 \0 
    head->next->next = head;                        //H-100

    head->next = NULL;

    return rest;
}

int main() {
    struct Node* head = NULL;
  int i, x, n;

    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        // Using insertAtEnd keeps the list in the order you type them
        insertAtEnd(&head, x); 
    }

    printf("Original List: ");
    printList(head);

    deleteValue(&head, 10);
    printf("After deleting 10: ");
    printList(head);

    search(head, 10);

    printf("Reversing (Recursive): ");
    head = reverseRecursive(head);
    printList(head);

    return 0;
}   