#ifndef RFID_CONFIG_H
#define RFID_CONFIG_H

#include <stddef.h>
#include <pthread.h>

#define CONFIG_DIR_PREFIX "/etc/rfid/"

#ifndef CONFIG_PATH
# define CONFIG_PATH CONFIG_DIR_PREFIX "rfid.yml"
#endif /* LOGFILE_PATH */

/* struct definition */
struct config_struct_def
{
	int 	rfid_uid_length;
	char 	*log_file_path;
	int 	log_file_fd;
	int 	config_file_fd;
	int	istream_fd;
	char 	istream_path;
	char 	*config_file_path;
};

typedef struct config_struct_def * config_t;

config_t init_config();
void delete_config(config_t conf);

void set_stream(config_t conf, char *stream_path);
void standard_config(config_t conf);

#endif /* RFID_CONFIG_H */
