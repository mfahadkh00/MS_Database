#pragma once
#include<iostream>
#include"FadiBST.h"
using namespace std;
class DOB
{
	int d;
	int m;
	int y;
	friend class Person;

public:
	DOB()
	{
		d = m = y = 0;
	}
	DOB(int a, int b, int c)
	{
		d = a;
		m = b;
		y = c;
	}
	void setDOB(int a, int b, int c)
	{
		d = a;
		m = b;
		y = c;
	}
	DOB operator=(DOB& const obj)
	{
		d = obj.d;
		m = obj.m;
		y = obj.y;
		return *this;
	}
	int getD()
	{
		return d;
	}
	int getM()
	{
		return m;
	}int getY()
	{
		return y;
	}
	//overload cout operator
};
class Name
{
	string fname;
	string mname;
	string lname;
	friend class Person;
public:
	Name()
	{
		fname = mname = lname = "";
	}
	Name(string x, string y, string z)
	{
		fname = x;
		mname = y;
		lname = z;
	}
	void printN()
	{
		cout << fname << ' '<<mname <<' '<< lname;
	}
	void setFName(string x)
	{
		fname = x;
	}
	void setMName(string y)
	{
		mname = y;
	}
	void setLName(string z)
	{
		lname = z;
	}

	void setName(string x, string y, string z)
	{
		fname = x;
		mname = y;
		lname = z;
	}
	void operator =(Name& const n)
	{
		setName(n.fname, n.mname, n.lname);
	}

	string getFName()
	{
		return fname;
	}
	string getMName()
	{
		return mname;
	}
	string getLName()
	{
		return lname;
	}
};
class Address
{
	string street;
	string city;
	string district;
	string zipCode; //used as country in birthaddress
	friend class Person;
public:
	Address()
	{
		street = city = district = zipCode = "";
	}
	Address(string x, string y, string z, string a)
	{
		street = x;
		city = y;
		district = z;
		zipCode = a;
	}
	void setAdd(string x, string y, string z, string a)
	{
		street = x;
		city = y;
		district = z;
		zipCode = a;
	}
	void printBirthAddress()
	{
		cout <<city << ',' << district << "," << zipCode << '\n';
	}
	void printPAddress()
	{
		cout << street<<','<<city << ',' << district << "," << zipCode << '\n';
	}
	void operator =(const Address& obj)
	{
		setAdd(obj.street, obj.city, obj.district, obj.zipCode);
	}

	string getSt()
	{
		return street;
	}
	string getCity()
	{
		return city;
	}
	string getDis()
	{
		return district;
	}
	string getzip()
	{
		return zipCode;
	}
};

class Person
{
public:

	int age;
	int idNo; //generated with timeseed in rand function --> 5 digit 
	char gender;
	DOB dob;
	Name name;
	Address presentAddress;
	Address birthAddress;

	Person* father;
	Person* mother;
	Person* spouse;
	Person** children; //consider adding
	bool status; //deceased/alive
	int childCount;

	bool parentInitalized;
	bool dbBool;
	bool spouseBool;

	

