#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#define MAX_SIZE 51200

int main(int argc, char **argv)
{
	int fd,fd2,leido;
	char buffer[MAX_SIZE];
	fd = open(argv[1], O_RDWR);
	int i=0;
	//char nombre[(sizeof(argv[1])+3)];
	//char *nombre = malloc(strlen(argv[1])+3);
	char nombre[80]; 
	while((leido = (read(fd,buffer,MAX_SIZE)))>0){	
//		printf("%d \n",leido);	
		//strcat(nombre, "-01");
		sprintf(nombre, "%s-%d", argv[1],i);
		fd2 = open(nombre,O_RDWR|O_CREAT, S_IRUSR|S_IWUSR);
//		leido = read(fd, buffer, sizeof buffer);
//		printf("%s %d\n \n",nombre,leido);
		write(fd2, buffer, leido);
		i=i+1;
	}
	close(fd2);
	close(fd);
	//free(nombre);
	return 0;
}
