#include "errors.h"

#include <cstdarg>
#include <cstdio>
#include <cstdlib>

/** print message specified by fmt, ... + "\n" on stderr... */
void error(const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  vfprintf(stderr, fmt, ap);
  fprintf(stderr, "\n");
  va_end(ap);
}

/** print message specified by fmt, ... + "\n" on stderr and exit */
void panic(const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  vfprintf(stderr, fmt, ap);
  fprintf(stderr, "\n");
  va_end(ap);
  exit(1);
}