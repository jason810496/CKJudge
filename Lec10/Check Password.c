# include <stdio.h>
# include <string.h>

#define SIZE 25

int length(char pwd1[], char pwd2[]);

int compare(char pwd1[], char pwd2[]);

int content(char pwd1[]);

int main()
{
    char password1[SIZE];
    char password2[SIZE];
    
    // Enter the password
    scanf("%s", password1);
    // Enter the password again
    scanf("%s", password2);
    
    // Check Password
    // First: Check length
    if(length(password1, password2) == 1) {
        printf("Length does not match the requirements");
    }
    else {
        // Second: Check for consistency
        if(compare(password1, password2) == 1) {
            printf("Not the same password");
        }
        else {
            // Third: Check for compliance
            if(content(password1) == 1) {
                printf("Do not satisfy the conditions");
            }
            else {
                printf("Everything is good");
            }
        }
    }

    return 0;
}


int length(char pwd1[], char pwd2[]) {
    int l1 = strlen(pwd1);
    int l2 = strlen(pwd2);
    return  !( (6<= l1 && l1 <= 16 ) && ( 6<= l2 && l2 <= 16 ) );
}

int compare(char pwd1[], char pwd2[]) {
    int l1 = strlen(pwd1);
    int l2 = strlen(pwd2);
    if( l1 != l2 ) return 1;

    for(int i=0;i<l1;i++){
        if( pwd1[i] != pwd2[i] ) return 1;
    }
    return 0;
}

int content(char pwd1[]) {
    int Num=1 , Big=1 , Small=1;
    int l1 = strlen(pwd1);
    for(int i=0;i<l1;i++){
        if( '0'<= pwd1[i] && pwd1[i] <= '9' ) Num=0;
        if( 'A'<= pwd1[i] && pwd1[i] <= 'Z' ) Big=0;
        if( 'a'<= pwd1[i] && pwd1[i] <= 'z' ) Small=0;
    }
    return Num || Big || Small;
}