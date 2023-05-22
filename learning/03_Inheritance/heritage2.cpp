#include <string>

class	Quadruped //Can access name, run() and legs
{
	private:
		std::string		name; //Only accessible from a Quadruped object
	
	protected:
		Leg				legs[4]; //Accessible from a Quadruped or derived object

	public:
		void			run(); //Accessible from wherever
};

class	Dog : public Quadruped // Can access run() and legs
{
};

int	main(void) // Can only access run()
{
}