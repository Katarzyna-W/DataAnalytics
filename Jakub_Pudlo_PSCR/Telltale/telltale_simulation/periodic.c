#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>
#include <time.h>
#include <errno.h>
#include <mqueue.h>

#include "logger.h"
#include "simulation.h"
#include "node1.h"
#include "node2.h"
#include "screen.h"
#include "periodic.h"

/* Thread function prototype */
void *tPeriodicThreadFunc(void *);
void *Node1(void *);
void *Node2(void *);
void *Telltale(void *);
/* Thread counter */
int i = 0;


/**
 * Function starts periodic thread
 */
int init_periodic() {

	int status;

	/* Thread attributes variable */
	pthread_attr_t aPeriodicThreadAttr;
	/* Structure with time values */
	struct	itimerspec timerSpecStruct;
	/* Timer variable */
	timer_t	timerVar;
	/* Signal variable */
	struct	sigevent timerEvent;

	/* Initialize thread attributes structure */
	pthread_attr_init(&aPeriodicThreadAttr);

	/* Initialize event to create thread */
	timerEvent.sigev_notify = SIGEV_THREAD;
    timerEvent.sigev_notify_function = tPeriodicThreadFunc;
	timerEvent.sigev_notify_attributes = &aPeriodicThreadAttr;

	/* Create timer */
  	if ((status = timer_create(CLOCK_REALTIME, &timerEvent, &timerVar))) {
  		fprintf(stderr, "Error creating timer : %d\n", status);
  		return 0;
  	}

	/* Set up timer structure with time parameters */
	timerSpecStruct.it_value.tv_sec = 1;
	timerSpecStruct.it_value.tv_nsec = 0;
	timerSpecStruct.it_interval.tv_sec = 0;
	timerSpecStruct.it_interval.tv_nsec = 50000000;

	/* Initialize plant */
	initialize_telltale();
	initialize_node1();
	initialize_node2();


	/* Change timer parameters and run */
	timer_settime( timerVar, 0, &timerSpecStruct, NULL);

	return 0;
}

/*
 *  Periodic thread function
 */
void *tPeriodicThreadFunc(void *cookie) {

	pthread_t TTB, N1, N2;
	/* Scheduling policy: FIFO or RR */
	int policy = SCHED_FIFO;
	/* Structure of other thread parameters */
	struct sched_param param;

	/* Read modify and set new thread priority */
	param.sched_priority = sched_get_priority_max(policy);
	pthread_setschedparam( pthread_self(), policy, &param);

	/* Calculate talltale */

	pthread_create(&TTB, NULL, *calculate_talltale, NULL);
	pthread_detach(TTB);

	/* Send the talltale output to the logger */
	pthread_mutex_lock(&output_mutex);
	mq_send(outputMQueue, (const char *)&talltale_status, sizeof(int), 0);
	pthread_mutex_unlock(&output_mutex);


	i++;
	if (!(i%2)) {
		pthread_create(&N1, NULL, calculate_node2, NULL);
		pthread_detach(N1);
	}
	if (!(i%20)) {
		pthread_create(&N2, NULL, calculate_node1, NULL);
		pthread_detach(N2);
	}

	/* Wake up screen thread, it knows what to do */
	
	if (!(i%50)) {
		i = 0;
		pthread_barrier_wait(&screen_barrier);
	}


	return 0;
}
