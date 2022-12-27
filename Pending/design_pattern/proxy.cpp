#include <iostream>
#include <memory>

class ICar {
public:
	virtual ~ICar() {
		std::cout << "ICar destructor!" << std::endl;
	}

	virtual void DriveCar() = 0;
};

class Car: public ICar {
public:
	void DriveCar() override {
		std::cout << "Car has been driven!" << std::endl;
	}
};

class ProxyCar: public ICar {
public:
	ProxyCar(int driver_age) :
			driver_age_(driver_age) {
	}

	void DriveCar() override {
		if (driver_age_ > 16) {
			real_car_->DriveCar();
		} else {
			std::cout << "Sorry, the driver is too young to drive."
					<< std::endl;
		}
	}

private:
	std::unique_ptr<ICar> real_car_ = std::make_unique<Car>();
	int driver_age_;
};

int main() {
	std::unique_ptr<ICar> car = std::make_unique < ProxyCar > (16);
	car->DriveCar();

	car = std::make_unique < ProxyCar > (25);
	car->DriveCar();
	return 0;
}
