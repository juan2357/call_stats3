/***********************************************************
Name:  Juan Perez   Z#: 23026404
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date: 01/30/18      Due Time: 11:59 PM
Total Points: 20     Assignment 1: call_stats

Description: This is a program that calculates the net cost of a call (net_cost),
              the tax on a call (call_tax)
              and the total cost of the call (total_cost).
*************************************************************/

//Libraries
#include <iostream> //standard library for i/o
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;
/*********************************************************
//Following is the declaration of a call record
**********************************************************/
class call_record {
public:
	string cell_number;
	int relays;
	int call_length;
	double net_cost;
	double tax_rate;
	double call_tax;
	double total_cost;
};

//Prototypes Prototypes
void Input(ifstream &,call_record &);
void Process(call_record &);
void Output(const call_record &);

//Main PROGRAM
int main( ) {

	call_record customer_record;


	ifstream in;    //declarreadFileg an input file stream
	in.open("call_data.txt");


	if (in.fail())
	{
		cout<<"Input file did not open correctly"<<endl;
	}
	else
	{
		while (!in.eof())
		{

			Input(in,customer_record);
      Process(customer_record);
      Output(customer_record);

		}
	}

	in.close();


	return 0;
}
//Function Calls

//Name:  Input
//Precondition: The varialbes cell_num, relays, and call_length have not been initialized
//Postcondition: The variables have been initialized by data  file.
//Description: Get input values from user.
void Input(ifstream & in, call_record & customer_record) {
	in>>customer_record.cell_number;
	in>>customer_record.relays;
	in>>customer_record.call_length;

  return;
}
//Name:  Process
//Precondition: The variables have been initialized by the data file.
//Postcondition: Conditional statements initialize relay variables.
//Description: Calculates net_cost, call_tax and total_cost.
void Process(call_record & customer_record)
{

  if (customer_record.relays <= 0 && customer_record.relays <=5) {
    customer_record.tax_rate = 0.01;
  } else if (customer_record.relays <= 6 && customer_record.relays <=11) {
    customer_record.tax_rate = 0.03;
  } else if (customer_record.relays <= 12 && customer_record.relays <=20) {
    customer_record.tax_rate = 0.05;
  } else if (customer_record.relays <= 21 && customer_record.relays <=50) {
    customer_record.tax_rate = 0.08;
  } else {
    customer_record.tax_rate = 0.12;
  }

  customer_record.net_cost = customer_record.relays/50.0 * 0.40 * customer_record.call_length;
  customer_record.call_tax = customer_record.net_cost * customer_record.tax_rate;
  customer_record.total_cost = customer_record.net_cost + customer_record.call_tax;

  return;
}
//Name:  Output
//Precondition: The variables have been initialized and calculated
//Postcondition: Results are displayed.
//Description: Prints results from user input and calculations.
void Output(const call_record & customer_record) {
  //magic formula
	ofstream outFile;
	outFile.open("weekly_call_info.txt");

	outFile.setf(ios::showpoint);
	outFile.precision(2);
	outFile.setf(ios::fixed);
	/********************************************/
	outFile<< std::left << setw(30)<< "Cell Phone " <<customer_record.cell_number<<"  "<<endl;
	outFile<< std::left << setw(30)<< "Number of Relay Stations " <<customer_record.relays<<"   "<<endl;
	outFile<< std::left << setw(30)<< "Minutes Used " <<customer_record.call_length<<endl;
  outFile<< std::left << setw(30)<< "Net Cost " <<customer_record.net_cost<<endl;
  outFile<< std::left << setw(30)<< "Tax Rate " <<customer_record.tax_rate<<endl;
  outFile<< std::left << setw(30)<< "Call Tax " <<customer_record.call_tax<<endl;
  outFile<< std::left << setw(30)<< "Total Cost of Call " <<customer_record.total_cost<<endl<<endl;

	outFile.close();
  return;
}
