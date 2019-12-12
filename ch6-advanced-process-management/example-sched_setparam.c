#include <sched.h>
#include <stdio.h>

int main(void) {
  struct sched_param sp, sp0, sp1;
  int ret, ret0, ret1;

  sp0.sched_priority = 2;
  ret0 = sched_setscheduler(0, SCHED_FIFO, &sp0);
  if (ret0 == -1) {
    perror("sched_setscheduler");
    return 1;
  }

  sp1.sched_priority = 1;
  ret1 = sched_setparam(0, &sp1);
  if (ret1 == -1) {
    perror("sched_setparam");
    return 1;
  }

  ret = sched_getparam(0, &sp);
  if (ret == -1) {
    perror("sched_getparam");
    return 1;
  }

  printf("Our priority is %d\n", sp.sched_priority);
}
