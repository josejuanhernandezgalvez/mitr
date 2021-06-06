#include <string.h>
#include "filter.h"

#define INPUT_BUFFER_SIZE 16384

char* old;
char* new;

unsigned int match_pos;
unsigned int match_goal;
unsigned int matches;

char output[INPUT_BUFFER_SIZE];
unsigned int output_pos;

void put(char c) {
    if (old[match_pos] == c) {
        if (++match_pos == match_goal) {
            strcpy(&output[output_pos], new);
            output_pos += strlen(new);
            match_pos = 0;
            matches++;
        }
    }
    else {
        strcpy(&output[output_pos], old);
        output_pos += match_pos;
        match_pos = 0;
        output[output_pos++] = c;
    }
}

char* done() {
    output[output_pos] = 0;
    output_pos = 0;
    return output;
}

void init_filter(char* old_text, char* new_text) {
    old = old_text;
    new = new_text;
    match_pos = 0;
    match_goal = strlen(old_text);
    matches = 0;
}


char* write_filter(char* str, int length) {
    for (int i = 0; i < length; ++i)
        put(str[i]);
    return done();
}

char* flush_filter() {
    strcpy(&output[output_pos], old);
    output_pos += match_pos;
    return done();
}

