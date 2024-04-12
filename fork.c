SS#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
        pid_t procid, parentid, result;
        int a=0;
        if(result<0) {
                printf("Ошибка при выполнении fork()\n");
                exit(-1);
        }
        else if(result==0) {
               a=a+1000;
               procid = getpid();
               parentid = getppid();
               printf("ИД, текущего процесса: %d\n", procid);
               printf("ИД, родительского процесса: %d\n", parentid);
               printf("Значение переменной a: %d\n", a);
               printf("Значение переменной result: %d\n", result);
        }
        else {
 
               a=a+1;
               procid = getpid();
               parentid = getppid();
               printf("ИД, текущего процесса: %d\n", procid);
               printf("ИД, родительского процесса: %d\n", parentid);
               printf("Значение переменной a: %d\n", a);
               printf("Значение переменной result: %d\n", result);

        }
        return 0;
}
