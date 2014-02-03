#include "fluidgui.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	FluidGUI w;
	w.show();
	return a.exec();
}
