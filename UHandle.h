#include "SQLite.h"

class User{
    // User Informations
    string id;
    string name;
    string email;
    string address;
    string phone;
    string gender;

    public:

    void addUser(string id, string name, string email, string address, string phone, string gender);

    void displayAllUser();

    void displayUser(string name);

    void removeUser(string name);

    void updateUser(string name, string email, string address, string phone);
};

// Updating user 
void User::updateUser(string name, string email, string address, string phone){
    // Asssigning values
    this->name = name;
    this->email = email;
    this->address = address;
    this->phone = phone;

    // Open, send request and close DB
    // Update name with new infos in db
    SQLite sqldb;
    sqldb.updateRow(name.c_str(), email.c_str(), address.c_str(), phone.c_str());
    sqldb.closeDB();
}

// Remove user by its name
void User::removeUser(string name){
    this->name = name;

    // Opening, requesting and closing DB
    SQLite sqldb;
    sqldb.removeRow(name.c_str());
    sqldb.closeDB();
}

// Display user by its name
void User::displayUser(string name){
    this->name = name;

    // Opening, requesting and closing DB
    SQLite sqldb;
    sqldb.displayRow(name.c_str());
    sqldb.closeDB();
}

// Display all the users from DB
void User::displayAllUser(){
    // Opening, requesting and closing DB
    SQLite sqldb;
    sqldb.displayTable();
    sqldb.closeDB();
}

// Adding user into DB
void User::addUser(string id, string name, string email, string address, string phone, string gender){
    // Assigining values to object
    this->id = id;
    this->name = name;
    this->email = email;
    this->address = address;
    this->phone = phone;
    this->gender = gender;

    // Opening DB and passing infos
    SQLite sqldb;
    sqldb.createTable();
    sqldb.insertData(id.c_str(), name.c_str(), email.c_str(), address.c_str(), phone.c_str(), gender.c_str());
    sqldb.closeDB();
}