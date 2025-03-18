#include <iostream>

class Human {
	private:
		std::string _name;
		int         _age;
	public:
		Human() : _name("Default Name"), _age(0) {
			std::cout << "Human Default Constructor Called!" << std::endl;
		}
		
		Human(const Human &other) : _name(other._name), _age(other._age) {
			std::cout << "Human Copy Constructor Called!" << std::endl;
		}

		Human(const std::string &name, int age) : _name(name), _age(age) {
			std::cout << "Human Parameterized Constructor Called!" << std::endl;
		}

		Human &operator=(const Human &other) {
			if (this != &other) {
				_name = other._name;
				_age = other._age;
			}
			std::cout << "Human Assignment Operator Called!" << std::endl;

			return (*this); //Required for chaining
		}

		const std::string &getName() const {
			return (_name);
		}
		int getAge() const {
			return (_age);
		}
};


int main() {
    Human h1("Mark", 42);
    Human h2("John", 30);

    h2 = h1;

    std::cout << h2.getName() << std::endl;
    std::cout << h2.getAge() << std::endl;

    return (0);
}