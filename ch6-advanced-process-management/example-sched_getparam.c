#include <sched.h>
#include <stdio.h>

int main(void) {
  struct sched_param sp;
  int ret;

  ret = sched_getparam(0, &sp);
  if (ret == -1) {
    perror("sched_getparam");
    return 1;
  }

  printf("Our priority is %d\n", sp.sched_priority);
}
