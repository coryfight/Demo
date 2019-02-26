#include "mainwindow.h"
#include"logindlg.h"
#include"scripdlg.h"
#include<QMessageBox>
#include<QIcon>
#include<QMdiSubWindow>
#include<QStandardItemModel>
#include<QTableView>
#include"mymysql.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setWindowTitle(tr("CDMA无线基站管理系统"));//设置窗口标题
    mdiArea = new QMdiArea;
    setCentralWidget(mdiArea);
    mdiArea->setBackground(Qt::NoBrush);
    mdiArea->setStyleSheet("background-image: url(1.jpg);");//设置背景为1.jpg‘子窗口大小可调节
    //mdiArea->setStyleSheet("border-image: url(1.jpg);");
    mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);//当子窗口的范围超过父窗口的显示范围时，父窗口自动添加横向滚动条
    mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);//竖向的滚动条
    setWindowIcon(QIcon("main.png"));//设置窗口关标
    createActions();//创建行为函数
    createMenus();//创建菜单
}

MainWindow::~MainWindow()
{

}

void MainWindow::closeEvent(QCloseEvent *event)//CloseEvent函数是在widget退出之前自动调用的函数
{
    //通过question的返回值来判断用户到底点击的是yes还是no
     QMessageBox::StandardButton button = QMessageBox::question(this,"提示","是否退出程序",
                                                                QMessageBox::Yes | QMessageBox::No);
     if(button == QMessageBox::Yes)
     {
            event->accept();//接受退出
     }
     else
     {
           event->ignore();//不接受退出
     }

}

void MainWindow::showview()
{
    QStandardItemModel *model = new QStandardItemModel(5,3);//要建立一个五行三列的
    //设置model猎头的名称
    model->setHeaderData(0,Qt::Horizontal,"姓名");
    model->setHeaderData(1,Qt::Horizontal,"性别");
    model->setHeaderData(2,Qt::Horizontal,"年龄");
    //设置每一个单元的内容
    model->setData(model->index(0,0,QModelIndex()),"张三");
    model->setData(model->index(0,1,QModelIndex()),"李四");
    model->setData(model->index(2,0,QModelIndex()),"王麻子");
    QTableView *view1 = new QTableView;
    view1->setAttribute(Qt::WA_DeleteOnClose);
    mdiArea->addSubWindow(view1);
    view1->setModel(model);
    view1->setWindowTitle("SSSSS");
    view1->show();
    view1->setStyleSheet("border-image: url(4.jpg);");
    mdiArea->activeSubWindow()->resize(width()-100,height()-100);
}

