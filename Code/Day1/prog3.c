#include<stdio.h>
#include<string.h>
void rev(char[]);
void main()
{
	char str[20];
	printf("enter string\n");
	gets(str);
	rev(str);
	puts("Reverse string");
	puts(str);
}

void rev(char str[])
{
	static int i=0,j=0;
	char temp;
	if(str[i]!='\0')
	{
		temp=str[i++];
		rev(str);
		str[j++]=temp;
	}
}
