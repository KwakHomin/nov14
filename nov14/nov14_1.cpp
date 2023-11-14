#include <iostream>

class Shape {		//�������̽��� ����� ���� �����Լ��� ������ class ����
public:
	virtual void draw() = 0;
};

class RoundedRectangle : public Shape {		//shape�� ���
public:
	void draw() override {		//����� class�� shape�� override
		std::cout << "Inside RoundedRectangle::draw() method." << std::endl;
	}
};

class RoundedSquare : public Shape {		//shape�� ���
public:
	void draw() override {		//����� class�� shape�� override
		std::cout << "Inside RoundedSquare::draw() method." << std::endl;
	}
};

class AbstractFactory {		//�߻�class�� �����ϱ����� ���� �Լ��� ���
public:
	virtual Shape* createShape() = 0;
};

class RoundedShapeFactory : public AbstractFactory {		//abstractFactory ���
public:
	Shape* createShape() override {		//����� class�� createShape override
		return new RoundedRectangle();
	}
};

class SquareShapeFactory : public AbstractFactory {		//AbstractFactroy ���
public:
	Shape* createShape() override {		//����� class�� createShape override
		return new RoundedSquare();
	}
};

int main() {
	AbstractFactory* roundedFactory = new RoundedShapeFactory();	//AbstractFactory ��ü�� RoundedShapeFactory�� ��ĳ�����Ͽ� ����
	Shape* roundedShape = roundedFactory->createShape();			//������ ��ü�� createShape�� ȣ���Ͽ� Shape class�� ��ü ����
	roundedShape->draw();		//roundedShape�� draw ȣ��

	AbstractFactory* squareFactory = new SquareShapeFactory();		//AbstractFactory ��ü�� SquareShapeFactory�� ��ĳ�����Ͽ� ����
	Shape* squareShape = squareFactory->createShape();		//������ ��ü�� createShape�� ȣ���Ͽ� Shape class�� ��ü ����
	squareShape->draw();		//squareShape�� draw ȣ��

	delete roundedFactory;
	delete roundedShape;
	delete squareFactory;
	delete squareShape;
	//�������� �Ҵ�� ��ü�� ����

	return 0;
}