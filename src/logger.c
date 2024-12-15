#include "logger.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <unistd.h>

const char* log_level_str[] = {
 "ALL" ,
 "INFO" ,
 "DEBUG" ,
 "ERROR"
};

const char* log_format = "[%s]:[%s]: %s\n";

void logger_init(logger_t* logger, log_level_t level) {
  logger->current_level = level;
  logger->std_out = 1;
}

// TODO(Ali): Define a maximum logfile size
// TODO(Ali): start overflowing logs to new file
// TODO(Ali): timestamp log files
void log(logger_t* logger, log_level_t level, const char* message) {
  // Handle time
  time_t rawtime;
  struct tm* timeinfo;
  char time_buffer[80];

  time(&rawtime);
  timeinfo = localtime(&rawtime);
  // 2024-12-15T11:27:58Z ISO time
  strftime(time_buffer, 80, "%Y-%m-%dT%I:%M:%SZ", timeinfo);

  // check if log directory exists
  struct stat st = {0};
  if (stat("./log", &st) == -1) mkdir("./log"); 

  // Open the file descriptor for writing
  FILE* file = fopen("./log/particle.log", "a");;
  if (file == NULL) {
    perror("Error opening file");
    return;
  }
  fprintf(file, log_format, log_level_str[logger->current_level], time_buffer, message);
  if(logger->std_out) {
    fprintf(stdout, log_format, log_level_str[logger->current_level], time_buffer, message);
  }
  // Close the file
  if (fclose(file) != 0) {
      perror("Error closing file");
      return; 
  }
}




