#include    <iostream>
using    namespace    std;

class  Vehicle {
public:
    Vehicle(int  _wheels, float  _weight) {
        wheels = _wheels;
        weight = _weight;
    }
    int  get_wheels() {
        return  wheels;
    }
    float  get_weight() {
        return  weight;
    }
    //void  show() {
    //    cout << "����:" << wheels << "��" << endl;
    //    cout << "����:" << weight << "����" << endl;
    //}
protected:
    int  wheels;
    float  weight;
};

class  Car : public  Vehicle {
public:
    Car(int  wheels, float  weight, int  passengers = 4) :Vehicle(wheels, weight) {
        passenger_load = passengers;
    }

    //
    void  show() {
		cout << "����:С��" << endl;
		cout << "����:" << wheels << "��" << endl;
		cout << "����:" << weight << "����" << endl;
		cout << "����:" << passenger_load << "λ" << endl;
	}


private:
    int  passenger_load;
    
};

class  Truck : public  Vehicle {

    public:
        Truck(int  wheels, float  weight, int  load, float  payload) :Vehicle(wheels, weight) {
		load_weight = load;
		payload_weight = payload;
	}
        void  show() {
            cout << "����:����" << endl;
		cout << "����:" << wheels << "��" << endl;
		cout << "����:" << weight << "����" << endl;
		cout << "����:" << load_weight << "λ" << endl;
		cout << "������:" << payload_weight << "����" << endl;
	}
        private:
		int  load_weight;
		float  payload_weight;
};

int    main() {
    int    c1, c3;
    float    c2;
    cin >> c1 >> c2 >> c3;
    Car    car1(c1, c2, c3);
    int    t1, t3;
    float    t2, t4;
    cin >> t1 >> t2 >> t3 >> t4;
    Truck    tru1(t1, t2, t3, t4);
    car1.show();
    tru1.show();
    return    0;
}