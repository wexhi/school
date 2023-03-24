#include  <iostream>
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

class    Date
{
public:
    int  year;
    int  month;
    int  day;
    bool  setDate(const  int  mm, const  int  dd, const  int  yy);
    void  display(void);
    string  getMonth(const  int  m);

};

string  Date::getMonth(const  int  m)
{
    string mon;
    enum Month
    {
        January = 1, 
        February,
        March,
        April,
        May,
        June,
        July,
        August,
        September,
        October,
        November,
        December,
    };

    switch (m)
    {
    case January:
    {
        mon = "January";
        return mon;
    }
    case February:
    {
        mon = "February";
        return mon;
    }
    case March:
    {
        mon = "March";
        return mon;
    }
    case April:
    {
        mon = "April";
        return mon;
    }
    case May:
    {
        mon = "May";
        return mon;
    }
    case June:
    {
        mon = "June";
        return mon;
    }  
    case July:
    {
        mon = "July";
        return mon;
    }    
    case August:
    {
        mon = "August";
        return mon;
    }    
    case September:
    {
        mon = "September";
        return mon;
    }    
    case October:
    {
        mon = "October";
        return mon;
    }
    case  November:
    {
        mon = " November";
        return mon;
    }   
    case December:
    {
        mon = "December";
        return mon;
    }
    default:
        break;
    }
}

bool  Date::setDate(const  int  mm, const  int  dd, const  int  yy)
{
    if (mm < 1 || mm>12)
        return  false;
    if (dd < 1 || dd>31)
        return  false;
    year = yy;
    month = mm;
    day = dd;
    return  true;
}
void  Date::display(void)
{
    cout << month << "--" << day << "--" << year << "\n";
    cout << getMonth(month) << "    " << day << ",    " << year << "\n";
    cout << day << "    " << getMonth(month) << "    " << year << "\n";
    cout.flush();
}

int  main()
{
    Date  myDate;
    int  year;
    int  month;
    int  day;

    while (true)
    {
        cin >> year;
        cin >> month;
        cin >> day;
        if (myDate.setDate(month, day, year))
        {
            break;
        }
        else
        {
            cout << "data  error";
            cout.flush();
        }
    }
    myDate.display();

    return  0;
}