#!usr/bin/python3
#-*- coding: utf-8 -*-

import socket

if __name__ == "__main__":

	socket_server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

	#Lier le socket a un hote public et a un port connu
	socket_server.bind((socket.gethostname() ,80))

	#Lui farie devenir un socket server (Mettre en attente un maximum de 5 demandes)
	socket_server.listen(5)

	clientsocket, address = socket_server.accept()

	while True:

		#Lit les donnée du socket par lots de 1024 octects jusqau'a retourner un chaine vide
		data = clientsocket.recv(1024)

		if not data:
			break
		clientsocket.sendall(data)
	
		# ct=client_thread(clientsocket)
		# ct.run()
	clientsocket.close()	
		
		#Accepter les connexions venant de l'exterieur
		#(clientsoket , address) = socket_server.accept()
        #Un connecteur serveur n'envoie ni ne recoit aucune données, il ne fait que produire des connecteurs clients
        #ct = client_thread(clientsocket)
		#ct.run()
