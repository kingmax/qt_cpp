#pragma once

#include <QtWidgets/QWidget>
#include "ui_qtgui.h"

class qtGui : public QWidget
{
    Q_OBJECT

public:
    qtGui(QWidget *parent = Q_NULLPTR);

private:
    Ui::qtGuiClass ui;
};
