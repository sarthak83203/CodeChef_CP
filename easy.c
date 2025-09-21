/*Passing Grade

Chef is in a class in his university with a total of NN students (including him). Chef's professor likes Chef but hates the entire class.

Chef's professor has just finished grading their exam papers, and it is known that the ii-th student has scored AiAi​ marks. Chef is student number 11, and the other students are numbered from 22 to NN.

Chef's professor cannot change the marks the students received, but he can decide the cutoff marks. He wants to ensure Chef passes, but at the same time, fail as many other students as possible. Formally, he will choose some cutoff marks X(0≤X≤100)X(0≤X≤100) and then fail all students with marks strictly less than XX, and pass those with ≥X≥X.

Find the number of students that passes that class, when Chef's professor chooses in the cutoff in the optimal way (minimizing the number of students that pass, but ensuring Chef passes).
Input Format

    The first line of input will contain a single integer TT, denoting the number of test cases.
    Each test case consists of multiple lines of input.
        The first line contains a single integer NN.
        The second line contains NN integers - A1,A2,…,ANA1​,A2​,…,AN​, the marks each student got.

Output Format

For each test case, output on a new line the minimum number of students that pass the class.
Constraints

    1≤T≤1001≤T≤100
    2≤N≤1002≤N≤100
    0≤Ai≤1000≤Ai​≤100

Sample 1:
Input
Output

3
3
100 59 98
4
0 100 0 100
7
54 23 67 85 34 54 53

1
4
4
*/

#include <stdio.h>

int main() {
	
	int T,n;
	scanf("%d",&T);
	while(T--){
	    scanf("%d",&n);
	    int arr[n];
	    for(int i=0;i<n;i++){
	        scanf("%d",&arr[i]);
	    }
	    int chef=arr[0];
	    int count=0;
	    for(int i=0;i<n;i++){
	        if(arr[i]>=chef){
	            count++;
	        }
	    }
	    printf("%d\n",count);
	}

}


