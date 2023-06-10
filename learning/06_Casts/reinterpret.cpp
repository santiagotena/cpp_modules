int main() {
    float   a = 420.042f;                       //Reference value

    void    *b = &a;                            //Implicit promotion -> Ok
    int     *c = reinterpret_cast<int *>(b);    //Explicit demotion -> Ok, it is possible
    int     &d = reinterpret_cast<int &>(b);    //Explicit demotion -> Ok, it is possible

    return (0);
}