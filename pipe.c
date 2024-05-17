#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	int fd[2], result;
	size_t size;
	char string[] = "Hello from pipe!\n";
	char resstring[17];
	if (pipe(fd)<0) {
		printf("Не удалось создать pipe\n");
		exit(-1);
	}
        result = fork();
        if (result < 0) {
                printf("ошибка при запуске fork()\n");
                exit(-1);
        }
	else if (result > 0) {
		if(close(fd[0])<0) {
			printf("Не удалось закрыть pipe для чтения\n");
			exit(-1);
		}
                if(close (fd[1])<0) {
                 	printf("Не удалось закрыть pipe для записи\n");
               		exit(-1);
        	}
		size = write(fd[1], string, 17);
		if (size != 17) {
 			printf("Не удалось записать 17 байт из строки\n");
			exit(-1);
		}
		printf("Родитель записал строку pipe\n");
	}
	else {
		if (close(fd[1])<0) {
        	        printf("Не удалось закрыть pipe для записи\n");
                	exit(-1);
        	}
	        size = read(fd[0], resstring, 17);
	        if (size != 17) {
	                printf("Не удалось прочитать 17 байт из pipe\n");
        	        exit(-1);
        	}
        	printf("Прочитанная строка %s\n", resstring);
        	if (close(fd[0])<0) {
                	printf("Не удалось закрыть pipe для чтения\n");
                	exit(-1);
        	}
	}
	return 0;
}
