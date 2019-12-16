#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Product.h"
#include "Product_List.h"
#include "Request_String.h"

#define uint unsigned int
#define bool unsigned short

#define DOUBLE_STR_LEN 25
#define DOUBLE_DECIMAL_LEN 3

// In this region - product type declaration.

product_list_t *new_product_list_from_file(char *file_path); // not impl
product_t *get_from_product_list(product_list_t *product_list, int i); // not impl // get element by index
void save_product_list_to_file(product_list_t *product_list, char *file_path, bool rewrite_file); // not impl
product_list_t *request_product_list(); // not impl

char* serialize(product_t *product);

// This is interface of files I/O.
char* request_path(void);
void load_file(char * path, product_list_t *product_list);
void save_to_file(char *path, product_list_t *product_list);


// This is interface of serialisation.
// After serialisation fields separate by '|' and objects separate by '\n'.
char *serializeArray(product_list_t *product_list); // not impl
product_t *deserialize(char const* serialized_product); // not impl
product_list_t *deserializeArray(char const* serialized_product_list); // not impl

int main(int argc, char **argv)
{
    printf("Greetings master!");
    unsigned int var;
    product_list_t *price = new_empty_product_list();
    do
    {
        printf("\n\n\t*** Main menu ***");
        printf("\n\t0) Close program\n\t1) Load data\n\t2) Save data\n\t3) Show all data\n\t4) Search between stores\n\t5) Add new product\n\t6) Change product's data(not implemented)\nAnswer:\t");
        scanf("%ui", &var);
        fflush(stdin);
        switch(var)
        {
        case 0:
            printf("\n*** Goodbye! ***");
            return 0;
        case 1:
            load_file(request_path(), price);
            break;
        case 2:
            save_to_file(request_path(), price);
            break;
        case 3:
            show_all_data (price);
            break;
        case 4:
            search_betwen_stores(price);
            break;
        case 5:
            add_to_product_list(price);
            break;
        case 6: //There is not in task!
            break;
        }
    }while(var != 0);
}

char* request_path(void)
{
  printf("\nWrite path to loading file:\t");
    char* string = request_string();
    char *path = (char*) malloc( (strlen(string) - 1) * sizeof(char) );
    for (int i = 0; (string[i] != '\0')&&(string[i] != '\n'); i++)
        {
            path[i] = string[i];
        }
    free(string);
  return path;
}


void load_file(char * path, product_list_t *product_list) {
    FILE *file = fopen(path, "r");
    char *buffer = (char*)calloc(200, sizeof(char)),*buffer2 = (char*)calloc(100, sizeof(char));
    int c, i;
//    long length;
    if (file == NULL)
    {
        fclose(file);
        free(buffer);
        printf("\n Error reading!");
    }else{
    free(product_list);
    fgets (buffer, 100, file);
    product_list = new_empty_product_list();
    product_list->capacity = atoi(buffer);
    printf("\n%d", atoi(buffer));
    realloc(product_list->product_list, sizeof(product_t*) * product_list->capacity );

    while (1)
   {

        if (fgets (buffer, 200, file) == NULL)
        {
            printf ("\nReading is complete\n");
            break;
        }
        i = 0;
        while (buffer[i] != '|')
        {
            c = 0;
            product_list->product_list[product_list->size].name[c] = buffer [i];
            c++;
            i++;
        }
        i++;
        while (buffer[i] != '|')
        {
            c = 0;
            product_list->product_list[product_list->size].store[c] = buffer [i];
            c++;
            i++;
        }
        i++;
        while (buffer[i] != '|')
        {
            c = 0;
            buffer2[c] = buffer[i];
            c++;
            i++;
        }
        product_list->product_list[product_list->size].price = atof(buffer2);
        product_list->size ++;
   }
   free(buffer2);
   free(buffer);
   fclose(file);
}}
char* serialize(product_t *product) {
    char *price_str = (char*) malloc(DOUBLE_STR_LEN * sizeof(char));
//    gcvt(product->price, DOUBLE_DECIMAL_LEN, price_str);
    sprintf(price_str, "%lf", product->price);
    char *serialized_string = malloc(strlen(product->name) + strlen(product->store) + strlen(price_str) + 2);
    strcpy(serialized_string, product->name);
    strcat(serialized_string, "|");
    strcat(serialized_string, product->store);
    strcat(serialized_string, "|");
    strcat(serialized_string, price_str);
    strcat(serialized_string, "|");
    return serialized_string;
}
void save_to_file(char * path, product_list_t *product_list) {
    FILE *fp = fopen(path, "w");
    char *tmp = (char*)calloc(100, sizeof(char));
    unsigned i = 0;
    fprintf(fp, "%u\n", product_list->capacity);
    for (; i < product_list->size; i++)
    {
        tmp = serialize(&(product_list->product_list[i]));
        fprintf(fp, "%s\n", tmp);
        free(tmp);
    }
    free(path);
    fclose(fp);
}

/*
// serialize to 'name|store|price'
char *serializeArray(product_list_t *product_list) {
    // для каждоого эллементта массива
    //     serialize(эллемен)
    // полученное добавляем к строке в вывод
    printf("char *serializeArray(product_list_t *product_list) { not implemented };\n");
}
product_t *deserialize(char const* serialized_product) {
    // мы ожидаем строку 'name|store|price'
    // делим по |
    // создаем структуру и возвращаем указаттель на неее
    printf("product_t *deserialize(char const* serialized_product) {not implemented };\n");
}
product_list_t *deserializeArray(char const* serialized_product_list) {
    // делим (split) по \n
    // для каждоой получившейся строки вызываем deserialize
    printf("product_list_t *deserializeArray(char const* serialized_product_list) { not implemented };\n");
}


product_list_t *new_product_list_from_file(char *file_path) {
    return deserializeArray(load_file(file_path));
}

product_t *get_from_product_list(product_list_t *product_list, int i) {
    // todo
}
void save_product_list_to_file(product_list_t *product_list, char *file_path, bool rewrite_file) {

}
*/
