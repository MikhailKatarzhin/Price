#include "Product.h"
typedef struct product_list_s {
    unsigned int capacity;
    unsigned int size;
    product_t *product_list;
} product_list_t;

product_list_t *new_empty_product_list();
void add_to_product_list(product_list_t *product_list);
void remove_from_product_list(product_list_t *product_list, int i);
void show_all_data (product_list_t *product_list);
void search_betwen_stores(product_list_t *product_list);
