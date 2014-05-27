#include "dialog.h"
#include "ui_dialog.h"

#include "systemicons.h"

#include <QDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    setWindowTitle(tr("System Icon Test"));

    qDebug() << "Available icons sizes:";
    qDebug() << "Warning:" << SystemIcons::icon(SystemIcons::WarningIcon).availableSizes();
    qDebug() << "Error:" << SystemIcons::icon(SystemIcons::ErrorIcon).availableSizes();
    qDebug() << "Information:" << SystemIcons::icon(SystemIcons::InformationIcon).availableSizes();

    ui->warningIcon->setPixmap(SystemIcons::icon(SystemIcons::WarningIcon).pixmap(QSize(16,16)));
    ui->warningIconBig->setPixmap(SystemIcons::icon(SystemIcons::WarningIcon).pixmap(QSize(32,32)));
    ui->errorIcon->setPixmap(SystemIcons::icon(SystemIcons::ErrorIcon).pixmap(QSize(16,16)));
    ui->errorIconBig->setPixmap(SystemIcons::icon(SystemIcons::ErrorIcon).pixmap(QSize(32,32)));
    ui->informationIcon->setPixmap(SystemIcons::icon(SystemIcons::InformationIcon).pixmap(QSize(16,16)));
    ui->informationIconBig->setPixmap(SystemIcons::icon(SystemIcons::InformationIcon).pixmap(QSize(32,32)));

    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
}

Dialog::~Dialog()
{
    delete ui;
}
