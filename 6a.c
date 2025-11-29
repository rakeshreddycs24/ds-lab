#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};

struct node *createsll() {
    struct node *start = NULL, *p, *last = NULL;
    int item;

    printf("Enter value to be inserted (-999 to stop): ");
    scanf("%d", &item);

    while(item != -999) {
        p = (struct node*)malloc(sizeof(struct node));
        p->info = item;
        p->next = NULL;

        if(start == NULL) {           // first node
            start = p;
            last = p;
        } else {                      // append
            last->next = p;
            last = p;
        }

        scanf("%d", &item);
    }
    return start;
}

struct node *sortsll(struct node *start) {
    if(start == NULL || start->next == NULL)
        return start;

    struct node *current = start;
    struct node *index;
    int temp;

    while(current != NULL) {
        index = current->next;
        while(index != NULL) {
            if(index->info < current->info) {
                temp = current->info;
                current->info = index->info;
                index->info = temp;
            }
            index = index->next;
        }
        current = current->next;
    }
    return start;
}

struct node *reversesll(struct node *start) {
    struct node *previous = NULL;
    struct node *current = start;
    struct node *next;

    while(current != NULL) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    return previous;
}

struct node *concatsll(struct node *start1, struct node *start2) {
    if(start1 == NULL) return start2;
    struct node *temp = start1;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = start2;
    return start1;
}

void display(struct node *start) {
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    while (start != NULL) {
        printf("%d -> ", start->info);
        start = start->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, llchoice;
    struct node *start1 = NULL, *start2 = NULL;

    printf("\n1. Create\n2. Sort\n3. Reverse\n4. Concatenate\n5. Display");

    while(1) {
        printf("\nChoice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Linked list 1: \n");
                start1 = createsll();
                printf("Linked list 2: \n");
                start2 = createsll();
                break;

            case 2:
                printf("\nWhich linked list do you want to sort (1/2): ");
                scanf("%d", &llchoice);
                if(llchoice == 1) { start1 = sortsll(start1); display(start1); }
                else { start2 = sortsll(start2); display(start2); }
                break;

            case 3:
                printf("\nWhich linked list do you want to reverse (1/2): ");
                scanf("%d", &llchoice);
                if(llchoice == 1) { start1 = reversesll(start1); display(start1); }
                else { start2 = reversesll(start2); display(start2); }
                break;

            case 4:
                start1 = concatsll(start1, start2);
                display(start1);
                break;

            case 5:
                printf("Linked list 1:\n");
                display(start1);
                printf("Linked list 2:\n");
                display(start2);
                break;

            default:
                printf("Invalid choice.\n");
        }
    }
}
