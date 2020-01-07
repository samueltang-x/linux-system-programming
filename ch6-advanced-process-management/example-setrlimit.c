#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>

int main(void) {
  struct rlimit rlim;
  int ret;

  rlim.rlim_cur = 32 * 1024 * 1024; // 21 MB
  rlim.rlim_max = RLIM_INFINITY;    // leave it alone
  ret = setrlimit(RLIMIT_CORE, &rlim);
  if (ret == -1) {
    perror("setrlimit");
    return 1;
  }

  return 0;
}
