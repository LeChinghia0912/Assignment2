#include <iostream>
using namespace std;

double inputValidate(double);
char userChoice(char);
double calculateTotalCharges(double, double);
double calculateTotalCharges(double, double, double, double);

int main()
{
    char user_choice;

    double days_spent,
           daily_rate,
           med_charges,
           services_charge,
           total_charges;
           
    cout << "chon 1 trong 2 " << endl
         << "benh nhan noi tru hay ngoai tru " << endl
         << "nhap 1 cho benh nhan noi tru, 2 cho benh nhan ngoai tru"
         << endl;
     
    user_choice = userChoice(user_choice);

    if (user_choice == '1')
    {
        cout << "so ngay nam vien: ";
        days_spent = inputValidate(days_spent);

        cout << "gia moi ngay: $";
        daily_rate = inputValidate(daily_rate);

        cout << "chi phi thuoc thang: $";
        med_charges = inputValidate(med_charges);

        cout << "phi dich vu benh vien: $";
        services_charge = inputValidate(services_charge);

        total_charges = calculateTotalCharges(days_spent,
                                              daily_rate,
                                              med_charges,
                                              services_charge);
                        
        cout << "tong chi phi = $" 
            << total_charges
            << endl;
    }
    else
    {
        cout << "chi phi thuoc thang: $";
        med_charges = inputValidate(med_charges);

        cout << "phi dich vu benh vien: $";
        services_charge = inputValidate(services_charge);

        total_charges = calculateTotalCharges(med_charges,
                                              services_charge);

        cout << "tong phi = $" 
               << total_charges
               << endl;
    }
    

    return 0;
}
char userChoice(char letter)
{
    cin >> letter;
    while (!((letter == '1') || (letter == '2')))
    {
        cout << "ERROR: enter 1 or 2: ";
        cin.clear();
      //  cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> letter;
    }
    return letter;
}

double inputValidate(double num)
{
    
    while(!(cin >> num) || num < 0)
    {
        cout << "Error. Number must not be "
             << " 0 or greater:";
        cin.clear();
      //  cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return num;
}

double calculateTotalCharges(double med_charges, 
                             double services_charge)
{
     return med_charges + services_charge;
}

double calculateTotalCharges(double days_spent, 
                             double daily_rate, 
                             double med_charges, 
                             double services_charge)
{
     return (days_spent * daily_rate) + med_charges + services_charge;
}