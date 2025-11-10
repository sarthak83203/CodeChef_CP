#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include<unistd.h>

// Shared number
int num;

// Function to check prime
void* check_prime(void* arg) {
    int n = num;
    int isPrime = 1;

    if (n <= 1) isPrime = 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            isPrime = 0;
            break;
        }
    }

    if (isPrime)
        printf("Thread 1: %d is a prime number.\n", n);
    else
        printf("Thread 1: %d is not a prime number.\n", n);

    pthread_exit(NULL);
}

// Function to calculate factorial
void* calc_factorial(void* arg) {
    int n = num;

    if (n > 20) {
        printf("Thread 2: Number too large for factorial calculation.\n");
    } else {
        unsigned long long fact = 1;
        for (int i = 1; i <= n; i++) {
            fact *= i;
        }
        printf("Thread 2: Factorial of %d is %llu\n", n, fact);
    }

    pthread_exit(NULL);
}

int main() {
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    pthread_t t1, t2;

    // Create threads
    pthread_create(&t1, NULL, check_prime, NULL);
    pthread_create(&t2, NULL, calc_factorial, NULL);

    // Wait for both threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Main: Both threads have finished.\n");

    return 0;
}
