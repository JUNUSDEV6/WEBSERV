// include includes file

#include <iostream>

int main (int argc, char **argv)
{
    if (argc > 2)
    {
        std::cerr << "error: too many arguments" << std::endl;
        return -1;
    }
    
    //Server server; //create server
    if (argc == 2)
    {
        //server.config(argv[1]);
    }
    else if (argc == 1)
    {
        //server.defaultconfig();
    }
    else
    {
        // error argc or bad code
        //server.close();
        return -1;
    }
    //server.run();
    //server.close(); //ferme proprement et appelle le destructeur
}
