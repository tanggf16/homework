#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
int main()
{
   char  c;
   int  origin,partsize,filesize,flag,file;
   int  eachsize=0,n=2;
   origin=open("file.dat",O_RDONLY);
   filesize = lseek(origin, 0, SEEK_END);    
   lseek(origin, 0, SEEK_SET);       
   partsize=filesize/n;       
       
         while(n=2){
                    file=open("file.dat1",O_RDWR|O_CREAT,S_IRUSR|S_IWUSR);
                    while((flag=read(origin,&c,1))>0)
      {
                     write(file,&c,flag);
                     eachsize=eachsize+flag;
                     if(partsize==eachsize)
            {
                printf("每个文件大小：%d bytes\n",eachsize);
                break;
              
            }
      }
        
                    file=open("file.dat2",O_RDWR|O_CREAT,S_IRUSR|S_IWUSR);
                    while((flag=read(origin,&c,1))>0)
    {
          write(file,&c,flag);
         }
                 break;
       }
     
    
   
   
   exit(0);
}
