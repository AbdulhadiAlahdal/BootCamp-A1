#include <stdio.h>
#include <string.h>
#include <ctype.h>

int check_password(const char *p) {
    int len = strlen(p);
    if (len > 0 && p[len - 1] == '\n') len--; 

    if (len <= 8) return 0;

    int upper = 0, lower = 0, digit = 0, symbol = 0;
    for (int i = 0; i < len; i++) {
        if (isupper(p[i])) upper = 1;
        else if (islower(p[i])) lower = 1;
        else if (isdigit(p[i])) digit = 1;
        else if (ispunct(p[i])) symbol = 1;
    }

    return (upper && lower && digit && symbol);
}

int main() {
    char password[50];
    
    printf("Enter password: ");
    if (fgets(password, sizeof(password), stdin)) {
        if (check_password(password)) {
            printf("Valid password!\n");
        } else {
            printf("Invalid password!\n");
        }
    }
    return 0;
}