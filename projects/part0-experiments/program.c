#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* get_password(int lenght) {
    char* password = malloc(lenght * sizeof(char));
    
    if(password == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < lenght; i++) {
        char temp = (rand() % (92 - 33)) + 33;
        password[i] = temp;
    }

    password[lenght] = '\0';

    return password;
}

int main() {
    srand(time(NULL));
    printf("All available chars\n");
    for (int i = 33; i < 92+33; i++) {
        char temp = i;
        printf("%10i%10c\n", i, temp); 
    }

    char* random_password = get_password(13);
    printf("Your random password: %s\n", random_password);

    free(random_password);
    return 0;
}
