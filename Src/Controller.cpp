#include "Controller.hpp"
#include <QDebug>

Controller::Controller(QObject *parent) : QObject(parent), backEnd(nullptr) {
}

void Controller::setUniversity(QString university) {
    parameters.universityName = university;
    qDebug() << "Selected university:" << university;
    updateUniversityTable();
}

void Controller::setDepartment(QString department) {
    parameters.departmentName = department;
    qDebug() << "Selected department:" << department;
    updateUniversityTable();
}

void Controller::updateUniversityTable() {

}

QStringList Controller::universities() const {
    QList<University> universities = backEnd.getUniversities();
    QStringList output;
    for(University &university : universities) {
        output.push_back(university.name);
    }
    return output;
}

QStringList Controller::departments() const {
    return backEnd.getDepartments();
}
