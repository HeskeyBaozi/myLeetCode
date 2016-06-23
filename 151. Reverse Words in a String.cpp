// Given s = "the sky is blue",
// return "blue is sky the".
//#define MY

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
	void reverseWords(string &s)
	{
#ifdef MY
		if (s.find_first_not_of(' ') == string::npos)
			s = "";
		vector<string> word_stack;

		string::iterator pre = s.begin();
		string::iterator cur = s.begin();

		while (cur != s.end())
		{
			while (cur != s.end() && *cur != ' ')
			{
				++cur;
			}

			string word(pre, cur);
			if (!word.empty())
				word_stack.push_back(word);
			if (cur != s.end())
			{
				++cur;
				pre = cur;
			}

		}
		string result;
		while (word_stack.size())
		{
			string word = word_stack.back();
			word_stack.pop_back();
			if (word_stack.size())
				result += word + ' ';
			else
				result += word;
		}
		s = result;
#endif // MY
#ifndef MY
		// s1, in place
		reverse(s.begin(), s.end());
		int storeIndex = 0;
		for (int i = 0; i < s.size(); i++) {

			// if not point to the space
			if (s[i] != ' ') {

				// 空格添加器
				if (storeIndex != 0)
				{
					s[storeIndex] = ' ';
					storeIndex++;
				}

				// i 指向一个倒序单词的开头
				int j = i;
				while (j < s.size() && s[j] != ' ')
				{
					s[storeIndex++] = s[j++];
				}
				reverse(s.begin() + storeIndex - (j - i), s.begin() + storeIndex);
				i = j;
			}
		}
		s.erase(s.begin() + storeIndex, s.end());

#endif
	}
};

void test_151()
{
	Solution sol;
	string s("    the   sky  is blue  ");
	sol.reverseWords(s);
	cout << s << endl;
}
