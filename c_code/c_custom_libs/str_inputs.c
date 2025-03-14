#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * -- General Info --
 * gets multiple lines of stdin using getline
 * Only works if POSIX is supported by system
 * Usage example: char* buffer = fgetsdyn()
 * 
 * -- types -- 
 * input -> None
 * return -> char* (string collected using getline)
 */
char* getlinesdyn() {
    char *buffer = NULL;        // return buffer (full input)
    size_t content_size = 0;    // contents size
    
    char *line = NULL;          // buffer per line
    size_t line_cap = 0;        // each lines buff capacity
    __ssize_t line_len;         // chars read in each line
    
    // read until EOF or empty line
    while ((line_len = getline(&line, &line_cap, stdin)) != -1) {
        // resize buff, using realloc
        char *new_buffer = realloc(buffer, content_size + line_len + 1); 
        if (new_buffer == NULL) {
            free(buffer);
            free(line);
            perror("Error with allocating new buffer");
            return NULL;
        }
        // set buff to new_buff
        buffer = new_buffer;
        
        // append using memcpy
        memcpy(buffer + content_size, line, line_len);
        content_size += line_len;
        buffer[content_size] = '\0';
    }
    
    // free line
    free(line);
    return buffer;
}

/**
 * -- General Info -- 
 * gets multiple lines of stdin using dyn malloc on a buffer
 * Usage example: char* buffer = fgetsdyn();
 * 
 * -- types -- 
 * input -> None
 * return -> char* (string collected using getchar())
 */
char* fgetsdyn() {
    size_t size = 64; // initial buffer size
    size_t pos = 0; // curr position in input

    // initial buffer memory allocation, c for input size
    char* buffer = malloc(size); 
    int c; 
    
    if (!buffer) {
        perror("Error allocating buffer");
    }
    
    while ((c = getchar()) != EOF) {
        // resize block
        if (pos >= size - 1) {
            size *= 2;
            char* new_buffer = realloc(buffer, size);
            if (!new_buffer) {
                perror("Error on reallocating buffer size...");
                free(buffer);
                return NULL;
            }
            buffer = new_buffer;
            // end resize
        }
        // append character to buffer
        buffer[pos++] = c;
    }

    // add termination character, return inputed lines
    buffer[pos] = '\0';
    return buffer;
}

// Useful testing / usecase info
int main() {
    // ---- uncomment below to get test of getlinesdyn() ----
    char* buffer = getlinesdyn();
    fputs(buffer, stdout);
    free (buffer);
    // ------------------------------------------------------

    // // ---- uncomment below to get test of fgetsdyn() -------
    // char* buffer = fgetsdyn();
    // fputs(buffer, stdout);
    // free(buffer);
    // // ------------------------------------------------------
}