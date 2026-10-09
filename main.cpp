#include <iostream>
#include <string>
#include <fstream>
#include "Login.cpp"
int main() {
    int menuInput;
    std::string filepath;
    loginFile login;
    do{
        std::cout<<"----------------------------------------"<<std::endl;
        std::cout<<"Welcome to Your Local LoginFile System!"<<std::endl;
        std::cout<<"If you do not have one registered already ,Please Enter a File Path you wish to use to store the login information."<<std::endl;
        std::cout<<"----------------------------------------"<<std::endl;
        std::cout<<"Please choose from one of the options below!"<<std::endl;
        std::cout<<"1. Add New FilePath"<<std::endl;
        std::cout<<"2. Register User"<<std::endl;
        std::cout<<"3. User Login"<<std::endl;
        std::cout<<"4. Change Password"<<std::endl;
        std::cout<<"5. Exit"<<std::endl;
        //
        std::cin >> menuInput;
        if(menuInput == 1){
            bool temp;
            std::getline(std::cin>>std::ws,filepath);
            temp = login.setFP(filepath);
            if(temp == false){
                std::cout<<"Sorry FilePath could not be opened, please ensure it was entered correctly."<<std::endl;
            }
            else{
                std::cout<<"FilePath Stored Properly!"<<std::endl;
            }
        }
        else if(menuInput == 2){
            std::string password;
            std::string username;
            int temp;
            std::cout<<"Please enter a username."<<std::endl;
            std::cin >> username;
            std::cout<<"Please enter a password"<<std::endl;
            std::cin >> password;
            temp = login.registration(password,username);
            if(temp == 1){
                std::cout<<"Registration Sucessful!"<<std::endl;
            }
            else{
                std::cout<<"Registration Failed!"<<std::endl;
            }
        }
        else if(menuInput == 3){
            std::string password;
            std::string username;
            int temp;
            std::cout<<"Please enter Your username."<<std::endl;
            std::cin >> username;
            std::cout<<"Please enter Your password"<<std::endl;
            std::cin >> password;
            temp = login.login(password,username);
            if(temp == 1){
                std::cout<<"Login Sucessful!"<<std::endl;
            }
            else{
                std::cout<<"Login Failed!"<<std::endl;
            }
        }
        else if(menuInput == 4){
            std::string oldPW,oldUN,newPW;
            int temp;
            std::cout<<"Please enter Your username."<<std::endl;
            std::cin >> oldUN;
            std::cout<<"Please enter Your password"<<std::endl;
            std::cin >> oldPW;
            std::cout<<"Please enter your new password"<<std::endl;
            std::cin >> newPW;
            temp = login.pass_change(oldPW,oldUN,newPW);
            if(temp == 1){
                std::cout<<"Password change Sucessful!"<<std::endl;
            }
            else{
                std::cout<<"password change Failed!"<<std::endl;
            }
        }
        else if(menuInput != 1 || menuInput != 2 || menuInput != 3 || menuInput != 4 || menuInput != 5){
            std::cout<<"Sorry that is not an avaliable input, please try again"<<std::endl;
            break;
        }
    }while(menuInput != 5);
    return 0;
}   