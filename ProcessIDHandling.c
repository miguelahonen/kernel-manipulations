#include <stdio.h>
#include <unistd.h>

int main() {
    // par_proc_id is for parent process..
    int proc_id, par_proc_id;
    par_proc_id = getppid();
    proc_id = getpid();

    printf("Parent processId: %d\n", par_proc_id);
    printf("ProcessId: %d\n", proc_id);
}