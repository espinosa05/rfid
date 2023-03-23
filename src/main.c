
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#include <utils.h>

#define ROOT_DIR 0
#define NO_CLOSE 0

#define FIXME(str) printf("FIXME:\t%s\n", str);

int main(int argc, char **argv)
{
	/* daemonize thread */
	ASSERT(daemon(ROOT_DIR, NO_CLOSE) == 0);

	config_t conf = init_config();
	write_log(conf, "daemon running on")
	
	if (argc < 2)
	{
		write_log(conf, "continuing with standard configuration");

		FIXME("parse config file hint: set_stream()");
		standard_config(conf);
	}

	

	return EXIT_SUCCESS;
}
