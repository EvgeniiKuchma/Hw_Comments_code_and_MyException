#pragma once
#include <iostream>
#include <string>
class MyException
{
public:
	MyException() {}

		 const std::string& what()
		{
		return  _whatStr;
		}
private:
	std::string _whatStr = "division by 0 is not possible\n";

};


