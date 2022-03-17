// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>
// char *line;
// char* readline(FILE *file){
//     line=(char *)calloc(1,sizeof(char));
//     char chr;
//     fscanf(file,"%c",&chr);
//     int i=0;
//     while(chr!='\n'&&chr!=EOF){
//         line[i]=chr;
//         fscanf(file,"%c",&chr);
//         if(chr!='\n'){
//             line =(char *)realloc(line , strlen(line)+1);
//             i++;
//         }
//     }
//     return line;
// }

// int main(){
//     FILE *restaurant;
//     restaurant =fopen("restaurants.txt","r");
//     char* rest_list[10];
//     for(int i=0;i<10;i++){
//         rest_list[i]=readline(restaurant);
//         free(line);
//     }
//     fclose(restaurant);
//     printf("Hello , Meal time\n\nSelect your restaurant\n\n");
//     for(int i=0;i<10;i++){
//         printf("%d %s\n\n",i+1,rest_list[i]); 
//     }
// }
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *line;
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
    char* rest_list[10];
    for(int i=0;i<10;i++){
        rest_list[i]=readline(restaurant);
        printf("%s\n",rest_list[i]);
        free(line);
    }
    fclose(restaurant);
    printf("Hello , Meal time\n\nSelect your restaurant\n\n");
    for(int i=0;i<10;i++){
        printf("%d %s\n\n",i+1,rest_list[i]); 
    }
}