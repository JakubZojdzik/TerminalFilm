#include <bits/stdc++.h>
#include <unistd.h>
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
	string pixel = "█", color, s, r, g, b;
	fstream pix;
	pix.open("pixels.txt");
	int k = 0;
	while(true)
	{
		system("clear");
		s = "";
		for(int i = 0; i < 41; i++)
		{
			for(int j = 0; j < 165; j++)
			{
				pix >> color;
				k = 0;
				r = ""; g = ""; b = ""; 
				while(color[k] != ';')
				{
					r += color[k];
					k++;
				}
					
				k++;
				while(color[k] != ';')
				{
					g += color[k];
					k++;
				}
					
				k++;
				while(color[k] != ';')
				{
					b += color[k];
					k++;
				}
				s += rgbToAnsiChar(stoi(r), stoi(g), stoi(b)) + pixel;
			}
			s += '\n';
		}
		cout << s;
		pix.clear();
		pix.seekg(0, pix.beg);
		usleep(600000);
	}
}
