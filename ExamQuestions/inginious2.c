#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct product {
  char *name;
  double price;
} product_t;

/*
 * @ptrProd != NULL
 * @return: the price of the product ptrProd
 */
double getPtrPrice(product_t *ptrProd) { return ptrProd->price; }

/*
 * @return: the price of the product prod
 */
double getPrice(product_t prod) { return prod.price; }

/*
 * ptrProd != NULL
 * @name in ptrProd != NULL
 * @return: a string on the heap that contains the name of the product ptrProd
 * or NULL if an error happens
 */
char *getPtrName(product_t *ptrProd) {
  if (ptrProd == NULL || ptrProd->name == NULL) {
    return NULL;
  }

  // Allocate memory for the copy of the name
  char *nameCopy = (char *)malloc(strlen(ptrProd->name) + 1);
  if (nameCopy == NULL) {
    // If malloc fails, return NULL
    return NULL;
  }

  // Copy the string to the allocated memory
  strcpy(nameCopy, ptrProd->name);

  // Return the copy of the name
  return nameCopy;
}

/*
 * @name in prod != NULL
 * @return: a string on the heap that contains the name of the product ptrProd
 * or NULL if an error happens
 */
char *getName(product_t prod) {
  if (prod.name == NULL) {
    return NULL;
  }

  char *nameCopy = (char *)malloc(sizeof(strlen(prod.name) + 1));
  if (nameCopy == NULL) {
    return NULL;
  }

  strcpy(nameCopy, prod.name);

  return nameCopy;
}

/*
 * @ptrProd != NULL
 * @name in ptrProd != NULL
 * @name in prod != NULL
 * @return: 1 if the two products are the same, i.e., they have the same price
 * and the same name
 */
int prodEquals(product_t *ptrProd, product_t prod) {
  if (ptrProd->name == NULL || ptrProd == NULL) {
    return 0;
  } else if (prod.name == NULL) {
    return 0;
  }

  if (ptrProd->name == prod.name && ptrProd->price == prod.price) {
    return 1;
  } else {
    return 0;
  }
}
