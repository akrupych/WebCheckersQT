#include <QtGui/QApplication>
#include "dialog.h"
#include <string>

using namespace std;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    try
    {

    Dialog w;

    w.show();

    return a.exec();
    }

    catch(string exp)
    {
        string oioi = exp;
        int y = 8;

    }


}
