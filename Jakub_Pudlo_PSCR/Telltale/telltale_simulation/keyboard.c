#include <stdio.h>
#include <pthread.h>
#include <mqueue.h>

#include "simulation.h"
#include "node1.h"
#include "node2.h"
#include "keyboard.h"

/* Keyboard thread function prototype */
void *tISRThreadFunc(void *);

/* Thread variable */
pthread_t tISRThread;
/* Thread attributes structure */
pthread_attr_t aISRThreadAttr;
/* Message Queue for sign */
mqd_t	keyboardMQ;
struct	mq_attr keyboardMQAttr;

/**
 * Keyboard thread initialization fucntion
 */
int init_keyboard() {

	int status;

	/* Initialize attributes structure */
	pthread_attr_init(&aISRThreadAttr);

	/* Start thread */
	if ((status = pthread_create(&tISRThread, NULL, tISRThreadFunc, &aISRThreadAttr))) {
		fprintf(stderr, "Cannot create thread.\n");
		return 0;
	}

	/* Set Message Queue attributes */
	keyboardMQAttr.mq_maxmsg = 10;
	keyboardMQAttr.mq_msgsize = sizeof(char);

	/* Create Message Queue */
	if ((keyboardMQ = mq_open("/keyboardMQ", O_CREAT | O_RDWR, 00600, &keyboardMQAttr)) == -1) {
		fprintf(stderr, "Creation of the mqueues failed\n");
		return 0;
	}

	return 0;
}

/**
 *  Keyboard thread function
 */
void *tISRThreadFunc(void *cookie) {

	/* sign */
	char c;
	/* Scheduling policy: FIFO or RR */
	int policy = SCHED_FIFO;
	/* Structure of other thread parameters */
	struct sched_param param;

	/* Read modify and set new thread priority */
	param.sched_priority = sched_get_priority_max(policy)-1;
	pthread_setschedparam( pthread_self(), policy, &param);

	/* Receive, identify and replay to message*/
	for (;;) {
		/* Wait from pulse from keyboard */
		mq_receive(keyboardMQ, (char *)&c, sizeof(char), NULL);

		/* Decide what to do */
		int temp_n1,temp_n2, temp_diode, temp_engine;
		if (c == '1') {
			pthread_mutex_lock(&node1_enable_mutex);
			node1_enable = !node1_enable;
			temp_n1 = node1_enable;
			pthread_mutex_unlock(&node1_enable_mutex);

			if (temp_n1)printf("Node1 is enable");
			else printf("Node1 is disable");

		} else if (c == '2') {
			pthread_mutex_lock(&node2_enable_mutex);
			node2_enable = !node2_enable;
			temp_n2 = node2_enable;
			pthread_mutex_unlock(&node2_enable_mutex);

			if (temp_n2)printf("Node 2 is enable");
			else printf("Node 2 is disable");

		} else if (c == '+') {
			pthread_mutex_lock(&diode_in_mutex);
			diode_in = !diode_in;
			temp_diode = diode_in;
			pthread_mutex_unlock(&diode_in_mutex);

			if (temp_diode) printf("Diode signal = 1");
			else printf("Diode signal = 0");

		} else if (c == '-') {
			pthread_mutex_lock(&engine_in_mutex);
			engine_in = !engine_in;
			temp_engine = engine_in;
			pthread_mutex_unlock(&engine_in_mutex);
			
			if (temp_engine) printf("Engine signal = 1");
			else printf("Engine signal = 0");

		} else {
			printf("Unrecognized value\n");
		}
	}

	return 0;
}
