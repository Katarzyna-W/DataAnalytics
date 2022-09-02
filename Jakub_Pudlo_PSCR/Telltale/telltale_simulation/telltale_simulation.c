#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mqueue.h>
#include <pthread.h>
#include <time.h>

#include "simulation.h"
#include "screen.h"
#include "keyboard.h"
#include "logger.h"
#include "periodic.h"


/*
 * Main project function
 */
int main(int argc, char *argv[]) {

	/* Char that we get from keyboard*/
    char c;

    /* Init screen thread */
    init_screen();
    /* Init keyboard thread */
	init_keyboard();
	/* Init logger thread */
	init_logger();
	/* Start periodic task */
	init_periodic();

	/* Get the char from keyboard and send it to keyboard thread */
	while(c = getc(stdin)) {

		if (c == 'q') {
			break;
		} else if (c == '\n') {
			continue;
		} else {
			mq_send(keyboardMQ, (const char *)&c, sizeof(char), 0);
		}
	}

  	/* Close logger thread */
	finalize_logger();

	return EXIT_SUCCESS;
}

