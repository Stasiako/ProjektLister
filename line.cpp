#include "line.h"

line::line(int lineNumber) {
	next = 0;
	this->lineNumber = lineNumber;
}

void line::clear() {
	if (this->next != 0) {
		this->next->clear();
	}
	delete(this->next);
}