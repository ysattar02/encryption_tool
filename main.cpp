#include <iostream>
#include <vector>
#include <unordered_map>
#include <iterator>
#include <string>
using namespace std;

string get_name(){
    //get name function
    string name;
    cout << "Enter your name: " << endl;
    getline(cin, name);
    return name;
}

string input(string name){
    cout << endl;
    cout << "Welcome to the Encyption/Decryption Tool " << name << "!" << endl << endl;
    cout << "Enter the phrase (a-z) to encrypt or decrypt (all lowercase) and use an underscore to separate words: " << endl;
    string input = "";
    char whitespace = ' ';
    cout << "Enter string to encrypt: ";
    getline(cin, input);
    bool flag = false;
    while (!flag){
        /*
         * if ( cin >> a )
{
   // Ignore rest of the line
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   // Use a
}
else
{
   // Deal with error.
}
         */
        for (int i = 0; i < input.length(); i++){
            if (isdigit(input[i]) == true){
                cout << "Integers are not allowed idiot, try again: " << endl;
                getline(cin, input);
            }
            else if (input[i] == NULL){
                cout << "Whitespace is not allowed kanjar, try again: " << endl;
                cin >> input;
            }
            else{
                flag = true;
            }
        }
    }
    return input;
}
int menu(){
    int choice = -1;
    cout << "Would you like to encrypt or decrypt the message?" << endl;
    cout << "Enter 1 for encrypt or 2 for decrypt: " << endl;
    cin >> choice;
    bool flag = false;
    if (choice == 1){
        flag = true;
    }
    else if (choice == 2){
        flag = true;
    }
    while (!flag){
        cout << "Invalid Input, try again: " << endl;
        cin >> choice;
        if (choice == 1 || choice == 2){
            flag = true;
        }
    }
    if (choice == 1){
        cout << "Encryption Process Beginning!" << endl;
        return 1;
    }
    if (choice == 2){
        cout << "Decrption Process Beginning!" << endl;
        return 2;
    }
}
string encrypt(string message){
    string alpha = "abcdefghijklmnopqrstuvwxyz";
    string r_alpha = "zyxwvutsrqponmlkjihgfedcba";
    pair <string, string> p;
    unordered_map<char, char> alphabet;
    unordered_map<char, char>::iterator itr;
    for (int i = 0; i < alpha.length(); i++){
        alphabet.insert({alpha[i], r_alpha[i]});
    }
    //to print out map contents
//    for (itr = alphabet.begin(); itr != alphabet.end(); ++itr) {
//        cout << '\t' << itr->first << '\t' << itr->second
//             << '\n';
//    }
    string return_val = "";
    char underscore = '_';
    for (int i = 0; i < message.length(); i++){
        if (isspace(message[i]) != 0 || message[i] == underscore){
            return_val += underscore;
        }
        else{
            return_val += alphabet.at(message[i]);
        }
    }
    return return_val;
}
string decrypt(string message){
    string alpha = "abcdefghijklmnopqrstuvwxyz";
    string r_alpha = "zyxwvutsrqponmlkjihgfedcba";
    pair <string, string> p; //might not be needed, unordered map
    unordered_map<char, char> alphabet;
    unordered_map<char, char>::iterator itr;
    for (int i = 0; i < alpha.length(); i++){
        alphabet.insert({r_alpha[i], alpha[i]});
    }
    string return_val = "";
    char underscore = '_';
    for (int i = 0; i < message.length(); i++){
        if (isspace(message[i]) != 0 || message[i] == underscore){
            return_val += underscore;
        }
        else{
            return_val += alphabet.at(message[i]);
        }
    }
    return return_val;
}

int main(){
    cout << "Encryption Tool Active" << endl;
    string name = get_name();
    string message = input(name);
    int operation = menu();
    if (operation == 1){
        string encrypted_phrase = encrypt(message);
        cout << "Encrypted Phrase: " << encrypted_phrase;
    }
    if (operation == 2){
        string decrypted_phrase = decrypt(message);
        cout << "Decrypted Phrase: " << decrypted_phrase;
    }
    return 0;
}


