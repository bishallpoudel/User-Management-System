#include<iostream>
#include<string.h>
#include<sqlite3.h>
using namespace std;

class SQLite{
    // Pointer to SQLite connection
    sqlite3 *db;
    // Error message
    char *aErrMsg;
    // Result of the opening file
    int rOpening;
    // SQL command
    const char *sql;
    // Compile sqlite statement
    sqlite3_stmt *stmt;

    // Callback function, It contains result of sql statement
    static int callback(void *fArg, int argc, char **argv, char **azColName);

    // Checking for error if any
    void checkDBError();

    public:

    // Open DB when creating an object
    SQLite();

    // Closing the connection
    void closeDB();

    // Creating DB table
    void createTable();

    // Insert data into table
    void insertData(const char* id, const char* name, const char* email, const char* address, const char* phone, const char* gender);

    // Display all the data of table
    void displayTable();

    // Display specific data
    void displayRow(const char* name);

    // Remove the specific user
    void removeRow(const char* name);

    // Update the specific user
    void updateRow(const char* name, const char* email, const char* address, const char* phone);
};

// Update a row by its name
void SQLite::updateRow(const char* name, const char* email, const char* address, const char* phone){
    // SQL command
    char * query = NULL;

    asprintf(&query, "UPDATE USERS SET EMAIL='%s', ADDRESS='%s', PHONE='%s' WHERE NAME='%s';", email, address, phone, name);

    // cout<<"Query = "<<query<<endl;

    // Prepere the query
    sqlite3_prepare(db, query, strlen(query), &stmt, NULL);
    // cout<<"SQL statement = "<<stmt<<endl;

    // Testing the statement
    rOpening = sqlite3_step(stmt);
    // cout<<"After testing rOpening = "<<rOpening<<endl;

    // Final the statement
    sqlite3_finalize(stmt);

    // Free the space of query
    free(query);
    // cout<<"Query after free: "<<query<<endl;
}

// Remove a row by name
void SQLite::removeRow(const char* name){
    // SQL command
    char * query = NULL;

    asprintf(&query, "DELETE FROM USERS WHERE NAME='%s';", name);
    // cout<<"query = "<<query<<endl;

    // Run sql
    rOpening = sqlite3_exec(db, query, callback, 0, &aErrMsg);
    // cout<<"rOpening = "<<rOpening<<endl;
}

// Display a row by name
void SQLite::displayRow(const char* name){
    // SQL command
    char * query = NULL;

    asprintf(&query, "SELECT * FROM USERS WHERE NAME='%s';", name);
    // cout<<"query = "<<query<<endl;
    
    // Run sql
    rOpening = sqlite3_exec(db, query, callback, 0, &aErrMsg);
    // cout<<"rOpening = "<<rOpening<<endl;
}

// To display all the data of table
void SQLite::displayTable(){
    // SQL for display all
    sql = "SELECT * FROM USERS;" ;
    cout<<"sql = "<<sql<<endl;

    // Run sql
    rOpening = sqlite3_exec(db, sql, callback, 0, &aErrMsg);
    // cout<<"rOpening = "<<rOpening<<endl;
}

// Insert al the data into table
void SQLite::insertData(const char* id, const char* name, const char* email, const char* address, const char* phone, const char* gender){
    // SQL query
    char * query = NULL;

    // Making single string of command and asign into query
    asprintf(&query, "INSERT INTO USERS(ID, NAME, EMAIL, ADDRESS, PHONE, GENDER) VALUES ('%s', '%s', '%s', '%s', '%s', '%s');", id, name, email, address, phone, gender);
    // cout<<"query = "<<query<<endl;

    // Prepere the query
    sqlite3_prepare(db, query, strlen(query), &stmt, NULL);
    // cout<<"SQL statement = "<<stmt<<endl;

    // Testing the statement
    rOpening = sqlite3_step(stmt);
    // cout<<"After testing rOpening = "<<rOpening<<endl;

    // Final the statement
    sqlite3_finalize(stmt);

    // Free the space of query
    free(query);
    // cout<<"Query after free: "<<query<<endl;
}

// Creating DB table
void SQLite::createTable(){
    // SQL command to create table
    sql = "CREATE TABLE IF NOT EXISTS USERS("
            "ID INT PRIMARY KEY NOT NULL UNIQUE, "
            "NAME TEXT NOT NULL UNIQUE, "
            "EMAIL TEXT NOT NULL UNIQUE, "
            "ADDRESS TEXT NOT NULL, "
            "PHONE CHAR(15) NOT NULL UNIQUE, "
            "GENDER CHAR(7) NOT NULL);";
    cout<<"SQL = "<<sql<<endl;
    // Run the sql
    rOpening = sqlite3_exec(db, sql, callback, 0, &aErrMsg);
    // cout<<"After running command rOpening = "<<rOpening<<endl;
}

// Open connection
SQLite::SQLite(){
    // Store the result of opening file
    rOpening = sqlite3_open("User.db", &db);
    // cout<<"rOpening = "<<rOpening<<endl;
    // Check errors
    // cout<<"DB opened succesfully"<<endl;
    checkDBError();
}

// Closing the connection
void SQLite::closeDB(){
        sqlite3_close(db);
        // cout<<"DB closed succesfully"<<endl;
    }

// Callback function, It contains result of sql statement
int SQLite::callback(void *fArg, int argc, char **argv, char **azColName){
    // void *fArg: It is the fourth argument pass in sqlite3_exec() command
    // int argc: It holds the number of results ie. number of rows(may be in some case)
    // char **argv (array of array of charactor): Holds each values of each column
    // char **azColName (array of pointer to pointer of charactor array): Holds each column returned

    // Now to display the returned contents, It goes row by row
    // static int c;
    cout<<"--- User ---"<<endl;
    for(int i=0; i<argc; i++){
        cout<<azColName[i]<< "--> "<<argv[i]<<endl;
    }
     // Inserting new line after completion of first row
    cout<<endl;
    // Returning success
    return 0;
}

void SQLite::checkDBError(){
    if(rOpening){
        // Generally rOpening is zero if not error, If error found display error
        cout<<"DB Error: "<<sqlite3_errmsg(db)<<endl;
        // closing the database
        closeDB();
    }
}