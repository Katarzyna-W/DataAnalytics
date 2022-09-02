#ifndef SCREEN_H_
#define SCREEN_H_

/* Screen barrier */
extern pthread_barrier_t screen_barrier;

/* Function creates screen thread */
int init_screen();

#endif /* SCREEN_H_ */
