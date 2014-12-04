#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int main(void)
{
	char * str=(char *) malloc(100);
	strcpy(str,"kuaidi");
	free(str);
	if(str!=NULL)
	{
	strcpy(str,"DACHE");
	printf(str);
	}
	system("pause");
}
