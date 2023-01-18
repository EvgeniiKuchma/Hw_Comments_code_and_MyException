#include <iostream>
#include <utility>//библиотека для работы с классом pair
#include <vector>
#include <unordered_map>
#include <tuple>

class DataManager//создаем класс
{
public://создаем мдификатор доступа: доступ открыт всем, кто видит определение данного класса
	int mostPopChedKey()//создаем функцию без параметров с типом данных int 
	{
		std::unordered_map<int, int> keyAutom;//создаем структуру(STL контейнер) для записи в нее пар <уникальный ключ, (елемент записанный в векторе std::vector<int>
		//хотя бы 1 раз) значение(количество повторений элемента, выше упомянутого, в векторе)> с типом данных для обоих значениq пар, хранящихся в нашей unordered_map, 
		// определенных как <int, int>, а так же создаем обьекть структуры в виде перменной локальной переменной keyAutom, с помощью которой в дальйнейшем будем взаимодействовать с данной структурой
		for (size_t i = 0; i < _key.size(); i++)//запускаем цикл for для пербора элементов записанныч в векторе std::vector<int> при этом тип переменной i определяем как size_t
		//что значит - беззнаковый целый тип, предназначенный для представления размера любого объекта в памяти (включая массивы) в конкретной реализации,а условия выполнения цикла 
		//ограничиваем методом .size() который возвращает количество элементов в векторе.
		{
			const auto& [it, isInserted] = keyAutom.insert({ _key[i], 1 });//достаем из вектора ключ пытаемся вставить в мап. в [it, isInsert] возвращает функция insert <указатель на элемент который мешает сделать инсерт, bool значение удалось вставить или нет>
			if (!isInserted)
			{
				auto value = it->second;
				value++;
				keyAutom[_key[i]] = value;//обращаемся через квадратные скобки так как фунция insert({}) не позволит вставить  а [] гарантированно вставят значения
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