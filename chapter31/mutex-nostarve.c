#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "common_threads.h"
#include <semaphore.h>

//
// Here, you have to write (almost) ALL the code. Oh no!
// How can you show that a thread does not starve
// when attempting to acquire this mutex you build?
//

typedef struct __ns_mutex_t {
    int turn;
    int count;
    sem_t lock;
    sem_t turnlock;
} ns_mutex_t;

ns_mutex_t m;

void ns_mutex_init(ns_mutex_t *m) {
    sem_init(&m->lock, 0, 1);
    sem_init(&m->turnlock, 0, 1);
    m->turn = 1;
    m->count = 0;
}

void ns_mutex_acquire(ns_mutex_t *m) {
    sem_wait(&m->turnlock);
    int turn = ++m->count;
    while (turn != m->turn) {
        sem_post(&m->turnlock);
        sem_wait(&m->lock);
        sem_wait(&m->turnlock);
    }
    sem_post(&m->turnlock);
}

void ns_mutex_release(ns_mutex_t *m) {
    sem_wait(&m->turnlock);
    m->turn++;
    sem_post(&m->lock);
    sem_post(&m->turnlock);
}


void *worker(void *arg) {
    printf("Started: %lu\n", pthread_self());
    ns_mutex_acquire(&m);
    printf("Got lock: %lu\n", pthread_self());
    ns_mutex_release(&m);
    return NULL;
}

int main(int argc, char *argv[]) {
    printf("parent: begin\n");
    ns_mutex_init(&m);
    pthread_t threads[10];
    for(int i = 0; i < 10; i++) {
        Pthread_create(&threads[i], NULL, worker, NULL);
    }
    for(int i = 0; i < 10; i++) {
        Pthread_join(threads[i], NULL);
    }
    printf("parent: end\n");
    return 0;
}



