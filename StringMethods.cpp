#ifndef STRINGMETHODS_CPP
#define STRINGMETHODS_CPP
#include <iostream>

namespace str_methods {
	int clen(const char *s)
	{
		int i = 0;
		while (s[i] != '\0')
		{
			i++;
		}
		return i;
	}

	void strcopy(char *dest, const char *s)
	{
		int i = 0;
		while (s[i] != '\0')
		{
			dest[i] = s[i];
			i++;
		}
		dest[i] = '\0';
	}

	char *cconcat(const char *s1, const char *s2)
	{
		int i = clen(s1);
		int buff_len = i + clen(s2);
		char *buff = new char[buff_len + 1];

		strcopy(buff, s1);

		for (int j = 0; j < clen(s2); j++)
		{
			buff[i + j] = s2[j];
		}

		buff[buff_len] = '\0';

		return buff;
	}

	bool strcmp(const char *s1, const char *s2)
	{
		int s1_size = clen(s1);
		int s2_size = clen(s2);

		if (s1_size == s2_size)
		{
			for (int i = 0; i < s2_size; i++)
			{
				if (s1[i] != s2[i])
				{
					return false;
				}
			}
		}
		else
		{
			return false;
		}
		return true;
	}

	bool str_match(const char *s1, const char *s2)
	{
		int s1_size = clen(s1);
		int s2_size = clen(s2);
		// std::cout << "str_match : " << " s1_size: " << s1_size << " s2_size: " << s2_size << '\n';

		int j;
		for (int i = 0; i < s1_size; i++)
		{
			j = 0;
			while (j < s2_size && s1[i] == s2[j])
			{
				// std::cout << "s1[" << i << "]= " << s1[i] << " == " << s2[j] << '\n';
				j++;
			}
			if (j == s2_size - 1)
			{
				// std::cout << j << " " << s2_size << '\n';
				return true;
			}
		}
		return false;
	}

	void print_char(const char *s)
	{
		int last_of = clen(s);
		for (int i = 0; i < last_of; i++)
		{
			std::cout << s[i];
		}
		std::cout << '\n';
	}
}

#endif