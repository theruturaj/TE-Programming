 #include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
int mygetch( ) {
  struct termios oldt,newt;
  int ch;
  tcgetattr( STDIN_FILENO, &oldt );
  newt = oldt;
  newt.c_lflag &= ~( ICANON | ECHO );
  tcsetattr( STDIN_FILENO, TCSANOW, &newt );
  ch = getchar();
  tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
  return ch;
}
int main(int argc, char *argv[]){
            int sock;
            struct sockaddr_in server;
            struct hostent *hp;
            char buffer[1024], cbuff[10];
            //Creating Socket
            sock= socket(AF_INET, SOCK_STREAM, 0);
            if(sock<0)
            {
                        perror("Socket Failed");
                        close(sock);
                        exit(1);
            }
            server.sin_family = AF_INET;
            hp = gethostbyname(argv[1]);
            if(hp==0)
            {
                        perror("gethostbynme Failed");
                        close(sock);
                        exit(1);
            }
            memcpy(&server.sin_addr, hp->h_addr, hp->h_length);
            server.sin_port = htons(5000);
if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        perror("connect failed. Error");
        return 1;
    }
    puts("Connected\n");
            //Accepting command
            printf("Enter command: \t");
            cbuff[0] = 1;
            do {
                        cbuff[0] = mygetch();
                        cbuff[1] = '\0';
                        if( send(sock , cbuff , strlen(cbuff) , 0) < 0)
        {
            puts("Send failed");
            return 1;
        }
            printf("%s",cbuff);
            }while(cbuff[0] != '\n');
            return 0;
}
