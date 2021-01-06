#pragma once
#include<iostream>
#include<fstream>
using namespace std;
template<typename k, typename v>
class BST
{
private:
	struct TNode
	{
		k key;
		v value;
		TNode* leftChild;
		TNode* rightChild;

		TNode()
		{
			leftChild = NULL;
			rightChild = NULL;
		}
		TNode(k keyy, v val)
		{
			key = keyy;
			value = val;
			leftChild = NULL;
			rightChild = NULL;
		}
	};
	TNode* root;
public:
	BST()//default constructor
	{
		root = NULL;
	}
	/*void copyHelper(TNode* temp, TNode* X)
	{
		if (X)
		{
			insert(X->key, X->value);
			copyHelper(temp->leftChild, X->leftChild);
			copyHelper(temp->rightChild, X->rightChild);
		}
	}

	BST(BST& tree)
	{
		TNode* rootB = tree.root;
		copyHelper(root, rootB);
	}*/
	TNode* inserthelper(k const _key, v const _value, TNode*& node)
	{
		if (node == NULL)
		{
			node = new TNode(_key, _value);
			//cout << "key " << node->key << " value " << node->value << " inserted\n";
		}
		else if (_key < node->key)
		{
			inserthelper(_key, _value, node->leftChild);
		}
		else if (_key > node->key)
		{
			inserthelper(_key, _value, node->rightChild);
		}
		else if (_key == node->key)
		{
			node->value = _value;
		}
		return node;

	}
	void insert(k const _key, v const _value)
	{
		if (root == NULL)
		{
			TNode* node = new TNode(_key, _value);
			root = node;
		}
		else
			inserthelper(_key, _value, root);
	}

	TNode* searcHelper(k const _key, TNode*& node)
	{
		if (node == NULL)
		{
			return NULL;
		}
		else if (_key == node->key)
			return node;
		else if (_key < node->key)
		{
			searcHelper(_key, node->leftChild);
		}
		else if (_key > node->key)
		{
			searcHelper(_key, node->rightChild);
		}
		//return NULL;
	}
	v search(k const _key)
	{
		TNode* temp = searcHelper(_key, root);
		return temp->value;
	}

	bool searchboolHelper(k const _key, TNode*& node)
	{
		if (node) {
			if (node->key > _key)
				searchboolHelper(_key,node->leftChild);
			else if (node->key < _key)
				searchboolHelper(_key,node->rightChild);
			else
				return true;
		}
		else
			return false;
	}
	
	bool searchbool(k const _key)
	{
		return searchboolHelper(_key, root);
		//return temp->value;
	}
	TNode* inorderPrintHelper(TNode* node) const
	{
		if (node == NULL)
			return NULL;
		inorderPrintHelper(node->leftChild);
		cout << node->key << "\t";
		inorderPrintHelper(node->rightChild);
	}
	void inorderPrintKeys() const
	{
		inorderPrintHelper(root);
	}

	void lengthHelper(TNode* node, int& count) const
	{
		if (node != NULL)
		{
			lengthHelper(node->leftChild, count);
			lengthHelper(node->rightChild, count);
			count++;
		}
	}
	int length() const
	{
		int nodeCount = 0;
		if (root != NULL)
		{
			//nodeCount++;
			lengthHelper(this->root, nodeCount);
		}
		return nodeCount;
	}

	TNode* minHelper(TNode* node)
	{
		if (node == NULL)
			return NULL;
		else if (node->leftChild == NULL)
			return node;
		else
			return minHelper(node->leftChild);
	}
	TNode* findMin()
	{
		TNode* temp = minHelper(root);
		return temp;
	}
	TNode* getRoot()
	{
		return root;
	}

	TNode* deleteKeyHelper(k const _key, TNode* node)
	{
		TNode* temp;
		if (node == NULL)
			return NULL;
		else if (_key < node->key)
			node->leftChild = deleteKeyHelper(_key, node->leftChild);
		else if (_key > node->key)
			node->rightChild = deleteKeyHelper(_key, node->rightChild);
		else if (node->leftChild && node->rightChild)
		{
			temp = minHelper(node->rightChild);
			node->key = temp->key;
			node->rightChild = deleteKeyHelper(node->key, node->rightChild);
		}
		else
		{
			temp = node;
			if (node->leftChild == NULL)
				node = node->rightChild;
			else if (node->rightChild == NULL)
				node = node->leftChild;
			delete temp;
		}
	}
	void deleteKey(k _key)
	{
		if (root != NULL)
			deleteKeyHelper(_key, root);
	}

	void destructorRec(TNode* node)
	{
		if (node != NULL)
		{
			destructorRec(node->leftChild);
			destructorRec(node->rightChild);
			delete node;
		}
	}


