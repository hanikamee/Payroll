// Hani Kamee
// July 3rd, 2022
// Status: Completed
// This program read a payroll file, stores the seven payrolls of employees in
// an array and display it to the user.



#include <iostream>
#include <fstream> // Must be included in order to write to and read from a file
#include <iomanip> // Must be included in order to manipulate the output.

using namespace std;

// Class
class PayRoll
{
    // private data members
private:
    double payRate;
    double hoursWorked;

public:
    // getters
    double gethoursWorked() const
    {
        return hoursWorked;
    }

    double getpayRate() const
    {
        return payRate;
    }
    // setters
    void sethoursWorked(double hoursWorked){
        this->hoursWorked = hoursWorked;
    }

    void setpayRate(double payRate){
        this-> payRate = payRate;
    }
    // Default constructor
    PayRoll()
    {
        payRate = 0;
        hoursWorked = 0;
    }
    // Overloaded constructor
    PayRoll(double hw, double pr)
    {
        payRate = pr;
        hoursWorked = hw;
    }
    // calculating the gross pay.
    double getGrossPay(){
        return payRate * hoursWorked;
    }

};


int main()
{
    // Creating an array of 7 of the class payroll
    PayRoll arr[7];

    // Reading from the file payroll dat by specifying its location
    ifstream f("C:/Users/haniy/OneDrive/Documents/C++/ch8assignment/"
               "payroll.dat");

    double hw, pr;

    int i = 0;
    while (f >> pr >> hw){
        // Creating an object named pay
        PayRoll pay(pr, hw);
        arr[i]= pay;
        i++; // This will allow the while loop to go over every item
    }
    f.close(); // Closing the file

    cout << "Employee      Gross Pay"<< endl;

    cout << fixed << setprecision(2); // Output manipulation
    for (i = 0; i < 7; i++){
    // Displaying the employee's number along with the corresponding grosspay
        cout << i+1 << ":" << "\t\t" << "$" << arr[i].getGrossPay() << endl;
    }

    return 0;
}
