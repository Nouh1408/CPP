#include<iostream>
using namespace std;

void showmenu(){
    cout << "1. Check Balnce" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Withdraw" << endl;
    cout << "4. Exit" << endl<<endl;
}

int main(){
    int option;
    double initial_balance = 500;
    do{
        showmenu();
        cout<<"Option: ";
        cin>>option;
        system("cls");

        switch (option)
        {
        case 1:
            cout<<"Balance is "<<initial_balance<<" $"<<endl;
            break;
        case 2:
        cout<<"Deposit amount: ";
        double deposit;
        cin>>deposit;
        initial_balance+=deposit;
        break;
        case 3:
            cout<<"Withdraw amount: ";
            double withdraw;
            cin>>withdraw;
            if(withdraw<=initial_balance){
                initial_balance-=withdraw;
            } else{
                cout<<"There is not enough money";
            }
            break;
        }
    } while (option != 4);
    
}