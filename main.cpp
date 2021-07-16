#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

string pixel = "█", color, s, r, g, b;
fstream pix;
bool stop_frame;
int k = 0, width = 234, height = 130; //165x82, hight resolution (not recomendet - 234x130)

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

void play()
{
	pix.open("pixels.txt");
	stop_frame = false;
	while(true)
	{
		system("clear");
		s = "";
		for(int i = 0; i < int(height/2); i++)
		{
			if(stop_frame)
				break;
			for(int j = 0; j < width; j++)
			{
				color = "";
				pix >> color;
				if(color.size() < 6)
				{
					stop_frame = true;
					break;
				}
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
		if(!stop_frame)
		{
			cout << s;
			pix.clear();
			pix.seekg(0, pix.beg);
			usleep(600000);
		}
		else 
		{
			stop_frame = false;
			pix.clear();
			pix.seekg(0, pix.beg);
			usleep(50000);
		}
		
	}
}

int main()
{
	play();
}
