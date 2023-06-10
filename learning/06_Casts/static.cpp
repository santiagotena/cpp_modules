int main(void) {
    int     a = 42;                     //Reference value

    double  b = a;                      //Implicit promotion -> Ok
//    int     c = b;                      //Implicit promotion -> Not allowed
    int     d = static_cast<int>(b);    //Explicit demotion -> Ok, it is possible

    return (0);
}
