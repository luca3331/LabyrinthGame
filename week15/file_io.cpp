#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  int a;
  FILE  *fp;
  errno_t error;

  error = fopen_s(&fp,"sample.txt","r");

  if(error != 0)
        printf("ファイルを開けませんでした");
  else{
        while((a = fgetc(fp)) != EOF)
               putchar(a);
        putchar('\n');
        fclose(fp);
      }

  return 0;
 }