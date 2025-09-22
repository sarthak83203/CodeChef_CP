#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    pid_t pid = fork(); // First child

    if (pid == 0) {
        // Child 1: check prime
        printf("Child 1 (PID: %d, Parent PID: %d)\n", getpid(), getppid());
        int isPrime = 1;
        if (num <= 1) isPrime = 0;
        for (int i = 2; i * i <= num; i++)
            if (num % i == 0) isPrime = 0;
        if (isPrime)
            printf("%d is prime.\n", num);
        else
            printf("%d is not prime.\n", num);
        exit(0);
    }

    pid = fork(); // Second child

    if (pid == 0) {
        // Child 2: factorial
        printf("Child 2 (PID: %d, Parent PID: %d)\n", getpid(), getppid());
        if (num > 20)
            printf("Number too large for factorial.\n");
        else {
            unsigned long long fact = 1;
            for (int i = 1; i <= num; i++) fact *= i;
            printf("Factorial of %d is %llu\n", num, fact);
        }
        exit(0);
    }

    // Parent waits for both children
    wait(NULL);
    wait(NULL);
    printf("Parent (PID: %d): Both children completed.\n", getpid());

    return 0;
}
