#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head;

void CreateHeadNode();
void InsertNode();
void DeleteNode();
void DisplayNodes();
void SearchNode();
void SortNodes();

void main() {
    int choice;
    printf("\n\n---------- Linked list -----------\n");
    CreateHeadNode();
    do{
        printf("\n\n1. Insert a node\n");
        printf("2. Delete a node\n");
        printf("3. Display the nodes\n");
        printf("4. Search for a node\n");
        printf("5. Sort the nodes\n");
        printf("0. Exit...\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                InsertNode();
                break;
            case 2:
                DeleteNode();
                break;
            case 3:
                DisplayNodes();
                break;
            case 4:
                SearchNode();
                break;
            case 5:
                SortNodes();
                break;
            case 0:
                printf("\nExiting...\n\n");
                break;
            default:
                printf("\n\nInvalid choice. Please try again...\n");
        }
    } while (choice != 0);
}

void DisplayNodes(){
    printf("\n\n--------------------------------\n");
    struct node *current = head;
    printf("Linked List: ");
    while(current != NULL){
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void CreateHeadNode(){
    printf("\n\n--------------------------------\n");
    printf("Enter data to create Head node: ");
    head = (struct node *) malloc(sizeof(struct node));
    if (head == NULL){
        printf("Memory error!\n");
        return;
    }
    scanf("%d", &head->data);
    head->next = NULL;
    printf("Head node created with data: %d\n", head->data);
}

void InsertNode(){
    printf("--------------------------------\n");
    printf("\nEnter the position of the node (0 to add at the end): ");
    int position, i;
    scanf("%d", &position);
    printf("\nEnter the data of the node: ");
    struct node *new = (struct node *) malloc(sizeof(struct node));
    if (new == NULL){
        printf("Memory error!\n");
        return;
    }else{
        scanf("%d", &new->data);
    }

    if (position == 1) {
        new->next = head;
        head = new;
        printf("Node inserted at the start\n");
    }else if (position < 1){
        struct node *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new;
        new->next = NULL;
        printf("Node inserted at the end\n");
    }else {
        struct node *current = head;
        int range = 1;
        for (i = 1; i < position - 1; i++) {
            if (current->next == NULL){
                range = 0;
                break;
            }
            current = current->next;
        }
        if (range){
            new->next = current->next;
            current->next = new;
            printf("Node inserted at position: %d\n", position);
        } else {
            current->next = new;
            new->next = NULL;
            printf("\nPosition Out of range! So node inserted at the end\n");
        }
    }
    DisplayNodes();
}

void DeleteNode(){
    printf("--------------------------------\n");
    printf("Enter the position of the node to delete: ");
    int position;
    scanf("%d", &position);
    struct node *current = head;
    struct node *previous;
    if (position == 1){
        head = current->next;
        printf("First node is deleted\n");
    } else if (position < 1){
        while (current->next != NULL){
            previous = current;
            current = current->next;
        }
        previous->next = NULL;
        printf("Last node is deleted\n");
    } else {
        for (int i = 1; i<position; i++ ){
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
    }
    free(current);
    printf("\nNode on position %d is deleted\n", position);
    DisplayNodes();
}

void SearchNode(){
    printf("--------------------------------\n");
    printf("Enter the data to search: ");
    int search_data, found = 0, position = 0;
    scanf("%d", &search_data);
    struct node *current = head;
    while(current != NULL){
        position++;
        if(current->data == search_data){
            found = 1;
            break;
        }
        current = current->next;
    }
    if(found){
        printf("\nNode with data %d found at position %d\n", search_data, position);
    } else {
        printf("\nNode with data %d not found\n", search_data);
    }
}

void SortNodes() {
    printf("--------------------------------\n");
    printf("Ascending or descending order (A/D): ");
    char order;
    scanf(" %c", &order);
    printf("\nSorting the linked list...\n");
    struct node *current, *next, *min;
    int temp;
    if (order == 'A') {
        for (current = head; current!= NULL; current = current->next) {
            min = current;
            for (next = current->next; next!= NULL; next = next->next) {
                if (next->data < min->data) {
                    min = next;
                }
            }
            temp = current->data;
            current->data = min->data;
            min->data = temp;
        }
        printf("\nLinked list sorted in ascending order.\n");
    }else if (order == 'D') {
        for (current = head; current!= NULL; current = current->next) {
            min = current;
            for (next = current->next; next!= NULL; next = next->next) {
                if (next->data > min->data) {
                    min = next;
                }
            }
            temp = current->data;
            current->data = min->data;
            min->data = temp;
        }
        printf("\nLinked list sorted in descending order.\n");
    }else {
        printf("\nInvalid order. Please enter 'A' for ascending or 'D' for descending.\n");
        return;
    }
    
    DisplayNodes();
}

