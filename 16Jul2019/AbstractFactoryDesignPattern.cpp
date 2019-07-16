#include <iostream>
using namespace std;

struct IWindow {	virtual void draw() = 0; };
struct MSWindow : IWindow { void draw() { cout << " MS Window drawn" << endl; } };
struct LinuxWindow : IWindow { void draw() { cout << " Linux Window drawn" << endl; } };

struct IStatusBar { virtual void draw() = 0; };
struct MSStatusBar : IStatusBar { void draw() { cout << " MS StatusBar drawn" << endl; } };
struct LinuxStatusBar : IStatusBar { void draw() { cout << " Linux StatusBar drawn" << endl; } };

struct ITaskBar { virtual void draw() = 0; };
struct MSTaskBar : ITaskBar { void draw() { cout << " MS TaskBar drawn" << endl; } };
struct LinuxTaskBar : ITaskBar { void draw() { cout << " Linux TaskBar drawn" << endl; } };

// ----------- Application -----------------
int main() {
	IWindow *wp = new MSWindow(); // new LinuxWindow()
	wp->draw();

	IStatusBar *sp = new  LinuxStatusBar();
	sp->draw();

	ITaskBar *tp = new MSTaskBar(); // new LinuxTaskBar();
	tp->draw();
}






