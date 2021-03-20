#ifndef QUEUE_H
#define QUEUE_H

using namespace std;

template <typename C>
class Queue
{
  public:
	typedef typename C::value_type value_type;

	Queue(){}
	int size() const {return thequeue.size();}
	bool empty() const {return thequeue.empty();}

	void enqueue(const value_type& x)
	{
		thequeue.push_back(x);
	}
	void dequeue() {thequeue.pop_front();}

	value_type front() {return thequeue.front();}

  private:
	C thequeue;
};

#endif