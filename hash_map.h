#ifndef C_MAP_HASH_MAP_LIBRARY_H
#define C_MAP_HASH_MAP_LIBRARY_H

#define C_HASH_MAP_ERROR_KEY_ALREADY_DEFINED 1

/**
 * @brief Hash Table Entry Structure
 *
 * This structure represents an entry in the hash table.
 * Each entry contains a key-value pair and a pointer to the next entry in the same bucket.
 */
typedef struct {
    char * key; /**< The key associated with the entry */
    void * value; /**< The value associated with the entry */
    struct c_hash_map_table_entry * next; /**< Pointer to the next entry in the same bucket */
} c_hash_map_table_entry;

/**
 * @brief Hash Table Structure
 *
 * This structure represents the hash table itself.
 * It contains an array of pointers to the entries.
 */
typedef struct {
    c_hash_map_table_entry **entries; /**< Array of pointers to the hash table entries */
    int size
} c_hash_map_table;

/**
 * @brief Hash function
 *
 * This function computes the hash value for a given key.
 *
 * @param key The key to hash
 * @return The computed hash value
 */
unsigned int hash(const char *key);

/**
 * @brief Create a new hash table
 *
 * @param {int} size The size of the hash table
 *
 * @return A pointer to the newly created hash table
 */
c_hash_map_table *hash_table_new(int size);

/**
 * @brief Check if a key exists in the hash table
 *
 * This function checks whether a given key is present in the hash table.
 *
 * @param table The hash table to check
 * @param key The key to look for
 * @return 1 if the key exists, 0 otherwise
 */
int hash_table_has_key(c_hash_map_table *table, const char *key);

/**
 * @brief Add a key-value pair to the hash table
 *
 * @param {c_hash_map_table *} table The hash table to add the key-value pair to
 * @param {char *} key The key to add
 * @param {void *} value The value to add
 *
 * @return {int} 0 if the key-value pair was added successfully, 1 if the key already exists
 */
int hash_table_add(c_hash_map_table *table, const char *key, void *value);

#endif //C_MAP_HASH_MAP_LIBRARY_H