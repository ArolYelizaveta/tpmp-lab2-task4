#ifndef BOOK_H
#define BOOK_H

#define MAX_STR 256

typedef struct {
    char title[MAX_STR];
    char surname[MAX_STR];
    char name[MAX_STR];
    int year;
    char publisher[MAX_STR];
    double cost;
    double price;
    double profit;
} Book;

int parse_book(char *line, Book *book);

void fprint_book(FILE *f, const Book *book);

int surname_starts_with_k(const char *surname);

#endif
