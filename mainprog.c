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
int fetch_restaurant(char **rest_list){
    printf("\n\nHello , Meal time\n\nSelect your restaurant\n\n");
    for(int i=0;i<10;i++){
        printf("%d. %s\n\n",i+1,rest_list[i]); 
    }
    printf("\n\nEnter * to exit\n\n");
    int restaurant_key=0;
    {
        char c;
        do {
            c=getchar();
            if(c!='\n'){
                restaurant_key += c-'0';
                restaurant_key *=10;
            }
        } while (c != '\n' && c != EOF);
        restaurant_key /=10;
    }
    return restaurant_key;
}
int fetch_item(){
    int menu_key;
    {
        char c;
        do {
            c=getchar();
            if(c!='\n'){
                if(c!='*'){
                    menu_key += c-'0';
                    menu_key *=10;
                }
                else
                    menu_key=c;
            }
        } while (c != '\n' && c != EOF);
        if(menu_key!='*')
            menu_key /=10;
        
    }
    return(menu_key);
}

void print_menu(char **menu_list,int price[],char ** suffix){
    for(int i=0;i<10;i++){
        printf("%s %d %s\n",menu_list[i],price[i],suffix[i]);
    }
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
    while(1)
    {
        int restaurant_key=fetch_restaurant(rest_list);
        FILE *menu;
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
            return 0;
        }
        printf("%s\n\n",rest_list[restaurant_key-1]);
        printf("Select an item\n\n");
        char** menu_list=malloc(10*sizeof(char *)); 
        char** suffix=malloc(10*sizeof(char *)); ;
        int price[10];
        for(int i=0;i<10;i++){
            line=readline(menu);
            price[i]=0;
            // menu_list[i]=malloc((strlen(line)+1)*sizeof(char));
            int item_len=0,suffix_len=0;
            int suffix_start=0;
            for(int j=0;j<(strlen(line));j++){
                if(!((0<=*(line+j)-'0')&&(*(line+j)-'0'<=9))){
                    if(!suffix_start)
                        item_len++;
                    else{
                       suffix_len++; 
                    }
                }
                else{
                    price[i]+=*(line+j)-'0';
                    price[i]*=10;
                    suffix_start=j;
                }
            }
            price[i]/=10;
            menu_list[i]=malloc((item_len+1)*sizeof(char));
            suffix[i]=malloc((suffix_len+1)*sizeof(char));
            suffix_start=0;
            for(int j=0,l=0;j<(strlen(line));j++){
                if(!((0<=*(line+j)-'0')&&(*(line+j)-'0'<=9))){
                    if(!suffix_start)
                        *(menu_list[i]+j)=*(line+j);
                    else{
                       *(suffix[i]+l)=*(line+j);
                    //    printf("%s\0",suffix[i]);
                       l++;
                    }
                }
                else{
                    suffix_start=j;
                }
            }
            *(menu_list[i]+item_len)='\0';
            *(suffix[i]+suffix_len)='\0';

            free(line);
        }
        fclose(menu);
        print_menu(menu_list,price,suffix);
        while(1){
            printf("\n\nTotal: %d",total);
            printf("\n\nPress * to go back\n\n");
            int flag=0;
            int menu_key=fetch_item();
            switch (menu_key)
            {
            case 42:
                flag=1;
                break;
            }
            if(flag){
                system("clear");
                break;
            }
        }
    }
}