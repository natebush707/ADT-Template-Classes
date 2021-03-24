#ifndef STACK_H
#define STACK_H

using namespace std;

template <typename C>
class Stack
{
  public:
	typedef typename C::value_type value_type;

	Stack() {}

	int size() const {return thestack.size();}

	bool empty() const {return thestack.empty();}

	void push(const value_type& x)
	{
		thestack.push_back(x);
	}

	void pop() {thestack.pop_back();}

	value_type top() {return thestack.back();}

  private:
	C thestack;
};

#endif