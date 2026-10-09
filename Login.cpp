#include <iostream>
#include "Login.h"
#include "bcrypt.cpp"
std::string loginFile::to_store(std::string PW, std::string userName){
    std::string final_line = "[";
    std::string hashedPW;
    hashedPW = bcrypt::generateHash(PW);
    final_line += hashedPW + "," + userName + "]";
    return final_line;

}
std::string loginFile::get_PW(std::string file_line){
    std::string returnedPW;
    char stopper = ',';
    size_t par = file_line.find(stopper);
    returnedPW = file_line.substr(1,par - 1); 
    return returnedPW;

}
std::string loginFile::get_userName(std::string file_line){
    std::string returnedUN;
    char stopper1 = ']';
    char stopper2 = ',';
    size_t par = file_line.find(stopper2);
    returnedUN = file_line.substr(par + 1); 
    size_t par2 = returnedUN.find(stopper1);
    returnedUN = returnedUN.substr(0,par2);
    return returnedUN;

}

bool loginFile::is_same_pass(std::string userPW, std::string storedPW){
    if(userPW != storedPW){
        return false;
    }
    return true;
}
int loginFile::login(std::string userPW,std::string userName){
    bool success = false;
    std::ifstream ifs(getFP());
    if(!ifs.is_open()){
        std::cout<<"Sorry file could not properly be opened, please make sure you have a proper file path saved!"<<std::endl;
        return -1;
    }
    std::string temp_line;
    std::string PW,UN;
    while(getline(ifs,temp_line)){
        PW = get_PW(temp_line);
        UN = get_userName(temp_line);
        if(bcrypt::validatePassword(userPW,PW) && UN == userName){
            success = true;
            break;
        }
    }
    ifs.close();
    if(success == false){
        std::cout << "Sorry UserName and Password Combination couldnt be found, Please make sure the user has Registered First!."<<std::endl;
        return 0;
    }
    else{
        return 1;
    }
}
bool loginFile::userName_taken(std::string userName){
    std::ifstream ifs(getFP());
    std::string line,UN;
    while(getline(ifs,line)){
        UN = get_userName(line);
        if(userName == UN){
            ifs.close();
            return true;
        }
    }
    ifs.close();
    return false;
}
int loginFile::registration(std::string userPW,std::string userName){
    std::ofstream ofs(getFP(),std::ios::app);
    if(!ofs.is_open()){
        std::cout<<"Sorry file could not properly be opened, please make sure you have a proper file path saved!"<<std::endl;
        return 0;
    }
    if(userName_taken(userName)){
        ofs.close();
        std::cout << "Sorry, This username is already taken!" << std::endl;
        return 0;
    }
    else{
        std::string new_entry = to_store(userPW,userName);
        ofs<<new_entry<<std::endl;
        ofs.close();
        return 1;
    }   
}
int loginFile::pass_change(std::string oldPW,std::string olduserName, std::string newPW){
    int search = 0;
    std::fstream fs(getFP(), std::fstream::in | std::fstream::out);
    if(!fs.is_open()){
        std::cout<<"Sorry file could not properly be opened, please make sure you have a proper file path saved!"<<std::endl;
        return -1;
    }
    std::string oldPWHASH = bcrypt::generateHash(oldPW); //hash given oldPW store in varibale to compare to each line.
    std::string newPWHASH = bcrypt::generateHash(newPW);//stores the value of the new password after hashing it.
    std::string temp1,temp2;
    while(getline(fs,temp1)){
        int pos = fs.tellg();
        if(get_PW(temp1) == oldPWHASH){
            fs.seekp(pos - (temp1.length()) - 6);
            fs << to_store(newPWHASH,olduserName);
            search = 1;
            break;
        }
        getline(fs,temp2);
        pos = fs.tellg();
        if(get_PW(temp2) == oldPWHASH){
           fs.seekp(pos - 1);
           fs<< to_store(newPWHASH,olduserName);
           search = 1;
           break;
        }  
    }
    fs.close();
    return search;
}

