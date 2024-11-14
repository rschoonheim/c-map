#include <stdio.h>

#include "hash_map.h"

int main() {

  c_hash_map_table *table = c_hash_table_new(500);

  int addResult = c_hash_table_add(table, "key", "value");
  printf("Add result: %d\n", addResult);

  int addResult2 = c_hash_table_add(table, "key", "value");
  printf("Add result (second time): %d\n", addResult2);

  int hasKey = c_hash_table_has_key(table, "key");
  printf("Key exists: %d\n", hasKey);

  char * value = c_hash_table_get(table, "key");
  printf("Value: %s\n", value);

  return 0;
}