#include <iostream>
using namespace std;

/*
 also called as factory abstract pattern

 Abstract Factory patterns work around a super-factory which creates other factories.
 This factory is also called as factory of factories.
 This type of design pattern comes under creational pattern as this pattern provides one of the best ways to create an object.

 In Abstract Factory pattern an interface is responsible for creating a factory of related objects without explicitly specifying their classes.
 Each generated factory can give the objects as per the Factory pattern.

 By creating abstract classes, Author bounds its user to implement some functionalities.

 */

// Set of Abstract Classes/Implementations
class Button {
public:
	virtual void paint() = 0;
};

class ScrollBar {
public:
	virtual void paint() = 0;
};

class GUIFactory {
public:
	virtual Button* createButton() = 0;
	virtual ScrollBar* createScrollBar() = 0;
};

// --------------------- Above is abstract design of the logic -----

class WinButton: public Button {
public:
	void paint() {
		std::cout << " Window Button \n";
	}
};

class MacButton: public Button {
public:
	void paint() {
		std::cout << " Mac Button \n";
	}
};

class WinScrollBar: public ScrollBar {
public:
	void paint() {
		std::cout << " Window ScrollBar \n";
	}
};

class MacScrollBar: public ScrollBar {
public:
	void paint() {
		std::cout << " Mac ScrollBar \n";
	}
};

class WinFactory: public GUIFactory {
public:
	Button* createButton() {
		return new WinButton;
	}
	ScrollBar* createScrollBar() {
		return new WinScrollBar;
	}
};

class MacFactory: public GUIFactory {
public:
	Button* createButton() {
		return new MacButton;
	}
	ScrollBar* createScrollBar() {
		return new MacScrollBar;
	}
};

int main() {
	GUIFactory *guiFactory;
	Button *btn;
	ScrollBar *sb;

	guiFactory = new MacFactory;
	btn = guiFactory->createButton();
	btn->paint();
	sb = guiFactory->createScrollBar();
	sb->paint();

	guiFactory = new WinFactory;
	btn = guiFactory->createButton();
	btn->paint();
	sb = guiFactory->createScrollBar();
	sb->paint();

	return 0;
}
