#ifndef UTILS_H
#define UTILS_H
#include <string.h>
#include <errno.h>
#include <stdlib.h>

#define ASSERT(cond)							\
	if ((cond))							\
	{								\
		fprintf(stderr, "assertion failed (%s)", #cond);	\
		if (errno != 0)						\
		{							\
			fprintf(stderr, ": %s", strerror(errno));	\
		}							\
		fprintf(stderr, "\n");					\
		abort();						\
	}			

#include "config.h"

#ifdef DEBUG
# define debugln puts
# define debugfmt printf
#else
# define debugln() /* empty */
# define debugfmt() /* empty */
#endif /* DEBUG */

void write_log(config_t conf, char * restrict  str);
#endif /* UTILS_H */
