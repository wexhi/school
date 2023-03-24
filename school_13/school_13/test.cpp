#include  <iostream>
#include<iomanip>
using  namespace  std;

//class  Column
//{
//    double  r;
//    double  h;
//public:
//    Column(double m_r, double m_h)
//    {
//        r = m_r;
//        h = m_h;
//    }
//
//
//    double  getArea();
//    double  getCubage();
//};
//double  Column::getArea()
//{
//    return 2 * 3.1415926 * r * r + (2 * 3.1415926 * r) * h;
//
//}
//double  Column::getCubage()
//{
//    return 3.1415926 * r * r * h;
//
//}
//int  main()
//{
//    double  r1, h1;
//
//    cin >> r1 >> h1;
//    Column  c1(r1, h1);
//    cout << c1.getArea() << "  " << c1.getCubage();
//    return  0;
//}

//class    Date
//{
//public:
//    int  year;
//    int  month;
//    int  day;
//    bool  setDate(const  int  mm, const  int  dd, const  int  yy);
//    void  display(void);
//    string  getMonth(const  int  m);
//
//};
//
//string  Date::getMonth(const  int  m)
//{
//    string mon;
//    enum Month
//    {
//        January = 1, 
//        February,
//        March,
//        April,
//        May,
//        June,
//        July,
//        August,
//        September,
//        October,
//        November,
//        December,
//    };
//
//    switch (m)
//    {
//    case January:
//    {
//        mon = "January";
//        return mon;
//    }
//    case February:
//    {
//        mon = "February";
//        return mon;
//    }
//    case March:
//    {
//        mon = "March";
//        return mon;
//    }
//    case April:
//    {
//        mon = "April";
//        return mon;
//    }
//    case May:
//    {
//        mon = "May";
//        return mon;
//    }
//    case June:
//    {
//        mon = "June";
//        return mon;
//    }  
//    case July:
//    {
//        mon = "July";
//        return mon;
//    }    
//    case August:
//    {
//        mon = "August";
//        return mon;
//    }    
//    case September:
//    {
//        mon = "September";
//        return mon;
//    }    
//    case October:
//    {
//        mon = "October";
//        return mon;
//    }
//    case  November:
//    {
//        mon = " November";
//        return mon;
//    }   
//    case December:
//    {
//        mon = "December";
//        return mon;
//    }
//    default:
//        break;
//    }
//}
//
//bool  Date::setDate(const  int  mm, const  int  dd, const  int  yy)
//{
//    if (mm < 1 || mm>12)
//        return  false;
//    if (dd < 1 || dd>31)
//        return  false;
//    year = yy;
//    month = mm;
//    day = dd;
//    return  true;
//}
//void  Date::display(void)
//{
//    cout << month << "--" << day << "--" << year << "\n";
//    cout << getMonth(month) << "    " << day << ",    " << year << "\n";
//    cout << day << "    " << getMonth(month) << "    " << year << "\n";
//    cout.flush();
//}
//
//int  main()
//{
//    Date  myDate;
//    int  year;
//    int  month;
//    int  day;
//
//    while (true)
//    {
//        cin >> year;
//        cin >> month;
//        cin >> day;
//        if (myDate.setDate(month, day, year))
//        {
//            break;
//        }
//        else
//        {
//            cout << "data  error";
//            cout.flush();
//        }
//    }
//    myDate.display();
//
//    return  0;
//}

