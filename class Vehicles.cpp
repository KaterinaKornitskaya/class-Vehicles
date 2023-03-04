// class Vehicles.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

/*
	Реализовать иерархию классов "Транспортное средство".
	Базовый класс - транспорт, производные - самолёт, судно, грузовик, 
	велосипед и легковой автомобиль.
	Метод вывода и метод расхода топлива реализовать как virtual.
	Реализовать меню для создания объектов.
	Объекты создаются через единственный указатель на базовый класс.
*/

class Vehicle  // класс Тренспортное средство, базовый
{
protected:
	float fuel_consumption;  // расход топлива
public:
	Vehicle() : fuel_consumption{0} {}
	Vehicle(float fuel_cons) : fuel_consumption{fuel_cons} {}

	void virtual Consumption()  // виртуальный метод Расход топлива
	{
		std::cout << "Fuel consumption for Vehicle is unavailable\n";
	}
	void virtual Show()  // виртуальный метод Вывод
	{
		std::cout << "Characteristics for Vehicle is unavailable\n";
	}
};

class Airplane : public Vehicle  // класс Самолет, дочерний от Транспортное средство  
{
	float distance;  // пройденная дистанция
public:
	Airplane() : distance{0} {}
	Airplane(float fuel_cons, float dist)
		: Vehicle{ fuel_cons }, distance{ dist } {}

	void virtual Consumption()  // виртуальный метод Расход топлива, переопределен для класса Самолет
	{
		std::cout << "Fuel consumption for Airplane is: "
			<< distance * fuel_consumption << std::endl;
	}
	void virtual Show()  // виртуальный метод Вывод, переопределен для класса Самолет
	{
		std::cout << "Characteristics for Airplane: \n"
			<< "-distance: " << distance;
	}
};

class Ship : public Vehicle  // класс Судно, дочерний от Транспортное средство  
{
	float distance;  // пройденная дистанция
public:
	Ship() : distance{ 0 } {}
	Ship(float fuel_cons, float dist)
		: Vehicle{ fuel_cons }, distance{ dist } {}

	void virtual Consumption()  // виртуальный метод Расход топлива, переопределен для класса Судно
	{
		std::cout << "Fuel consumption for Ship is: "
			<< distance * fuel_consumption << std::endl;
	}
	void virtual Show()  // виртуальный метод Вывод, переопределен для класса Судно
	{
		std::cout << "Characteristics for Ship: \n"
			<< "-distance: " << distance;
	}
};

class Truck : public Vehicle  // класс Грузовик, дочерний от Транспортное средство  
{
	float distance;  // пройденная дистанция
public:
	Truck() : distance{ 0 } {}
	Truck(float fuel_cons, float dist)
		: Vehicle{ fuel_cons }, distance{ dist } {}

	void virtual Consumption()  // виртуальный метод Расход топлива, переопределен для класса Грузовик
	{
		std::cout << "Fuel consumption for Truck is: "
			<< distance * fuel_consumption << std::endl;
	}
	void virtual Show()  // виртуальный метод Вывод, переопределен для класса Грузовик
	{
		std::cout << "Characteristics for Truck: \n"
			<< "-distance: " << distance;
	}
};

class Bicycle : public Vehicle  // класс Велосипед, дочерний от Транспортное средство  
{
	float distance;  // пройденная дистанция
public:
	Bicycle() : distance{0} {}
	Bicycle(float fuel_cons, float dist)
		: Vehicle{fuel_cons }, distance{ dist } {}

	void virtual Consumption()  // виртуальный метод Расход топлива, переопределен для класса Велосипед
	{
		std::cout << "No fuel consumption for Bicycle\n"
			 << std::endl;
	}
	void virtual Show()  // виртуальный метод Вывод, переопределен для класса Велосипед
	{
		std::cout << "Characteristics for Bicycle: \n"
			<< "-distance: " << distance;
	}
};

class Car : public Vehicle  // класс Автомобиль, дочерний от Транспортное средство  
{
	float distance;  // пройденная дистанция
public:
	Car() : distance{ 0 } {}
	Car(float fuel_cons, float dist)
		: Vehicle{ fuel_cons }, distance{ dist } {}

	void virtual Consumption()  // виртуальный метод Расход топлива, переопределен для класса Автомобиль
	{
		std::cout << "Fuel consumption for Car is: "
			<< distance * fuel_consumption << std::endl;
	}
	void virtual Show()  // виртуальный метод Вывод, переопределен для класса Автомобиль
	{
		std::cout << "Characteristics for Car: \n"
			<< "-distance: " << distance;
	}
};

int main()
{
	Vehicle* obj_vehicle = nullptr;  // создали указатель на базовый класс

	std::cout << "1. Airplane" << std::endl;
	std::cout << "2. Ship" << std::endl;
	std::cout << "3. Truck" << std::endl;
	std::cout << "4. Bicycle" << std::endl;
	std::cout << "5. Car" << std::endl;
	std::cout << "Make your choice: ";

	int choice{ 0 };
	std::cin >> choice;  // выбор пользователя

	// HELP HELP HELP
	// Подскажите, свич ниже закомментированный - тоже работает,
	// и следующий свич со ссылками тоже работает. Правильный со ссылками?
	// А тот, что закомментирован, тоже ведь можно?
	// 
	//switch (choice)
	//{
	//	case 1:
	//		obj_vehicle = new Airplane(10, 50);
	//		break;
	//	case 2:
	//		obj_vehicle = new Ship(20, 10);
	//		break;
	//	case 3:
	//		obj_vehicle = new Truck(10, 40);
	//		break;
	//	case 4:
	//		obj_vehicle = new Bicycle(0, 30);
	//		break;
	//	case 5:
	//		obj_vehicle = new Car(12, 100);
	//		break;
	//}
	//obj_vehicle->Consumption();
	//obj_vehicle->Show();

	switch (choice)
	{
		case 1: 
		{
			Airplane obj_air(10, 50);  // создали объект типа Airplane
			obj_vehicle = &obj_air;    // присваиваем указателю на базовый класс адрес объекта типа Airplane
			break;
		}
		case 2:
		{
			Ship obj_ship(20, 10);     // создали объект типа Ship
			obj_vehicle = &obj_ship;   // присваиваем указателю на базовый класс адрес объекта типа Ship
			break;
		}
		case 3:
		{
			Truck obj_truck(10, 40);    // создали объект типа Truck
			obj_vehicle = &obj_truck;	// присваиваем указателю на базовый класс адрес объекта типа Truck
			break;
		}
		case 4:
		{
			Bicycle obj_bscl(0, 30);    // создали объект типа Bicycle
			obj_vehicle = &obj_bscl;	// присваиваем указателю на базовый класс адрес объекта типа Bicycle
			break;
		}
		case 5:
		{
			Car obj_car(12, 100);       // создали объект типа Car
			obj_vehicle = &obj_car;		// присваиваем указателю на базовый класс адрес объекта типа Car
			break;
		}
	}
	obj_vehicle->Consumption();  // вызов метода Расход топлива соответственного (выбранного в свич) класса
	obj_vehicle->Show();         // вызов метода Вывод соответственного (выбранного в свич) класса

	return 0;
}

