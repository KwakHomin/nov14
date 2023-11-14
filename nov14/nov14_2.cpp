#include <iostream>

// Implementor interface
class DrawAPI {     //�������̽� ������ ���� �����Լ��� �̿��Ͽ� class ����
public:
    virtual void drawCircle(int radius, int x, int y) = 0;
};

// Concrete Implementor classes
class RedCircle : public DrawAPI {      //DrawAPI�� ����� RedCircle class ����
public:
    void drawCircle(int radius, int x, int y) override {    //drawCircle override
        std::cout << "Drawing Circle[ color: red, radius: " << radius
            << ", x: " << x << ", y: " << y << " ]" << std::endl;
    }
};

class GreenCircle : public DrawAPI {        //DrawAPI�� ����� GreenCircle class ����
public:
    void drawCircle(int radius, int x, int y) override {   //drawCircle override
        std::cout << "Drawing Circle[ color: green, radius: " << radius
            << ", x: " << x << ", y: " << y << " ]" << std::endl;
    }
};

class Shape {       //Shape �߻� class ����
protected:
    DrawAPI* drawAPI;       //��ü ����

public:
    Shape(DrawAPI* api) : drawAPI(api) {}

    virtual void draw() = 0;
};

class Circle : public Shape {       //Shape�� ����Ͽ� Circle class ����
private:
    int radius;     //������
    int x;          //x��
    int y;          //y��

public:
    Circle(int r, int xx, int yy, DrawAPI* api) : Shape(api), radius(r), x(xx), y(yy) {}        //Shape �� ����� ������

    void draw() override {      //draw�� override
        drawAPI->drawCircle(radius, x, y);
    }
};

int main() {
    DrawAPI* redCircle = new RedCircle();       //RedCircle ��ü�� ��ĳ�����Ͽ� redCircle ��ü ����
    DrawAPI* greenCircle = new GreenCircle();   //GreenCircle ��ü�� ��ĳ�����Ͽ� redCircle ��ü ����

    Shape* red = new Circle(100, 100, 10, redCircle);       //��ü ����
    Shape* green = new Circle(50, 50, 5, greenCircle);

    red->draw();        //red�� draw()ȣ��
    green->draw();      //green�� draw()ȣ��

    delete redCircle;
    delete greenCircle;
    delete red;
    delete green;

    return 0;
}