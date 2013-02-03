#include <sys/stat.h>
#include <fcntl.h>
#include "tlpi_hdr.h"
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]){
  
  
  /* Open new or existing file for reading and writing, truncating to zero
   * bytes; file permissions read+write for owner, nothing for all others */

  // ssize_t write(int fd, void *buffer, size_t count);
  
  
  int to_read;
  to_read = open ("rambling.txt", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
  
  if(to_read == -1)
    errExit("open");
  
  // time to reading
  
  ssize_t for_read, for_write;
  char* buf;
  size_t len = 12; //arbitrary
  buf = malloc(len);
  if(buf == NULL)
    errExit("malloc");
  
  for_read = read(to_read, buf, len);
  if(for_read == -1)
    errExit("read");
  
  
  // time to write
    
  char* buf1 = "\nI'm writing a new line here \n";
  int length = strlen(buf1);
  printf("%d\n", length);
  for_write = write(to_read, buf1, len);
  if(for_write == -1)
    errExit("write");
  
  free(buf); //de-allocate buf
  
  if(close(to_read) == -1)
    errExit("close");
  
  exit(EXIT_SUCCESS);
  //return 0;
}

