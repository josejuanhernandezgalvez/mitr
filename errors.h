#ifndef ERRORS_H
#define ERRORS_H

void out(char* text, int code);
void error(char* text, int code);

#define ERROR_30 error("ERROR: Input file doesn't exist or you don't have permissions to open it", 30);
#define ERROR_31 error("ERROR: You don't have permissions to write on output file", 31);

#endif
