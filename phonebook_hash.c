#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_hash.h"

/* FILL YOUR OWN IMPLEMENTATION HERE! */

unsigned int BKDRHash(char *str)
{
    unsigned int seed = 131; //131
    unsigned int hash = 0;
    while(*str) {
        hash = hash * seed + (*str++);
    }
    return hash;
}

entry *findName(char lastName[], entry *pHead[])
{
    unsigned int hVal = BKDRHash(lastName) % HASH_SIZE;
    entry *pHead_hVal = pHead[hVal];
    while (pHead_hVal->pNext != NULL) {
        if(strcasecmp(lastName, pHead_hVal->lastName) == 0)
            return pHead_hVal;
        pHead_hVal = pHead_hVal->pNext;
    }
    return NULL;
}

int append(char lastName[], entry *e[])
{
    unsigned int hVal = BKDRHash(lastName) % HASH_SIZE;
    strcpy(e[hVal]->lastName, lastName);
    e[hVal]->pNext = (entry *) malloc(sizeof(entry));
    e[hVal] = e[hVal]->pNext;
    e[hVal]->pNext = NULL;
    return 1;
}
