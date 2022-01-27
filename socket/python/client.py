#!/bin/python3


#Les sockets en python : INET pour les ipv4 et STREAM pour TCP 


#Partie 1 : SOcket bloquant

#L'application client (ex ; navigateur) utilise en partie des sockets client pour la communication entre plateforme
#Les sockets clients sont utilisés que pour un seul échange

#Le serveur auquel le client s'adresse utilise les 2 (clients et serveur)
#1. Il crée un socket serveur


#Partie 2 : Socket non bloquant


import socket
#from socket import socket, AF_INET, SOCK_STREAM
#from socketserver import *

if __name__ == "__main__":

    #Création d'un socket (INET ET STREAMING)
    socket1 = socket.socket(socket.AF_INET ,socket.SOCK_STREAM , 0)

    #print(socket1)

    #Connection du socket à une adresse sur le port 80 http

    # socket1.connect((socket.gethostname() , 80))

    #lorsque la connection à été établie, socket1 peut être utilisé pour des demande de page, il lira la réponse et sera ensuite détruit


    socket1.connect((socket.gethostname() , 80))

    #Envoie des données vers le serveur par lot de 1024 octets
    socket1.sendall("Bienvenue sur mon socket")

    data = socket1.recv(1024)

    socket1.close()

    # print repr(data),"Recue"

    #print("socket après le bind ", socket1)
    #socket1.listen(5)
