/*Write a C program for the following scenario:
Parent Process gets a positive integer input. It creates a child
process to check if the number is a prime. If prime, child creates a
child (grandchild of parent) to generate the Fibonacci series. If not
prime, child creates a child (grandchild of parent) to compute
factorial. Grandchild process performs the task and prints the
result. Each process performs the task and terminates properly.
Also print the process id and parent process id of each process.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

// Function to check prime
int isPrime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

// Function to generate Fibonacci series
void fibonacci(int n) {
    long long a = 0, b = 1, c;
    printf("Fibonacci series (%d terms): ", n);
    for (int i = 1; i <= n; i++) {
        printf("%lld ", a);
        c = a + b;
        a = b;
        b = c;
    }
    printf("\n");
}

// Function to compute factorial
void factorial(int n) {
    unsigned long long fact = 1;
    for (int i = 1; i <= n; i++) fact *= i;
    printf("Factorial of %d is %llu\n", n, fact);
}

int main() {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    pid_t child = fork();

    if (child == 0) {
        // Child process
        printf("Child (PID: %d, Parent PID: %d)\n", getpid(), getppid());
        int prime = isPrime(num);

        pid_t grandchild = fork();
        if (grandchild == 0) {
            // Grandchild process
            printf("Grandchild (PID: %d, Parent PID: %d)\n", getpid(), getppid());
            if (prime)
                fibonacci(num);
            else
                factorial(num);
            exit(0);
        } else {
            wait(NULL); // Child waits for grandchild
            exit(0);
        }
    } else {
        // Parent process
        printf("Parent (PID: %d)\n", getpid());
        wait(NULL); // Parent waits for child
        printf("Parent: All processes finished.\n");
    }

    return 0;
}
