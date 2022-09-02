#include <stdio.h>
#include <pthread.h>

#include "simulation.h"
#include "node1.h"
#include "node2.h"
#include "screen.h"

/* Screen thread function prototype */
void *tScreenThreadFunc(void *);

/* Thread variable */
pthread_t tScreenThread;
/* Thread attributes */
pthread_attr_t aScreenThreadAttr;
/* Screen barrier */
pthread_barrier_t screen_barrier;

/* Screen thread initialization function */
int init_screen() {

	int status;

	/* Initialize barrier */
	pthread_barrier_init(&screen_barrier, NULL, 2);

	/* Initialize attributes structure */
	pthread_attr_init(&aScreenThreadAttr);

	/* Create screen thread */
	if ((status = pthread_create(&tScreenThread, &aScreenThreadAttr, tScreenThreadFunc, NULL))) {
		fprintf(stderr, "Cannot create thread.\n");
		return 0;
	}

	return 0;
}

/*
 *  Screen thread function
 */
void *tScreenThreadFunc(void *cookie) {

	/* Scheduling policy: FIFO or RR */
	int policy = SCHED_FIFO;
	/* Structure of other thread parameters */
	struct sched_param param;

	/* Read modify and set new thread priority */
	param.sched_priority = sched_get_priority_min(policy)+1;
	pthread_setschedparam( pthread_self(), policy, &param);

	/* Receive, identify and replay to message*/
	for (;;) {
		/* Wait until you get pulse */
		pthread_barrier_wait(&screen_barrier);

		/* Put the input and output value to the screen */
		pthread_mutex_lock(&diod_mutex);
		pthread_mutex_lock(&output_mutex);
		pthread_mutex_lock(&engine_mutex);
		pthread_mutex_lock(&node1_mutex);
		pthread_mutex_lock(&node2_mutex);
		printf("\n Talltale status: %d <--- Diode request: %d, Engine status: %d, Node 1 disable counter: %d, Node 2 disable counter: %d \n", talltale_status, diode_request, engine_status, node1_status, node2_status);
		pthread_mutex_unlock(&diod_mutex);
		pthread_mutex_unlock(&output_mutex);
		pthread_mutex_unlock(&engine_mutex);
		pthread_mutex_unlock(&node1_mutex);
		pthread_mutex_unlock(&node2_mutex);
	}

	return 0;
}

