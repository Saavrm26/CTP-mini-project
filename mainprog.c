#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *line;
int total=0;
void readline(FILE *file){
    line=(char *)calloc(1,sizeof(char));
    char chr=' ';
    fscanf(file,"%c",&chr);
    int i=0;
    while(chr!='\n'&&chr!=EOF){
        line[i]=chr;
        fscanf(file,"%c",&chr);
        if(chr!='\n'){
            i++;
            line =(char *)realloc(line , i*sizeof(char));   
            if(line==NULL){
                printf("error");
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
    RESTAURANTS:
        printf("\n\nHello , Meal time\n\nSelect your restaurant\n\n");
        for(int i=0;i<10;i++){
            printf("%d. %s\n\n",i+1,rest_list[i]); 
        }
        int restaurant_key;
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
            readline(menu);
            menu_list[i]=malloc(strlen(line));
            for(int j=0;j<(strlen(line));j++)
                *(menu_list[i]+j)=*(line+j);
            printf("%s\n",menu_list[i]);
            free(line);
        }
        fclose(menu);
        printf("\n\nTotal: %d",total);
        printf("Press * to go back\n\n");
        char menu_key;
        scanf("%c",&menu_key);
        switch (menu_key)
        {
        case '*':
            free(menu_list);
            goto RESTAURANTS;
            break;
        default:
            break;
        }
}