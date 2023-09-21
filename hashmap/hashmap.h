/** 
 * CS 5008 - Homework 09
 * Student: Hanru Chen
 * Semester: Spring 2023
*/
#ifndef HASHMAP
#define HASHMAP

#include <stdlib.h>
#include <string.h>
#include <stdio.h> 

typedef struct node
{
    char *key;
    float value;
    struct node *next;
} h_node;

typedef struct ht {
    int size;
    h_node **contents;

} *hashmap;

typedef unsigned long ul;
typedef h_node **hashTable;

/**
 * A hashing algorithm. Students may pick their own
 * but it is recommended they use one of the ones 
 * from the lab. 
*/
ul get_hash(char *str) {
    ul hash = 5381;
    int c;
    while ((c = *str++)) hash = ((hash << 5) + hash) + c; 
    return hash;
}

/**
 * Creates with the specified size.
*/
hashmap map_create(int size) {
    hashmap map = (hashmap)malloc(sizeof(struct ht));
    map->size = size;
    map->contents = (h_node**)malloc(sizeof(h_node*) * size);
    for (int i = 0; i < size; i++) {
        map->contents[i] = NULL;
    }
    return map;
}

/**
 * Gets a value from the hashmap. 
 * If a value is not found, return -1.0F
*/
float map_get(hashmap map, char *key) {
    ul hash = get_hash(key) % map->size;
    h_node *cur = map->contents[hash];
    
    while(cur != NULL) {
        if (strcmp(cur->key, key) == 0) {
            return cur->value;
        }
        cur = cur->next;
    }
    return -1.0F;
}

/**
 * Removes an item from the hashmap, returning
 * the value of the item. If an item
 * is not found to remove, return -1.0F
*/
float map_del(hashmap map, char *key) {
    ul hash = get_hash(key) % map->size;
    h_node *cur = map->contents[hash];
    h_node *prev = NULL;

    while (cur != NULL) {
        if (strcmp(cur->key, key) == 0) {
            float value = cur->value;
            if (prev == NULL) {
                map->contents[hash] = cur->next;
            } else {
                prev->next = cur->next;
            }
            free(cur);
            return value;
        }
        prev = cur;
        cur = cur->next;
    }
    return -1.0F;
}

/**
 * Stores a value into the hashmap. 
 * 1. if a key is already in the map, overwrites it with the new value
 * 2. if the key is not in the map, adds the key/value (node) pair.
*/
void map_put(hashmap map, char *key, float value) {
    ul hash = get_hash(key) % map->size; 
    h_node *cur = map->contents[hash];
    h_node *prev = NULL;

    while (cur != NULL) {
        if (strcmp(cur->key, key) == 0) { // check if already in map.
            cur->value = value; // if it is, overwrite it. 
            return;
        }
        prev = cur;
        cur = cur->next;
    }

    h_node *new_node = (h_node*)malloc(sizeof(h_node));
    new_node->key = (char*)malloc(strlen(key) * sizeof(char)+1);
    new_node->value = value;
    strcpy(new_node->key, key); //to ensure any changes to original key will not affect the key store in hashmap.
    new_node->next = NULL;

    if (prev == NULL){
        map->contents[hash] = new_node;
    } else {
        prev->next = new_node;
    }
}

/**
 * Prints the map in the specified format of
 * {key : value, key : value}
 * Notice there is not a comma after the last
 * value. Refer to lab if needed. It should
 * only produce strings of .2f (two decimals). 
*/
void map_print(hashmap map) {
    printf("{");
    int print_once = 0;
    for (int i = 0; i < map->size; i++) {
        h_node * iter = map->contents[i];
        while (iter != NULL) {
            if (print_once) printf(", ");
            printf("%s : %0.2f", iter->key, iter->value);
            iter = iter->next;
            if(print_once == 0) print_once = 1;
        }
    }
    printf("}\n");
}

/**
 * Frees the map in memory. Make sure
 * to free all the individual nodes. 
*/
void map_free(hashmap map) {
    for (int i = 0; i < map->size; i++) {
        h_node *cur = map->contents[i];
        while (cur != NULL) {
            h_node *tmp = cur->next;
            free(cur);
            cur = tmp;
        }
    }
    free(map->contents);
    free(map);
}


#endif