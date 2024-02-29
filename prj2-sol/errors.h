#ifndef ERRORS_H_
#define ERRORS_H_

/** print message specified by fmt, ... + "\n" on stderr... */
void error(const char *fmt, ...);

/** print message specified by fmt, ... + "\n" on stderr and exit */
void panic(const char *fmt, ...);

#endif //ifndef ERRORS_H_