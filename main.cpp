#include <View/MainWindow.h>
#include <QApplication>
#include <ViewModel/CreatorProvider.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CreatorProvider p;

    return a.exec();
}
