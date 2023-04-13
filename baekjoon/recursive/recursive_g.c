#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int recursion(const char *s, int l, int r,int *count){
	(*count)++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1,count);
}

int isPalindrome(const char *s,int *count){
    return recursion(s, 0, strlen(s)-1,count);
}

int main(){
	int n;
	scanf("%d",&n);
	char s[1000];
	int *a;
	int *b;
	int count;

	a = (int *) malloc (sizeof(int ) * n);
	b = (int *) malloc (sizeof(int ) * n);
	for(int i = 0; i < n; i++)
	{
		scanf("%s",s);
		count = 0;
		a[i] = isPalindrome(s,&count);
		b[i] = count;
	}
	for(int i = 0; i < n; i++)
		printf("%d %d\n",a[i],b[i]);
	return (0);
}
