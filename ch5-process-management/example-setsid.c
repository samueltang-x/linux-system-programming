#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void) {
  pid_t pid, sid;

  printf("My pid=%jd before fork()\n", (intmax_t) getpid());
  sid = getsid(0);
  if(sid == -1)
    perror("getsid");
  else
    printf("before setsid, my session id=%d\n", sid);

  pid = fork();
  if(pid == -1) {
    perror("fork");
    return -1;
  } else if (pid != 0) {
    exit(EXIT_SUCCESS);
  }

  printf("My pid=%jd after fork()\n", (intmax_t) getpid());

  if(setsid() == -1) {
    perror("setsid");
    return -2;
  }

  sid = getsid(0);
  if(sid == -1)
    perror("getsid");
  else
    printf("after setsid, my session id=%d\n", sid);
}
