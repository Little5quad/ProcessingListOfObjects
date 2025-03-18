#include "processingobjects.h"
#include "./ui_processingobjects.h"
#include "input_output.h"

#include <QFileDialog>
#include <QMessageBox>

ProcessingObjects::ProcessingObjects(QWidget *parent, ManagerGroup& mg)
    : QMainWindow(parent)
    , ui(new Ui::ProcessingObjects), mg_(mg)
{
    ui->setupUi(this);
}

ProcessingObjects::~ProcessingObjects()
{
    delete ui;
}

void ProcessingObjects::on_btn_new_file_clicked(){
    mg_.Clear();
    if (CheckPath()){
        Load(ui->le_name_file->text(), mg_);
        QMessageBox::information(this, tr("Успех"), tr("Файл принят"));
    }
    ui->le_name_file->clear();
}


void ProcessingObjects::on_btn_save_distance_group_clicked(){
    if (CheckPath()) {
        //mg_.CreateGroup(SortingCriteria::Distance);
        SaveToFile(ui->le_name_file_2->text(), mg_, "По расстоянию", SortingCriteria::Distance);
    }
    ui->le_name_file_2->clear();
}

void ProcessingObjects::AddManagerGroup(ManagerGroup& mg){
    mg_ = mg;
}

bool ProcessingObjects::CheckPath(){
    QString tmp = ui->le_name_file->text();
    if (!tmp.isEmpty()) {
        if (QFileInfo fileInfo(tmp); fileInfo.suffix() == "txt") {
            return true;
        }
        else {
            QMessageBox::warning(this, tr("Ошибка"), tr("Выбранный файл не является текстовым файлом (.txt)"));
        }
    }

    return false;
}


void ProcessingObjects::on_btn_save_name_group_clicked() {
    if (CheckPath()) {
        SaveToFile(ui->le_name_file_2->text(), mg_, "По имени", SortingCriteria::Name);
    }
    ui->le_name_file_2->clear();

}


void ProcessingObjects::on_btn_save_type_group_clicked() {
    if (CheckPath()) {
        SaveToFile(ui->le_name_file_2->text(), mg_, "По типу", SortingCriteria::Type);
    }
    ui->le_name_file_2->clear();
}


void ProcessingObjects::on_btn_save_date_group_clicked() {
    if (CheckPath()) {
        SaveToFile(ui->le_name_file_2->text(), mg_, "По дате", SortingCriteria::Date);
    }
    ui->le_name_file_2->clear();
}


void ProcessingObjects::on_btn_save_data_clicked()
{
    PrintToFile(ui->le_name_file_2->text(), mg_);
    ui->le_name_file_2->clear();
}

