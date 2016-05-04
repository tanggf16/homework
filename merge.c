#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
int main()
{
   char  c;
   int  origin1,origin2,partsize,filesize1,filesize2,flag,file;
   int  firstsize=0,n=2;
   origin1=open("file.dat1",O_RDONLY);
   if(origin1==-1)             
   {exit(0);}
   filesize1 = lseek(origin1, 0, SEEK_END); 
   lseek(origin1, 0, SEEK_SET);   
   origin2=open("file.dat2",O_RDONLY);
   if(origin2==-1)             
   {exit(0);}
   filesize2= lseek(origin2, 0, SEEK_END);   
   lseek(origin2, 0, SEEK_SET);       
    
    
         while(n=2){
                    file=open("file.dat12",O_RDWR|O_CREAT,S_IRUSR|S_IWUSR);
                    if(file==-1)             
                    {exit(0);}
                    while((flag=read(origin1,&c,1))>0)
      {
                     write(file,&c,flag);
                     firstsize=firstsize+flag;
                     if(partsize==filesize1)
            {
               
                break;
              
            }
      }
                           
                    lseek(file,0,SEEK_END);
                    while((flag=read(origin2,&c,1))>0)
    {
          write(file,&c,flag);
         }
                 break;
       }
     
   close(origin1); 
   close(origin2);
   close(file);
   exit(0);
}
