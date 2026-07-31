#include <stdio.h>

typedef struct {
    int rollNumber;
    char name[50];
    float marks;
} Student;

int findTopperIndex(const Student students[], int count) {
    int topperIdx = 0;
    for (int i = 1; i < count; i++) {
        if (students[i].marks > students[topperIdx].marks) {
            topperIdx = i;
        }
    }
    return topperIdx;
}

float calculateClassAverage(const Student students[], int count) {
    float total = 0.0;
    for (int i = 0; i < count; i++) {
        total += students[i].marks;
    }
    return total / count;
}

int main() {
    const int count = 5;
    Student students[count];

    for (int i = 0; i < count; i++) {
        printf("Enter details for Student %d:\n", i + 1);
        printf("Roll Number: ");
        scanf("%d", &students[i].rollNumber);
        printf("Name: ");
        scanf(" %[^\n]", students[i].name);
        printf("Marks: ");
        scanf("%f", &students[i].marks);
        printf("\n");
    }

    int topperIdx = findTopperIndex(students, count);
    float average = calculateClassAverage(students, count);

    printf("--- Performance Analysis ---\n");
    printf("Highest Scorer: %s (Roll No: %d) with %.2f marks\n", 
           students[topperIdx].name, students[topperIdx].rollNumber, students[topperIdx].marks);
    printf("Class Average Marks: %.2f\n", average);

    return 0;
}