#include<stdio.h>

struct Student
{
    int roll;
    char name[50];
    float marks;
};

void analyzeStudents(struct Student s[],int n){
    int topindex = 0;
    float summarks = 0.0;
    for(int i=0;i<n;i++){
        summarks += s[i].marks;
        if(s[i].marks>s[topindex].marks){
            topindex = i;
        }
    }

    float avgMarks = summarks/n;
        printf("Avg class marks :%f",avgMarks);
        printf("\nTop student details\n");
        printf("Roll no : %d",s[topindex].roll);
        printf("Name : %s",s[topindex].name);        
        printf("Marks : %f",s[topindex].marks);
}

int main(){
    struct Student students[5];

    for(int i=0;i<5;i++){
        printf("Roll no : ");
        scanf("%d",&students[i].roll);
        printf("Name : ");     
        scanf("%s",students[i].name);   
        printf("Marks : ");
        scanf("%f",&students[i].marks);
    }
    analyzeStudents(students,5);
    return 0;
}