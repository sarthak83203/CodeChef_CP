/*Write a C program for the following scenario:
Parent process prompts the user to enter a positive
integer and creates a child process to check whether the
number is palindrome and prints the result. Simulate an
environment where the zombie process is created. Also
visualize the same using pstree.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// Function to check palindrome
int isPalindrome(int n) {
    int rev = 0, orig = n, digit;
    while (n > 0) {
        digit = n % 10;
        rev = rev * 10 + digit;
        n /= 10;
    }
    return orig == rev;
}

int main() {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        printf("Child (PID: %d, Parent PID: %d)\n", getpid(), getppid());
        if (isPalindrome(num))
            printf("%d is a palindrome.\n", num);
        else
            printf("%d is not a palindrome.\n", num);

        printf("Child exiting...\n");
        exit(0); // Child ends here
    } else {
        // Parent process
        printf("Parent (PID: %d) created child (PID: %d)\n", getpid(), pid);
        printf("Parent is not calling wait(), so child will become a zombie after exit.\n");

        // Keep parent alive for a while to observe zombie state
        sleep(20);

        printf("Parent exiting now.\n");
    }

    return 0;
}
