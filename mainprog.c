#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *line;
void readline(FILE *file){
    line=(char *)calloc(1,sizeof(char));
    char chr;
    fscanf(file,"%c",&chr);
    int i=0;
    while(chr!='\n'&&chr!=EOF){
        line[i]=chr;
        fscanf(file,"%c",&chr);
        if(chr!='\n'){
            i++;
            line =(char *)realloc(line , i*sizeof(char));   
            if(line==NULL){
                printf("shit");
            }
        }
        else{
            i++;
            line =(char *)realloc(line , i*sizeof(char));   
            line[i]='\0';
        }
    }
    // return line;
}

int main(){
    FILE *restaurant;
    restaurant =fopen("restaurants.txt","r");
    char** rest_list=malloc(10*sizeof(char *)); 
    for(int i=0;i<10;i++){
        readline(restaurant);
        rest_list[i]=malloc(strlen(line));
        for(int j=0;j<(strlen(line));j++)
            *(rest_list[i]+j)=*(line+j);
        free(line);
    }
    fclose(restaurant);
    printf("\n\nHello , Meal time\n\nSelect your restaurant\n\n");
    for(int i=0;i<10;i++){
        printf("%d. %s\n\n",i+1,rest_list[i]); 
    }
}