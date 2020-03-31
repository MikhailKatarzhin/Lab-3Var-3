using namespace std;

class vehicle
{
protected:
    int movementSpeed;
    unsigned int placeCount;
public:
    void virtual print() const = 0;
    static int const defaultMovementSpeed = 0;
    static unsigned int const defaultPlaceCount = 1;
    void setMovementSpeed(int const movementSpeed);
    void setMovementSpeed(short int const movementSpeed);
    void setMovementSpeed(unsigned int const movementSpeed);
    void setMovementSpeed(unsigned short int const movementSpeed);
    int getMovementSpeed() const;
    void setPlaceCount(unsigned int const placeCount);
    void setPlaceCount(unsigned short int const placeCount);
    unsigned int getPlaceCount() const;
};
