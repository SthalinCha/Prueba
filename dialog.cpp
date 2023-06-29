#include "dialog.h"
#include "ui_dialog.h"



Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_buttonBox_accepted()
{


    QString descripcion = ui->descripcion->text();

    QString prioridad = ui->prioridad->text();
    QString hecho = ui->hecho->text();  // Verificar si el texto es "true" (ignorando mayúsculas y minúsculas)

    this->m_tarea = new Tarea(descripcion, prioridad, hecho);
    accept();
}



void Dialog::on_buttonBox_rejected()
{
    reject();
}

Tarea *Dialog::tarea() const
{
    return m_tarea;
}


void Dialog::on_buttonBox_2_accepted()
{
    QString descripcion = ui->descripcion->text();

    QString prioridad = ui->prioridad->text();
    QString hecho = ui->hecho->text();

    this->m_tarea = new Tarea(descripcion, prioridad, hecho);
    accept();
}

