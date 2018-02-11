/***********************************************************
Name:  Juan Perez   Z#: 23026404
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date: 01/23/18      Due Time: 11:59 PM
Total Points: 20     Assignment 1: call_info

Description: This is a program that calculates the net cost of a call (net_cost),
              the tax on a call (call_tax)
              and the total cost of the call (total_cost).
*************************************************************/

#include <iostream> //standard library for i/o
#include <string>
#include <iomanip>
using namespace std;
//Function Prototypes
void Input(string & cell_num, int & relays, int & call_length);
void Process(const int relays, const int call_length, double & net_cost, double & call_tax, double & total_cost, double & tax_rate);
void Output(const string cell_num, const int relays, const int call_length, const double & net_cost, const double & call_tax, const double & total_cost);

int main()
{
	//Variable Declarations
	string user_response = "y";
  string cell_num;
  double net_cost,
         call_tax,
         total_cost,
         tax_rate;
  int relays,
      call_length;

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	//Runs program until user enters "n"
	while (user_response == "y" || user_response == "Y")
	{

			//Function calls
			//Name:  Input
			//Precondition: The varialbes cell_num, relays, and call_length have not been initialized
			//Postcondition: The variables have been initialized by the user.
			//Description: Get input values from user.
      Input(cell_num, relays, call_length);
			//Name:  Process
			//Precondition: The variables have been initialized by the user.
			//Postcondition: Conditional statements initialize relay variables.
			//Description: Calculates net_cost, call_tax and total_cost.
			Process(relays, call_length, net_cost, call_tax, total_cost, tax_rate);
			//Name:  Output
			//Precondition: The variables have been initialized and calculated
			//Postcondition: Results are displayed.
			//Description: Prints results from user input and calculations.

			Output(cell_num, relays, call_length, net_cost, call_tax, total_cost);

	    cout<<"Would you like to do another calculation (Y or N): "<<endl;
	    cin>>user_response;
	}
	return  0;
}
//Function Definitions
//Name:  Input
//Precondition: The varialbes cell_num, relays, and call_length have not been initialized
//Postcondition: The variables have been initialized by the user.
//Description: Get input values from user.
void Input(string & cell_num, int & relays, int & call_length){
	std::cout << "Pleae enter you phone number: " << endl;
	std::cin >> cell_num;
	std::cout <<"Please enter the number of relays: " << endl;
	std::cin >> relays;
	std::cout << "Please enter the number of minutes on the call" << endl;
	std::cin >> call_length;
	return;
}
//Name:  Process
//Precondition: The variables have been initialized by the user.
//Postcondition: Conditional statements initialize relay variables.
//Description: Calculates net_cost, call_tax and total_cost.
void Process(const int relays,
						 const int call_length,
						 double & net_cost,
						 double & call_tax,
						 double & total_cost,
					 	 double & tax_rate){
	 	if (relays <= 0 && relays <=5) {
      tax_rate = 0.01;
    } else if (relays <= 6 && relays <=11) {
      tax_rate = 0.03;
    } else if (relays <= 12 && relays <=20) {
      tax_rate = 0.05;
    } else if (relays <= 21 && relays <=50) {
      tax_rate = 0.08;
    } else {
      tax_rate = 0.12;
    }

    net_cost = relays/50.0 * 0.40 * call_length;
    call_tax = net_cost * tax_rate;
    total_cost = net_cost + call_tax;

		return;
}
//Name:  Output
//Precondition: The variables have been initialized and calculated
//Postcondition: Results are displayed.
//Description: Prints results from user input and calculations.

void Output(const string cell_num,
	  	 const int relays,
			 const int call_length,
			 const double & net_cost,
			 const double & call_tax,
			 const double & total_cost){

	std::cout << std::left << setw(30)<< "Cell Phone " << cell_num << endl;
  std::cout << std::left << setw(30)<< "Number of Relay Stations " << relays << endl;
  std::cout << std::left << setw(30)<< "Minutes Used " << call_length << endl;
  std::cout << std::left << setw(30)<< "Net Cost " << net_cost << endl;
  std::cout << std::left << setw(30)<< "Call Tax " << call_tax << endl;
  std::cout << std::left << setw(30)<< "Total Cost of Call " << total_cost<< endl;

	return;
}
