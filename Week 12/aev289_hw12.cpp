#include <iostream>
#include <vector>
using namespace std;

class Money {
public:
    Money();
    Money(long dollars);
    Money(long dollars, int cents);
    double getValue( ) const;
    friend istream& operator >>(istream& ins, Money& amount);
    friend Money operator +(const Money& amount1, const Money& amount2);
    friend ostream& operator <<(ostream& outs, const Money& amount);
    friend Money operator -(const Money& amount1, const Money& amount2);
    friend Money operator -(const Money& amount);
    friend bool operator <(const Money& amount1, const Money& amount2);
private:
    long all_cents;
};


class Check {
public:
    Check();
    Check(int CheckNum, Money CheckAmount, bool isCashed);
    int getCheckNum() const;
    Money getCheckAmount( ) const;
    bool getCashed( ) const;
    void setCheckNum(int number);
    void setCheckAmount(Money& amount);
    void setCashed(bool isCashed);
    friend istream& operator >>(istream& ins, Check& amount);
    friend bool operator <(const Check& amount1, const Check& amount2);

private:
    int checkNumber;
    Money checkAmount;
    bool cashed;
};

int digit_to_int(char c);

int main(){
    Money oldBalance, newBalance, deposit;
    Money depositsTotal=0;
    vector<Check> checksVector, cashedChecksVector, uncashedChecksVector;
    Check check;
    int numchecks=0;
    bool inputEndChecks=false;
    bool inputEndDeposits=false;
    Money sumCashed=0, sumUncashed=0;
   
    cout<<"Please enter the check number, check value(including $), and wether or not the check has been cashed.";
    cout<< " Use 1 to indicate cashed and 0 to indicate uncashed. "<<endl;
    cout<<"Enter ONE check per line, seperating each value with a space. "<<endl;
    cout<<"Ex- '# $##.## 1' or '# $##.## 0"<<endl;
    cout<< "Enter 0 as the check number when complete. Ex- 0 $0.00 0"<< endl;
    while(inputEndChecks == false)
    {
            cin >> check;
        if (check.getCheckNum() == 0)
            {
                inputEndChecks= true;

            }
            else
            {
                checksVector.push_back(check);
                numchecks++;
            }
        }
    int i=0;
    while(i<numchecks){
        if (checksVector[i].getCashed()){
            cashedChecksVector.push_back(checksVector[i]);
            sumCashed= sumCashed+ checksVector[i].getCheckAmount();
        }
        else {
            uncashedChecksVector.push_back(checksVector[i]);
            sumUncashed=sumUncashed+ checksVector[i].getCheckAmount();
        }
        i++;
    }
    
    cout<< "The sum of uncashed checks: "<< sumCashed<<endl;
    cout<< "The sum of cashed checks: "<< sumUncashed<<endl;

    cout<<endl;
    cout<<"Enter deposits(Format $##.##), with one deposit per line(end input by typign 0):"<<endl;
    while(inputEndDeposits==false)
    {
        cin>> deposit;
        cout<<endl;
        if(deposit.getValue()== 0.00)
        {
            inputEndDeposits=true;
        }
        else
        {
            depositsTotal= depositsTotal+deposit;
        }
    }
    
    cout<<"The sum of the deposits is: "<<depositsTotal<<endl;
    cout<<endl;
    cout<<"Enter your bank account balance the last time it was balanced (Format-$##.##): ";
    cin>>oldBalance;
    cout<<"Enter your current bank account balance. (Format-$##.##): ";
    cin>>newBalance;
   

    Money cashedChecksTotal;
    for (int i=0; i<cashedChecksVector.size(); i++)
    {
        cashedChecksTotal = cashedChecksTotal + cashedChecksVector[i].getCheckAmount();
    }

    
    Money bankBalance = oldBalance - cashedChecksTotal + depositsTotal;
    cout<<"Bank Balance(only including cleared checks): "<< bankBalance <<endl;
    cout<<"Difference between account holder's balance and bank balance is: "<<bankBalance-newBalance<<endl;
    cout<<endl;

    cout<<"Cashed Checks:"<<endl;
    for (int i=0; i<cashedChecksVector.size(); i++){
        cout<<"Check number: "<< cashedChecksVector[i].getCheckNum()<<" Amount: "<<cashedChecksVector[i].getCheckAmount()<<endl;
    }

    cout<<endl;
    cout<<"Uncashed Checks:"<<endl;
    for (int i=0; i<uncashedChecksVector.size(); i++){
        cout<<"Check number: "<<uncashedChecksVector[i].getCheckNum()<<" Amount: "<<uncashedChecksVector[i].getCheckAmount()<<endl;
    }

    return 0;
}

