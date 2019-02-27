#include "scripdlg.h"
#include<QHBoxLayout>
#include<QGridLayout>
aaaa
scripDlg::scripDlg()
{
    islogin = false;
    label0 = new QLabel;
    label0->setText(tr("请输入SQL"));
    textEditSQL = new QTextEdit;
    okBtn = new QPushButton;
    okBtn->setText(tr("执行"));
    cancelBtn = new QPushButton;
    cancelBtn->setText(tr("取消"));

    QGridLayout *layout1 = new QGridLayout(this);
    layout1->addWidget(label0,0,0);
    layout1->addWidget(textEditSQL,0,1);
    QHBoxLayout *layout2 = new QHBoxLayout;

    layout2->addWidget(okBtn);
    layout2->addWidget(cancelBtn);

    layout1->addLayout(layout2,1,1);
    connect(okBtn,SIGNAL(clicked(bool)),this,SLOT(okBtnOnclick()));
    connect(cancelBtn,SIGNAL(clicked(bool)),this,SLOT(cancelBtnOnclick()));

}

void scripDlg::okBtnOnclick()
{
    islogin = true;
    SQL = textEditSQL->toPlainText();//TextEdit没有text函数，得到textedit当中用户的输入内容
    close();
}

void scripDlg::cancelBtnOnclick()
{
    close();
}
