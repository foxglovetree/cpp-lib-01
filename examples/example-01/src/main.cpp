#include <fgt/util.h>
#include <iostream>
using namespace fgt::util;
using namespace std;
int main()
{
    String str("Hello, World!");
    cout << str.text() << endl;
    return 0;
}