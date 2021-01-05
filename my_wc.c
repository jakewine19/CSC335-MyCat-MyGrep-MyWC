#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include <ctype.h>


int main(int argc, char *argv[]){
//Counts the acutual lines, words, and character values
int lineCount =0;
int wordCount =0;
int charCount =0;

//Counters for arugments
int lc =0;
int wc =0;
int cc =0;
int j =0;
int space =1;
//Argument Options
int argOption;
//char initilizations

char *fileName;



    
FILE *file;

    if(argc < 2){
        printf("my_wc: [option ...] [file ...]\n");
        exit(1);
        }
        else{
            while((argOption = getopt(argc, argv, "lwc"))!= -1){
                if(argOption == 'l'){
                lc++;
                }
                if(argOption == 'w'){
                wc++;
                }
                if(argOption == 'c'){
                cc++;
                }

                }

        if(lc == 0 && wc == 0 && cc == 0){
                cc++;
                lc++;
                wc++;

        }

        if(lc > 1 || wc > 1 || cc > 1){
            printf("my_wc: [option ...][file ...]\n");
            exit(1);
        }


        if(optind < argc){
            while(optind < argc){
                fileName = argv[optind++];
                file = fopen(fileName, "r");

            if(file != NULL){
                while((j = getc(file))!= EOF){
                    charCount++;

                if(isspace(j)){
                    space = 1;
                    if(j == '\n'){
                        lineCount++;
                    }
                }

                else{
                    wordCount += space;
                        
                         space = 0;
                    
                }
            

            }
        
    
   
        if(lc == 1){
            printf("%d ", lineCount);
        }
        if(wc == 1){
            printf("%d ", wordCount);
        }
        if(cc == 1){
            printf("%d ", charCount);
        }
     printf("%s\n", fileName);

      charCount = wordCount = lineCount = 0;
    fclose(file);

}
    
                else{
                 printf("my_wc: cannot open file\n");
                    exit(1);
                }
            }
        }
    }
    return 0;
}

      
