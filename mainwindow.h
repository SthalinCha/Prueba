#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tarea.h"
#include "dialog.h"
#include <QWidget>
#include <QFile>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnAgregar_clicked();

    void on_btnGuardar_clicked();

private:
    Ui::MainWindow *ui;
    const QString ARCHIVO = "agenda.csv";
    enum Columna
    {
        DESCRIPCION, PRIORIDAD, HECHO
    };

    void cargarContactos();


};
#endif // MAINWINDOW_H

