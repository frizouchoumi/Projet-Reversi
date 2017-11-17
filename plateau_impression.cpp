#include <iostream>
#include <string>
#include <fstream>
using std::cout;
using std::endl;
using std::string;
using std::ifstream;

/* Ce code imprime juste un plateau mais n'agit pas du tout en fonction des cases du plateau
 * NE PAS RE MODIFIER, BLC de ce code
 */

int imprimePlateau(){
	for(char i='a';i<='h';i++)
		cout << '\t' << i;
	cout << endl;
	for(int j=1;j<=8;j++){
		cout << j << '\t';
		for(int k=1;k<=8;k++)
			cout << '.' << '\t';
		cout << j << endl;
	}
	for(char i='a';i<='h';i++)
		cout << '\t' << i;
	cout << endl;
	return 0;
}

int main(){
	imprimePlateau();
	return 0;
}
