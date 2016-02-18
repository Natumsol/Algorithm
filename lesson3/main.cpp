#include <iostream>
#include <string>
using namespace std; 
void bitString(int x,string prefix)
{ 
	if (x == 0)
		cout << prefix <<endl; 
	else
	{
		bitString(x-1,(prefix+"0"));
		bitString(x-1,(prefix+"1")); 
	}
} 

void func(){
	float x , y, z;
	for(x = 0; x <= 10000; x ++) {
		for(y = 0; y <= 10000; y ++) {
			z = ((y - 1 - (9 - x) / y) * (4 - x) - 4) / y;
			if(z - (int)z == 0 && z >=0 && z <= 10000) {
				cout<< x << " " << y << " " << z << endl;
			}
		}
	}
}

int main ()
{
	func();
	system ("pause");
	return 0;
}

