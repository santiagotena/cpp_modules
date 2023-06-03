#include <stdexcept>

void test1()
{
    try
    {
        //Do some stuff here
        if (/* there is an error */)
        {
            throw std::exception();
        }
        else
        {
            //Do more stuff
        }
    }
    catch (std::exception e)
    {
        //Handle the error here
    }
}

void test2()
{
    //Do some stuff here
    if (/* there is an error */)
    {
        throw std::exception();
    }
    else
    {
        //Do more stuff
    }
}

void test3()
{
    try
    {
        test2();
    }
    catch (std::exception &e)
    {
        //Handle error
    }
}

void test4()
{
    class PEBKACException : public std::exception
    {
        public:
            virtual const char *what() const throw()
            {
                return ("Problem exists between keyboard and chair");
            }
    };

    try
    {
        test3();
    }
    catch (PEBKACException &e)
    {
        //Handle the exception form the class above
    }
    catch (std::exception &e)
    {
        //Handle other exceptoions that are like std::exception
    }
}
