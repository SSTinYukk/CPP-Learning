#include <cstdio>
#include <iostream>
using namespace std;

#include "workerManager.cpp"
//#include"employee.cpp"
#include "manager.cpp"
//#include "boss.cpp"

int main() {

  Worker *worker =NULL;
  worker = new Manager(1,"张三",1);
  worker->showInfo();
  // WorkerManager wm;
  // int choice = 0;
  // while (true) {
  //   //展示菜单
  //   wm.Show_Menu();
  //   cout << "请输入您的选择:" << endl;
  //   cin >> choice;

  //   switch (choice) {
  //   case 0: //退出系统
  //     wm.sys_exit();
  //     break;
  //   case 1: //添加职工
  //     break;
  //   case 2: //显示职工
  //     break;
  //   case 3: //删除职工
  //     break;
  //   case 4: //修改职工
  //     break;
  //   case 5: //查找职工
  //     break;
  //   case 6: //排序职工
  //     break;
  //   case 7: //清空文件
  //     break;
  //   default:
  //     cout<<"\033c";
  //     break;
  //   }
  // }

  return 0;
}
