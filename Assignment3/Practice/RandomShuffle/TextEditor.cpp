#include <string>
#include <iostream>
#include <cctype>
#include <stdlib.h>
#include "simpio.h"
#include "buffer.h"
using namespace std;

void executeCmd(EditorBuffer &buffer, string cmd);

/*int main() {
	EditorBuffer buffer;
	while (true) {
		string cmd = getLine("*");
		executeCmd(buffer, cmd);
		buffer.showContent();
	}
	return 0;

}*/

void executeCmd(EditorBuffer &buffer, string cmd) {
	switch (toupper(cmd[0])) {
		case 'I': 
			for (int i = 1; i < cmd.length(); i++) {
				buffer.insertCharacter(cmd[i]);
			}
			break;
		case 'D': 
			if (cmd.length() > 1 && toupper(cmd[1]) == 'W') buffer.deleteWord();
			else buffer.deleteCharacter(); 
			break;
		case 'F': 
			if (cmd.length() > 1 && toupper(cmd[1]) == 'W') buffer.moveCursorForwardOneWord();
			else buffer.moveCursorForward(); 
			break;
		case 'B': 
			if (cmd.length() > 1 && toupper(cmd[1]) == 'W') buffer.moveCursorBackwardOneWord();
			else buffer.moveCursorBackward(); 
			break;
		case 'S': buffer.moveCursorToStart(); break;
		case 'E': buffer.moveCursorToEnd(); break;
		case 'C': 
			{
				string len = cmd.substr(1);
				int l = atoi(len.c_str());
				buffer.copy(l); 
			}
			break;
		case 'P': buffer.paste(); break;
		case 'Q': exit(0);
	}
}


