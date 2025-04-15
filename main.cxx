#include <string>

void hello_world(std::string const& name);

int main(int argc, char* argv[])
{
    hello_world(argv[1] ? argv[1] : "What?");
    hello_world(argv[1] ? argv[1] : "Who?");
    return 0;
}