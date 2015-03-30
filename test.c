#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define file1 		"myfile1.txt"
#define file2 		"myfile2.txt"
int main()
{
FILE *pFile;
FILE *pFile2;
char buffer[256];

pFile=fopen(file1, "r");
pFile2=fopen(file2, "a+");
if(pFile==NULL) {
    perror("Error opening file.");
}
else {
    while(!feof(pFile)) {
        if(fgets(buffer, 100, pFile) != NULL) {
        fseek(pFile2, -100, SEEK_END);
        fprintf(pFile2, buffer);
    }
}
fclose(pFile);
fclose(pFile2);
 return(0);
}
}