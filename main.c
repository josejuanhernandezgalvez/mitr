#include <stdlib.h>
#include <fcntl.h>
#include "filter.h"
#include "processor.h"
#include "utils.h"
#include "errors.h"

#define STDIN 1

#define OPTION 1
#define OLD_TEXT 1
#define NEW_TEXT 2
#define TEXT 2
#define INPUT 3
#define OUTPUT 4


char buffer[16];
char* toString(int n) {
    return itoa(n, buffer, 10);
}

void print(char* text) {
    write(STDIN, text, strlen(text));
}

void terminate(int n, char* text) {
    print(toString(n));
    print(text);
    exit(0);
}

int main(int argc, char** argv) {
    int ok = (argc == 4 && argv[1][0] == '-') || (argc == 5);
    if (!ok) error("USES\n"
                        "  mitr old_text new_txt input_file output_file  -->  Replace old_text by_new_text from input_file into output_file\n"
                        "  mitr -d text input_file output_file  -->  Delete text from input_file into output_file\n"
                        "  mitr -i text input_file  -->  Count text occurrences in input_file\n\n", 0);


    if (equals(argv[OPTION], "-i")) {
        init_filter(argv[TEXT], "");
        int n = process(argv[INPUT], "");
        terminate(n, " occurrences found\n");
    }

    if (equals(argv[OPTION], "-d")) {
        init_filter(argv[TEXT], "");
        int n = process(argv[INPUT], argv[OUTPUT]);
        terminate(n, " deletes done\n");
    }

    init_filter(argv[OLD_TEXT], argv[NEW_TEXT]);
    int n = process(argv[INPUT], argv[OUTPUT]);
    terminate(n, " replacements done\n");
}

