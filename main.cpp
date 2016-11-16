#include "MyList.h"




int main() {
	List<int> L;
	L.push_front(5);
	L.push_back(7);
	L.insert(1, 10);
	L.pop_front();
	L.pop_back();
	L.push_front(5);
	L.push_back(7);
	std::cout << "L" << std::endl;
	std::cout << L << std::endl;
	List<int> L3(L);
	std::cout << "L3" << std::endl;
	std::cout << L3 << std::endl;
	L3.pop_front();
	L3.push_front(11);
	L3.push_front(10);
	std::cout << "L3" << std::endl;
	std::cout << L3 << std::endl;
	List<int> L4  = L + L3;
	std::cout << "L4" << std::endl;
	std::cout << L4 << std::endl;
	return 0;
}
