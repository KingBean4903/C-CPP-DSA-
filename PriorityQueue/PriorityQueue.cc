#include <iostream>

int H[50];
int size = - 1;

int parent(int i)
{
	return (i - 1) / 2;
}

int leftChild(int i)
{
	return ((2 * i) + 1);
}

int rightChild(int i)
{
	return ((2 * i) + 2);
}

void shiftUp(int i) {
	
	while (i > 0 && H[parent(i)] < H[i]) {
		swap(H[parent(i)], H[i]);
		i = parent(i);
	}
}

void shiftDown(int i) 
{

 int maxIndex = i;

 int l  = leftChild(i);

 if (l < size && H[l] > H[maxIndex]) {
	maxIndex = l;
 }

 int r  = rightChild(i);
 if (r < size && H[r] > H[maxIndex]) {
	maxIndex = r;
 }

 if (i != maxIndex) {
	swap(H[i], H[maxIndex]);
    shiftDown(maxIndex);
 }

}

void changePriority(int i, int p) {
	
	int oldp = H[i];
	H[i] = p;
	if (p > oldp) {
		shiftUp(i);
	} else {
		shiftDown(i);
	}
}

int extractMax() {
	
	int result = H[0];
	H[O]  = H[size];
	
	size = size - 1;
	shiftDown(0);

	return result;
	
}

int getMax() {
	return H[0];
}

void remove(int i)
{
	H[i] = getMax() + 1;

	shiftUp(i);

	extractMax();

}

void insert(int i) {
	
	size = size + 1;

	H[size] = i;

	shiftUp(size);

}















