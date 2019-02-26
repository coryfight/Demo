#include "logindlg.h"
#include<QGridLayout>
#include<QPixmap>
#include<QPalette>
#include<QMessageBox>
//loginDlg::loginDlg()

loginDlg::loginDlg(QWidget *parent) :
    QDialog(parent)
{
   islogin = false;//意味着islogin在对话框初始化的时候为false
   label0 = new QLabel;
   label0->setText(tr("用户名"));

   label1 = new QLabel;
   label1->setText(tr("密码"));

   label2 = new QLabel;
   label2->setText(tr("数据库名称"));

   label3 = new QLabel;
   label3->setText(tr("服务器IP"));

   lineEditUserID = new QLineEdit;
   lineEditPasswd = new QLineEdit;
   lineEditPasswd->setEchoMode(QLineEdit::Password);//设置密码框
   lineEditDBName = new QLineEdit;
   lineEditHostIP = new QLineEdit;

   loginBtn = new QPushButton;
   loginBtn->setText(tr("登陆"));
   logoutBtn = new QPushButton;
   logoutBtn->setText(tr("取消"));

   QGridLayout *layout1 = new QGridLayout(this); //指定dialog为父窗口
   layout1->addWidget(label0,0,0);
   layout1->addWidget(lineEditUserID,0,1);

   layout1->addWidget(label1,1,0);
   layout1->addWidget(lineEditPasswd,1,1);

   layout1->addWidget(label2,2,0);
   layout1->addWidget(lineEditDBName,2,1);

   layout1->addWidget(label3,3,0);
   layout1->addWidget(lineEditHostIP,3,1);

   layout1->addWidget(loginBtn,4,0);
   layout1->addWidget(logoutBtn,4,1);

   layout1->setColumnStretch(0,1);//设置0列宽度
   layout1->setColumnStretch(1,1);//设置1列宽度

   layout1->setMargin(15);//设置layout的边距
   layout1->setSpacing(10);//设置layout当中控件之间的间距
   layout1->setSizeConstraint(QLayout::SetFixedSize);//设置对话框大小不变

   setWindowTitle(tr("登陆"));
   this->setAutoFillBackground(true);
   QPalette palette;
   palette.setBrush(QPalette::Background,QBrush(QPixmap("2.jpg")));
   setPalette(palette);

   connect(loginBtn, SIGNAL(clicked()), this, SLOT(loginBtnOnclick()));
   connect(logoutBtn, SIGNAL(clicked()), this, SLOT(logoutBtnOnclick()));
}

void loginDlg::loginBtnOnclick()
{
    userid = lineEditUserID->text();
    passwd = lineEditPasswd->text();
    dbname = lineEditDBName->text();
    hostip = lineEditHostIP->text();
    islogin = true;//只有用户点击了确定按钮islogin的时候才为真
    close();

}

void loginDlg::logoutBtnOnclick()
{
      close();
}
