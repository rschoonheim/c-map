#include <stdio.h>

#include "hash_map.h"

int main() {

  c_hash_map_table *table = hash_table_new(500);

  int addResult = hash_table_add(table, "key", "value");
  printf("Add result: %d\n", addResult);

  int addResult2 = hash_table_add(table, "key", "value");
  printf("Add result (second time): %d\n", addResult2);

  int hasKey = hash_table_has_key(table, "key");
  printf("Key exists: %d\n", hasKey);

  return 0;
}