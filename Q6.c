#include <stdio.h>

typedef struct {
    int rollNumber;
    char name[50];
    float marks;
} Student;

void displayStudentsTable(const Student students[], int count) {
    printf("\n--------------------------------------------------\n");
    printf("%-12s %-25s %-10s\n", "Roll No", "Name", "Marks");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-12d %-25s %-10.2f\n", students[i].rollNumber, students[i].name, students[i].marks);
    }
    printf("--------------------------------------------------\n");
}

int main() {
    const int count = 5;
    Student students[count];

    for (int i = 0; i < count; i++) {
        printf("\nEnter details for Student %d:\n", i + 1);
        printf("Roll Number: ");
        scanf("%d", &students[i].rollNumber);
        printf("Name: ");
        scanf(" %[^\n]", students[i].name);
        printf("Marks: ");
        scanf("%f", &students[i].marks);
    }

    displayStudentsTable(students, count);

    return 0;
}