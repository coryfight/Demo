#include "mymysql.h"
//建立这个类的目的是实现封装，封装所有和mysql相关函数
#include<QMessageBox>
#include<string.h>
mymysql::mymysql()
{
   mysql_init(&mysql);
   connection = NULL;
   memset(buf,0,sizeof(buf));

}

int mymysql::sql_connect(const char *Hostname, const char *User, const char *Password, const char *DBName)
{
    connection = mysql_real_connect(&mysql,Hostname,User,Password,DBName,0,0,0);
    if(connection == NULL)
    {
        memset(buf,0,sizeof(buf));
        strcpy(buf,mysql_error(&mysql));
        //QMessageBox::information(0,"",mysql_error(&mysql));
        return -1;
    }
    else
    {
        mysql_query(connection,"set names utf8");
        return 0;
    }

}

void mymysql::sql_disconnect()
{
    if(connection == NULL)
    {
        mysql_close(connection);//断开链接置空
        connection = NULL;
    }
}

int mymysql::sql_exec(const char *SQL)
{
    int state = mysql_query(connection,SQL);
    if(state !=0 )
    {
        memset(buf,0,sizeof(buf));
        strcpy(buf,mysql_error(&mysql));
        return -1;
    }
    return 0;
}

const char *mymysql::geterror()
{
    return buf;
}
