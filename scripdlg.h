#ifndef SCRIPDLG_H
#define SCRIPDLG_H
#include<QDialog>
#include <QWidget>
#include<QPushButton>
#include<QLabel>
#include<QTextEdit>
class scripDlg : public QDialog
{
       Q_OBJECT
public:
    bool islogin;
    scripDlg();
    QString SQL;
private:
    QLabel *label0;
    QTextEdit *textEditSQL;
    QPushButton *okBtn,*cancelBtn;
private slots:
    void okBtnOnclick();
    void cancelBtnOnclick();

};

#endif // SCRIPDLG_H
