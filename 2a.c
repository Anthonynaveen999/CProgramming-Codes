#include<stdio.h>
typedef struct student
{
char name[30];
int usn;
int marks [3];
float avg;
}STUDENT;

int main()
{
int i,j,n;
printf("Enter no of students of students\n");
scanf("%d",&n);
STUDENT temp;
STUDENT S[20];
for (i=0; i<n; i++)
{
printf("Enter details of student %d",i+1);
printf("Enter name of the student \n");
scanf("%s",S[i].name);
printf("Enter USN of student \n");
scanf("%d",&S[i].usn);
printf("Enter the marks\n");
scanf("%d%d%d",&S[i].marks[0],&S[i].marks[1],&S[i].marks[2]);
}
for(i=0;i<n;i++)
{
    S[i].avg=(S[i].marks[0]+S[i].marks[1]+S[i].marks[2])/3.0;
}
for(i=0;i<n;i++)
{
    for(j=0;j<n-i;j++)
    {
        if(S[j].avg<S[j+1].avg)
        {

            temp=S[j];
            S[j]=S[j+1];
            S[j+1]=temp;
        }
    }

}
printf("The student details are\n");
for(i=0;i<n;i++)
{
    printf("name: %s\n",S[i].name);
    printf("usn: %d\n",S[i].usn);
    printf("avg: %f\n",S[i].avg);
}
return 0;
}
