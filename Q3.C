#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
int main()
{
int fd[2],fd1,i=0,r=2;
char w[100],b[100],w1[100],ch;
pid_t id;
pipe(fd);
id=fork();

if(id==0)
{
close(fd[1]);
read(fd[0],&b,10);
printf("%s\n",b);
fd1=open("dictionary.txt",O_RDONLY,S_IRUSR | S_IWUSR);
if(fd1==-1)
{
printf("Failed to open file\n");
exit (EXIT_FAILURE);
}
else
{

while(ch!=EOF&&read(fd1,&ch,1))
{
if(ch!='\n')
{
w1[i]=ch;
i++;
}
else
{
w1[i]='\0';
r=strcmp(w1,b);
if(r==0)
{
printf("The word is found by process 1\n");
return 1;
}
else
{
i=0;

}

}

}
printf("word not found\n");



}
close(fd1);
}

else
{
close(fd[0]);

printf("Enter a word to search : \n");
scanf("%s",w);
write(fd[1],&w,10);

}
sleep(1);

return 0;
}

