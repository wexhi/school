#include  <iostream>
#include  <cmath>
#define    PI    3.1415926
using    namespace    std;

class  Point
{
    //
public:
    Point() {};

    Point(double x, double y)
    {
		this->x=x;
		this->y=y;
	}

    double getX()
    {
        return x;
    }

    double getY()
    {
		return y;
	}

private:
    double x;
    double y;
};

class  Triangle
{
protected:
    Point    A;
    Point    B;
    Point    C;
public:


    Triangle(Point    A, Point    B, Point    C)
    {
        this->A = A;
        this->B = B;
        this->C = C;
    }
    double    getAB()
    {
        return    sqrt(pow((A.getX() - B.getX()), 2) + pow((A.getY() - B.getY()), 2));
    }
    double    getAC()
    {
        return    sqrt(pow((A.getX() - C.getX()), 2) + pow((A.getY() - C.getY()), 2));
    }
    double    getBC()
    {
        return    sqrt(pow((B.getX() - C.getX()), 2) + pow((B.getY() - C.getY()), 2));
    }
    double    getA()
    {
        double    fz = pow(getAB(), 2) + pow(getAC(), 2) - pow(getBC(), 2);
        double    fm = 2 * getAB() * getAC();
        return    acos(fz / fm);
    }
    double    getB()
    {
        double    fz = pow(getAB(), 2) + pow(getBC(), 2) - pow(getAC(), 2);
        double    fm = 2 * getAB() * getBC();
        return    acos(fz / fm);
    }
    double    getC()
    {
        double    fz = pow(getAC(), 2) + pow(getBC(), 2) - pow(getAB(), 2);
        double    fm = 2 * getAC() * getBC();
        return    acos(fz / fm);
    }
    double  getArea()
    {
        double  p = (getAB() + getAC() + getBC()) / 2;
        return  sqrt(p * (p - getAB()) * (p - getAC()) * (p - getBC()));
    }
    void  draw()
    {
        cout << "Triangle:" << endl;
        cout << "PointA:" << "x=" << A.getX() << ",y=" << A.getY() << endl;
        cout << "PointB:" << "x=" << B.getX() << ",y=" << B.getY() << endl;
        cout << "PointC:" << "x=" << C.getX() << ",y=" << C.getY() << endl;
    }
};


class    EquilateralTriangle :public    Triangle
{
    //
public:
    EquilateralTriangle(Point A, Point B, Point C) :Triangle(A, B, C)
    {
        this->A = A;
        this->B = B;
        this->C = C;
	}

    double    getAB()
    {
        return    sqrt(pow((A.getX() - B.getX()), 2) + pow((A.getY() - B.getY()), 2));
    }
    double    getAC()
    {
        return    sqrt(pow((A.getX() - C.getX()), 2) + pow((A.getY() - C.getY()), 2));
    }
    double    getBC()
    {
        return    sqrt(pow((B.getX() - C.getX()), 2) + pow((B.getY() - C.getY()), 2));
    }
    double    getA()
    {
        double    fz = pow(getAB(), 2) + pow(getAC(), 2) - pow(getBC(), 2);
        double    fm = 2 * getAB() * getAC();
        return    acos(fz / fm);
    }
    double    getB()
    {
        double    fz = pow(getAB(), 2) + pow(getBC(), 2) - pow(getAC(), 2);
        double    fm = 2 * getAB() * getBC();
        return    acos(fz / fm);
    }
    double    getC()
    {
        double    fz = pow(getAC(), 2) + pow(getBC(), 2) - pow(getAB(), 2);
        double    fm = 2 * getAC() * getBC();
        return    acos(fz / fm);
    }

    double  getArea()
    {
        double  p = (getAB() + getAC() + getBC()) / 2;
        return  sqrt(p * (p - getAB()) * (p - getAC()) * (p - getBC()));
    }

    double getEdge() 
    {
        return    sqrt(pow((A.getX() - B.getX()), 2) + pow((A.getY() - B.getY()), 2));
    }



    void draw()
    {
		cout << "EquilateralTriangle:" << endl;
        cout<< "Area:" << getArea() << endl;
		cout << "PointA:" << "x=" << A.getX() << ",y=" << A.getY() << endl;
		cout << "PointB:" << "x=" << B.getX() << ",y=" << B.getY() << endl;
		cout << "PointC:" << "x=" << C.getX() << ",y=" << C.getY() << endl;
        cout << "Angle:1.0472" << endl;
        cout << "Edge:" << getEdge() << endl;
	}


    Point A;
    Point B;
    Point C;


};

int    main()
{
    double    x1, y1, x2, y2, x3, y3;
    double    x4, x5, x6, y4, y5, y6;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    cin >> x4 >> y4 >> x5 >> y5 >> x6 >> y6;
    Point    A(x1, y1);
    Point    B(x2, y2);
    Point    C(x3, y3);
    Point    D(x4, y4);
    Point    E(x5, y5);
    Point    F(x6, y6);
    Triangle    t(A, B, C);
    EquilateralTriangle  et(D, E, F);
    t.draw();
    et.draw();
    return  0;
}