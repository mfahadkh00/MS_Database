#pragma once
#include"FadiBST.h"
#include"Person.h"
#include<fstream>
#include<iostream>
using namespace std;
//void databaseInterface(BST<int, Person*>* tree);
void databaseGen(BST<int, Person*>* tree);
void addRecord(BST<int, Person*>* tree);
void modifyRecord(BST<int, Person*>* tree, Person* obj);
void viewRecord(BST<int, Person*>* tree, Person* obj);
void loginControl(BST<int, Person*>* tree, Person* obj, int &inp);


void dbaseInterface(BST<int, Person*>* tree)
{

	cout << "\n\n======================================================================================================================="
		<< "\n\t\t\t\t\t\tMS-Database System\n========================================================================================================================\n";

	cout << "\n\t\t\tM Fahad Khawaja - 19L1244\t\t M Sameed Yusuf - 19L1182\n=======================================================================================================================\n\n";


	cout << "\t\t\t\t\t\tSelect an Option\n========================================================================================================================"
		<< "\n\t\t\t1.Modify Record\t\t2.View Record\t\t3.Add Record\n\t\t\t\t\t\tPress 0 to exit\n";
	int inp;
	cin >> inp;

	while (inp != 0)
	{
			if (inp == 3)
			{
				addRecord(tree);
			}
			else if (inp == 1 || inp == 2) //modify/view record
			{
				cout << "\t\t\t\Enter MS ID# to continue:\t";
				int id = 0;
				cin >> id;
				//if (tree->search(id) != NULL)
				if (tree->searchbool(id))
				{
					//if (inp == 2)
					//{
					Person* obj = tree->search(id);
					cout << "\t\t\t\t\t";
					obj->getName()->printN();
					cout << "\n";
					system("pause");
					loginControl(tree, obj, inp);
					//}
				}

			}
		system("cls");
		cout << "\n\n======================================================================================================================="
			<< "\n\t\t\t\t\t\tMS-Database System\n========================================================================================================================\n";

		cout << "\n\t\t\tM Fahad Khawaja - 19L1244\t\t M Sameed Yusuf - 19L1182\n=======================================================================================================================\n\n";


		cout << "\t\t\t\t\t\tSelect an Option\n========================================================================================================================"
			<< "\n\t\t\t1.Modify Record\t\t2.View Record\t\t3.Add Record\n\t\t\t\t\t\tPress 0 to exit\n";
		cin >> inp;
	}
}
void databaseGen(BST<int, Person*>* tree)
{
	ifstream fin;
	fin.open("MS_InputData.txt", ios::in);
	if (fin)
	{
		//iDNo, FName, MName, LName, DOB, Street, City, District, zip, gender
		char format[1000];
		fin.getline(format, 999);
		while (!fin.eof())
		{
			//iDNo, FName, MName, LName, DOB, Street, City, District, zip
			int id = 0;
			int d = 0;
			int m = 0;
			int y = 0;
			char fname[100], mname[100], lname[100], st[100], city[100], dis[100], zip[100];
			fin >> id;
			//cout << id << ',';

			fin.ignore();
			fin.getline(fname, 100, '|');
			//cout << fname << ',';
			//fin.ignore();
			fin.getline(mname, 100, '|');
			//cout << mname << ',';
			//fin.ignore();
			fin.getline(lname, 100, '|');
			//cout << lname << ',';

			//fin.ignore();
			fin >> d;
			//cout << d << '/';
			fin.ignore();
			fin >> m;
			//cout << m << '/';
			fin.ignore();
			fin >> y;
			//cout << y << ',';

			fin.ignore();
			fin.getline(st, 100, '|');
			//cout << st << ',';
			//fin.ignore();
			fin.getline(city, 100, '|');
			//cout << city << ',';
			//fin.ignore();
			fin.getline(dis, 100, '|');
			//cout << dis << ',';
			//fin.ignore();
			fin.getline(zip, 100, '|');
			//cout << zip << ',';
			//fin.ignore();
			//
			int gender = 0;
			//
			//fin.getline(gender, 5, '\n');
			fin >> gender;
			//cout << gender;
			fin.ignore();
			int age = 2021 - y;
			//string std(fname, someStr.GetLength());
			DOB* db = new DOB(d, m, y);
			Name* nm = new Name(fname, mname, lname);
			Address* ad = new Address(st, city, dis, zip);
			Person* obj = new Person(age, id, gender, db, nm, ad);
			tree->insert(id, obj);

			//Person* temp = tree->search(id);
			//temp->printDets();
			//cout << '\n';
		}
		fin.close();
		//system("pause");
	}
	else
		cout << "MS_InputData.txt could not be opened\n";

	fin.open("ParentData.txt", ios::in);
	if (fin)
	{
		//personID,fatherID,motherID
		char format[1000];
		fin.getline(format, 999);
		while (!fin.eof())
		{
			int pid = 0;
			int fid = 0;
			int mid = 0;
			fin >> pid;
			fin.ignore();
			//cout << pid << ',';
			fin >> fid;
			fin.ignore();
			//cout << fid << ',';
			//fin.ignore();
			fin >> mid;
			//cout << mid << '\n';

			//Node* child=tree->search(pid);

			Person* man = tree->search(pid);
			Person* father = tree->search(fid);
			Person* mother = tree->search(mid);
			//Person* temp = tree->searchperson(pid);
			/*man->printDets();
			cout<< 'son\t';
			father->printDets();
			cout<< '\t';
			mother->printDets();
			cout<< '\t';*/
			man->setFather(father);
			man->setMother(mother);
			mother->addChild(man);
			father->addChild(man);
			//man->printDets();
			//cout << " has parents ";
			//man->printParentsName();
			//cout << "\n";
			//

			//tree->setParents(pid, fid, mid);
		}
		fin.close();
	}
	else
		cout << "ParentData.txt could not be opened\n";

	fin.open("birthData.txt", ios::in);
	if (fin)
	{
		char format[100];
		fin.getline(format, 99);
		while (!fin.eof())
		{
			int id = 0;
			char city[30], prov[40], country[50];
			fin >> id;
			//cout << id << ',';
			fin.ignore();
			fin.getline(city, 29, ',');
			//cout << city << ',';
			fin.getline(prov, 39, ',');
			//cout << prov << ',';
			fin.getline(country, 38, '\n');
			//cout << country << '\n';


			Address* add = new Address("", city, prov, country);
			Person* temp = tree->search(id);
			temp->setBirthAdd(add);
			//temp->printbirthAdd();
		}
		fin.close();
	}
	else
		cout << "birthData.txt could not be opened\n";

	fin.open("familyData.txt");
	if (fin)
	{
		char format[100];
		fin.getline(format, 99);
		//cout << "FamilyData\n";
		while (!fin.eof())
		{
			//id,wifeID,childrenCount,childrenID.....
			int id = 0, wID = 0;
			fin >> id;
			//cout << id<<',';
			fin.ignore();
			fin >> wID;
			//cout << wID << ',';
			fin.ignore();
			Person* man = tree->search(id);
			Person* wife = tree->search(wID);
			man->setSpouse(wife);

			int cc = 0;
			fin >> cc;
			//cout << cc << ",";
			for (int i = 0, cID = 0; i < cc; ++i)
			{
				fin.ignore();
				fin >> cID;
				//cout << cID << ',';
				man->addChild(tree->search(cID));
			}
			//cout << man->getChildcount()<<'\n';
		}
	}
	else
		cout << "familyData.txt could not be opened\n";
}
void addRecord(BST<int, Person*>* tree)
{
	system("cls");
	cout << "\n\n======================================================================================================================="
		<< "\n\t\t\t\t\t\tMS-Database System\n========================================================================================================================\n";

	int id = 0;
	int d = 0;
	int m = 0;
	int y = 0;
	string fname, mname, lname, st, city, dis, zip;
	cout << "Enter MS ID#:\t";
	cin >> id;
	// << id << ',';
	cout << "Enter First Name:\t";
	cin >> fname;
	cout << "Enter Middle Name:\t";
	cin >> mname;
	cout << "Enter Last Name:\t";
	cin >> lname;

	cout << "Enter Birth Day(d):\t";
	cin >> d;
	cout << "Enter Birth Month(m):\t";
	cin >> m;
	cout << "Enter Birth Year(y):\t";
	cin >> y;
	// << y << ',';


	cout << "Enter Street Address:\t";
	cin >> st;
	cout << "Enter City:\t";
	cin >> city;
	cout << "Enter District:\t";
	cin >> dis;
	cout << "Enter ZipCode:\t";
	cin >> zip;
	char gen;
	cout << "Enter Gender (M/F):\t";
	cin >> gen;
	int gender = 0;
	if (gen == 'M')
		gender = 0;
	else
		gender = 1;
	int age = 2021 - y;
	DOB* db = new DOB(d, m, y);
	Name* nm = new Name(fname, mname, lname);
	Address* ad = new Address(st, city, dis, zip);
	Person* obj = new Person(age, id, gender, db, nm, ad);
	tree->insert(id, obj);

	cout << "====================================Record Inserted to Database, will be updated in next restart======================\n";
	tree->dataSave();
	system("pause");
}
void modifyRecord(BST<int, Person*>* tree, Person* obj)
{
	system("cls");
	cout << "\n\n======================================================================================================================="
		<< "\n\n\t\t\t\t\t\tMS-Database System\n========================================================================================================================\n";
	cout << "\n\t\t\t\tCurrently Viewing:\t" << obj->idNo << "  " << obj->name.getFName() << " " << obj->name.getLName() << "\n";
	cout << "\n========================================================================================================================\n";

	cout << "\t\t\t\t\tChoose the data field to modify\n\n\t1.Name\t\t2.Present Address\t\t3.Add Spouse\t\t4.Add Child\t\t5.Birth Address\n\n\t\t\t\t\t6.Parent Details\t\t7.Exit\n";
	int inp = 0;
	cin >> inp;

	if (inp == 1)//name
	{
		string fname, mname, lname, st, city, dis, zip;
		cout << "Enter First Name:\t";
		cin >> fname;
		cout << "Enter Middle Name:\t";
		cin >> mname;
		cout << "Enter Last Name:\t";
		cin >> lname;

		obj->getName()->setName(fname, mname, lname);
		cout << "Record Updated Successfully\n";
		tree->dataSave();
	}
	else if (inp == 2) //present address
	{
		string st, city, dis, zip;
		cout << "Enter Street Address:\t";
		cin >> st;
		cout << "Enter City:\t";
		cin >> city;
		cout << "Enter District:\t";
		cin >> dis;
		cout << "Enter ZipCode:\t";
		cin >> zip;

		obj->getpAD()->setAdd(st, city, dis, zip);
		cout << "Record Updated Successfully\n";
		tree->dataSave();
	}
	else if (inp == 3)
	{
		int sID = 0;
		Person* sp;
		cout << "Enter Spouse MS ID#\t";
		cin >> sID;
		if (tree->searchbool(sID))
		{
			sp = tree->search(sID);
			cout << "\n";
			obj->setSpouse(sp);
			sp->getName()->printN();
			cout << " set as Spouse Successfully\n";
			system("pause");
			tree->dataSave();
		}
		else
		{
			cout << "Invalid MS ID# Entered";
			system("pause");
		}
	}
	else if (inp == 4)
	{
		int cID = 0;
		Person* sp;
		cout << "Enter Child MS ID#\t";
		cin >> cID;
		if (tree->searchbool(cID))
		{
			sp = tree->search(cID);
			obj->addChild(sp);
			sp->getName()->printN();
			cout << " added as Child Successfully\n";
			system("pause");
			tree->dataSave();
		}
		else
		{
			cout << "Invalid MS ID# Entered\n";
			system("pause");
		}
	}
	else if (inp == 5)
	{
		string city, dis, zip;
		cout << "Enter Birth City:\t";
		cin >> city;
		cout << "Enter Birth District:\t";
		cin >> dis;
		cout << "Enter Birth Country:\t";
		cin >> zip;

		Address* add = new Address("", city, dis, zip);
		obj->setBirthAdd(add);

		cout << "Birth Address set successfully\n";
		tree->dataSave();

		system("pause");
	}
	else if (inp == 6)
	{
		int fid = 0, mid = 0;
		cout << "Enter the MS ID# of Father\n";
		cin >> fid;
		cout << "Enter the MS ID# of Mother\n";
		cin >> mid;
		if (tree->searchbool(fid) && tree->searchbool(mid))
		{
			Person* father = tree->search(fid);
			Person* mother = tree->search(mid);

			obj->setFather(father);
			obj->setMother(mother);
			mother->addChild(obj);
			father->addChild(obj);

			cout << "Parents set successfully and Child updated for each parent\n";
			tree->dataSave();
		}
		else
		{
			cout << "Invalid MS ID# entered\n";
		}
		system("pause");
	}
	else if (inp == 7)
	{
		system("pause");
	}
	else
	{
		cout << "Invalid Option\n";
		system("pause");
	}
}
void viewRecord(BST<int, Person*>* tree, Person* obj)
{
	system("cls");
	cout << "\n\n======================================================================================================================="
		<< "\n\n\t\t\t\t\t\tMS-Database System\n========================================================================================================================\n";
	cout << "\t\t\t\t\t\tChoose an option\n\n\t\t1.Birth Certificate\t\t2.Family Certificate\t\t3.Form-B\n";
	int inp = 0;
	cin >> inp;
	if (inp == 1)
	{
		obj->birthCertificate();
	}
	else if (inp == 2)
	{
		obj->familyCertificate();
	}
	else if (inp == 3)
	{
		obj->formB();
	}
}
void loginControl(BST<int, Person*>* tree, Person* obj, int &inp)
{
	while (inp != 0)
	{
		if (inp == 1)
		{
			modifyRecord(tree, obj);
		}
		else if (inp == 2)
		{
			viewRecord(tree, obj);
		}
		system("cls");
		cout << "\n\n======================================================================================================================="
			<< "\n\t\t\t\t\t\tMS-Database System\n========================================================================================================================\n";

		cout << "\n\t\t\tM Fahad Khawaja - 19L1244\t\t M Sameed Yusuf - 19L1182\n=======================================================================================================================\n\n";

		cout << "\t\t\t\tCurrently Viewing:\t" <<obj->idNo<<"  "<<obj->name.getFName()<<" "<<obj->name.getLName()<<"\n";
		cout << "===================================================================================================================\n";
		cout << "\t\t\t\t\t\tSelect an Option\n========================================================================================================================"
			<< "\n\t\t\t\t\t1.Modify Record\t\t2.View Record\n\t\t\t\t\t\t\tPress 0 to switch record\n";
		cin >> inp;
	}
	//cout << "User switched\n";
	//system("pause");
}

