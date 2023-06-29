#ifndef TAREA_H
#define TAREA_H

#include <QObject>

class Tarea : public QObject
{
    Q_OBJECT
public:
    explicit Tarea(QObject *parent = nullptr);
    Tarea(const QString &descripcion, const QString &prioridad, const QString &hecho);

    const QString &descripcion() const;
    const QString &prioridad() const;
    const QString &hecho() const;

    void setDescripcion(const QString &descripcion);  // Método para establecer la descripción
    void setPrioridad(const QString &prioridad);      // Método para establecer la prioridad
    void setHecho(const QString &hecho);              // Método para establecer el estado de hecho

signals:

private:
    QString m_descripcion;
    QString m_prioridad;
    QString m_hecho;
};

#endif // TAREA_H
