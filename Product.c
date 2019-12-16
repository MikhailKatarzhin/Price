#include "Product.h"
#include <stdlib.h>
#include <stdio.h>

product_t* new_empty_product() {
    return malloc(sizeof(product_t));
}
product_t* new_product()
{
    product_t *thing = new_empty_product();
    printf("\nEntry product's name:\t");
    scanf("%s", thing->name);
    printf("\nEntry store's name:\t");
    scanf("%s", thing->store);
    printf("\nEntry product's price:\t");
    scanf("%lf", &thing->price);
    return thing;
}
