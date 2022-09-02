#ifndef NODE1_H_
#define NODE1_H_



/* Make this vars public */
extern int engine_status;
extern int engine_in;
extern int node1_status;
extern int node1_enable;



/* Make mutexs for my vars public */

extern pthread_mutex_t node1_enable_mutex;
extern pthread_mutex_t engine_in_mutex;
extern pthread_mutex_t node1_mutex;

void* calculate_node1(void*);
int initialize_node1(void);
#endif /* NODE1_H_ */