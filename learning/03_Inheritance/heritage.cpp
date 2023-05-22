#include <string>

class Animal
{
	private:
		int		_numberOfLegs;

	public:
		Animal(void);
		Animal(Animal const &other);
		Animal &operator=(Animal const &other);
		~Animal(void);

	void		run(int distance);
};

class Cat : public Animal
{
	public:
		Cat(void);
		Cat(Cat const &other);
		Cat &operator=(Cat const &other);
		~Cat(void);

	void		scornSomeone(std::string const &target);
};

class Pony : public Animal
{
	public:
		Pony(void);
		Pony(Pony const &other);
		Pony &operator=(Pony const &other);
		~Pony(void);

	void		doMagic(std::string const &target);
	void		run(int distance); //Replace the Animal's run function
};