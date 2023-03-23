
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>

#include <utils.h>

#define ROOT_DIR 0
#define NO_CLOSE 0

#define FIXME(str) printf("FIXME:\t%s\n", str);

#ifndef STREAM_PATH
#define STREAM_PATH "/dev/stdin"
#endif /* STREAM_PATH */

int main(void)
{
	/* daemonize thread */
	//ASSERT(daemon(ROOT_DIR, NO_CLOSE) == 0);

	config_t conf = init_config();
	//write_log(conf, "daemon running on");

	write_log(conf, "continuing with standard configuration");

	standard_config(conf);

    for(;;)
    {
        read_rfid(conf);
    }


	return EXIT_SUCCESS;
}
