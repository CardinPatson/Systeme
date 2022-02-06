#!/bin/bash
#include <sys/socket.h>

echo -e "==================\nLa commande find\n=================\n"

echo -e `find -type f -name '*.sh' -exec ls {} \;`
echo -e `find -type f -name "*.sh" -print0`
#{} -- Pour le resultat de tous ce qui se trouve derriere le -exec
#\; -- Sans ces caractères de fin, ne parvient pas a retrouver les paramètres


variable="Je suis une phrase"


commande_seq=`seq 1 10` #print a sequence of numbers

echo $commande_seq



commande="Execution de la commande tr "


#La commande tr -d
echo -e "=================\n"
echo -e "La commande tr\n"
echo -e "=================\n"

tr="Me voici  avec les a dans la phrase \n"

echo -e "${tr}"

echo `echo -e "${tr}" | replace "avec" "sans" | tr -d 'a' ` #| tr -c s`

#La commande tr prend un input et delete ou remplace un suite de caractère
#tr -d supprime tous les caractères que tu lui passe
#tr -s remplace toutes les occurences qui se répetent par une seule
 
#La commande cut
echo -e "==================\n"
echo -e "La commande cut \n"
echo -e "==================\n"

cut="Coupons cut dans cette phrase"

echo "cut -f 2 -d " "de ${cut} =" `echo "${cut}" | cut -f 2 -d " "`

#echo `echo "${cut}" | cut -c "c"`

#echo `man tr`

#if [commande == "Execution de la commande tr "]do;
#	echo "je suis le if";
#endif;

echo -e  "\nJe suis le debut des condition en bash"


#les nombres

echo -e "\n=================\nLes nombres\n================"

let "a = 5"
let "b = a + 1"
echo $a $b


#Declaration des tableaux
echo -e "\n=================\nLes tableaux\n================"
tableaux=("valeur1" "valeur2" "valeur3")

echo ${tableaux[0]}
echo "${tableaux[*]}" #recupere toutes les valeurs du tableaux 


#Les conditions

echo -e "\n==================\nLes conditions\n================"

#Les types de conditions et leurs significations

#Test sur les fichiers

#1. -e $fichier -- verifie si le fichier existe
#2. -d $fichier -- verifie si le fichier est un rép 
#3. -f $fichier -- verifie si le fichier est un fichier standard
#4. -L $fichier -- verifie si le fichier est un lien symbolique(raccourcie)
#5. -r $fichier -- verifie si le fichier est lisible (read)
#6. -w ------------------------------------- modifiable(write)
#7. -x ------------------------------------- executable(execute)
#8. $fichier1 -nt $fichier2 -- verifie si fichier1 est plus récent que fichier2(newer than)
#9. $fichier1 -ot $fichier2 -- verifie si fichier1 est plus ancien que fichier2 (old than) 

#Test sur les chaines

#1.$chaine1 =  $chaine2 
#2.$chaine1 != $chaine2
#3. -z $chaine -- verifie si la chaine est vide
#4. -n $chaine -- verifie si la chaine est non vide 

#Test sur les nombres

#1. $num1 -gt $num2 -- plus grand que
#2. $num1 -lt $num2 -- plus petit que 
#3. $num1 -ge $num2 -- plus grand ou egale
#4. $num1 -le $num2 -- plus petit ou egale
#5. ----- -eq ----- -- egale
#6. ----- -ne ----- -- different 

var="papa"
#Les expressions en bash sont dans deux crochet [[]]
#Pour evaluer les variables dans les expressions toujours mettre les ${}

if [ $var="apa" ] || [ $var!="papa" ]  #Les conditions en bash nont pas besoin de 2"="
then
	echo -e "enter in the condition\n"
fi

if [ -e ./commande.py  ] ;
then
	echo -e "contenu du fichier commande.py\n"
	echo -e "`cat ./commande.py`\n"
fi

#REMARQUE : dans les crochets des conditions il faut des espaces au début et à la fin, entre = il n'ya pas d'espace

#if [./commande.py];
#	then echo "je suis une commande"
#fi

#if echo "je suis" ; #Peut permettre l'execution de commande
#then
#	echo "papa"
#fi


#Boucle while
echo -e "\n===================\nLes Boucles While\n===================="

var="papa"
while true; do
       echo -e "je suis une boucle ifinie\n"
	if [ ${var} = "papa" ];
	then
		break
	fi
done

let "var = 0"

for i in `seq 1 10`;do
	echo -e "$i\n"
done

while [$var -lt 10 ];do
	let "var = var +1"
	echo -e "Nouvelle valeur de var -- $var\n"
done

#Les Fonctions

echo -e "\n=====================\nLes Fonctions\n======================="

#Pour appeler une fonction en bash on ne met pas les () 

function my_function(){
	#echo -e "je suis dans la dfonction\n"
	if [ -d  ./ ]
	then
		liste=`ls ./`
		liste_fichier=(`echo ${liste} | tr -d "\n"`)

		# ***Possible de créer des liste à partir de echo ***
		#echo -e "fichier premier ${liste_fichier[0]}"
		
		for file in ${liste_fichier[*]};do
		
			if [ -f $file ] && [ $file!="commande.sh" ];then
				echo -e "\nContenu du fichier : ${file}\n"
				echo -e "\n-------------------------------------------------------------------------------------------------\n"
				echo -e "`cat $file`\n"
				echo -e "\n-------------------------------------------------------------------------------------------------\n"
			fi
		done
	fi
	return ${liste_fichier[0]}
}
my_function


#Return dans une fonction qui prend des paramère

function transform_list(){
	
	list=my_function
	return $a

}
echo `transform_list`




echo -e "\n========================\nAutomatisation\n=======================\n"

echo -e "C'est fonction ne peuvent ne peuvent être tester que par vous\nDecomentez et Adaptez les lignes dont vous aviez besoin!\n\nPrenez garde, risque de perte de fichier\n"

echo -e "\n---Rename extension1 to extension2---\n"

#for file in *.ext1;do mv -- "$file" "${file%.ext1}.ext2";done

echo -e "\n---Remove extension1 from all files---\n"

#for file in ./*.ext1;do mv "$file" "${file%.ext1}";done"

echo -e "\n---Remplacer tous les espaces par underscore---\n"

#for file in *\ *;do mv -- "$file" "${file// /_}";done

echo -e "\n---Remplacer chaine1 par chaine2---\n"

#for file in ./*chaine1*;do mv "$file//chaine1/chaine2";done

echo -e "\n---Remplacer tous les .ext1 par .ext2 DANS TOUS LES SOUS REP\n"

#find . -type f -name '*.ext1' -print0 | while IFS= read -r -d '' f; do
#	mv -- "$f" "${f%.ext1}.ext2"
#done

echo -e "\n---Faire de meme pour tous les autres fichiers---\n"

#voir un exemple :
#find / -type f -name del_killer.sh | cd
#Copyright Cardin Tiako 2022
