#include<stdio.h>

struct Student
{
    int roll;
    char name[50];
    float marks;
};

void inputStudents(struct Student s[],int n){
    for(int i=0;i<n;i++){
        printf("Roll no : ");
        scanf("%d",&s[i].roll);
        printf("Name : ");
        scanf("%s",s[i].name);
        printf("Marks : ");
        scanf("%f",&s[i].marks);
    }
}

void displayStudents(struct Student s[],int n){
    for(int i=0;i<n;i++){
        printf("%d %s %f",s[i].roll,s[i].name,s[i].marks);
    }
}

int main(){
    struct Student students[5];

    inputStudents(students,5);
    displayStudents(students,5);
    return 0;
}