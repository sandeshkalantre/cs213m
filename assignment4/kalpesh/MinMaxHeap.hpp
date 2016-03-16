#ifndef _MINMAXHEAP_HPP_
#define _MINMAXHEAP_HPP_
#include <vector>
#include <iostream>
using namespace std;

template<class T>
class Predicate {
	public:
		virtual bool toDelete(T elem) {
			return true;
		}
};

template<class T>
class MinMaxHeap {
private:
	// Add your member variables here
	vector<T> elements;
	int size;
public:
	MinMaxHeap() {
		T a;
		elements.push_back(a); // dummy node
		size = 0;
	}

	void swap(T &e1, T &e2) {
		T swap = e1;
		e1 = e2;
		e2 = swap;
	}

	bool isMaxLevel(int i) {
		int level = 0;
		int k = i/2;
		while (k != 0) {
			k /= 2;
			level++;
		}
		if (level%2 == 0) {
			return false;
		} else {
			return true;
		}
	}

	void printVector() {
		cout << "The vector is: ";
		for (int i = 1; i <= size; i++) {
			cout << "(" << elements[i].getStep() << "," << elements[i].getType() << "," << elements[i].getSubject() << ") ";
		}
		cout << endl;
	}

	void fix_max(int i) {
		int grandparent = i/4;
		while (grandparent > 0 && elements[grandparent] < elements[i]) {
			swap(elements[i], elements[grandparent]);
			i = grandparent;
			grandparent /= 4;
		}
	}

	void fix_min(int i) {
		int grandparent = i/4;
		while (grandparent > 0 && elements[i] < elements[grandparent]) {
			swap(elements[i], elements[grandparent]);
			i = grandparent;
			grandparent /= 4;
		}
	}

	void insert(T elem) {
		elements.push_back(elem);
		size += 1;
		if (size == 1) {
			return;
		}
		int parent = size/2;
		if (isMaxLevel(parent)) {
			if (elements[parent] < elements[size]) {
				swap(elements[size], elements[parent]);
				fix_max(parent);
			} else {
				fix_min(size);
			}
		} else {
			if (elements[size] < elements[parent]) {
				swap(elements[size], elements[parent]);
				fix_min(parent);
			} else {
				fix_max(size);
			}
		}
	}

	T getMin() {
		T min;
		if (size > 0) {
			min = elements[1];
		}
		return min;
	}

	T getMax() {
		T max;
		if (size > 0) {
			max = elements[1];
		}
		if (size > 1) {
			max = elements[2];
		}
		if (size > 2 && elements[3] > max) {
			max = elements[3];
		}
		return max;
	}

	int minChildGrandChildPosition(int i) {
		int min = i;
		if (size >= 2*i && elements[2*i] < elements[min]) {
			min = 2*i;
		}
		if (size >= 2*i+1 && elements[2*i+1] < elements[min]) {
			min = 2*i+1;
		}
		if (size >= 4*i && elements[4*i] < elements[min]) {
			min = 4*i;
		}
		if (size >= 4*i+1 && elements[4*i+1] < elements[min]) {
			min = 4*i+1;
		}
		if (size >= 4*i+2 && elements[4*i+2] < elements[min]) {
			min = 4*i+2;
		}
		if (size >= 4*i+3 && elements[4*i+3] < elements[min]) {
			min = 4*i+3;
		}
		return min;
	}

	int maxChildGrandChildPosition(int i) {
		int max = i;
		if (size >= 2*i && elements[max] < elements[2*i]) {
			max = 2*i;
		}
		if (size >= 2*i+1 && elements[max] < elements[2*i+1]) {
			max = 2*i+1;
		}
		if (size >= 4*i && elements[max] < elements[4*i]) {
			max = 4*i;
		}
		if (size >= 4*i+1 && elements[max] < elements[4*i+1]) {
			max = 4*i+1;
		}
		if (size >= 4*i+2 && elements[max] < elements[4*i+2]) {
			max = 4*i+2;
		}
		if (size >= 4*i+3 && elements[max] < elements[4*i+3]) {
			max = 4*i+3;
		}
		return max;
	}

	void deleteMin() {
		if (size == 0) {
			return;
		}
		T min_elem = elements[1];
		elements[1] = elements[size];
		elements.pop_back();
		int i = 1;
		size--;
		while (i <= size/2) {
			int min = minChildGrandChildPosition(i);
			if (elements[i] < elements[min]) {
				// Element already forms the min-max heap
				break;
			}
			// elements[i] is > than elements[min]
			// swap root with min element
			swap(elements[min], elements[i]);
			// check which level min was on
			if (min <= 2*i+1) {
				// min is a max level
				break;
			}
			// min is a min level
			// check whether parent of min is still a max heap
			if (elements[min/2] < elements[min]) {
				swap(elements[min], elements[min/2]);
			}
			i = min;
		}

	}

	void deleteMax() {
		if (size == 0) {
			return;
		}
		int max_pos = 1;
		if (size >= 2) {
			max_pos = 2;
		}
		if (size >= 3 && elements[2] < elements[3]) {
			max_pos = 3;
		}
		T max_elem = elements[max_pos];
		elements[max_pos] = elements[size];
		elements.pop_back();
		int i = max_pos;
		size--;
		while (i <= size/2) {
			int max = maxChildGrandChildPosition(i);
			if (elements[max] < elements[i]) {
				// Element already forms the min-max heap
				break;
			}
			// elements[i] is < than elements[min]
			// swap root with max element
			swap(elements[max], elements[i]);
			// check which level max was on
			if (max <= 2*i+1) {
				// max is a min level
				break;
			}
			// max is a max level
			// check whether parent of max is not a min heap
			if (elements[max] < elements[max/2]) {
				swap(elements[max], elements[max/2]);
			}
			i = max;
		}
	}

	void deleteElems(Predicate<T> *predObject) {
		vector<T> remaining_elements;
		while (size != 0) {
			T elem = elements[size];
			elements.pop_back();
			if (!predObject->toDelete(elem)) {
				remaining_elements.push_back(elem);
			}
			size -= 1;
		}
		int i = 0;
		while (i < remaining_elements.size()) {
			insert(remaining_elements[i]);
			i++;
		}
	}
};

#endif //_MINMAXHEAP_HPP_