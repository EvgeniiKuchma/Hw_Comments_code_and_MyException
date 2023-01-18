#include <iostream>
#include <utility>//���������� ��� ������ � ������� pair
#include <vector>
#include <unordered_map>
#include <tuple>

class DataManager//������� �����
{
public://������� ���������� �������: ������ ������ ����, ��� ����� ����������� ������� ������
	int mostPopChedKey()//������� ������� ��� ���������� � ����� ������ int 
	{
		std::unordered_map<int, int> keyAutom;//������� ���������(STL ���������) ��� ������ � ��� ��� <���������� ����, (������� ���������� � ������� std::vector<int>
		//���� �� 1 ���) ��������(���������� ���������� ��������, ���� �����������, � �������)> � ����� ������ ��� ����� �������q ���, ���������� � ����� unordered_map, 
		// ������������ ��� <int, int>, � ��� �� ������� ������� ��������� � ���� ��������� ��������� ���������� keyAutom, � ������� ������� � ����������� ����� ����������������� � ������ ����������
		for (size_t i = 0; i < _key.size(); i++)//��������� ���� for ��� ������� ��������� ���������� � ������� std::vector<int> ��� ���� ��� ���������� i ���������� ��� size_t
		//��� ������ - ����������� ����� ���, ��������������� ��� ������������� ������� ������ ������� � ������ (������� �������) � ���������� ����������,� ������� ���������� ����� 
		//������������ ������� .size() ������� ���������� ���������� ��������� � �������.
		{
			const auto& [it, isInserted] = keyAutom.insert({ _key[i], 1 });//������� �� ������� ���� �������� �������� � ���. � [it, isInsert] ���������� ������� insert <��������� �� ������� ������� ������ ������� ������, bool �������� ������� �������� ��� ���>
			if (!isInserted)
			{
				auto value = it->second;
				value++;
				keyAutom[_key[i]] = value;//���������� ����� ���������� ������ ��� ��� ������ insert({}) �� �������� ��������  � [] �������������� ������� ��������
			}
		}
		std::pair<int, int> key_biggestValue = { 0,0 };
		for (std::unordered_map<int, int>::const_iterator it = keyAutom.begin(); it != keyAutom.end(); it++)
		{
			if (key_biggestValue.second < it->second)
				key_biggestValue = std::make_pair(it->first, it->second);
		}
		return key_biggestValue.first;
	}
private:
	std::vector<int> _key = { 1,1,2,2,2,4,2,6,7,7,7,2 };

};
int main()
{
DataManager dm;
std::cout << dm.mostPopChedKey() << std::endl;


return 0;
}