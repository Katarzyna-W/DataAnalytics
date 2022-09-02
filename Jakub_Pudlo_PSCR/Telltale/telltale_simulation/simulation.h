#ifndef SIMULATION_H_
#define SIMULATION_H_



/* Make this vars public */
extern int talltale_status;




/* Make mutexs for my vars public */

extern pthread_mutex_t output_mutex;
extern pthread_mutex_t diod_mutex;
extern pthread_mutex_t engine_mutex;




void* calculate_talltale(void*);

#endif /* PLANT_H_ */
