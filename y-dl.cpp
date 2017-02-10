#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

bool is_valid_response(string s)
{
	if (s == "Y")
		return true;
	else
		return false;
}

string uppercase(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		s = toupper(s[i]);
	}
	return s;
}
void list_formats(string s)
{
	string new_string = ("youtube-dl --list-formats " + s);
	system(new_string.c_str());
}

void download_format(string number, string link)
{
	string new_string = ("youtube-dl --format " + number + " " + link);
	system(new_string.c_str());
}

int main()
{
	for (int i = 0; i <= 10; i++)
	{
		cout << "What is the youtube link that you would like to enter?:";
		string video_link;
		getline(cin, video_link);
		list_formats(video_link);

		cout << endl << "What format would you like to download this video in?:";
		string format_number;
		getline(cin, format_number);
		download_format(format_number, video_link);

		cout << endl << "Is there another link to process? (Y, N)" << endl;
		string response;
		getline(cin, response);
		response = uppercase(response);

		if (!is_valid_response(response))
			i = 10;
			
	}
    return 0;
}

