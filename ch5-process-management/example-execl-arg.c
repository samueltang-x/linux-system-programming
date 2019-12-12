#include <stdio.h>
#include <unistd.h>

int main(void) {
  int ret;
  
  ret = execl("/bin/vi", "vi", "/tmp/2.xml", NULL);
  if (ret == -1)
    perror("execl");

}
