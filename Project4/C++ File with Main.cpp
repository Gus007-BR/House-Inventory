#include <vector>
#include "House.h"



int GetOptionSelection()
{
	int selection;
	do {
		cout << "Enter a choice:" << endl;
		cout << "  1) Print houses." << endl;
		cout << "  2) Add a house." << endl;
		cout << "  3) Edit a house." << endl;
		cout << "  4) Delete a house." << endl;
		cout << "  5) Quit." << endl;
		cin >> selection;
	} while (selection < 1 || selection > 5);
	return selection;
}


// Function to print House objects in vector:

void PrintHouses(vector<House*>& vectorList)
{
	int selection;
	int i;

	// Check if vector is empty before proceeding:
	if (vectorList.empty())
	{
		cout << "The house list is empty." << endl;
		cout << endl;
		return;
	}

	// Main print menu:
	do
	{
		cout << endl;
		cout << "Enter an option:" << endl;
		cout << " 1) Print all houses" << endl;
		cout << " 2) Print a specific house" << endl;
		cout << endl;
		cin >> selection;
		cout << endl;
	} while (selection < 1 || selection > 2);

	if (selection == 1)
	{
		cout << endl;
		cout << "***********************" << endl;
		for (i = 0; i < vectorList.size(); ++i)
		{
			cout << endl;
			cout << "House ID: " << vectorList.at(i)->GetHouseID() << endl;
			cout << "House name: " << vectorList.at(i)->GetHouseName() << endl;
			cout << "House SQF: " << vectorList.at(i)->GetHouseSqf() << endl;
			cout << "Baths: " << vectorList.at(i)->GetNumBaths() << endl;
			cout << "Beds: " << vectorList.at(i)->GetNumBeds() << endl;
			cout << endl;
		}
		cout << endl;
		cout << "***********************" << endl;
		cout << endl;
	}

	if (selection == 2)
	{
		i = 0;
		cout << endl;
		cout << "Select a house:" << endl;
		do
		{
			for (i = 0; i < vectorList.size(); ++i)
			{
				cout << " " << i + 1 << ") " << vectorList.at(i)->GetHouseName() << endl;
			}
			cin >> selection;
		} while (selection < 1 || selection > vectorList.size());
		
		cout << endl;
		cout << endl;
		cout << "House ID: " << vectorList.at(selection - 1)->GetHouseID() << endl;
		cout << "House name: " << vectorList.at(selection - 1)->GetHouseID() << endl;
		cout << "House SQF: " << vectorList.at(selection - 1)->GetHouseSqf() << endl;
		cout << "Baths: " << vectorList.at(selection - 1)->GetNumBaths() << endl;
		cout << "Beds: " << vectorList.at(selection - 1)->GetNumBeds() << endl;
		cout << endl;
		cout << "***********************" << endl;
		cout << endl;
	}
}

// Function to add a new house.
void AddHouse(vector<House*>& vectorList)
{
	string hID;
	string hName;
	int sQF;
	int nBaths;
	int nBeds;
	House* newHouse = nullptr;
	
	cout << endl;
	cout << "Enter the house ID (numeric):" << endl;
	cin >> hID;
	cout << "Enter the house name:" << endl;
	cin.ignore();
	getline(cin, hName);
	cout << "Enter the house SQF:" << endl;
	cin >> sQF;
	cout << "Enter the number of bathrooms:" << endl;
	cin >> nBaths;
	cout << "Enter the number of bedrooms:" << endl;
	cin >> nBeds;

	newHouse = new House(hID, hName, sQF, nBaths, nBeds);
	vectorList.push_back(newHouse);
	return;

}

