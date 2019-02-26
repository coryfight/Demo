#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"mymysql.h"
#include <QMainWindow>
#include<QMenu>
#include<QMenuBar>
#include<QAction>
#include<QCloseEvent>
#include<QMdiArea>

class MainWindow : public QMainWindow
{

Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void closeEvent(QCloseEvent *event);

private:
    mymysql db;
    void showview();
    void showsub();
    void createMenus();
    void createActions();
    /********菜单栏**********/
    QMenu *adminMenu;
    QMenu *dataMenu;
    QMenu *windowMenu;
    QMenu *helpMenu;

    QMdiArea *mdiArea;

    /********行为**********/
    QAction *loginAction;
    QAction *logoutAction;
    QAction *exitAction;

    QAction *scriptAction;

    QAction *cascadeAction;
    QAction *titleAction;

    QAction *helpAction;
    QAction *aboutAction;

private slots:
    void on_login();
    void on_logout();
    void on_exit();

    void on_script();

    void cascadeSubWindows();
    void titleSubWindows();

    void on_help();
    void on_about();
};

#endif // MAINWINDOW_H
