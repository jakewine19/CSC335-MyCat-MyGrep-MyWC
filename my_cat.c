/* do stuff */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
    
    int	i, j;
    // declare local variables
    
    if(argc > 1){
        
    
	        for (i = 1; i < argc; i++)
		        {
		      FILE *fp = fopen(argv[i], "r");
		           if(fp != NULL){
					   	while((j = getc(fp)) != EOF){
							   putchar(j);
						   }
						   fclose(fp);
				   }
					else{
						printf("my_cat: cannot open file\n");
						exit(1);
					}
				}
				exit(0);             
	}
        else{
			exit(0);
		}
    
}