#include <string>

void hello_world(std::string const& name);
void demo_ranges();

int main(int argc, char* argv[])
{
    auto const who = argv[1] ? argv[1] : "Anonymous";

    hello_world(who);
    demo_ranges();

    return 0;
}