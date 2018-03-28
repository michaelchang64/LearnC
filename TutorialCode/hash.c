#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE (20)

typedef struct node {
    char *string;
    struct node *next;
} node;

typedef struct hash_table {
    int size; /* the size of the table */
    node **table; /* the table elements */
} hash_table;

hash_table *create_hash_table() {
    hash_table *new_table;
    if (SIZE < 1)
        return NULL; //invalid SIZE for table

    // Attempt to allocate memory for the table structure
    if ((new_table = malloc(sizeof(hash_value_t))) == NULL) {
        return NULL;
    }

    // Attempt to allocate memory for the table itself
    if ((new_table->table = malloc(sizeof(node *) * SIZE)) == NULL) {
        return NULL;
    }

    // Initialize the elements of the table
    for(i=0; i<SIZE; i++)
        new_table->table[i] = NULL;

    // Set the table's SIZE
    new_table->SIZE = SIZE;

    return new_table;
}

hash_table *my_hash_table;
int SIZE_of_table = SIZE;
my_hash_table = create_hash_table(SIZE_of_table);

unsigned int hash(hash_table *hashtable, char *str) {
    unsigned int hashval = 0; // we start our hash out at 0

    /* for each character, we multiply the old hash by 31 and add the current
    * character. Remember that shifting a number left is equivalent to
    * multiplying it by 2 raised to the number of places shifted. So we
    * are in effect multiplying hashval by 32 and then subtracting hashval.
    * Why do we do this? Because shifting and subtraction are much more
    * efficient operations than multiplication.
    */
    for(; *str != '\0'; str++)
        hashval = *str + (hashval << 5) - hashval;

    /* we then return the hash value mod the hashtable SIZE so that it will
    * fit into the necessary range
    */
    return hashval % hashtable->SIZE;
}

node *lookup_string(hash_table *hashtable, char *str) {
    node *list;
    unsigned int hashval = hash(hashtable, str);

    /* Go to the correct list based on the hash value and see if str is
    * in the list. If it is, return a pointer to the list element.
    * If it isn't, the item isn't in the table, so return NULL.
    */
    for(list = hashtable->table[hashval]; list != NULL; list = list->next) {
        if (strcmp(str, list->str) == 0)
            return list;
    }
    return NULL;
}

int add_string(hash_table *hashtable, char *str) {
    node *new_list;
    node *current_list;
    unsigned int hashval = hash(hashtable, str);

    /* Attempt to allocate memory for list */
    if ((new_list = malloc(SIZEof(node))) == NULL) return 1;

    /* Does item already exist? */
    current_list = lookup_string(hashtable, str);
    /* item already exists, don't insert it again. */
    if (current_list != NULL) return 2;
    /* Insert into list */
    new_list->str = strdup(str);
    new_list->next = hashtable->table[hashval];
    hashtable->table[hashval] = new_list;

    return 0;
}

int delete_string(hash_table *hashtable, char *str) {
    int i;
    node *list, *prev;
    unsigned int hashval = hash(str);

    /* find the string in the table keeping track of the list item
    * that points to it
    */
    for(prev=NULL, list=hashtable->table[hashval];
    list != NULL && strcmp(str, list->str);
    prev = list,
    list = list->next);

    /* if it wasn't found, return 1 as an error */
    if (list==NULL) return 1; /* string does not exist in table */

    /* otherwise, it exists. remove it from the table */
    if (prev==NULL) hashtable[hashval] = list->next;
    else prev->next = list->next;

    /* free the memory associate with it */
    free(list->str);
    free(list);

    return 0;
}

int count_strings(hash_table *hashtable) {
    int i, count = 0;
    node *list;

    /* error check to make sure hashtable exists */
    if (hashtable==NULL) return -1;

    /* go through every index and count all list elements in each index */
    for(i=0; i<hashtable->SIZE; i) {
        for(list=hashtable[i]; list != NULL; list = list->next)
            count;
    }
    return count;
}

void free_table(hash_table *hashtable) {
    int i;
    node *list, *temp;

    if (hashtable == NULL) return;

    // Free the memory for every item in the table, including the
    // strings themselves.
    for(i=0; i < hashtable->SIZE; i++) {
        list = hashtable->table[i];
        while(list!=NULL) {
            temp = list;
            list = list->next;
            free(temp->str);
            free(temp);
        }
    }

    // Free the table itself
    free(hashtable->table);
    free(hashtable);
}
