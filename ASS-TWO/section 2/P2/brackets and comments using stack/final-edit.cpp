#include "pch.h"
#include <iostream>

using namespace std;

template <class t>
class Stack {
private:
	t top;
	t* item;//array and size
	int size = 0;
public:
	Stack() :top(NULL) {}
	Stack(t value, int intial_size)
	{
		for (int i = 0; i < intial_size;i++) {
			push(value);
		}
	}
	void push(t element) {//check if stack is full
		if (size > 0) {
			t* tmp = new t[size];
			for (int i = 0; i < size;i++) {
				tmp[i] = item[i];
			}
			delete[] item;
			size++;
			item = new t[size];
			item[0] = element;
			top = element;
			for (int i = 0; i < size - 1;i++) {
				item[i+1] = tmp[i];
			}
		}
		else {
			size++;
			item = new t[size];
			item[0] = element;
			top = element;
		}
	}
	bool empty() {
		return top == NULL;
	}
	void pop() {//check if stack is empty
		if (empty()) {
			cout << "stack is empty";
		}
		else {//delete element
			t* tmp = new t[size - 1];
			for (int i = 0; i < size;i++) {
				tmp[i] = item[i +1];
			}
			size--;
			delete[] item;
			item = new t[size];
			for (int i = 0; i < size;i++) {
				item[i] = tmp[i];
			}
			top = item[0];
		}
	}
	t Top()
	{
		return top;
	};
	void print()
	{
		cout << "[";
		for (int i = top; i >= 0; --i)
		{
			cout << item[i] << " ";
		}
		cout << "]";
	}
	int Size() {
		return size;
	}
	~Stack()
	{
		delete[] item;
	}
};
bool airpair(char open, char close) {
	if (open == '(' && close == ')')
		return true;
	else if (open == '[' && close == ']')
		return true;
	else if (open == '{' && close == '}')
		return true;
	return false;
}


bool balance(string exp) {
	Stack<char>S;
	bool cam;
	for (size_t i = 0; i < exp.length(); i++) {
		cam = true;
		if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
			S.push(exp[i]);
			continue;
		}
		else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
		{
			if (S.empty() || !airpair(S.Top(), exp[i])) {

				return false;
			}
			else {
				S.pop();
			}
			continue;
		}
		else if (exp[i] == '/') {
			if (exp[i + 1] == '*') {
				i++;
				while (i < exp.length()) {
					i++;
					if (exp[i] == '*') {
						if (exp[i+1] == '/') {
							i++;
							cam = false;
							break;
						}
					}
				}
				if (cam)
				{
					cout << "the comment is not closed\n";
					return false;
				}
				continue;

			}
		}

		if (S.empty())
			return true;
		else {
			return false;
		}
	}
}

int main() {
	string experision;
	cout << "enter the experision";
	cin >> experision;
	if (balance(experision)) {
		cout << "valid";
	}
	else {
		cout << " invalid";
	}


	return 0;
	
}
