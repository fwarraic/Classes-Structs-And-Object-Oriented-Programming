// a2.cpp

/////////////////////////////////////////////////////////////////////////
//
// Student Info
// ------------
//
// Name : <Fazal Dad Warraich>
// St.# : <301319108>
// Email: <fwarraic@sfu.ca>
//
//
// Statement of Originality
// ------------------------
//
// All the code and comments below are my own original work. For any non-
// original work, I have provided citations in the comments with enough
// detail so that someone can see the exact source and extent of the
// borrowed work.
//
// In addition, I have not shared this work with anyone else, and I have
// not seen solutions from other students, tutors, websites, books,
// etc.
//
/////////////////////////////////////////////////////////////////////////

#include "cmpt_error.h"    // These are the only permitted includes!
#include <iostream>        //
#include <string>          // Don't include anything else.
#include <algorithm>
#include <cassert>

using namespace std;

//
// ... write your code here here ...
//

class str_vec
{
private:
	string* arr;    // pointer to the underlying array
    int sz;       // # of elements from user's perspective
    int cap;   // length of underlying array

public:


	// Question 1.
	// Default Constructor.
	str_vec()
	: arr(new string[5]), sz(0), cap(10)
	{
	}


	// Question 2.
	// Constructor.
	str_vec(int n, string s)
	: arr(new string[n + 5]), sz(n), cap(n + 5)
	{
		if (n < 0)
		{
			cmpt::error("Sorry, size cannot be less than 0.");
		}
		
		for (int i = 0; i < sz; i++)
		{
			arr[i] = s;
		}

	}

	// Question 3.
	// Copy Constructor.
	str_vec(const str_vec& other)
	: arr(new string[other.sz]), sz(other.sz), cap(other.cap) 
	{
		for (int i=0; i<other.sz; i++) {
			arr[i] = other.arr[i];
		}
	}

	// Question 4.
	// Destructor.
	~str_vec()
	{
		delete[] arr;
	}

	// Question 5.
	// getters.

	// returns size of str_vec.
	int size() const
	{
		return sz;
	}

	// returns capacity of str_vec.
	int capacity() const
	{
		return cap;
	}

	// returns percentage of the underlying array in use.
	double pct_used() const
	{
		return (static_cast<double>(sz) / cap);
	}

	// returns arr.
	string* get_arr() const
	{
		return arr;
	}
	

	// Question 6.
	// non-mutating methods.

	// returns a string representation of this str_vec.
	// same as assignment 1 with a few modifications.
	// convert arr's underlying array to a string.
	string to_str() const
	{
		string nextString;
		nextString += "{";
	
		// evaluates each input from the array.
		for (int index = 0; index < sz; index++)
		{
			// checks for last comma to be added or not.
			if (index != sz - 1)
			{
				nextString += "\"" + arr[index] + "\"" + ", ";
			}
			else
			{
				nextString += "\"" + arr[index] + "\"";
			}// if-else
		}// for

		nextString += "}";

		// checks for no string(only brackets) and for one string(no comma).
		if (sz == 0)
		{
			return "{}";
		}
		else if (sz == 1)
		{
			return nextString;
		}// if-else
	
		// If above condition unsatisfied return the strings in the required format
		// for more than one string.
		return nextString;
	}

	// prints to_str(arr) to cout
	void print() const
	{
		cout << to_str();
	}

	// same as print, but also prints '\n' at the end
	void println() const
	{
		cout << to_str() << "\n";
	}


	// Question 7.
	// getter.
	// returns the string at index location of i of the str_vec.
	string get(int i) const
	{
		if (i < 0 || i >= sz)
		{
			cmpt::error ("Index i cannot be reached, incorrect size.");
    		throw;
		}// if
	
		string array;
		array = arr[i];
		return array;
	}

	// setter.
	// sets index location i to be a copy of the string s.
	void set(int i, const string& s)
	{
		if (i < 0 || i >= sz)
		{
			cmpt::error ("Index i cannot be reached, incorrect size.");
			throw;
		}// if

    	arr[i] = s;
	}


	// Question 8.
	// Adds a new element to the right end of arr, re-sizing it if necessary.
	// Increases size by 1.
	void append(const string& s)
	{
		// if size greater than capacity, resize capacity.
		if (sz >= cap)
		{
			int twiceCap = cap * 2;
			string *array = new string[twiceCap];

			// adding arr pointer content into array pointer.
			for (int index = 0; index < sz; index++)
			{
				array[index] = arr[index];
			}// for

			// deletes new memory.
			delete[] arr;
			// doubles the capacity.
			cap = cap * 2;
			arr = array;

		}// if

		// increments size and adds the string to the right.
		arr[sz] = s;
		sz++;

	}

	// String is added as the first element of the array 
	// (and all the other elements are moved right one position).
	// Increases size by 1.
	void prepend(const string& s)
	{
		// if size greater than capacity, resize capacity.
		if (sz >= cap)
		{
			int twiceCap = cap * 2;
			string *array = new string[twiceCap];

			// adding arr pointer content into array pointer.
			for (int index = 0; index < sz; index++)
			{
				array[index] = arr[index];
			}// for

			// deletes new memory.
			delete[] arr;

			// doubles the capacity.
			cap = cap * 2;
			arr = array;

		}// if

		// starts from the end of the array till arr[1]
		// moves the strings one place to the right.
		for (int index = sz; index > 0; index--)
		{
			arr[index] = arr[index - 1];
		}// for

		// adds the string to the left most order.
		arr[0] = s;
		sz++;
	}


	// Question 9.
	// reverses the order of the elements.
	void reverse()
	{
		string temp;
  		int i, j = 0;
  
		for(i = 0, j = sz - 1 ; i < j ; i++, j--){
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}

	// arranges in alphabetical order.
	void sort()
	{
		std::sort(arr, arr + sz);
	}
	

	// Question 10.
	// The size of the array is reset to zero.
	void clear()
	{
		sz = 0;
	}

	// make the size and capacity of arr the same
	void shrink_to_fit()
	{
		cap = sz;
	}


};// class


// Functions----------------------------------------------------

// Question 11.
// Returns true when str_vec a and str_vec b are equal.
// bool operator==(const str_vec& a, const str_vec& b)
bool operator==(const str_vec& a, const str_vec& b)
{
	// Initially size check.
	if (a.size() != b.size())
	{
		return false;
	}// if

	// Then character by character check.
	for (int index = 0; index < a.size() && index < b.size(); index++)
	{
		if (a.get(index) != b.get(index))
		{
			return false;
		}// if
	}// for

	return true;
}

// Returns true when str_vec a and str_vec b are not equal.
bool operator!=(const str_vec& a, const str_vec& b)
{
	// Initially size check.
	if (a.size() != b.size())
	{
		return true;
	}// if

	// Then character by character check.
	for (int index = 0; index < a.size() && index < b.size(); index++)
	{
		if (a.get(index) != b.get(index))
		{
			return true;
		}// if
	}// for

	return false;
}


// Main-------------------------------------------------------------------
int main() 
{
	return 0;
}