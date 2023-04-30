#pragma once
#include "Users.h"
using namespace std;

//进入商品管理界面
bool Sales_item(User& u);

//进入用户界面
void User_item();

//进入编辑用户设置界面
bool User_edit(User &u);

//检测文件是否完全，如没有文件，则创建空文件
void checkFile();
