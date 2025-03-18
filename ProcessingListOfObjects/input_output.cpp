#include "input_output.h"

#include <QFileDialog>
#include <QMessageBox>

#include <iostream>

void Load(const QString& file_name, ManagerGroup& mg){
    QFile file(file_name);

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream input(&file);

        while(!input.atEnd()) {
            QString line = input.readLine();

            if (line.isEmpty()) {
                continue;
            }

            QStringList list = line.split(' ');

            if (list.size() != 5) {
                qDebug() << "Error in file: not 5 arguments in line";
                continue;
            }

            try{
                mg.AddToList(list[0].toStdString(), {list[1].toDouble(),
                                                     list[2].toDouble()}, list[3].toStdString(), list[4].toDouble());
            }catch (...) {
                //QDebug() << "Error conversion";
                continue;
            }
        }
    }
    file.close();
}

void PrintObj(const QString& file_name, const Object& obj) {
    QFile file(file_name);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << QString::fromStdString(obj.GetName())
            << obj.GetCoordinates().x_ << obj.GetCoordinates().y_
            <<QString::fromStdString(obj.GetType()) << obj.GetTime() << "\n";
    }
    file.close();
}

void PrintToFile(const QString& file_name, ManagerGroup& mg){
    QFile file(file_name);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        const auto& all_objects = mg.GetAllObjects();
        QTextStream out(&file);
        for (const auto& obj : all_objects) {
            out << QString::fromStdString(obj.GetName())
                << obj.GetCoordinates().x_ << obj.GetCoordinates().y_
                <<QString::fromStdString(obj.GetType()) << obj.GetTime() << "\n";
        }
    }
    file.close();
}

void SaveToFile(const QString& file_name, ManagerGroup& mg, const std::string& name_group, SortingCriteria crit){
    QFile file(file_name);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        if (mg.GetAllObjects().empty()) {
            return;
        }
        QTextStream output_file(&file);
        if (const auto& tmp_gr = mg.GetGroup(name_group); tmp_gr.GetNameGroup() != "" && tmp_gr.GetSubgroups().size() != 0) {
            output_file << "Сортировка: " << QString::fromStdString(name_group) << "\n";
            for (const auto& [name, subgroup] : tmp_gr.GetSubgroups()) {
                output_file << "Подгруппа: " << QString::fromStdString(name) << "\n";
                for (const auto& obj: subgroup.GetConstGroup()) {
                    std::cout << obj->GetName() << std::endl;
                    output_file << QString::fromStdString(obj->GetName())
                                << obj->GetCoordinates().x_ << obj->GetCoordinates().y_
                                <<QString::fromStdString(obj->GetType()) << obj->GetTime() << "\n";
                }
            }
            output_file << "\n";
        }
        else {
            mg.CreateGroup(crit);
            SaveToFile(file_name, mg, name_group, crit);
        }
    }
    file.close();
}
