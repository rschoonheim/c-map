#include "hash_map.h"
#include <stdlib.h>
#include <string.h>

/**
 * @brief Compute the hash value for a given key.
 *
 * This function computes the hash value for a given key using a simple hash algorithm.
 *
 * @param key The key to hash.
 * @param size The size of the hash table.
 * @return The computed hash value.
 */
unsigned int hash(const char *key, int size) {
    unsigned int hash = 0;
    while (*key) {
        hash = (hash << 5) + *key++;
    }
    return hash % size;
}

/**
 * @brief Create a new hash table.
 *
 * This function allocates and initializes a new hash table with the specified size.
 *
 * @param size The size of the hash table.
 * @return A pointer to the newly created hash table.
 */
c_hash_map_table *c_hash_table_new(int size) {
    c_hash_map_table *table = malloc(sizeof(c_hash_map_table));
    table->entries = calloc(size, sizeof(c_hash_map_table_entry *));
    table->size = size;
    return table;
}

/**
 * @brief Check if a key exists in the hash table.
 *
 * This function checks whether a given key is present in the hash table.
 *
 * @param table The hash table to check.
 * @param key The key to look for.
 * @return 1 if the key exists, 0 otherwise.
 */
int c_hash_table_has_key(c_hash_map_table *table, const char *key) {
    unsigned int index = hash(key, table->size);
    c_hash_map_table_entry *entry = table->entries[index];
    while (entry) {
        if (strcmp(entry->key, key) == 0) {
            return 1;
        }
        entry = entry->next;
    }
    return 0;
}

/**
 * @brief Add a key-value pair to the hash table.
 *
 * This function adds a key-value pair to the hash table. If the key already exists, it returns an error.
 *
 * @param table The hash table to add the key-value pair to.
 * @param key The key to add.
 * @param value The value to add.
 * @return 0 if the key-value pair was added successfully, 1 if the key already exists.
 */
int c_hash_table_add(c_hash_map_table *table, const char *key, void *value) {
    unsigned int index = hash(key, table->size);
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

/**
 * @brief Get the value associated with a key in the hash table.
 *
 * This function retrieves the value associated with a given key in the hash table.
 *
 * @param table The hash table to search.
 * @param key The key to look for.
 * @return The value associated with the key, or NULL if the key is not found.
 */
void * c_hash_table_get(c_hash_map_table *table, const char *key) {
    unsigned int index = hash(key, table->size);
    c_hash_map_table_entry *entry = table->entries[index];
    while (entry) {
        if (strcmp(entry->key, key) == 0) {
            return entry->value;
        }
        entry = entry->next;
    }
    return NULL;
}