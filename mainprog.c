#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *line;
char* rest_list[10];
char* readline(FILE *file){
    line=(char *)calloc(1,sizeof(char));
    char chr;
    fscanf(file,"%c",&chr);
    int i=0;
    while(chr!='\n'&&chr!=EOF){
        line[i]=chr;
        fscanf(file,"%c",&chr);
        if(chr!='\n'){
            line =(char *)realloc(line , strlen(line)+1);
            i++;
        }
    }
    return line;
}

int main(){
    FILE *restaurant;
    restaurant =fopen("restaurants.txt","r");
    for(int i=0;i<10;i++){
        rest_list[i]=readline(restaurant);
        printf("%s\n",rest_list[i]);
        free(line);
    }
    fclose(restaurant);
}