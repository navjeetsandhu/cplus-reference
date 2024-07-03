#include <unistd.h>
#include <cstdio>

int testCreateProcess() {
    pid_t pid = fork(); // Create child process

    if (pid < 0) {
        // Error forking
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {
        // Child process
        char * const arguments[] = {"/bin/ls", ".", NULL}; // "./" is the argument for "ls"
        execv(arguments[0], arguments); // Replace current process image with new one
        perror("exec failed");
        return 1;
    }
    else {
        // Parent process
        printf("I am parent process:\n- PID:%d\n- Child's PID:%d\n", getpid(), pid);
    }
    return 0;
}