#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

int main(void) {
	printf("Client Process writing\n");
	char clientmsg[] = "Linux System Kernel Programming";

	int fd = open("cli_ser_fifo", O_WRONLY);
	if (fd == -1) {
		perror("cannot open FIFO");
		return EXIT_FAILURE;
	}

	write(fd,clientmsg,strlen(clientmsg));

	close(fd);
	return 0;
}
