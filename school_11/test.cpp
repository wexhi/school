#include  <iostream>
using  namespace  std;


//const  int  N = 3;
//
//typedef  struct  stu_type
//{
//    char  no[8];
//    char  name[20];
//    int  age;
//}STU;
//
//int  main()
//{
//    int  count(STU  s[]);
//    int  i, sum = 0;
//    STU  student[N];
//    for (i = 0; i < N; i++)
//    {
//        cin >> student[i].no;
//        cin >> student[i].name;
//        cin >> student[i].age;
//        getchar();
//    }
//    sum = count(student);
//    cout << sum << endl;
//    return  0;
//}
//int  count(STU  s[])
//{
//    int  sum = 0;
//    int  i;
//    for (i = 0; i < N; i++)
//        if (s[i].age < 20)
//            sum++;
//    return  sum;
//}


struct  student {
    string  name;
    int  total = 0;
};

int  main()
{
    int  n;
    struct  student  a[100];
    struct  student  temp;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i].name >> a[i].total;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j <= n - 2; j++)
        {
            if (a[j].name[0] > a[j + 1].name[0])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }

            if(a[j].total < a[j + 1].total)
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    for (int i = 0; i <= n - 1; i++)
    {
        cout << a[i].name << "  " << a[i].total << endl;
    }
    return  0;
}