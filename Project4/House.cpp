#include "House.h"

// Constructors:

House::House(string hID, string hName, int hSqf, int nBaths, int nBeds)
{
	houseID = hID;
	houseName = hName;
	houseSqf = hSqf;
	numBaths = nBaths;
	numBeds = nBeds;
}


House::~House()
{
	// Temp message:
	cout << "!!!!!!!Destructor started!!!!!" << endl;
}

// Accessor methods:

string House::GetHouseID()
{
	return houseID;
}

string House::GetHouseName()
{
	return houseName;
}

int House::GetHouseSqf()
{
	return houseSqf;
}

int House::GetNumBaths()
{
	return numBaths;

}

int House::GetNumBeds()
{
	return numBeds;
}



// Mutator methods:

void House::SetHouseID(string hID)
{
	houseID = hID;
}

void House::SetHouseName(string hName)
{
	houseName = hName;
}

void House::SetHouseSqf(int hSqf)
{
	houseSqf = hSqf;
}

void House::SetNumBaths(int nBaths)
{
	numBaths = nBaths;
}

void House::SetNumBeds(int nBeds)
{
	numBeds = nBeds;
}
