#include <config.h>
#include <unistd.h>
#include <fcntl.h>

config_t init_config()
{
	config_t conf = malloc(sizeof(struct config_struct_def));

	memset(conf, 0, sizeof(struct config_struct_def));

	conf->config_file_path = CONFIG_PATH;
	conf->config_file_fd = open(conf->config_file_path, O_RDONLY);

	return conf;
}

void set_stream(config_t conf, char *stream_path)
{
	conf->istream_path = stream_path;
	conf->istream_fd = open(conf->istream_path, O_RDONLY);

	ASSERT(conf->istream_fd != -1);
}

ssize_t delete_config(config_t conf)
{
	free(conf);
}

void standard_config(config_t conf)
{
	conf->log_file_path = "log";
	conf->log_file_fd = open(conf->log_file_path, O_RDWR);

	if (conf->log_file_fd < 0)
	{
		/* create */
		conf->log_file_fd = open(conf->log_file_path,
				O_CREAT | O_RDWR);

		ASSERT(conf->log_file_fd != -1);
	}

	conf->istream_fd = STDIN_FILENO;
}
