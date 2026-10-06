#include <stdio.h>
#include <string.h>

int main(void){
    char firstName[20], lastName[20];
    int firstNameLength, lastNameLength;
    printf("Please enter your first name: ");
    scanf("%s", firstName);
    printf("Please enter your last name: ");
    scanf("%s", lastName);
    printf("%s %s\n", firstName, lastName);
    firstNameLength = strlen(firstName);
    lastNameLength = strlen(lastName);
    printf("%*d %*d\n", firstNameLength, firstNameLength, lastNameLength, lastNameLength);
    return 0;
}