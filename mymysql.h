#ifndef MYMYSQL_H
#define MYMYSQL_H
#include<windows.h>
#include<C:/mysql/mysql-5.6.15-win32/include/mysql.h>
//#include<mysql/mysql.h>
//在设计c++程序的时候，切记，如果能使用类成员变量，就不要使用全局变量。linux下#include<mysql/mysql.h>
class mymysql
{
public:
    mymysql();
    //第一个函数代表Server IP 地址 第二个参数代表用户名，第三个代表密码，第四个代表默认登录使用数据库
    int sql_connect(const char *Hostname,const char *User,const char *Password,const char *DBName);
    void sql_disconnect();
    int sql_exec(const char *SQL);
    const char *geterror();

private:
    MYSQL *connection;
    MYSQL  mysql;
    char buf[1024];
};

#endif // MYMYSQL_H
