#include "vector.h"
#include <string>
#include "queue.h"
#include "stack.h"
#include "tokenscanner.h"
#include "map.h"
#include "set.h"
#include <cctype>
#include <fstream>
#include "practice2.h"

using namespace std;

//VECTORS-------------------------------------------------------------


//QUEUES------------------------------------------------------------------

void ReverseQueue(Queue<int> & q) {
    Stack<int> s;
    while (!q.isEmpty()) {
        s.push(q.dequeue());
    }
    while (!s.isEmpty()) {
        q.enqueue(s.pop());
    }
}

//SCANNER & STACK---------------------------------------------------------------

bool isCorrectlyNested(string htmlStr) {
    TokenScanner scanner;
    scanner.addOperator(">");
    scanner.setInput(htmlStr);
    while (scanner.hasMoreTokens()) {
        cout << scanner.nextToken() << endl;
    }
    return true;
}

//Map--------------------------------------------------------------------------

char MostFrequentCharacter(ifstream & in, int & numOccurrences) {
    Map<string, int> charFreqMap;
    while (true) {
        char ch;
        in >> ch;
        if (in.fail()) break;

        if (isalpha(ch)) {
            ch = toupper(ch);
            cout << ch << endl;
        }
    }
    /*
     *while (true) {
        char ch;
        in >> ch;
        if (in.fail()) break;

        ch = tolower(ch);
        string str = "" + ch;
        cout << ch << endl;

        if (isalpha(ch) != 0) {
            if (charFreqMap.containsKey(str)) {
                charFreqMap[str]++;
            }
            else {
                charFreqMap.put(str, 0);
            }
            cout << str << ": " << charFreqMap[str] << endl;
        }
    }*/

    /*out << "testing" << endl;
    Vector<string> chars = charFreqMap.keys();
    cout << chars.size() << endl;
    string highestFreq = chars[0];
    for (int i = 1; i < chars.size(); i++) {
        cout << chars[i] << endl;
        if (charFreqMap[chars[i]] > charFreqMap[highestFreq]) {
            highestFreq = chars[i];
        }
    }*/
    return 'a';
}