Money::Money(): all_cents(0){}

Money::Money(long dollars)
{
    if (dollars<0){
        cout<<"Invalid money amount, please try again"<<endl;
        exit(1);
    }
    all_cents = dollars * .01;
}

Money::Money(long dollars, int cents)
{
    if (dollars * cents < 0) {
        cout << "Invalid money amount, please try again"<<endl;
        exit(1);
    }
    all_cents = (dollars*100) + cents;
}

Check::Check(): checkNumber(0), checkAmount(0), cashed(false){}

Check::Check(int CheckNum, Money CheckAmount, bool isCashed)
{
    checkNumber=CheckNum;
    checkAmount=CheckAmount;
    cashed=isCashed;
}

double Money::getValue() const
{
    return all_cents * .01;
}

int Check::getCheckNum() const
{
    return checkNumber;
}

Money Check::getCheckAmount() const
{
    return checkAmount;
}

bool Check::getCashed() const
{
    return cashed;
}

void Check::setCheckNum(int number)
{
    this->checkNumber = number;
}

void Check::setCheckAmount(Money& amount)
{
    this->checkAmount=amount;
}

void Check::setCashed(bool isCashed)
{
    this->cashed=isCashed;
}

istream& operator >>(istream& ins, Check& check)
{
    int ifcashed;
    ins >> check.checkNumber >> check.checkAmount >> ifcashed;

    if (ifcashed == 1 ){
        check.cashed = true;
    }
    else if (ifcashed == 0){
        check.cashed = false;
    }
    else {
        cout<<"Unable to determine if check cashed or not, please try again";
        exit(1);
    }

    return ins;
}

istream& operator >>(istream& ins, Money& amount)
{
    char one_char, decimalPoint, digit1, digit2;
    long dollars;
    int cents;

    ins >> one_char;

    ins >> dollars >> decimalPoint >> digit1 >> digit2;

    if (one_char != '$' || decimalPoint != '.' || !isdigit(digit1) || !isdigit(digit2)) {
        cout << "Error illegal form for money input\n";
        exit(1);
    }

    cents = digit_to_int(digit1) * 10 + digit_to_int(digit2);
    amount.all_cents = dollars * 100 + cents;


    return ins;
}


ostream& operator <<(ostream& outs, const Money& amount)
{
    long positive_cents, dollars, cents;
   
    positive_cents = labs(amount.all_cents);
    dollars = positive_cents/100;
    cents = positive_cents%100;

    if (amount.all_cents < 0)
        outs << "− $" << dollars << '.';
    else
        outs << "$" << dollars << '.';

    if (cents < 10)
        outs << '0';
    outs << cents;

    return outs;
}

Money operator +(const Money& amount1, const Money& amount2)
{
    Money temp;
    temp.all_cents = amount1.all_cents + amount2.all_cents;
    return temp;
}


Money operator -(const Money& amount1, const Money& amount2)
{
    Money temp;
    temp.all_cents = amount1.all_cents - amount2.all_cents;
    return temp;
}

Money operator -(const Money& amount)
{
    Money temp;
    temp.all_cents = -amount.all_cents;
    return temp;
}

bool operator <(const Check& lhs, const Check& rhs)
{
    return lhs.checkAmount < rhs.checkAmount;
}

bool operator <(const Money& amount1, const Money& amount2)
{
    return amount1.all_cents < amount2.all_cents;
}


int digit_to_int(char c)
{
    return static_cast<int>(c) - static_cast<int>('0');
}