	TNode* dataSaveHelper(TNode* x)
	{
		if (x == NULL)
			return NULL;
		
		dataSaveHelper(x->leftChild);
			//cout << root->data << " ";
			//iDNo, FName, MName, LName, DOB, Street, City, District, zip, gender
			ofstream fout;
			fout.open("MS_InputData.txt", ios::app); //msdata
			if (fout)
			{
				fout << x->value->getID() << '|' << x->value->name.getFName() << '|' << x->value->name.getMName() << '|' <<
					x->value->name.getLName() << '|' << x->value->dob.getD() << '/' << x->value->dob.getM() << '/'
					<< x->value->dob.getY() << '|' << x->value->presentAddress.getSt() << '|' << x->value->presentAddress.getCity() << '|'
					<< x->value->presentAddress.getDis() << '|' << x->value->presentAddress.getzip() << '|'
					<< x->value->getGender() << '\n';
				/*cout << x->value->getID() << '|' << x->value->name.getFName() << '|' << x->value->name.getMName() << '|' <<
					x->value->name.getLName() << '|' << x->value->dob.getD() << '/' << x->value->dob.getM() << '/'
					<< x->value->dob.getY() << '|' << x->value->presentAddress.getSt() << '|' << x->value->presentAddress.getCity() << '|'
					<< x->value->presentAddress.getDis() << '|' << x->value->presentAddress.getzip() << '|'
					<< x->value->getGender() << '\n';
			*/}
			else
				cout << "MS_InputData.txt could not be opened\n";
			fout.close();

			if (x->value->parentInitalized)
			{
				fout.open("ParentData.txt", ios::app); //parentdata
				if (fout)
				{
					//personID,fatherID,motherID
					fout << x->value->getID() << "," << x->value->father->getID() << ',' << x->value->mother->getID() << '\n';
					//cout << x->value->getID() << "," << x->value->father->getID() << ',' << x->value->mother->getID() << '\n';
					fout.close();
				}
				else
					cout << "ParentData.txt could not be opened\n";
			}
			if (x->value->dbBool)
			{
				fout.open("birthData.txt", ios::app); //birthdata
				if (fout)
				{
					fout << x->value->getID() << "," << x->value->birthAddress.getCity() << ','
						<< x->value->birthAddress.getDis() << ',' << x->value->birthAddress.getzip() << '\n';
					fout.close();
				}
				else
					cout << "birthData.txt could not be opened\n";
			}
			if (x->value->spouseBool)
			{
				fout.open("familyData.txt", ios::app); //familydata
				if (fout)
				{
					fout << x->value->getID() << "," << x->value->spouse->getID() << ','<<x->value->getChildcount();
					for (int i = 0; i < x->value->getChildcount(); ++i)
					{
						fout << ',' << x->value->children[i]->getID();
					}
					fout << '\n';

					fout.close();
				}
				else
					cout << "familyData.txt could not be opened\n";
			}

			dataSaveHelper(x->rightChild);
		
	}

	void dataSave()
	{
		if (root != nullptr)
		{
			ofstream fout;
			fout.open("MS_InputData.txt", ios::out); //msdata
			if (fout)
			{
				fout << "iDNo, FName, MName, LName, DOB, Street, City, District, zip, gender\n";
			}
			else
				cout << "MS_InputData.txt could not be opened\n";
			fout.close();
			fout.open("ParentData.txt", ios::out);//parents
			if (fout)
			{
				fout << "personID,fatherID,motherID\n";
			}
			else
				cout << "ParentData.txt could not be opened\n";
			fout.close();

			fout.open("birthData.txt", ios::out);//birth
			if (fout)
			{
				fout << "idNo,birthCity,birthPronvince,birthCountry\n";
			}
			else
				cout << "birthData.txt could not be opened\n";
			fout.close();

			fout.open("familyData.txt", ios::out);//birth
			if (fout)
			{
				fout << "id,wifeID,childrenCount,childrenID.....\n";
			}
			else
				cout << "familyData.txt could not be opened\n";
			fout.close();

			dataSaveHelper(root);


		}
	}

#define COUNT 10
	void print2DUtil(TNode* node, int space)
	{
		// Base case  
		if (node == NULL)
			return;

		// Increase distance between levels  
		space += COUNT;

		// Process right child first  
		print2DUtil(node->rightChild, space);

		// Print current node after space  
		// count  
		cout << endl;
		for (int i = COUNT; i < space; i++)
			cout << " ";
		//cout << node->data << "\n";
		cout << node->key << "\n";

		// Process left child  
		print2DUtil(node->leftChild, space);
	}

	// Wrapper over print2DUtil()  
	void print2D()
	{
		// Pass initial space count as 0  
		print2DUtil(root, 0);
	}

	~BST()
	{
		destructorRec(root);
	}
};
