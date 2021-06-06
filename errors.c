#include <fcntl.h>
#include <unistd.h>

#define STDERR 2


void error(char* text, int code) {
    write(STDERR, text, strlen(text));
    exit(code);
}

