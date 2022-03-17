#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *rest;
char* rest_list[10];
char* readline(FILE *restaurant){
    rest=(char *)calloc(1,sizeof(char));
    char chr;
    fscanf(restaurant,"%c",&chr);
    int i=0;
    while(chr!='\n'&&chr!=EOF){
        rest[i]=chr;
        fscanf(restaurant,"%c",&chr);
        if(chr!='\n'){
            rest =(char *)realloc(rest , strlen(rest)+1);
            i++;
        }
    }
    
    return rest;
}

int main(){
    FILE *restaurant;
    restaurant =fopen("restaurants.txt","r");
    for(int i=0;i<10;i++){
        rest_list[i]=readline(restaurant);
        printf("%s\n",rest_list[i]);
        free(rest);
    }
    fclose(restaurant);
}