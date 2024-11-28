#include <iostream>
#include <cassert>
using namespace std;

// Declaration of a doubly-linked list
class List {
private:
	int mida = 0;
	int capacity;
	int* array;
public:
	// Constructor and destructor
	List() {
		capacity = 10;
		array = new int[capacity];
	}
	List(int ca) {
		capacity = ca;
		array = new int[capacity];
	}
	List(int ca, int* inicial, int midainicial) {
		capacity = ca;
		mida = midainicial;
		array = new int[capacity];
		for (int i = 0; i < midainicial; i++) {
			array[i] = inicial[i];
		}
	}
	~List() {};

	
	void insert(unsigned int position, const int& value) {
		if (capacity <= mida) {
			capacity*= 2;
		}
		int* newarray = new int[capacity];
		mida++;
		int i;
		for (i = 0; i < position; i++) {
			newarray[i] = array[i];
		}
		newarray[i] = value;
		i++;
		while (i < mida) {
			newarray[i] = array[i - 1];
			i++;
		}
		delete[] array;
		array = newarray;
	};

	void print() {
		for (int i = 0; i < mida; i++) {
			cout << array[i] << ", ";
		}
		//pointing
		Node* current = first;
		while (current != nullptr) {
			cout << current->value << ", ";
			current = current->next;
		}
		cout << endl;
	}
	// Modifiers
	void push_back(const int& value) {
		Node* newNode = new Node();
		newNode->value = value;
		newNode->next = nullptr;

		if (last == nullptr) {  
			first = last = newNode;
			newNode->prev = nullptr;
		}
		else {  
			newNode->prev = last;
			last->next = newNode;
			last = newNode;
		}

		num_elems++;
	}
private:
	// Internal struct for list nodes
	struct Node {
		int value;
		Node* next;
		Node* prev;
	};

	// List internals
	Node* first = nullptr;
	Node* last = nullptr;
	unsigned int num_elems = 0;
};

int main() {

	List a(10);

	a.insert(0, 7);
	a.print();
	a.insert(1, 5);
	a.print();
	a.insert(2, 3);
	a.print();
	a.push_back(6);
	a.print();

}
