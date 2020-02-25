#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct basic_finding
{
	char lastname[30];
	char firstname[30];
	char cityname[30];
};
typedef struct basic_finding myinfom_t;
int compar( void *a , void *b)
{
	char* x= (*(myinfom_t*)a).lastname;
	char* y = (*(myinfom_t*)b).lastname;
	int ret;
	ret= strcmp (x,y);
	if(ret == 0)
	{
		return 0;
	}
	else if(ret > 0)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
int main(void)
{
	unsigned int i=0;
	myinfom_t arr[50];
	FILE  *projectfile;
	projectfile= fopen("/home/simran/Downloads/abc.txt","r");
	if(projectfile!=NULL)
	{
	while (fscanf(projectfile, " %s " " %s " " %s ", arr[i].lastname ,arr[i].firstname ,arr[i].cityname) != -1)
		++i;
	}
	else
		{
		printf(" ERROR!! ");
		}
	int N;
	printf("*******BEFORE SORTING******* \n");
	for(N=0;N<i;++N)
	{
	   printf("\n %s \t",         arr[N].lastname);
	   printf("   %s \t",         arr[N].firstname);
	   printf("   %s \t \n \n",      arr[N].cityname);
	}
	qsort((void*)arr , i , sizeof(myinfom_t), compar);
	printf("*******AFTER SORTING******* \n");
	for(N=0;N<i;++N)
		{
		printf("\n %s \t",            arr[N].lastname);
		printf("   %s \t",            arr[N].firstname);
		printf("   %s \t \n \n",         arr[N].cityname);

		}
	return 0;
}
