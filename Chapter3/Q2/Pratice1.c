#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    FILE *fp = fopen("./Pratice1.txt", "r");
    char word[256];
    int i, len;

    //fscanf(fp, "%s", word);
    while(!feof(fp)){
        fgets(word, 256, fp);
    }
    len = strlen(word);

    for(i = len-1; i>=0; i--){
        printf("%c", word[i]);
    }
    printf("\n");
    return 0;

}
