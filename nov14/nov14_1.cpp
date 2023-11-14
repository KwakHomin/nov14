#include <iostream>

class Shape {		//인터페이스를 만들기 위해 가상함수를 포함한 class 생성
public:
	virtual void draw() = 0;
};

class RoundedRectangle : public Shape {		//shape을 상속
public:
	void draw() override {		//상속한 class의 shape을 override
		std::cout << "Inside RoundedRectangle::draw() method." << std::endl;
	}
};

class RoundedSquare : public Shape {		//shape을 상속
public:
	void draw() override {		//상속한 class의 shape을 override
		std::cout << "Inside RoundedSquare::draw() method." << std::endl;
	}
};

class AbstractFactory {		//추상class를 생성하기위해 가상 함수를 사용
public:
	virtual Shape* createShape() = 0;
};

class RoundedShapeFactory : public AbstractFactory {		//abstractFactory 상속
public:
	Shape* createShape() override {		//상속한 class의 createShape override
		return new RoundedRectangle();
	}
};

class SquareShapeFactory : public AbstractFactory {		//AbstractFactroy 상속
public:
	Shape* createShape() override {		//상속한 class의 createShape override
		return new RoundedSquare();
	}
};

int main() {
	AbstractFactory* roundedFactory = new RoundedShapeFactory();	//AbstractFactory 객체를 RoundedShapeFactory를 업캐스팅하여 생성
	Shape* roundedShape = roundedFactory->createShape();			//생성한 객체의 createShape를 호출하여 Shape class의 객체 생성
	roundedShape->draw();		//roundedShape의 draw 호출

	AbstractFactory* squareFactory = new SquareShapeFactory();		//AbstractFactory 객체를 SquareShapeFactory를 업캐스팅하여 생성
	Shape* squareShape = squareFactory->createShape();		//생성한 객체의 createShape를 호출하여 Shape class의 객체 생성
	squareShape->draw();		//squareShape의 draw 호출

	delete roundedFactory;
	delete roundedShape;
	delete squareFactory;
	delete squareShape;
	//동적으로 할당된 객체들 삭제

	return 0;
}