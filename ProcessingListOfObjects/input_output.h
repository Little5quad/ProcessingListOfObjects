#pragma once

#include <string>
#include <QFile>
#include <QString>

#include "object.h"
#include "group.h"
#include "geo.h"
#include "comparator.h"

void Load(const QString& file_name, ManagerGroup& mg);

void PrintObj(const QString& file_name, const Object& obj);

void PrintToFile(const QString& file_name, ManagerGroup& mg);

void SaveToFile(const QString& file_name, ManagerGroup& mg, const std::string& name_group, SortingCriteria crit);
