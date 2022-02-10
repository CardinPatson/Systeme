//les types en d 
//long, bool, string, 

//ON REMPLACE LES TYPES CHAR PAR LONG =
import std.stdio;
import std.stdint;
import std.datetime , std.datetime.systime;

//
import std.net.curl;
import std.file;

import core.memory;
import std.process;
import std.conv;
import  core.sys.posix.pwd, core.sys.posix.unistd;
import config;

//GET USERNAME VIA ONEDRIVE

void testConnection(){
    auto http = HTTP();
    http.method = HTTP.Method.get;
    http.url  ="http://google.com";

    //LES METHODES POSSIBLE DE HTTP
    //http.onReceive  = (ubyte[] data ){return data.length}
    //http.onProgress = (){}
    //http.pereform
}


//[DOC] Passer une fonction en paramètre
int addOne(int a)pure{
    return a +1;
}

int addTwo(int a)pure{
    return a +2;
}

int apply( int function(int) pure fun, int value)pure{
    return fun(value);
}  

int function(int) pure apply2(int value)pure{

    //RETURN UNE FUNCTION
    return value == 1 ? &addOne :&addTwo;
} 


//[CODE] function principale main 
void main(){
string username ;
string userSurName ;

// mkdir("./patson");

//LIRE ET ECRIRE LENTRE USER
username = readln; 
writeln("Your username is " , username);


//[DOC] : LES CONDITIONS

if(username != "" ){
    userSurName = readln;
    writeln("Your surname is ", userSurName);
}else{
    writeln("Error please enter your name before");
}

//[DOC] : LES BOUCLES
int i ; 
for(i = 0 ;  i<5; i++){
    writeln("Ici un compteur : ",i);
}

//[TEST] function en parametre
writeln("function en para 1",apply(&addOne , 2));
writeln("function en para 2", apply2(5));
}








// [DOC] : LES CLASSES 
// class APIOnedrive{
//     private Config cfg; // variable interne à la classe 
//     private HTTP http;
//     private string notification;
//     private string host ;

//     bool printAccessToken;
//     //constructeur
//     this(Config cfg ){
//         this.cfg = cfg;
//         http = HTTP();

//         http.dnsTimeout(dur!"seconds"(5));

//         http.connectTimeout = (dur!"seconds"(10));

//         http.dataTimeout(dur!"seconds"(600));

//         http.operationTimeout = (dur!"seconds"(cfg.getValueLong("operation_timeout")));


//         http.maxRedirects(5);

//         if(cfg.getValueBool("debug_https")){
//             http.verbose = true;
//             .debugResponse = true;
//         }

//         //Mise a jour du clientId si l'appli_id est configurer dans le fichier de configuration
//         if(cfg.getValueString("application_id") != ""){
            
//         }
//     }
// }