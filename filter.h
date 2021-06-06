#ifndef FILTER_H
#define FILTER_H

void init_filter(char* old_text, char* new_text);
char* write_filter(char* str, int length);
char* flush_filter();

unsigned int matches;

#endif
