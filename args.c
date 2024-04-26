#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[], char *envp[]) {
        if(argc>1) {
               printf("Количество параметров программы %d\n", argc);
               for (int i=0; i<argc; i++) {
                       printf("Параметр %d: %s\n", i, argv[i]);
               }
        }
        else {
                int j=0;
                while (envp[j]!=NULL) {
                        printf("Значение параметра %d: %s\n", j, envp[j]);
                        j++;
                }
        }
        return 0;
}
