#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <fcntl.h>

#include <string.h>
#include <errno.h>

#include <sys/stat.h>

void print_error() {
  printf("Error #%d: %s\n", errno, strerror(errno));
}

int rand_int() {
  int numbytes;
  int fd = open("/dev/random", O_RDONLY);

  unsigned int randint; 
  numbytes = read(fd, &randint, 4);
  if (numbytes < 0) print_error();

  close(fd);
  return randint;
}


int main() {

  umask(0);

  int rand_array[10];
  int i;
  int numbytes;
  int fd;
  
  printf("Generating Random Numbers:\n");
  for (i = 0; i < 10; i++) {
    rand_array[i] = rand_int();
    printf("\trandom %d: %u\n", i, rand_int());
  }
  printf("\n");
  
  printf("Writing Numbers to File...\n");
  fd = open("out.txt", O_CREAT|O_WRONLY|O_APPEND, 0644);
  if (fd < 0) print_error();

  for (i = 0; i < 10; i++) {
    numbytes = write(fd, &rand_array[i], 4);
    if (numbytes < 0) print_error();
  }
  close(fd);
  printf("\n");

  
  printf("Reading numbers from file...\n");
  fd = open("out.txt", O_RDONLY);
  if (fd < 0) print_error();

  // TODO: fill this in
  
  close(fd);
  
  
  return 0;
}
