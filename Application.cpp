#include "Application.h"

Application::Application(int argc, char *argv[]):
    a(argc, argv)
{
    QGuiApplication::setApplicationDisplayName(MainWindow::tr("Image Processor"));
    commandLineParser.addHelpOption();
    commandLineParser.addPositionalArgument(MainWindow::tr("[file]"), MainWindow::tr("Image file to open."));
    commandLineParser.process(QCoreApplication::arguments());
}

int Application::run(){
    if (!commandLineParser.positionalArguments().isEmpty()
        && !w.loadFile(commandLineParser.positionalArguments().front())) {
        return -1;
    }
    w.show();
    return a.exec();
}
