#include <sched.h>
#include <stdio.h>

int main(void) {
  int policy;

  /* get our scheduling policy */
  policy = sched_getscheduler(0);

  switch(policy) {
  case SCHED_OTHER:
    printf("Policy is normal\n");
    break;
  case SCHED_RR:
    printf("Policy is round-robin\n");
    break;
  case SCHED_FIFO:
    printf("Policy is first-in, first-out\n");
    break;
  case -1:
    perror("sched_getscheduler");
    break;
  default:
    fprintf(stderr, "unkwnow policy!\n");
  }
}
