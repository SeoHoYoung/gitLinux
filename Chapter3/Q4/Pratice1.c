#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void pratice();
void result(char *text[], char *input[][20], char check[], int total);

int main(){
    pratice();
    return 0;
}

void pratice(){
    int i, total = 0;
    char *text[3] = {"Hi my name", "Hello Hoyoung", "Linux Example"};

    char check[3];
    char *input[3][20] = { NULL, };
    srand((unsigned)time(NULL));

    for(i = 0; i < 3; i++){
        printf("%d text : %s", i+1, text[i]);
        printf("\n");
        fgets(input[i], sizeof(input[i]), stdin);
        if((strcmp(text[i], input[i]))<0){
                total++;
                check[i] = 1;
        }else check[i] = 0;
    }
    result(text, input, check, total);
}

void result(char *text[], char *input[][20], char check[], int total){
    int i;

    printf("result\n\n");

    for(i = 0; i < 3; i++){
        printf("%d text : %s, input : %s", i+1, text[i], input[i]);
        if(check[i] == 0) printf(" --> X \n");
        else printf(" --> O \n");
    }
    printf("\n");

    printf("Success : %d\n", total);
}

