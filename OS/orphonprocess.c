/*4) Write a C program for the following scenario:
Parent process prompts the user to enter a positive
integer and creates a child process to check whether the
number is odd/even and prints the result. Simulate an
environment where the orphan process is created. Also
visualize the same using getppid()
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        printf("Child (PID: %d, Parent PID: %d)\n", getpid(), getppid());

        if (num % 2 == 0)
            printf("%d is Even.\n", num);
        else
            printf("%d is Odd.\n", num);

        // Sleep so parent can exit before child finishes
        sleep(10);

        // After sleep, check new parent
        printf("Child (PID: %d) after parent exit, new Parent PID: %d\n", getpid(), getppid());

        exit(0);
    } else {
        // Parent process
        printf("Parent (PID: %d) created child (PID: %d)\n", getpid(), pid);
        printf("Parent will exit immediately, making child an orphan.\n");
        exit(0); // Parent terminates quickly
    }

    return 0;
}
