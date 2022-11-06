 #include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include <arpa/inet.h>
#include<string.h>
#include<stdlib.h>
int main(int argc, char* argv[])
{
            /*Variables*/
            int sock,i=0;
            struct sockaddr_in server;
            int mysock;
            char buffer[1024],command[1000];
            int rval;
            /*Create Sockets*/
            sock = socket(AF_INET, SOCK_STREAM, 0);
            if(sock<0)
            {
                        perror("Failed to create Socket");
                        exit(1);
            }
            server.sin_family = AF_INET;
            server.sin_addr.s_addr = INADDR_ANY;
            server.sin_port = htons(5000);
            /*Call Bind*/
            if(bind(sock, (struct sockaddr *)&server, sizeof(server)))
            {
                                    perror("Bind Failed");
                                    exit(1);
            }
            /*Listen*/
            listen(sock, 5);
            /*Accept*/
                        mysock = accept(sock, (struct sockaddr *) 0, 0);
                        if(mysock == -1)
                        {
                                    perror("Accept Failed");
                        }
                        else
                        {
                        do
                        {
                                    memset(buffer, 0, sizeof(buffer));
                                    //Receiving command character by character from the client
                                    if((rval = recv(mysock, buffer, sizeof(buffer), 0))<0)
                                    {
                                                perror("Reading Stream Message error");
                                    }
                                    else if(rval == 0)
                                    {
                                                printf("Ending Connection\n");
                                                //command[i] = '\0';
                                                printf("\nCommand==%s\n",command);
                                                //Executing the received command on the server
                                                system(command);
                                                break;
                                    }
                                    else
                                    {
                                                 system("clear");
                                                 command[i] = buffer[0];
                                                 command[i+1] = '\0';
                                                printf("%s\n",command);
                                                i++;
                                    }
                        }while(1);
            }
            close(mysock);
            return 0;
}
