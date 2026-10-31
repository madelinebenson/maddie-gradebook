#include <stdio.h>

#define students 4
#define tests 3

void printTable(int scores[][tests]) {
    printf("Student Test1 Test2 Test3\n");
    for (int s = 0; s < students; s++) {
        printf("%-7d", s + 1);
        for (int t = 0; t < tests; t++) {
            printf("%-6d", scores[s][t]);
        }
        printf("\n");
    }
}

double studentAverage(const int *row) {
    int sum = 0;
    for (int i = 0; i < tests; i++) {
        sum += *(row + i);
    }
    return sum / (double)tests;
}

double testAverage(int scores[][tests], int test) {
    int sum = 0;
    for (int s = 0; s < students; s++) {
        sum += scores[s][test];
    }
    return sum / (double)students;
}

void findHighest(int scores[][tests], int *best, int *student, int *test) {
    *best = scores[0][0];
    *student = 1;
    *test = 1;
    for (int s = 0; s < students; s++) {
        for (int t = 0; t < tests; t++) {
            if (scores[s][t] > *best) {
                *best = scores[s][t];
                *student = s + 1;
                *test = t + 1;
            }
        }
    }
}

void addBonus(int scores[][tests]) {
    for (int s = 0; s < students; s++) {
        scores[s][2] += 5;
        if (scores[s][2] > 100) {
            scores[s][2] = 100;
        }
    }
}

int main(void) {
    int scores[students][tests] = {
        {78, 85, 92},
        {64, 70, 58},
        {90, 88, 97},
        {55, 61, 73}
    };

    printTable(scores);

    printf("\nStudent averages:\n");
    for (int s = 0; s < students; s++) {
        printf("Student %d: %.2f\n", s + 1, studentAverage(scores[s]));
    }

    printf("\nTest averages:\n");
    for (int t = 0; t < tests; t++) {
        printf("Test %d: %.2f\n", t + 1, testAverage(scores, t));
    }

    int best, student, test;
    findHighest(scores, &best, &student, &test);
    printf("\nHighest score: %d (Student %d, Test %d)\n", best, student, test);

    addBonus(scores);
    printf("\nAfter adding 5 bonus points to Test 3:\n");
    printTable(scores);

    return 0;
}