/*void databaseInterface(BST<int, Person*>* tree)
{

	cout << "\n\n======================================================================================================================="
		<< "\n\t\t\t\t\t\tMS-Database System\n========================================================================================================================\n";

	cout << "\n\t\t\tM Fahad Khawaja - 19L1244\t\t M Sameed Yusuf - 19L1182\n=======================================================================================================================\n\n";


	cout << "\t\t\t\t\t\tSelect an Option\n========================================================================================================================"
		<< "\n\t\t\t1.Add Record\t\t2.Modify Record\t\t3.View Record\n\t\t\t\t\t\tPress 0 to exit\n";
	int inp;
	cin >> inp;

	while (inp != 0)
	{
		if (inp == 1)
		{
			addRecord(tree);
		}
		else if (inp == 2 || inp == 3) //modify/view record
		{
			cout << "\t\t\t\Enter MS ID# to continue:\t";
			int id = 0;
			cin >> id;
			//if (tree->search(id) != NULL)
			if (tree->searchbool(id))
			{
				if (inp == 2)
				{
					Person* obj = tree->search(id);
					cout << "\t\t\t\t\t";
					obj->getName()->printN();
					cout << "\n";
					system("pause");
					modifyRecord(tree, obj);
					tree->dataSave();
				}
				else
				{
					Person* obj = tree->search(id);
					cout << "\t\t\t\t\t";
					obj->getName()->printN();
					cout << "\n";
					system("pause");
					viewRecord(tree, obj);
				}
			}
			else
			{
				cout << "\t\t\t\t\tInvalid MS ID# Entered\n";
				system("pause");
			}
		}
		system("cls");
		cout << "\n\n======================================================================================================================="
			<< "\n\t\t\t\t\t\tMS-Database System\n========================================================================================================================\n";

		cout << "\n\t\t\tM Fahad Khawaja - 19L1244\t\t M Sameed Yusuf - 19L1182\n=======================================================================================================================\n\n";


		cout << "\t\t\t\t\t\tSelect an Option\n========================================================================================================================"
			<< "\n\t\t\t1.Add Record\t\t2.Modify Record\t\t3.View Record\n\t\t\t\t\t\tPress 0 to exit\n";
		cin >> inp;
	}
}*/
