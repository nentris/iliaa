#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
int main() {
	int fd;
	size_t size;
	char string[] = "Gr. 3.124.2.23";
	if ((fd = open("wrfile.txt", O_WRONLY|O_CREAT, 0666))<0) {
		printf("Не удалось открыть файл на запись\n");
		exit(-1);
	}
	size = write(fd, string, 14);
	if (size != 14) {
		printf("Не удалось записать в файл строку из 14 байт\n");
		exit(-1);
	}
	printf("Строка записана в файл wrfile.txt\n");
	if (close(fd) < 0) {
		printf("Не удалось закрыть файл\n");
		exit(-1);
	}
	return 0;
}
