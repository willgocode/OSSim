#include <iostream>
#include <queue>
#include <vector>
#include <list>

using namespace std;

class Rectangle{
	public:
		Rectangle(int x = 0, int y = 0) : length(x), width(y) {};
		int getLength() const {return length;}
		int getWidth() const {return width;}
		int getArea() const {return width*length;}
	private:
		int length;
		int width;
};

template<class T>
class Comparator{
	public:
		bool operator()(T const &lhs, T const &rhs){
			return lhs.getArea() > rhs.getArea();
		}
};

int main(){

//	priority_queue<Rectangle, vector<Rectangle>, Comparator<Rectangle>> myQueue;
	Rectangle one(4, 3);
	Rectangle two(12, 3);
//	myQueue.push(one);
//	myQueue.push(two);
//	cout << myQueue.top().getArea() << endl;

	list<Rectangle> myList;
	myList.push_back(two);
	myList.push_back(one);
	
	for(list<Rectangle>::const_iterator ci = myList.begin(); ci != myList.end(); ++ci){
		cout << ci -> getArea() << " ";
	}

	return 0;
}
