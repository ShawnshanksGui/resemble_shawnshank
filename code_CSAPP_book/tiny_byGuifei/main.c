#include<stdio.h>
#include<ctype.h>

char s[100010];
void fuck(int index){
    s[index]=='\0' || (s[index] = s[index] == 't'?'t':toupper(s[index]),fuck(index+1), 1);
	}
	int main(void){
	    
		    scanf("%s",s);
			    fuck(0);
				    printf("%s",s);
					    return 0;
						}
