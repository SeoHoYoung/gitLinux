#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

void main(){
    void *handle;
    double (*Add) (double, double);
    double (*Subtract) (double, double);
    double (*Multiply) (double, double);
    double (*Divide) (double, double);
    char *error;

    handle = dlopen("./libtest.so", RTLD_LAZY);
    if(!handle){
        fputs(dlerror(), stderr);
        exit(1);
    }

    Add = dlsym(handle, "Add");
    if((error = dlerror()) != NULL){
        fprintf(stderr, "%s", error);
        exit(1);
    }

    Subtract = dlsym(handle, "Subtract");
    if((error = dlerror()) != NULL){
        fprintf(stderr, "%s", error);
        exit(1);
    }

    Multiply = dlsym(handle, "Multiply");
    if((error = dlerror()) != NULL){
        fprintf(stderr, "%s", error);
        exit(1);
    }

    Divide = dlsym(handle, "Divide"); 
    if((error = dlerror()) != NULL){
        fprintf(stderr, "%s", error);
        exit(1);
    }

    printf("Add(2.4,3.1) = %.1lf\n", (*Add) (2.4,3.1));
    printf("Subtract(6.4,3.1) = %.1lf\n", (*Subtract) (6.4, 3.1));
    printf("Multiply(5.5,1.1) = %.1lf\n", (*Multiply) (5.5,1.1));
    printf("Divide(2,1) = %.1lf\n", (*Divide) (2,1));

    dlclose(handle);
}
