#include <stdio.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 1000

void encodeMessage() {
    char messages[MAX_MESSAGE_LENGTH], reverse[MAX_MESSAGE_LENGTH];
    int len;
    
    printf("Enter plain text message to encode: ");
    getchar(); // Clear input buffer
    fgets(messages, MAX_MESSAGE_LENGTH, stdin);
    
    len = strlen(messages);
    if(messages[len - 1] == '\n') {
        messages[len - 1] = '\0';
        len--;
    }
    
    // Step 1: Reverse the string
    for(int i = 0; i < len; i++)
        reverse[i] = messages[len - 1 - i];
    reverse[len] = '\0';
    
    // Step 2: Toggle 2nd and 5th bits (using XOR with 18 = 00010010 in binary)
    for(int i = 0; i < len; i++)
        reverse[i] = reverse[i] ^ 18;
    
    printf("\n===== ENCODING RESULTS =====\n");
    printf("Original Message: %s\n", messages);
    printf("Encoded Message: %s\n", reverse);
    printf("Encoding completed successfully!\n");
}

void decodeMessage() {
    char messages[MAX_MESSAGE_LENGTH], reverse[MAX_MESSAGE_LENGTH];
    int len;
    
    printf("Enter encoded message to decode: ");
    getchar(); // Clear input buffer
    fgets(reverse, MAX_MESSAGE_LENGTH, stdin);
    
    len = strlen(reverse);
    if(reverse[len - 1] == '\n') {
        reverse[len - 1] = '\0';
        len--;
    }
    
    // Step 1: Untoggle bits (same as encoding - XOR with 18)
    for(int i = 0; i < len; i++)
        reverse[i] = reverse[i] ^ 18;
    
    // Step 2: Reverse the string back to original
    for(int i = 0; i < len; i++)
        messages[i] = reverse[len - 1 - i];
    messages[len] = '\0';
    
    printf("\n===== DECODING RESULTS =====\n");
    printf("Encoded Message: %s\n", reverse);
    printf("Decoded Message: %s\n", messages);
    printf("Decoding completed successfully!\n");
}

int main() {
    char choice;
    
    printf("===== WELCOME TO TCS SECURE MESSAGE SYSTEM =====\n");
    printf("Secure your messages with our encoding algorithm!\n\n");
    
    while(1) {
        printf("\n===== MAIN MENU =====\n");
        printf("E - Encode Message (Make it secure)\n");
        printf("D - Decode Message (Read secure message)\n");
        printf("S - Exit System\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        
        if(choice == 'E' || choice == 'e') {
            encodeMessage();
        } else if(choice == 'D' || choice == 'd') {
            decodeMessage();
        } else if(choice == 'S' || choice == 's') {
            printf("Exiting TCS Secure Message System. Stay secure!\n");
            return 0;
        } else {
            printf("ERROR: Invalid choice! Please enter E, D, or S.\n");
        }
    }
    
    return 0;
}
