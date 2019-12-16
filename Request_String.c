#include <stdlib.h>
#include <string.h>
#include "Request_String.h"
char* request_string() {
    char* string;
    char* temporaryString;
    char symbol = ' ';
    int lenthString = 1;

    string = (char*)calloc(lenthString, sizeof(char));

    do {
        symbol = getchar();
        temporaryString = (char*)calloc(lenthString, sizeof(char));
        strncpy(temporaryString, string, lenthString);
        lenthString++;
        free(string);
        string = (char*)calloc(lenthString, sizeof(char));
        strcpy(string, temporaryString);
        free(temporaryString);
        string[lenthString - 2] = symbol;
    } while ((symbol != '\n')&&(symbol != '\0'));
    return string;
}
