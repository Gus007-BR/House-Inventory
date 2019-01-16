#pragma once
#include <iostream>
#include <string>
using namespace std;

class House
{
public:

	// Constructors:
	House(
		string hID = "no ID",
		string hName = "no name",
		int hSqf = 0,
		int nBaths = 0,
		int nBeds = 0);
	~House();

	// Accessor methods:
	string GetHouseID();
	string GetHouseName();
	int GetHouseSqf();
	int GetNumBaths();
	int GetNumBeds();
	

	// Mutator methods:
	void SetHouseID(string hID);
	void SetHouseName(string hName);
	void SetHouseSqf(int hSqf);
	void SetNumBaths(int nBaths);
	void SetNumBeds(int nBeds);

private:
	string houseID;
	string houseName;
	int houseSqf;
	int numBaths;
	int numBeds;
};

