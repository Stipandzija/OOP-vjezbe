#include <iostream>
#include <string>
#include <cctype>
#include<sstream>
#include "Header.hpp"

using namespace std;

char pretvara(char& c)
{
	if (isupper(c))
		return putchar(tolower(c));
	return c;
}
void prov(string& s)
{
	cout << "unesite string" << endl;
	getline(cin, s);
	string ss;
	string q;
	string word;
	stringstream x(s);

	while (x >> word)
	{
		if(pretvara(word[0]) == 'a' || pretvara(word[0]) == 'e' || pretvara(word[0]) == 'i' || pretvara(word[0]) =='o' || pretvara(word[0]) == 'u')
		{
			ss.append(word + "hay ");
		}
		else {
			for(char& element: word)
			{
				if(pretvara(element) == 'a' || pretvara(element) == 'e' || pretvara(element) == 'i' || pretvara(element) == 'o' || pretvara(element) == 'u')
				{
					ss.push_back(element);
				}
				else
					q.push_back(element);
					
			}
		}
	}
	ss.append(q + "ay ");
	s.clear();
	s.append(ss);

}