/*
Socket = Point de terminaison mise à l'écoute sur le réseau pour faire transiter les données logicielles

Elles sont associés à un numéro de ports ( 0- 65535)

Elles sont aussi associé aux protocoles (UDP , TCP/IP)

En C la communication entre 02 programmes peut se faire via les sockets 
Les navigateurs internet utiliseront les sockets pour faire  la liaison entre le client et le serveur (pour récupérer le code source )
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define INVALID_SOCKET -1
#define SOCKET_ERROR -2
#define closesocket(s) close(s)

typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;


/*PREPROCESSEUR RECUPERER DEPUIS SYS SOCKET**/
/*
int socket(int domain , int type , int protocol);

//domain == famille des protocoles (AF_INET pour TCP/IP , AF_UNIX pour les communications unix en local sur la meme machine )

//type == type de service (SOCK_STREAM pour TCP/IP , SOCK_DGRAM pour UDP/IP)

//protocole pas utile peut etre 0



// structure de parametrage de la socket : on a besoin d'une structure pour configurer la connexion

struct sockaddr_in{
	short sin_family;
	unsigned short sin_port;
	struct in_addr sin_addr;
	char sin_zero[8];
}

//la structure in_addr contient un champ nommée s_addr  -- sin_addr.s_addr sera l'ip du serveur

//  -- si vous voulez spécifier manuellement un ip  = inet_addr("127.0.0.1");
//pour la connaitre on peut utiliser  la fonction htnol avec comme paramère INADDR_ANY

//sin_family sera égale à AF_INET 

//sin_port va faire apple a la fonction htons avec pour para le port utilisé 



int bind(int socket , const struct sockaddr* addr  , socklen_t addrlen);

//socket est le socket du serveur 

//addr pointeur de structure sockaddr -- specifie l'ip à laquelle on se connecte

//addrlen taille occupé par le contexte d'addressage du serveur (la structure sockaddr : sizeof(sockaddr))


int listen(int socket , int backlog);

//Backlog est le nombre max de connexion pouvant être mise en attente


int accept(int socket , struct sockaddr* addr , socklen_t* addr_len);

//accept est une fonction bloquante et se termine que si le client se connecte. Lors de la gestion des applications utilisant le threads

//addr pointeur sur la structure sockaddr :  -- specifie l'ip sur lequel on se connecte 

//addrlen taille occupé par le contexte d'addressage du client  -- necessite une nouvelle variable


int closesocket(int sock);

*/

/*
APPLICATION QUI ATTEND QUUN CLIENT SE CONNECTE DESSSUS MAIS SANS APPLICATION CLIENT 

*/

int main(void){

//ETape 1 creer le socket pour configurer la connexion à établier

//Etape 12 La parametrer pour qu'elle communique avec le client 

//Etape 3 Fermeture de la connexion

	SOCKET sock;
	SOCKET csock;

	sock = socket(AF_INET , SOCK_STREAM, 0);

	SOCKADDR_IN sin;
	SOCKADDR_IN csin;

	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	sin.sin_family = AF_INET;
	sin.sin_port  = htons(23);

	bind(sock , (SOCKADDR*)&sin , sizeof(sin));

	//if(listen(sock , 5)){
	printf("Ecoute sur le port 5\n");

	//csock == socket client 
	//csin  == contexte d'addressage du client
	socklen_t taille = sizeof(csin);
	csock = accept(sock , (SOCKADDR*)&sin , &taille) ;
	if (csock){
		printf("Connexion accepté depuis le serveur \n");
	}
	closesocket(csock); //fermeture du socket client

	closesocket(sock); //fermeture du socket serveur

	return 0; 
}

