#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validateEmail(const char* email){
    int i, at = 0, dot = 0;
    int at_pos = -1, dot_pos = -1;
    for (i = 0; i < strlen(email); i++){
        if (email[i] == '@'){
            at++;
            at_pos = i;
        }
        if (email[i] == '.'){
            dot++;
            dot_pos = i;
        }
        if (email[i] == ' '){
            return 0;
        }
    }
    if (at == 1 && dot >= 1 && at_pos < dot_pos){
        return 1;
    }
    return 0;
}

int main(){
    char *email;
    size_t size = 100;

    email = (char*)malloc(size * sizeof(char));
    if (email == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter email: ");
    fgets(email, size, stdin);

    email[strcspn(email, "\n")] = 0;

    if (validateEmail(email)){
        printf("Valid email\n");
    } else {
        printf("Invalid email\n");
    }

    free(email);
    return 0;
}
