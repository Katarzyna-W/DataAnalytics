#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

#include "simulation.h"
#include "node1.h"

/* Parameters values */
int diode_request;
int diode_in;
int node2_status;
int node2_enable;


pthread_mutex_t node2_enable_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t node2_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t diode_in_mutex = PTHREAD_MUTEX_INITIALIZER;

int initialize_node2(){
    pthread_mutex_lock(&node2_mutex);
	node2_enable = 1;
	pthread_mutex_unlock(&node2_mutex);
    return 0;
}

/**
 * Calculates node2
 */
void* calculate_node2(void *cookie) {

        int policy = SCHED_FIFO;
	/* Structure of other thread parameters */
	struct sched_param param;

	/* Read modify and set new thread priority */
	param.sched_priority = sched_get_priority_max(policy)-3;
	pthread_setschedparam( pthread_self(), policy, &param);



    int temp_en_node2, temp_diod_in;

    pthread_mutex_lock(&node2_mutex);
	temp_en_node2 = node2_enable;
	pthread_mutex_unlock(&node2_mutex);

    pthread_mutex_lock(&diode_in_mutex);
	temp_diod_in = diode_in;
	pthread_mutex_unlock(&diode_in_mutex);


    if(temp_en_node2)
    {
        pthread_mutex_lock(&engine_mutex);
	    diode_request = temp_diod_in;
	    pthread_mutex_unlock(&engine_mutex);

        pthread_mutex_lock(&node2_mutex);
	    node2_status = 0;
	    pthread_mutex_unlock(&node2_mutex);
    }
    else{
        pthread_mutex_lock(&node2_mutex);
	    node2_status += 1;
	    pthread_mutex_unlock(&node2_mutex);
    }
    
}