#include <iostream>
#include "console.h"
#include "simpio.h"  // for getLine
#include "vector.h"  // for Vector
#include <fstream>
#include <string>
#include <map.h>
#include <vector.h>
#include "strlib.h"
#include "random.h"
using namespace std;

void getFile(ifstream& in);

int getOrder();

string readFileIntoString(ifstream & in);

void mapSequences(string str, Map<string, Vector<char> >& map, int order);

string getMostFrequentSequence(Map<string, Vector<char> >& map);

string generateText(string startingStr, Map<string, Vector<char> >& map, int order);

int main() {
    Map<string, Vector<char> > map;
    int order;
    ifstream in;

    cout << "Welcome to the Markov Text Generator" << endl;
    getFile(in);
    order = getOrder();

    string fileString = readFileIntoString(in);

    mapSequences(fileString, map, order);

    /*Vector<string> keys = map.keys();
    for (int i = 0; i < keys.size(); i++) {
        cout << keys[i] << ": " << map[keys[i]] << endl;
    }*/

    string maxSeq = getMostFrequentSequence(map);
    //cout << maxSeq << endl;

    string result = generateText(maxSeq, map, order);
    cout << result;
    return 0;

}

void getFile(ifstream & in) {
    while (true) {
        string fileName = getLine("Please enter a text file: ");
        in.open(fileName);
        if (!in.fail()) break;
    }
}

int getOrder() {
    int order;
    while (true) {
        order = getInteger("Please enter the order of analysis (1 - 10): ");
        if (order >= 1 && order <= 10) {
            break;
        }
    }
    return order;
}

string readFileIntoString(ifstream& in) {
    string result = "";
    while (true) {
        string line;
        getLine(in, line);
        if (in.fail()) {
            break;
        }
        line = toLowerCase(line);
        result += line;
    }
    return result;
}

void mapSequences(string str, Map<string, Vector<char> >& map, int order) {
    for (int i = 0; (i + order) < str.length(); i++) {
        string key = str.substr(i, order);
        char value = str[i + order];
        if (map.containsKey(key)) {
            map[key].add(value);
        }
        else {
            map[key] = Vector<char>(1, value);
        }
    }
}

string getMostFrequentSequence(Map<string, Vector<char> >& map) {
    Vector<string> keys = map.keys();
    string maxKey = keys[0];
    for (int i = 1; i < keys.size(); i++){
        if (map[keys[i]].size() > map[maxKey].size()) {
            maxKey = keys[i];
        }
    }
    return maxKey;
}

string generateText(string startingStr, Map<string, Vector<char> >& map, int order) {
    string result = startingStr;
    int seed = 0;
    string key = startingStr;

    for(int i = startingStr.length(); i <= 10000; i++) {
        if(!map.containsKey(key)) {
            break;
        }
        else {
            int randomCharPos = randomInteger(0, map[key].size() - 1);
            result += map[key].get(randomCharPos);
            seed++;
            key =  result.substr(seed, order);
        }
    }
    return result;
}
