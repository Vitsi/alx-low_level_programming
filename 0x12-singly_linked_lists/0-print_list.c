#include "lists.h"
#include <stdio.h>
size_t print_list(const list_t *h)
{
  size_t count = 0;
  const list_t *node = h;

  while (node != NULL) {
    if (node->str != NULL) {
      printf("[%u] %s\n", node->len, node->str);
    } else {
      printf("[0] (nil)\n");
    }
    count++;
    node = node->next;
  }

  return count;
}

