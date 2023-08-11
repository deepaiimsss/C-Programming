#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 4

struct student {
    char usn[10];
    char name[30];
    char branch[5];
    int sem;
    char phno[10];
    struct student *next;
};

typedef struct student NODE;

int countnodes(NODE *head) {
    NODE *p = head;
    int count = 0;
    
    while (p != NULL) {
        p = p->next;
        count++;
    }
    
    return count;
}

NODE* getnode() {
    NODE *newnode = (NODE*)malloc(sizeof(NODE));
    if (newnode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    
    printf("\nEnter USN, Name, Branch, Sem, Ph.No\n");
    scanf("%s", newnode->usn);
    scanf("%s", newnode->name);
    scanf("%s", newnode->branch);
    scanf("%d", &(newnode->sem));
    scanf("%s", newnode->phno);
    newnode->next = NULL;
    
    return newnode;
}

NODE* display(NODE *head) {
    NODE *p = head;
    
    if (p == NULL) {
        printf("\nNo student data\n");
    } else {
        printf("\n----STUDENT DATA----\n");
        printf("\nUSN\tNAME\t\tBRANCH\tSEM\tPh.NO.");
        while (p != NULL) {
            printf("\n%s\t%s\t\t%s\t%d\t%s", p->usn, p->name, p->branch, p->sem, p->phno);
            p = p->next;
        }
        printf("\nThe no. of nodes in list is: %d\n", countnodes(head));
    }
    
    return head;
}

NODE* insert_front(NODE *head) {
    if (countnodes(head) == MAX) {
        printf("\nList is Full / Overflow!!\n");
    } else {
        NODE *newnode = getnode();
        newnode->next = head;
        head = newnode;
    }
    
    return head;
}

NODE* insert_rear(NODE *head) {
    if (countnodes(head) == MAX) {
        printf("\nList is Full(QUEUE)!!\n");
    } else {
        NODE *newnode = getnode();
        if (head == NULL) {
            head = newnode;
        } else {
            NODE *p = head;
            while (p->next != NULL) {
                p = p->next;
            }
            p->next = newnode;
        }
    }
    
    return head;
}

NODE* insert(NODE *head) {
    int ch;
    do {
        printf("\n1. Insert at Front(First)\t2. Insert at End(Rear/Last)\t3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                head = insert_front(head);
                break;
            case 2:
                head = insert_rear(head);
                break;
            case 3:
                break;
            default:
                printf("Invalid choice.\n");
        }
        head = display(head);
    } while (ch != 3);
    
    return head;
}

void free_list(NODE *head) {
    while (head != NULL) {
        NODE *temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int ch, n;
    NODE *head = NULL;
    
    printf("\n*----------Student Database-----------*");
    
    do {
        printf("\n 1. Create\t 2. Display\t 3. Insert\t 4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        
        switch (ch) {
            case 1:
                printf("\nHow many student data you want to create: ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    head = insert_rear(head);
                }
                break;
            case 2:
                head = display(head);
                break;
            case 3:
                head = insert(head);
                break;
            case 4:
                free_list(head);
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}
