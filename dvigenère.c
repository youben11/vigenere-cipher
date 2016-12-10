#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int main(int argc,char** argv){

	if(argc!=1){
		printf("Usage: %s\n",argv[0]);
		return 0;
	}

	char c,*message=malloc(0),*keyword=malloc(0);
	int i=0,key,typechar,keysize=0,messagesize=0;

	printf("[*]Key : ");

	while((c=getchar())!='\n'){
		
		if(isalpha(c)){
			keyword=realloc(keyword,(keysize+1)*sizeof(char));
			keyword[keysize]=c;
			keysize++;
		}
		
	}

	printf("[*]Message to décrypt : ");

	while((c=getchar())!='\n'){
		message=realloc(message,(messagesize+1)*sizeof(char));
		message[messagesize]=c;
		messagesize++;
	}

	for(int j=0;j<messagesize;j++){
		
		c=message[j];

		if(isalpha(c)){

			typechar=(c<95)?65:97;
			c-=typechar;
			key=(int) keyword[i];
			typechar=(key<95)?65:97;
			key-=typechar;
			c=(c+26-key)%26;
			printf("%c",c+65);
			i=(i+1)%keysize;

		}else printf("%c",c);

	}
	puts("");

	return 0;
}