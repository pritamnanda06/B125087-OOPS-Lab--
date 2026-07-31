#include <stdio.h>

typedef struct {
    int rollNumber;
    char name[50];
    float marks;
} Student;

void inputStudent(Student *s) {
    printf("Enter Roll Number: ");
    scanf("%d", &s->rollNumber);
    printf("Enter Name: ");
    scanf(" %[^\n]", s->name);
    printf("Enter Marks: ");
    scanf("%f", &s->marks);
}

void displayStudent(const Student *s) {
    printf("\n--- Student Details ---\n");
    printf("Roll Number: %d\n", s->rollNumber);
    printf("Name:        %s\n", s->name);
    printf("Marks:       %.2f\n", s->marks);
}

int main() {
    Student studentObj;
    Student *ptr = &studentObj;

    inputStudent(ptr);
    displayStudent(ptr);

    return 0;
}