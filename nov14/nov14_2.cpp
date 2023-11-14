#include <iostream>

// Implementor interface
class DrawAPI {     //인터페이스 생성을 위해 가상함수를 이용하여 class 생성
public:
    virtual void drawCircle(int radius, int x, int y) = 0;
};

// Concrete Implementor classes
class RedCircle : public DrawAPI {      //DrawAPI를 상속한 RedCircle class 생성
public:
    void drawCircle(int radius, int x, int y) override {    //drawCircle override
        std::cout << "Drawing Circle[ color: red, radius: " << radius
            << ", x: " << x << ", y: " << y << " ]" << std::endl;
    }
};

class GreenCircle : public DrawAPI {        //DrawAPI를 상속한 GreenCircle class 생성
public:
    void drawCircle(int radius, int x, int y) override {   //drawCircle override
        std::cout << "Drawing Circle[ color: green, radius: " << radius
            << ", x: " << x << ", y: " << y << " ]" << std::endl;
    }
};

class Shape {       //Shape 추상 class 생성
protected:
    DrawAPI* drawAPI;       //객체 생성

public:
    Shape(DrawAPI* api) : drawAPI(api) {}

    virtual void draw() = 0;
};

class Circle : public Shape {       //Shape를 상속하여 Circle class 생성
private:
    int radius;     //반지름
    int x;          //x값
    int y;          //y값

public:
    Circle(int r, int xx, int yy, DrawAPI* api) : Shape(api), radius(r), x(xx), y(yy) {}        //Shape 을 상속한 생성자

    void draw() override {      //draw를 override
        drawAPI->drawCircle(radius, x, y);
    }
};

int main() {
    DrawAPI* redCircle = new RedCircle();       //RedCircle 객체를 업캐스팅하여 redCircle 객체 생성
    DrawAPI* greenCircle = new GreenCircle();   //GreenCircle 객체를 업캐스팅하여 redCircle 객체 생성

    Shape* red = new Circle(100, 100, 10, redCircle);       //객체 생성
    Shape* green = new Circle(50, 50, 5, greenCircle);

    red->draw();        //red의 draw()호출
    green->draw();      //green의 draw()호출

    delete redCircle;
    delete greenCircle;
    delete red;
    delete green;

    return 0;
}