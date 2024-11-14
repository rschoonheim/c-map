#include "hash_map.h"
#include <stdlib.h>
#include <string.h>

unsigned int hash(const char *key) {
    unsigned int hash = 0;
    while (*key) {
        hash = (hash << 5) + *key++;
    }
    return hash % 1000;
}

c_hash_map_table *hash_table_new(int size) {
    c_hash_map_table *table = malloc(sizeof(c_hash_map_table));
    table->entries = calloc(1000, sizeof(c_hash_map_table_entry *));
    table->size = size;
    return table;
}

int hash_table_has_key(c_hash_map_table *table, const char *key) {
    unsigned int index = hash(key);
    c_hash_map_table_entry *entry = table->entries[index];
    while (entry) {
        if (strcmp(entry->key, key) == 0) {
            return 1;
        }
        entry = entry->next;
    }
    return 0;
}

int hash_table_add(c_hash_map_table *table, const char *key, void *value) {
    unsigned int index = hash(key);
    c_hash_map_table_entry *entry = table->entries[index];

    while (entry) {
        if (strcmp(entry->key, key) == 0) {
            return C_HASH_MAP_ERROR_KEY_ALREADY_DEFINED;
        }
        entry = entry->next;
    }

    c_hash_map_table_entry *new_entry = malloc(sizeof(c_hash_map_table_entry));
    new_entry->key = strdup(key);
    new_entry->value = value;
    new_entry->next = table->entries[index];
    table->entries[index] = new_entry;

    return 0;
}