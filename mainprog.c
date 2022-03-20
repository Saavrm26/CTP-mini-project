#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int total=0;
char *line;
char* readline(FILE *file){
    char *ln;
    ln=(char *)calloc(1,sizeof(char));
    char chr=' ';
    fscanf(file,"%c",&chr);
    int i=0;
    while(chr!='\n'&&chr!=EOF){
        ln[i]=chr;
        fscanf(file,"%c",&chr);
        if(chr!='\n'){
            i++;
            ln =(char *)realloc(ln , (i+1)*sizeof(char));   
            if(ln==NULL){
                printf("error");
            }
        }
        else{
            i++;
            ln =(char *)realloc(ln , (i+1)*sizeof(char));   
            ln[i]='\0';
        }
    }
    int l=strlen(ln);
    return ln;
}

int main(){
    FILE *restaurant;
    restaurant =fopen("restaurants.txt","r");
    char** rest_list=malloc(10*sizeof(char *)); 
    for(int i=0;i<10;i++){
        line=readline(restaurant);
        rest_list[i]=malloc((strlen(line)+1)*sizeof(char));
        for(int j=0;j<(strlen(line));j++)
            *(rest_list[i]+j)=*(line+j);
        *(rest_list[i]+strlen(line))='\0';
        free(line);
    }
    fclose(restaurant);
    int restaurant_key;
    RESTAURANTS:
        printf("\n\nHello , Meal time\n\nSelect your restaurant\n\n");
        for(int i=0;i<10;i++){
            printf("%d. %s\n\n",i+1,rest_list[i]); 
        }
        scanf("%d",&restaurant_key);
        FILE *menu;
        MENUS:
        switch (restaurant_key)
        {
        case 1:
            menu=fopen("./menulist/res1.txt","r");
            break;
        case 2:
            menu=fopen("./menulist/res2.txt","r");
            break;
        case 3:
            menu=fopen("./menulist/res3.txt","r");
            break;
        case 4:
            menu=fopen("./menulist/res4.txt","r");
            break;
        case 5:
            menu=fopen("./menulist/res5.txt","r");
            break;
        case 6:
            menu=fopen("./menulist/res6.txt","r");
            break;
        case 7:
            menu=fopen("./menulist/res7.txt","r");
            break;
        case 8:
            menu=fopen("./menulist/res8.txt","r");
            break;
        case 9:
            menu=fopen("./menulist/res9.txt","r");
            break;
        case 10:
            menu=fopen("./menulist/res10.txt","r");
            break;   
        default:
            break;
        }
        printf("%s\n\n",rest_list[restaurant_key-1]);
        printf("Select an item\n\n");
        char** menu_list=malloc(10*sizeof(char *)); 
        for(int i=0;i<10;i++){
            line=readline(menu);
            menu_list[i]=malloc((strlen(line)+1)*sizeof(char));
            for(int j=0;j<(strlen(line));j++)
                *(menu_list[i]+j)=*(line+j);
            *(menu_list[i]+strlen(line))='\0';
            printf("%s\n",menu_list[i]);
            free(line);
        }
        fclose(menu);
        printf("\n\nTotal: %d",total);
        printf("\n\nPress * to go back\n\n");
        int menu_key;
        scanf("%d",&menu_key);
        switch ((char)(menu_key))
        {
        case '*':
            
            // break;
        }
    free(menu_list);
    // free(&menu_key);
    // free(&restaurant_key);
    goto RESTAURANTS;
}