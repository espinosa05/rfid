#include "rfid_reader.h"

#include <sys/types.h>
#include <unistd.h>

#include <utils.h>

#define END_OF_UID '\n'
/* static function declarations */
static void clear_rest_of_buffer(ssize_t *length_until_nl, int stream);


static void clear_rest_of_buffer(ssize_t *length_until_nl, int stream)
{
	char c;
	int length;

	for (length = 0; read(stream, &c, 1) == 1; ++length)
	{
		if (c == END_OF_UID)
			break;
	}

	if (errno != 0)
	{
		/* highly unlikely */
		abort();
	}

	return length;
}

void read_rfid(config_t conf)
{
	char *rfid_uid_buf = malloc(conf->rfid_uid_length);

	ASSERT(rfid_uid_buf);

	ssize_t uid_length = read(conf->istream_fd, conf->rfid_uid_length + 1);

	if (uid_length != 0)
	{
		fprintf(conf->log_file, "invalid rfid string detected: 0x%10x\n",
				rfid_uid_buf);

		free(rfid_uid_buf);
		return;
	}	

	free(rfid_uid_buf);
}


