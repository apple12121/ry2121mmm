#include "mainwindow.h"
#include "ui_mainwindow.h"
#include    <QMenu>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createSelectionPopMenu();
    setActionsForToolButton();
    //ui->ListWidget->setContextMenuPolicy(Qt::CustomContextMenu);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createSelectionPopMenu()
{
//创建下拉菜单
    QMenu* menuSelection=new QMenu(this); //创建选择弹出式菜单
    menuSelection->addAction(ui->actSelALL);
    menuSelection->addAction(ui->actSelNone);
    menuSelection->addAction(ui->actSelInvs);
    
//ListWidget上方的tBtnSelectItem按钮
    ui->tBtnSelectItem->setPopupMode(QToolButton::MenuButtonPopup);//菜单弹出模式，执行按钮的Action
    ui->tBtnSelectItem->setToolButtonStyle(Qt::ToolButtonTextBesideIcon); //按钮样式
    ui->tBtnSelectItem->setDefaultAction(ui->actSelPopMenu);//关联Action
    ui->tBtnSelectItem->setMenu(menuSelection); //设置下拉菜单
     
//工具栏上的 下拉式菜单按钮
    QToolButton  *aBtn=new QToolButton(this);
    aBtn->setPopupMode(QToolButton::InstantPopup);
    aBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);//按钮样式
    aBtn->setDefaultAction(ui->actSelPopMenu); //获取图标、标题等设置
    aBtn->setMenu(menuSelection);//设置下拉菜单
    ui->toolBar->addWidget(aBtn); //工具栏添加按钮
    ui->toolBar->addSeparator();
    ui->toolBar->addAction(ui->actQuit);
}
    

void MainWindow::setActionsForToolButton()
{//为QToolButton按钮设置Action（参数）
    ui->tBtnListIni_2->setDefaultAction(ui->actListIni);
    ui->tBtnListClear_2->setDefaultAction(ui->actListClear);
    ui->tBtnListInsert_2->setDefaultAction(ui->actListInsert);
    ui->tBtnListAppend_2->setDefaultAction(ui->actListAppend);
    ui->tBtnListDelete_2->setDefaultAction(ui->actListDelete);
 
    ui->tBtnSelAll->setDefaultAction(ui->actSelALL);
    ui->tBtnSelNone->setDefaultAction(ui->actSelNone);
    ui->tBtnSelInvs->setDefaultAction(ui->actSelInvs);
}

void MainWindow::on_actSelALL_triggered()
{ //项全选
    int cnt=ui->listWidget->count();//项个数
    for (int i=0; i<cnt; ++i)
    {
        QListWidgetItem *aItem=ui->listWidget->item(i);//获取一个项
        aItem->setCheckState(Qt::Checked);//设置为选中
    }
}
 
void MainWindow::on_actSelNone_triggered()
{ //全不选
    int i,cnt;
    QListWidgetItem *aItem;
 
    cnt=ui->listWidget->count();//项个数
    for (i=0; i<cnt; ++i)
    {
        aItem=ui->listWidget->item(i);//获取一个项
        aItem->setCheckState(Qt::Unchecked);//不选
    }
}

void MainWindow::on_actSelInvs_triggered()
{//反选
    int i,cnt;
    QListWidgetItem *aItem;
 
    cnt=ui->listWidget->count();//项个数
    for (i=0; i<cnt; ++i)
    {
        aItem=ui->listWidget->item(i);//获取一个项
        if (aItem->checkState()!=Qt::Checked)
            aItem->setCheckState(Qt::Checked);
        else
            aItem->setCheckState(Qt::Unchecked);
    }
 
}

//弹出菜单
void MainWindow::on_ListWidget_customContextMenuRequested(const QPoint &pos)
{
    Q_UNUSED(pos);
    QMenu* menuList=new QMenu(this); //创建指针菜单
 
  //添加Actions创建菜单项
    menuList->addAction(ui->actListIni);
    menuList->addAction(ui->actListClear);
    menuList->addAction(ui->actListInsert);
    menuList->addAction(ui->actListAppend);
    menuList->addAction(ui->actListDelete);
    menuList->addSeparator();
    menuList->addAction(ui->actSelALL);
    menuList->addAction(ui->actSelNone);
    menuList->addAction(ui->actSelInvs);
    
    menuList->exec(QCursor::pos());//在鼠标光标位置显示右键快捷菜单
    
    delete menuList; //删除创建指针
}

 //ToolBox当前组变化时，显示TabWidget相应的页面
