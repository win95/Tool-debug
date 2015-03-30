#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define file1 		"bat_iv_ogm.c"
#define file2		"debug/bat_iv_ogm.c"
#define funs		"if(debug_dc =1) printk(\" anhduc \");"

int main()
{
   FILE *fp1,*fp2;
   char str[1024];
   char str1[1024];
   char str2[2048];
   char ch;
   int write=0;
   /* opening file for reading */
   fp1 = fopen(file1, "a+");
   fp2 = fopen(file2, "w");
   if(fp1 == NULL) {
      perror("Error opening file");
      return(-1);
   }
   while(fgets (str, 1024, fp1)!=NULL)
    {
      if(strstr(str,"void batadv")||strstr(str,"int batadv")||strstr(str,"static")){
	write=1;
	//printf("Tim thay void\n");
	fprintf(fp2,"%s",str);
      }
      else
      {
	fprintf(fp2,"%s",str);
      }
      
      if(strstr(str,";")&&write){
	//printf("tim thay cau lenh dau tien\n");
	sprintf(str1,"%s",funs);
	sprintf(str2,"%s%s\n",str,str1);
	fprintf(stdout,"%s",str2);
	fprintf(fp2,"%s",str2);
	write=0;
      }
      
    }
   fclose(fp1);
   fclose(fp2);
   return(0);
  
}