#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "book.h"

int parse_book(char *line, Book *book) {
    char *token;
    int field = 0;
    token = strtok(line, ";");
    while (token != NULL && field < 8) {
        switch (field) {
            case 0: strncpy(book->title, token, MAX_STR-1); book->title[MAX_STR-1] = '\0'; break;
            case 1: strncpy(book->surname, token, MAX_STR-1); book->surname[MAX_STR-1] = '\0'; break;
            case 2: strncpy(book->name, token, MAX_STR-1); book->name[MAX_STR-1] = '\0'; break;
            case 3: book->year = atoi(token); break;
            case 4: strncpy(book->publisher, token, MAX_STR-1); book->publisher[MAX_STR-1] = '\0'; break;
            case 5: book->cost = atof(token); break;
            case 6: book->price = atof(token); break;
            case 7: book->profit = atof(token); break;
        }
        field++;
        token = strtok(NULL, ";");
    }
    return (field == 8); 
}

void fprint_book(FILE *f, const Book *book) {
    fprintf(f, "%s;%s;%s;%d;%s;%.2f;%.2f;%.2f\n",
            book->title,
            book->surname,
            book->name,
            book->year,
            book->publisher,
            book->cost,
            book->price,
            book->profit);
}

int surname_starts_with_k(const char *surname) {
    if (surname == NULL) return 0;
    return (strncmp(surname, "К", strlen("К")) == 0);
}
