#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->webView->settings()->setAttribute(QWebSettings::LocalStorageEnabled, true);
    ui->webView->settings()->enablePersistentStorage(QDir::homePath());
    ui->webView->setUrl(QUrl("http://arenda.ligmar.ru:3000"));

    connect(ui->webView, SIGNAL(loadProgress(int)),ui->progressBar, SLOT(setValue(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->webView->setUrl(QUrl("http://arenda.ligmar.ru:3000"));
}
