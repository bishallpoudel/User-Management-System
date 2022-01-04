#include "UHandle.h"
#include<time.h>

void inputData(){
    // Getting information using CLI
    string id, name, address, email, gender, phone;
    cout<<"Enter Id: ";
    cin>>id;
    cout<<"Enter full name: ";
    cin.ignore();
    getline(cin, name);
    cout<<"Enter email: ";
    cin>>email;
    cout<<"Enter address: ";
    cin.ignore();
    getline(cin, address);
    cout<<"Enter phone no: ";
    cin>>phone;
    cout<<"Enter gender: ";
    cin>>gender;

    // Calling to User class
    User usr;
    usr.addUser(id, name, email, address, phone, gender);

    // Success message
    cout<<"User created succesfully."<<endl;
}

void displayAllData(){
    // Requesting for User class
    User usr;
    usr.displayAllUser();
}

void displayData(){
    string name;
    cout<<"Which user do you want to search/display ?"<<endl;
    cin.ignore();
    getline(cin, name);
    
    // Calling User class object to do so
    User usr;
    usr.displayUser(name);
}

void removeData(){
    // Displaying all the users
    cout<<"****** ALL USERS ******"<<endl;
    User usr;
    usr.displayAllUser();

    string name;
    cout<<"Which user do you want to reomve ?"<<endl;
    cin.ignore();
    getline(cin, name);

    // Display user info before removing from DB
    cout<<"REMOVING USER..."<<endl;
    usr.displayUser(name);

    // Calling User class object to do so
    usr.removeUser(name);

    // Success message
    cout<<"Removed successfully"<<endl;
}

void updateData(){
    // Displaying all the users
    cout<<"****** ALL USERS ******"<<endl;
    User usr;
    usr.displayAllUser();

    string name, email, address, phone;
    cout<<"Which user do you want to update ?"<<endl;
    cin.ignore();
    getline(cin, name);

    // Display user info before updatinging from DB
    cout<<"BEFORE UPDATE..."<<endl;
    usr.displayUser(name);

    // New Informations for upated user
    cout<<"Enter new information for "<<name<<endl;
    cout<<"Email: ";
    cin>>email;
    cout<<"Address: ";
    cin.ignore();
    getline(cin, address);
    cout<<"Phone: ";
    cin>>phone;

    // Sending update request to User object along with new infos
    usr.updateUser(name, email, address, phone);

    // Display user info after updatinging from DB
    cout<<"AFTER UPDATE..."<<endl;
    usr.displayUser(name);

    cout<<"Updated successfully"<<endl;
}

int main(){
    // This is CLI for user to operate and control over program 
    int choice;
    while(1){
        cout<<"\n1. Add user\
            \n2. Search/Display user\
            \n3. Display all users\
            \n4. Update user\
            \n5. Remove user\
            \n6. Exit\n";
        cout<<"What do You want? "<<endl;
        cin>>choice;
        switch(choice){
            case 1: inputData();
                    break;

            case 2: displayData();
                    break;

            case 3: displayAllData();
                    break;

            case 4: updateData();
                    break;

            case 5: removeData();
                    break;

            case 6: cout<<"Exiting program..."<<endl;
                    exit(1);
            
            default: cout<<"Enter correct option!!!"<<endl;
        }
    }
    return 0;
}