void MainWindow::on_toolBox_currentChanged(int index)
{
    ui->tabWidget->setCurrentIndex(index);//ToolBox链接tabWidget
}

//chkBoxListEditable单击事件
void MainWindow::on_chkBoxListEditable_clicked(bool checked)
{
    int cnt=ui->listWidget->count();//项的个数
    QListWidgetItem *aItem;
    
    for (int i=0; i<cnt; ++i)
    {
        aItem=ui->listWidget->item(i);//获得一个项
        if (checked)
            aItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable |Qt::ItemIsUserCheckable |Qt::ItemIsEnabled);
        //通过枚举值设置aItem属性为可被选择，可被编辑，可被复选，可被使能
        else
            aItem->setFlags(Qt::ItemIsSelectable |Qt::ItemIsUserCheckable |Qt::ItemIsEnabled);
        //没有设置可被编辑属性
    }
 
}
 
//当前选择项发生变化
void MainWindow::on_ListWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
                                                  //QListWidgetItem *current表示当前项
                                                  //QListWidgetItem *previous表示前一项
                                                  //需要在头文件中加入<QListWidget>
{
  QString str;
  if (current != NULL) //看current变量指针是否为空
  {
    if (previous==NULL)  //看previous变量指针是否为空
      str="当前："+current->text();//获取当前项的文本
    else
      str="前一项："+previous->text()+"; 当前项："+current->text();//获取当前项和之前项的文本
    ui->lineEdit->setText(str);
  }
}


void MainWindow::on_actListAppend_triggered()
{//增加一个项
    
    QIcon aIcon;
    aIcon.addFile(":/images/images/check2.ico"); //设定图标
 
    bool chk=ui->checkBox->isChecked();//是否可编辑
 
    QListWidgetItem* aItem=new QListWidgetItem("New Added Item"); //创建一个Item
    aItem->setIcon(aIcon); //设置图标
    aItem->setCheckState(Qt::Checked); //设置为checked
    if (chk) //设置标志
        aItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable |Qt::ItemIsUserCheckable |Qt::ItemIsEnabled);
    else
        aItem->setFlags(Qt::ItemIsSelectable |Qt::ItemIsUserCheckable |Qt::ItemIsEnabled);
 
    ui->listWidget->addItem(aItem);//增加一个项
 
    
}

//清除项
void MainWindow::on_actListClear_triggered()
{
     ui->listWidget->clear(); 
}


void MainWindow::on_actListInsert_triggered()
{//插入一个项
    
    QIcon aIcon;
    aIcon.addFile(":/images/images/check2.ico"); //图标
 
    bool chk=ui->checkBox->isChecked();
 
    QListWidgetItem *aItem=new QListWidgetItem("New Inserted Item"); //创建一个项
    aItem->setIcon(aIcon);//设置图标
    aItem->setCheckState(Qt::Checked); //设置为checked
    if (chk) //设置标记
        aItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable |Qt::ItemIsUserCheckable |Qt::ItemIsEnabled);
    else
        aItem->setFlags(Qt::ItemIsSelectable |Qt::ItemIsUserCheckable |Qt::ItemIsEnabled);
 
    ui->listWidget->insertItem(ui->listWidget->currentRow(),aItem); //在当前行的上方插入一个项
 
    
}


//   初始化项
void MainWindow::on_actListIni_triggered()
{
    // 每一行是一个QListWidgetItem
    QListWidgetItem *aItem; 
 
    // 设置ICON的图标
    QIcon aIcon;
    aIcon.addFile(":/images/images/check2.ico"); 
    bool chk=ui->checkBox->isChecked();
 
    ui->listWidget->clear(); 
    for (int i=0; i<10; i++)
    {
        QString str=QString::asprintf("Item %d",i);
        aItem=new QListWidgetItem(); //新建一个项
 
        aItem->setText(str);//设置文字标签
        aItem->setIcon(aIcon);//设置文字图标
        aItem->setCheckState(Qt::Checked);// 设为选中状态
        if (chk)
            aItem->setFlags(Qt::ItemIsSelectable| Qt::ItemIsEditable |Qt::ItemIsUserCheckable |Qt::ItemIsEnabled);
        else
            aItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable |Qt::ItemIsEnabled);
        ui->listWidget->addItem(aItem); //增加项
    }
}


void MainWindow::on_actListDelete_triggered()
{ //删除当前项
    //    QListWidgetItem *aItem;
        int row=ui->listWidget->currentRow();//当前行
     
        QListWidgetItem* aItem=ui->listWidget->takeItem(row); //移除指定行的项，但不delete
        delete aItem; //需要手工删除对象
    
}

