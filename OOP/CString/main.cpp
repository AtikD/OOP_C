#include "string.hpp"
#include <iostream>

int main()
{
	CString str_1;
	CString str_2("This is an example sentence. And it's cool.");
	CString str_3(str_2);
	CString str_4("Very important text for save", 10);
	CString str_5(20, '*');
	CString str_6(str_4, 5, 3);

	str_1.print();
	str_2.print();
	str_3.print();
	str_4.print();
	str_5.print();
	str_6.print();
	std::cout << '\n';

	std::cout << "str_1.empty();\n" <<
		(str_1.empty() ? "true" : "false") << '\n';
	std::cout << "str_4.size();\n" <<
		str_4.size() << '\n';
	std::cout << "str_4.capacity();\n" <<
		str_4.capacity() << '\n';
	std::cout << "str_4.data();\n" <<
		str_4.data() << '\n';

	str_4.clear();
	std::cout << "str_4.clear();\n";
	str_4.print();
	std::cout << '\n';

	str_4.push_back('H');
	str_4.push_back('i');
	str_4.push_back(',');
	str_4.push_back(' ');
	str_4.push_back('B');
	str_4.push_back('o');
	str_4.push_back('b');
	str_4.print();
	std::cout << '\n';

	str_2.erase(10, 8);
	str_2.print();
	std::cout << '\n';

	str_5.resize(10);
	str_5.resize(15);
	str_5.print();
	std::cout << '\n';

	str_2.swap(str_5);
	str_2.print();
	str_5.print();
	std::cout << '\n';

	char buf[20];
	size_t length = str_2.copy(buf, 2, 9);
	buf[length] = '\0';
	std::cout << '\n';

	str_2.assign(str_5);
	str_2.print();
	str_5.print();
	std::cout << '\n';

	std::cout << str_2.compare(str_5);
	std::cout << '\n';

	CString str_7("Hello"), str_8("Hello It\'s Me");
	str_7.print();
	str_8.print();
	std::cout << str_7.compare(str_8);
	std::cout << str_8.compare(str_7);
	std::cout << '\n';

	CString str_9(", My Dear Dear Dear Friend!");
	str_7.append(str_9);
	str_7.print();
	std::cout << '\n';

	CString str_10(". Oh! It\'s you");
	str_7.insert(5, str_10);
	str_7.print();
	std::cout << '\n';

	CString str_11(". Ah, I\'m very busy");
	str_7.replace(5, 14, str_11);
	str_7.print();
	std::cout << '\n';

	std::cout << "str_7.find(\"very\");\n" << str_7.find("very") << '\n';

	std::cout << "str_7.find_first_of(\"aeiouy\");\n" <<
		str_7.find_first_of("aeiouy") << '\n';

	std::cout << "str_7.find_first_not_of(\"ABCDEFGHIKLMNOPQRSTVXYZabcdefghiklmnopqrstvxyz ., \");\n" <<
		str_7.find_first_not_of("ABCDEFGHIKLMNOPQRSTVXYZabcdefghiklmnopqrstvxyz .,") << '\n';

	system("pause");
	return 0;
}
