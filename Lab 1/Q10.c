#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int rollNumber;
    char name[50];
    float marks;
} Student;

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    Student *students = (Student *)malloc(n * sizeof(Student));

    if (students == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("\nEnter details for Student %d:\n", i + 1);
        printf("Roll Number: ");
        scanf("%d", &(students + i)->rollNumber);
        printf("Name: ");
        scanf(" %[^\n]", (students + i)->name);
        printf("Marks: ");
        scanf("%f", &(students + i)->marks);
    }

    int topperIdx = 0;
    for (int i = 1; i < n; i++) {
        if ((students + i)->marks > (students + topperIdx)->marks) {
            topperIdx = i;
        }
    }

    printf("\n--- Student With Highest Marks ---\n");
    printf("Roll Number: %d\n", (students + topperIdx)->rollNumber);
    printf("Name:        %s\n", (students + topperIdx)->name);
    printf("Marks:       %.2f\n", (students + topperIdx)->marks);

    free(students);
    students = NULL;

    return 0;
}