#include <stdio.h>
#include <pthread.h>
#include <mqueue.h>

#include "logger.h"
#include "simulation.h"
#include "node1.h"
#include "node2.h"

/* Logger thread prototype */
void *tLoggerThreadFunc(void *);

/* Mqueue variable */
mqd_t outputMQueue;
/* Mqueue attributes structure */
struct	mq_attr outputMQueueAttr;
/* Thread variable */
pthread_t tLoggerThread;
/* Thread attributes structure */
pthread_attr_t aLoggerThreadAttr;


/**
 * Function crates logger thread
 */
int init_logger() {

	int status;

	/* Initialize attributes structure */
	pthread_attr_init(&aLoggerThreadAttr);

	/* Set Message Queue size */
	outputMQueueAttr.mq_maxmsg = 2048;
	outputMQueueAttr.mq_msgsize = sizeof(int);

	/* Create Message Queue */
	if ((outputMQueue = mq_open("/outputMQ", O_CREAT | O_RDWR, 777, &outputMQueueAttr)) == -1) {
		fprintf(stderr, "Creation of the mqueue failed.\n");
		return 0;
	}

	/* Create logger thread */
	if ((status = pthread_create( &tLoggerThread, NULL, tLoggerThreadFunc, &aLoggerThreadAttr))) {
		fprintf(stderr, "Cannot create thread.\n");
		return 0;
	}

	return 0;
}

/**
 * Finalize logger
 */
int finalize_logger() {

	/* Close Message Queue */
	mq_close(outputMQueue);

	return 0;
}

/**
 * Logger thread function
 */
void *tLoggerThreadFunc(void *cookie) {

	/* Output file descriptor */
	FILE * output_file;
	double i;

	/* Scheduling policy: FIFO or RR */
	int policy = SCHED_FIFO;
	/* Structure of other thread parameters */
	struct sched_param param;

	/* Read modify and set new thread priority */
	param.sched_priority = sched_get_priority_min(policy);
	pthread_setschedparam( pthread_self(), policy, &param);

	/* Set the fiel header */
	output_file = fopen("telltale_result.txt", "w");
	fprintf(output_file, "Telltale status: \n");
	fclose(output_file);

	for (;;) {
		/* Wait until something will appears in queue */
		mq_receive(outputMQueue, (char *)&i, sizeof(int), NULL);

		/* Append file with new data */
		output_file = fopen("telltale_result.txt", "a");
		fprintf(output_file, "%d\n", i);
		fclose(output_file);
	}

	return 0;
}
