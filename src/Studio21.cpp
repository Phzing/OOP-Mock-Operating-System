#include <iostream>
#include <string>
#include "mockos/SimpleFileSystem.h"
#include "mockos/SimpleFileFactory.h"
#include "mockos/TouchCommand.h"
#include "mockos/CommandPrompt.h"

using namespace std;

int main(int argc, char* argv[]) {
	SimpleFileSystem fileSystem;
	SimpleFileFactory fileFactory;
	AbstractCommand* touchComm = new TouchCommand(&fileSystem, &fileFactory);
	CommandPrompt* cmdPrompt = new CommandPrompt();
	cmdPrompt->setFileSystem(&fileSystem);
	cmdPrompt->setFileFactory(&fileFactory);
	cmdPrompt->addCommand("touch", touchComm);
	cmdPrompt->run();

	AbstractFile* file = fileSystem.openFile("hello.txt"); // testing 'touch hello.txt':
	if (file != nullptr) { cout << "'hello.txt' file created successfully" << endl; }
	else { cout << "file is nullptr" << endl; }
	return 0;
}


