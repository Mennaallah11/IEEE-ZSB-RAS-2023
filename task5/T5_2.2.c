#include <stdio.h>
#include <string.h>
int main() {
    char arr[100]; 
    int  unique;
    
    do {
        printf("Enter a string: ");
        fgets(arr, sizeof(arr), stdin);
             if (arr == "!!") {
             printf("Program stopped.\n");
             break;
        }
        
        for (int j = 0; j < strlen(arr); j++) {
            unique = 1; // Assume character is unique
            for (int x = 0; x < j; x++) {
                if (arr[j] == arr[x]) {
                    unique = 0; // Character is not unique
                    break;
                }
            }
            if (unique) {
            printf("%c", arr[j]);
            }
        }
    } while (1); 
    
    return 0;
}