// Function to edit an existing house:
void EditHouse(vector<House*>& vectorList)
{
	int i;
	int houseSelection;
	int editSelection;
	string newStringValue;
	int newIntValue;
	string setMethodName;
	string editMore;

	// Prompt user for which house to edit:
	cout << endl;
	cout << "Select a house to edit:" << endl;
	do
	{
		for (i = 0; i < vectorList.size(); ++i)
		{
			cout << " " << i + 1 << ") " << vectorList.at(i)->GetHouseName() << endl;
		}
		cin >> houseSelection;
	} while (houseSelection < 1 || houseSelection > vectorList.size());
	cout << endl;

	
	// This while loop allows to user to edit multiple fields of the selected house:
	editMore = "y";
	while (editMore == "y")
	{
		// Prompt user for which field should be edited:
		do
		{
			cout << "Select an option to edit:" << endl;
			cout << " 1) House ID: " << vectorList.at(houseSelection - 1)->GetHouseID() << endl;
			cout << " 2) House name: " << vectorList.at(houseSelection - 1)->GetHouseName() << endl;
			cout << " 3) House SQF: " << vectorList.at(houseSelection - 1)->GetHouseSqf() << endl;
			cout << " 4) Number of bathrooms: " << vectorList.at(houseSelection - 1)->GetNumBaths() << endl;
			cout << " 5) Number of bedrooms: " << vectorList.at(houseSelection - 1)->GetNumBeds() << endl;
			cout << endl;
			cin >> editSelection;
			cout << endl;
		} while (editSelection < 1 || editSelection > 5);

		cout << "Enter a new value:" << endl;

		// Determine if selected option is a string or an int, and store the new value:
		if (editSelection == 1 || editSelection == 2)
		{
			cin >> newStringValue;
		}
		else
		{
			cin >> newIntValue;
		}

		// Call the appropriate mutator method based on the hosue and edit selection:
		switch (editSelection)
		{
		case 1:
			vectorList.at(houseSelection - 1)->SetHouseID(newStringValue);
			break;
		case 2:
			vectorList.at(houseSelection - 1)->SetHouseName(newStringValue);
			break;
		case 3:
			vectorList.at(houseSelection - 1)->SetHouseSqf(newIntValue);
			break;
		case 4:
			vectorList.at(houseSelection - 1)->SetNumBaths(newIntValue);
			break;
		case 5:
			vectorList.at(houseSelection - 1)->SetNumBeds(newIntValue);
			break;
		}

		// Ask if they would like to edit another field of the selected house:
		cout << endl;
		cout << "Would you like to edit another field of this house? ";
		cout << "Enter 'y' for yes, or any other letter to exit." << endl;
		cin >> editMore;
		cout << endl;
	}
	
	return;

}


// Funtion to delete an existing house:
void DeleteHouse(vector<House*>& vectorList)
{
	int i;
	int houseSelection;
	string confirmDelete;
	
	// Prompt user for which house to edit:
	cout << endl;
	cout << "Select a house to delete:" << endl;
	do
	{
		for (i = 0; i < vectorList.size(); ++i)
		{
			cout << " " << i + 1 << ") " << vectorList.at(i)->GetHouseName() << endl;
		}
		cout << " " << vectorList.size() + 1 << ") to CANCEL" << endl;
		cout << endl;
		cin >> houseSelection;
	} while (houseSelection < 1 || houseSelection > vectorList.size() + 1);

	if (houseSelection == vectorList.size() + 1)
	{
		cout << "House deletion canceled." << endl;
		cout << endl;
		return;
	}
	else // confirm delete before proceeding:
	{
		cout << "Please confirm house deletion. Type 'yes' to confirm. Type any other key to cancel." << endl;
		cin >> confirmDelete;
		cout << endl;

		if (confirmDelete == "yes")
		{
			delete vectorList.at(houseSelection - 1);
			vectorList.erase(vectorList.begin() + houseSelection - 1);
			cout << "House deleted." << endl;
			cout << endl;
		}
		else
		{
			return;
		}
		
	}

	return;
}


int main()
{
	int optionSelection;
	vector<House*> houseListVector(0);

	// Keep prompting for an option until option 5 is selected:
	do {
		optionSelection = GetOptionSelection();

		switch (optionSelection) 
		{
		case 1: //Print houses
			PrintHouses(houseListVector);
			break;
		case 2:
			AddHouse(houseListVector);
			break;
		case 3:
			EditHouse(houseListVector);
			break;
		case 4:
			DeleteHouse(houseListVector);
			break;
		case 5:
			cout << "Goodbye" << endl;
			break;
		}
	} while (optionSelection != 5);
	
	return 0;
}