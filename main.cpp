#include <iostream>
using namespace std;

string rgbToAnsiBg(int r, int g, int b)
{
	return ("\u001b[48;2;" + to_string(r) + ";" + to_string(g) + ";" + to_string(b) + "m");
}

string rgbToAnsiChar(int r, int g, int b){
	if(r < 75)
		r = 0;
	else
		r = (r-35)/40 * 36;

	if(g < 75)
		g = 0;
	else
		g = (g-35)/40 * 6;

	if(b < 75)
		b = 0;
	else
		b = (b-35)/40;

	return "\u001b[38;5;" + to_string(r+g+b+16) + "m";

}

int main()
{
	const int spaceWidth = 32; 	//pixels
	const int spaceHeight = 64; //pixels
	string code = "";
	cout << rgbToAnsiChar(255, 255, 255) << " - ALA MA KOTA - "  << rgbToAnsiChar(255, 0, 0) << " - ALA MA KOTA - "  << rgbToAnsiChar(0, 255, 0) << " - ALA MA KOTA" << endl;
}
