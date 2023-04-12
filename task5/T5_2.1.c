#include <stdio.h>
int main() {
	int sec, hh,mm,ss;
	printf("input seconds: ");
	scanf("%d", &sec);
	
	hh = (sec/3600); 
	
	mm = (sec -(3600*hh))/60;
	
	ss = (sec -(3600*hh)-(mm*60));
	
	printf("hh:mm:ss _ %d:%d:%d\n",hh,mm,ss);
	
	return 0;
}