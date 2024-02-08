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
printf("how many students");
scanf("%d",&n);
STUDENT temp;
STUDENT S[20];
for (i=0; i<n; i++)
{
printf("Enter the name,usn and 3 marks:\n");
scanf("%s %d %d %d %d",S[i].name,&S[i].usn,&S[i].marks[0],&S[i].marks[1],&S[i].marks[2]);
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
    printf("%s %d %f\n",S[i].name,S[i].usn,S[i].avg);

}
return 0;
}