void MainWindow::showsub()
{
    QWidget *w1 = new QWidget;
    w1->setAttribute(Qt::WA_DeleteOnClose);//代表关闭这个widget的时候，自动将这个widget delete
    mdiArea->addSubWindow(w1);
    w1->setWindowTitle("SSSSS");
    w1->setStyleSheet("background-image: url(3.jpg);");
    w1->show();
    mdiArea->activeSubWindow()->resize(width()-100,height()-100);
}
void MainWindow::createMenus()
{
    adminMenu = menuBar()->addMenu(tr("管理"));//添加管理菜单
    adminMenu->addAction(loginAction);
    adminMenu->addAction(logoutAction);
    adminMenu->addSeparator();//加入分隔符
    adminMenu->addAction(exitAction);

    dataMenu = menuBar()->addMenu(tr("数据"));//添加数据菜单
    dataMenu->addAction(scriptAction);

    windowMenu = menuBar()->addMenu(tr("窗口"));//添加窗口菜单
    windowMenu->addAction(cascadeAction);
    windowMenu->addAction(titleAction);

    helpMenu = menuBar()->addMenu(tr("帮助"));//添加帮助菜单
    helpMenu->addAction(helpAction);
    helpMenu->addSeparator();
    helpMenu->addAction(aboutAction);



}
void MainWindow::createActions()
{
   loginAction = new QAction(tr("登陆"),this);   //登陆行为
   loginAction->setShortcut(tr("Ctrl+U"));
   connect(loginAction,SIGNAL(triggered()),this,SLOT(on_login()));

   logoutAction = new QAction(tr("注销"),this);  //注销行为
   logoutAction->setShortcut(tr("Ctrl+B"));
   connect(logoutAction,SIGNAL(triggered()),this,SLOT(on_logout()));

   exitAction = new QAction(tr("退出"),this);  //退出行为
   exitAction->setShortcut(tr("Ctrl+W"));
   connect(exitAction,SIGNAL(triggered()),this,SLOT(on_exit()));

   scriptAction = new QAction(tr("执行脚本"),this);  //执行脚本行为
   scriptAction->setShortcut(tr("Ctrl+p"));
   scriptAction->setEnabled(false);// 设置执行脚本为不可用
   connect(scriptAction,SIGNAL(triggered()),this,SLOT(on_script()));

   cascadeAction = new QAction(tr("层叠"),this);
   cascadeAction->setShortcut(tr("Ctrl+Q"));
   connect(cascadeAction,SIGNAL(triggered()),this,SLOT(cascadeSubWindows()));

   titleAction = new QAction(tr("并列"),this);
   titleAction->setShortcut(tr("Ctrl+R"));
   connect(titleAction,SIGNAL(triggered()),this,SLOT(titleSubWindows()));

   helpAction = new QAction(tr("帮助"),this);
   helpAction->setShortcut(tr("Ctrl+S"));
   connect(helpAction,SIGNAL(triggered()),this,SLOT(on_help()));

   aboutAction = new QAction(tr("关于"),this);
   aboutAction->setShortcut(tr("Ctrl+T"));
   connect(aboutAction,SIGNAL(triggered()),this,SLOT(on_about()));
}
void MainWindow::on_login()//登陆行为函数
{

    loginDlg dlg;//将对话框实例化
    dlg.resize(300,200);
    dlg.exec();//调用exec产生一个模式对话框,程序在exec这里阻塞了
    //如何在这里知道用户名，密码IP等用户的信息呢？

    int res = db.sql_connect(dlg.hostip.toStdString().data()
                            ,dlg.userid.toStdString().data()
                            ,dlg.passwd.toStdString().data()
                            ,dlg.dbname.toStdString().data());
      if( res == -1)
       {
          QMessageBox::information(this,"","登录失败",db.geterror());
       }
     else
      {
       scriptAction->setEnabled(true);
       QMessageBox::information(this,"","登录成功");
      }

    /*if(dlg.islogin)//代表用户点击了dlg的对话框的登录按钮
    {
        if (dlg.userid == "abc" && dlg.passwd == "123456")
         {
          QMessageBox::information(this,"","登陆成功");
         }
         else
         {
          QMessageBox::information(this,"","登陆失败");
         }
    }*/
}
void MainWindow::on_logout()//注销行为函数
{
    //通过question的返回值来判断用户到底点击的是yes还是no
     QMessageBox::StandardButton button = QMessageBox::question(this,"提示","是否注销",
                                                                QMessageBox::Yes | QMessageBox::No);
     if(button == QMessageBox::Yes)
     {
             db.sql_disconnect();//接受退出
     }

}
void MainWindow::on_exit()//退出行为函数
{
    this->close();
}

void MainWindow::on_script()
{
    //showsub();
    //showview();
    scripDlg dlg;
    dlg.exec();
 if(dlg.islogin)
   {
   if( db.sql_exec(dlg.SQL.toStdString().data()) == -1)
   {
       QMessageBox::information(this,"执行失败",db.geterror());
   }
   else
   {
       QMessageBox::information(this,"提示","执行成功");
   }
 }
}

void MainWindow::cascadeSubWindows()
{
    mdiArea->cascadeSubWindows();
}

void MainWindow::titleSubWindows()
{
    mdiArea->tileSubWindows();
}

void MainWindow::on_help()
{
   QMessageBox::information(this,tr("帮助"),tr("自学成才"));
}

void MainWindow::on_about()
{
    QMessageBox::information(this,tr("关于"),tr("版权：中国电信\n作者：朱柯宇"));
}
