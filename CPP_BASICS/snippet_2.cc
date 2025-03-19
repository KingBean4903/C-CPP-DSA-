#include <iostream>

void digits()
{
		
	for (int i = 0; i != 10; ++i)
				std::cout << static_cast<char>('0'+i);
}

void crazyChars() 
{
		
	signed char sc = -160;
	unsigned char uc = sc;
	std::cout << uc;

}

void signdCheck() 
{
		char c = 255;
		int t = c;
		if (t == -1)
				std::cout << "Chars are signed " ;
		else 
				std::cout << "Chars are unsigned";

}


int main()
{
//	digits();
//	crazyChars();
	
	signdCheck();


	return 0;
}
