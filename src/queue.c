#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
        if (q == NULL) return 1;
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
        /* TODO: put a new process to queue [q] */
        if(q->size == MAX_QUEUE_SIZE){
                fprintf(stderr, "Queue is full\n");
                return;
        }
        q->proc[q->size] = proc;
        q->size++;
}

struct pcb_t * dequeue(struct queue_t * q) {
        if (q->size ==0)
	return NULL;
        int i;
        struct pcb_t * proc = q->proc[0];
        for (i = 1; i < q->size -1; i++) {
                q->proc[i] = q->proc[i+1];
        }
        q->size--;
        return proc;
}

