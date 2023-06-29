#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "tarea.h"
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    Tarea *tarea() const;

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

    void on_buttonBox_2_accepted();

private:
    Ui::Dialog *ui;
    Tarea *m_tarea;
};

#endif // DIALOG_H
