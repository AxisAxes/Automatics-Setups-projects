#include "DjangoProjectRunning.h"

namespace DjangoRun
{
    std::string exec(string command) {
   	    char buffer[128];
        std::string result = "";

    	FILE* pipe = popen(command.c_str(), "r");
   	    if (!pipe) {
      		return "popen failed!";
   	    }

        while (!feof(pipe)) {

            if (fgets(buffer, 128, pipe) != NULL)
                result += buffer;
        }

   	    pclose(pipe);
   	    return result;
	}

    DjangoProjectRunning::DjangoProjectRunning(const char* venv, const char* path_project, const char* database, const char* browser, bool vim = true)
    {
        _venv = venv;
        _path_project = path_project;
        _database = database;
        _browser = browser;
        _vim = vim;

    }
    DjangoProjectRunning::~DjangoProjectRunning(){ };
    
    void DjangoRun::RunProject()
    {
        system("cd %c", _path_project );
        std::string find_manage = exec("locate -b '\\manage.py'");
        std::string pwd = exec("pwd");
        if(find_manage.length() != 0)
        {
            std::string conda_env = exec("conda env list");
            std::string py_env = exec("lsvirtualenv -b");
            //compare liste exist env

        }
    
    }
}
