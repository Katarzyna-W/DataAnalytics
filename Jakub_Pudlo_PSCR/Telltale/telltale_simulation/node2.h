#ifndef NODE2_H_
#define NODE2_H_



/* Make this vars public */
extern int diode_request;
extern int diode_in;
extern int node2_status;
extern int node2_enable;



/* Make mutexs for my vars public */
extern pthread_mutex_t node2_enable_mutex;
extern pthread_mutex_t diode_in_mutex;
extern pthread_mutex_t node2_mutex;

void* calculate_node2(void*);
int initialize_node2(void);
#endif /* NODE2_H_ */