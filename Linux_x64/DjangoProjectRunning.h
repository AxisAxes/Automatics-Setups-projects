#include<stdexcept>
#include<stdio.h>
#include<string>
#include<stdio.h>
#include<stdlib.h>

namespace DjangoRun 
{
    class DjangoProjectRunning
    {
        public:
            DjangoProjectRunning(const char* venv, const char* path_project, const char* database, const char* browser, bool vim = true);
            ~DjangoProjectRunning();
            char CreateWorkspaceVim();
            void RunProject();
            void StopProject();
        private:
            char _vimWorkspace;
            const char _path_project;
            const char _database;
            const char _browser;
            bool _vim = true;
            const char _venv;

    }
}

