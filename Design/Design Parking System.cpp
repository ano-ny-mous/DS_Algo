class ParkingSystem {
public:
    int bignum;
    int mednum;
    int smallnum;
    ParkingSystem(int big, int medium, int small) {
        bignum=big;
        mednum=medium;
        smallnum=small;
    }
    
    bool addCar(int carType) {
        if(carType==1&&bignum>0)
        {
            bignum--;
            return true;
        }
        else if(carType==2&&mednum>0)
        {
            mednum--;
            return true;
        }
        else if(carType==3&&smallnum>0)
        {
            smallnum--;
            return true;
        }
        return false;
    }
};