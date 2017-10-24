#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME 20 

struct Student{
    char name[MAX_NAME];
    int middle;
    int final;
    double avg;
}Student;
struct Node{
    struct Node *left;
    struct Node *right;
    int num;
}Node;


void main(){
    int size = 0;
    int i = 0;
    struct Student *s;

    printf("Press number of student : ");
    scanf("%d", &size);

    s = (struct Student *)malloc(sizeof(struct Student) * size);

    for(i = 0; i < size; i++){
        printf("%d. Add Student name : ", i+1);
        scanf("%s", s[i].name);
        printf("%d. Add Student middle : ", i+1);
        scanf("%d", &s[i].middle);
        printf("%d. Add Student final : ", i+1);
        scanf("%d", &s[i].final);
        
        s[i].avg = (s[i].middle + s[i].final)/2;
    }
    for(i = 0; i < size; i ++){
        printf("===%d. Student info===\n",i+1);
        printf("Name : %s\n", s[i].name);
        printf("Middle : %d\tFinal : %d\n", s[i].middle, s[i].final);
        printf("Avg : %.2lf\n", s[i].avg);

    }
    free(s);
}


