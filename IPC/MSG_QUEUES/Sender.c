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

int main(void) 
{

	mqd_t mq;
	struct mq_attr attr;
	const char *queue_name = "/my_queue";
	struct msg_buffer message;


	// define attres for the message queue
	attr.mq_flags = 0;
	attr_mq_maxmsg = 120;
	attr.mq_msgsize = sizeof (message.msg_text);
	attr.mq_curmsgs = 0;

	mq = mq_open (queue_name, O_WRONLY | O_CREAT, 0666, &attr);
	if (mq == (mqd_t) - 1)
	{
		perror("mq_open");
		exit (EXIT_FAILURE);
	}

	// Prepare the message
	message.msg_type = 1;
	strcpy (message.msg_text, "Hello, Message Queue!");

	if (mq_send (mq, message.msg_text, strlen (message.msg_text) + 1, 
				message.msg_type) == -1)
	{
			perror ("mq_send");
			mq_close (mq);
			exit (EXIT_FAILURE);
	}
	
	printf ("Message sent: %s\n", message.msg_text);

	mq_close (mq);

	return 0;

}
