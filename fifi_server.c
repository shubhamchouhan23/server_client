#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>


int main(void) {
	printf("Server .listening");

	int code = mkfifo("cli_ser_fifo",0764);
	if (code == -1) {
		perror("mkfifo returned an error  - file may already exist");
	}

	int fd = open("cli_ser_fifo", O_RDONLY);
	if (fd == -1) {
		perror("cannot open FIFO for read");
		return 0;
	}
	printf("FIFO OPEN");

	char serverrcv[100];
	memset(serverrcv,0,100);

	int res;
	int Len;
		
		read(fd,serverrcv,100);

		printf("Server received: %s\n", serverrcv);

	printf("EOF Reached");

	close(fd);
	printf("FIFO closed");

	return 0;
}

		
