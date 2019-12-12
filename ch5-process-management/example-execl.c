#include <stdio.h>
#include <unistd.h>

int main(void) {
  int ret;
  
  ret = execl("/bin/vi", "vi", NULL);
  if (ret == -1)
    perror("execl");

}
