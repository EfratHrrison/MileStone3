cmake_minimum_required(VERSION 3.12)
project(MileStone3)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)
add_executable(MileStone3 main.cpp CacheManager.h ClientHandler.h FileCacheManager.cpp
        FileCachManager.h MyClientHandler.cpp MyClientHandler.h MySerialServer.cpp BFS.h
        Server.h Solver.h stringRevers.cpp stringRevers.h MySerialServer.h DFS.h State.h Searchable.h Searcher.h BestFirstSearch.h Matrix.cpp Matrix.h Point.cpp Point.h GetSolution.h)