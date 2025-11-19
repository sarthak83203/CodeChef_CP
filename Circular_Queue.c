#include <stdio.h>

#define SIZE 7

int Q[SIZE];
int front = 2;
int rear  = 4;

void insert(char x) {
    if ((rear + 1) % SIZE == front) {
        printf("Overflow\n");
        return;
    }
    rear = (rear + 1) % SIZE;
    Q[rear] = x;
}

void delete() {
    if (front == -1) {
        printf("Underflow\n");
        return;
    }
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

int main() {
    // initial values from the question
    Q[2] = 'V'; 
    Q[3] = 'I'; 
    Q[4] = 'T';

    // Insert A, B, X, Y, Z
    insert('A');
    insert('B');
    insert('X');
    insert('Y');
    insert('Z');

    // Delete two elements
    delete();
    delete();

    return 0;
}
