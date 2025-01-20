#include <stdio.h>
#include <stdlib.h>
#include <mqueue.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

struct msg_buffer
{
	long msg_type;
	char msg_text[100];
};

int main() 
{
	mqd_t mq;
	const char *queue_name = "/my_queue";
	struct msg_buffer message;

	mq = mq_open (queue_name, O_RDONLY);
	if (mq == (mdq_t) - 1)
	{
			perror ("mq_open");
			exit (EXIT_FAILURE);
	}


	// Receive the message
	if (mq_receive (mq, message.msg_text, sizeof (message.msg_text),
				&message.msg_type) == -1)
	{
			perror("mq_receive");
			mq_close(mq);
			exit (EXIT_FAILURE);
	}

	printf ("Message received: %s\n", message.msg_text);

	mq_close (mq);
	mq_unlink (queue_name);

	return 0;

}
