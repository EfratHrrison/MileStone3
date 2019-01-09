#include <iostream>
#include "FileCachManager.h"
#include "MySerialServer.h"
#include "MyClientHandler.h"
#include "Solver.h"
#include "stringRevers.h"

int main() {

    MySerialServer test;
    ClientHandler *cH=new MyClientHandler();
    test.open(5400,cH);
    stringRevers *Sr=new stringRevers();
    string neta=Sr->solve("efrart");
}