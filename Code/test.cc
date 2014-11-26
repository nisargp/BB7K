#include <map>
#include <iostream>
#include <string>

using namespace std;

int main() {
	string s = "II";
    int length = s.length();
    s = s.substr (0, length - 1);
    cout << length << s << endl;
}

