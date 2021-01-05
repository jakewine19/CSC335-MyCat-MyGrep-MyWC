#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
    FILE *fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    if(argc < 2){
        printf("my_grep: searchterm [file ...]\n");
        exit(1);

    }


    for(int i =2; i < argc; i++){
        fp = fopen(argv[i], "r");
    

    if(fp ==NULL){
        printf("my_grep: cannot open file\n");
        exit(1);
    }

    while((read = getline(&line, &len, fp)) != -1){
        if(strstr(line, argv[1]) != NULL)
        printf("%s", line);
    }
    fclose(fp);

}
return 0;
}



/* do stuff */