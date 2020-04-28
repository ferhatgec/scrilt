
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include "../../include/src/Syntax/CommandFunc.h"
#include "../../include/src/main.h"
#include "../../include/src/Syntax/GetNameFunction.hpp"
#include "../../include/src/Syntax/CDFunction.hpp"
#include "../../include/src/Syntax/PrintErrorFunction.hpp"
#include "../../include/src/Syntax/MkdirFunction.hpp"
#include <iostream>
#include <unistd.h>

FCommand *command = new FCommand();
FMain *fmain = new FMain();
fprinterror *printerror = new fprinterror;
std::string str;
fchar *file_path = new fchar;
fchar* input_char;
std::string path_directory;


FCDFunction::FCDFunction()
{
    
}



FCDFunction::~FCDFunction()
{
    delete fmain, printerror, command, str;
}


boolean
FCDFunction::FileExists(const std::string &Filename)
{
    return access(Filename.c_str(), 0 ) == 0;
}

void
FCDFunction::CDFunctionInit()
{
    command = new FCommand();
    fmain = new FMain();
    std::cin >> str;
    // or std::getline
    if(str != "") 
    {
        if(fmain->_home != true) 
        {
            std::string path;
            path.append(command->_file_path_cd_function);
            path.append("/");
            path.append(str);
            if(FileExists(path) == true) {
                std::strcat(command->_file_path_cd_function, "/");
                std::strcat(command->_file_path_cd_function, str.c_str()); 
            } else {
                printerror->PrintError("This directory is not exist!");
                slashn
                return;
            }
        }
    } 
    return;         
}



FMKDirFunction::FMKDirFunction()
{

}


FMKDirFunction::~FMKDirFunction()
{

}


void
FMKDirFunction::MKDirFunctionInit()
{
    input_char = new fchar;
    std::cin >> input_char; // I will use std::getline.
    path_directory.append(command->_file_path_cd_function); // default getenv("HOME")
    path_directory.append("/"); // ex: /home/username -> getenv("HOME") -> /home/username'/'
    path_directory.append(input_char); // maybe directory is exist or directory is not exist.
    if(mkdir(path_directory.c_str(), 0777) == -1 ) {// 0777 is user permission number.
        printerror->PrintError("Directory is exist or you're not root");
        slashn
    } else {
            printlnf("Success");
            slashn
    }
    return;
}