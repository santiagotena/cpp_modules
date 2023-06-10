int main() {
    int         a = 42;                         //Reference value

    int const   *b = &a;                        //Implicit promotion -> Ok
    int         *c = b;                         //Explicit demotion -> Not possible
    int         *d = const_cast<int *>(b);      //Explicit demotion -> Ok, it is possible

    return (0);
}