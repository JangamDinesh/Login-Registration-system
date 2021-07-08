#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to generate and verify captcha
bool verify()
{
    int x, y, val;
    int ans;
    srand(time(0));
    x = rand()%10+2*(rand()%10);
    y = rand()%10+1;
    val = x+y;
    cout<<"Captcha: "<<x<<" + "<<y<<" = ";
    cin>>ans;
    if(ans == val) return true;
    else return false;
}

// Function for registering..
void Register()
{
    string username, password;
    cout<<"Create a username: \n";
    cin>>username;
    cout<<"Create a password: \n";
    cin>>password;

    ofstream file(username + ".txt");
    file<<username;
    file<<endl;
    file<<password;
    cout<<"\nRegistered successfully\n\n";
    system("PAUSE");
    file.close();
}

// Function to check if login credentials are true or not
bool isLoggedIn()
{
    string username, password;
    string u,p;
    cout<<"Enter username: ";
    cin>>username;
    cout<<"Enter password: ";
    cin>>password;

    ifstream obj(username + ".txt");
    obj>>u;
    obj>>p;

    if(u==username && p==password)
        return true;
    else
        return false;
}

// function to retain users password
void forgotPassword( string un )
{
    string s1, s2;
    bool captcha;

    ifstream readFile(un + ".txt");
    readFile>>s1;
    readFile>>s2;

    if(s1 != un)
    {
        cout<<"\nEnter valid username!\n"<<endl;
    }
    else
    {
        captcha = verify();
        if(captcha == false)
            cout<<"\nEnter valid captcha!!"<<endl;
        else
             cout<<"\nYour password is : "<<s2<<endl<<endl;
    }
}

int main()
{
    do{
        int x;
        cout << "\n1.Registration\n";
        cout << "2.Login\n";
        cout << "3.Forgot password?\n";
        cout << "4.Exit\n";
        cout << "Enter your choice: ";
        cin >> x;
        cout<<endl;

        if(x == 1)
        {
            Register();
            //main();
        }

        else if(x == 2)
        {
            bool status;
            status = isLoggedIn();

            if(status == 0)
            {
                cout<<"\nLogin Failed!!!\nEnter valid details\n"<<endl;
                system("PAUSE");
                /*  cin.ignore();
                    cin.get();
                */

                //return 0;
            }
            else
            {
                cout<<"\nSuccessfully logged in!\n"<<endl;
                system("PAUSE");
                break;
                //return 1;
            }
        }

        else if(x == 3)
        {
            string s;
            cout<<"Enter your username: "; cin>>s;

            forgotPassword(s);
            system("pause");

            //main();
        }

        else if(x == 4)
            break;

        else
        {
            cout<<"Enter Valid choice\n"<<endl;
            //
            system("PAUSE");
            //main();
        }
    } while(true);

    return 0;
}
