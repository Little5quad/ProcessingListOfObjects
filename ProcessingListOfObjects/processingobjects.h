#ifndef PROCESSINGOBJECTS_H
#define PROCESSINGOBJECTS_H

#include <QMainWindow>

#include "group.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class ProcessingObjects;
}
QT_END_NAMESPACE

class ProcessingObjects : public QMainWindow
{
    Q_OBJECT

public:
    ProcessingObjects(QWidget *parent, ManagerGroup& mg);
    ~ProcessingObjects();

    bool CheckPath();

    void AddManagerGroup(ManagerGroup& mg);

private slots:
    void on_btn_new_file_clicked();

    void on_btn_save_distance_group_clicked();

    void on_btn_save_name_group_clicked();

    void on_btn_save_type_group_clicked();

    void on_btn_save_date_group_clicked();

    void on_btn_save_data_clicked();

private:
    Ui::ProcessingObjects *ui;
    ManagerGroup& mg_;
};
#endif // PROCESSINGOBJECTS_H
