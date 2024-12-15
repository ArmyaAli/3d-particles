#ifndef LOGGER_H
#define LOGGER_H

typedef enum log_level {
  ALL,
  INFO,
  DEBUG,
  ERROR
} log_level_t;

typedef struct logger {
  log_level_t current_level;
  unsigned int std_out;
} logger_t;

void logger_init(logger_t* logger, log_level_t level);
void log(logger_t* logger, log_level_t level, const char* message);

#endif
