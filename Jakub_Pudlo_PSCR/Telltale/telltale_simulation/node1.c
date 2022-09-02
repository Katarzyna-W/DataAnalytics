#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

#include "simulation.h"
#include "node2.h"

/* Parameters values */
int engine_status;
int engine_in;
int node1_status;
int node1_enable;


pthread_mutex_t node1_enable_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t engine_in_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t node1_mutex = PTHREAD_MUTEX_INITIALIZER;


int initialize_node1(){

    pthread_mutex_lock(&node2_mutex);
	node1_enable = 1;
	pthread_mutex_unlock(&node2_mutex);

    return 0;
}


/**
 * Calculates node1
 */
int *calculate_node1(void *cookie) {

    int policy = SCHED_FIFO;
	/* Structure of other thread parameters */
	struct sched_param param;

	/* Read modify and set new thread priority */
	param.sched_priority = sched_get_priority_max(policy)-4;
	pthread_setschedparam( pthread_self(), policy, &param);


    int temp_en_node1, temp_eng_in;

    pthread_mutex_lock(&node1_mutex);
	temp_en_node1 = node1_enable;
	pthread_mutex_unlock(&node1_mutex);

    pthread_mutex_lock(&engine_in_mutex);
	temp_eng_in = engine_in;
	pthread_mutex_unlock(&engine_in_mutex);


    if(temp_en_node1)
    {
        pthread_mutex_lock(&engine_mutex);
	    engine_status = temp_eng_in;
	    pthread_mutex_unlock(&engine_mutex);

        pthread_mutex_lock(&node1_mutex);
	    node1_status =0;
	    pthread_mutex_unlock(&node1_mutex);
    }
    else{
        pthread_mutex_lock(&node1_mutex);
	    node1_status += 10;
	    pthread_mutex_unlock(&node1_mutex);
    }
    
	return 0;
}