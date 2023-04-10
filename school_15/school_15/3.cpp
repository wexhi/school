#include    <iostream>
#define  PI  3.14159
using  namespace  std;

class  Shape {
public:
    double  getArea() { return  0; }
    double  getPerimeter() { return  0; }
};

class  Rectangle :public  Shape {
protected:
    double    height;
    double    width;
public:
    Rectangle() {};
    Rectangle(double  _height, double  _width) {
        height = _height;
        width = _width;
    }
    double  getArea() {
        return    height * width;
    }
    double  getPerimeter() {
        return    2 * (height + width);
    }
    void  Print() {
        cout << "Width=" << width << ",Height=" << height << endl;
    }
};

class  Square :public  Rectangle
{
public:
    Square() {};
    Square(double size) {
		height = size;
		width = size;
	}
    void  Print() {
		cout << "Side=" << height << endl;
	}
};

class  Circle : public  Shape {
public:
    Circle() {};
    Circle(double  _x, double  _y, double  _r) {
		x = _x;
		y = _y;
		r = _r;
	}
    double  getArea() {
		return    PI * r * r;
	}
    double  getPerimeter() {
		return    2 * PI * r;
	}
    void  Print() {
		cout << "Center=[" << x << "," << y << "],Adius=" << r << endl;
	}
    double x, y, r;
};

int    main() {
    double    ra, rb;
    cin >> ra >> rb;
    Rectangle    r1(ra, rb);
    double    sa;
    cin >> sa;
    Square    s1(sa);
    double    ca, cb, cc;
    cin >> ca >> cb >> cc;
    Circle    c1(ca, cb, cc);
    cout << "Rectangle" << endl;
    r1.Print();
    cout << "Area=" << r1.getArea() << endl;
    cout << "Perimeter=" << r1.getPerimeter() << endl;
    cout << "Square" << endl;
    s1.Print();
    cout << "Area=" << s1.getArea() << endl;
    cout << "Perimeter=" << s1.getPerimeter() << endl;
    cout << "Circle" << endl;
    c1.Print();
    cout << "Area=" << c1.getArea() << endl;
    cout << "Perimeter=" << c1.getPerimeter() << endl;
    return    0;
}