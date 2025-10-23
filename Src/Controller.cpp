#include "Controller.hpp"

#include <QDebug>

Controller::Controller(QObject *parent) : QObject(parent) {
    m_universities = {"Boğaziçi", "İTÜ", "ODTÜ"};
    m_departments = {"Bilgisayar Mühendisliği", "Tıp", "Fizik"};
}

void Controller::selectUniversity(int index) {
    if (index >= 0 && index < m_universities.size())
        qDebug() << "Selected university:" << m_universities.at(index);
}

QStringList Controller::universities() const {
    return m_universities;
}

QStringList Controller::departments() const {
    return m_departments;
}
