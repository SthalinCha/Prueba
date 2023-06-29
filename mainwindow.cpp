#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "QDebug"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Lista de Tareas");
    // Configurar la tabla
    ui->tblLista->setColumnCount(3);
    QStringList titulo;
    titulo << "Descripción" << "Prioridad" << "Hecho";
    ui->tblLista->setHorizontalHeaderLabels(titulo);
    // Leer desde el archivo
    cargarContactos();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnAgregar_clicked()
{
    // Crear y mostrar el dialogo
    Dialog pd(this);
    pd.setWindowTitle("Agregar tarea");
    // Abrir la ventana y evaluar respuesta
    int res = pd.exec();
    if (res == QDialog::Rejected){
        return;
    }
    // Recuperar el objeto del cuadro de dialogo
    Tarea*p = pd.tarea();
    //Agregar a la tabla
    int fila = ui->tblLista->rowCount();
    ui->tblLista->insertRow(fila);
    ui->tblLista->setItem(fila, DESCRIPCION, new QTableWidgetItem(p->descripcion()));
    ui->tblLista->setItem(fila, PRIORIDAD, new QTableWidgetItem(p->prioridad()));
    ui->tblLista->setItem(fila, HECHO, new QTableWidgetItem(p->hecho()));


}


void MainWindow::on_btnGuardar_clicked()
{

    // Abrir el archivo y guardar
    int filas = ui->tblLista->rowCount();
    QFile archivo(ARCHIVO);
    if (archivo.open(QFile::WriteOnly | QFile::Truncate)) {
        QTextStream salida(&archivo);
        for (int i=0; i<filas; i++) {
            QTableWidgetItem *descripcion = ui->tblLista->item(i, DESCRIPCION);
            QTableWidgetItem *prioridad = ui->tblLista->item(i, PRIORIDAD);
            QTableWidgetItem *hecho = ui->tblLista->item(i, HECHO);

            salida << descripcion->text() << ";" << prioridad->text() << ";";
            salida << hecho->text() <<  "\n";
        }
        archivo.close();
        QMessageBox::information(this,"Guardar contactos","Contactos guardados con éxito");
    }else{
        QMessageBox::critical(this,"Guardar contactos", "No se puede escribir sobre " + ARCHIVO);
    }

}

void MainWindow::cargarContactos()
{
    // Verificar si el archivo existe
    QFile archivo(ARCHIVO);
    if (!archivo.exists())
        return;

    // cargar datos
    if (archivo.open(QFile::ReadOnly)) {
        QTextStream entrada(&archivo);
        int fila;
        while(!entrada.atEnd()){
            QString linea = entrada.readLine();
            QStringList datos = linea.split(";");
            //Agregar a la tabla
            fila = ui->tblLista->rowCount();
            ui->tblLista->insertRow(fila);
            ui->tblLista->setItem(fila, DESCRIPCION, new QTableWidgetItem(datos[DESCRIPCION]));
            ui->tblLista->setItem(fila, PRIORIDAD, new QTableWidgetItem(datos[PRIORIDAD]));
            ui->tblLista->setItem(fila, HECHO, new QTableWidgetItem(datos[HECHO]));

        }
        archivo.close();
    }
}

