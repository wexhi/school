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
    //    cout << "车轮:" << wheels << "个" << endl;
    //    cout << "重量:" << weight << "公斤" << endl;
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
		cout << "车型:小车" << endl;
		cout << "车轮:" << wheels << "个" << endl;
		cout << "重量:" << weight << "公斤" << endl;
		cout << "载人:" << passenger_load << "位" << endl;
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
            cout << "车型:卡车" << endl;
		cout << "车轮:" << wheels << "个" << endl;
		cout << "重量:" << weight << "公斤" << endl;
		cout << "载人:" << load_weight << "位" << endl;
		cout << "载重量:" << payload_weight << "公斤" << endl;
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