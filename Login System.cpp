#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

unordered_map<string, string> database;

void registration() {
    string username, password;

    cout << "-----Register New User-----\n" << endl;
    cout << "Enter your username: ";
    cin>>username;

    //check username already exist
    if(database.find(username)!=database.end()) {
        cout << "username already exist! Try another username..." << endl;
        return;
    }

    cout << "Enter your password: ";
    cin>>password;

    //Save Username and password in database
    database[username]= password;
    cout << "Registration successful!" << endl;
}

void login() {
    string username, password;
    cout << "-----User Login-----" << endl;

    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    //check credentials
    if(database.find(username)!=database.end() && database[username]==password) {
        cout << "Login successful! Welcome "<< username << endl;
    } else {
        cout << "Invalid username or password. Try again." << endl;
    }
}

int main() {
    int choice;
    while(true) {
        cout << "\n-----Login-----\n" << endl;
        cout << "1. Registration" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
        case 1:
            registration();
            break;
        case 2:
            login();
            break;
        case 3:
            cout << "Exiting System. Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid choice! please try again\n" << endl;
        }
    }
    return 0;
}

