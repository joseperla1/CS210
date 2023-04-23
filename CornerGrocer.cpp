#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;
// creating class for different functions to be used later
class groceries
{
public:
	void readDataFile();
	void displayMenu();
private:
	// creating a map for frequency of item
	map<string, int> frequency;
	//function for option 1
	void searchItem();
	//function for option 2
	void printFrequencyList();
	//function for option 3
	void printHistogram();
};
void groceries::readDataFile()
{
	// method to get data from text file
	ifstream dataFile("CS210_Project_Three_Input_File.txt");
	string item;
	while (dataFile >> item) {
		frequency[item]++;

	}
	//method to create dat file 
	ofstream outFile; 
	outFile.open("frequency.dat");
	// function that creates the data points in the file ( item and frequency)
	for (auto i : frequency) {
		outFile << i.first << " " << i.second << endl;
	}
	dataFile.close();
	outFile.close();
}
void groceries::displayMenu()
{
	//creating variable for user input
	int choice;
	do
	{
		//displays menu
		cout << "\nMenu\n";
		cout << "------ What would you like to do? ------ " << endl;
		cout << "1. Search inventory" << endl;
		cout << "2. Print entire grocery list inventory " << endl;
		cout << "3. Print Histogram of grocery list" << endl;
		cout << "4. Exit Program" <<endl;
		//gets user input
		cin >> choice;
		// different cases based on user input
		switch (choice)
		{
		// cases call function from the private classes
		case 1:
			searchItem();
			break;
		case 2:
			printFrequencyList();
			break;
		case 3:
			printHistogram();
			break;
		//method to exit program
		case 4:
			cout << "Exiting....." << endl;
			break;
		// method to verify correct input from user
		default:
			cout << "Invalid entry please choose option 1-4" << endl;
			break;
		}
	// allows user to continue using menu until exit method
	} while (choice != 4);
}
// function for menu option 1

void groceries::searchItem()
{
	// creates variable for user input grocery item
	string item;
	cout << " Search item name: ";
	cin >> item;
	//searches list to find user inputted item
	if (frequency.find(item) == frequency.end())
	{
		//if item not found
		cout << item << "Item not found" << endl;
	}
	else {
		//when item is found returns item along with frequency of item in list
		cout << item << ":" << frequency[item] << " In Stock" << endl;

	}
}
//function for menu option 2
void groceries::printFrequencyList() {
	cout << "Grocery Inventory" << endl;
	// uses frequency map to print the values of all item and how often they appear
	for (auto const& item : frequency) {
		cout << item.first << " " << item.second << endl;
	}
}
//function for menu option 3
void groceries::printHistogram() {
	cout << "Inventory Chart" << endl;
	// uses frequency map to print the values of all item and how often they appear
	for (auto const& item : frequency) {
		cout << item.first << " ";
		// uses the frequency of items to instead print '*' to create histogram
		for (int i = 0; i < item.second; i++) {
			cout << "*";
		}
		cout << endl;
	}
}
int main() {
	groceries groceries;
	groceries.readDataFile();
	groceries.displayMenu();
	
	return 0;
}
