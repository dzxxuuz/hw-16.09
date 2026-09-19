#include "Time.h"
#include <iostream>

using namespace std;

int main()
{
    Time t1;
    Time t2(10, 30, 45, false);

    cout << t1.toString() << " " << t2.toString() << endl;

    t1.tickTime();
    t2.untickTime();
    cout << t1.toString() << " " << t2.toString() << endl;

    cout << "-------------------------" << endl;

    cout << t1.toString() << " == " << t2.toString()
        << " = " << boolalpha << (t1 == t2) << endl;

    cout << t1.toString() << " != " << t2.toString()
        << " = " << boolalpha << (t1 != t2) << endl;

    cout << t1.toString() << " > " << t2.toString()
        << " = " << boolalpha << (t1 > t2) << endl;

    cout << t1.toString() << " < " << t2.toString()
        << " = " << boolalpha << (t1 < t2) << endl;

    cout << t1.toString() << " >= " << t2.toString()
        << " = " << boolalpha << (t1 >= t2) << endl;

    cout << t1.toString() << " <= " << t2.toString()
        << " = " << boolalpha << (t1 <= t2) << endl;

    cout << "-------------------------" << endl;

    cout << t2.toString() << " + 15 seconds = "
        << (t2 + 15.0f).toString() << endl;

    cout << t2.toString() << " + 15 minutes = "
        << (t2 + 15).toString() << endl;

    cout << t2.toString() << " + 15 hours = "
        << (t2 + 15L).toString() << endl;

    cout << "-------------------------" << endl;

    t2 += 15.0f;
    cout << "t2 after += 15 seconds: " << t2.toString() << endl;

    t2 += 15;
    cout << "t2 after += 15 minutes: " << t2.toString() << endl;

    t2 += 15L;
    cout << "t2 after += 15 hours: " << t2.toString() << endl;

    return 0;
}