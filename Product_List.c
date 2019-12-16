#include <stdio.h>
#include "Product_List.h"
#include <stdlib.h>
#include <string.h>

product_list_t *new_empty_product_list()
{
    product_list_t *product_list = (product_list_t**)calloc(sizeof(product_list_t*), 1);
    product_list->capacity = 10;
    product_list->size = 0;
    product_list->product_list = (product_t*) calloc(sizeof(product_t), product_list->capacity);
    return product_list;
}

void add_to_product_list(product_list_t *product_list)
{
    if (product_list->size == ((product_list->capacity)-1))
    {
        product_list->capacity += 10;
        /*product_list->product_list = (product_t**) */realloc(product_list->product_list, sizeof(product_t*) * product_list->capacity);
    }
  //  product_list->product_list[product_list->size+1] = (product_t*) calloc(sizeof(product_t),1);
    product_list->product_list[product_list->size] = *new_product();
   // new_product(product_list->product_list[product_list->size]);
    product_list->size++;
}

void remove_from_product_list(product_list_t *product_list, int i) {

  if (product_list->size > 1){
    for(;i<product_list->size; i++)
    {
      product_list[i]=product_list[i+1];
    }
  }
  free(&product_list[product_list->size-1]);
  product_list->size --;
}

void show_all_data (product_list_t *product_list)
{
    int i = 0;
    printf("\nAll products:");
    for (; i < product_list->size; i++)
            printf("\nproduct %d\n\t name: %s\n\tstore: %s\n\tprice: %lf ", i+1, product_list->product_list[i].name, product_list->product_list[i].store, product_list->product_list[i].price);
}

void search_betwen_stores(product_list_t *product_list)
{
    char *name_shop = (char*)calloc(25, sizeof(char));
    printf("\nEntry name of store:\t");
    scanf("%s", name_shop);
    int i, c, j, m, tmp;
    for (c = 0, m = 0, i = 0; i < (product_list->size); i++)
    {
        tmp = strlen(name_shop) > strlen(product_list->product_list[i].store) ? strlen(name_shop) : strlen(product_list->product_list[i].store);
        for (j = 0, m = 0, c++; j < tmp; j++)
        {
            if (name_shop[j] != product_list->product_list[i].store[j])
            {
                m--;
                break;
            }
        }
        if (m == 0)
        {
            c++;
            printf("\nproduct %d\n\t name: %s\n\tstore: %s\n\tprice: %lf ", i, product_list->product_list[i].name, product_list->product_list[i].store, product_list->product_list[i].price);
        }
    }
    if (c == 0)
            printf("\nThere are no products in these stores");
    free(name_shop);
}
