#include<iostream>
#include <string>
using namespace std;
void Open();
void SignUp();
void SignIn();
void Options();
void Call();
void Message();
void Recharging();
void Transfer();
void Packages();

struct numbers {
    string package = { "All for 0.25" }, line;
    double balance = 50;
};
struct information {
    string username, password, email, address;
    int id = 0, number_of_lines = 0;
    numbers number[3];
};

int n, counter = 2, number_to_use, second_number, c = 0;
string user, password, message, serial = {}, start_date = { "31/5/2020" }, renewal_date = { "31/5/2030" };
information inf[50];
int serial10LE[5] = { 1010 , 2010 , 3010 , 4010 , 5010 };
bool usedserial10LE[5] = { false };
int  serial25LE[5] = { 1025 , 2025 , 3025 , 4025 , 5025 };
bool usedserial25LE[5] = { false };
int serial50LE[5] = { 1050 , 2050 , 3050 , 4050 , 5050 };
bool usedserial50LE[5] = { false };
int serial100LE[5] = { 1100 , 2100 , 3100 , 4100 , 5100 };
bool usedserial100LE[5] = { false };
int serial200LE[5] = { 1200 , 2200, 3200 , 4200 ,5200 };
bool usedserial200LE[5] = { false };
int main() {
    inf[0].username = { "user1" }; inf[0].password = { "password1" }; inf[0].number[0].line = { "01093415293" }; inf[0].number[1].line = { "01003524628" };
    inf[0].email = { "user1@gmail.com" }; inf[0].id = 0134; inf[0].number_of_lines = 2; inf[0].address = { "Nasr city" };
    inf[1].username = { "user2" }; inf[1].password = { "password2" }; inf[1].number[0].line = { "01005423871" }; inf[1].number[1].line = { "01004327569" };
    inf[1].email = { "user2@gmail.com" }; inf[1].id = 0124; inf[1].number_of_lines = 2; inf[1].address = { "Downtown" };
    Open();
    return 0;
}
void Open() {
    cout << "Please enter a number that represents what you want to do : \n";
    cout << "1. sign in \t 2. sign up \n";
    cin >> n;
    if (n == 2)
    {
        SignUp();
    }
    else if (n == 1)
    {
        SignIn();
    }
};
void SignUp() {
    cout << "Please enter a username \n";
    cin >> inf[counter].username;
    for (int j = 0; j < 50; j++)
    {
        if (inf[counter].username == inf[j].username)
        {
            if (counter == j)
            {
                continue;
            }
            cout << "This username is used , try another one : \n";
            cin >> inf[counter].username;
        }
    }
    cout << "Please enter password : \n";
    cin >> inf[counter].password;
    cout << "Please enter how many numbers do you have : \n";
    cin >> inf[counter].number_of_lines;
    for (int j = 0; j < inf[counter].number_of_lines; j++)
    {
        cout << "Please enter your number : \n";
        cin >> inf[counter].number[j].line;
        for (int a = 0; a < 50; a++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (a == counter && k == j)
                {
                    continue;
                }
                if (inf[counter].number[j].line == inf[a].number[k].line)
                {
                    cout << "This number is already used by an account ,try another one : \n";
                    cin >> inf[counter].number[j].line;
                }
            }
        }
        if (inf[counter].number[j].line.size() != 11)
        {
            cout << "You entered a wrong number. Make sure that your number consists of 11 numbers \n";
            cin >> inf[counter].number[j].line;
        }
    }
    cout << "Please Enter your email : \n";
    cin >> inf[counter].email;
    cout << "Please enter your ID : \n";
    cin >> inf[counter].id;
    cout << "Please enter your address : \n";;
    cin >> inf[counter].address;
    cout << "we're done now \n";
    Options();
    counter++;
}
void SignIn() {
    bool exist = false;
    cout << "Please enter your username : \n";
    cin >> user;
    for (int i = 0; i < 50; i++)
    {
        if (user == inf[i].username)
        {
            exist = true;
            counter = i;
        }
    }
    if (exist)
    {
        cout << "Please enter your password : \n";
        cin >> password;
        if (password == inf[counter].password)
        {
            cout << "We're done now" << endl;
            Options();
        }
        else
        {
            cout << "You entered an invalid password, try again : \n";
            cin >> password;
            if (password == inf[counter].password)
            {
                cout << "We're done now" << endl;
                Options();
            }
            else
            {
                cout << "You entered an invalid password, try again : \n";
                cin >> password;

            }
        }
    }
    else
    {
        cout << "You entered an invalid username \n";
        cout << "Please enter your username : \n";
        cin >> user;
        for (int i = 0; i < 50; i++)
        {
            if (user == inf[i].username)
            {
                exist = true;
                counter = i;
            }
        }
        if (exist)
        {
            cout << "Please enter your password : \n";
            cin >> password;
            if (password == inf[counter].password)
            {
                cout << "We're done now" << endl;
                Options();
            }
            else
            {
                cout << "You entered an invalid password, try again : \n";
                cin >> password;
                if (password == inf[counter].password)
                {
                    cout << "We're done now" << endl;
                    Options();
                }
                else
                {
                    cout << "You entered an invalid password, try again : \n";
                    cin >> password;

                }
            }
        }
        else
        {
            cout << "You entered an invalid username \n";
            cout << "Please enter your username : \n";
            cin >> user;
        }

    }
}
void Options() {
    int n;
    cout << "To make a call press 1 \nTo send a message press 2 \nTo recharge your balance press 3 \nTo transfer balance press 4 \n";
    cout << "To change your package press 5 \nTo sign in press 6\nTo know your renewal date press 7 \nTo sign up press 8 \nTo exit press 9 \n ";
    cin >> n;
    switch (n)
    {
    case 1:
        Call();
        break;
    case 2:
        Message();
        break;
    case 3:
        Recharging();
        break;
    case 4:
        Transfer();
        break;
    case 5:
        Packages();
        break;
    case 6:
        SignIn();
        break;
    case 7:
        cout << renewal_date << endl;
        Options();
        break;
    case 8:
        SignUp();
        break;
    case 9:
        break;
    default:
        cout << "You entered a wrong number \n";
        Options();
        break;
    }
}

