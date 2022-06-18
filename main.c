#include <stdio.h>
#include <stdlib.h>

// Prototypes

struct Node;
struct Node* create_node(int data);
void b_insert (struct Node** head, int data);
void n_insert (struct Node** head, int data, int pos);
void e_insert (struct Node** head, int data);
void display (struct Node* temp);

// End of prototypes

int main()
{
    struct Node* head = NULL;

    int ch, data, pos;

    printf("Linked list: \n\n");
    while (1) {
        printf("1. Insert at beginning");
        printf("\n2. Insert at Nth position");
        printf("\n3. Insert at ending");
        printf("\n4. Display");
        printf("\n0. Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                b_insert(&head, data);
                break;

            case 2:
                printf("Enter the position: ");
                scanf("%d", &pos);
                n_insert(&head, data, pos);
                break;

            case 3:
                printf("Enter the data: ");
                scanf("%d", &data);
                e_insert(&head, data);
                break;

            case 4:
                display(head);
                break;

            case 0:
                return 0;

            default:
                printf("Wrong choice.");
        }
    }
}

struct Node {
    int data;
    struct Node* next;
};

struct Node* create_node(int data)
{
    struct Node* temp
        = (struct Node*)
            malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;

    return temp;
}

void b_insert(struct Node** head, int data)
{
    struct Node* new_node = create_node(data);

    new_node->next = *head;
    *head = new_node;
}

void n_insert (struct Node** head, int data, int pos)
{
    if (*head == NULL) {
        b_insert(head, data);
        return;
    }

    struct Node* new_node = create_node(data);

    struct Node* temp = *head;

    for (int i = 0; i < pos - 2; ++i)
        temp = temp->next;

    new_node->next = temp->next;
    temp->next = new_node;
}

void e_insert(struct Node** head, int data)
{
    if (*head == NULL) {
        b_insert(head, data);
        return;
    }

    struct Node* temp = *head;

    while (temp->next != NULL)
        temp = temp->next;

    struct Node* new_node = create_node(data);
    temp->next = new_node;
}

void display(struct Node* temp)
{
    printf("The elements are:\n");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}