#include <iostream>


class Account
{
    char* Name;
    char* Surname;
    int AccountNumber;
    double AccrualPercentage;
    double Sum;
public:
    Account()
    {
        Name = nullptr;
        Surname = nullptr;
        AccountNumber = 0;
        AccrualPercentage = 0;
        Sum = 0;
    }


    Account(char* name, char* surname, int accountnumber, double accrualpercentage, double sum)
    {
        Name = name;
        Surname = surname;
        AccountNumber = accountnumber;
        AccrualPercentage = accrualpercentage;
        Sum = sum;
    }


    ~Account()
    {
        delete[] Name;
        delete[] Surname;
    }


    void Init()
    {
        char buf[20];
        std::cout << "Enter name -> ";
        std::cin.getline(buf, 20);


        if (Name != nullptr)
        {
            delete[] Name;
        }
        Name = new char[strlen(buf) + 1];
        strcpy_s(Name, strlen(buf) + 1, buf);


        std::cout << "Enter surname -> ";
        std::cin.getline(buf, 20);


        if (Surname != nullptr)
        {
            delete[] Surname;
        }
        Surname = new char[strlen(buf) + 1];
        strcpy_s(Surname, strlen(buf) + 1, buf);


        std::cout << "Account number -> ";
        std::cin >> AccountNumber;


        std::cout << "Accrual percentage -> ";
        std::cin >> AccrualPercentage;
    }


    void ChangeAccountOwner()
    {
        std::cout << "Name of new owner -> ";
        std::cin >> Name;


        std::cout << "Surname of new owner -> ";
        std::cin >> Surname;
    }


    void WithdrawMoney()
    {
        int temp;
        std::cout << "How much do you want to withdraw?\n";
        std::cin >> temp;


        if (Sum >= temp)
        {
            Sum -= temp;
            std::cout << "Successfully withdrawed!\n";
        }
        else
        {
            std::cout << "Insufficient funds\n";
        }
    }


    void PutMoney()
    {
        int temp;
        std::cout << "How much do you want to deposit?\n";
        std::cin >> temp;


        Sum += temp;
        std::cout << "Successfully deposited!\n";
    }


    void AccrueInterest()
    {
        int temp;
        std::cout << "How much interest to pay?\n";
        std::cin >> temp;


        Sum = Sum + (Sum / 100 * temp);
        std::cout << "Interest has been successfully calculated!\n";
    }


    void ConvertToDollars()
    {
        std::cout << Sum << " rubles = " << Sum / 68 << " dollars\n";
    }


    void ConvertToEuro()
    {
        std::cout << Sum << " rubles = " << Sum / 72 << " euros\n";
    }


    double GetSum()
    {
        return Sum;
    }
};


int main()
{
    Account obj1;
    obj1.Init();
    obj1.ChangeAccountOwner();
    obj1.PutMoney();
    obj1.AccrueInterest();
    obj1.WithdrawMoney();
    obj1.GetSum();
    obj1.ConvertToDollars();
    obj1.ConvertToEuro();
}