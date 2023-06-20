//Data Validation
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isValidEmail(const char* email) {
    int len = strlen(email);
    bool usernameValid = true;
    bool domainValid = true;
    bool extensionValid = true;
    bool dotEncountered = false;
    bool atSymbolEncountered = false;

    for (int i = 0; i < len; i++) {
        char c = email[i];

        if (c == '@') {
            if (i == 0 || i == len - 1) {
                return false;
            }
            if (dotEncountered) {
                return false;
            }
            if (!usernameValid) {
                return false;
            }
            usernameValid = false;
            atSymbolEncountered = true;
        } else if (c == '.') {
            if (!atSymbolEncountered) {
                return false;
            }
            if (i == len - 1 || i == 0 || dotEncountered) {
                return false;
            }
            dotEncountered = true;
        } else if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
            if (dotEncountered) {
                return false;
            }
            if (!atSymbolEncountered) {
                usernameValid = true;
            } else {
                extensionValid = false;
                domainValid = false;
            }
        } else {
            return false;
        }
    }
    if (!domainValid || !extensionValid) {
        return false;
    }

    return true;
}

int main() {
    const char* email = "username@example.com";

    if (isValidEmail(email)) {
        printf("Valid email format.\n");
    } else {
        printf("Invalid email format.\n");
    }

    return 0;
}
