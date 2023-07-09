#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
private:

    void    setActionsForToolButton();
    void    createSelectionPopMenu();
    
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    

private slots:
 
    void on_chkBoxListEditable_clicked(bool checked);   //chkBoxListEditable单击事件
 
    void on_ListWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);   //当前选择项发生变化
 
    void on_ListWidget_customContextMenuRequested(const QPoint &pos);   //弹出菜单
 
    void on_toolBox_currentChanged(int index); //ToolBox当前组变化时，显示TabWidget相应的页面
 
    void on_actSelALL_triggered(); //全选
 
    void on_actSelNone_triggered();//全不选
 
    void on_actSelInvs_triggered();//反选
    
    void on_actListAppend_triggered();  //添加项
    
    void on_actListClear_triggered();   //清除项
    
    void on_actListInsert_triggered();   //插入项 
    
    void on_actListIni_triggered();    //   初始化项
    
    void on_actListDelete_triggered();     //删除当前项
    
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
