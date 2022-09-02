#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

#include "simulation.h"
#include "node1.h"
#include "node2.h"

/* Parameters values */

int talltale_status;




/* Mutex */
pthread_mutex_t output_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t diod_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t engine_mutex = PTHREAD_MUTEX_INITIALIZER;



int initialize_telltale(){
    return 0;
}



/**
 * Calculates talltale 
 */
 void* calculate_talltale(void *cookie) {

	int policy = SCHED_FIFO;
	/* Structure of other thread parameters */
	struct sched_param param;

	/* Read modify and set new thread priority */
	param.sched_priority = sched_get_priority_max(policy)-2;
	pthread_setschedparam( pthread_self(), policy, &param);

	int temp_status, temp_diode, temp_engine, temp_node1, temp_node2;

	/* Read input value */
	pthread_mutex_lock(&diod_mutex);
	temp_diode = diode_request;
	pthread_mutex_unlock(&diod_mutex);

	pthread_mutex_lock(&engine_mutex);
	temp_engine = engine_status;
	pthread_mutex_unlock(&engine_mutex);

	pthread_mutex_lock(&node1_mutex);
	temp_node1 = node1_status;
	pthread_mutex_unlock(&node1_mutex);

	pthread_mutex_lock(&node2_mutex);
	temp_node2 = node2_status;
	pthread_mutex_unlock(&node2_mutex);

	if(temp_node1||temp_node2>=50)temp_status=1;
	else if (temp_engine&&temp_diode)temp_status=1;
	else temp_status = 0;
	
	/* Make output public */
	pthread_mutex_lock(&output_mutex);
	talltale_status = temp_status;
	pthread_mutex_unlock(&output_mutex);

}

