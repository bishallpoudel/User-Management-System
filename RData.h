// #include<iostream>
// #include<string.h>
// using namespace std;
// #include<vector>

// class RData: public User{
//     // User Informations
//     char id[20];
//     char name[20];
//     char email[20];
//     char address[20];
//     char phone[20];
//     char gender[20];

//     public:
//     char** callbacks(int argc, char **argv, char **azColName){
//         cout<<"In RDAta"<<endl;
//         cout<<"--- User ---"<<endl;
//         vector<char*> vec;
//         for(int i=0; i<argc; i++){
//             vec.push_back(argv[i]);
//             // cout<<azColName[i]<< "--> "<<argv[i]<<endl;
//         }
//         // Inserting new line after completion of first row
//         for (int i = 0; i < vec.size(); ++i) {
//         cout << vec[i] << "; ";
//         }
//         cout<<endl;


//         // cout<<argv[0];
//         // strcpy(id, argv[0]);
//         // strcpy(name, argv[1]);
//         // strcpy(email, argv[2]);
//         // strcpy(address, argv[3]);
//         // strcpy(phone, argv[4]);
//         // strcpy(gender, argv[5]);
//         // display();
//         return argv;
//     }

//     void display(){
//         cout<<id<<endl;
//         cout<<name<<endl;
//         cout<<email<<endl;
//         cout<<address<<endl;
//         cout<<phone<<endl;
//         cout<<gender<<endl;
//     }
// };