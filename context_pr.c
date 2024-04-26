#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[], char *envp[]) {
         int result;
         result = execle("/bin/cat", "/bin/cat", "args.c", 0, envp);
         printf("Ошибка при выполнении системного вызова exec()\n");
         exit(-1);
         return 0;
}

