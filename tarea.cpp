#include "tarea.h"

Tarea::Tarea(QObject *parent)
    : QObject(parent)
{
}

Tarea::Tarea(const QString &descripcion, const QString &prioridad, const QString &hecho)
    : m_descripcion(descripcion), m_prioridad(prioridad), m_hecho(hecho)
{
}

const QString &Tarea::descripcion() const
{
    return m_descripcion;
}

const QString &Tarea::prioridad() const
{
    return m_prioridad;
}

const QString &Tarea::hecho() const
{
    return m_hecho;
}

void Tarea::setDescripcion(const QString &descripcion)
{
    m_descripcion = descripcion;
}

void Tarea::setPrioridad(const QString &prioridad)
{
    m_prioridad = prioridad;
}

void Tarea::setHecho(const QString &hecho)
{
    m_hecho = hecho;
}
