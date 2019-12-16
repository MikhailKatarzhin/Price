#pragma once
typedef struct product_s {
    char name[30];
    char store[30];
    double price;
} product_t;
product_t *new_empty_product();
product_t *new_product();
