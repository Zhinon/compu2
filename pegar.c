/*#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)

	int i=0;
	for(i=0; i< argc; i++ ){
		printf("%s \n", argv[i]); 
	}
    return 0;
}*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> /*Es la libreria a la que llama write */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define MAX_SIZE 51200 * sizeof (char)

int main(int argc, char *argv[])
{
	char buffer [MAX_SIZE];
	int leido,fd,fd2;
	int i=1;
	int ultimo= argc - 1;
	fd = open (argv[ultimo],O_RDWR|O_APPEND|O_CREAT,S_IRUSR|S_IWUSR);
	while(i<ultimo){
		fd2 = open(argv[i],O_RDWR);
		leido = read(fd2, buffer, MAX_SIZE);
		write(fd, buffer, leido);
		close(fd2);
	//	printf("%s \n",argv[i]);
		i=i+1;	
	}
	close(fd);
	return 0;
}

