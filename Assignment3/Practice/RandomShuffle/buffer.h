class EditorBuffer {
public:
	EditorBuffer();

	~EditorBuffer();

	void moveCursorForward();

	void moveCursorForwardOneWord();

	void moveCursorBackward();

	void moveCursorBackwardOneWord();

	void moveCursorToStart();

	void moveCursorToEnd();

	void insertCharacter(char ch);

	void deleteCharacter();

	void deleteWord();

	void copy(int count);

	void paste();

	void showContent();

#include "bufferpriv.h"
};