#include <stdio.h>
#include <time.h>
#include "utils.h"

void LOG_ERROR(const char* message) {
    fprintf(stderr, "[ERROR] %s\n", message);
}

void LOG_INFO(const char* message) {
    printf("[INFO] %s\n", message);
}

void write_to_log_file(const char* message) {
    // Buffer to hold the filename
    char filename[64];

    // Get the current time
    time_t now = time(NULL);
    struct tm* t = localtime(&now);

    // Format the filename as "LOGFILE_YYYY-MM-DD_HHMM.txt"
    strftime(filename, sizeof(filename), "LOGFILE_%Y-%m-%d_%H%M.txt", t);

    // Open the file in append mode
    FILE* file = fopen(filename, "a");
    if (file == NULL) {
        fprintf(stderr, "Error: Unable to open log file '%s'\n", filename);
        return;
    }

    // Write the message to the file
    fprintf(file, "%s\n", message);
    fclose(file);
}