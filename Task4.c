#include <stdio.h>

#define STACK_SIZE 10

int StackSize = STACK_SIZE, TopPointer = 0;

void push(int Stack[], int num) {
    if(TopPointer < StackSize) {
        Stack[TopPointer] = num;
        TopPointer++;
        printf("SUCCESS: Element %d added to stack successfully!\n", num);
    } else {
        printf("ERROR: Stack is FULL! Cannot add more elements.\n");
    }
}

void pop(int Stack[]) {
    if(TopPointer != 0) {
        printf("SUCCESS: Element %d removed from stack.\n", Stack[TopPointer - 1]);
        TopPointer--;
    } else {
        printf("ERROR: Stack is EMPTY! No elements to remove.\n");
    }
}

void peek(int Stack[]) {
    if(TopPointer != 0) {
        printf("Top Element: %d\n", Stack[TopPointer - 1]);
    } else {
        printf("Stack is currently empty.\n");
    }
}

void display(int Stack[]) {
    if(TopPointer == 0) {
        printf("Stack is empty.\n");
        return;
    }
    
    printf("Stack elements (from top to bottom): ");
    for(int i = TopPointer - 1; i >= 0; i--) {
        printf("%d", Stack[i]);
        if(i > 0) printf(" <- ");
    }
    printf("\n");
    printf("Total elements in stack: %d/%d\n", TopPointer, StackSize);
}

int main() {
    int Stack[STACK_SIZE];
    int choice, num;
    
    printf("===== STACK IMPLEMENTATION USING ARRAYS =====\n");
    printf("Stack Size: %d elements\n\n", STACK_SIZE);
    
    do {
        printf("\n===== STACK OPERATIONS MENU =====\n");
        printf("1 - PUSH (Add element)\n");
        printf("2 - POP (Remove element)\n");
        printf("3 - PEEK (View top element)\n");
        printf("4 - DISPLAY (Show all elements)\n");
        printf("5 - EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter number to push into stack: ");
                scanf("%d", &num);
                push(Stack, num);
                break;
                
            case 2:
                pop(Stack);
                break;
                
            case 3:
                peek(Stack);
                break;
                
            case 4:
                display(Stack);
                break;
                
            case 5:
                printf("Exiting Stack Program. Goodbye!\n");
                break;
                
            default:
                printf("ERROR: Invalid choice! Please enter 1-5.\n");
                break;
        }
    } while(choice != 5);
    
    return 0;
}
