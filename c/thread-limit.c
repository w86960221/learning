/* compile with:   gcc -lpthread -o thread-limit thread-limit.c */
/* originally from: http://www.volano.com/linuxnotes.html */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

#define MAX_THREADS 100000
int i;

void run(void) {
  sleep(60 * 60);
}

int main(int argc, char *argv[]) {
  int rc = 0;
  pthread_t thread[MAX_THREADS];
  printf("Creating threads ...\n");
  for (i = 0; i < MAX_THREADS && rc == 0; i++) {
    rc = pthread_create(&(thread[i]), NULL, (void *) &run, NULL);
    if (rc == 0) {
      pthread_detach(thread[i]);
      if ((i + 1) % 100 == 0)
    printf("%i threads so far ...\n", i + 1);
    }
    else
    {
      printf("Failed with return code %i creating thread %i (%s).\n",
         rc, i + 1, strerror(rc));

      // can we allocate memory?
      char *block = NULL;
      block = malloc(65545);
      if(block == NULL)
        printf("Malloc failed too :( \n");
      else
        printf("Malloc worked, hmmm\n");
    }
  }
sleep(60*60); // ctrl+c to exit; makes it easier to see mem use
  exit(0);
}
