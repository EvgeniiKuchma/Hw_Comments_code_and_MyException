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
			const auto& [it, isInserted] = keyAutom.insert({ _key[i], 1 });//� ������� �������� ��������� � ���� ������������ ����� ������ � ����������� �������� � �������� ������������ ������� ����
			//������� �� ������� ���� �������� �������� � ���. � [it, isInsert] ���������� ������� insert <�������� �� ������� ������� ������ ������� ������(��� ������ �������� ��� ��������, bool �������� ������� ��� ��� ��������� insert>
			// ��� ���� ��������� �������� ������ ������� �� ���������� ������� ���� ������������ � ����������, � �������� �� �������� � ���� ������ ������ ���������� �� ���������, ������ ����� ��������� _key(������������ ��������� � �������) 
			// � [i](����������� �� ������ ����������� ��������) �� ������� �� ���������� (�������� ���������� ������ ������������� ���� it - �������� �� �������� ���� ({key[i],1})  � bool ��������)
			//������ � [it, isInsert]
			if (!isInserted)//����������� ������� ��� ������� �������� �� ������� ����� �������� � unordered_map, !inInsert ���������������� ��� - ���� ������� �� ���������
			{
				auto value = it->second;// � ������ �������� ���� ���������� ������� �� ������� ��������� value � ����� ������ auto � ���������� � ��� �������� �� ���� insert � ����� ������ 1
				value++;//����� ���� ����������� ��� �������� �� ������� 1 + 1
				keyAutom[_key[i]] = value;//���������� ����� ���������� ������ � ��������� keyAuto, ��� ��� ������ insert({}) �� �������� �������� � [] �������������� ������� ��������, � ���� � ������ insrert ����������� � unordered_map � ����������� ��������
				//�������� �������� ����
			}
		} 
		std::pair<int, int> key_biggestValue = { 0,0 };//������� ��������� pair � ����� ������� ����� � �������� int, ��� ���� ��������� ������� ���������� ��������� � ��� key_biggestValue �  ��������������� �� �������� ���������� ��� ��������� ���� ��� 
		//� ������ ��������� ����� ������� �������� �������� �� ������ unordered_map (��� ���� ���������� ������ ������ �������� 0 0 � �������). ���� �������� ������ ��������� ���������� � ��� ��������� � �������� ����� ������������� � unordered_map. ����� �� �� ��������� � ��������� pair keyAutom.begin() � keyAutom.end()
		//��� ��� ����� �������� �  ����������� ������ � ������ ���� unordered_map ����� ������
		for (std::unordered_map<int, int>::const_iterator it = keyAutom.begin(); it != keyAutom.end(); it++)//��������� ���� ��� ������� ��� ����������� � unordered_map, ������� ��� �� ������ ������ � ��� ����������� ���������� ����� 
	//�������� �������� �������� ���� �� ��� ������������ � ������� � ��� �� �������� ���� ������ �������������� �� ���� ���������� ���������� ���� ��� ����� ��������� � ������� 
		{
			if (key_biggestValue.second < it->second)//�������� ������� ��� ������� ���� �� unordered_map ������ ����� ������� �������� ������� �������� ������ ����������� �������� �������� ���� ��������� pair � ����� �� ��������� ����� 
				//��������� key_biggestValue � ����� second ������� �������� ��������� �� 2� ������� ����
				key_biggestValue = std::make_pair(it->first, it->second);//��� ����������� ������� ������� ���������� � ��������� pair � ������� ������� key_biggestValue � ��������� ������� std::make_pair ������� ��������� 
			//������� ���� �������� ��� ����� ������ �����. ���	���� ��������� ��������  it ������� ��������� �� ������ � ����� ���� ������������ ����
		}
		return key_biggestValue.first;//� ����� ���������� ���� ���������� ��������� 2 �� ��� �������� �������, �������, �������� ����������� ���������� ����� � �������
	}
private:
	std::vector<int> _key = { 1,1,2,2,2,4,2,6,7,7,7,2 };//��� ����� ������� ��� ���� ���������� ������

};
int main()
{
DataManager dm;//�������� ������� ������ ��� �������������� � ��� 
std::cout << dm.mostPopChedKey() << std::endl;//����� ������ � ����� ���������� �� ������ � ������  ����� ���������� std::cout


return 0;
}