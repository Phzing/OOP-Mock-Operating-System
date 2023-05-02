#include <iostream>
#include <string>
#include "mockos/SimpleFileSystem.h"
#include "mockos/SimpleFileFactory.h"
#include "mockos/TouchCommand.h"
#include "mockos/RemoveCommand.h"
#include "mockos/LSCommand.h"
#include "mockos/CommandPrompt.h"

using namespace std;

int main(int argc, char* argv[]) {
    SimpleFileSystem fileSystem;
    SimpleFileFactory fileFactory;
    AbstractCommand* touchComm = new TouchCommand(&fileSystem, &fileFactory);
    AbstractCommand* removeCommand = new RemoveCommand(&fileSystem);
    AbstractCommand* lsCommand = new LSCommand(&fileSystem);
    CommandPrompt* cmdPrompt = new CommandPrompt();
    cmdPrompt->setFileSystem(&fileSystem);
    cmdPrompt->setFileFactory(&fileFactory);
    cmdPrompt->addCommand("touch", touchComm);
    cmdPrompt->addCommand("rm", removeCommand);
    cmdPrompt->addCommand("ls", lsCommand);
    cmdPrompt->run();
    return 0;
}