//class Complex
//{
//public:
//    Complex(float a, float b)
//    {
//        m_a = a, m_b = b;
//    }
//
//    void show()
//    {
//        if (m_a != 0 && m_b < 0)
//        {
//            cout << fixed << setprecision(2) << m_a << fixed << setprecision(2) << m_b << "i";
//        }
//        else if (m_a != 0 && m_b > 0)
//        {
//            cout << fixed << setprecision(2) << m_a << fixed << setprecision(2) << "+" << m_b << "i";
//        }
//        else if (m_a != 0 && m_b == 0)
//        {
//            cout << fixed << setprecision(2) << m_a ;
//        }
//        else if (m_a == 0 && m_b < 0)
//        {
//            cout << fixed << setprecision(2) << m_b << "i";
//        }
//        else if (m_a == 0 && m_b > 0)
//        {
//            cout << fixed << setprecision(2) << "+" << m_b << "i";
//        }
//        else
//        {
//            cout << "0";
//        }
//    }
//
//    Complex add(Complex& s)
//    {
//        this->m_a = this->m_a + s.m_a;
//        this->m_b = this->m_b + s.m_b;
//        return s;
//    }
//
//    float m_a, m_b;
//};



//int  main() {
//    float  a, b;
//    cin >> a >> b;
//    Complex  c1(a, b);
//    c1.show();
//    cout << endl;
//    cin >> a >> b;
//    Complex  c2(a, b);
//    c2.show();
//    cout << endl;
//    c1.add(c2);
//    c1.show();
//
//    return  0;
//}


//class    Payroll
//{
//public:
//
//    float pay_per_hour, total_pay, hours;
//
//    Payroll(){}
//    
//
//    Payroll(float  hour);
//    void  setPay_per_hour(float  pph);
//    bool  setHours(float  hour);
//    float  getPayment();
//};
//
//Payroll::Payroll(float  hour)
//{
//    ;
//}
//void  Payroll::setPay_per_hour(float  pph)
//{
//    pay_per_hour = pph;
//}
//
//bool  Payroll::setHours(float  hour)
//{
//    if (hour >= 0 && hour <= 60)
//    {
//        hours = hour;
//        total_pay = pay_per_hour * hours;
//        return  true;
//    }
//    else
//        return  false;
//}
//
//float  Payroll::getPayment()
//{
//    return  total_pay;
//}
//
//
//int  main()
//{
//    Payroll  employee[10];
//    float    pph;
//    float    tHour;
//    cin >> pph;
//
//    for (int i = 0; i < 10; i++)
//    {
//        employee[i].setPay_per_hour(pph);
//        while (true)
//        {
//            cin >> tHour;
//            if (employee[i].setHours(tHour))
//                break;
//            else
//            {
//
//            }
//        }
//    }
//    cout << endl;
//
//    for (int i = 0; i < 10; i++)
//        cout << setiosflags(ios::fixed) << setprecision(2)
//        << employee[i].getPayment() << "  ";
//
//    return  0;
//}

class Point 
{
public:
    Point(double x, double y)
    {
        m_x = x, m_y = y;
    }

    void draw()
    {
        cout << "Point:x=" << m_x <<  ",y=" << m_y;
    }

    double m_x, m_y;
};


class Line
{
public:
    double m_x1, m_y1, m_x2, m_y2;

    Line(const Point& p1, const Point& p2)
    {
        m_x1 = p1.m_x;
        m_y1 = p1.m_y;
        m_x2 = p2.m_x;
        m_y2 = p2.m_y;
    }

    void draw()
    {
        cout << "Line:(Point:x=" << m_x1 << ",y=" << m_y1 << ";Point:x=" << m_x2 << ",y=" << m_y2 <<  ")" << endl;
    }
};

class Circle
{
public:
    double m_r, m_x, m_y;

    Circle(const Point& p, double r)
    {
        m_r = r;
        m_x = p.m_x;
        m_y = p.m_y;
    }

    void draw()
    {
        cout << "Circle:(radius:" << m_r << ";orgin:Point:x=" << m_x << ",y=" << m_y << ")" << endl;
    }
};

int  main()
{
    double  x1, y1, x2, y2, r;
    cin >> x1 >> y1 >> x2 >> y2 >> r;
    Point  p1(x1, y1);
    Point  p2(x2, y2);
    Line  L(p1, p2);
    Circle  c(p2, r);
    p1.draw();
    cout << endl;
    L.draw();
    c.draw();

    return  0;
}
