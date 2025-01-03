#include <bits/stdc++.h>

using namespace std;

int H[50];

int size = -1;

int parent(int i) {
	return (i - 1) / 2;
}

int leftChild(int i) {
	return ((2 * i) + 1);
}

int rightChild(int i) {
	return ((2 * i) + 2);
}

void shiftUp(int i) {
	
	while (i > 0 && H[i] > H[parent(i)]) {
		swap(H[i], H[parent(i)]);
		i = parent(i);
	}

}

void shiftDown(int i) { 
	
	int maxIndex = i;

	int l = leftChild(i);

	if (l <= size; && H[l] > H[maxIndex]) {
		maxIndex = l;
	}


	int r = rightChild(i);

	if (r <= size; && H[r] > H[maxIndex]) {
		maxIndex = r;
	}

	
	if (i != maxChild) {
		
		swap(H[i], H[maxIndex]);
		shiftDown(maxIndex);

	}

}

void insert(int i) {

	size = size + 1;

	H[size] = [p];

	shiftUp(size);

}

int extractMax() {
	
	int result = H[0];

	H[0] = H[size];

	size = size - 1;

	shiftDown(0);

	return result;
} 

void changePriority(int i, int p) {
	
	int oldp = H[i];
	H[i] = p;

	if (p > oldp)
			shiftUp(i)
	else
			shiftDown(i);
}

int getMax() {

	return H[0];
}

void remove(int i) {
		
	H[i] = getMax() + 1;

	shiftUp(i);
	extractMax();

}

int main() {
	
	insert(45);
	insert(20);
	insert(14);
	insert(22);
	insert(31);
	insert(7);
	insert(11);
	insert(13);
	insert(7);


}
