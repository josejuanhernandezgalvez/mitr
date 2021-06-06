#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "processor.h"
#include "filter.h"
#include "utils.h"
#include "errors.h"

#define INPUT_BUFFER_SIZE 1024
#define TEMP "temp"

char *as_temp(char* filename) {
    rename(filename, TEMP);
    return TEMP;
}

int mode(char* filename) {
    struct stat info_stat;
    int error = stat(filename, &info_stat);
    return error == 0 ? O_TRUNC | O_WRONLY : O_CREAT | O_WRONLY;
}

int process(char* input, char* output) {
    if (equals(input, output)) input = as_temp(input);
    int f_in = open(input, O_RDONLY);
    if (f_in < 0) ERROR_30;

    int f_out = strlen(output) > 0 ? open(output, mode(output), S_IRUSR | S_IWUSR) : 0;
    if (f_out < 0) ERROR_31;

    char in[INPUT_BUFFER_SIZE];
    int length;
    do {
        length = read(f_in, in, INPUT_BUFFER_SIZE);
        char* out = write_filter(in, length);
        if (f_out != 0) write(f_out, out, strlen(out));

    } while (length > 0);

    close(f_in);
    if (f_out != 0) close(f_out);
    if (equals(input, TEMP)) remove(input);
    return matches;
}

