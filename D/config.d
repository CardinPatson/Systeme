final class Config{
    public string defaultSyncDir = "Onedrive";
    public string defaultSkipFile  = "*.tmp|.~*";
    public string defaultSkipDir = "";
    public string defaultLogFileDir = "/var/log/onedrive";


    private string[string] stringValues;
    private string[string] boolValues;

    //application set items
    public string refreshTokenFilePath = "";
    public string deltaLinkFIlePath = "";
    this(){
        string getValueString(strink key){
            auto p  = key in stringValues;
            if(p){
                return *p;
            }
            else{
                throw new Exception("Missing config value : "~key);
            }
        }

        bool getValueBool(string key){
            auto p = key in boolValues;
            if(p){
                return *p;
            }else{
                throw new Exception("Missing config value : "~key);
            }
        }
    }
}