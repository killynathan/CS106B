#include <iostream>
#include "console.h"
#include "vector.h"  // for Vector
#include <fstream>
#include <string>
#include <ctype.h>
#include "queue.h"
#include <cctype>

#include "practice2.h"
using namespace std;


int main() {
    ifstream in("readme.txt");


    int test;
    MostFrequentCharacter(in, test);
    return 0;
}
