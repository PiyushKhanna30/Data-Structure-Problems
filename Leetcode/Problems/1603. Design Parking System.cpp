class ParkingSystem {
public:
    vector<int>arr;
    ParkingSystem(int b, int m, int s) {
        arr.push_back(b);
        arr.push_back(m);
        arr.push_back(s);
    }
    
    bool addCar(int carType) {
        if(arr[carType-1]>0)
        {    
            arr[carType-1]--;
            return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */