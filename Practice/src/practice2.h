#include "vector.h"
#include <string>
#include "queue.h"
#include "stack.h"
#include "tokenscanner.h"
#include "map.h"
#include "set.h"
#include <cctype>

using namespace std;

//VECTORS-------------------------------------------------------------


//QUEUES------------------------------------------------------------------

void ReverseQueue(Queue<int> & q);

//SCANNER & STACK---------------------------------------------------------------

bool isCorrectlyNested(string htmlStr);

//Map--------------------------------------------------------------------------

char MostFrequentCharacter(ifstream & in, int & numOccurrences);
