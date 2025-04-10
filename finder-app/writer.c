#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>

#define MAX_STRING_LENGTH 1024

void write_to_file(const char *filename, const char *string_to_write){
	FILE *file = fopen(filename,"w");
	if(file == NULL){
		syslog(LOG_ERR,"Failed to open file: %s",filename);
		perror("Error opening file");
		exit(EXIT_FAILURE);
		}
	fprintf(file,"%s",string_to_write);
	syslog(LOG_DEBUG,"Writing '%s' to %s",string_to_write,filename);
	
	fclose(file);
	
	}

int main(int argc,char *argv[]){
	if (argc!=3){
		syslog(LOG_ERR,"Invalid number of arguments");
		fprintf(stderr,"Usage: %s <filename> <string_to_write>\n",argv[0]);
		exit(EXIT_FAILURE);
		}
	const char *filename = argv[1];
	const char *string_to_write = argv[2];
	
	openlog("writer",LOG_PID| LOG_CONS,LOG_USER);
	
	write_to_file(filename,string_to_write);
	
	closelog();
	
	return 0 ;
	
	}
	
	

