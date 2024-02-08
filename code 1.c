#include<stdio.h>
typedef struct C{
int code;
char course[20];

}course;
typedef struct S{
    char name[20];
    int id;
    course Cs;

}student;
student* display(student *st);
student disp(student nd);
int main()
{
    student S={"naveen",20,27,"CSE"};
printf("%s %d %d %s\n",S.name,S.id,S.Cs.code,S.Cs.course);
student *stu;
stu=display(&S);
printf("%s %d %d %s\n",stu->name,stu->id,stu->Cs.code,stu->Cs.course);

 student stud=disp(S);
printf("%s %d %d %s",stud.name,stud.id,stud.Cs.code,stud.Cs.course);

return 0;
}
student*display(student*st)
{
   printf("%s %d %d %s\n",st->name,st->id,st->Cs.code,st->Cs.course);
   st->Cs.code=15;
   printf("%s %d %d %s\n",st->name,st->id,st->Cs.code,st->Cs.course);
    return st;
}
student disp(student nd)
{
    student *md=&nd;
    md->Cs.code=10;
    printf("%s %d %d %s\n",md->name,md->id,md->Cs.code,md->Cs.course);
    return *md;
}
