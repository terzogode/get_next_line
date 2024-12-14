#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>


int main(void){
	int fd = open("prova", O_RDONLY);
	char buffer[5];
	read(fd, buffer, 4);
	close(fd);
}
cc *.c -DBUFFER_SIZE=5 -g && yolo ./a.out prova
