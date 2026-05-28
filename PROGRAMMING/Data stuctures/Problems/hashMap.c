#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Entry {
    char *key;
    int value;
    struct Entry *next;
} Entry;

typedef struct HashTable {
    size_t capacity;
    size_t size;
    Entry **buckets;
} HashTable;

// Create a new table
HashTable *ht_create(size_t capacity) {
    HashTable *table = malloc(sizeof(HashTable));
    table->capacity = capacity;
    table->size = 0;
    table->buckets = calloc(capacity, sizeof(Entry*));
    return table;
}

// Hash function for string key
size_t ht_hash(const char *key, size_t capacity) {
    unsigned long hash = 5381;
    int c;
    while ((c = *key++))
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    return hash % capacity;
}

// Insert key/value
void ht_set(HashTable *table, const char *key, int value) {
    size_t idx = ht_hash(key, table->capacity);
    Entry *entry = table->buckets[idx];
    while (entry) {
        if (strcmp(entry->key, key) == 0) {
            entry->value = value; // update
            return;
        }
        entry = entry->next;
    }
    // not found → insert new
    Entry *newEntry = malloc(sizeof(Entry));
    newEntry->key = strdup(key);
    newEntry->value = value;
    newEntry->next = table->buckets[idx];
    table->buckets[idx] = newEntry;
    table->size++;
}

// Get value by key
int *ht_get(HashTable *table, const char *key) {
    size_t idx = ht_hash(key, table->capacity);
    Entry *entry = table->buckets[idx];
    while (entry) {
        if (strcmp(entry->key, key) == 0)
            return &entry->value;
        entry = entry->next;
    }
    return NULL; // not found
}

// Free table
void ht_free(HashTable *table) {
    for (size_t i = 0; i < table->capacity; i++) {
        Entry *entry = table->buckets[i];
        while (entry) {
            Entry *next = entry->next;
            free(entry->key);
            free(entry);
            entry = next;
        }
    }
    free(table->buckets);
    free(table);
}

int main(void) {
    HashTable *ht = ht_create(50);
    ht_set(ht, "apple", 5);
    ht_set(ht, "banana", 12);
    ht_set(ht, "orange", 7);

    int *v = ht_get(ht, "mango");
    if (v) printf("banana => %d\n", *v);
    else    printf("banana not found\n");

    ht_free(ht);
    return 0;
}
