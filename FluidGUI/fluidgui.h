#ifndef FLUIDGUI_H
#define FLUIDGUI_H

#include <QtWidgets/QWidget>
#include "ui_fluidgui.h"

class FluidGUI : public QWidget
{
	Q_OBJECT

public:
	FluidGUI(QWidget *parent = 0);
	~FluidGUI();

private:
	Ui::FluidGUIClass ui;
};

#endif // FLUIDGUI_H
