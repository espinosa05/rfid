
#include <utils.h>
#include <signal.h>

#define NULL_TERM_SIZ 1
void write_log(config_t conf, char * restrict str)
{
	char *msg_buf = malloc(strlen(str) + NULL_TERM_SIZ + 1);

	strncpy(msg_buf, str, strlen(str));
	strcat(msg_buf, "\n");

	msg_buf[strlen(str) + NULL_TERM_SIZ] = '\0';
	write(conf->log_file_fd, msg_buf, strlen(msg_buf));

	free(msg_buf);
}
