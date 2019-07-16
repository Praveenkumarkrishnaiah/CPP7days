#include <iostream>
using namespace std;

// -------------- Initial design -------------
struct IWindow { virtual void draw() = 0; };
struct MSWindow : IWindow { void draw() { cout << " MS Window drawn" << endl; } };
struct LinuxWindow : IWindow { void draw() { cout << " Linux Window drawn" << endl; } };

struct IStatusBar { virtual void draw() = 0; };
struct MSStatusBar : IStatusBar { void draw() { cout << " MS StatusBar drawn" << endl; } };
struct LinuxStatusBar : IStatusBar { void draw() { cout << " Linux StatusBar drawn" << endl; } };

struct ITaskBar { virtual void draw() = 0; };
struct MSTaskBar : ITaskBar { void draw() { cout << " MS TaskBar drawn" << endl; } };
struct LinuxTaskBar : ITaskBar { void draw() { cout << " Linux TaskBar drawn" << endl; } };

// ----------- Abstract Factory -----------

struct IFactory {
	virtual IWindow *createWindow() = 0;
	virtual IStatusBar* createStatusBar() = 0;
	virtual ITaskBar *createTaskBar() = 0;
};

struct MSFactory : IFactory {
	virtual IWindow *createWindow() {		return new MSWindow();	}
	virtual IStatusBar* createStatusBar() { return new MSStatusBar(); }
	virtual ITaskBar *createTaskBar() { return new MSTaskBar(); }
};

struct LinuxFactory : IFactory {
	virtual IWindow *createWindow() { return new LinuxWindow(); }
	virtual IStatusBar* createStatusBar() { return new LinuxStatusBar(); }
	virtual ITaskBar *createTaskBar() { return new LinuxTaskBar(); }
};

// ----------- Application -----------------
void gfun(IFactory *fp) {
	IWindow *wp = fp->createWindow();
	wp->draw();

	IStatusBar *sp = fp->createStatusBar();
	sp->draw();

	ITaskBar *tp = fp->createTaskBar();
	tp->draw();
}

int main() {
	IFactory *fp = new LinuxFactory();
	gfun(fp);

	fp = new MSFactory();
	gfun(fp);
}






