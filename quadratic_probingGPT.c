#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10
#define DELETED -1

// Hash function: h(k) = k mod TABLE_SIZE
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Insert a key into the hash table using quadratic probing
void insert(int hashTable[], int key) {
    int index = hashFunction(key);

    // Quadratic probing to find an empty slot
    int i = 0;
    while (hashTable[(index + i * i) % TABLE_SIZE] != -1 && hashTable[(index + i * i) % TABLE_SIZE] != DELETED) {
        i++;
        if (i >= TABLE_SIZE) {
            printf("Table is full, cannot insert %d\n", key);
            return;
        }
    }

    // Insert the key
    hashTable[(index + i * i) % TABLE_SIZE] = key;
    printf("Inserted %d at index %d\n", key, (index + i * i) % TABLE_SIZE);
}

// Search for a key in the hash table using quadratic probing
int search(int hashTable[], int key) {
    int index = hashFunction(key);

    // Quadratic probing to find the key
    int i = 0;
    while (hashTable[(index + i * i) % TABLE_SIZE] != -1) {
        if (hashTable[(index + i * i) % TABLE_SIZE] == key) {
            return (index + i * i) % TABLE_SIZE; // Key found
        }
        i++;
        if (i >= TABLE_SIZE) {
            break; // Reached the table's limit
        }
    }
    return -1; // Key not found
}

// Delete a key from the hash table using quadratic probing
void delete(int hashTable[], int key) {
    int index = search(hashTable, key);

    if (index != -1) {
        // Mark the slot as deleted
        hashTable[index] = DELETED;
        printf("Deleted %d from index %d\n", key, index);
    } else {
        printf("Key %d not found in the hash table\n", key);
    }
}

// Display the hash table
void display(int hashTable[]) {
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] == -1) {
            printf("Index %d: Empty\n", i);
        } else if (hashTable[i] == DELETED) {
            printf("Index %d: Deleted\n", i);
        } else {
            printf("Index %d: %d\n", i, hashTable[i]);
        }
    }
}

int main() {
    int hashTable[TABLE_SIZE];
    
    // Initialize hash table
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1; // -1 indicates an empty slot
    }

    // Inserting keys
    insert(hashTable, 12);
    insert(hashTable, 22);
    insert(hashTable, 42);
    insert(hashTable, 23);

    // Display hash table
    display(hashTable);

    // Searching for a key
    int key = 22;
    int index = search(hashTable, key);
    if (index != -1) {
        printf("Key %d found at index %d\n", key, index);
    } else {
        printf("Key %d not found in the hash table\n", key);
    }

    // Deleting a key
    delete(hashTable, 22);

    // Display hash table after deletion
    display(hashTable);

    return 0;
}