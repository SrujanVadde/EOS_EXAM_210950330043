#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
 #include <sys/stat.h>
 #include <fcntl.h>
 #include<stdlib.h>
 #include<errno.h>
int main()
{
    int fd1;
    char word[20],buff[20];
    pid_t id1,id2;
    printf("Before fork\n");
    id1=fork();
    id2=fork();
    if(id1==0&&id2>0)
    {
      while(!(buff==word))
      {
         read(fd1,&buff,1);
         if(buff==word)
         {
             printf("FOUND\n");
         }
      }
    }
    else if(id2==0&&id1>0)
    {
         read(fd1,buff,1024);
        if(buff==word)
         {
             printf("FOUND\n");
         }

    }
    else
    {
        fd1=open("/home/srujan/EOS_EXAM/dictionary.txt",O_RDONLY,S_IRUSR | S_IWUSR);
        printf("Enter a word to search:");
        scanf("%s",word);
    }
    return 0;
}
