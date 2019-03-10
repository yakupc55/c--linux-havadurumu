#ifndef LOGIN_H
#define LOGIN_H

#include <QtCore/qglobal.h>

class login
{
public:
  login();
private:
  Ui::Login *ui;
  QSqlDatabase db;
};

#endif // LOGIN_H
