#include <iostream>

using namespace std;

int main() {

#ifdef FLAG_MACRO
    cout << "FLAG_MACRO defined" << endl;
#endif

#ifdef VALUE_MACRO
    cout << "VALUE_MACRO defined: " << VALUE_MACRO << endl;
#endif

#ifdef STRING_MACRO
    cout << "STRING_MACRO defined: " << STRING_MACRO << endl;
#endif

    return 0;
}
