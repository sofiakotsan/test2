#include <iostream>
#include <fstream>
#include <list>
#include <map>
#include <string>
#include <stack>
#include <vector>

using namespace std;

class Building abstract
{
protected:
	//bool compleated;
public:
	//Building() : compleated(false) {}
	virtual bool isCompleated() = 0;
	virtual void Show() = 0;
};

class BuildingWithBasement : public Building
{
protected:
	bool basementCompleated;
public:
	BuildingWithBasement() : basementCompleated(false) {}
	bool basementIsCompleated() { return basementCompleated; }
	void buildBasement() { basementCompleated = true; }
	virtual void Show() override
	{
		cout << "Basement " << basementCompleated << endl;
	}
	virtual bool isCompleated() override
	{
		return basementCompleated;
	}
};

class BuildingWithWalls : public BuildingWithBasement
{
protected:
	bool wallsCompleated;
public:
	BuildingWithWalls() : BuildingWithBasement(), wallsCompleated(false) {}
	bool wallsIsCompleated() { return wallsCompleated; }
	void buildWalls() 
	{ 
		buildBasement();
		wallsCompleated = true;
	}
	virtual void Show() override
	{
		BuildingWithBasement::Show();
		cout << "Walls " << wallsCompleated << endl;
	}
	virtual bool isCompleated() override
	{
		return basementCompleated && wallsCompleated;
	}
};

class BuildingWithRoof : public BuildingWithWalls
{
protected:
	bool roofCompleated;
public:
	BuildingWithRoof() : BuildingWithWalls(), roofCompleated(false) {}
	bool roofIsCompleated() { return roofCompleated; }
	void buildRoof() 
	{ 
		buildWalls();
		roofCompleated = true;
	}


	virtual void Show() override
	{
		BuildingWithWalls::Show();
		cout << "Roof " << roofCompleated << endl;
	}
	virtual bool isCompleated() override
	{
		return basementCompleated && wallsCompleated && roofCompleated;
	}
};

int main()
{
	BuildingWithBasement bb;
	bb.Show();
	bb.buildBasement();
	bb.Show();

	cout << endl;

	BuildingWithWalls bw;
	bw.Show();
	bw.buildWalls();
	bw.Show();

	cout << endl;

	BuildingWithRoof br;
	br.Show();
	br.buildRoof();
	br.Show();


	return 0;
}