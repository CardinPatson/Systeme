#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define closesocket(s) close(s)

typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockeaddr SOCKADDR;


//LE CLIENT EST CELUI QUI VA FAIRE LA REQUETE VERS LE SERVEUR EN ECOUTE
//int connect(int socket , struct sockaddr* addr , socklen_t addrlen) ; 

//socket est toujours celui utilisé

//addr représente l'adresse de l'hote à contacter (faire un cast comme dans accept )

//addrlen est la taille de l'adresse de l'appelant (sizeof )
int main(void){

	SOCKET sock;

	sock = socket(AF_INET  , SOCK_STREAM , 0);

	SOCKADDR_IN sin; // les cles qu'on utilise sur la structure : sin_addr.s_addr , sin.sin_family sin.sin_port

	sin.sin_addr.s_addr = inet_addr("127.0.0.1"); // Pour attrubuer une addresse et htonl(ADDRIN_ANY) sert a attribuer une adresse automatique
	sin.sin_family = AF_INET;
	sin.sin_port = htons(23);

x	if(connect(sock , (SOCKADDR*)&sin , sizeof(sin)) != -1){
		printf("Connexion à %s sur le port %d \n" , inet_ntoa(sin.sin_addr) , htons(sin.sin_port));
		printf("Prêt à servir \n");

	}
	else{
		printf("connexion refusé");
	}

	closesocket(sock);
	//accept(sock , (SOCKADDR*)&sin ,sizeof(sin) );

	//listen(sock , 5);
	return 0;
}
