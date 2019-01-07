#include <iostream>
#include "FileCachManager.h"
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "Solver.h"
#include "stringRevers.h"

int main() {

    MySerialServer test;
    ClientHandler *cH=new MyTestClientHandler();
    test.open(5400,cH);
    stringRevers *Sr=new stringRevers();
    string neta=Sr->solve("efrart");



}