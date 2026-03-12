#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book.h"

#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        return 1;
    }

    const char *input_filename = argv[1];
    const char *output_filename = argv[2];

    FILE *in = fopen(input_filename, "r");
    if (!in) {
        perror("Error opening input file");
        return 1;
    }

    FILE *out = fopen(output_filename, "w");
    if (!out) {
        perror("Error opening output file");
        fclose(in);
        return 1;
    }

    char line[MAX_LINE];
    int line_num = 0;
    int count_filtered = 0;

    while (fgets(line, sizeof(line), in)) {
        line_num++;
        line[strcspn(line, "\n")] = 0;

        Book book;
        if (!parse_book(line, &book)) {
            fprintf(stderr, "Warning: line %d has invalid format, skipped.\n", line_num);
            continue;
        }

        if (surname_starts_with_k(book.surname)) {
            fprint_book(out, &book);
            count_filtered++;
        }
    }

    fclose(in);
    fclose(out);

    printf("Filtered %d books written to %s\n", count_filtered, output_filename);
    return 0;
}
