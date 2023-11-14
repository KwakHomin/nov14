#include <iostream>

class BaseClass {
public:
	virtual ~BaseClass() {}
};

class DerivedClass : public BaseClass {
public:

};

int main() {
	BaseClass* base = new DerivedClass();

	DerivedClass* derived = dynamic_cast<DerivedClass*>(base);

	if (derived) {
		std::cout << "Everything is OKAY" << std::endl;
	}

	delete base;

	return 0;
}