#include<stdio.h>
#include<stdlib.h>

struct Student
{
    int roll;
    char name[50];
    float marks;
};

int main(){
    struct Student s;
    struct Student *ptr = &s;

    printf("Enter Roll no : ");
    scanf("%d",&ptr->roll);
    printf("Enter name : ");
    scanf("%s",ptr->name);
    printf("Enter marks : ");
    scanf("%f",&ptr->marks);

    printf("Roll number : %d\n",ptr->roll);
    printf("Name : %s\n",ptr->name);
    printf("Marks : %f\n",ptr->marks);

    return 0;
}