void Call() {
    int x = 0, c = 0;
    cout << "Which number do you want to use ? \n";
    for (int j = 0; j < inf[counter].number_of_lines; j++)
    {
        cout << inf[counter].number[j].line << " press " << j + 1 << endl;
    }
    cin >> number_to_use;
    for (int j = 0; j <= inf[counter].number_of_lines; j++)
    {
        if (number_to_use == j)
        {
            x = j - 1;
        }
    }
    cout << "Which number do you want to call ? \n";
    for (int i = 0; i < inf[counter].number_of_lines; i++)
    {
        if (number_to_use == (i + 1))
        {
            c++;
            continue;
        }
        cout << inf[counter].number[i].line << " press " << i + 1 - c << endl;

        c = 0;
    }
    cin >> second_number;
    if (inf[counter].number[x].balance > 0.25)
    {
        inf[counter].number[x].balance -= 0.25;
        cout << "call done, your balance is " << inf[counter].number[x].balance << endl;
        Options();
    }
    else
    {
        cout << "Your balance isn't enough \n";
        Options();
    }
}

void Message() {
    int x = 0;
    cout << "Which number do you want to use ? \n";
    for (int j = 0; j < inf[counter].number_of_lines; j++)
    {
        cout << inf[counter].number[j].line << " press " << j + 1 << endl;
    }
    cin >> number_to_use;
    for (int j = 0; j <= inf[counter].number_of_lines; j++)
    {
        if (number_to_use == j)
        {
            x = j - 1;
        }
    }
    cout << "Which number do you want to send a message for ? \n";
    for (int i = 0; i < inf[counter].number_of_lines; i++)
    {
        if (number_to_use == (i + 1))
        {
            c++;
            continue;
        }
        cout << inf[counter].number[i].line << " press " << i + 1 - c << endl;
        c = 0;
    }
    cin >> second_number;
    cout << "Type the message you want to send : \n";
    cin >> message;
    if (inf[counter].number[x].balance > 0.25)
    {
        inf[counter].number[x].balance -= 0.25;
        cout << "Message sent, your balance is " << inf[counter].number[x].balance << endl;
        Options();
    }
    else
    {
        cout << "Your balance isn't enough \n";
        Options();
    }
}
void Recharging()
{
    int x = 0, serial_number;
    cout << "Which number do you want to use ? \n";
    for (int j = 0; j < inf[counter].number_of_lines; j++)
    {
        cout << inf[counter].number[j].line << " press " << j + 1 << endl;
    }
    cin >> number_to_use;
    for (int j = 0; j <= inf[counter].number_of_lines; j++)
    {
        if (number_to_use == j)
        {
            x = j - 1;
        }
    }
    cout << "Enter the serial number : \n";
    cin >> serial_number;
    bool accepted = false;
    for (int i = 0; i < 5; i++)
    {

        if (serial_number == serial200LE[i] || serial_number == serial10LE[i] || serial_number == serial25LE[i] || serial_number == serial50LE[i] || serial_number == serial100LE[i])
        {
            accepted = true;
        }
        if (serial_number == serial10LE[i] && !usedserial10LE[i])
        {
            usedserial10LE[i] = true;
            inf[counter].number[x].balance = inf[counter].number[x].balance + 10;
            cout << "Your balance is : " << inf[counter].number[x].balance << endl;
            Options();
            break;
        }
        else if (serial_number == serial25LE[i] && !usedserial25LE[i])
        {
            usedserial25LE[i] = true;
            inf[counter].number[x].balance = inf[counter].number[x].balance + 25;
            cout << "Your balance is : " << inf[counter].number[x].balance << endl;
            Options();
            break;
        }
        else if (serial_number == serial50LE[i] && !usedserial50LE[i])
        {
            usedserial50LE[i] = true;
            inf[counter].number[x].balance = inf[counter].number[x].balance + 50;
            cout << "Your balance is : " << inf[counter].number[x].balance << endl;
            Options();
            break;
        }
        else if (serial_number == serial100LE[i] && !usedserial100LE[i])
        {
            usedserial100LE[i] = true;
            inf[counter].number[x].balance = inf[counter].number[x].balance + 100;
            cout << "Your balance is : " << inf[counter].number[x].balance << endl;
            Options();
            break;
        }
        else if (serial_number == serial200LE[i] && !usedserial200LE[i])
        {
            usedserial200LE[i] = true;
            inf[counter].number[x].balance = inf[counter].number[x].balance + 200;
            cout << "Your balance is : " << inf[counter].number[x].balance << endl;
            Options();
            break;
        }
        else if (usedserial10LE[i] || usedserial25LE[i] || usedserial50LE[i] || usedserial100LE[i] || usedserial200LE[i]) {

            if (accepted)
            {
                cout << "Used card number, please try again\n";
                Options();
                break;
            }
            else
            {
                cout << "wrong number , please try again.\n";
                Options();
                break;
            }

        }
        else
        {
            if (i == 4)
            {
                cout << "wrong number , please try again.\n";
                Options();
                break;
            }
        }
    }
}
void Transfer() {
    int a = 0, x = 0, amount = 0, b = 0;
    string transfer_number;
    bool exist = false;
    cout << "Which number do you want to use ? \n";
    for (int j = 0; j < inf[counter].number_of_lines; j++)
    {
        cout << inf[counter].number[j].line << " press " << j + 1 << endl;
    }
    cin >> number_to_use;
    for (int j = 0; j <= inf[counter].number_of_lines; j++)
    {
        if (number_to_use == j)
        {
            x = j - 1;
        }
    }
    cout << "Type the number you want to transfer to: \n";
    cin >> transfer_number;
    cout << "Type the amount you want to transfer : \n";
    cin >> amount;
    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (transfer_number == inf[i].number[j].line)
            {
                a = i;
                b = j;
                exist = true;
                break;
            }
        }
    }
    if (inf[counter].number[x].balance >= amount)
    {
        if (exist)
        {
            inf[counter].number[x].balance -= amount;
            inf[a].number[b].balance += amount;
            cout << "Transfer done, your balance is " << inf[counter].number[x].balance << endl;
            cout << transfer_number << "'s balance is " << inf[a].number[b].balance << endl;
            Options();
        }
        else
        {
            cout << "This  number doesn't exist \n";
            Options();
        }
    }
    else
    {
        cout << "Your balance doesn't contain this amount. \n";
        Options();
    }
}
void Packages() {
    int a, x = 0, number_of_package;
    string packages[3];
    packages[0] = { "Internet 10" }; packages[1] = { "Internet 20" }; packages[2] = { "All for 0.25" };
    cout << "Which number do you want to use ? \n";
    for (int j = 0; j < inf[counter].number_of_lines; j++)
    {
        cout << inf[counter].number[j].line << " press " << j + 1 << endl;
    }
    cin >> number_to_use;
    for (int j = 0; j <= inf[counter].number_of_lines; j++)
    {
        if (number_to_use == j)
        {
            x = j - 1;
        }
    }
    cout << "Your package is " << inf[counter].number[x].package << endl;
    cout << "choose the package you want : \n";
    for (int j = 0; j < 3; j++)
    {
        cout << packages[j] << " press " << j + 1 << endl;
    }
    cin >> number_of_package;
    for (int j = 0; j <= 3; j++)
    {
        if (number_of_package == j)
        {
            a = j - 1;
            break;
        }
    }
    if (packages[a] == inf[counter].number[x].package)
    {
        cout << "This package is your current package \n";
        Options();
    }
    else
    {
        inf[counter].number[x].package = packages[a];
        switch (a)
        {
        case 0:
            inf[counter].number[x].balance -= 10;
            break;
        case 1:
            inf[counter].number[x].balance -= 20;
            break;
        case 2:
            inf[counter].number[x].balance -= 0.25;
            break;
        }
        cout << "Your new package is : " << inf[counter].number[x].package << endl;
        cout << "Your balance is : " << inf[counter].number[x].balance << endl;
        Options();
    }
}