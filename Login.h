
#include <iostream>
#include <string>
#include <fstream>
class loginFile{
    private:
        std::string filepath;
    public:
        loginFile(){
            filepath = "";
        }
        loginFile(std::string fp) // initializes with a set filepath to write to.
        {
            filepath = fp;
        };
        std::string getFP(){
            return filepath;
        }
        bool setFP(std::string fp){
            std::ifstream ifs(fp);
            if(!ifs.is_open()){
                return false;
            }
            else{
                filepath = fp;
                return true;
            }
        }
        std::string to_store(std::string PW,std::string userName); // takes the hashed PW and the username and puts it in the format to be stored in file.
        std::string get_PW(std::string file_line); // parses the stored file string and returns the hashed PW.
        std::string get_userName(std::string file_line); // parses the stroed file string and returns the userName.
        bool userName_taken(std::string userName); // checks if a registration username is already taken.
        bool is_same_pass(std::string userPW, std::string storedPW); //checks if a hashed password(given string) is the same as the hashed PW line in the file(returns success if so ,fail otherwise).
        int login(std::string userPW,std::string userName);//opens file, reads lines in the file and passes them through is_same_pass to check if the pass and username mathch ,returns true if so false if not. closes file
        int registration(std::string userPW,std::string userName); // opens file, reads till the end, on a new line adds hashed userPW and userName, closes file
        int pass_change(std::string oldPW,std::string olduserName, std::string newPW);// opens file ,find current saved hashed PW and userName , changes PW to new hashed PW and closes the file.

};