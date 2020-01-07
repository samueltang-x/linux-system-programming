#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int find_file_in_dir(const char *path, const char *file) {
  int ret = 1;
  struct dirent *entry;
  DIR *dir;

  dir = opendir(path);
  if (dir == NULL) {
    perror("opendir");
    return ret;
  }

  errno = 0;
  while ((entry = readdir(dir)) != NULL) {
    if (strcmp(entry->d_name, file) == 0) {
      ret = 0;
      break;
    }
  }

  if (errno && entry == NULL) {
    perror("readdir");
  }

  closedir(dir);
  return ret;
}

int main(int argc,  char **argv) {
  char *path = argv[1];
  char *file = argv[2];

  if (find_file_in_dir(path, file) == 0) {
    printf("found file %s in dir %s\n", file, path);
  } else {
    printf("did not find file %s in dir %s\n", file, path);
  }

  return 0;
}
