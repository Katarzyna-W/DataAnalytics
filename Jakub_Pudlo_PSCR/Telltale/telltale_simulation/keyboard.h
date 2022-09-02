#ifndef KEYBOARD_H_
#define KEYBOARD_H_

/* Make keyboard message queue public */
extern mqd_t keyboardMQ;

/* Function initialize keyboard thread */
int init_keyboard();

#endif /* KEYBOARD_H_ */
