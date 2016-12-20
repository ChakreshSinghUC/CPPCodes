//setSTL.cc
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

bool IsEven(int values)
{
	return (values%2 == 0);
	//	return true;
	//else 
		//return false;
}	

int main(int argc, char const *argv[])
{
	set<int> myset; //unordered container with no duplicity 
	//Insert into the set...
	myset.insert(140);
	myset.insert(2);
	myset.insert(10);
	//Check if 140 is in the set or not...
	if (myset.count(140))
		cout<<"Yes... "<<endl;
	else 
		cout<<"No... "<<endl;

	myset.erase(140);
	
	//Check if 140 is in the set or not...
	if (myset.count(140))
		cout<<"Yes... "<<endl;
	else 
		cout<<"No... "<<endl;

	myset.insert(140);
	myset.insert(2);
	myset.insert(10);
	myset.insert(40);
	myset	.insert(12);
	myset.insert(110);
	
	cout<<"Size of the set: "<<myset.size()<<endl;
	//Print the set using an iterator
	for (set<int>::iterator itr = myset.begin(); itr != myset.end(); ++itr)
		cout<<*itr<<"\t";

	cout<<"\n 140 comes.. : "<<count(myset.begin(), myset.end(), 140)<< " number of times";
	cout<<"\n Even comes.. : "<<count_if(myset.begin(), myset.end(), IsEven)<< " number of times";
	cout<<endl;


	return 0;
}