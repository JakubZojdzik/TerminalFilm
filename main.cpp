#include <iostream>
using namespace std;

string rgbToAnsi(int r, int g, int b)
{
	return ("\u001b[48;2;" + to_string(r) + ";" + to_string(g) + ";" + to_string(b) + "m");
}

int main()
{
	cout << rgbToAnsi(255, 0, 0) << "  " << rgbToAnsi(0, 255, 0) << "  " << rgbToAnsi(0, 0, 255) << "  " << rgbToAnsi(255, 255, 255) << "  " << rgbToAnsi(0, 0, 0) << "  \n";
}