	Person()
	{
		father = spouse = mother = NULL;
		idNo = NULL;
		status = 1;
		children = new Person * [10];
		childCount = 0;
		//age =
	}
	Person(int a, int id, int gen, DOB* x, Name* n, Address* ad)// Person* f, Person* m)
	{
		age = a;
		idNo = id;
		dob = *x;
		name = *n;
		status = 1;
		presentAddress = *ad;
		children = new Person * [10];
		childCount = 0;
		father = mother = spouse = NULL;
		if (gen)
			gender = 'M';
		else
			gender = 'F';
		parentInitalized = false;
		dbBool = false;
		spouseBool = false;
	}
	int getID()
	{
		return idNo;
	}
	int getGender()
	{
		if (gender == 'M')
			return 1;
		else
			return 0;
	}
	void setFather(Person* f)
	{
		father = f;
		parentInitalized = true;
	}
	void setMother(Person* m)
	{
		mother = m;
	}
	void setSpouse(Person* w)
	{
		spouse = w;
		spouseBool = true;
	}
	void addChild(Person* c)
	{
		children[childCount++] = c;
	}
	void setBirthAdd(Address* ad)
	{
		birthAddress = *ad;
		dbBool = true;
	}
	void printDets()
	{
		cout << idNo << '\t';
		name.printN();
		//cout << gender << "\n";
		//name.fname;//name.mname,name.lname
	}
	void printParentsName()
	{
		cout << father->name.fname << '\t' << mother->name.fname;

	}
	int getChildcount()
	{
		return childCount;
	}
	void setPerson(int a, int id, DOB x, Name n,Address ad)// Person* f, Person* m)
	{
		age = a;
		idNo = id;
		dob = x;
		name = n;
		this->presentAddress = ad;
		//father = f;
		//mother = m;
	}
	void operator=( Person& obj)
	{
		setPerson(obj.age, obj.idNo, obj.dob, obj.name, obj.presentAddress);//  obj.father, obj.mother);
	}
	Name* getName()
	{
		return &name;
	}
	Address* getpAD()
	{
		return &presentAddress;
	}
	Address* getbAD()
	{
		return &birthAddress;
	}
	Person** getChildren()
	{
		return children;
	}
	void birthCertificate()
	{
		if (dbBool && parentInitalized)
		{
			system("cls");
			cout << "\t\t\t\tBirth Certificate\n-----------------------------------------------------------------------------------------------------------\n";
			cout << "Name:\t";
			name.printN();
			cout << "\nID Card#:\t" << idNo;
			cout << "\nGender:\t" << gender;
			cout << "\n\nFather Name:\t";
			father->name.printN();
			cout << "\nFather ID Card#:\t" << father->idNo;
			cout << "\n\nMother Name:\t";
			mother->name.printN();
			cout << "\nMother ID Card#:\t" << mother->idNo;
			cout << "\n-----------------------------------------------------------------------------------------------------------\n";
			cout << "\n\nDate of Birth:\t" << dob.d << '/' << dob.m << '/' << dob.y << "\n";
			cout << "Place of Birth:\t";
			birthAddress.printBirthAddress();
			cout << "\n-----------------------------------------------------------------------------------------------------------\n";
			
		}
		else
			cout << "Birth Data not initialized\n";
		system("pause");
	}
	void familyCertificate()
	{
		if (spouseBool&&parentInitalized)
		{
			system("cls");
			cout << "\t\t\t\t\t\tFamily Certificate\n---------------------------------------------------------------------------------------------------------------\n";
			cout << "Name:\t";
			name.printN();
			cout << "\nID Card#:\t" << idNo;
			cout << "\nGender:\t" << gender;
			cout << "\nPresent Address:\t";
			presentAddress.printPAddress();
			cout << "\n\nFather Name:\t";
			father->name.printN();
			cout << "\nFather ID Card#:\t" << father->idNo;
			cout << "\n\nMother Name:\t";
			mother->name.printN();
			cout << "\nMother ID Card#:\t" << mother->idNo;
			cout << "\n\n----------------------------------------------------------------------------------------------------------------\n";
			cout << "\nSpouse Name:\t";
			spouse->name.printN();
			cout << "\nSpuse ID Card#:\t" << spouse->idNo << "\nGender:\t" << gender;

			cout << "\n\n----------------------------------------------------------------------------------------------------------------\n\n";

			int i = 0;
			if (childCount > 0)
			{
				for (int i = 0; i < childCount; ++i)
				{
					cout << "\nChild Name:\t";
					children[i]->name.printN();
					cout << "\nChild ID Card#:\t" << children[i]->idNo;
					cout << "\nGender:\t" << children[i]->gender;
				}
			}
			cout << "\n\n----------------------------------------------------------------------------------------------------------------\n\n";
		}
		else
			cout << "Spouse/Child Data not initialized\n";
		system("pause");

	}
	void formB()
	{
		if (parentInitalized)
		{
			system("cls");
			cout << "\t\t\t\t\t\tForm-B\n---------------------------------------------------------------------------------------------------------------\n";
			cout << "Name:  ";
			name.printN();
			cout << "\nID Card#:  " << idNo;
			cout << "\nGender:  " << gender;
			cout << "\nPresent Address:  ";
			presentAddress.printPAddress();

			cout << "\n\nFather Name:  ";
			father->name.printN();
			cout << "\nFather ID Card#:  " << father->idNo;
			cout << "\n\nMother Name:  ";
			mother->name.printN();
			cout << "\nMother ID Card#:  " << mother->idNo;
			cout << "\n\n----------------------------------------------------------------------------------------------------------------\n";
			int i = 0;
			if (father->childCount > 0)
			{
				for (int i = 0; i < father->childCount; ++i)
				{
					cout << "\n\nSibling Name:  ";
					father->children[i]->name.printN();
					cout << "\nSibling ID Card#:  " << father->children[i]->idNo;
					cout << "\nSibling Gender:  " << father->children[i]->gender;
				}
			}
			cout << "\n\n----------------------------------------------------------------------------------------------------------------\n\n";
		}
		else
			cout << "Family Data not initialized\n";
		system("pause");

	}
	//void printbirthAdd()
	//{
	//	birthAddress.printAddress();
	//}

	~Person()
	{
		delete[]children;
		children = NULL;
	}
};

//