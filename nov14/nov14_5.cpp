#include <iostream>
#include <cassert>

class CEO {
public:
	virtual ~CEO() {}
};

class CPO {
public:
	virtual ~CPO() {}
};

class Manager : public CEO, CPO {

};

class Staff : public CPO {

};

int main() {
	CPO* cpo = new Staff();
	CEO* ceo = new Manager();
	Staff* staff = dynamic_cast<Staff*>(cpo);
	Staff* staff2 = dynamic_cast<Staff*>(ceo);
	Manager* manager = dynamic_cast<Manager*>(ceo);

	assert(staff != NULL);
	assert(staff2 == NULL);
	assert(manager != NULL);

	return 0;
}